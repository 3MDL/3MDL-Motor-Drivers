# About #

This repository contains design files for low-cost brushed DC motor drivers. These low-cost motor drivers were concieved for use in low-cost swarm robotics. Work was done under the Mechanism, Mobility, and Multifunctional Design Laboratory (3MDL) at the University of Toledo.

## In This Repository ##

The Firmware sub folder contains test code that was used to evaluate motor drivers that were based on microcontrollers.

The Hardware sub folder contains hardware design files for:
	* An OP Amp based current regulator motor driver
        * This design was confirmed to work and the cost is marginally lower than the off the shelf driver IC solution. However, due to complex timing, only limited testing was performed before the motor driver failed due to shoot through in the H bridge circuit.
    * A Microcrocontroller based current regulator motor driver
        * The footprint used for the microcntroller was incorrect so this design could not be evaluated
    * A motor driver using an off the shelf motor driver IC
        * This design was confirmed to work, however near the current limit rating of the driver IC, additional cooling is required or else the driver IC goes into over temperature protection mode.
