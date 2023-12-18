<h2>Commands to launch</h2>

<h3>Running Rviz</h3>
<code>roslaunch arm_description display.launch</code><br>

<h3>Running Gazebo</h3>
<code>roslaunch arm_gazebo arm_gazebo.launch</code>

<h3>Running the controller</h3>
<code>rosrun arm_controller arm_controller_node</code>


<h2>Stack description</h2>
<ul>
  <li><code>arm_description</code>
    <ul>
      <li><code>arm.gazebo.xacro</code></li>
      <li><code>arm.transmission.xacro</code></li>
      <li><code>arm.urdf.xacro</code></li>
      <li><code>camera.urdf.xacro</code></li>
    </ul>
  </li>
  <li><code>arm_gazebo</code>
    <ul>
      <li><code>arm_gazebo.launch</code>: launches <code>arm_world.launch</code> and <code>arm_control.launch</code>
      <li><code>arm_world.launch</code>: spawns the Gazebo world
    </ul>
  </li>
  <li><code>arm_control</code>
    <ul>
      <li><code>arm_control.yaml</code>: contains the controllers configuration</li>
        <ul>
          <li>PositionJointInterface_J0_controller</li>
          <li>PositionJointInterface_J1_controller</li>
          <li>PositionJointInterface_J2_controller</li>
          <li>PositionJointInterface_J3_controller</li>
        </ul>
      <li><code>arm_control.launch</code>
        <ul>
          <li>Spawns the controller</li>
          <li>Publishes the joint states</li>
        </ul>
      </li>
    </ul>
  </li>
  <li><code>arm_controller</code>
    <ul>
      <li><code>arm_controller_node.cpp</code></li>
    </ul>
  </li>
</ul>

<h2>Arm_controller_node</h2>

* The node "_arm_controller_node_" sends commands to the four topics like "_/arm/PositionJointInterface_J0_controller/command_".
* Gazebo is subscribed to this topic, so it can read these commands and send them to the robot.
* Gazebo also sends information to the "_arm/joint_states_" topic
* So you can also use this topic to read the joint states and print them
<br><br>
![image -thumbnail](https://github.com/marseluca/arm_stack/assets/33966986/528177bc-43f0-49bd-97cf-332ee2ba8d02) 
