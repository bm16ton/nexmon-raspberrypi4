/***************************************************************************
 *                                                                         *
 *          ###########   ###########   ##########    ##########           *
 *         ############  ############  ############  ############          *
 *         ##            ##            ##   ##   ##  ##        ##          *
 *         ##            ##            ##   ##   ##  ##        ##          *
 *         ###########   ####  ######  ##   ##   ##  ##    ######          *
 *          ###########  ####  #       ##   ##   ##  ##    #    #          *
 *                   ##  ##    ######  ##   ##   ##  ##    #    #          *
 *                   ##  ##    #       ##   ##   ##  ##    #    #          *
 *         ############  ##### ######  ##   ##   ##  ##### ######          *
 *         ###########    ###########  ##   ##   ##   ##########           *
 *                                                                         *
 *            S E C U R E   M O B I L E   N E T W O R K I N G              *
 *                                                                         *
 * Warning:                                                                *
 *                                                                         *
 * Our software may damage your hardware and may void your hardware’s      *
 * warranty! You use our tools at your own risk and responsibility!        *
 *                                                                         *
 * License:                                                                *
 * Copyright (c) 2015 NexMon Team                                          *
 *                                                                         *
 * Permission is hereby granted, free of charge, to any person obtaining   *
 * a copy of this software and associated documentation files (the         *
 * "Software"), to deal in the Software without restriction, including     *
 * without limitation the rights to use, copy, modify, merge, publish,     *
 * distribute copies of the Software, and to permit persons to whom the    *
 * Software is furnished to do so, subject to the following conditions:    *
 *                                                                         *
 * The above copyright notice and this permission notice shall be included *
 * in all copies or substantial portions of the Software.                  *
 *                                                                         *
 * Any use of the Software which results in an academic publication or     *
 * other publication which includes a bibliography must include a citation *
 * to the author's publication "M. Schulz, D. Wegemer and M. Hollick.      *
 * NexMon: A Cookbook for Firmware Modifications on Smartphones to Enable  *
 * Monitor Mode.".                                                         *
 *                                                                         *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF              *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  *
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY    *
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,    *
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE       *
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                  *
 *                                                                         *
 **************************************************************************/
#pragma NEXMON targetregion "patch"

#include <firmware_version.h>
#include <channels.h>
#include <patcher.h>
#include <wrapper.h>
#include <channels.h>

