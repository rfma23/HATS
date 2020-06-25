# HATS
HATS: Histograms of Averaged Time Surfaces

HATS is a robust event-based object classification algorithm proposed by Amos Sironi, Manuele Brambilla, Nicolas Bourdis, Xavier Lagorce, and Ryad Benosman in 2018.
[(paper)](https://arxiv.org/abs/1803.07913).

Event-based cameras are a new typology of vision sensors which offer some advantages w.r.t. standard camera sensors, mainly a high dynamic range and temporal resolution, low power consumption and low transfer rate as when there is no motion the sensor does not output any data.

<p align="left">
    <img src="images/ebc.png?raw=true" width="500" alt="Event Based Camera Advantages"/> </br>
</p>

The problem with this new type of cameras is that all state of the art algorithms were developed using standard images. Therefore, since their invention, many researchers have tried to develop algorithms for these kind of sensors as their properties make them a perfect fit for autonomous vehicles, robot navigation or other UAV applications were power supply is limited and real-time computations are needed.

This new approach for object classification takes ideas from HOTS and combines it with a new low level operator: Local Memory Time Surfaces.

Test is done on the Neuromorphic MNIST (N-MNIST)
<p align="left">
    <img src="images/nmnist.gif?raw=true" width="450" alt="NMNIST"/> </br>
</p>
