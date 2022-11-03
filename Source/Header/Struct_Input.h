//=============================================================================
//
// 入力処理系構造体 [Struct_Input.h]
//
//=============================================================================
#ifndef _INPUTSTRUCT_H_
#define _INPUTSTRUCT_H_

#include <dinput.h>
#include <Windows.h>
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dinput8.lib")

/*キー情報*/
struct INPUTSTATE
{
	DWORD now;
	DWORD trg;
	DWORD ntrg;
};



//キー情報とか
static DIOBJECTDATAFORMAT diodfKeyData[] =
{
	{ &GUID_Key, 0, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(0), 0 },
	{ &GUID_Key, 1, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(1), 0 },
	{ &GUID_Key, 2, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(2), 0 },
	{ &GUID_Key, 3, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(3), 0 },
	{ &GUID_Key, 4, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(4), 0 },
	{ &GUID_Key, 5, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(5), 0 },
	{ &GUID_Key, 6, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(6), 0 },
	{ &GUID_Key, 7, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(7), 0 },
	{ &GUID_Key, 8, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(8), 0 },
	{ &GUID_Key, 9, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(9), 0 },
	{ &GUID_Key, 10, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(10), 0 },
	{ &GUID_Key, 11, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(11), 0 },
	{ &GUID_Key, 12, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(12), 0 },
	{ &GUID_Key, 13, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(13), 0 },
	{ &GUID_Key, 14, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(14), 0 },
	{ &GUID_Key, 15, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(15), 0 },
	{ &GUID_Key, 16, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(16), 0 },
	{ &GUID_Key, 17, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(17), 0 },
	{ &GUID_Key, 18, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(18), 0 },
	{ &GUID_Key, 19, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(19), 0 },
	{ &GUID_Key, 20, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(20), 0 },
	{ &GUID_Key, 21, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(21), 0 },
	{ &GUID_Key, 22, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(22), 0 },
	{ &GUID_Key, 23, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(23), 0 },
	{ &GUID_Key, 24, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(24), 0 },
	{ &GUID_Key, 25, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(25), 0 },
	{ &GUID_Key, 26, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(26), 0 },
	{ &GUID_Key, 27, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(27), 0 },
	{ &GUID_Key, 28, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(28), 0 },
	{ &GUID_Key, 29, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(29), 0 },
	{ &GUID_Key, 30, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(30), 0 },
	{ &GUID_Key, 31, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(31), 0 },
	{ &GUID_Key, 32, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(32), 0 },
	{ &GUID_Key, 33, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(33), 0 },
	{ &GUID_Key, 34, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(34), 0 },
	{ &GUID_Key, 35, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(35), 0 },
	{ &GUID_Key, 36, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(36), 0 },
	{ &GUID_Key, 37, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(37), 0 },
	{ &GUID_Key, 38, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(38), 0 },
	{ &GUID_Key, 39, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(39), 0 },
	{ &GUID_Key, 40, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(40), 0 },
	{ &GUID_Key, 41, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(41), 0 },
	{ &GUID_Key, 42, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(42), 0 },
	{ &GUID_Key, 43, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(43), 0 },
	{ &GUID_Key, 44, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(44), 0 },
	{ &GUID_Key, 45, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(45), 0 },
	{ &GUID_Key, 46, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(46), 0 },
	{ &GUID_Key, 47, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(47), 0 },
	{ &GUID_Key, 48, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(48), 0 },
	{ &GUID_Key, 49, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(49), 0 },
	{ &GUID_Key, 50, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(50), 0 },
	{ &GUID_Key, 51, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(51), 0 },
	{ &GUID_Key, 52, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(52), 0 },
	{ &GUID_Key, 53, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(53), 0 },
	{ &GUID_Key, 54, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(54), 0 },
	{ &GUID_Key, 55, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(55), 0 },
	{ &GUID_Key, 56, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(56), 0 },
	{ &GUID_Key, 57, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(57), 0 },
	{ &GUID_Key, 58, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(58), 0 },
	{ &GUID_Key, 59, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(59), 0 },
	{ &GUID_Key, 60, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(60), 0 },
	{ &GUID_Key, 61, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(61), 0 },
	{ &GUID_Key, 62, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(62), 0 },
	{ &GUID_Key, 63, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(63), 0 },
	{ &GUID_Key, 64, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(64), 0 },
	{ &GUID_Key, 65, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(65), 0 },
	{ &GUID_Key, 66, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(66), 0 },
	{ &GUID_Key, 67, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(67), 0 },
	{ &GUID_Key, 68, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(68), 0 },
	{ &GUID_Key, 69, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(69), 0 },
	{ &GUID_Key, 70, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(70), 0 },
	{ &GUID_Key, 71, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(71), 0 },
	{ &GUID_Key, 72, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(72), 0 },
	{ &GUID_Key, 73, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(73), 0 },
	{ &GUID_Key, 74, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(74), 0 },
	{ &GUID_Key, 75, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(75), 0 },
	{ &GUID_Key, 76, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(76), 0 },
	{ &GUID_Key, 77, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(77), 0 },
	{ &GUID_Key, 78, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(78), 0 },
	{ &GUID_Key, 79, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(79), 0 },
	{ &GUID_Key, 80, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(80), 0 },
	{ &GUID_Key, 81, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(81), 0 },
	{ &GUID_Key, 82, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(82), 0 },
	{ &GUID_Key, 83, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(83), 0 },
	{ &GUID_Key, 84, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(84), 0 },
	{ &GUID_Key, 85, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(85), 0 },
	{ &GUID_Key, 86, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(86), 0 },
	{ &GUID_Key, 87, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(87), 0 },
	{ &GUID_Key, 88, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(88), 0 },
	{ &GUID_Key, 89, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(89), 0 },
	{ &GUID_Key, 90, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(90), 0 },
	{ &GUID_Key, 91, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(91), 0 },
	{ &GUID_Key, 92, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(92), 0 },
	{ &GUID_Key, 93, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(93), 0 },
	{ &GUID_Key, 94, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(94), 0 },
	{ &GUID_Key, 95, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(95), 0 },
	{ &GUID_Key, 96, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(96), 0 },
	{ &GUID_Key, 97, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(97), 0 },
	{ &GUID_Key, 98, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(98), 0 },
	{ &GUID_Key, 99, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(99), 0 },
	{ &GUID_Key, 100, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(100), 0 },
	{ &GUID_Key, 101, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(101), 0 },
	{ &GUID_Key, 102, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(102), 0 },
	{ &GUID_Key, 103, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(103), 0 },
	{ &GUID_Key, 104, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(104), 0 },
	{ &GUID_Key, 105, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(105), 0 },
	{ &GUID_Key, 106, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(106), 0 },
	{ &GUID_Key, 107, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(107), 0 },
	{ &GUID_Key, 108, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(108), 0 },
	{ &GUID_Key, 109, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(109), 0 },
	{ &GUID_Key, 110, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(110), 0 },
	{ &GUID_Key, 111, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(111), 0 },
	{ &GUID_Key, 112, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(112), 0 },
	{ &GUID_Key, 113, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(113), 0 },
	{ &GUID_Key, 114, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(114), 0 },
	{ &GUID_Key, 115, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(115), 0 },
	{ &GUID_Key, 116, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(116), 0 },
	{ &GUID_Key, 117, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(117), 0 },
	{ &GUID_Key, 118, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(118), 0 },
	{ &GUID_Key, 119, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(119), 0 },
	{ &GUID_Key, 120, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(120), 0 },
	{ &GUID_Key, 121, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(121), 0 },
	{ &GUID_Key, 122, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(122), 0 },
	{ &GUID_Key, 123, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(123), 0 },
	{ &GUID_Key, 124, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(124), 0 },
	{ &GUID_Key, 125, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(125), 0 },
	{ &GUID_Key, 126, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(126), 0 },
	{ &GUID_Key, 127, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(127), 0 },
	{ &GUID_Key, 128, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(128), 0 },
	{ &GUID_Key, 129, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(129), 0 },
	{ &GUID_Key, 130, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(130), 0 },
	{ &GUID_Key, 131, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(131), 0 },
	{ &GUID_Key, 132, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(132), 0 },
	{ &GUID_Key, 133, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(133), 0 },
	{ &GUID_Key, 134, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(134), 0 },
	{ &GUID_Key, 135, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(135), 0 },
	{ &GUID_Key, 136, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(136), 0 },
	{ &GUID_Key, 137, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(137), 0 },
	{ &GUID_Key, 138, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(138), 0 },
	{ &GUID_Key, 139, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(139), 0 },
	{ &GUID_Key, 140, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(140), 0 },
	{ &GUID_Key, 141, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(141), 0 },
	{ &GUID_Key, 142, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(142), 0 },
	{ &GUID_Key, 143, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(143), 0 },
	{ &GUID_Key, 144, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(144), 0 },
	{ &GUID_Key, 145, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(145), 0 },
	{ &GUID_Key, 146, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(146), 0 },
	{ &GUID_Key, 147, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(147), 0 },
	{ &GUID_Key, 148, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(148), 0 },
	{ &GUID_Key, 149, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(149), 0 },
	{ &GUID_Key, 150, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(150), 0 },
	{ &GUID_Key, 151, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(151), 0 },
	{ &GUID_Key, 152, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(152), 0 },
	{ &GUID_Key, 153, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(153), 0 },
	{ &GUID_Key, 154, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(154), 0 },
	{ &GUID_Key, 155, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(155), 0 },
	{ &GUID_Key, 156, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(156), 0 },
	{ &GUID_Key, 157, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(157), 0 },
	{ &GUID_Key, 158, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(158), 0 },
	{ &GUID_Key, 159, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(159), 0 },
	{ &GUID_Key, 160, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(160), 0 },
	{ &GUID_Key, 161, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(161), 0 },
	{ &GUID_Key, 162, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(162), 0 },
	{ &GUID_Key, 163, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(163), 0 },
	{ &GUID_Key, 164, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(164), 0 },
	{ &GUID_Key, 165, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(165), 0 },
	{ &GUID_Key, 166, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(166), 0 },
	{ &GUID_Key, 167, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(167), 0 },
	{ &GUID_Key, 168, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(168), 0 },
	{ &GUID_Key, 169, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(169), 0 },
	{ &GUID_Key, 170, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(170), 0 },
	{ &GUID_Key, 171, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(171), 0 },
	{ &GUID_Key, 172, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(172), 0 },
	{ &GUID_Key, 173, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(173), 0 },
	{ &GUID_Key, 174, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(174), 0 },
	{ &GUID_Key, 175, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(175), 0 },
	{ &GUID_Key, 176, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(176), 0 },
	{ &GUID_Key, 177, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(177), 0 },
	{ &GUID_Key, 178, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(178), 0 },
	{ &GUID_Key, 179, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(179), 0 },
	{ &GUID_Key, 180, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(180), 0 },
	{ &GUID_Key, 181, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(181), 0 },
	{ &GUID_Key, 182, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(182), 0 },
	{ &GUID_Key, 183, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(183), 0 },
	{ &GUID_Key, 184, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(184), 0 },
	{ &GUID_Key, 185, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(185), 0 },
	{ &GUID_Key, 186, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(186), 0 },
	{ &GUID_Key, 187, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(187), 0 },
	{ &GUID_Key, 188, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(188), 0 },
	{ &GUID_Key, 189, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(189), 0 },
	{ &GUID_Key, 190, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(190), 0 },
	{ &GUID_Key, 191, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(191), 0 },
	{ &GUID_Key, 192, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(192), 0 },
	{ &GUID_Key, 193, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(193), 0 },
	{ &GUID_Key, 194, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(194), 0 },
	{ &GUID_Key, 195, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(195), 0 },
	{ &GUID_Key, 196, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(196), 0 },
	{ &GUID_Key, 197, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(197), 0 },
	{ &GUID_Key, 198, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(198), 0 },
	{ &GUID_Key, 199, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(199), 0 },
	{ &GUID_Key, 200, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(200), 0 },
	{ &GUID_Key, 201, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(201), 0 },
	{ &GUID_Key, 202, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(202), 0 },
	{ &GUID_Key, 203, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(203), 0 },
	{ &GUID_Key, 204, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(204), 0 },
	{ &GUID_Key, 205, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(205), 0 },
	{ &GUID_Key, 206, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(206), 0 },
	{ &GUID_Key, 207, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(207), 0 },
	{ &GUID_Key, 208, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(208), 0 },
	{ &GUID_Key, 209, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(209), 0 },
	{ &GUID_Key, 210, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(210), 0 },
	{ &GUID_Key, 211, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(211), 0 },
	{ &GUID_Key, 212, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(212), 0 },
	{ &GUID_Key, 213, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(213), 0 },
	{ &GUID_Key, 214, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(214), 0 },
	{ &GUID_Key, 215, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(215), 0 },
	{ &GUID_Key, 216, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(216), 0 },
	{ &GUID_Key, 217, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(217), 0 },
	{ &GUID_Key, 218, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(218), 0 },
	{ &GUID_Key, 219, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(219), 0 },
	{ &GUID_Key, 220, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(220), 0 },
	{ &GUID_Key, 221, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(221), 0 },
	{ &GUID_Key, 222, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(222), 0 },
	{ &GUID_Key, 223, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(223), 0 },
	{ &GUID_Key, 224, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(224), 0 },
	{ &GUID_Key, 225, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(225), 0 },
	{ &GUID_Key, 226, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(226), 0 },
	{ &GUID_Key, 227, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(227), 0 },
	{ &GUID_Key, 228, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(228), 0 },
	{ &GUID_Key, 229, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(229), 0 },
	{ &GUID_Key, 230, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(230), 0 },
	{ &GUID_Key, 231, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(231), 0 },
	{ &GUID_Key, 232, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(232), 0 },
	{ &GUID_Key, 233, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(233), 0 },
	{ &GUID_Key, 234, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(234), 0 },
	{ &GUID_Key, 235, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(235), 0 },
	{ &GUID_Key, 236, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(236), 0 },
	{ &GUID_Key, 237, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(237), 0 },
	{ &GUID_Key, 238, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(238), 0 },
	{ &GUID_Key, 239, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(239), 0 },
	{ &GUID_Key, 240, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(240), 0 },
	{ &GUID_Key, 241, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(241), 0 },
	{ &GUID_Key, 242, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(242), 0 },
	{ &GUID_Key, 243, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(243), 0 },
	{ &GUID_Key, 244, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(244), 0 },
	{ &GUID_Key, 245, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(245), 0 },
	{ &GUID_Key, 246, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(246), 0 },
	{ &GUID_Key, 247, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(247), 0 },
	{ &GUID_Key, 248, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(248), 0 },
	{ &GUID_Key, 249, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(249), 0 },
	{ &GUID_Key, 250, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(250), 0 },
	{ &GUID_Key, 251, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(251), 0 },
	{ &GUID_Key, 252, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(252), 0 },
	{ &GUID_Key, 253, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(253), 0 },
	{ &GUID_Key, 254, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(254), 0 },
	{ &GUID_Key, 255, 0x80000000 | DIDFT_BUTTON | DIDFT_MAKEINSTANCE(255), 0 }
};

