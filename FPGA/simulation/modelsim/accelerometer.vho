-- Copyright (C) 1991-2015 Altera Corporation. All rights reserved.
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, the Altera Quartus II License Agreement,
-- the Altera MegaCore Function License Agreement, or other 
-- applicable license agreement, including, without limitation, 
-- that your use is for the sole purpose of programming logic 
-- devices manufactured by Altera and sold by Altera or its 
-- authorized distributors.  Please refer to the applicable 
-- agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 15.0.0 Build 145 04/22/2015 SJ Web Edition"

-- DATE "11/14/2020 16:31:57"

-- 
-- Device: Altera 10M08DAF484C8GES Package FBGA484
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY FIFTYFIVENM;
LIBRARY IEEE;
USE FIFTYFIVENM.FIFTYFIVENM_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	accelerometer IS
    PORT (
	MISO_IC : IN std_logic;
	MISO_PMOD : BUFFER std_logic;
	MOSI_IC : BUFFER std_logic;
	MOSI_PMOD : IN std_logic;
	SCK_IC : BUFFER std_logic;
	SCK_PMOD : IN std_logic;
	CS_IC : BUFFER std_logic;
	CS_PMOD : IN std_logic
	);
END accelerometer;

-- Design Ports Information
-- MISO_PMOD	=>  Location: PIN_E19,	 I/O Standard: 3.3-V LVCMOS,	 Current Strength: 2mA
-- MOSI_IC	=>  Location: PIN_L19,	 I/O Standard: 3.3-V LVCMOS,	 Current Strength: 2mA
-- SCK_IC	=>  Location: PIN_M18,	 I/O Standard: 3.3-V LVCMOS,	 Current Strength: 2mA
-- CS_IC	=>  Location: PIN_L14,	 I/O Standard: 3.3-V LVCMOS,	 Current Strength: 2mA
-- MISO_IC	=>  Location: PIN_L18,	 I/O Standard: 3.3-V LVCMOS,	 Current Strength: Default
-- MOSI_PMOD	=>  Location: PIN_F18,	 I/O Standard: 3.3-V LVCMOS,	 Current Strength: Default
-- SCK_PMOD	=>  Location: PIN_F20,	 I/O Standard: 3.3-V LVCMOS,	 Current Strength: Default
-- CS_PMOD	=>  Location: PIN_G19,	 I/O Standard: 3.3-V LVCMOS,	 Current Strength: Default


ARCHITECTURE structure OF accelerometer IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_MISO_IC : std_logic;
SIGNAL ww_MISO_PMOD : std_logic;
SIGNAL ww_MOSI_IC : std_logic;
SIGNAL ww_MOSI_PMOD : std_logic;
SIGNAL ww_SCK_IC : std_logic;
SIGNAL ww_SCK_PMOD : std_logic;
SIGNAL ww_CS_IC : std_logic;
SIGNAL ww_CS_PMOD : std_logic;
SIGNAL \~QUARTUS_CREATED_ADC1~_CHSEL_bus\ : std_logic_vector(4 DOWNTO 0);
SIGNAL \~QUARTUS_CREATED_GND~I_combout\ : std_logic;
SIGNAL \~QUARTUS_CREATED_UNVM~~busy\ : std_logic;
SIGNAL \~QUARTUS_CREATED_ADC1~~eoc\ : std_logic;
SIGNAL \MISO_PMOD~output_o\ : std_logic;
SIGNAL \MOSI_IC~output_o\ : std_logic;
SIGNAL \SCK_IC~output_o\ : std_logic;
SIGNAL \CS_IC~output_o\ : std_logic;
SIGNAL \MISO_IC~input_o\ : std_logic;
SIGNAL \MOSI_PMOD~input_o\ : std_logic;
SIGNAL \SCK_PMOD~input_o\ : std_logic;
SIGNAL \CS_PMOD~input_o\ : std_logic;

BEGIN

ww_MISO_IC <= MISO_IC;
MISO_PMOD <= ww_MISO_PMOD;
MOSI_IC <= ww_MOSI_IC;
ww_MOSI_PMOD <= MOSI_PMOD;
SCK_IC <= ww_SCK_IC;
ww_SCK_PMOD <= SCK_PMOD;
CS_IC <= ww_CS_IC;
ww_CS_PMOD <= CS_PMOD;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\~QUARTUS_CREATED_ADC1~_CHSEL_bus\ <= (\~QUARTUS_CREATED_GND~I_combout\ & \~QUARTUS_CREATED_GND~I_combout\ & \~QUARTUS_CREATED_GND~I_combout\ & \~QUARTUS_CREATED_GND~I_combout\ & \~QUARTUS_CREATED_GND~I_combout\);

