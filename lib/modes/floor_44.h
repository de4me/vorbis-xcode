/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis SOFTWARE CODEC SOURCE CODE.   *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2001             *
 * by the XIPHOPHORUS Company http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************

 function: key floor settings for 44.1/48kHz
 last mod: $Id: floor_44.h,v 1.3 2002/06/28 22:19:54 xiphmont Exp $

 ********************************************************************/

#include "vorbis/codec.h"
#include "backends.h"
#include "books/floor/floor_books.h"

static static_codebook *_floor_44_128x4_books[]={
  &_huff_book_line_128x4_class0,
  &_huff_book_line_128x4_0sub0,
  &_huff_book_line_128x4_0sub1,
  &_huff_book_line_128x4_0sub2,
  &_huff_book_line_128x4_0sub3,
};
static static_codebook *_floor_44_128x7_books[]={
  &_huff_book_line_128x7_class0,
  &_huff_book_line_128x7_class1,
  
  &_huff_book_line_128x7_0sub1,
  &_huff_book_line_128x7_0sub2,
  &_huff_book_line_128x7_0sub3,
  &_huff_book_line_128x7_1sub1,
  &_huff_book_line_128x7_1sub2,
  &_huff_book_line_128x7_1sub3, 
};
static static_codebook *_floor_44_128x11_books[]={
  &_huff_book_line_128x11_class1,
  &_huff_book_line_128x11_class2,
  &_huff_book_line_128x11_class3,
  
  &_huff_book_line_128x11_0sub0,
  &_huff_book_line_128x11_1sub0,
  &_huff_book_line_128x11_1sub1,
  &_huff_book_line_128x11_2sub1,
  &_huff_book_line_128x11_2sub2,
  &_huff_book_line_128x11_2sub3, 
  &_huff_book_line_128x11_3sub1,
  &_huff_book_line_128x11_3sub2,
  &_huff_book_line_128x11_3sub3, 
};
static static_codebook *_floor_44_128x17_books[]={
  &_huff_book_line_128x17_class1,
  &_huff_book_line_128x17_class2,
  &_huff_book_line_128x17_class3,
  
  &_huff_book_line_128x17_0sub0,
  &_huff_book_line_128x17_1sub0,
  &_huff_book_line_128x17_1sub1,
  &_huff_book_line_128x17_2sub1,
  &_huff_book_line_128x17_2sub2,
  &_huff_book_line_128x17_2sub3, 
  &_huff_book_line_128x17_3sub1,
  &_huff_book_line_128x17_3sub2,
  &_huff_book_line_128x17_3sub3, 
};
static static_codebook *_floor_44_1024x27_books[]={
  &_huff_book_line_1024x27_class1,
  &_huff_book_line_1024x27_class2,
  &_huff_book_line_1024x27_class3,
  &_huff_book_line_1024x27_class4,
  
  &_huff_book_line_1024x27_0sub0,
  &_huff_book_line_1024x27_1sub0,
  &_huff_book_line_1024x27_1sub1,
  &_huff_book_line_1024x27_2sub0,
  &_huff_book_line_1024x27_2sub1,
  &_huff_book_line_1024x27_3sub1,
  &_huff_book_line_1024x27_3sub2,
  &_huff_book_line_1024x27_3sub3,
  &_huff_book_line_1024x27_4sub1,
  &_huff_book_line_1024x27_4sub2,
  &_huff_book_line_1024x27_4sub3,
};

static static_codebook **_floor_44_books[9]={
  _floor_44_128x4_books,
  _floor_44_128x4_books,
  _floor_44_128x7_books,
  _floor_44_128x7_books,
  _floor_44_128x11_books,
  _floor_44_128x17_books,
  _floor_44_128x17_books,
  _floor_44_1024x27_books,
  _floor_44_1024x27_books
};

static vorbis_info_floor1 _floor_44[9]={
  /* 128 x 4 */
  {
    1,{0},{4},{2},{0},
    {{1,2,3,4}},
    4,{0,128, 33,8,16,70},

    60,30,500,   0.,18.,  -1
  },
  /* 256 x 4 */
  {
    1,{0},{4},{2},{0},
    {{1,2,3,4}},
    4,{0,256, 66,16,32,140},

    60,30,500,   0.,18.,  -1
  },
  /* 128 x 7 */
  {
    2,{0,1},{3,4},{2,2},{0,1},
    {{-1,2,3,4},{-1,5,6,7}},
    4,{0,128, 14,4,58, 2,8,28,90},
    
    60,30,500,   0.,18.,  -1
  },
  /* 256 x 7 */
  {
    2,{0,1},{3,4},{2,2},{0,1},
    {{-1,2,3,4},{-1,5,6,7}},
    4,{0,256, 28,8,116, 4,16,56,180},
    
    60,30,500,   0.,18.,  -1
  },

  /* 128 x 11 */
  {
    4,{0,1,2,3},{2,3,3,3},{0,1,2,2},{-1,0,1,2},
    {{3},{4,5},{-1,6,7,8},{-1,9,10,11}},
    
    2,{0,128,  8,33,  4,16,70,  2,6,12,  23,46,90},
    
     60,30,500,   0,18.,  -1
  },
    
  /* 128 x 17 */
  {
    6,{0,1,1,2,3,3},{2,3,3,3},{0,1,2,2},{-1,0,1,2},
    {{3},{4,5},{-1,6,7,8},{-1,9,10,11}},
    2,{0,128,  12,46,  4,8,16,  23,33,70,  2,6,10,  14,19,28,  39,58,90},

    60,30,500,    0,18.,  -1 
  },
  
  /* 1024 x 17 */
  {
    6,{0,1,1,2,3,3},{2,3,3,3},{0,1,2,2},{-1,0,1,2},
    {{3},{4,5},{-1,6,7,8},{-1,9,10,11}},
    2,{0,1024,  93,372,  33,65,130,  186,260,556,  
       14,46,79,  111,158,220,  312,464,720},
    
    60,30,500,    0,18.,  -1 /* lowpass! */
  },
  /* 1024 x 27 */
  {
    8,{0,1,2,2,3,3,4,4},{3,4,3,4,3},{0,1,1,2,2},{-1,0,1,2,3},
    {{4},{5,6},{7,8},{-1,9,10,11},{-1,12,13,14}},
    2,{0,1024,   93,23,372, 6,46,186,750,  14,33,65, 130,260,556,
       3,10,18,28,  39,55,79,111,  158,220,312,  464,650,850},
    
    60,30,500,    3,18.,  -1 /* lowpass */
  },
  /* 2048 x 27 */
  {
    8,{0,1,2,2,3,3,4,4},{3,4,3,4,3},{0,1,1,2,2},{-1,0,1,2,3},
    {{4},{5,6},{7,8},{-1,9,10,11},{-1,12,13,14}},
    2,{0,2048,   186,46,744, 12,92,372,1500,  28,66,130, 260,520,1112,
       6,20,36,56,  78,110,158,222,  316,440,624,  928,1300,1700},
    
    60,30,500,    3,18.,  -1 /* lowpass */
  }
};