//const DIDATAFORMAT c_dfDIKeyboard =
//{ 24, 16, DIDF_RELAXIS, 256, 256, &diodfKeyData[0] };

static DIOBJECTDATAFORMAT diodfJoyData[] =
{
	{ &GUID_XAxis, 0, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
	{ &GUID_YAxis, 4, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
	{ &GUID_ZAxis, 8, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
	{ &GUID_RxAxis, 12, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
	{ &GUID_RyAxis, 16, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
	{ &GUID_RzAxis, 20, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
	{ &GUID_Slider, 24, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
	{ &GUID_Slider, 28, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
	{ &GUID_POV, 32, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_POV, 0 },
	{ &GUID_POV, 36, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_POV, 0 },
	{ &GUID_POV, 40, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_POV, 0 },
	{ &GUID_POV, 44, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_POV, 0 },
	{ NULL, 48, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 49, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 50, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 51, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 52, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 53, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 54, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 55, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 56, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 57, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 58, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 59, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 60, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 61, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 62, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 63, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 64, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 65, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 66, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 67, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 68, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 69, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 70, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 71, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 72, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 73, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 74, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 75, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 76, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 77, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 78, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
	{ NULL, 79, 0x80000000 | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 }
};

//const DIDATAFORMAT c_dfDIJoystick =
//{ 24, 16, DIDF_ABSAXIS, 80, 44, &diodfJoyData[0] };

#endif