unsigned short additional_valid_chanspecs[] = {
    CH20MHZ_CHSPEC(1),
    CH40MHZ_CHSPEC(2, WL_CHANSPEC_CTL_SB_U),
    CH40MHZ_CHSPEC(3, WL_CHANSPEC_CTL_SB_U),
    CH40MHZ_CHSPEC(4, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(5),
    CH40MHZ_CHSPEC(5, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(5, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(6),
    CH40MHZ_CHSPEC(6, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(6, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(7),
    CH40MHZ_CHSPEC(7, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(7, WL_CHANSPEC_CTL_SB_U),
    CH80MHZ_CHSPEC(7, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(8),
    CH40MHZ_CHSPEC(8, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(8, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(9),
    CH40MHZ_CHSPEC(9, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(9, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(10),
    CH40MHZ_CHSPEC(10, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(10, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(11),
    CH40MHZ_CHSPEC(11, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(11, WL_CHANSPEC_CTL_SB_U),
    CH80MHZ_CHSPEC(9, WL_CHANSPEC_CTL_SB_L),
    CH20MHZ_CHSPEC(12),
    CH40MHZ_CHSPEC(12, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(12, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(13),
    CH40MHZ_CHSPEC(13, WL_CHANSPEC_CTL_SB_L),
    CH80MHZ_CHSPEC(13, WL_CHANSPEC_CTL_SB_L),
    CH20MHZ_CHSPEC(14),
//    CH40MHZ_CHSPEC(14, WL_CHANSPEC_CTL_SB_L),
//    CH80MHZ_CHSPEC(14, WL_CHANSPEC_CTL_SB_L),
    CH20MHZ_CHSPEC(15),
    CH40MHZ_CHSPEC(15, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(16),
    CH40MHZ_CHSPEC(16, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(17),
    CH40MHZ_CHSPEC(17, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(17, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(18),
    CH40MHZ_CHSPEC(18, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(18, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(19),
    CH40MHZ_CHSPEC(19, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(19, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(20),
    CH40MHZ_CHSPEC(20, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(20, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(21),
    CH40MHZ_CHSPEC(21, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(21, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(22),
    CH40MHZ_CHSPEC(22, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(22, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(23),
    CH40MHZ_CHSPEC(23, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(23, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(24),
    CH40MHZ_CHSPEC(24, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(24, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(25),
    CH40MHZ_CHSPEC(25, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(25, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(26),
    CH40MHZ_CHSPEC(26, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(26, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(27),
    CH40MHZ_CHSPEC(27, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(27, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(28),
    CH40MHZ_CHSPEC(28, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(28, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(29), 
    CH40MHZ_CHSPEC(29, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(29, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(30),
    CH40MHZ_CHSPEC(30, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(30, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(31),
    CH40MHZ_CHSPEC(31, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(31, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(32),
//	CH80MHZ_CHSPEC(32, WL_CHANSPEC_CTL_SB_L),
//	CH80MHZ_CHSPEC(32, WL_CHANSPEC_CTL_SB_U),
    CH40MHZ_CHSPEC(32, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(32, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(33),
    CH40MHZ_CHSPEC(33, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(33, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(34),
//    CH80MHZ_CHSPEC(34, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(34, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(34, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(35),
    CH40MHZ_CHSPEC(35, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(35, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(37),
    CH40MHZ_CHSPEC(37, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(37, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(38),
    CH40MHZ_CHSPEC(38, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(38, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(39),
    CH40MHZ_CHSPEC(39, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(39, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(41),
    CH40MHZ_CHSPEC(41, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(41, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(42),
    CH40MHZ_CHSPEC(42, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(42, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(43),
    CH40MHZ_CHSPEC(43, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(43, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(45),
    CH40MHZ_CHSPEC(45, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(45, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(46),
    CH40MHZ_CHSPEC(46, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(46, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(47),
    CH40MHZ_CHSPEC(47, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(47, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(49),
    CH40MHZ_CHSPEC(49, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(49, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(50),
    CH40MHZ_CHSPEC(50, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(50, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(51),
    CH40MHZ_CHSPEC(51, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(51, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(53),
    CH40MHZ_CHSPEC(53, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(53, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(54),
    CH40MHZ_CHSPEC(54, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(54, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(55),
    CH40MHZ_CHSPEC(55, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(55, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(57),
    CH40MHZ_CHSPEC(57, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(57, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(58),
    CH40MHZ_CHSPEC(58, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(58, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(59),
    CH40MHZ_CHSPEC(59, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(59, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(61),
    CH40MHZ_CHSPEC(61, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(61, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(62),
    CH40MHZ_CHSPEC(62, WL_CHANSPEC_CTL_SB_L),
//    CH40MHZ_CHSPEC(62, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(63),
    CH40MHZ_CHSPEC(63, WL_CHANSPEC_CTL_SB_L),
    CH20MHZ_CHSPEC(64),
    CH40MHZ_CHSPEC(64, WL_CHANSPEC_CTL_SB_L),
    CH20MHZ_CHSPEC(99),
    CH40MHZ_CHSPEC(99, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(100),
    CH20MHZ_CHSPEC(101),
    CH40MHZ_CHSPEC(101, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(101, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(102),
    CH40MHZ_CHSPEC(102, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(102, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(103),
    CH40MHZ_CHSPEC(103, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(103, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(105),
    CH40MHZ_CHSPEC(105, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(105, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(106),
    CH40MHZ_CHSPEC(106, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(106, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(107),
    CH40MHZ_CHSPEC(107, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(107, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(109),
    CH40MHZ_CHSPEC(109, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(109, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(110),
    CH40MHZ_CHSPEC(110, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(110, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(111),
    CH40MHZ_CHSPEC(111, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(111, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(113),
    CH40MHZ_CHSPEC(113, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(113, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(114),
    CH40MHZ_CHSPEC(114, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(114, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(115),
    CH40MHZ_CHSPEC(115, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(115, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(116),
    CH40MHZ_CHSPEC(116, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(116, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(117),
    CH40MHZ_CHSPEC(117, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(117, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(118),
    CH40MHZ_CHSPEC(118, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(118, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(119),
    CH40MHZ_CHSPEC(119, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(119, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(120),
    CH40MHZ_CHSPEC(120, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(120, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(121),
    CH40MHZ_CHSPEC(121, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(121, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(122),
    CH40MHZ_CHSPEC(122, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(122, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(123),
    CH40MHZ_CHSPEC(123, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(123, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(125),
    CH40MHZ_CHSPEC(125, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(125, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(126),
    CH40MHZ_CHSPEC(126, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(126, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(127),
    CH40MHZ_CHSPEC(127, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(127, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(129),
    CH40MHZ_CHSPEC(129, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(129, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(130),
    CH40MHZ_CHSPEC(130, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(130, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(131),
    CH40MHZ_CHSPEC(131, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(131, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(133),
    CH40MHZ_CHSPEC(133, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(133, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(134),
    CH40MHZ_CHSPEC(134, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(134, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(135),
    CH40MHZ_CHSPEC(135, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(135, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(137),
    CH40MHZ_CHSPEC(137, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(137, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(138),
    CH40MHZ_CHSPEC(138, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(138, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(139),
    CH40MHZ_CHSPEC(139, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(139, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(140),
    CH80MHZ_CHSPEC(140, WL_CHANSPEC_CTL_SB_L),
    CH80MHZ_CHSPEC(140, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(141),
    CH40MHZ_CHSPEC(141, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(141, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(142),
    CH40MHZ_CHSPEC(142, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(142, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(143),
    CH40MHZ_CHSPEC(143, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(143, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(145),
    CH40MHZ_CHSPEC(145, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(145, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(146),
    CH40MHZ_CHSPEC(146, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(146, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(147),
    CH40MHZ_CHSPEC(147, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(147, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(148),
    CH40MHZ_CHSPEC(148, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(148, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(150),
    CH40MHZ_CHSPEC(150, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(150, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(151),
    CH40MHZ_CHSPEC(151, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(151, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(152),
    CH40MHZ_CHSPEC(152, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(152, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(154),
    CH40MHZ_CHSPEC(154, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(154, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(155),
    CH40MHZ_CHSPEC(155, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(155, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(156),
    CH40MHZ_CHSPEC(156, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(156, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(158),
    CH40MHZ_CHSPEC(158, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(158, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(159),
    CH40MHZ_CHSPEC(159, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(159, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(160),
    CH40MHZ_CHSPEC(160, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(160, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(162),
    CH40MHZ_CHSPEC(162, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(162, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(163),
    CH40MHZ_CHSPEC(163, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(163, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(164),
    CH40MHZ_CHSPEC(164, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(164, WL_CHANSPEC_CTL_SB_U),
//    CH40MHZ_CHSPEC(165, WL_CHANSPEC_CTL_SB_L),
//    CH40MHZ_CHSPEC(165, WL_CHANSPEC_CTL_SB_U),
//	CH80MHZ_CHSPEC(165, WL_CHANSPEC_CTL_SB_L),
//	CH80MHZ_CHSPEC(165, WL_CHANSPEC_CTL_SB_L),
    CH20MHZ_CHSPEC(166),
//    CH40MHZ_CHSPEC(166, WL_CHANSPEC_CTL_SB_L),
//    CH40MHZ_CHSPEC(166, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(167),
    CH20MHZ_CHSPEC(168),
    CH40MHZ_CHSPEC(168, WL_CHANSPEC_CTL_SB_L),
//    CH40MHZ_CHSPEC(168, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(169),
//    CH40MHZ_CHSPEC(169, WL_CHANSPEC_CTL_SB_L),
//    CH40MHZ_CHSPEC(169, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(170),
//    CH40MHZ_CHSPEC(170, WL_CHANSPEC_CTL_SB_L),
//    CH40MHZ_CHSPEC(170, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(171),
//  CH40MHZ_CHSPEC(171, WL_CHANSPEC_CTL_SB_L),
//  CH40MHZ_CHSPEC(171, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(172),
//  CH40MHZ_CHSPEC(172, WL_CHANSPEC_CTL_SB_L),
//  CH40MHZ_CHSPEC(172, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(173),
//	CH80MHZ_CHSPEC(173, WL_CHANSPEC_CTL_SB_L),
//	CH80MHZ_CHSPEC(173, WL_CHANSPEC_CTL_SB_L),
//  CH40MHZ_CHSPEC(173, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(173, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(174),
//  CH40MHZ_CHSPEC(174, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(174, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(175),
//  CH40MHZ_CHSPEC(175, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(175, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(176),
//  CH40MHZ_CHSPEC(176, WL_CHANSPEC_CTL_SB_L),
    CH40MHZ_CHSPEC(176, WL_CHANSPEC_CTL_SB_L),
    CH20MHZ_CHSPEC(177),
    CH40MHZ_CHSPEC(177, WL_CHANSPEC_CTL_SB_L),
//  CH40MHZ_CHSPEC(177, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(178),
    CH40MHZ_CHSPEC(178, WL_CHANSPEC_CTL_SB_L),
//  CH40MHZ_CHSPEC(178, WL_CHANSPEC_CTL_SB_U),
    CH20MHZ_CHSPEC(179),
    CH40MHZ_CHSPEC(179, WL_CHANSPEC_CTL_SB_L),
//    CH40MHZ_CHSPEC(179, WL_CHANSPEC_CTL_SB_U),
/*	CH20MHZ_CHSPEC(180),
//  CH40MHZ_CHSPEC(180, WL_CHANSPEC_CTL_SB_L),
//  CH40MHZ_CHSPEC(180, WL_CHANSPEC_CTL_SB_U),
	CH20MHZ_CHSPEC(181),
//  CH40MHZ_CHSPEC(181, WL_CHANSPEC_CTL_SB_L),
//  CH40MHZ_CHSPEC(181, WL_CHANSPEC_CTL_SB_U),
	CH20MHZ_CHSPEC(182),
//  CH40MHZ_CHSPEC(182, WL_CHANSPEC_CTL_SB_L),
//  CH40MHZ_CHSPEC(182, WL_CHANSPEC_CTL_SB_U),
	CH20MHZ_CHSPEC(183),
	CH20MHZ_CHSPEC(184),
	CH20MHZ_CHSPEC(185),
	CH20MHZ_CHSPEC(186),
	CH20MHZ_CHSPEC(187),
	CH20MHZ_CHSPEC(188),
	CH20MHZ_CHSPEC(189),
	CH20MHZ_CHSPEC(190),
	CH20MHZ_CHSPEC(191),
	CH20MHZ_CHSPEC(192),
	CH20MHZ_CHSPEC(193),
	CH20MHZ_CHSPEC(194),
	CH20MHZ_CHSPEC(195),
	CH20MHZ_CHSPEC(196),
	CH20MHZ_CHSPEC(197),
	CH20MHZ_CHSPEC(198),
	CH20MHZ_CHSPEC(199),
	CH20MHZ_CHSPEC(200),
	CH20MHZ_CHSPEC(201),
	CH20MHZ_CHSPEC(202),
	CH20MHZ_CHSPEC(203),
	CH20MHZ_CHSPEC(204),
	CH20MHZ_CHSPEC(205),
	CH20MHZ_CHSPEC(206),
	CH20MHZ_CHSPEC(207),
	CH20MHZ_CHSPEC(208),
	CH20MHZ_CHSPEC(209),
	CH20MHZ_CHSPEC(210),
	CH20MHZ_CHSPEC(211),
	CH20MHZ_CHSPEC(212),
	CH20MHZ_CHSPEC(213),
    CH20MHZ_CHSPEC(214),
    CH20MHZ_CHSPEC(215),
    CH20MHZ_CHSPEC(216),
*/
//    216 is max channel or issues with kernel driver compares
#if (NEXMON_CHIP == CHIP_VER_BCM43455c0)
//    	0xe02a, // 36/80
//    	0xe29b, // 157/80
// this appears the be the correct wat to setup 80mhz, these where in firmware and nevr changed for me
//the other way IE
//CH80MHZ_CHSPEC(162, WL_CHANSPEC_CTL_SB_L),
//CH80MHZ_CHSPEC(162, WL_CHANSPEC_CTL_SB_U),
//wouldt work for me and caused problems
//	0xe001,
//	0xe00a,
//	0xe010,
//	0xe01a,
//    0xe020, 
//    0xe022,
// 30  134 138 are invalid 	0xe120, 0xe08c, 0xe18c,
	0xe02a, //36
	0xe03a, //52
	0xe06a, //100
	0xe07a, //116
	0xe08a, //132
	0xe09b, //149
	0xe12a, //40
	0xe13a, //56
	0xe16a, //104
	0xe17a, //120
	0xe18a, //136
	0xe19b, //153
	0xe22a, //44
	0xe23a, //60
	0xe26a, //108
	0xe27a, //124
	0xe28a, //140
	0xe29b, //157
	0xe32a, //48
	0xe33a, //64
	0xe36a, //112
	0xe37a, //128
	0xe38a, //144
	0xe39b, //161
// chanels below 14 in 5ghz band add this way, and add chan to kernel driver
// this will create the chspec for it anyway not sure how to force the channel to it
/*	0xd0b9, //185
	0xd0ba,
	0xd0bb,
	0xd0bc,
	0xd0bd,
	0xd0be,
	0xd0c1,
	0xd0c2,
	0xd00f, //15 5ghz
	0xd00e, //channel 14 in 5ghz
	0xd00d,
	0xd00c,
	0xd00b,
	0xd016,
	0xd009,	//channel 9 in 5ghz
	0xd008,
	0xd007,
	0xd006,
	0xd005,
	0xd004,
	0xd003,
	0xd002,
	0xd001, //channel 1z in 5gh
*/
#endif
};

int
wlc_valid_chanspec_ext_hook(void *wlc_cm, unsigned short chanspec, int dualband)
{
	int valid = wlc_valid_chanspec_ext(wlc_cm, chanspec, dualband);
	int i;

	if (!valid && dualband == 1)
		for (i = 0; i < sizeof(additional_valid_chanspecs)/sizeof(additional_valid_chanspecs[0]); i++)
			valid |= additional_valid_chanspecs[i] == chanspec;

    return valid;
}

__attribute__((at(0x58eb6, "flashpatch", CHIP_VER_BCM43455c0, FW_VER_7_45_189)))
__attribute__((at(0x5BA28, "flashpatch", CHIP_VER_BCM4339, FW_VER_6_37_32_RC23_34_43_r639704)))
BPatch(wlc_valid_chanspec_ext, wlc_valid_chanspec_ext_hook)

// Overwrite the call to wlc_valid_chanspec_db() in wlc_radar_chanspec():
//      - clear "quiet" setting for the channel (so that it doesn't get muted)
//      - returns 0 to signal that it is not a radar sensitive channel
int
wlc_radar_chanspec_hook(void* wlc_cmi, unsigned short chanspec)
{
    printf("%s: Hook successful!\n", __FUNCTION__);
    wlc_clr_quiet_chanspec(wlc_cmi, chanspec);
    return 0;
}
__attribute__((at(0x58a0e, "flashpatch", CHIP_VER_BCM43455c0, FW_VER_7_45_189)))
BLPatch(wlc_valid_chanspec_db, wlc_radar_chanspec_hook)

