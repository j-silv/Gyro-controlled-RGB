# -----------------------------------------------------------------------
# Quartus (TCL) script for assigning various input/output pin parameters
#
# MISO_PMOD is connected to PIN_E19 (PMOD_B_1) (Purple)
# MOSI_PMOD is connected to PIN_F18 (PMOD_B_2) (Blue)
# SCK_PMOD is connected to PIN_F20 (PMOD_B_3)  (Grey)
# CS_PMOD is connected to PIN_G19 (PMOD_B_4)   (Green)
# GND is connected to PMOD pin 10

# INT1_PMOD is connected to PIN_C20 (PMOD_A_1)
# INT2_PMOD is connected to PIN_D19 (PMOD_A_2)

# MISO_IC is connected to PIN_L18 (ADXL362_MISO)
# MOSI_IC is connected to PIN_L19 (ADXL362_MOSI)
# SCK_IC is connected to PIN_M18 (ADXL362_SCLK)
# CS_IC is connected to PIN_L14 (ADXL362_CS)

# INT1_IC is connected to PIN_M15 (ADXL362_INT1)
# INT2_IC is connected to PIN_M14 (ADXL362_INT2)
#
# -----------------------------------------------------------------------

# necessary package declaration to pull in Quartus project
package require ::quartus::project

# ********* OUTPUT PINS **************
# set pin locations
set_location_assignment PIN_E19 -to MISO_PMOD
set_location_assignment PIN_L19 -to MOSI_IC
set_location_assignment PIN_M18 -to SCK_IC
set_location_assignment PIN_L14 -to CS_IC
# set the logic levels
set_instance_assignment -name IO_STANDARD "3.3-V LVCMOS" -to MISO_PMOD
set_instance_assignment -name IO_STANDARD "3.3-V LVCMOS" -to MOSI_IC
set_instance_assignment -name IO_STANDARD "3.3-V LVCMOS" -to SCK_IC
set_instance_assignment -name IO_STANDARD "3.3-V LVCMOS" -to CS_IC

# ********* INPUT PINS **************
# set pin locations
set_location_assignment PIN_L18 -to MISO_IC
set_location_assignment PIN_F18 -to MOSI_PMOD
set_location_assignment PIN_F20 -to SCK_PMOD
set_location_assignment PIN_G19 -to CS_PMOD
# set the logic levels
set_instance_assignment -name IO_STANDARD "3.3-V LVCMOS" -to MISO_IC
set_instance_assignment -name IO_STANDARD "3.3-V LVCMOS" -to MOSI_PMOD
set_instance_assignment -name IO_STANDARD "3.3-V LVCMOS" -to SCK_PMOD
set_instance_assignment -name IO_STANDARD "3.3-V LVCMOS" -to CS_PMOD