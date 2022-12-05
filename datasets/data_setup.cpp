/** Convert N-MNIST dataset to plaintext
 *  x, y, t, p format
 *  Seth Roffe
 *  2021-07-27
 */
#include <iostream>
#include <fstream>
#include <stdint.h>
using namespace std;

// just for easy readability
struct event {
    unsigned int x;
    unsigned int y;
    unsigned int t;
    bool pol;
};

int main(int argc, char** argv) {

    /** Constants **/
    char* filename;
    char* outname;
    event evt;

    unsigned int ts_upper = 0, ts_lower = 0, ts_mid = 0;
    char* x_pos = new char[1];
    char* y_pos = new char[1];
    char* pol = new char[1];
    char* ts = new char[2];
    char polRaw = 0;

    /** need filename argument **/
    if (argc < 3) {
        cout << "Need input and output filename arguments!" << endl;
        cout << "Usage:" << argv[0] << " <input file> <output file>" << endl;
        return 1;
    }
    filename = argv[1];
    outname = argv[2];

    /** Read in data **/
    ifstream data(filename, ios::binary);
    if (!data) {
        cout << "Cannot open input file" << endl;
        return 1;
    }

    ofstream output(outname);
    if (!output) {
        cout << "HEEERE Cannot open output file" << endl;
        return 1;
    }

    int num_evts = 0;
    while (!data.eof()) {

        /** x and y addresses **/
        data.read(x_pos,1); // first byte is x evt address
        data.read(y_pos,1); // second byte is y evt address

        evt.x = (unsigned int) x_pos[0];
        evt.y = (unsigned int) y_pos[0];

        evt.x = evt.x & 0x00000FF;
        evt.y = evt.y & 0x00000FF;
        
        /** polarity and time **/
        data.read(pol,1); // next bit is polarity
        data.read(ts,2); // 23 bits for timestamp, read next 2 bytes

        polRaw = pol[0];
        evt.pol = (polRaw >> 7) & 0x01; // shift and mask to get bit

        ts_upper = (unsigned int) (pol[0] & 0x7F);
        ts_mid = (unsigned int) ts[0];
        ts_lower = (unsigned int) ts[1];

        /** ts sanitization **/
        ts_upper = ts_upper << 16;
        ts_upper = ts_upper & 0x007F0000;

        ts_mid = ts_mid << 8;
        ts_mid = ts_mid & 0x0000FF00;
        
        evt.t = ts_upper + ts_mid + ts_lower;

        /** write to file **/
        if (evt.t < 50000000) {
            // sometimes we get a crazy high number for the first event. No idea why
            output << evt.x << " " << evt.y << " " << evt.t << " " << evt.pol << endl;
        }
        num_evts++;

    }
    cout << "Wrote " << num_evts << " events" << endl;
    return 0;
}