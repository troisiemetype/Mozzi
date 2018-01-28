#ifndef SQUARE2048_H_
#define SQUARE2048_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <avr/pgmspace.h>
 
#define SQUARE2048_NUM_CELLS 2048
#define SQUARE2048_SAMPLERATE 2048
 
const int16_t __attribute__((section(".progmem.data"))) SQUARE2048_DATA [] = {0,
1729, 3449, 5150, 6823, 8458, 10048, 11583, 13057, 14462, 15792, 17041, 18205,
19279, 20260, 21147, 21936, 22628, 23223, 23723, 24129, 24443, 24670, 24814,
24879, 24871, 24795, 24659, 24468, 24229, 23950, 23637, 23298, 22940, 22570,
22194, 21818, 21450, 21093, 20755, 20438, 20147, 19886, 19657, 19463, 19305,
19184, 19101, 19055, 19045, 19071, 19130, 19221, 19340, 19484, 19651, 19836,
20037, 20249, 20468, 20691, 20914, 21133, 21345, 21546, 21734, 21906, 22060,
22193, 22304, 22392, 22456, 22496, 22512, 22503, 22471, 22418, 22344, 22251,
22141, 22016, 21879, 21733, 21579, 21421, 21261, 21102, 20947, 20798, 20657,
20526, 20408, 20304, 20215, 20143, 20088, 20051, 20033, 20032, 20050, 20084,
20135, 20201, 20281, 20372, 20475, 20586, 20703, 20825, 20950, 21075, 21198,
21317, 21431, 21538, 21636, 21723, 21798, 21861, 21910, 21945, 21966, 21972,
21963, 21941, 21904, 21855, 21795, 21723, 21643, 21554, 21460, 21361, 21259,
21156, 21053, 20953, 20856, 20765, 20681, 20605, 20538, 20481, 20436, 20402,
20380, 20370, 20373, 20387, 20414, 20451, 20499, 20556, 20622, 20694, 20773,
20856, 20943, 21031, 21119, 21206, 21290, 21370, 21445, 21513, 21574, 21626,
21669, 21702, 21725, 21738, 21740, 21731, 21712, 21683, 21645, 21598, 21543,
21482, 21415, 21343, 21269, 21192, 21114, 21038, 20962, 20890, 20823, 20760,
20704, 20655, 20613, 20580, 20557, 20542, 20537, 20541, 20555, 20577, 20608,
20647, 20693, 20746, 20804, 20866, 20932, 21000, 21069, 21138, 21207, 21272,
21335, 21393, 21446, 21493, 21533, 21565, 21590, 21606, 21614, 21613, 21604,
21587, 21562, 21529, 21490, 21444, 21394, 21338, 21280, 21218, 21156, 21092,
21030, 20969, 20911, 20856, 20806, 20761, 20722, 20690, 20664, 20646, 20636,
20634, 20639, 20652, 20672, 20700, 20734, 20774, 20819, 20868, 20921, 20977,
21034, 21092, 21150, 21207, 21262, 21314, 21362, 21405, 21444, 21476, 21502,
21521, 21534, 21539, 21536, 21527, 21511, 21487, 21458, 21423, 21383, 21339,
21290, 21239, 21186, 21132, 21078, 21024, 20972, 20923, 20876, 20834, 20796,
20764, 20737, 20717, 20703, 20695, 20695, 20701, 20714, 20733, 20759, 20790,
20826, 20866, 20910, 20957, 21006, 21057, 21108, 21159, 21209, 21257, 21302,
21343, 21380, 21413, 21440, 21462, 21477, 21487, 21490, 21486, 21476, 21460,
21439, 21411, 21379, 21342, 21302, 21258, 21212, 21164, 21116, 21067, 21019,
20973, 20929, 20888, 20851, 20818, 20790, 20768, 20751, 20739, 20734, 20735,
20742, 20755, 20774, 20798, 20827, 20861, 20899, 20939, 20983, 21028, 21074,
21121, 21167, 21212, 21255, 21295, 21332, 21365, 21394, 21418, 21436, 21449,
21456, 21457, 21453, 21442, 21426, 21405, 21379, 21348, 21313, 21275, 21234,
21191, 21147, 21102, 21058, 21014, 20971, 20931, 20894, 20861, 20831, 20806,
20787, 20772, 20763, 20760, 20762, 20770, 20783, 20802, 20826, 20854, 20886,
20922, 20961, 21002, 21044, 21088, 21131, 21174, 21216, 21256, 21293, 21327,
21357, 21383, 21404, 21421, 21431, 21437, 21437, 21431, 21420, 21404, 21382,
21356, 21326, 21293, 21256, 21217, 21176, 21133, 21091, 21048, 21007, 20967,
20930, 20895, 20864, 20837, 20815, 20797, 20784, 20777, 20775, 20779, 20787,
20802, 20821, 20844, 20872, 20904, 20939, 20977, 21017, 21058, 21100, 21141,
21182, 21222, 21260, 21295, 21327, 21355, 21379, 21398, 21413, 21422, 21426,
21425, 21418, 21406, 21389, 21367, 21341, 21311, 21278, 21242, 21203, 21163,
21122, 21080, 21039, 20999, 20961, 20925, 20892, 20863, 20838, 20817, 20800,
20789, 20783, 20783, 20787, 20797, 20812, 20832, 20856, 20885, 20917, 20952,
20989, 21029, 21069, 21111, 21152, 21192, 21231, 21267, 21301, 21332, 21359,
21381, 21399, 21412, 21420, 21423, 21420, 21412, 21399, 21381, 21359, 21332,
21301, 21267, 21231, 21192, 21152, 21111, 21069, 21029, 20989, 20952, 20917,
20885, 20856, 20832, 20812, 20797, 20787, 20783, 20783, 20789, 20800, 20817,
20838, 20863, 20892, 20925, 20961, 20999, 21039, 21080, 21122, 21163, 21203,
21242, 21278, 21311, 21341, 21367, 21389, 21406, 21418, 21425, 21426, 21422,
21413, 21398, 21379, 21355, 21327, 21295, 21260, 21222, 21182, 21141, 21100,
21058, 21017, 20977, 20939, 20904, 20872, 20844, 20821, 20802, 20787, 20779,
20775, 20777, 20784, 20797, 20815, 20837, 20864, 20895, 20930, 20967, 21007,
21048, 21091, 21133, 21176, 21217, 21256, 21293, 21326, 21356, 21382, 21404,
21420, 21431, 21437, 21437, 21431, 21421, 21404, 21383, 21357, 21327, 21293,
21256, 21216, 21174, 21131, 21088, 21044, 21002, 20961, 20922, 20886, 20854,
20826, 20802, 20783, 20770, 20762, 20760, 20763, 20772, 20787, 20806, 20831,
20861, 20894, 20931, 20971, 21014, 21058, 21102, 21147, 21191, 21234, 21275,
21313, 21348, 21379, 21405, 21426, 21442, 21453, 21457, 21456, 21449, 21436,
21418, 21394, 21365, 21332, 21295, 21255, 21212, 21167, 21121, 21074, 21028,
20983, 20939, 20899, 20861, 20827, 20798, 20774, 20755, 20742, 20735, 20734,
20739, 20751, 20768, 20790, 20818, 20851, 20888, 20929, 20973, 21019, 21067,
21116, 21164, 21212, 21258, 21302, 21342, 21379, 21411, 21439, 21460, 21476,
21486, 21490, 21487, 21477, 21462, 21440, 21413, 21380, 21343, 21302, 21257,
21209, 21159, 21108, 21057, 21006, 20957, 20910, 20866, 20826, 20790, 20759,
20733, 20714, 20701, 20695, 20695, 20703, 20717, 20737, 20764, 20796, 20834,
20876, 20923, 20972, 21024, 21078, 21132, 21186, 21239, 21290, 21339, 21383,
21423, 21458, 21487, 21511, 21527, 21536, 21539, 21534, 21521, 21502, 21476,
21444, 21405, 21362, 21314, 21262, 21207, 21150, 21092, 21034, 20977, 20921,
20868, 20819, 20774, 20734, 20700, 20672, 20652, 20639, 20634, 20636, 20646,
20664, 20690, 20722, 20761, 20806, 20856, 20911, 20969, 21030, 21092, 21156,
21218, 21280, 21338, 21394, 21444, 21490, 21529, 21562, 21587, 21604, 21613,
21614, 21606, 21590, 21565, 21533, 21493, 21446, 21393, 21335, 21272, 21207,
21138, 21069, 21000, 20932, 20866, 20804, 20746, 20693, 20647, 20608, 20577,
20555, 20541, 20537, 20542, 20557, 20580, 20613, 20655, 20704, 20760, 20823,
20890, 20962, 21038, 21114, 21192, 21269, 21343, 21415, 21482, 21543, 21598,
21645, 21683, 21712, 21731, 21740, 21738, 21725, 21702, 21669, 21626, 21574,
21513, 21445, 21370, 21290, 21206, 21119, 21031, 20943, 20856, 20773, 20694,
20622, 20556, 20499, 20451, 20414, 20387, 20373, 20370, 20380, 20402, 20436,
20481, 20538, 20605, 20681, 20765, 20856, 20953, 21053, 21156, 21259, 21361,
21460, 21554, 21643, 21723, 21795, 21855, 21904, 21941, 21963, 21972, 21966,
21945, 21910, 21861, 21798, 21723, 21636, 21538, 21431, 21317, 21198, 21075,
20950, 20825, 20703, 20586, 20475, 20372, 20281, 20201, 20135, 20084, 20050,
20032, 20033, 20051, 20088, 20143, 20215, 20304, 20408, 20526, 20657, 20798,
20947, 21102, 21261, 21421, 21579, 21733, 21879, 22016, 22141, 22251, 22344,
22418, 22471, 22503, 22512, 22496, 22456, 22392, 22304, 22193, 22060, 21906,
21734, 21546, 21345, 21133, 20914, 20691, 20468, 20249, 20037, 19836, 19651,
19484, 19340, 19221, 19130, 19071, 19045, 19055, 19101, 19184, 19305, 19463,
19657, 19886, 20147, 20438, 20755, 21093, 21450, 21818, 22194, 22570, 22940,
23298, 23637, 23950, 24229, 24468, 24659, 24795, 24871, 24879, 24814, 24670,
24443, 24129, 23723, 23223, 22628, 21936, 21147, 20260, 19279, 18205, 17041,
15792, 14462, 13057, 11583, 10048, 8458, 6823, 5150, 3449, 1729, 0, -1729,
-3449, -5150, -6823, -8458, -10048, -11583, -13057, -14462, -15792, -17041,
-18205, -19279, -20260, -21147, -21936, -22628, -23223, -23723, -24129, -24443,
-24670, -24814, -24879, -24871, -24795, -24659, -24468, -24229, -23950, -23637,
-23298, -22940, -22570, -22194, -21818, -21450, -21093, -20755, -20438, -20147,
-19886, -19657, -19463, -19305, -19184, -19101, -19055, -19045, -19071, -19130,
-19221, -19340, -19484, -19651, -19836, -20037, -20249, -20468, -20691, -20914,
-21133, -21345, -21546, -21734, -21906, -22060, -22193, -22304, -22392, -22456,
-22496, -22512, -22503, -22471, -22418, -22344, -22251, -22141, -22016, -21879,
-21733, -21579, -21421, -21261, -21102, -20947, -20798, -20657, -20526, -20408,
-20304, -20215, -20143, -20088, -20051, -20033, -20032, -20050, -20084, -20135,
-20201, -20281, -20372, -20475, -20586, -20703, -20825, -20950, -21075, -21198,
-21317, -21431, -21538, -21636, -21723, -21798, -21861, -21910, -21945, -21966,
-21972, -21963, -21941, -21904, -21855, -21795, -21723, -21643, -21554, -21460,
-21361, -21259, -21156, -21053, -20953, -20856, -20765, -20681, -20605, -20538,
-20481, -20436, -20402, -20380, -20370, -20373, -20387, -20414, -20451, -20499,
-20556, -20622, -20694, -20773, -20856, -20943, -21031, -21119, -21206, -21290,
-21370, -21445, -21513, -21574, -21626, -21669, -21702, -21725, -21738, -21740,
-21731, -21712, -21683, -21645, -21598, -21543, -21482, -21415, -21343, -21269,
-21192, -21114, -21038, -20962, -20890, -20823, -20760, -20704, -20655, -20613,
-20580, -20557, -20542, -20537, -20541, -20555, -20577, -20608, -20647, -20693,
-20746, -20804, -20866, -20932, -21000, -21069, -21138, -21207, -21272, -21335,
-21393, -21446, -21493, -21533, -21565, -21590, -21606, -21614, -21613, -21604,
-21587, -21562, -21529, -21490, -21444, -21394, -21338, -21280, -21218, -21156,
-21092, -21030, -20969, -20911, -20856, -20806, -20761, -20722, -20690, -20664,
-20646, -20636, -20634, -20639, -20652, -20672, -20700, -20734, -20774, -20819,
-20868, -20921, -20977, -21034, -21092, -21150, -21207, -21262, -21314, -21362,
-21405, -21444, -21476, -21502, -21521, -21534, -21539, -21536, -21527, -21511,
-21487, -21458, -21423, -21383, -21339, -21290, -21239, -21186, -21132, -21078,
-21024, -20972, -20923, -20876, -20834, -20796, -20764, -20737, -20717, -20703,
-20695, -20695, -20701, -20714, -20733, -20759, -20790, -20826, -20866, -20910,
-20957, -21006, -21057, -21108, -21159, -21209, -21257, -21302, -21343, -21380,
-21413, -21440, -21462, -21477, -21487, -21490, -21486, -21476, -21460, -21439,
-21411, -21379, -21342, -21302, -21258, -21212, -21164, -21116, -21067, -21019,
-20973, -20929, -20888, -20851, -20818, -20790, -20768, -20751, -20739, -20734,
-20735, -20742, -20755, -20774, -20798, -20827, -20861, -20899, -20939, -20983,
-21028, -21074, -21121, -21167, -21212, -21255, -21295, -21332, -21365, -21394,
-21418, -21436, -21449, -21456, -21457, -21453, -21442, -21426, -21405, -21379,
-21348, -21313, -21275, -21234, -21191, -21147, -21102, -21058, -21014, -20971,
-20931, -20894, -20861, -20831, -20806, -20787, -20772, -20763, -20760, -20762,
-20770, -20783, -20802, -20826, -20854, -20886, -20922, -20961, -21002, -21044,
-21088, -21131, -21174, -21216, -21256, -21293, -21327, -21357, -21383, -21404,
-21421, -21431, -21437, -21437, -21431, -21420, -21404, -21382, -21356, -21326,
-21293, -21256, -21217, -21176, -21133, -21091, -21048, -21007, -20967, -20930,
-20895, -20864, -20837, -20815, -20797, -20784, -20777, -20775, -20779, -20787,
-20802, -20821, -20844, -20872, -20904, -20939, -20977, -21017, -21058, -21100,
-21141, -21182, -21222, -21260, -21295, -21327, -21355, -21379, -21398, -21413,
-21422, -21426, -21425, -21418, -21406, -21389, -21367, -21341, -21311, -21278,
-21242, -21203, -21163, -21122, -21080, -21039, -20999, -20961, -20925, -20892,
-20863, -20838, -20817, -20800, -20789, -20783, -20783, -20787, -20797, -20812,
-20832, -20856, -20885, -20917, -20952, -20989, -21029, -21069, -21111, -21152,
-21192, -21231, -21267, -21301, -21332, -21359, -21381, -21399, -21412, -21420,
-21423, -21420, -21412, -21399, -21381, -21359, -21332, -21301, -21267, -21231,
-21192, -21152, -21111, -21069, -21029, -20989, -20952, -20917, -20885, -20856,
-20832, -20812, -20797, -20787, -20783, -20783, -20789, -20800, -20817, -20838,
-20863, -20892, -20925, -20961, -20999, -21039, -21080, -21122, -21163, -21203,
-21242, -21278, -21311, -21341, -21367, -21389, -21406, -21418, -21425, -21426,
-21422, -21413, -21398, -21379, -21355, -21327, -21295, -21260, -21222, -21182,
-21141, -21100, -21058, -21017, -20977, -20939, -20904, -20872, -20844, -20821,
-20802, -20787, -20779, -20775, -20777, -20784, -20797, -20815, -20837, -20864,
-20895, -20930, -20967, -21007, -21048, -21091, -21133, -21176, -21217, -21256,
-21293, -21326, -21356, -21382, -21404, -21420, -21431, -21437, -21437, -21431,
-21421, -21404, -21383, -21357, -21327, -21293, -21256, -21216, -21174, -21131,
-21088, -21044, -21002, -20961, -20922, -20886, -20854, -20826, -20802, -20783,
-20770, -20762, -20760, -20763, -20772, -20787, -20806, -20831, -20861, -20894,
-20931, -20971, -21014, -21058, -21102, -21147, -21191, -21234, -21275, -21313,
-21348, -21379, -21405, -21426, -21442, -21453, -21457, -21456, -21449, -21436,
-21418, -21394, -21365, -21332, -21295, -21255, -21212, -21167, -21121, -21074,
-21028, -20983, -20939, -20899, -20861, -20827, -20798, -20774, -20755, -20742,
-20735, -20734, -20739, -20751, -20768, -20790, -20818, -20851, -20888, -20929,
-20973, -21019, -21067, -21116, -21164, -21212, -21258, -21302, -21342, -21379,
-21411, -21439, -21460, -21476, -21486, -21490, -21487, -21477, -21462, -21440,
-21413, -21380, -21343, -21302, -21257, -21209, -21159, -21108, -21057, -21006,
-20957, -20910, -20866, -20826, -20790, -20759, -20733, -20714, -20701, -20695,
-20695, -20703, -20717, -20737, -20764, -20796, -20834, -20876, -20923, -20972,
-21024, -21078, -21132, -21186, -21239, -21290, -21339, -21383, -21423, -21458,
-21487, -21511, -21527, -21536, -21539, -21534, -21521, -21502, -21476, -21444,
-21405, -21362, -21314, -21262, -21207, -21150, -21092, -21034, -20977, -20921,
-20868, -20819, -20774, -20734, -20700, -20672, -20652, -20639, -20634, -20636,
-20646, -20664, -20690, -20722, -20761, -20806, -20856, -20911, -20969, -21030,
-21092, -21156, -21218, -21280, -21338, -21394, -21444, -21490, -21529, -21562,
-21587, -21604, -21613, -21614, -21606, -21590, -21565, -21533, -21493, -21446,
-21393, -21335, -21272, -21207, -21138, -21069, -21000, -20932, -20866, -20804,
-20746, -20693, -20647, -20608, -20577, -20555, -20541, -20537, -20542, -20557,
-20580, -20613, -20655, -20704, -20760, -20823, -20890, -20962, -21038, -21114,
-21192, -21269, -21343, -21415, -21482, -21543, -21598, -21645, -21683, -21712,
-21731, -21740, -21738, -21725, -21702, -21669, -21626, -21574, -21513, -21445,
-21370, -21290, -21206, -21119, -21031, -20943, -20856, -20773, -20694, -20622,
-20556, -20499, -20451, -20414, -20387, -20373, -20370, -20380, -20402, -20436,
-20481, -20538, -20605, -20681, -20765, -20856, -20953, -21053, -21156, -21259,
-21361, -21460, -21554, -21643, -21723, -21795, -21855, -21904, -21941, -21963,
-21972, -21966, -21945, -21910, -21861, -21798, -21723, -21636, -21538, -21431,
-21317, -21198, -21075, -20950, -20825, -20703, -20586, -20475, -20372, -20281,
-20201, -20135, -20084, -20050, -20032, -20033, -20051, -20088, -20143, -20215,
-20304, -20408, -20526, -20657, -20798, -20947, -21102, -21261, -21421, -21579,
-21733, -21879, -22016, -22141, -22251, -22344, -22418, -22471, -22503, -22512,
-22496, -22456, -22392, -22304, -22193, -22060, -21906, -21734, -21546, -21345,
-21133, -20914, -20691, -20468, -20249, -20037, -19836, -19651, -19484, -19340,
-19221, -19130, -19071, -19045, -19055, -19101, -19184, -19305, -19463, -19657,
-19886, -20147, -20438, -20755, -21093, -21450, -21818, -22194, -22570, -22940,
-23298, -23637, -23950, -24229, -24468, -24659, -24795, -24871, -24879, -24814,
-24670, -24443, -24129, -23723, -23223, -22628, -21936, -21147, -20260, -19279,
-18205, -17041, -15792, -14462, -13057, -11583, -10048, -8458, -6823, -5150,
-3449, -1729, };
 
 #endif /* SQUARE2048_H_ */