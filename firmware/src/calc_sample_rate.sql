-- #define ADC_HZ (8000)                        // ADC sample rate, Hz (all channels sampled, works over range of 232 Hz to 116 kHz)
-- #define ADC_CHANNELS    (2)            // number of ADC channels to be read
-- #define SAMC_VALUE        (31)        // sample time (Tad units)
-- #define ADCS_VALUE        ((FOSC/((2*12)*(SAMC_VALUE+12)/12)/ADC_HZ/ADC_CHANNELS-1))    // rounds frequency up

-- Tpb * 2 *
--	((fosc/((2*12)*(samc+12)/12)/adc_hz/chans-1)) as ADCS
select FOSC.*, ADC_HZ.*, CHANNELS.*, SAMC.*,
	((fosc/((2 * 12)*(samc+12)/12)/adc_hz/chans-1)) as ADCS
from (
   select 40000000 as fosc
) FOSC
join (
   select 1000 as adc_hz union
--   select 4000 as adc_hz union
--   select 8000 as adc_hz union
   select 32000 as adc_hz union
   select 48000 as adc_hz union
   select 96000 as adc_hz
) ADC_HZ
join (
--   select 2 as chans union
   select 3 as chans
) CHANNELS
join (
   select 31 as samc union
   select 24 as samc union
   select 16 as samc union
   select  8 as samc
) SAMC
order by chans, adc_hz, samc

-- +----------+--------+-------+------+------------------+
-- | fosc     | adc_hz | chans | samc | ADCS             |
-- +----------+--------+-------+------+------------------+
-- | 40000000 |   1000 |     3 |    8 | 332.333333333333 |
-- | 40000000 |   1000 |     3 |   16 | 237.095238095238 |
-- | 40000000 |   1000 |     3 |   24 | 184.185185185185 |
-- | 40000000 |   1000 |     3 |   31 | 154.038759689922 |
-- | 40000000 |  32000 |     3 |    8 |   9.416666666667 |
-- | 40000000 |  32000 |     3 |   16 |   6.440476190476 |
-- | 40000000 |  32000 |     3 |   24 |   4.787037037037 |
-- | 40000000 |  32000 |     3 |   31 |   3.844961240310 |
-- | 40000000 |  48000 |     3 |    8 |   5.944444444444 |
-- | 40000000 |  48000 |     3 |   16 |   3.960317460317 |
-- | 40000000 |  48000 |     3 |   24 |   2.858024691358 |
-- | 40000000 |  48000 |     3 |   31 |   2.229974160207 |
-- | 40000000 |  96000 |     3 |    8 |   2.472222222222 |
-- | 40000000 |  96000 |     3 |   16 |   1.480158730159 |
-- | 40000000 |  96000 |     3 |   24 |   0.929012345679 |
-- | 40000000 |  96000 |     3 |   31 |   0.614987080103 |
-- +----------+--------+-------+------+------------------+
