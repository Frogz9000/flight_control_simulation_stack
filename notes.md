# C++ resources to look into: 
Effective Modern C++ ~~ need to get pdf 
[C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines "https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines") 
[C++ Reference](https://en.cppreference.com/ "https://en.cppreference.com/") 
[Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)

# rocket simulators references:
[Open Rocket](https://openrocket.info/ "https://openrocket.info/")
[PX4](https://github.com/PX4/PX4-Autopilot "https://github.com/PX4/PX4-Autopilot") 

# Research Notes
[Spacecraft attitude determination and control](https://en.wikipedia.org/wiki/Spacecraft_attitude_determination_and_control)
- Attitude is the rotational data of an object
	- pitch yaw roll as one vector/matrix
- "Attitude and position fully describe how an object is placed in space"
	- the combination of position and attitude is known as a Pose
- 3 commons methods of representation for attitude
	- Rotational Matrices
		- require 9 values, offers a full description
		- computationally intensive 
	- Quaternions
		- only require 4 values and is the standard for computational work
	- Euler angles
		- most intuitive to visualize but suffers from Gimbal lock
		- can be difficult to manipulate mathematically
- 
[Pose](https://en.wikipedia.org/wiki/Pose_(computer_vision))
- pose and transform are largely synonymous
- pose is the representation of position and orientation of an object
	- allows the coordinates and attitude to be stored in one data class
[Quaternions and Spatial Rotation](https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation)
- notes

https://www.learncpp.com/cpp-tutorial/classes-and-header-files/

https://stackoverflow.com/questions/5424042/class-variables-public-access-read-only-but-private-access-read-write

https://www.geeksforgeeks.org/cpp/when-do-we-use-initializer-list-in-c/

