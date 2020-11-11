--------------------------------------------------------------------
-- Accelerometer setup
--------------------------------------------------------------------

--------------------------------------------------------------------
-- This code routes the various SPI signals from the 
-- ADXL362 accelerometer that are hard wired to the FPGA IC, towards 
-- the outputs located on the FPGA Dev Kit headers (PMOD connectors)
--------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity accelerometer is
	port(
		MISO_IC		: in std_logic; 	-- Master in, slave out (ADXL362 pin)
		MISO_PMOD 	: out std_logic; 	-- Master in, slave out (PMOD header)
	
		MOSI_IC	 	: out std_logic; 	-- Master out, slave in (ADXL362 pin)
		MOSI_PMOD 	: in std_logic; 	-- Master out, slave in (PMOD header)
		
		SCK_IC 		: out std_logic;	-- Serial clock (ADXL362 pin)
		SCK_PMOD 	: in std_logic;		-- Serial clock (PMOD header)
		
		CS_IC		: out std_logic; 	-- Slave select (ADXL362 pin)
		CS_PMOD		: in std_logic 		-- Slave select (PMOD header)	
	);
end entity accelerometer;

architecture logic of accelerometer is
begin

	MISO_PMOD 	<= MISO_IC; 			-- MISO is a signal from IC, so the IC pin outputs to the PMOD pin
	MOSI_IC 	<= MOSI_PMOD;			-- MOSI is a signal to IC, so the PMOD pin outputs to the IC pin
	SCK_IC		<= SCK_PMOD;			-- SCK is a signal to IC, so the PMOD pin outputs to the IC pin
	CS_IC 		<= CS_PMOD;				-- CS is a signal to IC, so the PMOD pin outputs to the IC pin

end architecture logic;