-- Location: LCCOMB_X1_Y1_N24
\~QUARTUS_CREATED_GND~I\ : fiftyfivenm_lcell_comb
-- Equation(s):
-- \~QUARTUS_CREATED_GND~I_combout\ = GND

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	combout => \~QUARTUS_CREATED_GND~I_combout\);

-- Location: IOOBUF_X31_Y20_N23
\MISO_PMOD~output\ : fiftyfivenm_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MISO_IC~input_o\,
	devoe => ww_devoe,
	o => \MISO_PMOD~output_o\);

-- Location: IOOBUF_X31_Y19_N9
\MOSI_IC~output\ : fiftyfivenm_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MOSI_PMOD~input_o\,
	devoe => ww_devoe,
	o => \MOSI_IC~output_o\);

-- Location: IOOBUF_X31_Y19_N23
\SCK_IC~output\ : fiftyfivenm_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \SCK_PMOD~input_o\,
	devoe => ww_devoe,
	o => \SCK_IC~output_o\);

-- Location: IOOBUF_X31_Y17_N23
\CS_IC~output\ : fiftyfivenm_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \CS_PMOD~input_o\,
	devoe => ww_devoe,
	o => \CS_IC~output_o\);

-- Location: IOIBUF_X31_Y19_N15
\MISO_IC~input\ : fiftyfivenm_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	listen_to_nsleep_signal => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_MISO_IC,
	o => \MISO_IC~input_o\);

-- Location: IOIBUF_X31_Y20_N15
\MOSI_PMOD~input\ : fiftyfivenm_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	listen_to_nsleep_signal => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_MOSI_PMOD,
	o => \MOSI_PMOD~input_o\);

-- Location: IOIBUF_X31_Y15_N15
\SCK_PMOD~input\ : fiftyfivenm_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	listen_to_nsleep_signal => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_SCK_PMOD,
	o => \SCK_PMOD~input_o\);

-- Location: IOIBUF_X31_Y12_N15
\CS_PMOD~input\ : fiftyfivenm_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	listen_to_nsleep_signal => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CS_PMOD,
	o => \CS_PMOD~input_o\);

-- Location: UNVM_X0_Y11_N40
\~QUARTUS_CREATED_UNVM~\ : fiftyfivenm_unvm
-- pragma translate_off
GENERIC MAP (
	addr_range1_end_addr => -1,
	addr_range1_offset => -1,
	addr_range2_offset => -1,
	is_compressed_image => "false",
	is_dual_boot => "false",
	is_eram_skip => "false",
	max_ufm_valid_addr => -1,
	max_valid_addr => -1,
	min_ufm_valid_addr => -1,
	min_valid_addr => -1,
	part_name => "quartus_created_unvm",
	reserve_block => "true")
-- pragma translate_on
PORT MAP (
	nosc_ena => \~QUARTUS_CREATED_GND~I_combout\,
	xe_ye => \~QUARTUS_CREATED_GND~I_combout\,
	se => \~QUARTUS_CREATED_GND~I_combout\,
	busy => \~QUARTUS_CREATED_UNVM~~busy\);

-- Location: ADCBLOCK_X10_Y24_N0
\~QUARTUS_CREATED_ADC1~\ : fiftyfivenm_adcblock
-- pragma translate_off
GENERIC MAP (
	analog_input_pin_mask => 0,
	clkdiv => 1,
	device_partname_fivechar_prefix => "none",
	is_this_first_or_second_adc => 1,
	prescalar => 0,
	pwd => 1,
	refsel => 0,
	reserve_block => "true",
	testbits => 66,
	tsclkdiv => 1,
	tsclksel => 0)
-- pragma translate_on
PORT MAP (
	soc => \~QUARTUS_CREATED_GND~I_combout\,
	usr_pwd => VCC,
	tsen => \~QUARTUS_CREATED_GND~I_combout\,
	chsel => \~QUARTUS_CREATED_ADC1~_CHSEL_bus\,
	eoc => \~QUARTUS_CREATED_ADC1~~eoc\);

ww_MISO_PMOD <= \MISO_PMOD~output_o\;

ww_MOSI_IC <= \MOSI_IC~output_o\;

ww_SCK_IC <= \SCK_IC~output_o\;

ww_CS_IC <= \CS_IC~output_o\;
END structure;


