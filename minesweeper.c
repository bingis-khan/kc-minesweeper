#include <stddef.h>
#include <sys/ioctl.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <stdint.h>
int _global_argc;
const char** _global_argv;
static  const char*   from_dash_charlike0 (    const char*  s46 ) {
    return (  s46 );
}

static  char   from_dash_charlike1 (    const char*  s49 ) {
    return ( * ( ( (char * ) (  s49 ) ) ) );
}

static  int64_t   from_dash_integral2 (    int64_t  x57 ) {
    return (  x57 );
}

static  int32_t   from_dash_integral3 (    int64_t  x60 ) {
    return ( (int32_t ) (  x60 ) );
}

static  uint32_t   from_dash_integral4 (    int64_t  x63 ) {
    return ( (uint32_t ) (  x63 ) );
}

static  uint16_t   from_dash_integral5 (    int64_t  x66 ) {
    return ( (uint16_t ) (  x66 ) );
}

static  uint8_t   from_dash_integral6 (    int64_t  x72 ) {
    return ( (uint8_t ) (  x72 ) );
}

static  uint64_t   from_dash_integral7 (    int64_t  x75 ) {
    return ( (uint64_t ) (  x75 ) );
}

static  size_t   from_dash_integral8 (    int64_t  x78 ) {
    return ( (size_t ) (  x78 ) );
}

static  bool   eq9 (    int32_t  l94 ,    int32_t  r96 ) {
    return ( (  l94 ) == (  r96 ) );
}

static  bool   eq10 (    uint32_t  l99 ,    uint32_t  r101 ) {
    return ( (  l99 ) == (  r101 ) );
}

static  bool   eq11 (    uint8_t  l104 ,    uint8_t  r106 ) {
    return ( (  l104 ) == (  r106 ) );
}

static  bool   eq12 (    uint16_t  l109 ,    uint16_t  r111 ) {
    return ( (  l109 ) == (  r111 ) );
}

static  bool   eq13 (    size_t  l114 ,    size_t  r116 ) {
    return ( (  l114 ) == (  r116 ) );
}

static  bool   eq14 (    char  l129 ,    char  r131 ) {
    return ( (  l129 ) == (  r131 ) );
}

enum Color8_18 {
    Color8_18_Black8,
    Color8_18_Red8,
    Color8_18_Green8,
    Color8_18_Yellow8,
    Color8_18_Blue8,
    Color8_18_Magenta8,
    Color8_18_Cyan8,
    Color8_18_White8,
};

enum Color16_19 {
    Color16_19_Black16,
    Color16_19_Red16,
    Color16_19_Green16,
    Color16_19_Yellow16,
    Color16_19_Blue16,
    Color16_19_Magenta16,
    Color16_19_Cyan16,
    Color16_19_White16,
    Color16_19_BrightBlack16,
    Color16_19_BrightRed16,
    Color16_19_BrightGreen16,
    Color16_19_BrightYellow16,
    Color16_19_BrightBlue16,
    Color16_19_BrightMagenta16,
    Color16_19_BrightCyan16,
    Color16_19_BrightWhite16,
};

struct RGB_20 {
    uint8_t  f_r;
    uint8_t  f_g;
    uint8_t  f_b;
};

struct Color_17 {
    enum {
        Color_17_ColorDefault_t,
        Color_17_Color8_t,
        Color_17_Color16_t,
        Color_17_Color256_t,
        Color_17_ColorRGB_t,
    } tag;
    union {
        struct {
            enum Color8_18  field0;
        } Color_17_Color8_s;
        struct {
            enum Color16_19  field0;
        } Color_17_Color16_s;
        struct {
            uint8_t  field0;
        } Color_17_Color256_s;
        struct {
            struct RGB_20  field0;
        } Color_17_ColorRGB_s;
    } stuff;
};

static struct Color_17 Color_17_Color8 (  enum Color8_18  field0 ) {
    return ( struct Color_17 ) { .tag = Color_17_Color8_t, .stuff = { .Color_17_Color8_s = { .field0 = field0 } } };
};

static struct Color_17 Color_17_Color16 (  enum Color16_19  field0 ) {
    return ( struct Color_17 ) { .tag = Color_17_Color16_t, .stuff = { .Color_17_Color16_s = { .field0 = field0 } } };
};

static struct Color_17 Color_17_Color256 (  uint8_t  field0 ) {
    return ( struct Color_17 ) { .tag = Color_17_Color256_t, .stuff = { .Color_17_Color256_s = { .field0 = field0 } } };
};

static struct Color_17 Color_17_ColorRGB (  struct RGB_20  field0 ) {
    return ( struct Color_17 ) { .tag = Color_17_ColorRGB_t, .stuff = { .Color_17_ColorRGB_s = { .field0 = field0 } } };
};

struct Cell_16 {
    char  f_c;
    struct Color_17  f_fg;
    struct Color_17  f_bg;
};

struct Tuple2_23 {
    struct Color_17  field0;
    struct Color_17  field1;
};

static struct Tuple2_23 Tuple2_23_Tuple2 (  struct Color_17  field0 ,  struct Color_17  field1 ) {
    return ( struct Tuple2_23 ) { .field0 = field0 ,  .field1 = field1 };
};

static  void *   cast_dash_ptr29 (    int32_t *  p493 ) {
    return ( (void * ) (  p493 ) );
}

static  size_t   size_dash_of30 (    int32_t  x484 ) {
    return ( sizeof( (  x484 ) ) );
}

static  int32_t   zeroed27 (  ) {
    int32_t  temp28;
    int32_t  x500 = (  temp28 );
    ( ( memset ) ( ( (  cast_dash_ptr29 ) ( ( & (  x500 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of30 ) ( (  x500 ) ) ) ) );
    return (  x500 );
}

static  enum Color8_18 *   cast31 (    int32_t *  x490 ) {
    return ( (enum Color8_18 * ) (  x490 ) );
}

static  int32_t   cast_dash_on_dash_zeroed25 (    enum Color8_18  x503 ) {
    int32_t  temp26 = ( (  zeroed27 ) ( ) );
    int32_t *  y504 = ( &temp26 );
    enum Color8_18 *  yp505 = ( (  cast31 ) ( (  y504 ) ) );
    (*  yp505 ) = (  x503 );
    return ( * (  y504 ) );
}

static  bool   eq24 (    enum Color8_18  l2063 ,    enum Color8_18  r2065 ) {
    return (  eq9 ( ( ( (  cast_dash_on_dash_zeroed25 ) ( (  l2063 ) ) ) ) , ( (  cast_dash_on_dash_zeroed25 ) ( (  r2065 ) ) ) ) );
}

static  enum Color16_19 *   cast35 (    int32_t *  x490 ) {
    return ( (enum Color16_19 * ) (  x490 ) );
}

static  int32_t   cast_dash_on_dash_zeroed33 (    enum Color16_19  x503 ) {
    int32_t  temp34 = ( (  zeroed27 ) ( ) );
    int32_t *  y504 = ( &temp34 );
    enum Color16_19 *  yp505 = ( (  cast35 ) ( (  y504 ) ) );
    (*  yp505 ) = (  x503 );
    return ( * (  y504 ) );
}

static  bool   eq32 (    enum Color16_19  l2069 ,    enum Color16_19  r2071 ) {
    return (  eq9 ( ( ( (  cast_dash_on_dash_zeroed33 ) ( (  l2069 ) ) ) ) , ( (  cast_dash_on_dash_zeroed33 ) ( (  r2071 ) ) ) ) );
}

static  bool   eq36 (    struct RGB_20  l2099 ,    struct RGB_20  r2101 ) {
    return ( ( (  eq11 ( ( (  l2099 ) .f_r ) , ( (  r2101 ) .f_r ) ) ) && (  eq11 ( ( (  l2099 ) .f_g ) , ( (  r2101 ) .f_g ) ) ) ) && (  eq11 ( ( (  l2099 ) .f_b ) , ( (  r2101 ) .f_b ) ) ) );
}

static  bool   eq22 (    struct Color_17  l2122 ,    struct Color_17  r2124 ) {
    return ( {  struct Tuple2_23  dref2125 = ( ( Tuple2_23_Tuple2 ) ( (  l2122 ) ,  (  r2124 ) ) ) ; dref2125 .field0.tag == Color_17_ColorDefault_t && dref2125 .field1.tag == Color_17_ColorDefault_t ? ( true ) : dref2125 .field0.tag == Color_17_Color8_t && dref2125 .field1.tag == Color_17_Color8_t ? (  eq24 ( ( dref2125 .field0 .stuff .Color_17_Color8_s .field0 ) , ( dref2125 .field1 .stuff .Color_17_Color8_s .field0 ) ) ) : dref2125 .field0.tag == Color_17_Color16_t && dref2125 .field1.tag == Color_17_Color16_t ? (  eq32 ( ( dref2125 .field0 .stuff .Color_17_Color16_s .field0 ) , ( dref2125 .field1 .stuff .Color_17_Color16_s .field0 ) ) ) : dref2125 .field0.tag == Color_17_Color256_t && dref2125 .field1.tag == Color_17_Color256_t ? (  eq11 ( ( dref2125 .field0 .stuff .Color_17_Color256_s .field0 ) , ( dref2125 .field1 .stuff .Color_17_Color256_s .field0 ) ) ) : dref2125 .field0.tag == Color_17_ColorRGB_t && dref2125 .field1.tag == Color_17_ColorRGB_t ? (  eq36 ( ( dref2125 .field0 .stuff .Color_17_ColorRGB_s .field0 ) , ( dref2125 .field1 .stuff .Color_17_ColorRGB_s .field0 ) ) ) : ( false ) ; } );
}

static  bool   eq21 (    struct Cell_16  l2787 ,    struct Cell_16  r2789 ) {
    if ( ( !  eq14 ( ( (  l2787 ) .f_c ) , ( (  r2789 ) .f_c ) ) ) ) {
        return ( false );
    }
    if ( ( !  eq22 ( ( (  l2787 ) .f_fg ) , ( (  r2789 ) .f_fg ) ) ) ) {
        return ( false );
    }
    if ( ( !  eq22 ( ( (  l2787 ) .f_bg ) , ( (  r2789 ) .f_bg ) ) ) ) {
        return ( false );
    }
    return ( true );
}

static  bool   eq15 (    struct Cell_16 *  dref141 ,    struct Cell_16 *  dref143 ) {
    return (  eq21 ( ( (* dref141 ) ) , ( (* dref143 ) ) ) );
}

enum Ordering_38 {
    Ordering_38_LT,
    Ordering_38_EQ,
    Ordering_38_GT,
};

static int64_t builtin_int64_tcmp (int64_t l, int64_t r) {
    return (l < r) ? 0 : (l == r) ? 1 : 2;
}

static  enum Ordering_38   cmp37 (    int64_t  l147 ,    int64_t  r149 ) {
    return ( builtin_int64_tcmp( (  l147 ) , (  r149 ) ) );
}

static size_t builtin_size_tcmp (size_t l, size_t r) {
    return (l < r) ? 0 : (l == r) ? 1 : 2;
}

static  enum Ordering_38   cmp39 (    size_t  l152 ,    size_t  r154 ) {
    return ( builtin_size_tcmp( (  l152 ) , (  r154 ) ) );
}

static int32_t builtin_int32_tcmp (int32_t l, int32_t r) {
    return (l < r) ? 0 : (l == r) ? 1 : 2;
}

static  enum Ordering_38   cmp40 (    int32_t  l157 ,    int32_t  r159 ) {
    return ( builtin_int32_tcmp( (  l157 ) , (  r159 ) ) );
}

static uint32_t builtin_uint32_tcmp (uint32_t l, uint32_t r) {
    return (l < r) ? 0 : (l == r) ? 1 : 2;
}

static  enum Ordering_38   cmp41 (    uint32_t  l162 ,    uint32_t  r164 ) {
    return ( builtin_uint32_tcmp( (  l162 ) , (  r164 ) ) );
}

static uint8_t builtin_uint8_tcmp (uint8_t l, uint8_t r) {
    return (l < r) ? 0 : (l == r) ? 1 : 2;
}

static  enum Ordering_38   cmp42 (    uint8_t  l167 ,    uint8_t  r169 ) {
    return ( builtin_uint8_tcmp( (  l167 ) , (  r169 ) ) );
}

static  int64_t   op_dash_add43 (    int64_t  l177 ,    int64_t  r179 ) {
    return ( (  l177 ) + (  r179 ) );
}

static  int64_t   op_dash_sub44 (    int64_t  l182 ,    int64_t  r184 ) {
    return ( (  l182 ) - (  r184 ) );
}

static  int64_t   op_dash_mul45 (    int64_t  l187 ,    int64_t  r189 ) {
    return ( (  l187 ) * (  r189 ) );
}

static  int64_t   op_dash_div46 (    int64_t  l192 ,    int64_t  r194 ) {
    return ( (  l192 ) / (  r194 ) );
}

static  int32_t   op_dash_add47 (    int32_t  l200 ,    int32_t  r202 ) {
    return ( (  l200 ) + (  r202 ) );
}

static  int32_t   op_dash_sub48 (    int32_t  l205 ,    int32_t  r207 ) {
    return ( (  l205 ) - (  r207 ) );
}

static  int32_t   op_dash_mul49 (    int32_t  l210 ,    int32_t  r212 ) {
    return ( (  l210 ) * (  r212 ) );
}

static  int32_t   op_dash_div50 (    int32_t  l215 ,    int32_t  r217 ) {
    return ( (  l215 ) / (  r217 ) );
}

static  int32_t   op_dash_neg51 (    int32_t  x220 ) {
    return ( (  from_dash_integral3 ( 0 ) ) - (  x220 ) );
}

static  uint32_t   op_dash_add52 (    uint32_t  l223 ,    uint32_t  r225 ) {
    return ( (  l223 ) + (  r225 ) );
}

static  uint32_t   op_dash_sub53 (    uint32_t  l228 ,    uint32_t  r230 ) {
    return ( (  l228 ) - (  r230 ) );
}

static  uint32_t   op_dash_mul54 (    uint32_t  l233 ,    uint32_t  r235 ) {
    return ( (  l233 ) * (  r235 ) );
}

static  uint32_t   op_dash_div55 (    uint32_t  l238 ,    uint32_t  r240 ) {
    return ( (  l238 ) / (  r240 ) );
}

static  uint8_t   op_dash_add56 (    uint8_t  l243 ,    uint8_t  r245 ) {
    return ( (  l243 ) + (  r245 ) );
}

static  uint8_t   op_dash_sub57 (    uint8_t  l248 ,    uint8_t  r250 ) {
    return ( (  l248 ) - (  r250 ) );
}

static  size_t   op_dash_add58 (    size_t  l263 ,    size_t  r265 ) {
    return ( (  l263 ) + (  r265 ) );
}

static  size_t   op_dash_sub59 (    size_t  l268 ,    size_t  r270 ) {
    return ( (  l268 ) - (  r270 ) );
}

static  size_t   op_dash_mul60 (    size_t  l273 ,    size_t  r275 ) {
    return ( (  l273 ) * (  r275 ) );
}

struct Array_63 {
    uint32_t _arr [4];
};

struct SmolArray_62 {
    struct Array_63  f_arr;
};

static  struct SmolArray_62   from_dash_listlike61 (    struct Array_63  arr307 ) {
    return ( (struct SmolArray_62) { .f_arr = (  arr307 ) } );
}

struct Array_66 {
    uint32_t _arr [5];
};

struct SmolArray_65 {
    struct Array_66  f_arr;
};

static  struct SmolArray_65   from_dash_listlike64 (    struct Array_66  arr307 ) {
    return ( (struct SmolArray_65) { .f_arr = (  arr307 ) } );
}

struct Array_69 {
    uint32_t _arr [1];
};

struct SmolArray_68 {
    struct Array_69  f_arr;
};

static  struct SmolArray_68   from_dash_listlike67 (    struct Array_69  arr307 ) {
    return ( (struct SmolArray_68) { .f_arr = (  arr307 ) } );
}

struct Array_72 {
    int32_t _arr [3];
};

struct SmolArray_71 {
    struct Array_72  f_arr;
};

static  struct SmolArray_71   from_dash_listlike70 (    struct Array_72  arr307 ) {
    return ( (struct SmolArray_71) { .f_arr = (  arr307 ) } );
}

static  int32_t   clock_dash_monotonic73 (  ) {
    return (  from_dash_integral3 ( 1 ) );
}

struct Stat_75 {
    uint64_t  f_dev;
    uint64_t  f_ino;
    uint64_t  f_nlink;
    uint32_t  f_mode;
    uint32_t  f_uid;
    uint32_t  f_gid;
    uint32_t  f_pad0;
    uint64_t  f_rdev;
    int64_t  f_size;
    int64_t  f_blksize;
    int64_t  f_blocks;
    struct timespec  f_atim;
    struct timespec  f_mtim;
    struct timespec  f_ctim;
    int64_t  f_unused1;
    int64_t  f_unused2;
    int64_t  f_unused3;
};

static  void*   ptr_dash_castptr74 (    struct Stat_75 *  ptr326 ) {
    return ( (void* ) (  ptr326 ) );
}

static  int32_t   seek_dash_set76 (  ) {
    return (  from_dash_integral3 ( 0 ) );
}

static  int32_t   seek_dash_end77 (  ) {
    return (  from_dash_integral3 ( 2 ) );
}

static  int32_t   stdout_dash_fileno78 (  ) {
    return (  from_dash_integral3 ( 1 ) );
}

static  int32_t   stdin_dash_fileno79 (  ) {
    return (  from_dash_integral3 ( 0 ) );
}

static  uint32_t   echo80 (  ) {
    return (  from_dash_integral4 ( 8 ) );
}

static  uint32_t   icanon81 (  ) {
    return (  from_dash_integral4 ( 2 ) );
}

static  uint32_t   isig82 (  ) {
    return (  from_dash_integral4 ( 1 ) );
}

static  uint32_t   iexten83 (  ) {
    return (  from_dash_integral4 ( 32768 ) );
}

static  uint32_t   brkint84 (  ) {
    return (  from_dash_integral4 ( 2 ) );
}

static  uint32_t   icrnl85 (  ) {
    return (  from_dash_integral4 ( 256 ) );
}

static  uint32_t   inpck86 (  ) {
    return (  from_dash_integral4 ( 16 ) );
}

static  uint32_t   istrip87 (  ) {
    return (  from_dash_integral4 ( 32 ) );
}

static  uint32_t   ixon88 (  ) {
    return (  from_dash_integral4 ( 1024 ) );
}

static  uint32_t   opost89 (  ) {
    return (  from_dash_integral4 ( 1 ) );
}

static  uint32_t   cs890 (  ) {
    return (  from_dash_integral4 ( 48 ) );
}

static  size_t   vmin91 (  ) {
    return (  from_dash_integral8 ( 6 ) );
}

static  size_t   vtime92 (  ) {
    return (  from_dash_integral8 ( 5 ) );
}

static  int32_t   tcsa_dash_flush93 (  ) {
    return (  from_dash_integral3 ( 2 ) );
}

static  uint64_t   tiocgwinsz94 (  ) {
    return (  from_dash_integral7 ( 21523 ) );
}

static  bool   errno_dash_EEXIST95 (  ) {
    return (  eq9 ( ( errno ) , (  from_dash_integral3 ( 17 ) ) ) );
}

static  uint32_t   s_dash_ifmt96 (  ) {
    return (  from_dash_integral4 ( 61440 ) );
}

static  uint32_t   s_dash_ifdir97 (  ) {
    return (  from_dash_integral4 ( 16384 ) );
}

static  int64_t   undefined98 (  ) {
    int64_t  temp99;
    return (  temp99 );
}

static  char   undefined100 (  ) {
    char  temp101;
    return (  temp101 );
}

struct Tile_104 {
    bool  f_hidden;
    bool  f_is_dash_bomb;
    bool  f_flagged;
};

struct Slice_103 {
    struct Tile_104 *  f_ptr;
    size_t  f_count;
};

static  struct Slice_103   undefined102 (  ) {
    struct Slice_103  temp105;
    return (  temp105 );
}

static  struct Tile_104   undefined106 (  ) {
    struct Tile_104  temp107;
    return (  temp107 );
}

struct Array_110 {
    uint8_t _arr [32];
};

struct Termios_109 {
    uint32_t  f_c_dash_iflag;
    uint32_t  f_c_dash_oflag;
    uint32_t  f_c_dash_cflag;
    uint32_t  f_c_dash_lflag;
    uint8_t  f_c_dash_line;
    struct Array_110  f_c_dash_cc;
    uint32_t  f_c_dash_ispeed;
    uint32_t  f_c_dash_ospeed;
};

static  struct Termios_109   undefined108 (  ) {
    struct Termios_109  temp111;
    return (  temp111 );
}

static  struct timespec   undefined112 (  ) {
    struct timespec  temp113;
    return (  temp113 );
}

static  struct Cell_16   undefined114 (  ) {
    struct Cell_16  temp115;
    return (  temp115 );
}

static  uint8_t   undefined116 (  ) {
    uint8_t  temp117;
    return (  temp117 );
}

enum MouseButton_119 {
    MouseButton_119_MouseLeft,
    MouseButton_119_MouseMiddle,
    MouseButton_119_MouseRight,
    MouseButton_119_ScrollUp,
    MouseButton_119_ScrollDown,
};

static  enum MouseButton_119   undefined118 (  ) {
    enum MouseButton_119  temp120;
    return (  temp120 );
}

static  bool   undefined121 (  ) {
    bool  temp122;
    return (  temp122 );
}

static  struct Stat_75   undefined123 (  ) {
    struct Stat_75  temp124;
    return (  temp124 );
}

static  struct Cell_16 *   undefined125 (  ) {
    struct Cell_16 *  temp126;
    return (  temp126 );
}

static  const char* *   offset_dash_ptr127 (    const char* *  x477 ,    int64_t  count479 ) {
    const char*  temp128;
    return ( (const char* * ) ( ( (void*) (  x477 ) ) + (  op_dash_mul45 ( (  count479 ) , ( (int64_t ) ( sizeof( ( (  temp128 ) ) ) ) ) ) ) ) );
}

static  char *   offset_dash_ptr129 (    char *  x477 ,    int64_t  count479 ) {
    char  temp130;
    return ( (char * ) ( ( (void*) (  x477 ) ) + (  op_dash_mul45 ( (  count479 ) , ( (int64_t ) ( sizeof( ( (  temp130 ) ) ) ) ) ) ) ) );
}

static  struct Slice_103 *   offset_dash_ptr131 (    struct Slice_103 *  x477 ,    int64_t  count479 ) {
    struct Slice_103  temp132;
    return ( (struct Slice_103 * ) ( ( (void*) (  x477 ) ) + (  op_dash_mul45 ( (  count479 ) , ( (int64_t ) ( sizeof( ( (  temp132 ) ) ) ) ) ) ) ) );
}

static  struct Tile_104 *   offset_dash_ptr133 (    struct Tile_104 *  x477 ,    int64_t  count479 ) {
    struct Tile_104  temp134;
    return ( (struct Tile_104 * ) ( ( (void*) (  x477 ) ) + (  op_dash_mul45 ( (  count479 ) , ( (int64_t ) ( sizeof( ( (  temp134 ) ) ) ) ) ) ) ) );
}

static  uint8_t *   offset_dash_ptr135 (    uint8_t *  x477 ,    int64_t  count479 ) {
    uint8_t  temp136;
    return ( (uint8_t * ) ( ( (void*) (  x477 ) ) + (  op_dash_mul45 ( (  count479 ) , ( (int64_t ) ( sizeof( ( (  temp136 ) ) ) ) ) ) ) ) );
}

static  uint32_t *   offset_dash_ptr137 (    uint32_t *  x477 ,    int64_t  count479 ) {
    uint32_t  temp138;
    return ( (uint32_t * ) ( ( (void*) (  x477 ) ) + (  op_dash_mul45 ( (  count479 ) , ( (int64_t ) ( sizeof( ( (  temp138 ) ) ) ) ) ) ) ) );
}

static  struct Cell_16 *   offset_dash_ptr139 (    struct Cell_16 *  x477 ,    int64_t  count479 ) {
    struct Cell_16  temp140;
    return ( (struct Cell_16 * ) ( ( (void*) (  x477 ) ) + (  op_dash_mul45 ( (  count479 ) , ( (int64_t ) ( sizeof( ( (  temp140 ) ) ) ) ) ) ) ) );
}

static  int32_t *   offset_dash_ptr141 (    int32_t *  x477 ,    int64_t  count479 ) {
    int32_t  temp142;
    return ( (int32_t * ) ( ( (void*) (  x477 ) ) + (  op_dash_mul45 ( (  count479 ) , ( (int64_t ) ( sizeof( ( (  temp142 ) ) ) ) ) ) ) ) );
}

struct TypeSize_144 {
    size_t  f_size;
};

static  struct TypeSize_144   get_dash_typesize143 (  ) {
    char  temp145;
    return ( (struct TypeSize_144) { .f_size = ( sizeof( ( (  temp145 ) ) ) ) } );
}

struct TypeSize_147 {
    size_t  f_size;
};

static  struct TypeSize_147   get_dash_typesize146 (  ) {
    struct Slice_103  temp148;
    return ( (struct TypeSize_147) { .f_size = ( sizeof( ( (  temp148 ) ) ) ) } );
}

struct TypeSize_150 {
    size_t  f_size;
};

static  struct TypeSize_150   get_dash_typesize149 (  ) {
    struct Tile_104  temp151;
    return ( (struct TypeSize_150) { .f_size = ( sizeof( ( (  temp151 ) ) ) ) } );
}

struct TypeSize_153 {
    size_t  f_size;
};

static  struct TypeSize_153   get_dash_typesize152 (  ) {
    struct Cell_16  temp154;
    return ( (struct TypeSize_153) { .f_size = ( sizeof( ( (  temp154 ) ) ) ) } );
}

static  size_t   size_dash_of155 (    void *  x484 ) {
    return ( sizeof( (  x484 ) ) );
}

static  size_t   size_dash_of156 (    FILE *  x484 ) {
    return ( sizeof( (  x484 ) ) );
}

static  size_t   size_dash_of157 (    char  x484 ) {
    return ( sizeof( (  x484 ) ) );
}

static  size_t   size_dash_of158 (    char *  x484 ) {
    return ( sizeof( (  x484 ) ) );
}

enum Unit_160 {
    Unit_160_Unit,
};

static  size_t   size_dash_of159 (    enum Unit_160 *  x484 ) {
    return ( sizeof( (  x484 ) ) );
}

static  size_t   size_dash_of161 (    uint32_t  x484 ) {
    return ( sizeof( (  x484 ) ) );
}

struct Winsize_163 {
    uint16_t  f_ws_dash_row;
    uint16_t  f_ws_dash_col;
    uint16_t  f_ws_dash_xpixel;
    uint16_t  f_ws_dash_ypixel;
};

static  size_t   size_dash_of162 (    struct Winsize_163  x484 ) {
    return ( sizeof( (  x484 ) ) );
}

static  size_t   size_dash_of164 (    size_t  x484 ) {
    return ( sizeof( (  x484 ) ) );
}

static  size_t   size_dash_of165 (    int64_t  x484 ) {
    return ( sizeof( (  x484 ) ) );
}

struct Array_167 {
    char _arr [32];
};

static  size_t   size_dash_of166 (    struct Array_167  x484 ) {
    return ( sizeof( (  x484 ) ) );
}

static  size_t   size_dash_of168 (    struct timespec *  x484 ) {
    return ( sizeof( (  x484 ) ) );
}

static  uint32_t   cast169 (    int32_t  x490 ) {
    return ( (uint32_t ) (  x490 ) );
}

static  char *   cast170 (    const char*  x490 ) {
    return ( (char * ) (  x490 ) );
}

static  char *   cast171 (    int32_t *  x490 ) {
    return ( (char * ) (  x490 ) );
}

static  const char*   cast172 (    char *  x490 ) {
    return ( (const char* ) (  x490 ) );
}

static  enum Unit_160 *   cast173 (    const char*  x490 ) {
    return ( (enum Unit_160 * ) (  x490 ) );
}

static  int32_t   cast174 (    uint32_t  x490 ) {
    return ( (int32_t ) (  x490 ) );
}

static  uint16_t *   cast175 (    uint32_t *  x490 ) {
    return ( (uint16_t * ) (  x490 ) );
}

static  uint32_t *   cast176 (    size_t *  x490 ) {
    return ( (uint32_t * ) (  x490 ) );
}

static  uint8_t *   cast177 (    int64_t *  x490 ) {
    return ( (uint8_t * ) (  x490 ) );
}

static  uint8_t   cast178 (    char  x490 ) {
    return ( (uint8_t ) (  x490 ) );
}

static  char *   cast179 (    struct Array_167 *  x490 ) {
    return ( (char * ) (  x490 ) );
}

static  char   cast180 (    int32_t  x490 ) {
    return ( (char ) (  x490 ) );
}

static  enum MouseButton_119 *   cast181 (    uint32_t *  x490 ) {
    return ( (enum MouseButton_119 * ) (  x490 ) );
}

static  char   cast182 (    uint32_t  x490 ) {
    return ( (char ) (  x490 ) );
}

static  uint8_t *   cast183 (    int32_t *  x490 ) {
    return ( (uint8_t * ) (  x490 ) );
}

static  void *   cast_dash_ptr184 (    void * *  p493 ) {
    return ( (void * ) (  p493 ) );
}

static  char *   cast_dash_ptr185 (    void *  p493 ) {
    return ( (char * ) (  p493 ) );
}

static  void *   cast_dash_ptr186 (    FILE * *  p493 ) {
    return ( (void * ) (  p493 ) );
}

static  void *   cast_dash_ptr187 (    char *  p493 ) {
    return ( (void * ) (  p493 ) );
}

static  void *   cast_dash_ptr188 (    enum Unit_160 *  p493 ) {
    return ( (void * ) (  p493 ) );
}

static  void *   cast_dash_ptr189 (    char * *  p493 ) {
    return ( (void * ) (  p493 ) );
}

static  void *   cast_dash_ptr190 (    enum Unit_160 * *  p493 ) {
    return ( (void * ) (  p493 ) );
}

static  struct Slice_103 *   cast_dash_ptr191 (    void *  p493 ) {
    return ( (struct Slice_103 * ) (  p493 ) );
}

static  struct Tile_104 *   cast_dash_ptr192 (    void *  p493 ) {
    return ( (struct Tile_104 * ) (  p493 ) );
}

static  void *   cast_dash_ptr193 (    uint32_t *  p493 ) {
    return ( (void * ) (  p493 ) );
}

static  void *   cast_dash_ptr194 (    struct Winsize_163 *  p493 ) {
    return ( (void * ) (  p493 ) );
}

static  struct termios *   cast_dash_ptr195 (    struct Termios_109 *  p493 ) {
    return ( (struct termios * ) (  p493 ) );
}

static  uint8_t *   cast_dash_ptr196 (    struct Array_110 *  p493 ) {
    return ( (uint8_t * ) (  p493 ) );
}

static  uint32_t *   cast_dash_ptr197 (    struct Array_69 *  p493 ) {
    return ( (uint32_t * ) (  p493 ) );
}

static  uint32_t *   cast_dash_ptr198 (    struct Array_66 *  p493 ) {
    return ( (uint32_t * ) (  p493 ) );
}

static  uint32_t *   cast_dash_ptr199 (    struct Array_63 *  p493 ) {
    return ( (uint32_t * ) (  p493 ) );
}

static  struct Cell_16 *   cast_dash_ptr200 (    void *  p493 ) {
    return ( (struct Cell_16 * ) (  p493 ) );
}

static  void *   cast_dash_ptr201 (    size_t *  p493 ) {
    return ( (void * ) (  p493 ) );
}

static  void *   cast_dash_ptr202 (    int64_t *  p493 ) {
    return ( (void * ) (  p493 ) );
}

static  char *   cast_dash_ptr203 (    struct Array_167 *  p493 ) {
    return ( (char * ) (  p493 ) );
}

static  void *   cast_dash_ptr204 (    struct Array_167 *  p493 ) {
    return ( (void * ) (  p493 ) );
}

struct Pollfd_206 {
    int32_t  f_fd;
    uint16_t  f_events;
    uint16_t  f_revents;
};

static  struct pollfd *   cast_dash_ptr205 (    struct Pollfd_206 *  p493 ) {
    return ( (struct pollfd * ) (  p493 ) );
}

static  int32_t *   cast_dash_ptr207 (    struct Array_72 *  p493 ) {
    return ( (int32_t * ) (  p493 ) );
}

static  void *   cast_dash_ptr208 (    struct timespec * *  p493 ) {
    return ( (void * ) (  p493 ) );
}

static  void *   cast_dash_ptr209 (    struct Cell_16 *  p493 ) {
    return ( (void * ) (  p493 ) );
}

static  void *   zeroed210 (  ) {
    void *  temp211;
    void *  x500 = (  temp211 );
    ( ( memset ) ( ( (  cast_dash_ptr184 ) ( ( & (  x500 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of155 ) ( (  x500 ) ) ) ) );
    return (  x500 );
}

static  FILE *   zeroed212 (  ) {
    FILE *  temp213;
    FILE *  x500 = (  temp213 );
    ( ( memset ) ( ( (  cast_dash_ptr186 ) ( ( & (  x500 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of156 ) ( (  x500 ) ) ) ) );
    return (  x500 );
}

static  char   zeroed214 (  ) {
    char  temp215;
    char  x500 = (  temp215 );
    ( ( memset ) ( ( (  cast_dash_ptr187 ) ( ( & (  x500 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of157 ) ( (  x500 ) ) ) ) );
    return (  x500 );
}

static  char *   zeroed216 (  ) {
    char *  temp217;
    char *  x500 = (  temp217 );
    ( ( memset ) ( ( (  cast_dash_ptr189 ) ( ( & (  x500 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of158 ) ( (  x500 ) ) ) ) );
    return (  x500 );
}

static  enum Unit_160 *   zeroed218 (  ) {
    enum Unit_160 *  temp219;
    enum Unit_160 *  x500 = (  temp219 );
    ( ( memset ) ( ( (  cast_dash_ptr190 ) ( ( & (  x500 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of159 ) ( (  x500 ) ) ) ) );
    return (  x500 );
}

static  uint32_t   zeroed220 (  ) {
    uint32_t  temp221;
    uint32_t  x500 = (  temp221 );
    ( ( memset ) ( ( (  cast_dash_ptr193 ) ( ( & (  x500 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of161 ) ( (  x500 ) ) ) ) );
    return (  x500 );
}

static  struct Winsize_163   zeroed222 (  ) {
    struct Winsize_163  temp223;
    struct Winsize_163  x500 = (  temp223 );
    ( ( memset ) ( ( (  cast_dash_ptr194 ) ( ( & (  x500 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of162 ) ( (  x500 ) ) ) ) );
    return (  x500 );
}

static  size_t   zeroed224 (  ) {
    size_t  temp225;
    size_t  x500 = (  temp225 );
    ( ( memset ) ( ( (  cast_dash_ptr201 ) ( ( & (  x500 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of164 ) ( (  x500 ) ) ) ) );
    return (  x500 );
}

static  int64_t   zeroed226 (  ) {
    int64_t  temp227;
    int64_t  x500 = (  temp227 );
    ( ( memset ) ( ( (  cast_dash_ptr202 ) ( ( & (  x500 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of165 ) ( (  x500 ) ) ) ) );
    return (  x500 );
}

static  struct Array_167   zeroed228 (  ) {
    struct Array_167  temp229;
    struct Array_167  x500 = (  temp229 );
    ( ( memset ) ( ( (  cast_dash_ptr204 ) ( ( & (  x500 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of166 ) ( (  x500 ) ) ) ) );
    return (  x500 );
}

static  struct timespec *   zeroed230 (  ) {
    struct timespec *  temp231;
    struct timespec *  x500 = (  temp231 );
    ( ( memset ) ( ( (  cast_dash_ptr208 ) ( ( & (  x500 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of168 ) ( (  x500 ) ) ) ) );
    return (  x500 );
}

static  int32_t   cast_dash_on_dash_zeroed232 (    char  x503 ) {
    int32_t  temp233 = ( (  zeroed27 ) ( ) );
    int32_t *  y504 = ( &temp233 );
    char *  yp505 = ( (  cast171 ) ( (  y504 ) ) );
    (*  yp505 ) = (  x503 );
    return ( * (  y504 ) );
}

static  uint32_t   cast_dash_on_dash_zeroed234 (    uint16_t  x503 ) {
    uint32_t  temp235 = ( (  zeroed220 ) ( ) );
    uint32_t *  y504 = ( &temp235 );
    uint16_t *  yp505 = ( (  cast175 ) ( (  y504 ) ) );
    (*  yp505 ) = (  x503 );
    return ( * (  y504 ) );
}

static  size_t   cast_dash_on_dash_zeroed236 (    uint32_t  x503 ) {
    size_t  temp237 = ( (  zeroed224 ) ( ) );
    size_t *  y504 = ( &temp237 );
    uint32_t *  yp505 = ( (  cast176 ) ( (  y504 ) ) );
    (*  yp505 ) = (  x503 );
    return ( * (  y504 ) );
}

static  int64_t   cast_dash_on_dash_zeroed238 (    uint8_t  x503 ) {
    int64_t  temp239 = ( (  zeroed226 ) ( ) );
    int64_t *  y504 = ( &temp239 );
    uint8_t *  yp505 = ( (  cast177 ) ( (  y504 ) ) );
    (*  yp505 ) = (  x503 );
    return ( * (  y504 ) );
}

static  uint32_t   cast_dash_on_dash_zeroed240 (    enum MouseButton_119  x503 ) {
    uint32_t  temp241 = ( (  zeroed220 ) ( ) );
    uint32_t *  y504 = ( &temp241 );
    enum MouseButton_119 *  yp505 = ( (  cast181 ) ( (  y504 ) ) );
    (*  yp505 ) = (  x503 );
    return ( * (  y504 ) );
}

static  int32_t   cast_dash_on_dash_zeroed242 (    uint8_t  x503 ) {
    int32_t  temp243 = ( (  zeroed27 ) ( ) );
    int32_t *  y504 = ( &temp243 );
    uint8_t *  yp505 = ( (  cast183 ) ( (  y504 ) ) );
    (*  yp505 ) = (  x503 );
    return ( * (  y504 ) );
}

static  FILE *   null_dash_ptr244 (  ) {
    return ( (  zeroed212 ) ( ) );
}

static  char *   null_dash_ptr245 (  ) {
    return ( (  zeroed216 ) ( ) );
}

static  enum Unit_160 *   null_dash_ptr246 (  ) {
    return ( (  zeroed218 ) ( ) );
}

static  struct timespec *   null_dash_ptr247 (  ) {
    return ( (  zeroed230 ) ( ) );
}

static  void *   null_dash_c_dash_ptr248 (  ) {
    return ( (  zeroed210 ) ( ) );
}

static  bool   is_dash_ptr_dash_null249 (    FILE *  p510 ) {
    return ( (  p510 ) == ( (  null_dash_ptr244 ) ( ) ) );
}

static  bool   ptr_dash_eq250 (    enum Unit_160 *  l516 ,    enum Unit_160 *  r518 ) {
    return ( (  l516 ) == (  r518 ) );
}

struct Maybe_252 {
    enum {
        Maybe_252_None_t,
        Maybe_252_Just_t,
    } tag;
    union {
        struct {
            const char*  field0;
        } Maybe_252_Just_s;
    } stuff;
};

static struct Maybe_252 Maybe_252_Just (  const char*  field0 ) {
    return ( struct Maybe_252 ) { .tag = Maybe_252_Just_t, .stuff = { .Maybe_252_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_252   from_dash_nullable_dash_c_dash_str251 (    const char*  s521 ) {
    if ( ( (  ptr_dash_eq250 ) ( ( (  cast173 ) ( (  s521 ) ) ) ,  ( ( (  null_dash_ptr246 ) ( ) ) ) ) ) ) {
        return ( (struct Maybe_252) { .tag = Maybe_252_None_t } );
    } else {
        return ( ( Maybe_252_Just ) ( (  s521 ) ) );
    }
}

static  int64_t   size_dash_i64253 (    size_t  x524 ) {
    return ( (int64_t ) (  x524 ) );
}

static  uint32_t   i32_dash_u32254 (    int32_t  x530 ) {
    return ( (uint32_t ) (  x530 ) );
}

static  int64_t   i32_dash_i64255 (    int32_t  x533 ) {
    return ( (int64_t ) (  x533 ) );
}

static  size_t   i32_dash_size256 (    int32_t  x536 ) {
    return ( (size_t ) ( (int64_t ) (  x536 ) ) );
}

static  int32_t   i64_dash_i32257 (    int64_t  x542 ) {
    return ( (int32_t ) (  x542 ) );
}

static  uint32_t   i64_dash_u32258 (    int64_t  x545 ) {
    return ( (uint32_t ) (  x545 ) );
}

static  size_t   i64_dash_size259 (    int64_t  x548 ) {
    return ( (size_t ) (  x548 ) );
}

static  int32_t   size_dash_i32260 (    size_t  x551 ) {
    return ( (int32_t ) (  x551 ) );
}

static  uint32_t   size_dash_u32261 (    size_t  x554 ) {
    return ( (uint32_t ) (  x554 ) );
}

static  uint32_t   u16_dash_u32262 (    uint16_t  x557 ) {
    return ( (  cast_dash_on_dash_zeroed234 ) ( (  x557 ) ) );
}

static  size_t   u32_dash_size263 (    uint32_t  x563 ) {
    return ( (  cast_dash_on_dash_zeroed236 ) ( (  x563 ) ) );
}

static  int32_t   u32_dash_i32264 (    uint32_t  x572 ) {
    return ( (  cast174 ) ( (  x572 ) ) );
}

static  int64_t   u8_dash_i64265 (    uint8_t  x578 ) {
    return ( (  cast_dash_on_dash_zeroed238 ) ( (  x578 ) ) );
}

static  int32_t   u8_dash_i32266 (    uint8_t  x581 ) {
    return ( (  cast_dash_on_dash_zeroed242 ) ( (  x581 ) ) );
}

struct Slice_270 {
    char *  f_ptr;
    size_t  f_count;
};

struct SliceIter_269 {
    struct Slice_270  f_slice;
    size_t  f_current_dash_offset;
};

struct Scanner_268 {
    struct SliceIter_269  f_s;
};

static  struct Scanner_268   into_dash_iter271 (    struct Scanner_268  self2636 ) {
    return (  self2636 );
}

static  struct Scanner_268   into_dash_iter267 (    struct Scanner_268 *  self587 ) {
    return ( (  into_dash_iter271 ) ( ( * (  self587 ) ) ) );
}

enum EmptyIter_273 {
    EmptyIter_273_EmptyIter,
};

static  enum EmptyIter_273   nil272 (  ) {
    return ( EmptyIter_273_EmptyIter );
}

static  enum EmptyIter_273   into_dash_iter274 (    enum EmptyIter_273  self592 ) {
    return (  self592 );
}

struct Maybe_276 {
    enum {
        Maybe_276_None_t,
        Maybe_276_Just_t,
    } tag;
    union {
        struct {
            char  field0;
        } Maybe_276_Just_s;
    } stuff;
};

static struct Maybe_276 Maybe_276_Just (  char  field0 ) {
    return ( struct Maybe_276 ) { .tag = Maybe_276_Just_t, .stuff = { .Maybe_276_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_276   next275 (    enum EmptyIter_273 *  dref594 ) {
    return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
}

struct ConstStrIter_279 {
    const char*  f_ogstr;
    size_t  f_i;
};

struct Map_278 {
    struct ConstStrIter_279  field0;
    uint32_t (*  field1 )(    char  );
};

static struct Map_278 Map_278_Map (  struct ConstStrIter_279  field0 ,  uint32_t (*  field1 )(    char  ) ) {
    return ( struct Map_278 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct Map_278   into_dash_iter277 (    struct Map_278  self598 ) {
    return (  self598 );
}

struct Maybe_281 {
    enum {
        Maybe_281_None_t,
        Maybe_281_Just_t,
    } tag;
    union {
        struct {
            uint32_t  field0;
        } Maybe_281_Just_s;
    } stuff;
};

static struct Maybe_281 Maybe_281_Just (  uint32_t  field0 ) {
    return ( struct Maybe_281 ) { .tag = Maybe_281_Just_t, .stuff = { .Maybe_281_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_276   next282 (    struct ConstStrIter_279 *  self1116 ) {
    if ( (  cmp39 ( ( ( * (  self1116 ) ) .f_i ) , ( (  i32_dash_size256 ) ( ( ( strlen ) ( ( ( * (  self1116 ) ) .f_ogstr ) ) ) ) ) ) != 0 ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    char *  char_dash_ptr1117 = ( ( (  cast170 ) ( ( ( * (  self1116 ) ) .f_ogstr ) ) ) );
    char  c1118 = ( * ( (  offset_dash_ptr129 ) ( (  char_dash_ptr1117 ) ,  ( (  size_dash_i64253 ) ( ( ( * (  self1116 ) ) .f_i ) ) ) ) ) );
    (*  self1116 ) .f_i = (  op_dash_add58 ( ( ( * (  self1116 ) ) .f_i ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_276_Just ) ( (  c1118 ) ) );
}

static  struct Maybe_281   next280 (    struct Map_278 *  dref600 ) {
    struct Maybe_276  dref603 = ( (  next282 ) ( ( & ( (* dref600 ) .field0 ) ) ) );
    if ( dref603.tag == Maybe_276_None_t ) {
        return ( (struct Maybe_281) { .tag = Maybe_281_None_t } );
    }
    else {
        if ( dref603.tag == Maybe_276_Just_t ) {
            return ( ( Maybe_281_Just ) ( ( ( (* dref600 ) .field1 ) ( ( dref603 .stuff .Maybe_276_Just_s .field0 ) ) ) ) );
        }
    }
}

static  struct ConstStrIter_279   into_dash_iter284 (    const char*  self1110 ) {
    return ( (struct ConstStrIter_279) { .f_ogstr = (  self1110 ) , .f_i = (  from_dash_integral8 ( 0 ) ) } );
}

static  struct Map_278   map283 (    const char*  iterable607 ,    uint32_t (*  fun609 )(    char  ) ) {
    struct ConstStrIter_279  it610 = ( (  into_dash_iter284 ) ( (  iterable607 ) ) );
    return ( ( Map_278_Map ) ( (  it610 ) ,  (  fun609 ) ) );
}

struct Range_286 {
    int32_t  field0;
    int32_t  field1;
};

static struct Range_286 Range_286_Range (  int32_t  field0 ,  int32_t  field1 ) {
    return ( struct Range_286 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct Range_286   to285 (    int32_t  from676 ,    int32_t  to678 ) {
    return ( ( Range_286_Range ) ( (  from676 ) ,  (  to678 ) ) );
}

struct RangeIter_288 {
    struct Range_286  field0;
    int32_t  field1;
};

static struct RangeIter_288 RangeIter_288_RangeIter (  struct Range_286  field0 ,  int32_t  field1 ) {
    return ( struct RangeIter_288 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct RangeIter_288   into_dash_iter287 (    struct Range_286  dref685 ) {
    return ( ( RangeIter_288_RangeIter ) ( ( ( Range_286_Range ) ( ( dref685 .field0 ) ,  ( dref685 .field1 ) ) ) ,  ( dref685 .field0 ) ) );
}

struct Maybe_290 {
    enum {
        Maybe_290_None_t,
        Maybe_290_Just_t,
    } tag;
    union {
        struct {
            int32_t  field0;
        } Maybe_290_Just_s;
    } stuff;
};

static struct Maybe_290 Maybe_290_Just (  int32_t  field0 ) {
    return ( struct Maybe_290 ) { .tag = Maybe_290_Just_t, .stuff = { .Maybe_290_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_290   next289 (    struct RangeIter_288 *  self693 ) {
    struct RangeIter_288  dref694 = ( * (  self693 ) );
    if ( true ) {
        if ( (  cmp40 ( ( dref694 .field1 ) , ( dref694 .field0 .field1 ) ) == 2 ) ) {
            return ( (struct Maybe_290) { .tag = Maybe_290_None_t } );
        }
        struct Maybe_290  x698 = ( ( Maybe_290_Just ) ( ( dref694 .field1 ) ) );
        (*  self693 ) = ( ( RangeIter_288_RangeIter ) ( ( ( Range_286_Range ) ( ( dref694 .field0 .field0 ) ,  ( dref694 .field0 .field1 ) ) ) ,  (  op_dash_add47 ( ( dref694 .field1 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) );
        return (  x698 );
    }
}

struct FromIter_292 {
    int32_t  f_from;
};

static  struct FromIter_292   from291 (    int32_t  f702 ) {
    return ( (struct FromIter_292) { .f_from = (  f702 ) } );
}

static  struct FromIter_292   into_dash_iter293 (    struct FromIter_292  it705 ) {
    return (  it705 );
}

static  struct Maybe_290   next294 (    struct FromIter_292 *  dref707 ) {
    int32_t  v709 = ( ( (* dref707 ) ) .f_from );
    (* dref707 ) .f_from = (  op_dash_add47 ( ( ( (* dref707 ) ) .f_from ) , (  from_dash_integral3 ( 1 ) ) ) );
    return ( ( Maybe_290_Just ) ( (  v709 ) ) );
}

struct Zip_296 {
    struct SliceIter_269  f_left_dash_it;
    struct FromIter_292  f_right_dash_it;
};

static  struct Zip_296   into_dash_iter295 (    struct Zip_296  self713 ) {
    return (  self713 );
}

struct IntStrIter_300 {
    uint32_t  f_int;
    int32_t  f_len;
};

struct StrConcatIter_299 {
    struct ConstStrIter_279  f_left;
    struct IntStrIter_300  f_right;
};

struct Zip_298 {
    struct StrConcatIter_299  f_left_dash_it;
    struct FromIter_292  f_right_dash_it;
};

static  struct Zip_298   into_dash_iter297 (    struct Zip_298  self713 ) {
    return (  self713 );
}

struct Slice_304 {
    struct Slice_103 *  f_ptr;
    size_t  f_count;
};

struct SliceIter_303 {
    struct Slice_304  f_slice;
    size_t  f_current_dash_offset;
};

struct Zip_302 {
    struct SliceIter_303  f_left_dash_it;
    struct FromIter_292  f_right_dash_it;
};

static  struct Zip_302   into_dash_iter301 (    struct Zip_302  self713 ) {
    return (  self713 );
}

struct SliceIter_307 {
    struct Slice_103  f_slice;
    size_t  f_current_dash_offset;
};

struct Zip_306 {
    struct SliceIter_307  f_left_dash_it;
    struct FromIter_292  f_right_dash_it;
};

static  struct Zip_306   into_dash_iter305 (    struct Zip_306  self713 ) {
    return (  self713 );
}

struct Zip_309 {
    struct ConstStrIter_279  f_left_dash_it;
    struct FromIter_292  f_right_dash_it;
};

static  struct Zip_309   into_dash_iter308 (    struct Zip_309  self713 ) {
    return (  self713 );
}

struct Tuple2_312 {
    char  field0;
    int32_t  field1;
};

static struct Tuple2_312 Tuple2_312_Tuple2 (  char  field0 ,  int32_t  field1 ) {
    return ( struct Tuple2_312 ) { .field0 = field0 ,  .field1 = field1 };
};

struct Maybe_311 {
    enum {
        Maybe_311_None_t,
        Maybe_311_Just_t,
    } tag;
    union {
        struct {
            struct Tuple2_312  field0;
        } Maybe_311_Just_s;
    } stuff;
};

static struct Maybe_311 Maybe_311_Just (  struct Tuple2_312  field0 ) {
    return ( struct Maybe_311 ) { .tag = Maybe_311_Just_t, .stuff = { .Maybe_311_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_276   next313 (    struct SliceIter_269 *  self1511 ) {
    size_t  off1512 = ( ( * (  self1511 ) ) .f_current_dash_offset );
    if ( (  cmp39 ( (  op_dash_add58 ( (  off1512 ) , (  from_dash_integral8 ( 1 ) ) ) ) , ( ( ( * (  self1511 ) ) .f_slice ) .f_count ) ) == 2 ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    char  elem1513 = ( * ( (  offset_dash_ptr129 ) ( ( ( ( * (  self1511 ) ) .f_slice ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  off1512 ) ) ) ) ) );
    (*  self1511 ) .f_current_dash_offset = (  op_dash_add58 ( (  off1512 ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_276_Just ) ( (  elem1513 ) ) );
}

static  struct Maybe_311   next310 (    struct Zip_296 *  self716 ) {
    struct Zip_296  copy717 = ( * (  self716 ) );
    while ( ( true ) ) {
        struct Maybe_276  dref718 = ( (  next313 ) ( ( & ( (  copy717 ) .f_left_dash_it ) ) ) );
        if ( dref718.tag == Maybe_276_None_t ) {
            return ( (struct Maybe_311) { .tag = Maybe_311_None_t } );
        }
        else {
            if ( dref718.tag == Maybe_276_Just_t ) {
                struct Maybe_290  dref720 = ( (  next294 ) ( ( & ( (  copy717 ) .f_right_dash_it ) ) ) );
                if ( dref720.tag == Maybe_290_None_t ) {
                    return ( (struct Maybe_311) { .tag = Maybe_311_None_t } );
                }
                else {
                    if ( dref720.tag == Maybe_290_Just_t ) {
                        ( (  next313 ) ( ( & ( ( * (  self716 ) ) .f_left_dash_it ) ) ) );
                        ( (  next294 ) ( ( & ( ( * (  self716 ) ) .f_right_dash_it ) ) ) );
                        return ( ( Maybe_311_Just ) ( ( ( Tuple2_312_Tuple2 ) ( ( dref718 .stuff .Maybe_276_Just_s .field0 ) ,  ( dref720 .stuff .Maybe_290_Just_s .field0 ) ) ) ) );
                    }
                }
            }
        }
    }
}

struct env319 {
    uint32_t  base977;
    ;
};

struct funenv319 {
    uint32_t  (*fun) (  struct env319  ,    int32_t  ,    uint32_t  );
    struct env319 env;
};

static  uint32_t   reduce318 (    struct Range_286  iterable860 ,    uint32_t  base862 ,   struct funenv319  fun864 ) {
    uint32_t  x865 = (  base862 );
    struct RangeIter_288  it866 = ( (  into_dash_iter287 ) ( (  iterable860 ) ) );
    while ( ( true ) ) {
        struct Maybe_290  dref867 = ( (  next289 ) ( ( & (  it866 ) ) ) );
        if ( dref867.tag == Maybe_290_None_t ) {
            return (  x865 );
        }
        else {
            if ( dref867.tag == Maybe_290_Just_t ) {
                struct funenv319  temp320 = (  fun864 );
                x865 = ( temp320.fun ( temp320.env ,  ( dref867 .stuff .Maybe_290_Just_s .field0 ) ,  (  x865 ) ) );
            }
        }
    }
    uint32_t  temp321;
    return (  temp321 );
}

static  uint32_t   lam319 (   struct env319 env ,    int32_t  item981 ,    uint32_t  x983 ) {
    return (  op_dash_mul54 ( (  x983 ) , ( env.base977 ) ) );
}

static  uint32_t   pow317 (    uint32_t  base977 ,    int32_t  p979 ) {
    struct env319 envinst319 = {
        .base977 =  base977 ,
    };
    return ( (  reduce318 ) ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  op_dash_sub48 ( (  p979 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) ,  (  from_dash_integral4 ( 1 ) ) ,  ( (struct funenv319){ .fun = lam319, .env = envinst319 } ) ) );
}

static  struct Maybe_276   next316 (    struct IntStrIter_300 *  self1142 ) {
    if ( (  cmp40 ( ( ( * (  self1142 ) ) .f_len ) , (  from_dash_integral3 ( 0 ) ) ) != 2 ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    uint32_t  trim_dash_down1143 = ( (  pow317 ) ( (  from_dash_integral4 ( 10 ) ) ,  (  op_dash_sub48 ( ( ( * (  self1142 ) ) .f_len ) , (  from_dash_integral3 ( 1 ) ) ) ) ) );
    uint32_t  upper1144 = (  op_dash_div55 ( ( ( * (  self1142 ) ) .f_int ) , (  trim_dash_down1143 ) ) );
    uint32_t  upper_dash_mask1145 = (  op_dash_mul54 ( (  op_dash_div55 ( (  upper1144 ) , (  from_dash_integral4 ( 10 ) ) ) ) , (  from_dash_integral4 ( 10 ) ) ) );
    uint32_t  digit1146 = (  op_dash_sub53 ( (  upper1144 ) , (  upper_dash_mask1145 ) ) );
    (*  self1142 ) .f_len = (  op_dash_sub48 ( ( ( * (  self1142 ) ) .f_len ) , (  from_dash_integral3 ( 1 ) ) ) );
    char  digit_dash_char1147 = ( (  cast182 ) ( (  op_dash_add52 ( (  digit1146 ) , (  from_dash_integral4 ( 48 ) ) ) ) ) );
    return ( ( Maybe_276_Just ) ( (  digit_dash_char1147 ) ) );
}

static  struct Maybe_276   next315 (    struct StrConcatIter_299 *  self1208 ) {
    struct Maybe_276  dref1209 = ( (  next282 ) ( ( & ( ( * (  self1208 ) ) .f_left ) ) ) );
    if ( dref1209.tag == Maybe_276_Just_t ) {
        return ( ( Maybe_276_Just ) ( ( dref1209 .stuff .Maybe_276_Just_s .field0 ) ) );
    }
    else {
        if ( dref1209.tag == Maybe_276_None_t ) {
            return ( (  next316 ) ( ( & ( ( * (  self1208 ) ) .f_right ) ) ) );
        }
    }
}

static  struct Maybe_311   next314 (    struct Zip_298 *  self716 ) {
    struct Zip_298  copy717 = ( * (  self716 ) );
    while ( ( true ) ) {
        struct Maybe_276  dref718 = ( (  next315 ) ( ( & ( (  copy717 ) .f_left_dash_it ) ) ) );
        if ( dref718.tag == Maybe_276_None_t ) {
            return ( (struct Maybe_311) { .tag = Maybe_311_None_t } );
        }
        else {
            if ( dref718.tag == Maybe_276_Just_t ) {
                struct Maybe_290  dref720 = ( (  next294 ) ( ( & ( (  copy717 ) .f_right_dash_it ) ) ) );
                if ( dref720.tag == Maybe_290_None_t ) {
                    return ( (struct Maybe_311) { .tag = Maybe_311_None_t } );
                }
                else {
                    if ( dref720.tag == Maybe_290_Just_t ) {
                        ( (  next315 ) ( ( & ( ( * (  self716 ) ) .f_left_dash_it ) ) ) );
                        ( (  next294 ) ( ( & ( ( * (  self716 ) ) .f_right_dash_it ) ) ) );
                        return ( ( Maybe_311_Just ) ( ( ( Tuple2_312_Tuple2 ) ( ( dref718 .stuff .Maybe_276_Just_s .field0 ) ,  ( dref720 .stuff .Maybe_290_Just_s .field0 ) ) ) ) );
                    }
                }
            }
        }
    }
}

struct Tuple2_324 {
    struct Slice_103  field0;
    int32_t  field1;
};

static struct Tuple2_324 Tuple2_324_Tuple2 (  struct Slice_103  field0 ,  int32_t  field1 ) {
    return ( struct Tuple2_324 ) { .field0 = field0 ,  .field1 = field1 };
};

struct Maybe_323 {
    enum {
        Maybe_323_None_t,
        Maybe_323_Just_t,
    } tag;
    union {
        struct {
            struct Tuple2_324  field0;
        } Maybe_323_Just_s;
    } stuff;
};

static struct Maybe_323 Maybe_323_Just (  struct Tuple2_324  field0 ) {
    return ( struct Maybe_323 ) { .tag = Maybe_323_Just_t, .stuff = { .Maybe_323_Just_s = { .field0 = field0 } } };
};

struct Maybe_325 {
    enum {
        Maybe_325_None_t,
        Maybe_325_Just_t,
    } tag;
    union {
        struct {
            struct Slice_103  field0;
        } Maybe_325_Just_s;
    } stuff;
};

static struct Maybe_325 Maybe_325_Just (  struct Slice_103  field0 ) {
    return ( struct Maybe_325 ) { .tag = Maybe_325_Just_t, .stuff = { .Maybe_325_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_325   next326 (    struct SliceIter_303 *  self1511 ) {
    size_t  off1512 = ( ( * (  self1511 ) ) .f_current_dash_offset );
    if ( (  cmp39 ( (  op_dash_add58 ( (  off1512 ) , (  from_dash_integral8 ( 1 ) ) ) ) , ( ( ( * (  self1511 ) ) .f_slice ) .f_count ) ) == 2 ) ) {
        return ( (struct Maybe_325) { .tag = Maybe_325_None_t } );
    }
    struct Slice_103  elem1513 = ( * ( (  offset_dash_ptr131 ) ( ( ( ( * (  self1511 ) ) .f_slice ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  off1512 ) ) ) ) ) );
    (*  self1511 ) .f_current_dash_offset = (  op_dash_add58 ( (  off1512 ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_325_Just ) ( (  elem1513 ) ) );
}

static  struct Maybe_323   next322 (    struct Zip_302 *  self716 ) {
    struct Zip_302  copy717 = ( * (  self716 ) );
    while ( ( true ) ) {
        struct Maybe_325  dref718 = ( (  next326 ) ( ( & ( (  copy717 ) .f_left_dash_it ) ) ) );
        if ( dref718.tag == Maybe_325_None_t ) {
            return ( (struct Maybe_323) { .tag = Maybe_323_None_t } );
        }
        else {
            if ( dref718.tag == Maybe_325_Just_t ) {
                struct Maybe_290  dref720 = ( (  next294 ) ( ( & ( (  copy717 ) .f_right_dash_it ) ) ) );
                if ( dref720.tag == Maybe_290_None_t ) {
                    return ( (struct Maybe_323) { .tag = Maybe_323_None_t } );
                }
                else {
                    if ( dref720.tag == Maybe_290_Just_t ) {
                        ( (  next326 ) ( ( & ( ( * (  self716 ) ) .f_left_dash_it ) ) ) );
                        ( (  next294 ) ( ( & ( ( * (  self716 ) ) .f_right_dash_it ) ) ) );
                        return ( ( Maybe_323_Just ) ( ( ( Tuple2_324_Tuple2 ) ( ( dref718 .stuff .Maybe_325_Just_s .field0 ) ,  ( dref720 .stuff .Maybe_290_Just_s .field0 ) ) ) ) );
                    }
                }
            }
        }
    }
}

struct Tuple2_329 {
    struct Tile_104  field0;
    int32_t  field1;
};

static struct Tuple2_329 Tuple2_329_Tuple2 (  struct Tile_104  field0 ,  int32_t  field1 ) {
    return ( struct Tuple2_329 ) { .field0 = field0 ,  .field1 = field1 };
};

struct Maybe_328 {
    enum {
        Maybe_328_None_t,
        Maybe_328_Just_t,
    } tag;
    union {
        struct {
            struct Tuple2_329  field0;
        } Maybe_328_Just_s;
    } stuff;
};

static struct Maybe_328 Maybe_328_Just (  struct Tuple2_329  field0 ) {
    return ( struct Maybe_328 ) { .tag = Maybe_328_Just_t, .stuff = { .Maybe_328_Just_s = { .field0 = field0 } } };
};

struct Maybe_330 {
    enum {
        Maybe_330_None_t,
        Maybe_330_Just_t,
    } tag;
    union {
        struct {
            struct Tile_104  field0;
        } Maybe_330_Just_s;
    } stuff;
};

static struct Maybe_330 Maybe_330_Just (  struct Tile_104  field0 ) {
    return ( struct Maybe_330 ) { .tag = Maybe_330_Just_t, .stuff = { .Maybe_330_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_330   next331 (    struct SliceIter_307 *  self1511 ) {
    size_t  off1512 = ( ( * (  self1511 ) ) .f_current_dash_offset );
    if ( (  cmp39 ( (  op_dash_add58 ( (  off1512 ) , (  from_dash_integral8 ( 1 ) ) ) ) , ( ( ( * (  self1511 ) ) .f_slice ) .f_count ) ) == 2 ) ) {
        return ( (struct Maybe_330) { .tag = Maybe_330_None_t } );
    }
    struct Tile_104  elem1513 = ( * ( (  offset_dash_ptr133 ) ( ( ( ( * (  self1511 ) ) .f_slice ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  off1512 ) ) ) ) ) );
    (*  self1511 ) .f_current_dash_offset = (  op_dash_add58 ( (  off1512 ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_330_Just ) ( (  elem1513 ) ) );
}

static  struct Maybe_328   next327 (    struct Zip_306 *  self716 ) {
    struct Zip_306  copy717 = ( * (  self716 ) );
    while ( ( true ) ) {
        struct Maybe_330  dref718 = ( (  next331 ) ( ( & ( (  copy717 ) .f_left_dash_it ) ) ) );
        if ( dref718.tag == Maybe_330_None_t ) {
            return ( (struct Maybe_328) { .tag = Maybe_328_None_t } );
        }
        else {
            if ( dref718.tag == Maybe_330_Just_t ) {
                struct Maybe_290  dref720 = ( (  next294 ) ( ( & ( (  copy717 ) .f_right_dash_it ) ) ) );
                if ( dref720.tag == Maybe_290_None_t ) {
                    return ( (struct Maybe_328) { .tag = Maybe_328_None_t } );
                }
                else {
                    if ( dref720.tag == Maybe_290_Just_t ) {
                        ( (  next331 ) ( ( & ( ( * (  self716 ) ) .f_left_dash_it ) ) ) );
                        ( (  next294 ) ( ( & ( ( * (  self716 ) ) .f_right_dash_it ) ) ) );
                        return ( ( Maybe_328_Just ) ( ( ( Tuple2_329_Tuple2 ) ( ( dref718 .stuff .Maybe_330_Just_s .field0 ) ,  ( dref720 .stuff .Maybe_290_Just_s .field0 ) ) ) ) );
                    }
                }
            }
        }
    }
}

static  struct Maybe_311   next332 (    struct Zip_309 *  self716 ) {
    struct Zip_309  copy717 = ( * (  self716 ) );
    while ( ( true ) ) {
        struct Maybe_276  dref718 = ( (  next282 ) ( ( & ( (  copy717 ) .f_left_dash_it ) ) ) );
        if ( dref718.tag == Maybe_276_None_t ) {
            return ( (struct Maybe_311) { .tag = Maybe_311_None_t } );
        }
        else {
            if ( dref718.tag == Maybe_276_Just_t ) {
                struct Maybe_290  dref720 = ( (  next294 ) ( ( & ( (  copy717 ) .f_right_dash_it ) ) ) );
                if ( dref720.tag == Maybe_290_None_t ) {
                    return ( (struct Maybe_311) { .tag = Maybe_311_None_t } );
                }
                else {
                    if ( dref720.tag == Maybe_290_Just_t ) {
                        ( (  next282 ) ( ( & ( ( * (  self716 ) ) .f_left_dash_it ) ) ) );
                        ( (  next294 ) ( ( & ( ( * (  self716 ) ) .f_right_dash_it ) ) ) );
                        return ( ( Maybe_311_Just ) ( ( ( Tuple2_312_Tuple2 ) ( ( dref718 .stuff .Maybe_276_Just_s .field0 ) ,  ( dref720 .stuff .Maybe_290_Just_s .field0 ) ) ) ) );
                    }
                }
            }
        }
    }
}

static  struct SliceIter_269   into_dash_iter334 (    struct Slice_270  self1505 ) {
    return ( (struct SliceIter_269) { .f_slice = (  self1505 ) , .f_current_dash_offset = (  from_dash_integral8 ( 0 ) ) } );
}

static  struct Zip_296   zip333 (    struct Slice_270  left724 ,    struct FromIter_292  right726 ) {
    struct SliceIter_269  left_dash_it727 = ( (  into_dash_iter334 ) ( (  left724 ) ) );
    struct FromIter_292  right_dash_it728 = ( (  into_dash_iter293 ) ( (  right726 ) ) );
    return ( (struct Zip_296) { .f_left_dash_it = (  left_dash_it727 ) , .f_right_dash_it = (  right_dash_it728 ) } );
}

static  struct StrConcatIter_299   into_dash_iter336 (    struct StrConcatIter_299  self1205 ) {
    return (  self1205 );
}

static  struct Zip_298   zip335 (    struct StrConcatIter_299  left724 ,    struct FromIter_292  right726 ) {
    struct StrConcatIter_299  left_dash_it727 = ( (  into_dash_iter336 ) ( (  left724 ) ) );
    struct FromIter_292  right_dash_it728 = ( (  into_dash_iter293 ) ( (  right726 ) ) );
    return ( (struct Zip_298) { .f_left_dash_it = (  left_dash_it727 ) , .f_right_dash_it = (  right_dash_it728 ) } );
}

static  struct SliceIter_303   into_dash_iter338 (    struct Slice_304  self1505 ) {
    return ( (struct SliceIter_303) { .f_slice = (  self1505 ) , .f_current_dash_offset = (  from_dash_integral8 ( 0 ) ) } );
}

static  struct Zip_302   zip337 (    struct Slice_304  left724 ,    struct FromIter_292  right726 ) {
    struct SliceIter_303  left_dash_it727 = ( (  into_dash_iter338 ) ( (  left724 ) ) );
    struct FromIter_292  right_dash_it728 = ( (  into_dash_iter293 ) ( (  right726 ) ) );
    return ( (struct Zip_302) { .f_left_dash_it = (  left_dash_it727 ) , .f_right_dash_it = (  right_dash_it728 ) } );
}

static  struct SliceIter_307   into_dash_iter340 (    struct Slice_103  self1505 ) {
    return ( (struct SliceIter_307) { .f_slice = (  self1505 ) , .f_current_dash_offset = (  from_dash_integral8 ( 0 ) ) } );
}

static  struct Zip_306   zip339 (    struct Slice_103  left724 ,    struct FromIter_292  right726 ) {
    struct SliceIter_307  left_dash_it727 = ( (  into_dash_iter340 ) ( (  left724 ) ) );
    struct FromIter_292  right_dash_it728 = ( (  into_dash_iter293 ) ( (  right726 ) ) );
    return ( (struct Zip_306) { .f_left_dash_it = (  left_dash_it727 ) , .f_right_dash_it = (  right_dash_it728 ) } );
}

static  struct ConstStrIter_279   into_dash_iter342 (    struct ConstStrIter_279  self1113 ) {
    return (  self1113 );
}

static  struct Zip_309   zip341 (    struct ConstStrIter_279  left724 ,    struct FromIter_292  right726 ) {
    struct ConstStrIter_279  left_dash_it727 = ( (  into_dash_iter342 ) ( (  left724 ) ) );
    struct FromIter_292  right_dash_it728 = ( (  into_dash_iter293 ) ( (  right726 ) ) );
    return ( (struct Zip_309) { .f_left_dash_it = (  left_dash_it727 ) , .f_right_dash_it = (  right_dash_it728 ) } );
}

struct FlattenIter_344 {
    struct SliceIter_303  f_super;
    struct SliceIter_307  f_inner;
    bool  f_empty;
};

static  struct FlattenIter_344   into_dash_iter343 (    struct FlattenIter_344  self732 ) {
    return (  self732 );
}

static  struct Maybe_330   next345 (    struct FlattenIter_344 *  self735 ) {
    if ( ( ( * (  self735 ) ) .f_empty ) ) {
        return ( (struct Maybe_330) { .tag = Maybe_330_None_t } );
    }
    while ( ( true ) ) {
        struct Maybe_330  dref736 = ( (  next331 ) ( ( & ( ( * (  self735 ) ) .f_inner ) ) ) );
        if ( dref736.tag == Maybe_330_Just_t ) {
            return ( ( Maybe_330_Just ) ( ( dref736 .stuff .Maybe_330_Just_s .field0 ) ) );
        }
        else {
            if ( dref736.tag == Maybe_330_None_t ) {
                struct Maybe_325  dref738 = ( (  next326 ) ( ( & ( ( * (  self735 ) ) .f_super ) ) ) );
                if ( dref738.tag == Maybe_325_Just_t ) {
                    (*  self735 ) .f_inner = ( (  into_dash_iter340 ) ( ( dref738 .stuff .Maybe_325_Just_s .field0 ) ) );
                }
                else {
                    if ( dref738.tag == Maybe_325_None_t ) {
                        return ( (struct Maybe_330) { .tag = Maybe_330_None_t } );
                    }
                }
            }
        }
    }
}

static  struct FlattenIter_344   flatten346 (    struct Slice_304  it742 ) {
    struct SliceIter_303  it743 = ( (  into_dash_iter338 ) ( (  it742 ) ) );
    struct Maybe_325  dref744 = ( (  next326 ) ( ( & (  it743 ) ) ) );
    if ( dref744.tag == Maybe_325_Just_t ) {
        return ( (struct FlattenIter_344) { .f_super = (  it743 ) , .f_inner = ( (  into_dash_iter340 ) ( ( dref744 .stuff .Maybe_325_Just_s .field0 ) ) ) , .f_empty = ( false ) } );
    }
    else {
        if ( dref744.tag == Maybe_325_None_t ) {
            struct SliceIter_307  temp347;
            return ( (struct FlattenIter_344) { .f_super = (  it743 ) , .f_inner = (  temp347 ) , .f_empty = ( true ) } );
        }
    }
}

struct TakeWhile_349 {
    struct Scanner_268  f_it;
    bool (*  f_pred )(    char  );
};

static  struct TakeWhile_349   into_dash_iter348 (    struct TakeWhile_349  self763 ) {
    return (  self763 );
}

static  struct Maybe_276   next351 (    struct Scanner_268 *  self2633 ) {
    return ( (  next313 ) ( ( & ( ( * (  self2633 ) ) .f_s ) ) ) );
}

static  struct Maybe_276   next350 (    struct TakeWhile_349 *  self766 ) {
    struct Maybe_276  mx767 = ( (  next351 ) ( ( & ( ( * (  self766 ) ) .f_it ) ) ) );
    struct Maybe_276  dref768 = (  mx767 );
    if ( dref768.tag == Maybe_276_None_t ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    else {
        if ( dref768.tag == Maybe_276_Just_t ) {
            if ( ( ( ( * (  self766 ) ) .f_pred ) ( ( dref768 .stuff .Maybe_276_Just_s .field0 ) ) ) ) {
                return ( ( Maybe_276_Just ) ( ( dref768 .stuff .Maybe_276_Just_s .field0 ) ) );
            } else {
                return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
            }
        }
    }
}

static  struct TakeWhile_349   take_dash_while352 (    struct Scanner_268 *  it772 ,    bool (*  pred774 )(    char  ) ) {
    return ( (struct TakeWhile_349) { .f_it = ( (  into_dash_iter267 ) ( (  it772 ) ) ) , .f_pred = (  pred774 ) } );
}

struct AppendIter_354 {
    enum EmptyIter_273  f_it;
    char  f_elem;
    bool  f_appended;
};

static  struct AppendIter_354   append353 (    enum EmptyIter_273  it808 ,    char  e810 ) {
    return ( (struct AppendIter_354) { .f_it = ( (  into_dash_iter274 ) ( (  it808 ) ) ) , .f_elem = (  e810 ) , .f_appended = ( false ) } );
}

static  struct AppendIter_354   cons355 (    enum EmptyIter_273  it813 ,    char  e815 ) {
    return ( (  append353 ) ( (  it813 ) ,  (  e815 ) ) );
}

static  struct AppendIter_354   single356 (    char  e818 ) {
    return ( (  cons355 ) ( ( (  nil272 ) ( ) ) ,  (  e818 ) ) );
}

static  struct Maybe_276   next357 (    struct AppendIter_354 *  self824 ) {
    struct Maybe_276  dref825 = ( (  next275 ) ( ( & ( ( * (  self824 ) ) .f_it ) ) ) );
    if ( dref825.tag == Maybe_276_Just_t ) {
        return ( ( Maybe_276_Just ) ( ( dref825 .stuff .Maybe_276_Just_s .field0 ) ) );
    }
    else {
        if ( dref825.tag == Maybe_276_None_t ) {
            if ( ( ! ( ( * (  self824 ) ) .f_appended ) ) ) {
                (*  self824 ) .f_appended = ( true );
                return ( ( Maybe_276_Just ) ( ( ( * (  self824 ) ) .f_elem ) ) );
            }
            return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
        }
    }
}

struct Key_362 {
    enum {
        Key_362_Escape_t,
        Key_362_Enter_t,
        Key_362_Tab_t,
        Key_362_Backspace_t,
        Key_362_Char_t,
        Key_362_Ctrl_t,
        Key_362_Up_t,
        Key_362_Down_t,
        Key_362_Left_t,
        Key_362_Right_t,
        Key_362_Home_t,
        Key_362_End_t,
        Key_362_PageUp_t,
        Key_362_PageDown_t,
        Key_362_Delete_t,
        Key_362_Insert_t,
        Key_362_F1_t,
        Key_362_F2_t,
        Key_362_F3_t,
        Key_362_F4_t,
        Key_362_F5_t,
        Key_362_F6_t,
        Key_362_F7_t,
        Key_362_F8_t,
        Key_362_F9_t,
        Key_362_F10_t,
        Key_362_F11_t,
        Key_362_F12_t,
    } tag;
    union {
        struct {
            char  field0;
        } Key_362_Char_s;
        struct {
            char  field0;
        } Key_362_Ctrl_s;
    } stuff;
};

static struct Key_362 Key_362_Char (  char  field0 ) {
    return ( struct Key_362 ) { .tag = Key_362_Char_t, .stuff = { .Key_362_Char_s = { .field0 = field0 } } };
};

static struct Key_362 Key_362_Ctrl (  char  field0 ) {
    return ( struct Key_362 ) { .tag = Key_362_Ctrl_t, .stuff = { .Key_362_Ctrl_s = { .field0 = field0 } } };
};

struct MouseEvent_363 {
    enum MouseButton_119  f_button;
    int32_t  f_x;
    int32_t  f_y;
    bool  f_pressed;
};

struct InputEvent_361 {
    enum {
        InputEvent_361_Key_t,
        InputEvent_361_Mouse_t,
    } tag;
    union {
        struct {
            struct Key_362  field0;
        } InputEvent_361_Key_s;
        struct {
            struct MouseEvent_363  field0;
        } InputEvent_361_Mouse_s;
    } stuff;
};

static struct InputEvent_361 InputEvent_361_Key (  struct Key_362  field0 ) {
    return ( struct InputEvent_361 ) { .tag = InputEvent_361_Key_t, .stuff = { .InputEvent_361_Key_s = { .field0 = field0 } } };
};

static struct InputEvent_361 InputEvent_361_Mouse (  struct MouseEvent_363  field0 ) {
    return ( struct InputEvent_361 ) { .tag = InputEvent_361_Mouse_t, .stuff = { .InputEvent_361_Mouse_s = { .field0 = field0 } } };
};

struct Maybe_360 {
    enum {
        Maybe_360_None_t,
        Maybe_360_Just_t,
    } tag;
    union {
        struct {
            struct InputEvent_361  field0;
        } Maybe_360_Just_s;
    } stuff;
};

static struct Maybe_360 Maybe_360_Just (  struct InputEvent_361  field0 ) {
    return ( struct Maybe_360 ) { .tag = Maybe_360_Just_t, .stuff = { .Maybe_360_Just_s = { .field0 = field0 } } };
};

struct FunIter_359 {
    struct Maybe_360 (*  f_fun )(  );
    bool  f_finished;
};

static  struct FunIter_359   into_dash_iter358 (    struct FunIter_359  self830 ) {
    return (  self830 );
}

static  struct Maybe_360   next364 (    struct FunIter_359 *  self833 ) {
    if ( ( ( * (  self833 ) ) .f_finished ) ) {
        return ( (struct Maybe_360) { .tag = Maybe_360_None_t } );
    }
    struct Maybe_360  dref834 = ( ( ( * (  self833 ) ) .f_fun ) ( ) );
    if ( dref834.tag == Maybe_360_Just_t ) {
        return ( ( Maybe_360_Just ) ( ( dref834 .stuff .Maybe_360_Just_s .field0 ) ) );
    }
    else {
        if ( dref834.tag == Maybe_360_None_t ) {
            (*  self833 ) .f_finished = ( true );
            return ( (struct Maybe_360) { .tag = Maybe_360_None_t } );
        }
    }
}

static  struct FunIter_359   from_dash_function365 (    struct Maybe_360 (*  fun838 )(  ) ) {
    return ( (struct FunIter_359) { .f_fun = (  fun838 ) , .f_finished = ( false ) } );
}

struct env367 {
    ;
    ;
    struct Slice_270  new_dash_slice1725;
};

struct funenv367 {
    enum Unit_160  (*fun) (  struct env367  ,    struct Tuple2_312  );
    struct env367 env;
};

static  enum Unit_160   for_dash_each366 (    struct Zip_296  iterable841 ,   struct funenv367  fun843 ) {
    struct Zip_296  temp368 = ( (  into_dash_iter295 ) ( (  iterable841 ) ) );
    struct Zip_296 *  it844 = ( &temp368 );
    while ( ( true ) ) {
        struct Maybe_311  dref845 = ( (  next310 ) ( (  it844 ) ) );
        if ( dref845.tag == Maybe_311_None_t ) {
            return ( Unit_160_Unit );
        }
        else {
            if ( dref845.tag == Maybe_311_Just_t ) {
                struct funenv367  temp369 = (  fun843 );
                ( temp369.fun ( temp369.env ,  ( dref845 .stuff .Maybe_311_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_160_Unit );
}

struct StrConcatIter_373 {
    struct ConstStrIter_279  f_left;
    struct ConstStrIter_279  f_right;
};

struct StrCaseIter_372 {
    enum {
        StrCaseIter_372_StrCaseIter1_t,
        StrCaseIter_372_StrCaseIter2_t,
    } tag;
    union {
        struct {
            struct ConstStrIter_279  field0;
        } StrCaseIter_372_StrCaseIter1_s;
        struct {
            struct StrConcatIter_373  field0;
        } StrCaseIter_372_StrCaseIter2_s;
    } stuff;
};

static struct StrCaseIter_372 StrCaseIter_372_StrCaseIter1 (  struct ConstStrIter_279  field0 ) {
    return ( struct StrCaseIter_372 ) { .tag = StrCaseIter_372_StrCaseIter1_t, .stuff = { .StrCaseIter_372_StrCaseIter1_s = { .field0 = field0 } } };
};

static struct StrCaseIter_372 StrCaseIter_372_StrCaseIter2 (  struct StrConcatIter_373  field0 ) {
    return ( struct StrCaseIter_372 ) { .tag = StrCaseIter_372_StrCaseIter2_t, .stuff = { .StrCaseIter_372_StrCaseIter2_s = { .field0 = field0 } } };
};

struct StrConcatIter_371 {
    struct StrCaseIter_372  f_left;
    struct ConstStrIter_279  f_right;
};

struct env376 {
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    size_t  growth_dash_factor1720;
    size_t  starting_dash_size1719;
};

enum CAllocator_378 {
    CAllocator_378_CAllocator,
};

struct List_377 {
    enum CAllocator_378  f_al;
    struct Slice_270  f_elements;
    size_t  f_count;
};

struct funenv376 {
    enum Unit_160  (*fun) (  struct env376  ,    struct List_377 *  );
    struct env376 env;
};

struct env375 {
    ;
    ;
    ;
    ;
    ;
    struct env376 envinst376;
};

struct funenv375 {
    enum Unit_160  (*fun) (  struct env375  ,    struct List_377 *  ,    char  );
    struct env375 env;
};

struct StrBuilder_379 {
    struct List_377  f_chars;
};

struct env374 {
    struct env375 envinst375;
    struct StrBuilder_379 *  builder2197;
};

struct funenv374 {
    enum Unit_160  (*fun) (  struct env374  ,    char  );
    struct env374 env;
};

static  struct StrConcatIter_371   into_dash_iter381 (    struct StrConcatIter_371  self1205 ) {
    return (  self1205 );
}

static  struct Maybe_276   next384 (    struct StrConcatIter_373 *  self1208 ) {
    struct Maybe_276  dref1209 = ( (  next282 ) ( ( & ( ( * (  self1208 ) ) .f_left ) ) ) );
    if ( dref1209.tag == Maybe_276_Just_t ) {
        return ( ( Maybe_276_Just ) ( ( dref1209 .stuff .Maybe_276_Just_s .field0 ) ) );
    }
    else {
        if ( dref1209.tag == Maybe_276_None_t ) {
            return ( (  next282 ) ( ( & ( ( * (  self1208 ) ) .f_right ) ) ) );
        }
    }
}

static  struct Maybe_276   next383 (    struct StrCaseIter_372 *  self1230 ) {
    struct StrCaseIter_372 *  dref1231 = (  self1230 );
    if ( (* dref1231 ).tag == StrCaseIter_372_StrCaseIter1_t ) {
        return ( (  next282 ) ( ( & ( (* dref1231 ) .stuff .StrCaseIter_372_StrCaseIter1_s .field0 ) ) ) );
    }
    else {
        if ( (* dref1231 ).tag == StrCaseIter_372_StrCaseIter2_t ) {
            return ( (  next384 ) ( ( & ( (* dref1231 ) .stuff .StrCaseIter_372_StrCaseIter2_s .field0 ) ) ) );
        }
    }
}

static  struct Maybe_276   next382 (    struct StrConcatIter_371 *  self1208 ) {
    struct Maybe_276  dref1209 = ( (  next383 ) ( ( & ( ( * (  self1208 ) ) .f_left ) ) ) );
    if ( dref1209.tag == Maybe_276_Just_t ) {
        return ( ( Maybe_276_Just ) ( ( dref1209 .stuff .Maybe_276_Just_s .field0 ) ) );
    }
    else {
        if ( dref1209.tag == Maybe_276_None_t ) {
            return ( (  next282 ) ( ( & ( ( * (  self1208 ) ) .f_right ) ) ) );
        }
    }
}

static  enum Unit_160   for_dash_each370 (    struct StrConcatIter_371  iterable841 ,   struct funenv374  fun843 ) {
    struct StrConcatIter_371  temp380 = ( (  into_dash_iter381 ) ( (  iterable841 ) ) );
    struct StrConcatIter_371 *  it844 = ( &temp380 );
    while ( ( true ) ) {
        struct Maybe_276  dref845 = ( (  next382 ) ( (  it844 ) ) );
        if ( dref845.tag == Maybe_276_None_t ) {
            return ( Unit_160_Unit );
        }
        else {
            if ( dref845.tag == Maybe_276_Just_t ) {
                struct funenv374  temp385 = (  fun843 );
                ( temp385.fun ( temp385.env ,  ( dref845 .stuff .Maybe_276_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_160_Unit );
}

struct env388 {
    struct Tile_104  x1634;
};

struct funenv388 {
    struct Tile_104  (*fun) (  struct env388  ,    struct Tile_104  );
    struct env388 env;
};

struct env387 {
    ;
    struct Slice_103  s1588;
    ;
    struct funenv388  fun1590;
    ;
};

struct funenv387 {
    enum Unit_160  (*fun) (  struct env387  ,    int32_t  );
    struct env387 env;
};

static  enum Unit_160   for_dash_each386 (    struct Range_286  iterable841 ,   struct funenv387  fun843 ) {
    struct RangeIter_288  temp389 = ( (  into_dash_iter287 ) ( (  iterable841 ) ) );
    struct RangeIter_288 *  it844 = ( &temp389 );
    while ( ( true ) ) {
        struct Maybe_290  dref845 = ( (  next289 ) ( (  it844 ) ) );
        if ( dref845.tag == Maybe_290_None_t ) {
            return ( Unit_160_Unit );
        }
        else {
            if ( dref845.tag == Maybe_290_Just_t ) {
                struct funenv387  temp390 = (  fun843 );
                ( temp390.fun ( temp390.env ,  ( dref845 .stuff .Maybe_290_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_160_Unit );
}

struct Slice_393 {
    struct Cell_16 *  f_ptr;
    size_t  f_count;
};

struct env392 {
    ;
    struct Slice_393  s1588;
    ;
    struct Cell_16 (*  fun1590 )(    struct Cell_16  );
    ;
};

struct funenv392 {
    enum Unit_160  (*fun) (  struct env392  ,    int32_t  );
    struct env392 env;
};

static  enum Unit_160   for_dash_each391 (    struct Range_286  iterable841 ,   struct funenv392  fun843 ) {
    struct RangeIter_288  temp394 = ( (  into_dash_iter287 ) ( (  iterable841 ) ) );
    struct RangeIter_288 *  it844 = ( &temp394 );
    while ( ( true ) ) {
        struct Maybe_290  dref845 = ( (  next289 ) ( (  it844 ) ) );
        if ( dref845.tag == Maybe_290_None_t ) {
            return ( Unit_160_Unit );
        }
        else {
            if ( dref845.tag == Maybe_290_Just_t ) {
                struct funenv392  temp395 = (  fun843 );
                ( temp395.fun ( temp395.env ,  ( dref845 .stuff .Maybe_290_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_160_Unit );
}

struct env397 {
    ;
    struct Slice_393  s1588;
    ;
    struct Cell_16 (*  fun1590 )(    struct Cell_16  );
    ;
};

struct funenv397 {
    enum Unit_160  (*fun) (  struct env397  ,    int32_t  );
    struct env397 env;
};

static  enum Unit_160   for_dash_each396 (    struct Range_286  iterable841 ,   struct funenv397  fun843 ) {
    struct RangeIter_288  temp398 = ( (  into_dash_iter287 ) ( (  iterable841 ) ) );
    struct RangeIter_288 *  it844 = ( &temp398 );
    while ( ( true ) ) {
        struct Maybe_290  dref845 = ( (  next289 ) ( (  it844 ) ) );
        if ( dref845.tag == Maybe_290_None_t ) {
            return ( Unit_160_Unit );
        }
        else {
            if ( dref845.tag == Maybe_290_Just_t ) {
                struct funenv397  temp399 = (  fun843 );
                ( temp399.fun ( temp399.env ,  ( dref845 .stuff .Maybe_290_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_160_Unit );
}

struct env401 {
    struct Scanner_268 *  it953;
    ;
};

struct funenv401 {
    struct Maybe_276  (*fun) (  struct env401  ,    int32_t  );
    struct env401 env;
};

static  enum Unit_160   for_dash_each400 (    struct Range_286  iterable841 ,   struct funenv401  fun843 ) {
    struct RangeIter_288  temp402 = ( (  into_dash_iter287 ) ( (  iterable841 ) ) );
    struct RangeIter_288 *  it844 = ( &temp402 );
    while ( ( true ) ) {
        struct Maybe_290  dref845 = ( (  next289 ) ( (  it844 ) ) );
        if ( dref845.tag == Maybe_290_None_t ) {
            return ( Unit_160_Unit );
        }
        else {
            if ( dref845.tag == Maybe_290_Just_t ) {
                struct funenv401  temp403 = (  fun843 );
                ( temp403.fun ( temp403.env ,  ( dref845 .stuff .Maybe_290_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_160_Unit );
}

struct env406 {
    ;
    struct env375 envinst375;
    ;
};

struct funenv406 {
    enum Unit_160  (*fun) (  struct env406  ,    struct StrBuilder_379 *  ,    char  );
    struct env406 env;
};

struct env410 {
    struct env375 envinst375;
    ;
    ;
    ;
    ;
    ;
    ;
};

struct funenv410 {
    enum Unit_160  (*fun) (  struct env410  ,    struct StrBuilder_379 *  ,    struct StrBuilder_379  );
    struct env410 env;
};

struct env409 {
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    struct env410 envinst410;
    ;
    ;
    struct env406 envinst406;
    ;
};

struct DynStr_411 {
    struct Slice_270  f_contents;
};

struct funenv409 {
    struct DynStr_411  (*fun) (  struct env409  ,    struct StrBuilder_379  ,    enum CAllocator_378  );
    struct env409 env;
};

struct env408 {
    ;
    ;
    ;
    ;
    ;
    struct env409 envinst409;
    ;
};

struct funenv408 {
    const char*  (*fun) (  struct env408  ,    struct StrBuilder_379  ,    enum CAllocator_378  );
    struct env408 env;
};

struct env407 {
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    struct env408 envinst408;
    ;
    ;
    ;
    ;
    ;
    ;
};

struct funenv407 {
    enum Unit_160  (*fun) (  struct env407  ,    struct StrBuilder_379  ,    enum CAllocator_378  );
    struct env407 env;
};

struct env405 {
    struct env406 envinst406;
    ;
    ;
    enum CAllocator_378  al2356;
    ;
    struct env407 envinst407;
    ;
    ;
    struct StrBuilder_379 *  sb2357;
};

struct funenv405 {
    enum Unit_160  (*fun) (  struct env405  ,    char  );
    struct env405 env;
};

static  enum Unit_160   for_dash_each404 (    struct StrConcatIter_371  iterable841 ,   struct funenv405  fun843 ) {
    struct StrConcatIter_371  temp412 = ( (  into_dash_iter381 ) ( (  iterable841 ) ) );
    struct StrConcatIter_371 *  it844 = ( &temp412 );
    while ( ( true ) ) {
        struct Maybe_276  dref845 = ( (  next382 ) ( (  it844 ) ) );
        if ( dref845.tag == Maybe_276_None_t ) {
            return ( Unit_160_Unit );
        }
        else {
            if ( dref845.tag == Maybe_276_Just_t ) {
                struct funenv405  temp413 = (  fun843 );
                ( temp413.fun ( temp413.env ,  ( dref845 .stuff .Maybe_276_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_160_Unit );
}

struct env415 {
    struct env375 envinst375;
    struct StrBuilder_379 *  builder2197;
};

struct funenv415 {
    enum Unit_160  (*fun) (  struct env415  ,    char  );
    struct env415 env;
};

static  struct SliceIter_269   into_dash_iter417 (    struct SliceIter_269  self1508 ) {
    return (  self1508 );
}

static  enum Unit_160   for_dash_each414 (    struct SliceIter_269  iterable841 ,   struct funenv415  fun843 ) {
    struct SliceIter_269  temp416 = ( (  into_dash_iter417 ) ( (  iterable841 ) ) );
    struct SliceIter_269 *  it844 = ( &temp416 );
    while ( ( true ) ) {
        struct Maybe_276  dref845 = ( (  next313 ) ( (  it844 ) ) );
        if ( dref845.tag == Maybe_276_None_t ) {
            return ( Unit_160_Unit );
        }
        else {
            if ( dref845.tag == Maybe_276_Just_t ) {
                struct funenv415  temp418 = (  fun843 );
                ( temp418.fun ( temp418.env ,  ( dref845 .stuff .Maybe_276_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_160_Unit );
}

struct StrConcatIter_420 {
    struct StrConcatIter_371  f_left;
    struct ConstStrIter_279  f_right;
};

struct env421 {
    struct env375 envinst375;
    struct StrBuilder_379 *  builder2197;
};

struct funenv421 {
    enum Unit_160  (*fun) (  struct env421  ,    char  );
    struct env421 env;
};

static  struct StrConcatIter_420   into_dash_iter423 (    struct StrConcatIter_420  self1205 ) {
    return (  self1205 );
}

static  struct Maybe_276   next424 (    struct StrConcatIter_420 *  self1208 ) {
    struct Maybe_276  dref1209 = ( (  next382 ) ( ( & ( ( * (  self1208 ) ) .f_left ) ) ) );
    if ( dref1209.tag == Maybe_276_Just_t ) {
        return ( ( Maybe_276_Just ) ( ( dref1209 .stuff .Maybe_276_Just_s .field0 ) ) );
    }
    else {
        if ( dref1209.tag == Maybe_276_None_t ) {
            return ( (  next282 ) ( ( & ( ( * (  self1208 ) ) .f_right ) ) ) );
        }
    }
}

static  enum Unit_160   for_dash_each419 (    struct StrConcatIter_420  iterable841 ,   struct funenv421  fun843 ) {
    struct StrConcatIter_420  temp422 = ( (  into_dash_iter423 ) ( (  iterable841 ) ) );
    struct StrConcatIter_420 *  it844 = ( &temp422 );
    while ( ( true ) ) {
        struct Maybe_276  dref845 = ( (  next424 ) ( (  it844 ) ) );
        if ( dref845.tag == Maybe_276_None_t ) {
            return ( Unit_160_Unit );
        }
        else {
            if ( dref845.tag == Maybe_276_Just_t ) {
                struct funenv421  temp425 = (  fun843 );
                ( temp425.fun ( temp425.env ,  ( dref845 .stuff .Maybe_276_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_160_Unit );
}

struct env427 {
    ;
    struct Slice_393  s1588;
    ;
    struct Cell_16 (*  fun1590 )(    struct Cell_16  );
    ;
};

struct funenv427 {
    enum Unit_160  (*fun) (  struct env427  ,    int32_t  );
    struct env427 env;
};

static  enum Unit_160   for_dash_each426 (    struct Range_286  iterable841 ,   struct funenv427  fun843 ) {
    struct RangeIter_288  temp428 = ( (  into_dash_iter287 ) ( (  iterable841 ) ) );
    struct RangeIter_288 *  it844 = ( &temp428 );
    while ( ( true ) ) {
        struct Maybe_290  dref845 = ( (  next289 ) ( (  it844 ) ) );
        if ( dref845.tag == Maybe_290_None_t ) {
            return ( Unit_160_Unit );
        }
        else {
            if ( dref845.tag == Maybe_290_Just_t ) {
                struct funenv427  temp429 = (  fun843 );
                ( temp429.fun ( temp429.env ,  ( dref845 .stuff .Maybe_290_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_160_Unit );
}

enum ColorPalette_434 {
    ColorPalette_434_Palette8,
    ColorPalette_434_Palette16,
    ColorPalette_434_Palette256,
    ColorPalette_434_PaletteRGB,
};

struct Tui_433 {
    uint32_t  f_width;
    uint32_t  f_height;
    uint32_t  f_target_dash_fps;
    uint32_t  f_actual_dash_fps;
    enum ColorPalette_434  f_palette;
    struct timespec  f_last_dash_sync;
    struct timespec  f_fps_dash_ts;
    uint32_t  f_fps_dash_count;
    struct Termios_109  f_orig_dash_termios;
};

struct Screen_432 {
    enum CAllocator_378  f_al;
    struct Tui_433 *  f_tui;
    struct Slice_393  f_current;
    struct Slice_393  f_previous;
    bool  f_requires_dash_full_dash_redraw;
    struct Color_17  f_default_dash_fg;
    struct Color_17  f_default_dash_bg;
};

struct env431 {
    ;
    int32_t  y2905;
    struct Screen_432 *  screen2899;
    int32_t  x2908;
    ;
};

struct funenv431 {
    enum Unit_160  (*fun) (  struct env431  ,    struct Tuple2_312  );
    struct env431 env;
};

static  enum Unit_160   for_dash_each430 (    struct Zip_298  iterable841 ,   struct funenv431  fun843 ) {
    struct Zip_298  temp435 = ( (  into_dash_iter297 ) ( (  iterable841 ) ) );
    struct Zip_298 *  it844 = ( &temp435 );
    while ( ( true ) ) {
        struct Maybe_311  dref845 = ( (  next314 ) ( (  it844 ) ) );
        if ( dref845.tag == Maybe_311_None_t ) {
            return ( Unit_160_Unit );
        }
        else {
            if ( dref845.tag == Maybe_311_Just_t ) {
                struct funenv431  temp436 = (  fun843 );
                ( temp436.fun ( temp436.env ,  ( dref845 .stuff .Maybe_311_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_160_Unit );
}

struct env438 {
    ;
    int32_t  y2905;
    struct Screen_432 *  screen2899;
    int32_t  x2908;
    ;
};

struct funenv438 {
    enum Unit_160  (*fun) (  struct env438  ,    struct Tuple2_312  );
    struct env438 env;
};

static  enum Unit_160   for_dash_each437 (    struct Zip_309  iterable841 ,   struct funenv438  fun843 ) {
    struct Zip_309  temp439 = ( (  into_dash_iter308 ) ( (  iterable841 ) ) );
    struct Zip_309 *  it844 = ( &temp439 );
    while ( ( true ) ) {
        struct Maybe_311  dref845 = ( (  next332 ) ( (  it844 ) ) );
        if ( dref845.tag == Maybe_311_None_t ) {
            return ( Unit_160_Unit );
        }
        else {
            if ( dref845.tag == Maybe_311_Just_t ) {
                struct funenv438  temp440 = (  fun843 );
                ( temp440.fun ( temp440.env ,  ( dref845 .stuff .Maybe_311_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_160_Unit );
}

struct Maybe_442 {
    enum {
        Maybe_442_None_t,
        Maybe_442_Just_t,
    } tag;
    union {
        struct {
            int64_t  field0;
        } Maybe_442_Just_s;
    } stuff;
};

static struct Maybe_442 Maybe_442_Just (  int64_t  field0 ) {
    return ( struct Maybe_442 ) { .tag = Maybe_442_Just_t, .stuff = { .Maybe_442_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_442   reduce441 (    struct ConstStrIter_279  iterable860 ,    struct Maybe_442  base862 ,    struct Maybe_442 (*  fun864 )(    char  ,    struct Maybe_442  ) ) {
    struct Maybe_442  x865 = (  base862 );
    struct ConstStrIter_279  it866 = ( (  into_dash_iter342 ) ( (  iterable860 ) ) );
    while ( ( true ) ) {
        struct Maybe_276  dref867 = ( (  next282 ) ( ( & (  it866 ) ) ) );
        if ( dref867.tag == Maybe_276_None_t ) {
            return (  x865 );
        }
        else {
            if ( dref867.tag == Maybe_276_Just_t ) {
                x865 = ( (  fun864 ) ( ( dref867 .stuff .Maybe_276_Just_s .field0 ) ,  (  x865 ) ) );
            }
        }
    }
    struct Maybe_442  temp443;
    return (  temp443 );
}

static  struct Maybe_442   reduce444 (    struct SliceIter_269  iterable860 ,    struct Maybe_442  base862 ,    struct Maybe_442 (*  fun864 )(    char  ,    struct Maybe_442  ) ) {
    struct Maybe_442  x865 = (  base862 );
    struct SliceIter_269  it866 = ( (  into_dash_iter417 ) ( (  iterable860 ) ) );
    while ( ( true ) ) {
        struct Maybe_276  dref867 = ( (  next313 ) ( ( & (  it866 ) ) ) );
        if ( dref867.tag == Maybe_276_None_t ) {
            return (  x865 );
        }
        else {
            if ( dref867.tag == Maybe_276_Just_t ) {
                x865 = ( (  fun864 ) ( ( dref867 .stuff .Maybe_276_Just_s .field0 ) ,  (  x865 ) ) );
            }
        }
    }
    struct Maybe_442  temp445;
    return (  temp445 );
}

struct SmolArrayIter_447 {
    struct SmolArray_68  f_backing;
    size_t  f_cur;
};

static  struct SmolArrayIter_447   into_dash_iter448 (    struct SmolArray_68  self1869 ) {
    return ( (struct SmolArrayIter_447) { .f_backing = (  self1869 ) , .f_cur = (  from_dash_integral8 ( 0 ) ) } );
}

struct StrConcat_456 {
    const char*  field0;
    size_t  field1;
};

static struct StrConcat_456 StrConcat_456_StrConcat (  const char*  field0 ,  size_t  field1 ) {
    return ( struct StrConcat_456 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_455 {
    struct StrConcat_456  field0;
    const char*  field1;
};

static struct StrConcat_455 StrConcat_455_StrConcat (  struct StrConcat_456  field0 ,  const char*  field1 ) {
    return ( struct StrConcat_455 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_454 {
    struct StrConcat_455  field0;
    int32_t  field1;
};

static struct StrConcat_454 StrConcat_454_StrConcat (  struct StrConcat_455  field0 ,  int32_t  field1 ) {
    return ( struct StrConcat_454 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_453 {
    struct StrConcat_454  field0;
    char  field1;
};

static struct StrConcat_453 StrConcat_453_StrConcat (  struct StrConcat_454  field0 ,  char  field1 ) {
    return ( struct StrConcat_453 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_459 {
    const char*  field0;
    struct StrConcat_453  field1;
};

static struct StrConcat_459 StrConcat_459_StrConcat (  const char*  field0 ,  struct StrConcat_453  field1 ) {
    return ( struct StrConcat_459 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_458 {
    struct StrConcat_459  field0;
    char  field1;
};

static struct StrConcat_458 StrConcat_458_StrConcat (  struct StrConcat_459  field0 ,  char  field1 ) {
    return ( struct StrConcat_458 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_160   print_dash_str461 (    const char*  self1121 ) {
    ( ( printf ) ( ( "%s" ) ,  (  self1121 ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str466 (    size_t  self1178 ) {
    ( ( printf ) ( ( "%lu" ) ,  (  self1178 ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str465 (    struct StrConcat_456  self1217 ) {
    struct StrConcat_456  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str461 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str466 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str464 (    struct StrConcat_455  self1217 ) {
    struct StrConcat_455  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str465 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str461 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str467 (    int32_t  self1154 ) {
    ( ( printf ) ( ( "%d" ) ,  (  self1154 ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str463 (    struct StrConcat_454  self1217 ) {
    struct StrConcat_454  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str464 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str467 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str468 (    char  self1127 ) {
    ( ( printf ) ( ( "%c" ) ,  (  self1127 ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str462 (    struct StrConcat_453  self1217 ) {
    struct StrConcat_453  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str463 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str468 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str460 (    struct StrConcat_459  self1217 ) {
    struct StrConcat_459  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str461 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str462 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str457 (    struct StrConcat_458  self1217 ) {
    struct StrConcat_458  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str460 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str468 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   panic452 (    struct StrConcat_453  errmsg1394 ) {
    ( (  print_dash_str457 ) ( ( ( StrConcat_458_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1394 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral3 ( 1 ) ) ) );
    return ( Unit_160_Unit );
}

static  uint32_t *   get_dash_ptr451 (    struct Array_69 *  arr1831 ,    size_t  i1834 ) {
    if ( ( (  cmp39 ( (  i1834 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1834 ) , ( (size_t ) ( 1 ) ) ) != 0 ) ) ) {
        ( (  panic452 ) ( ( ( StrConcat_453_StrConcat ) ( ( ( StrConcat_454_StrConcat ) ( ( ( StrConcat_455_StrConcat ) ( ( ( StrConcat_456_StrConcat ) ( ( "Access to array at index " ) ,  (  i1834 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 1 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    uint32_t *  p1835 = ( ( (  cast_dash_ptr197 ) ( (  arr1831 ) ) ) );
    return ( (  offset_dash_ptr137 ) ( (  p1835 ) ,  ( (int64_t ) (  i1834 ) ) ) );
}

static  uint32_t   get450 (    struct Array_69 *  arr1838 ,    size_t  i1841 ) {
    return ( * ( (  get_dash_ptr451 ) ( (  arr1838 ) ,  (  i1841 ) ) ) );
}

static  struct Maybe_281   next449 (    struct SmolArrayIter_447 *  self1876 ) {
    if ( (  cmp39 ( ( ( * (  self1876 ) ) .f_cur ) , ( (size_t ) ( 1 ) ) ) != 0 ) ) {
        return ( (struct Maybe_281) { .tag = Maybe_281_None_t } );
    }
    uint32_t  e1878 = ( (  get450 ) ( ( & ( ( ( * (  self1876 ) ) .f_backing ) .f_arr ) ) ,  ( ( * (  self1876 ) ) .f_cur ) ) );
    (*  self1876 ) .f_cur = (  op_dash_add58 ( ( ( * (  self1876 ) ) .f_cur ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_281_Just ) ( (  e1878 ) ) );
}

static  uint32_t   reduce446 (    struct SmolArray_68  iterable860 ,    uint32_t  base862 ,    uint32_t (*  fun864 )(    uint32_t  ,    uint32_t  ) ) {
    uint32_t  x865 = (  base862 );
    struct SmolArrayIter_447  it866 = ( (  into_dash_iter448 ) ( (  iterable860 ) ) );
    while ( ( true ) ) {
        struct Maybe_281  dref867 = ( (  next449 ) ( ( & (  it866 ) ) ) );
        if ( dref867.tag == Maybe_281_None_t ) {
            return (  x865 );
        }
        else {
            if ( dref867.tag == Maybe_281_Just_t ) {
                x865 = ( (  fun864 ) ( ( dref867 .stuff .Maybe_281_Just_s .field0 ) ,  (  x865 ) ) );
            }
        }
    }
    uint32_t  temp469;
    return (  temp469 );
}

struct SmolArrayIter_471 {
    struct SmolArray_65  f_backing;
    size_t  f_cur;
};

static  struct SmolArrayIter_471   into_dash_iter472 (    struct SmolArray_65  self1869 ) {
    return ( (struct SmolArrayIter_471) { .f_backing = (  self1869 ) , .f_cur = (  from_dash_integral8 ( 0 ) ) } );
}

static  uint32_t *   get_dash_ptr475 (    struct Array_66 *  arr1831 ,    size_t  i1834 ) {
    if ( ( (  cmp39 ( (  i1834 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1834 ) , ( (size_t ) ( 5 ) ) ) != 0 ) ) ) {
        ( (  panic452 ) ( ( ( StrConcat_453_StrConcat ) ( ( ( StrConcat_454_StrConcat ) ( ( ( StrConcat_455_StrConcat ) ( ( ( StrConcat_456_StrConcat ) ( ( "Access to array at index " ) ,  (  i1834 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 5 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    uint32_t *  p1835 = ( ( (  cast_dash_ptr198 ) ( (  arr1831 ) ) ) );
    return ( (  offset_dash_ptr137 ) ( (  p1835 ) ,  ( (int64_t ) (  i1834 ) ) ) );
}

static  uint32_t   get474 (    struct Array_66 *  arr1838 ,    size_t  i1841 ) {
    return ( * ( (  get_dash_ptr475 ) ( (  arr1838 ) ,  (  i1841 ) ) ) );
}

static  struct Maybe_281   next473 (    struct SmolArrayIter_471 *  self1876 ) {
    if ( (  cmp39 ( ( ( * (  self1876 ) ) .f_cur ) , ( (size_t ) ( 5 ) ) ) != 0 ) ) {
        return ( (struct Maybe_281) { .tag = Maybe_281_None_t } );
    }
    uint32_t  e1878 = ( (  get474 ) ( ( & ( ( ( * (  self1876 ) ) .f_backing ) .f_arr ) ) ,  ( ( * (  self1876 ) ) .f_cur ) ) );
    (*  self1876 ) .f_cur = (  op_dash_add58 ( ( ( * (  self1876 ) ) .f_cur ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_281_Just ) ( (  e1878 ) ) );
}

static  uint32_t   reduce470 (    struct SmolArray_65  iterable860 ,    uint32_t  base862 ,    uint32_t (*  fun864 )(    uint32_t  ,    uint32_t  ) ) {
    uint32_t  x865 = (  base862 );
    struct SmolArrayIter_471  it866 = ( (  into_dash_iter472 ) ( (  iterable860 ) ) );
    while ( ( true ) ) {
        struct Maybe_281  dref867 = ( (  next473 ) ( ( & (  it866 ) ) ) );
        if ( dref867.tag == Maybe_281_None_t ) {
            return (  x865 );
        }
        else {
            if ( dref867.tag == Maybe_281_Just_t ) {
                x865 = ( (  fun864 ) ( ( dref867 .stuff .Maybe_281_Just_s .field0 ) ,  (  x865 ) ) );
            }
        }
    }
    uint32_t  temp476;
    return (  temp476 );
}

struct SmolArrayIter_478 {
    struct SmolArray_62  f_backing;
    size_t  f_cur;
};

static  struct SmolArrayIter_478   into_dash_iter479 (    struct SmolArray_62  self1869 ) {
    return ( (struct SmolArrayIter_478) { .f_backing = (  self1869 ) , .f_cur = (  from_dash_integral8 ( 0 ) ) } );
}

static  uint32_t *   get_dash_ptr482 (    struct Array_63 *  arr1831 ,    size_t  i1834 ) {
    if ( ( (  cmp39 ( (  i1834 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1834 ) , ( (size_t ) ( 4 ) ) ) != 0 ) ) ) {
        ( (  panic452 ) ( ( ( StrConcat_453_StrConcat ) ( ( ( StrConcat_454_StrConcat ) ( ( ( StrConcat_455_StrConcat ) ( ( ( StrConcat_456_StrConcat ) ( ( "Access to array at index " ) ,  (  i1834 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 4 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    uint32_t *  p1835 = ( ( (  cast_dash_ptr199 ) ( (  arr1831 ) ) ) );
    return ( (  offset_dash_ptr137 ) ( (  p1835 ) ,  ( (int64_t ) (  i1834 ) ) ) );
}

static  uint32_t   get481 (    struct Array_63 *  arr1838 ,    size_t  i1841 ) {
    return ( * ( (  get_dash_ptr482 ) ( (  arr1838 ) ,  (  i1841 ) ) ) );
}

static  struct Maybe_281   next480 (    struct SmolArrayIter_478 *  self1876 ) {
    if ( (  cmp39 ( ( ( * (  self1876 ) ) .f_cur ) , ( (size_t ) ( 4 ) ) ) != 0 ) ) {
        return ( (struct Maybe_281) { .tag = Maybe_281_None_t } );
    }
    uint32_t  e1878 = ( (  get481 ) ( ( & ( ( ( * (  self1876 ) ) .f_backing ) .f_arr ) ) ,  ( ( * (  self1876 ) ) .f_cur ) ) );
    (*  self1876 ) .f_cur = (  op_dash_add58 ( ( ( * (  self1876 ) ) .f_cur ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_281_Just ) ( (  e1878 ) ) );
}

static  uint32_t   reduce477 (    struct SmolArray_62  iterable860 ,    uint32_t  base862 ,    uint32_t (*  fun864 )(    uint32_t  ,    uint32_t  ) ) {
    uint32_t  x865 = (  base862 );
    struct SmolArrayIter_478  it866 = ( (  into_dash_iter479 ) ( (  iterable860 ) ) );
    while ( ( true ) ) {
        struct Maybe_281  dref867 = ( (  next480 ) ( ( & (  it866 ) ) ) );
        if ( dref867.tag == Maybe_281_None_t ) {
            return (  x865 );
        }
        else {
            if ( dref867.tag == Maybe_281_Just_t ) {
                x865 = ( (  fun864 ) ( ( dref867 .stuff .Maybe_281_Just_s .field0 ) ,  (  x865 ) ) );
            }
        }
    }
    uint32_t  temp483;
    return (  temp483 );
}

static  uint32_t   reduce484 (    struct Map_278  iterable860 ,    uint32_t  base862 ,    uint32_t (*  fun864 )(    uint32_t  ,    uint32_t  ) ) {
    uint32_t  x865 = (  base862 );
    struct Map_278  it866 = ( (  into_dash_iter277 ) ( (  iterable860 ) ) );
    while ( ( true ) ) {
        struct Maybe_281  dref867 = ( (  next280 ) ( ( & (  it866 ) ) ) );
        if ( dref867.tag == Maybe_281_None_t ) {
            return (  x865 );
        }
        else {
            if ( dref867.tag == Maybe_281_Just_t ) {
                x865 = ( (  fun864 ) ( ( dref867 .stuff .Maybe_281_Just_s .field0 ) ,  (  x865 ) ) );
            }
        }
    }
    uint32_t  temp485;
    return (  temp485 );
}

static  struct Maybe_442   reduce486 (    struct TakeWhile_349  iterable860 ,    struct Maybe_442  base862 ,    struct Maybe_442 (*  fun864 )(    char  ,    struct Maybe_442  ) ) {
    struct Maybe_442  x865 = (  base862 );
    struct TakeWhile_349  it866 = ( (  into_dash_iter348 ) ( (  iterable860 ) ) );
    while ( ( true ) ) {
        struct Maybe_276  dref867 = ( (  next350 ) ( ( & (  it866 ) ) ) );
        if ( dref867.tag == Maybe_276_None_t ) {
            return (  x865 );
        }
        else {
            if ( dref867.tag == Maybe_276_Just_t ) {
                x865 = ( (  fun864 ) ( ( dref867 .stuff .Maybe_276_Just_s .field0 ) ,  (  x865 ) ) );
            }
        }
    }
    struct Maybe_442  temp487;
    return (  temp487 );
}

static  size_t   reduce488 (    struct TakeWhile_349  iterable860 ,    size_t  base862 ,    size_t (*  fun864 )(    char  ,    size_t  ) ) {
    size_t  x865 = (  base862 );
    struct TakeWhile_349  it866 = ( (  into_dash_iter348 ) ( (  iterable860 ) ) );
    while ( ( true ) ) {
        struct Maybe_276  dref867 = ( (  next350 ) ( ( & (  it866 ) ) ) );
        if ( dref867.tag == Maybe_276_None_t ) {
            return (  x865 );
        }
        else {
            if ( dref867.tag == Maybe_276_Just_t ) {
                x865 = ( (  fun864 ) ( ( dref867 .stuff .Maybe_276_Just_s .field0 ) ,  (  x865 ) ) );
            }
        }
    }
    size_t  temp489;
    return (  temp489 );
}

struct env491 {
    bool (*  fun893 )(    struct Tile_104  );
};

struct funenv491 {
    bool  (*fun) (  struct env491  ,    struct Tile_104  ,    bool  );
    struct env491 env;
};

static  bool   reduce490 (    struct FlattenIter_344  iterable860 ,    bool  base862 ,   struct funenv491  fun864 ) {
    bool  x865 = (  base862 );
    struct FlattenIter_344  it866 = ( (  into_dash_iter343 ) ( (  iterable860 ) ) );
    while ( ( true ) ) {
        struct Maybe_330  dref867 = ( (  next345 ) ( ( & (  it866 ) ) ) );
        if ( dref867.tag == Maybe_330_None_t ) {
            return (  x865 );
        }
        else {
            if ( dref867.tag == Maybe_330_Just_t ) {
                struct funenv491  temp492 = (  fun864 );
                x865 = ( temp492.fun ( temp492.env ,  ( dref867 .stuff .Maybe_330_Just_s .field0 ) ,  (  x865 ) ) );
            }
        }
    }
    bool  temp493;
    return (  temp493 );
}

struct SmolArrayIter_495 {
    struct SmolArray_71  f_backing;
    size_t  f_cur;
};

static  struct SmolArrayIter_495   into_dash_iter496 (    struct SmolArray_71  self1869 ) {
    return ( (struct SmolArrayIter_495) { .f_backing = (  self1869 ) , .f_cur = (  from_dash_integral8 ( 0 ) ) } );
}

static  int32_t *   get_dash_ptr499 (    struct Array_72 *  arr1831 ,    size_t  i1834 ) {
    if ( ( (  cmp39 ( (  i1834 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1834 ) , ( (size_t ) ( 3 ) ) ) != 0 ) ) ) {
        ( (  panic452 ) ( ( ( StrConcat_453_StrConcat ) ( ( ( StrConcat_454_StrConcat ) ( ( ( StrConcat_455_StrConcat ) ( ( ( StrConcat_456_StrConcat ) ( ( "Access to array at index " ) ,  (  i1834 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 3 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    int32_t *  p1835 = ( ( (  cast_dash_ptr207 ) ( (  arr1831 ) ) ) );
    return ( (  offset_dash_ptr141 ) ( (  p1835 ) ,  ( (int64_t ) (  i1834 ) ) ) );
}

static  int32_t   get498 (    struct Array_72 *  arr1838 ,    size_t  i1841 ) {
    return ( * ( (  get_dash_ptr499 ) ( (  arr1838 ) ,  (  i1841 ) ) ) );
}

static  struct Maybe_290   next497 (    struct SmolArrayIter_495 *  self1876 ) {
    if ( (  cmp39 ( ( ( * (  self1876 ) ) .f_cur ) , ( (size_t ) ( 3 ) ) ) != 0 ) ) {
        return ( (struct Maybe_290) { .tag = Maybe_290_None_t } );
    }
    int32_t  e1878 = ( (  get498 ) ( ( & ( ( ( * (  self1876 ) ) .f_backing ) .f_arr ) ) ,  ( ( * (  self1876 ) ) .f_cur ) ) );
    (*  self1876 ) .f_cur = (  op_dash_add58 ( ( ( * (  self1876 ) ) .f_cur ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_290_Just ) ( (  e1878 ) ) );
}

static  int32_t   reduce494 (    struct SmolArray_71  iterable860 ,    int32_t  base862 ,    int32_t (*  fun864 )(    int32_t  ,    int32_t  ) ) {
    int32_t  x865 = (  base862 );
    struct SmolArrayIter_495  it866 = ( (  into_dash_iter496 ) ( (  iterable860 ) ) );
    while ( ( true ) ) {
        struct Maybe_290  dref867 = ( (  next497 ) ( ( & (  it866 ) ) ) );
        if ( dref867.tag == Maybe_290_None_t ) {
            return (  x865 );
        }
        else {
            if ( dref867.tag == Maybe_290_Just_t ) {
                x865 = ( (  fun864 ) ( ( dref867 .stuff .Maybe_290_Just_s .field0 ) ,  (  x865 ) ) );
            }
        }
    }
    int32_t  temp500;
    return (  temp500 );
}

struct env502 {
    ;
    int32_t  base977;
};

struct funenv502 {
    int32_t  (*fun) (  struct env502  ,    int32_t  ,    int32_t  );
    struct env502 env;
};

static  int32_t   reduce501 (    struct Range_286  iterable860 ,    int32_t  base862 ,   struct funenv502  fun864 ) {
    int32_t  x865 = (  base862 );
    struct RangeIter_288  it866 = ( (  into_dash_iter287 ) ( (  iterable860 ) ) );
    while ( ( true ) ) {
        struct Maybe_290  dref867 = ( (  next289 ) ( ( & (  it866 ) ) ) );
        if ( dref867.tag == Maybe_290_None_t ) {
            return (  x865 );
        }
        else {
            if ( dref867.tag == Maybe_290_Just_t ) {
                struct funenv502  temp503 = (  fun864 );
                x865 = ( temp503.fun ( temp503.env ,  ( dref867 .stuff .Maybe_290_Just_s .field0 ) ,  (  x865 ) ) );
            }
        }
    }
    int32_t  temp504;
    return (  temp504 );
}

static  size_t   reduce505 (    struct ConstStrIter_279  iterable860 ,    size_t  base862 ,    size_t (*  fun864 )(    char  ,    size_t  ) ) {
    size_t  x865 = (  base862 );
    struct ConstStrIter_279  it866 = ( (  into_dash_iter342 ) ( (  iterable860 ) ) );
    while ( ( true ) ) {
        struct Maybe_276  dref867 = ( (  next282 ) ( ( & (  it866 ) ) ) );
        if ( dref867.tag == Maybe_276_None_t ) {
            return (  x865 );
        }
        else {
            if ( dref867.tag == Maybe_276_Just_t ) {
                x865 = ( (  fun864 ) ( ( dref867 .stuff .Maybe_276_Just_s .field0 ) ,  (  x865 ) ) );
            }
        }
    }
    size_t  temp506;
    return (  temp506 );
}

static  size_t   lam508 (    char  dref872 ,    size_t  x874 ) {
    return (  op_dash_add58 ( (  x874 ) , (  from_dash_integral8 ( 1 ) ) ) );
}

static  size_t   count507 (    struct TakeWhile_349  it871 ) {
    return ( (  reduce488 ) ( (  it871 ) ,  (  from_dash_integral8 ( 0 ) ) ,  (  lam508 ) ) );
}

static  size_t   lam510 (    char  dref872 ,    size_t  x874 ) {
    return (  op_dash_add58 ( (  x874 ) , (  from_dash_integral8 ( 1 ) ) ) );
}

static  size_t   count509 (    struct ConstStrIter_279  it871 ) {
    return ( (  reduce505 ) ( (  it871 ) ,  (  from_dash_integral8 ( 0 ) ) ,  (  lam510 ) ) );
}

static  bool   lam491 (   struct env491 env ,    struct Tile_104  e895 ,    bool  x897 ) {
    return ( ( ( env.fun893 ) ( (  e895 ) ) ) && (  x897 ) );
}

static  bool   all511 (    struct FlattenIter_344  it891 ,    bool (*  fun893 )(    struct Tile_104  ) ) {
    struct env491 envinst491 = {
        .fun893 =  fun893 ,
    };
    return ( (  reduce490 ) ( (  it891 ) ,  ( true ) ,  ( (struct funenv491){ .fun = lam491, .env = envinst491 } ) ) );
}

static  struct Maybe_276   head512 (    struct ConstStrIter_279  it909 ) {
    struct ConstStrIter_279  temp513 = ( (  into_dash_iter342 ) ( (  it909 ) ) );
    return ( (  next282 ) ( ( &temp513 ) ) );
}

static  struct Maybe_276   head514 (    struct SliceIter_269  it909 ) {
    struct SliceIter_269  temp515 = ( (  into_dash_iter417 ) ( (  it909 ) ) );
    return ( (  next313 ) ( ( &temp515 ) ) );
}

static  struct Maybe_276   head516 (    struct TakeWhile_349  it909 ) {
    struct TakeWhile_349  temp517 = ( (  into_dash_iter348 ) ( (  it909 ) ) );
    return ( (  next350 ) ( ( &temp517 ) ) );
}

struct IntStrIter_519 {
    int32_t  f_int;
    int32_t  f_len;
};

static  int32_t   lam502 (   struct env502 env ,    int32_t  item981 ,    int32_t  x983 ) {
    return (  op_dash_mul49 ( (  x983 ) , ( env.base977 ) ) );
}

static  int32_t   pow521 (    int32_t  base977 ,    int32_t  p979 ) {
    struct env502 envinst502 = {
        .base977 =  base977 ,
    };
    return ( (  reduce501 ) ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  op_dash_sub48 ( (  p979 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) ,  (  from_dash_integral3 ( 1 ) ) ,  ( (struct funenv502){ .fun = lam502, .env = envinst502 } ) ) );
}

static  struct Maybe_276   next520 (    struct IntStrIter_519 *  self1142 ) {
    if ( (  cmp40 ( ( ( * (  self1142 ) ) .f_len ) , (  from_dash_integral3 ( 0 ) ) ) != 2 ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    int32_t  trim_dash_down1143 = ( (  pow521 ) ( (  from_dash_integral3 ( 10 ) ) ,  (  op_dash_sub48 ( ( ( * (  self1142 ) ) .f_len ) , (  from_dash_integral3 ( 1 ) ) ) ) ) );
    int32_t  upper1144 = (  op_dash_div50 ( ( ( * (  self1142 ) ) .f_int ) , (  trim_dash_down1143 ) ) );
    int32_t  upper_dash_mask1145 = (  op_dash_mul49 ( (  op_dash_div50 ( (  upper1144 ) , (  from_dash_integral3 ( 10 ) ) ) ) , (  from_dash_integral3 ( 10 ) ) ) );
    int32_t  digit1146 = (  op_dash_sub48 ( (  upper1144 ) , (  upper_dash_mask1145 ) ) );
    (*  self1142 ) .f_len = (  op_dash_sub48 ( ( ( * (  self1142 ) ) .f_len ) , (  from_dash_integral3 ( 1 ) ) ) );
    char  digit_dash_char1147 = ( (  cast180 ) ( (  op_dash_add47 ( (  digit1146 ) , (  from_dash_integral3 ( 48 ) ) ) ) ) );
    return ( ( Maybe_276_Just ) ( (  digit_dash_char1147 ) ) );
}

static  struct IntStrIter_519   into_dash_iter523 (    struct IntStrIter_519  self1139 ) {
    return (  self1139 );
}

static  struct Maybe_276   head518 (    struct IntStrIter_519  it909 ) {
    struct IntStrIter_519  temp522 = ( (  into_dash_iter523 ) ( (  it909 ) ) );
    return ( (  next520 ) ( ( &temp522 ) ) );
}

static  bool   null524 (    struct TakeWhile_349  it918 ) {
    struct Maybe_276  dref919 = ( (  head516 ) ( (  it918 ) ) );
    if ( dref919.tag == Maybe_276_None_t ) {
        return ( true );
    }
    else {
        if ( true ) {
            return ( false );
        }
    }
}

static  struct Maybe_276   lam401 (   struct env401 env ,    int32_t  dref956 ) {
    return ( (  next351 ) ( ( env.it953 ) ) );
}

static  enum Unit_160   drop_prime_525 (    struct Scanner_268 *  it953 ,    size_t  n955 ) {
    struct env401 envinst401 = {
        .it953 =  it953 ,
    };
    ( (  for_dash_each400 ) ( ( (  to285 ) ( (  from_dash_integral3 ( 1 ) ) ,  ( (  size_dash_i32260 ) ( (  n955 ) ) ) ) ) ,  ( (struct funenv401){ .fun = lam401, .env = envinst401 } ) ) );
    return ( Unit_160_Unit );
}

struct Tuple2_527 {
    int32_t  field0;
    int32_t  field1;
};

static struct Tuple2_527 Tuple2_527_Tuple2 (  int32_t  field0 ,  int32_t  field1 ) {
    return ( struct Tuple2_527 ) { .field0 = field0 ,  .field1 = field1 };
};

static  int32_t   fst526 (    struct Tuple2_527  dref1017 ) {
    return ( dref1017 .field0 );
}

struct Tuple2_529 {
    uint32_t  field0;
    uint32_t  field1;
};

static struct Tuple2_529 Tuple2_529_Tuple2 (  uint32_t  field0 ,  uint32_t  field1 ) {
    return ( struct Tuple2_529 ) { .field0 = field0 ,  .field1 = field1 };
};

static  uint32_t   fst528 (    struct Tuple2_529  dref1017 ) {
    return ( dref1017 .field0 );
}

static  int32_t   snd530 (    struct Tuple2_527  dref1020 ) {
    return ( dref1020 .field1 );
}

static  uint32_t   snd531 (    struct Tuple2_529  dref1020 ) {
    return ( dref1020 .field1 );
}

struct Maybe_533 {
    enum {
        Maybe_533_None_t,
        Maybe_533_Just_t,
    } tag;
    union {
        struct {
            struct DynStr_411  field0;
        } Maybe_533_Just_s;
    } stuff;
};

static struct Maybe_533 Maybe_533_Just (  struct DynStr_411  field0 ) {
    return ( struct Maybe_533 ) { .tag = Maybe_533_Just_t, .stuff = { .Maybe_533_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_442   and_dash_maybe532 (    struct Maybe_533  m1028 ,    struct Maybe_442 (*  fun1030 )(    struct DynStr_411  ) ) {
    struct Maybe_533  dref1031 = (  m1028 );
    if ( dref1031.tag == Maybe_533_None_t ) {
        return ( (struct Maybe_442) { .tag = Maybe_442_None_t } );
    }
    else {
        if ( dref1031.tag == Maybe_533_Just_t ) {
            return ( (  fun1030 ) ( ( dref1031 .stuff .Maybe_533_Just_s .field0 ) ) );
        }
    }
}

struct env535 {
    size_t  x2594;
    ;
};

struct funenv535 {
    struct Maybe_330  (*fun) (  struct env535  ,    struct Slice_103  );
    struct env535 env;
};

static  struct Maybe_330   and_dash_maybe534 (    struct Maybe_325  m1028 ,   struct funenv535  fun1030 ) {
    struct Maybe_325  dref1031 = (  m1028 );
    if ( dref1031.tag == Maybe_325_None_t ) {
        return ( (struct Maybe_330) { .tag = Maybe_330_None_t } );
    }
    else {
        if ( dref1031.tag == Maybe_325_Just_t ) {
            struct funenv535  temp536 = (  fun1030 );
            return ( temp536.fun ( temp536.env ,  ( dref1031 .stuff .Maybe_325_Just_s .field0 ) ) );
        }
    }
}

struct env538 {
    enum CAllocator_378  al2995;
    ;
};

struct funenv538 {
    enum Unit_160  (*fun) (  struct env538  ,    const char*  );
    struct env538 env;
};

struct env539 {
    ;
    enum CAllocator_378  al2995;
};

struct funenv539 {
    struct Maybe_533  (*fun) (  struct env539  ,    const char*  );
    struct env539 env;
};

static  struct Maybe_533   with537 (    const char*  res1051 ,   struct funenv538  free_dash_fun1053 ,   struct funenv539  fun1055 ) {
    struct funenv539  temp540 = (  fun1055 );
    struct Maybe_533  ret1056 = ( temp540.fun ( temp540.env ,  (  res1051 ) ) );
    struct funenv538  temp541 = (  free_dash_fun1053 );
    ( temp541.fun ( temp541.env ,  (  res1051 ) ) );
    return (  ret1056 );
}

struct env543 {
    enum CAllocator_378  al3021;
    ;
};

struct funenv543 {
    enum Unit_160  (*fun) (  struct env543  ,    const char*  );
    struct env543 env;
};

struct Stats_545 {
    uint32_t  f_total_dash_wins;
};

struct env544 {
    ;
    struct Stats_545  stats3019;
    ;
};

struct funenv544 {
    enum Unit_160  (*fun) (  struct env544  ,    const char*  );
    struct env544 env;
};

static  enum Unit_160   with542 (    const char*  res1051 ,   struct funenv543  free_dash_fun1053 ,   struct funenv544  fun1055 ) {
    struct funenv544  temp546 = (  fun1055 );
    enum Unit_160  ret1056 = ( temp546.fun ( temp546.env ,  (  res1051 ) ) );
    struct funenv543  temp547 = (  free_dash_fun1053 );
    ( temp547.fun ( temp547.env ,  (  res1051 ) ) );
    return (  ret1056 );
}

static  uint32_t   mod548 (    uint32_t  l996 ,    uint32_t  d998 ) {
    uint32_t  r999 = (  op_dash_div55 ( (  l996 ) , (  d998 ) ) );
    uint32_t  m1000 = (  op_dash_sub53 ( (  l996 ) , (  op_dash_mul54 ( (  r999 ) , (  d998 ) ) ) ) );
    if ( (  cmp41 ( (  m1000 ) , (  from_dash_integral4 ( 0 ) ) ) == 0 ) ) {
        return (  op_dash_add52 ( (  d998 ) , (  m1000 ) ) );
    } else {
        return (  m1000 );
    }
}

static  int32_t   mod549 (    int32_t  l996 ,    int32_t  d998 ) {
    int32_t  r999 = (  op_dash_div50 ( (  l996 ) , (  d998 ) ) );
    int32_t  m1000 = (  op_dash_sub48 ( (  l996 ) , (  op_dash_mul49 ( (  r999 ) , (  d998 ) ) ) ) );
    if ( (  cmp40 ( (  m1000 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) ) {
        return (  op_dash_add47 ( (  d998 ) , (  m1000 ) ) );
    } else {
        return (  m1000 );
    }
}

static  size_t   min550 (    size_t  l1003 ,    size_t  r1005 ) {
    if ( (  cmp39 ( (  l1003 ) , (  r1005 ) ) == 0 ) ) {
        return (  l1003 );
    } else {
        return (  r1005 );
    }
}

static  int32_t   min551 (    int32_t  l1003 ,    int32_t  r1005 ) {
    if ( (  cmp40 ( (  l1003 ) , (  r1005 ) ) == 0 ) ) {
        return (  l1003 );
    } else {
        return (  r1005 );
    }
}

static  struct ConstStrIter_279   chars552 (    const char*  self1124 ) {
    return ( (  into_dash_iter284 ) ( (  self1124 ) ) );
}

static  struct AppendIter_354   chars553 (    char  self1130 ) {
    return ( (  single356 ) ( (  self1130 ) ) );
}

static  int32_t   count_dash_digits554 (    uint32_t  self1150 ) {
    if ( (  eq10 ( (  self1150 ) , (  from_dash_integral4 ( 0 ) ) ) ) ) {
        return (  from_dash_integral3 ( 1 ) );
    }
    int32_t  digits1151 = (  from_dash_integral3 ( 0 ) );
    while ( (  cmp41 ( (  self1150 ) , (  from_dash_integral4 ( 0 ) ) ) == 2 ) ) {
        self1150 = (  op_dash_div55 ( (  self1150 ) , (  from_dash_integral4 ( 10 ) ) ) );
        digits1151 = (  op_dash_add47 ( (  digits1151 ) , (  from_dash_integral3 ( 1 ) ) ) );
    }
    return (  digits1151 );
}

static  int32_t   count_dash_digits555 (    int32_t  self1150 ) {
    if ( (  eq9 ( (  self1150 ) , (  from_dash_integral3 ( 0 ) ) ) ) ) {
        return (  from_dash_integral3 ( 1 ) );
    }
    int32_t  digits1151 = (  from_dash_integral3 ( 0 ) );
    while ( (  cmp40 ( (  self1150 ) , (  from_dash_integral3 ( 0 ) ) ) == 2 ) ) {
        self1150 = (  op_dash_div50 ( (  self1150 ) , (  from_dash_integral3 ( 10 ) ) ) );
        digits1151 = (  op_dash_add47 ( (  digits1151 ) , (  from_dash_integral3 ( 1 ) ) ) );
    }
    return (  digits1151 );
}

static  struct IntStrIter_519   chars556 (    int32_t  self1157 ) {
    return ( (struct IntStrIter_519) { .f_int = (  self1157 ) , .f_len = ( (  count_dash_digits555 ) ( (  self1157 ) ) ) } );
}

static  enum Unit_160   print_dash_str557 (    uint32_t  self1160 ) {
    ( ( printf ) ( ( "%u" ) ,  (  self1160 ) ) );
    return ( Unit_160_Unit );
}

static  struct IntStrIter_300   chars558 (    uint32_t  self1163 ) {
    return ( (struct IntStrIter_300) { .f_int = (  self1163 ) , .f_len = ( (  count_dash_digits554 ) ( (  self1163 ) ) ) } );
}

static  enum Unit_160   print_dash_str559 (    uint8_t  self1166 ) {
    ( ( printf ) ( ( "%d" ) ,  ( (  u8_dash_i32266 ) ( (  self1166 ) ) ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str560 (    int64_t  self1172 ) {
    ( ( printf ) ( ( "%ld" ) ,  (  self1172 ) ) );
    return ( Unit_160_Unit );
}

struct StrConcatIter_562 {
    struct IntStrIter_300  f_left;
    struct AppendIter_354  f_right;
};

static  struct Maybe_276   next561 (    struct StrConcatIter_562 *  self1208 ) {
    struct Maybe_276  dref1209 = ( (  next316 ) ( ( & ( ( * (  self1208 ) ) .f_left ) ) ) );
    if ( dref1209.tag == Maybe_276_Just_t ) {
        return ( ( Maybe_276_Just ) ( ( dref1209 .stuff .Maybe_276_Just_s .field0 ) ) );
    }
    else {
        if ( dref1209.tag == Maybe_276_None_t ) {
            return ( (  next357 ) ( ( & ( ( * (  self1208 ) ) .f_right ) ) ) );
        }
    }
}

struct StrConcat_566 {
    const char*  field0;
    const char*  field1;
};

static struct StrConcat_566 StrConcat_566_StrConcat (  const char*  field0 ,  const char*  field1 ) {
    return ( struct StrConcat_566 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrCase_565 {
    enum {
        StrCase_565_StrCase1_t,
        StrCase_565_StrCase2_t,
    } tag;
    union {
        struct {
            const char*  field0;
        } StrCase_565_StrCase1_s;
        struct {
            struct StrConcat_566  field0;
        } StrCase_565_StrCase2_s;
    } stuff;
};

static struct StrCase_565 StrCase_565_StrCase1 (  const char*  field0 ) {
    return ( struct StrCase_565 ) { .tag = StrCase_565_StrCase1_t, .stuff = { .StrCase_565_StrCase1_s = { .field0 = field0 } } };
};

static struct StrCase_565 StrCase_565_StrCase2 (  struct StrConcat_566  field0 ) {
    return ( struct StrCase_565 ) { .tag = StrCase_565_StrCase2_t, .stuff = { .StrCase_565_StrCase2_s = { .field0 = field0 } } };
};

struct StrConcat_564 {
    struct StrCase_565  field0;
    const char*  field1;
};

static struct StrConcat_564 StrConcat_564_StrConcat (  struct StrCase_565  field0 ,  const char*  field1 ) {
    return ( struct StrConcat_564 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct StrConcatIter_373   into_dash_iter570 (    struct StrConcat_566  dref1212 ) {
    return ( (struct StrConcatIter_373) { .f_left = ( (  chars552 ) ( ( dref1212 .field0 ) ) ) , .f_right = ( (  chars552 ) ( ( dref1212 .field1 ) ) ) } );
}

static  struct StrConcatIter_373   chars569 (    struct StrConcat_566  self1223 ) {
    return ( (  into_dash_iter570 ) ( (  self1223 ) ) );
}

static  struct StrCaseIter_372   into_dash_iter568 (    struct StrCase_565  self1236 ) {
    struct StrCase_565  dref1237 = (  self1236 );
    if ( dref1237.tag == StrCase_565_StrCase1_t ) {
        return ( ( StrCaseIter_372_StrCaseIter1 ) ( ( (  chars552 ) ( ( dref1237 .stuff .StrCase_565_StrCase1_s .field0 ) ) ) ) );
    }
    else {
        if ( dref1237.tag == StrCase_565_StrCase2_t ) {
            return ( ( StrCaseIter_372_StrCaseIter2 ) ( ( (  chars569 ) ( ( dref1237 .stuff .StrCase_565_StrCase2_s .field0 ) ) ) ) );
        }
    }
}

static  struct StrCaseIter_372   chars567 (    struct StrCase_565  self1248 ) {
    return ( (  into_dash_iter568 ) ( (  self1248 ) ) );
}

static  struct StrConcatIter_371   into_dash_iter563 (    struct StrConcat_564  dref1212 ) {
    return ( (struct StrConcatIter_371) { .f_left = ( (  chars567 ) ( ( dref1212 .field0 ) ) ) , .f_right = ( (  chars552 ) ( ( dref1212 .field1 ) ) ) } );
}

struct StrConcat_572 {
    uint32_t  field0;
    char  field1;
};

static struct StrConcat_572 StrConcat_572_StrConcat (  uint32_t  field0 ,  char  field1 ) {
    return ( struct StrConcat_572 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct StrConcatIter_562   into_dash_iter571 (    struct StrConcat_572  dref1212 ) {
    return ( (struct StrConcatIter_562) { .f_left = ( (  chars558 ) ( ( dref1212 .field0 ) ) ) , .f_right = ( (  chars553 ) ( ( dref1212 .field1 ) ) ) } );
}

struct StrConcat_574 {
    struct StrConcat_564  field0;
    const char*  field1;
};

static struct StrConcat_574 StrConcat_574_StrConcat (  struct StrConcat_564  field0 ,  const char*  field1 ) {
    return ( struct StrConcat_574 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct StrConcatIter_371   chars575 (    struct StrConcat_564  self1223 ) {
    return ( (  into_dash_iter563 ) ( (  self1223 ) ) );
}

static  struct StrConcatIter_420   into_dash_iter573 (    struct StrConcat_574  dref1212 ) {
    return ( (struct StrConcatIter_420) { .f_left = ( (  chars575 ) ( ( dref1212 .field0 ) ) ) , .f_right = ( (  chars552 ) ( ( dref1212 .field1 ) ) ) } );
}

struct StrConcat_577 {
    const char*  field0;
    uint32_t  field1;
};

static struct StrConcat_577 StrConcat_577_StrConcat (  const char*  field0 ,  uint32_t  field1 ) {
    return ( struct StrConcat_577 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct StrConcatIter_299   into_dash_iter576 (    struct StrConcat_577  dref1212 ) {
    return ( (struct StrConcatIter_299) { .f_left = ( (  chars552 ) ( ( dref1212 .field0 ) ) ) , .f_right = ( (  chars558 ) ( ( dref1212 .field1 ) ) ) } );
}

struct StrConcat_579 {
    struct StrConcat_566  field0;
    char  field1;
};

static struct StrConcat_579 StrConcat_579_StrConcat (  struct StrConcat_566  field0 ,  char  field1 ) {
    return ( struct StrConcat_579 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_160   print_dash_str580 (    struct StrConcat_566  self1217 ) {
    struct StrConcat_566  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str461 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str461 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str578 (    struct StrConcat_579  self1217 ) {
    struct StrConcat_579  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str580 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str468 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

struct StrConcat_583 {
    struct StrConcat_455  field0;
    size_t  field1;
};

static struct StrConcat_583 StrConcat_583_StrConcat (  struct StrConcat_455  field0 ,  size_t  field1 ) {
    return ( struct StrConcat_583 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_582 {
    struct StrConcat_583  field0;
    char  field1;
};

static struct StrConcat_582 StrConcat_582_StrConcat (  struct StrConcat_583  field0 ,  char  field1 ) {
    return ( struct StrConcat_582 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_160   print_dash_str584 (    struct StrConcat_583  self1217 ) {
    struct StrConcat_583  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str464 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str466 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str581 (    struct StrConcat_582  self1217 ) {
    struct StrConcat_582  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str584 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str468 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

struct StrConcat_587 {
    const char*  field0;
    struct StrConcat_582  field1;
};

static struct StrConcat_587 StrConcat_587_StrConcat (  const char*  field0 ,  struct StrConcat_582  field1 ) {
    return ( struct StrConcat_587 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_586 {
    struct StrConcat_587  field0;
    char  field1;
};

static struct StrConcat_586 StrConcat_586_StrConcat (  struct StrConcat_587  field0 ,  char  field1 ) {
    return ( struct StrConcat_586 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_160   print_dash_str588 (    struct StrConcat_587  self1217 ) {
    struct StrConcat_587  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str461 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str581 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str585 (    struct StrConcat_586  self1217 ) {
    struct StrConcat_586  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str588 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str468 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

struct StrConcat_591 {
    char  field0;
    char  field1;
};

static struct StrConcat_591 StrConcat_591_StrConcat (  char  field0 ,  char  field1 ) {
    return ( struct StrConcat_591 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_590 {
    struct StrConcat_591  field0;
    const char*  field1;
};

static struct StrConcat_590 StrConcat_590_StrConcat (  struct StrConcat_591  field0 ,  const char*  field1 ) {
    return ( struct StrConcat_590 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_160   print_dash_str592 (    struct StrConcat_591  self1217 ) {
    struct StrConcat_591  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str468 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str468 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str589 (    struct StrConcat_590  self1217 ) {
    struct StrConcat_590  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str592 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str461 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

struct StrConcat_595 {
    const char*  field0;
    struct StrConcat_590  field1;
};

static struct StrConcat_595 StrConcat_595_StrConcat (  const char*  field0 ,  struct StrConcat_590  field1 ) {
    return ( struct StrConcat_595 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_594 {
    struct StrConcat_595  field0;
    char  field1;
};

static struct StrConcat_594 StrConcat_594_StrConcat (  struct StrConcat_595  field0 ,  char  field1 ) {
    return ( struct StrConcat_594 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_160   print_dash_str596 (    struct StrConcat_595  self1217 ) {
    struct StrConcat_595  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str461 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str589 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str593 (    struct StrConcat_594  self1217 ) {
    struct StrConcat_594  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str596 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str468 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

struct StrConcat_598 {
    const char*  field0;
    int64_t  field1;
};

static struct StrConcat_598 StrConcat_598_StrConcat (  const char*  field0 ,  int64_t  field1 ) {
    return ( struct StrConcat_598 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_160   print_dash_str597 (    struct StrConcat_598  self1217 ) {
    struct StrConcat_598  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str461 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str560 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

struct StrConcat_601 {
    const char*  field0;
    struct StrConcat_598  field1;
};

static struct StrConcat_601 StrConcat_601_StrConcat (  const char*  field0 ,  struct StrConcat_598  field1 ) {
    return ( struct StrConcat_601 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_600 {
    struct StrConcat_601  field0;
    char  field1;
};

static struct StrConcat_600 StrConcat_600_StrConcat (  struct StrConcat_601  field0 ,  char  field1 ) {
    return ( struct StrConcat_600 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_160   print_dash_str602 (    struct StrConcat_601  self1217 ) {
    struct StrConcat_601  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str461 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str597 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str599 (    struct StrConcat_600  self1217 ) {
    struct StrConcat_600  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str602 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str468 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

struct StrConcat_605 {
    const char*  field0;
    struct StrConcat_566  field1;
};

static struct StrConcat_605 StrConcat_605_StrConcat (  const char*  field0 ,  struct StrConcat_566  field1 ) {
    return ( struct StrConcat_605 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_604 {
    struct StrConcat_605  field0;
    char  field1;
};

static struct StrConcat_604 StrConcat_604_StrConcat (  struct StrConcat_605  field0 ,  char  field1 ) {
    return ( struct StrConcat_604 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_160   print_dash_str606 (    struct StrConcat_605  self1217 ) {
    struct StrConcat_605  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str461 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str580 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str603 (    struct StrConcat_604  self1217 ) {
    struct StrConcat_604  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str606 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str468 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

struct StrConcat_610 {
    struct StrConcat_577  field0;
    char  field1;
};

static struct StrConcat_610 StrConcat_610_StrConcat (  struct StrConcat_577  field0 ,  char  field1 ) {
    return ( struct StrConcat_610 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_609 {
    struct StrConcat_610  field0;
    uint32_t  field1;
};

static struct StrConcat_609 StrConcat_609_StrConcat (  struct StrConcat_610  field0 ,  uint32_t  field1 ) {
    return ( struct StrConcat_609 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_608 {
    struct StrConcat_609  field0;
    char  field1;
};

static struct StrConcat_608 StrConcat_608_StrConcat (  struct StrConcat_609  field0 ,  char  field1 ) {
    return ( struct StrConcat_608 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_160   print_dash_str613 (    struct StrConcat_577  self1217 ) {
    struct StrConcat_577  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str461 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str557 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str612 (    struct StrConcat_610  self1217 ) {
    struct StrConcat_610  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str613 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str468 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str611 (    struct StrConcat_609  self1217 ) {
    struct StrConcat_609  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str612 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str557 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str607 (    struct StrConcat_608  self1217 ) {
    struct StrConcat_608  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str611 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str468 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

struct StrConcat_620 {
    const char*  field0;
    uint8_t  field1;
};

static struct StrConcat_620 StrConcat_620_StrConcat (  const char*  field0 ,  uint8_t  field1 ) {
    return ( struct StrConcat_620 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_619 {
    struct StrConcat_620  field0;
    char  field1;
};

static struct StrConcat_619 StrConcat_619_StrConcat (  struct StrConcat_620  field0 ,  char  field1 ) {
    return ( struct StrConcat_619 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_618 {
    struct StrConcat_619  field0;
    uint8_t  field1;
};

static struct StrConcat_618 StrConcat_618_StrConcat (  struct StrConcat_619  field0 ,  uint8_t  field1 ) {
    return ( struct StrConcat_618 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_617 {
    struct StrConcat_618  field0;
    char  field1;
};

static struct StrConcat_617 StrConcat_617_StrConcat (  struct StrConcat_618  field0 ,  char  field1 ) {
    return ( struct StrConcat_617 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_616 {
    struct StrConcat_617  field0;
    uint8_t  field1;
};

static struct StrConcat_616 StrConcat_616_StrConcat (  struct StrConcat_617  field0 ,  uint8_t  field1 ) {
    return ( struct StrConcat_616 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_615 {
    struct StrConcat_616  field0;
    char  field1;
};

static struct StrConcat_615 StrConcat_615_StrConcat (  struct StrConcat_616  field0 ,  char  field1 ) {
    return ( struct StrConcat_615 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_160   print_dash_str625 (    struct StrConcat_620  self1217 ) {
    struct StrConcat_620  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str461 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str559 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str624 (    struct StrConcat_619  self1217 ) {
    struct StrConcat_619  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str625 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str468 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str623 (    struct StrConcat_618  self1217 ) {
    struct StrConcat_618  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str624 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str559 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str622 (    struct StrConcat_617  self1217 ) {
    struct StrConcat_617  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str623 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str468 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str621 (    struct StrConcat_616  self1217 ) {
    struct StrConcat_616  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str622 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str559 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   print_dash_str614 (    struct StrConcat_615  self1217 ) {
    struct StrConcat_615  dref1218 = (  self1217 );
    if ( true ) {
        ( (  print_dash_str621 ) ( ( dref1218 .field0 ) ) );
        ( (  print_dash_str468 ) ( ( dref1218 .field1 ) ) );
    }
    return ( Unit_160_Unit );
}

static  struct StrConcatIter_562   chars626 (    struct StrConcat_572  self1223 ) {
    return ( (  into_dash_iter571 ) ( (  self1223 ) ) );
}

static  struct StrConcatIter_420   chars627 (    struct StrConcat_574  self1223 ) {
    return ( (  into_dash_iter573 ) ( (  self1223 ) ) );
}

static  struct StrConcatIter_299   chars628 (    struct StrConcat_577  self1223 ) {
    return ( (  into_dash_iter576 ) ( (  self1223 ) ) );
}

static  struct TakeWhile_349   chars629 (    struct TakeWhile_349  self1333 ) {
    return (  self1333 );
}

static  char   nullchar630 (  ) {
    return ( (  zeroed214 ) ( ) );
}

static  int32_t   char_dash_i32631 (    char  c1360 ) {
    return ( (  cast_dash_on_dash_zeroed232 ) ( (  c1360 ) ) );
}

static  uint8_t   char_dash_u8632 (    char  c1363 ) {
    return ( (  cast178 ) ( (  c1363 ) ) );
}

static  char   i32_dash_char633 (    int32_t  i1366 ) {
    return ( (  cast180 ) ( (  i1366 ) ) );
}

static  bool   eq634 (    const char*  l1379 ,    const char*  r1381 ) {
    return (  eq9 ( ( ( strcmp ) ( (  l1379 ) ,  (  r1381 ) ) ) , (  from_dash_integral3 ( 0 ) ) ) );
}

static  enum Ordering_38   cmp635 (    char  l1384 ,    char  r1386 ) {
    return ( (  cmp40 ) ( ( (  char_dash_i32631 ) ( (  l1384 ) ) ) ,  ( (  char_dash_i32631 ) ( (  r1386 ) ) ) ) );
}

static  bool   unreachable636 (  ) {
    ( (  print_dash_str461 ) ( ( "unreachable\n" ) ) );
    ( ( exit ) ( (  from_dash_integral3 ( 1 ) ) ) );
    return ( (  undefined121 ) ( ) );
}

static  enum Unit_160   panic637 (    const char*  errmsg1394 ) {
    ( (  print_dash_str578 ) ( ( ( StrConcat_579_StrConcat ) ( ( ( StrConcat_566_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1394 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral3 ( 1 ) ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   panic638 (    struct StrConcat_582  errmsg1394 ) {
    ( (  print_dash_str585 ) ( ( ( StrConcat_586_StrConcat ) ( ( ( StrConcat_587_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1394 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral3 ( 1 ) ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   panic639 (    struct StrConcat_590  errmsg1394 ) {
    ( (  print_dash_str593 ) ( ( ( StrConcat_594_StrConcat ) ( ( ( StrConcat_595_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1394 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral3 ( 1 ) ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   panic640 (    struct StrConcat_566  errmsg1394 ) {
    ( (  print_dash_str603 ) ( ( ( StrConcat_604_StrConcat ) ( ( ( StrConcat_605_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1394 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral3 ( 1 ) ) ) );
    return ( Unit_160_Unit );
}

static  enum MouseButton_119   panic_prime_641 (    struct StrConcat_598  errmsg1397 ) {
    ( (  print_dash_str599 ) ( ( ( StrConcat_600_StrConcat ) ( ( ( StrConcat_601_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1397 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral3 ( 1 ) ) ) );
    return ( (  undefined118 ) ( ) );
}

static  int64_t   or_dash_fail642 (    struct Maybe_442  x1407 ,    const char*  errmsg1409 ) {
    struct Maybe_442  dref1410 = (  x1407 );
    if ( dref1410.tag == Maybe_442_None_t ) {
        ( (  panic637 ) ( (  errmsg1409 ) ) );
        return ( (  undefined98 ) ( ) );
    }
    else {
        if ( dref1410.tag == Maybe_442_Just_t ) {
            return ( dref1410 .stuff .Maybe_442_Just_s .field0 );
        }
    }
}

static  char   or_dash_fail643 (    struct Maybe_276  x1407 ,    struct StrConcat_582  errmsg1409 ) {
    struct Maybe_276  dref1410 = (  x1407 );
    if ( dref1410.tag == Maybe_276_None_t ) {
        ( (  panic638 ) ( (  errmsg1409 ) ) );
        return ( (  undefined100 ) ( ) );
    }
    else {
        if ( dref1410.tag == Maybe_276_Just_t ) {
            return ( dref1410 .stuff .Maybe_276_Just_s .field0 );
        }
    }
}

static  struct Slice_103   or_dash_fail644 (    struct Maybe_325  x1407 ,    struct StrConcat_582  errmsg1409 ) {
    struct Maybe_325  dref1410 = (  x1407 );
    if ( dref1410.tag == Maybe_325_None_t ) {
        ( (  panic638 ) ( (  errmsg1409 ) ) );
        return ( (  undefined102 ) ( ) );
    }
    else {
        if ( dref1410.tag == Maybe_325_Just_t ) {
            return ( dref1410 .stuff .Maybe_325_Just_s .field0 );
        }
    }
}

static  struct Tile_104   or_dash_fail645 (    struct Maybe_330  x1407 ,    struct StrConcat_582  errmsg1409 ) {
    struct Maybe_330  dref1410 = (  x1407 );
    if ( dref1410.tag == Maybe_330_None_t ) {
        ( (  panic638 ) ( (  errmsg1409 ) ) );
        return ( (  undefined106 ) ( ) );
    }
    else {
        if ( dref1410.tag == Maybe_330_Just_t ) {
            return ( dref1410 .stuff .Maybe_330_Just_s .field0 );
        }
    }
}

struct Maybe_647 {
    enum {
        Maybe_647_None_t,
        Maybe_647_Just_t,
    } tag;
    union {
        struct {
            struct Cell_16  field0;
        } Maybe_647_Just_s;
    } stuff;
};

static struct Maybe_647 Maybe_647_Just (  struct Cell_16  field0 ) {
    return ( struct Maybe_647 ) { .tag = Maybe_647_Just_t, .stuff = { .Maybe_647_Just_s = { .field0 = field0 } } };
};

static  struct Cell_16   or_dash_fail646 (    struct Maybe_647  x1407 ,    struct StrConcat_582  errmsg1409 ) {
    struct Maybe_647  dref1410 = (  x1407 );
    if ( dref1410.tag == Maybe_647_None_t ) {
        ( (  panic638 ) ( (  errmsg1409 ) ) );
        return ( (  undefined114 ) ( ) );
    }
    else {
        if ( dref1410.tag == Maybe_647_Just_t ) {
            return ( dref1410 .stuff .Maybe_647_Just_s .field0 );
        }
    }
}

struct Maybe_649 {
    enum {
        Maybe_649_None_t,
        Maybe_649_Just_t,
    } tag;
    union {
        struct {
            uint8_t  field0;
        } Maybe_649_Just_s;
    } stuff;
};

static struct Maybe_649 Maybe_649_Just (  uint8_t  field0 ) {
    return ( struct Maybe_649 ) { .tag = Maybe_649_Just_t, .stuff = { .Maybe_649_Just_s = { .field0 = field0 } } };
};

static  uint8_t   or_dash_fail648 (    struct Maybe_649  x1407 ,    struct StrConcat_590  errmsg1409 ) {
    struct Maybe_649  dref1410 = (  x1407 );
    if ( dref1410.tag == Maybe_649_None_t ) {
        ( (  panic639 ) ( (  errmsg1409 ) ) );
        return ( (  undefined116 ) ( ) );
    }
    else {
        if ( dref1410.tag == Maybe_649_Just_t ) {
            return ( dref1410 .stuff .Maybe_649_Just_s .field0 );
        }
    }
}

struct Maybe_651 {
    enum {
        Maybe_651_None_t,
        Maybe_651_Just_t,
    } tag;
    union {
        struct {
            struct Cell_16 *  field0;
        } Maybe_651_Just_s;
    } stuff;
};

static struct Maybe_651 Maybe_651_Just (  struct Cell_16 *  field0 ) {
    return ( struct Maybe_651 ) { .tag = Maybe_651_Just_t, .stuff = { .Maybe_651_Just_s = { .field0 = field0 } } };
};

static  struct Cell_16 *   or_dash_fail650 (    struct Maybe_651  x1407 ,    const char*  errmsg1409 ) {
    struct Maybe_651  dref1410 = (  x1407 );
    if ( dref1410.tag == Maybe_651_None_t ) {
        ( (  panic637 ) ( (  errmsg1409 ) ) );
        return ( (  undefined125 ) ( ) );
    }
    else {
        if ( dref1410.tag == Maybe_651_Just_t ) {
            return ( dref1410 .stuff .Maybe_651_Just_s .field0 );
        }
    }
}

static  char   or_dash_fail652 (    struct Maybe_276  x1407 ,    const char*  errmsg1409 ) {
    struct Maybe_276  dref1410 = (  x1407 );
    if ( dref1410.tag == Maybe_276_None_t ) {
        ( (  panic637 ) ( (  errmsg1409 ) ) );
        return ( (  undefined100 ) ( ) );
    }
    else {
        if ( dref1410.tag == Maybe_276_Just_t ) {
            return ( dref1410 .stuff .Maybe_276_Just_s .field0 );
        }
    }
}

static  int64_t   or_dash_else653 (    struct Maybe_442  self1414 ,    int64_t  alt1416 ) {
    struct Maybe_442  dref1417 = (  self1414 );
    if ( dref1417.tag == Maybe_442_None_t ) {
        return (  alt1416 );
    }
    else {
        if ( dref1417.tag == Maybe_442_Just_t ) {
            return ( dref1417 .stuff .Maybe_442_Just_s .field0 );
        }
    }
}

static  const char*   or_dash_else654 (    struct Maybe_252  self1414 ,    const char*  alt1416 ) {
    struct Maybe_252  dref1417 = (  self1414 );
    if ( dref1417.tag == Maybe_252_None_t ) {
        return (  alt1416 );
    }
    else {
        if ( dref1417.tag == Maybe_252_Just_t ) {
            return ( dref1417 .stuff .Maybe_252_Just_s .field0 );
        }
    }
}

static  struct Tile_104   or_dash_else655 (    struct Maybe_330  self1414 ,    struct Tile_104  alt1416 ) {
    struct Maybe_330  dref1417 = (  self1414 );
    if ( dref1417.tag == Maybe_330_None_t ) {
        return (  alt1416 );
    }
    else {
        if ( dref1417.tag == Maybe_330_Just_t ) {
            return ( dref1417 .stuff .Maybe_330_Just_s .field0 );
        }
    }
}

static  struct Slice_270   empty656 (  ) {
    return ( (struct Slice_270) { .f_ptr = ( (  null_dash_ptr245 ) ( ) ) , .f_count = (  from_dash_integral8 ( 0 ) ) } );
}

static  char *   get_dash_ptr657 (    struct Slice_270  slice1440 ,    size_t  i1442 ) {
    if ( ( (  cmp39 ( (  i1442 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1442 ) , ( (  slice1440 ) .f_count ) ) != 0 ) ) ) {
        ( (  panic638 ) ( ( ( StrConcat_582_StrConcat ) ( ( ( StrConcat_583_StrConcat ) ( ( ( StrConcat_455_StrConcat ) ( ( ( StrConcat_456_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1442 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1440 ) .f_count ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    char *  elem_dash_ptr1443 = ( (  offset_dash_ptr129 ) ( ( (  slice1440 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  i1442 ) ) ) ) );
    return (  elem_dash_ptr1443 );
}

static  struct Tile_104 *   get_dash_ptr658 (    struct Slice_103  slice1440 ,    size_t  i1442 ) {
    if ( ( (  cmp39 ( (  i1442 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1442 ) , ( (  slice1440 ) .f_count ) ) != 0 ) ) ) {
        ( (  panic638 ) ( ( ( StrConcat_582_StrConcat ) ( ( ( StrConcat_583_StrConcat ) ( ( ( StrConcat_455_StrConcat ) ( ( ( StrConcat_456_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1442 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1440 ) .f_count ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    struct Tile_104 *  elem_dash_ptr1443 = ( (  offset_dash_ptr133 ) ( ( (  slice1440 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  i1442 ) ) ) ) );
    return (  elem_dash_ptr1443 );
}

static  struct Cell_16 *   get_dash_ptr659 (    struct Slice_393  slice1440 ,    size_t  i1442 ) {
    if ( ( (  cmp39 ( (  i1442 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1442 ) , ( (  slice1440 ) .f_count ) ) != 0 ) ) ) {
        ( (  panic638 ) ( ( ( StrConcat_582_StrConcat ) ( ( ( StrConcat_583_StrConcat ) ( ( ( StrConcat_455_StrConcat ) ( ( ( StrConcat_456_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1442 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1440 ) .f_count ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    struct Cell_16 *  elem_dash_ptr1443 = ( (  offset_dash_ptr139 ) ( ( (  slice1440 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  i1442 ) ) ) ) );
    return (  elem_dash_ptr1443 );
}

static  struct Maybe_276   try_dash_get660 (    struct Slice_270  slice1446 ,    size_t  i1448 ) {
    if ( ( (  cmp39 ( (  i1448 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1448 ) , ( (  slice1446 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    char *  elem_dash_ptr1449 = ( (  offset_dash_ptr129 ) ( ( (  slice1446 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  i1448 ) ) ) ) );
    return ( ( Maybe_276_Just ) ( ( * (  elem_dash_ptr1449 ) ) ) );
}

static  struct Maybe_325   try_dash_get661 (    struct Slice_304  slice1446 ,    size_t  i1448 ) {
    if ( ( (  cmp39 ( (  i1448 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1448 ) , ( (  slice1446 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Maybe_325) { .tag = Maybe_325_None_t } );
    }
    struct Slice_103 *  elem_dash_ptr1449 = ( (  offset_dash_ptr131 ) ( ( (  slice1446 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  i1448 ) ) ) ) );
    return ( ( Maybe_325_Just ) ( ( * (  elem_dash_ptr1449 ) ) ) );
}

static  struct Maybe_330   try_dash_get662 (    struct Slice_103  slice1446 ,    size_t  i1448 ) {
    if ( ( (  cmp39 ( (  i1448 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1448 ) , ( (  slice1446 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Maybe_330) { .tag = Maybe_330_None_t } );
    }
    struct Tile_104 *  elem_dash_ptr1449 = ( (  offset_dash_ptr133 ) ( ( (  slice1446 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  i1448 ) ) ) ) );
    return ( ( Maybe_330_Just ) ( ( * (  elem_dash_ptr1449 ) ) ) );
}

static  struct Maybe_647   try_dash_get663 (    struct Slice_393  slice1446 ,    size_t  i1448 ) {
    if ( ( (  cmp39 ( (  i1448 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1448 ) , ( (  slice1446 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Maybe_647) { .tag = Maybe_647_None_t } );
    }
    struct Cell_16 *  elem_dash_ptr1449 = ( (  offset_dash_ptr139 ) ( ( (  slice1446 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  i1448 ) ) ) ) );
    return ( ( Maybe_647_Just ) ( ( * (  elem_dash_ptr1449 ) ) ) );
}

static  char   get664 (    struct Slice_270  slice1452 ,    size_t  i1454 ) {
    return ( (  or_dash_fail643 ) ( ( (  try_dash_get660 ) ( (  slice1452 ) ,  (  i1454 ) ) ) ,  ( ( StrConcat_582_StrConcat ) ( ( ( StrConcat_583_StrConcat ) ( ( ( StrConcat_455_StrConcat ) ( ( ( StrConcat_456_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1454 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1452 ) .f_count ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
}

static  struct Slice_103   get665 (    struct Slice_304  slice1452 ,    size_t  i1454 ) {
    return ( (  or_dash_fail644 ) ( ( (  try_dash_get661 ) ( (  slice1452 ) ,  (  i1454 ) ) ) ,  ( ( StrConcat_582_StrConcat ) ( ( ( StrConcat_583_StrConcat ) ( ( ( StrConcat_455_StrConcat ) ( ( ( StrConcat_456_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1454 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1452 ) .f_count ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
}

static  struct Tile_104   get666 (    struct Slice_103  slice1452 ,    size_t  i1454 ) {
    return ( (  or_dash_fail645 ) ( ( (  try_dash_get662 ) ( (  slice1452 ) ,  (  i1454 ) ) ) ,  ( ( StrConcat_582_StrConcat ) ( ( ( StrConcat_583_StrConcat ) ( ( ( StrConcat_455_StrConcat ) ( ( ( StrConcat_456_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1454 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1452 ) .f_count ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
}

static  struct Cell_16   get667 (    struct Slice_393  slice1452 ,    size_t  i1454 ) {
    return ( (  or_dash_fail646 ) ( ( (  try_dash_get663 ) ( (  slice1452 ) ,  (  i1454 ) ) ) ,  ( ( StrConcat_582_StrConcat ) ( ( ( StrConcat_583_StrConcat ) ( ( ( StrConcat_455_StrConcat ) ( ( ( StrConcat_456_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1454 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1452 ) .f_count ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
}

static  enum Unit_160   set668 (    struct Slice_270  slice1457 ,    size_t  i1459 ,    char  x1461 ) {
    char *  ep1462 = ( (  get_dash_ptr657 ) ( (  slice1457 ) ,  (  i1459 ) ) );
    (*  ep1462 ) = (  x1461 );
    return ( Unit_160_Unit );
}

static  enum Unit_160   set669 (    struct Slice_103  slice1457 ,    size_t  i1459 ,    struct Tile_104  x1461 ) {
    struct Tile_104 *  ep1462 = ( (  get_dash_ptr658 ) ( (  slice1457 ) ,  (  i1459 ) ) );
    (*  ep1462 ) = (  x1461 );
    return ( Unit_160_Unit );
}

static  enum Unit_160   set670 (    struct Slice_393  slice1457 ,    size_t  i1459 ,    struct Cell_16  x1461 ) {
    struct Cell_16 *  ep1462 = ( (  get_dash_ptr659 ) ( (  slice1457 ) ,  (  i1459 ) ) );
    (*  ep1462 ) = (  x1461 );
    return ( Unit_160_Unit );
}

struct Slice_672 {
    const char* *  f_ptr;
    size_t  f_count;
};

static  struct Slice_672   subslice671 (    struct Slice_672  slice1465 ,    size_t  from1467 ,    size_t  to1469 ) {
    const char* *  begin_dash_ptr1470 = ( (  offset_dash_ptr127 ) ( ( (  slice1465 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  from1467 ) ) ) ) );
    if ( ( (  cmp39 ( (  from1467 ) , (  to1469 ) ) != 0 ) || (  cmp39 ( (  from1467 ) , ( (  slice1465 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Slice_672) { .f_ptr = (  begin_dash_ptr1470 ) , .f_count = (  from_dash_integral8 ( 0 ) ) } );
    }
    size_t  count1471 = (  op_dash_sub59 ( ( (  min550 ) ( (  to1469 ) ,  ( (  slice1465 ) .f_count ) ) ) , (  from1467 ) ) );
    return ( (struct Slice_672) { .f_ptr = (  begin_dash_ptr1470 ) , .f_count = (  count1471 ) } );
}

static  struct Slice_270   subslice673 (    struct Slice_270  slice1465 ,    size_t  from1467 ,    size_t  to1469 ) {
    char *  begin_dash_ptr1470 = ( (  offset_dash_ptr129 ) ( ( (  slice1465 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  from1467 ) ) ) ) );
    if ( ( (  cmp39 ( (  from1467 ) , (  to1469 ) ) != 0 ) || (  cmp39 ( (  from1467 ) , ( (  slice1465 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Slice_270) { .f_ptr = (  begin_dash_ptr1470 ) , .f_count = (  from_dash_integral8 ( 0 ) ) } );
    }
    size_t  count1471 = (  op_dash_sub59 ( ( (  min550 ) ( (  to1469 ) ,  ( (  slice1465 ) .f_count ) ) ) , (  from1467 ) ) );
    return ( (struct Slice_270) { .f_ptr = (  begin_dash_ptr1470 ) , .f_count = (  count1471 ) } );
}

struct SliceAddressIter_675 {
    struct Slice_304  f_slice;
    size_t  f_current_dash_offset;
};

static  struct SliceAddressIter_675   addresses674 (    struct Slice_304  slice1523 ) {
    return ( (struct SliceAddressIter_675) { .f_slice = (  slice1523 ) , .f_current_dash_offset = (  from_dash_integral8 ( 0 ) ) } );
}

static  struct SliceAddressIter_675   into_dash_iter676 (    struct SliceAddressIter_675  self1526 ) {
    return (  self1526 );
}

struct Maybe_678 {
    enum {
        Maybe_678_None_t,
        Maybe_678_Just_t,
    } tag;
    union {
        struct {
            struct Slice_103 *  field0;
        } Maybe_678_Just_s;
    } stuff;
};

static struct Maybe_678 Maybe_678_Just (  struct Slice_103 *  field0 ) {
    return ( struct Maybe_678 ) { .tag = Maybe_678_Just_t, .stuff = { .Maybe_678_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_678   next677 (    struct SliceAddressIter_675 *  self1529 ) {
    size_t  off1530 = ( ( * (  self1529 ) ) .f_current_dash_offset );
    if ( (  cmp39 ( (  op_dash_add58 ( (  off1530 ) , (  from_dash_integral8 ( 1 ) ) ) ) , ( ( ( * (  self1529 ) ) .f_slice ) .f_count ) ) == 2 ) ) {
        return ( (struct Maybe_678) { .tag = Maybe_678_None_t } );
    }
    struct Slice_103 *  elem1531 = ( (  offset_dash_ptr131 ) ( ( ( ( * (  self1529 ) ) .f_slice ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  off1530 ) ) ) ) );
    (*  self1529 ) .f_current_dash_offset = (  op_dash_add58 ( (  off1530 ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_678_Just ) ( (  elem1531 ) ) );
}

static  struct Slice_103   elem_dash_get679 (    struct Slice_304  self1550 ,    size_t  idx1552 ) {
    return ( (  get665 ) ( (  self1550 ) ,  (  idx1552 ) ) );
}

static  struct Tile_104   elem_dash_get680 (    struct Slice_103  self1550 ,    size_t  idx1552 ) {
    return ( (  get666 ) ( (  self1550 ) ,  (  idx1552 ) ) );
}

static  struct Cell_16   elem_dash_get681 (    struct Slice_393  self1550 ,    size_t  idx1552 ) {
    return ( (  get667 ) ( (  self1550 ) ,  (  idx1552 ) ) );
}

static  char   elem_dash_get682 (    struct Slice_270  self1550 ,    size_t  idx1552 ) {
    return ( (  get664 ) ( (  self1550 ) ,  (  idx1552 ) ) );
}

struct ListSpread_684 {
    enum {
        ListSpread_684_NoSpread_t,
        ListSpread_684_UnassignedSpread_t,
        ListSpread_684_AssignedSpread_t,
    } tag;
    union {
        struct {
            struct Slice_672 *  field0;
        } ListSpread_684_AssignedSpread_s;
    } stuff;
};

static struct ListSpread_684 ListSpread_684_AssignedSpread (  struct Slice_672 *  field0 ) {
    return ( struct ListSpread_684 ) { .tag = ListSpread_684_AssignedSpread_t, .stuff = { .ListSpread_684_AssignedSpread_s = { .field0 = field0 } } };
};

static  bool   deconstruct683 (    struct Slice_672  self1561 ,    const char* * *  lp1563 ,    size_t  lc1565 ,    struct ListSpread_684  spread1567 ,    const char* * *  rp1569 ,    size_t  rc1571 ) {
    if ( (  cmp39 ( (  lc1565 ) , (  from_dash_integral8 ( 0 ) ) ) == 2 ) ) {
        if ( (  cmp39 ( (  lc1565 ) , ( (  self1561 ) .f_count ) ) == 2 ) ) {
            return ( false );
        }
        (*  lp1563 ) = ( (  self1561 ) .f_ptr );
    }
    if ( (  cmp39 ( (  rc1571 ) , (  from_dash_integral8 ( 0 ) ) ) == 2 ) ) {
        if ( (  cmp39 ( (  op_dash_add58 ( (  rc1571 ) , (  lc1565 ) ) ) , ( (  self1561 ) .f_count ) ) == 2 ) ) {
            return ( false );
        }
        struct Slice_672  cut1572 = ( (  subslice671 ) ( (  self1561 ) ,  (  op_dash_sub59 ( ( (  self1561 ) .f_count ) , (  rc1571 ) ) ) ,  ( (  self1561 ) .f_count ) ) );
        (*  rp1569 ) = ( (  cut1572 ) .f_ptr );
    }
    struct ListSpread_684  dref1573 = (  spread1567 );
    if ( dref1573.tag == ListSpread_684_NoSpread_t ) {
        return (  eq13 ( (  op_dash_add58 ( (  lc1565 ) , (  rc1571 ) ) ) , ( (  self1561 ) .f_count ) ) );
    }
    else {
        if ( dref1573.tag == ListSpread_684_UnassignedSpread_t ) {
            return ( true );
        }
        else {
            if ( dref1573.tag == ListSpread_684_AssignedSpread_t ) {
                (* dref1573 .stuff .ListSpread_684_AssignedSpread_s .field0 ) = ( (  subslice671 ) ( (  self1561 ) ,  (  lc1565 ) ,  (  op_dash_sub59 ( ( (  self1561 ) .f_count ) , (  rc1571 ) ) ) ) );
                return ( true );
            }
        }
    }
}

static  enum Unit_160   lam387 (   struct env387 env ,    int32_t  i1592 ) {
    struct funenv388  temp686 = ( env.fun1590 );
    return ( (  set669 ) ( ( env.s1588 ) ,  ( (  i32_dash_size256 ) ( (  i1592 ) ) ) ,  ( temp686.fun ( temp686.env ,  (  elem_dash_get680 ( ( env.s1588 ) , ( (  i32_dash_size256 ) ( (  i1592 ) ) ) ) ) ) ) ) );
}

static  enum Unit_160   map685 (    struct Slice_103  s1588 ,   struct funenv388  fun1590 ) {
    struct env387 envinst387 = {
        .s1588 =  s1588 ,
        .fun1590 =  fun1590 ,
    };
    ( (  for_dash_each386 ) ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_i32260 ) ( (  op_dash_sub59 ( ( (  s1588 ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) ) ) ) ) ,  ( (struct funenv387){ .fun = lam387, .env = envinst387 } ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   lam392 (   struct env392 env ,    int32_t  i1592 ) {
    return ( (  set670 ) ( ( env.s1588 ) ,  ( (  i32_dash_size256 ) ( (  i1592 ) ) ) ,  ( ( env.fun1590 ) ( (  elem_dash_get681 ( ( env.s1588 ) , ( (  i32_dash_size256 ) ( (  i1592 ) ) ) ) ) ) ) ) );
}

static  enum Unit_160   map687 (    struct Slice_393  s1588 ,    struct Cell_16 (*  fun1590 )(    struct Cell_16  ) ) {
    struct env392 envinst392 = {
        .s1588 =  s1588 ,
        .fun1590 =  fun1590 ,
    };
    ( (  for_dash_each391 ) ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_i32260 ) ( (  op_dash_sub59 ( ( (  s1588 ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) ) ) ) ) ,  ( (struct funenv392){ .fun = lam392, .env = envinst392 } ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   lam397 (   struct env397 env ,    int32_t  i1592 ) {
    return ( (  set670 ) ( ( env.s1588 ) ,  ( (  i32_dash_size256 ) ( (  i1592 ) ) ) ,  ( ( env.fun1590 ) ( (  elem_dash_get681 ( ( env.s1588 ) , ( (  i32_dash_size256 ) ( (  i1592 ) ) ) ) ) ) ) ) );
}

static  enum Unit_160   map688 (    struct Slice_393  s1588 ,    struct Cell_16 (*  fun1590 )(    struct Cell_16  ) ) {
    struct env397 envinst397 = {
        .s1588 =  s1588 ,
        .fun1590 =  fun1590 ,
    };
    ( (  for_dash_each396 ) ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_i32260 ) ( (  op_dash_sub59 ( ( (  s1588 ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) ) ) ) ) ,  ( (struct funenv397){ .fun = lam397, .env = envinst397 } ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   lam427 (   struct env427 env ,    int32_t  i1592 ) {
    return ( (  set670 ) ( ( env.s1588 ) ,  ( (  i32_dash_size256 ) ( (  i1592 ) ) ) ,  ( ( env.fun1590 ) ( (  elem_dash_get681 ( ( env.s1588 ) , ( (  i32_dash_size256 ) ( (  i1592 ) ) ) ) ) ) ) ) );
}

static  enum Unit_160   map689 (    struct Slice_393  s1588 ,    struct Cell_16 (*  fun1590 )(    struct Cell_16  ) ) {
    struct env427 envinst427 = {
        .s1588 =  s1588 ,
        .fun1590 =  fun1590 ,
    };
    ( (  for_dash_each426 ) ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_i32260 ) ( (  op_dash_sub59 ( ( (  s1588 ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) ) ) ) ) ,  ( (struct funenv427){ .fun = lam427, .env = envinst427 } ) ) );
    return ( Unit_160_Unit );
}

static  enum CAllocator_378   idc690 (  ) {
    return ( CAllocator_378_CAllocator );
}

static  struct Slice_270   allocate691 (    enum CAllocator_378  dref1619 ,    size_t  count1621 ) {
    if (!(  dref1619 == CAllocator_378_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    size_t  size1622 = ( ( ( (  get_dash_typesize143 ) ( ) ) ) .f_size );
    char *  ptr1623 = ( (  cast_dash_ptr185 ) ( ( ( malloc ) ( (  op_dash_mul60 ( (  size1622 ) , (  count1621 ) ) ) ) ) ) );
    return ( (struct Slice_270) { .f_ptr = (  ptr1623 ) , .f_count = (  count1621 ) } );
}

static  struct Slice_304   allocate692 (    enum CAllocator_378  dref1619 ,    size_t  count1621 ) {
    if (!(  dref1619 == CAllocator_378_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    size_t  size1622 = ( ( ( (  get_dash_typesize146 ) ( ) ) ) .f_size );
    struct Slice_103 *  ptr1623 = ( (  cast_dash_ptr191 ) ( ( ( malloc ) ( (  op_dash_mul60 ( (  size1622 ) , (  count1621 ) ) ) ) ) ) );
    return ( (struct Slice_304) { .f_ptr = (  ptr1623 ) , .f_count = (  count1621 ) } );
}

static  struct Slice_103   allocate693 (    enum CAllocator_378  dref1619 ,    size_t  count1621 ) {
    if (!(  dref1619 == CAllocator_378_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    size_t  size1622 = ( ( ( (  get_dash_typesize149 ) ( ) ) ) .f_size );
    struct Tile_104 *  ptr1623 = ( (  cast_dash_ptr192 ) ( ( ( malloc ) ( (  op_dash_mul60 ( (  size1622 ) , (  count1621 ) ) ) ) ) ) );
    return ( (struct Slice_103) { .f_ptr = (  ptr1623 ) , .f_count = (  count1621 ) } );
}

static  struct Slice_393   allocate694 (    enum CAllocator_378  dref1619 ,    size_t  count1621 ) {
    if (!(  dref1619 == CAllocator_378_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    size_t  size1622 = ( ( ( (  get_dash_typesize152 ) ( ) ) ) .f_size );
    struct Cell_16 *  ptr1623 = ( (  cast_dash_ptr200 ) ( ( ( malloc ) ( (  op_dash_mul60 ( (  size1622 ) , (  count1621 ) ) ) ) ) ) );
    return ( (struct Slice_393) { .f_ptr = (  ptr1623 ) , .f_count = (  count1621 ) } );
}

static  enum Unit_160   free695 (    enum CAllocator_378  dref1625 ,    struct Slice_270  slice1627 ) {
    if (!(  dref1625 == CAllocator_378_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    ( ( free ) ( ( (  cast_dash_ptr187 ) ( ( (  slice1627 ) .f_ptr ) ) ) ) );
    return ( Unit_160_Unit );
}

struct Slice_697 {
    enum Unit_160 *  f_ptr;
    size_t  f_count;
};

static  enum Unit_160   free696 (    enum CAllocator_378  dref1625 ,    struct Slice_697  slice1627 ) {
    if (!(  dref1625 == CAllocator_378_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    ( ( free ) ( ( (  cast_dash_ptr188 ) ( ( (  slice1627 ) .f_ptr ) ) ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   free698 (    enum CAllocator_378  dref1625 ,    struct Slice_393  slice1627 ) {
    if (!(  dref1625 == CAllocator_378_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    ( ( free ) ( ( (  cast_dash_ptr209 ) ( ( (  slice1627 ) .f_ptr ) ) ) ) );
    return ( Unit_160_Unit );
}

static  struct Tile_104   lam388 (   struct env388 env ,    struct Tile_104  dref1636 ) {
    return ( env.x1634 );
}

static  struct Slice_103   default699 (    enum CAllocator_378  al1630 ,    size_t  count1632 ,    struct Tile_104  x1634 ) {
    struct Slice_103  s1635 = ( (  allocate693 ) ( (  al1630 ) ,  (  count1632 ) ) );
    struct env388 envinst388 = {
        .x1634 =  x1634 ,
    };
    ( (  map685 ) ( (  s1635 ) ,  ( (struct funenv388){ .fun = lam388, .env = envinst388 } ) ) );
    return (  s1635 );
}

static  struct SliceIter_269   into_dash_iter700 (    struct List_377  self1711 ) {
    return ( (  into_dash_iter334 ) ( ( (  subslice673 ) ( ( (  self1711 ) .f_elements ) ,  (  from_dash_integral8 ( 0 ) ) ,  ( (  self1711 ) .f_count ) ) ) ) );
}

static  struct List_377   mk701 (    enum CAllocator_378  al1714 ) {
    struct Slice_270  elements1715 = ( (  empty656 ) ( ) );
    return ( (struct List_377) { .f_al = (  al1714 ) , .f_elements = (  elements1715 ) , .f_count = (  from_dash_integral8 ( 0 ) ) } );
}

static  enum Unit_160   free702 (    struct List_377 *  list1718 ) {
    ( (  free695 ) ( ( ( * (  list1718 ) ) .f_al ) ,  ( ( * (  list1718 ) ) .f_elements ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   lam367 (   struct env367 env ,    struct Tuple2_312  dref1726 ) {
    return ( (  set668 ) ( ( env.new_dash_slice1725 ) ,  ( (  i32_dash_size256 ) ( ( dref1726 .field1 ) ) ) ,  ( dref1726 .field0 ) ) );
}

static  enum Unit_160   grow_dash_if_dash_full376 (   struct env376 env ,    struct List_377 *  list1724 ) {
    if ( (  eq13 ( ( ( * (  list1724 ) ) .f_count ) , (  from_dash_integral8 ( 0 ) ) ) ) ) {
        (*  list1724 ) .f_elements = ( (  allocate691 ) ( ( ( * (  list1724 ) ) .f_al ) ,  ( env.starting_dash_size1719 ) ) );
    } else {
        if ( (  eq13 ( ( ( * (  list1724 ) ) .f_count ) , ( ( ( * (  list1724 ) ) .f_elements ) .f_count ) ) ) ) {
            struct Slice_270  new_dash_slice1725 = ( (  allocate691 ) ( ( ( * (  list1724 ) ) .f_al ) ,  (  op_dash_mul60 ( ( ( * (  list1724 ) ) .f_count ) , ( env.growth_dash_factor1720 ) ) ) ) );
            struct env367 envinst367 = {
                .new_dash_slice1725 =  new_dash_slice1725 ,
            };
            ( (  for_dash_each366 ) ( ( (  zip333 ) ( ( ( * (  list1724 ) ) .f_elements ) ,  ( (  from291 ) ( (  from_dash_integral3 ( 0 ) ) ) ) ) ) ,  ( (struct funenv367){ .fun = lam367, .env = envinst367 } ) ) );
            ( (  free695 ) ( ( ( * (  list1724 ) ) .f_al ) ,  ( ( * (  list1724 ) ) .f_elements ) ) );
            (*  list1724 ) .f_elements = (  new_dash_slice1725 );
        }
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   add375 (   struct env375 env ,    struct List_377 *  list1731 ,    char  elem1733 ) {
    struct funenv376  temp703 = ( (struct funenv376){ .fun = grow_dash_if_dash_full376, .env =  env.envinst376  } );
    ( temp703.fun ( temp703.env ,  (  list1731 ) ) );
    ( (  set668 ) ( ( ( * (  list1731 ) ) .f_elements ) ,  ( ( * (  list1731 ) ) .f_count ) ,  (  elem1733 ) ) );
    (*  list1731 ) .f_count = (  op_dash_add58 ( ( ( * (  list1731 ) ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( Unit_160_Unit );
}

static  struct SliceIter_269   chars704 (    struct DynStr_411  self1661 ) {
    return ( (  into_dash_iter334 ) ( ( (  self1661 ) .f_contents ) ) );
}

static  struct DynStr_411   substr705 (    struct DynStr_411  s1667 ,    size_t  from1669 ,    size_t  to1671 ) {
    return ( (struct DynStr_411) { .f_contents = ( (  subslice673 ) ( ( (  s1667 ) .f_contents ) ,  (  from1669 ) ,  (  to1671 ) ) ) } );
}

static  uint8_t *   get_dash_ptr706 (    struct Array_110 *  arr1831 ,    size_t  i1834 ) {
    if ( ( (  cmp39 ( (  i1834 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1834 ) , ( (size_t ) ( 32 ) ) ) != 0 ) ) ) {
        ( (  panic452 ) ( ( ( StrConcat_453_StrConcat ) ( ( ( StrConcat_454_StrConcat ) ( ( ( StrConcat_455_StrConcat ) ( ( ( StrConcat_456_StrConcat ) ( ( "Access to array at index " ) ,  (  i1834 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 32 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    uint8_t *  p1835 = ( ( (  cast_dash_ptr196 ) ( (  arr1831 ) ) ) );
    return ( (  offset_dash_ptr135 ) ( (  p1835 ) ,  ( (int64_t ) (  i1834 ) ) ) );
}

static  char *   get_dash_ptr707 (    struct Array_167 *  arr1831 ,    size_t  i1834 ) {
    if ( ( (  cmp39 ( (  i1834 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1834 ) , ( (size_t ) ( 32 ) ) ) != 0 ) ) ) {
        ( (  panic452 ) ( ( ( StrConcat_453_StrConcat ) ( ( ( StrConcat_454_StrConcat ) ( ( ( StrConcat_455_StrConcat ) ( ( ( StrConcat_456_StrConcat ) ( ( "Access to array at index " ) ,  (  i1834 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 32 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    char *  p1835 = ( ( (  cast_dash_ptr203 ) ( (  arr1831 ) ) ) );
    return ( (  offset_dash_ptr129 ) ( (  p1835 ) ,  ( (int64_t ) (  i1834 ) ) ) );
}

static  enum Unit_160   set708 (    struct Array_110 *  arr1844 ,    size_t  i1847 ,    uint8_t  e1849 ) {
    uint8_t *  p1850 = ( (  get_dash_ptr706 ) ( (  arr1844 ) ,  (  i1847 ) ) );
    (*  p1850 ) = (  e1849 );
    return ( Unit_160_Unit );
}

static  enum Unit_160   set709 (    struct Array_167 *  arr1844 ,    size_t  i1847 ,    char  e1849 ) {
    char *  p1850 = ( (  get_dash_ptr707 ) ( (  arr1844 ) ,  (  i1847 ) ) );
    (*  p1850 ) = (  e1849 );
    return ( Unit_160_Unit );
}

static  struct Slice_270   as_dash_slice710 (    struct Array_167 *  arr1853 ) {
    return ( (struct Slice_270) { .f_ptr = ( (  cast179 ) ( (  arr1853 ) ) ) , .f_count = ( (size_t ) ( 32 ) ) } );
}

static  char   newline711 (  ) {
    return ( (  from_dash_charlike1 ) ( ( "\n" ) ) );
}

struct LineIter_713 {
    struct DynStr_411  f_og;
    size_t  f_last;
};

static  struct LineIter_713   lines712 (    struct DynStr_411  s1933 ) {
    return ( (struct LineIter_713) { .f_og = (  s1933 ) , .f_last = (  from_dash_integral8 ( 0 ) ) } );
}

static  struct LineIter_713   into_dash_iter714 (    struct LineIter_713  self1936 ) {
    return (  self1936 );
}

static  struct Maybe_533   next715 (    struct LineIter_713 *  self1939 ) {
    if ( ( (  cmp39 ( ( ( * (  self1939 ) ) .f_last ) , ( ( ( ( * (  self1939 ) ) .f_og ) .f_contents ) .f_count ) ) != 0 ) || (  eq14 ( ( (  get664 ) ( ( ( ( * (  self1939 ) ) .f_og ) .f_contents ) ,  ( ( * (  self1939 ) ) .f_last ) ) ) , ( (  nullchar630 ) ( ) ) ) ) ) ) {
        return ( (struct Maybe_533) { .tag = Maybe_533_None_t } );
    }
    size_t  i1940 = ( ( * (  self1939 ) ) .f_last );
    while ( ( (  cmp39 ( (  i1940 ) , ( ( ( ( * (  self1939 ) ) .f_og ) .f_contents ) .f_count ) ) == 0 ) && ( !  eq14 ( ( (  get664 ) ( ( ( ( * (  self1939 ) ) .f_og ) .f_contents ) ,  (  i1940 ) ) ) , ( (  newline711 ) ( ) ) ) ) ) ) {
        i1940 = (  op_dash_add58 ( (  i1940 ) , (  from_dash_integral8 ( 1 ) ) ) );
    }
    struct DynStr_411  line1941 = ( (  substr705 ) ( ( ( * (  self1939 ) ) .f_og ) ,  ( ( * (  self1939 ) ) .f_last ) ,  (  i1940 ) ) );
    if ( (  cmp39 ( (  i1940 ) , ( ( ( ( * (  self1939 ) ) .f_og ) .f_contents ) .f_count ) ) == 0 ) ) {
        i1940 = (  op_dash_add58 ( (  i1940 ) , (  from_dash_integral8 ( 1 ) ) ) );
    }
    (*  self1939 ) .f_last = (  i1940 );
    return ( ( Maybe_533_Just ) ( (  line1941 ) ) );
}

static  bool   is_dash_digit716 (    char  c1962 ) {
    return ( (  cmp40 ( ( (  char_dash_i32631 ) ( (  c1962 ) ) ) , ( (  char_dash_i32631 ) ( ( (  from_dash_charlike1 ) ( ( "0" ) ) ) ) ) ) != 0 ) && (  cmp40 ( ( (  char_dash_i32631 ) ( (  c1962 ) ) ) , ( (  char_dash_i32631 ) ( ( (  from_dash_charlike1 ) ( ( "9" ) ) ) ) ) ) != 2 ) );
}

static  struct Maybe_290   parse_dash_digit717 (    char  c1965 ) {
    if ( ( (  is_dash_digit716 ) ( (  c1965 ) ) ) ) {
        return ( ( Maybe_290_Just ) ( (  op_dash_sub48 ( ( (  char_dash_i32631 ) ( (  c1965 ) ) ) , ( (  char_dash_i32631 ) ( ( (  from_dash_charlike1 ) ( ( "0" ) ) ) ) ) ) ) ) );
    } else {
        return ( (struct Maybe_290) { .tag = Maybe_290_None_t } );
    }
}

static  struct Maybe_442   sequence_dash_maybe719 (    char  e1971 ,    struct Maybe_442  b1973 ) {
    struct Maybe_442  dref1974 = (  b1973 );
    if ( dref1974.tag == Maybe_442_None_t ) {
        return ( (struct Maybe_442) { .tag = Maybe_442_None_t } );
    }
    else {
        if ( dref1974.tag == Maybe_442_Just_t ) {
            struct Maybe_290  dref1976 = ( (  parse_dash_digit717 ) ( (  e1971 ) ) );
            if ( dref1976.tag == Maybe_290_None_t ) {
                return ( (struct Maybe_442) { .tag = Maybe_442_None_t } );
            }
            else {
                if ( dref1976.tag == Maybe_290_Just_t ) {
                    return ( ( Maybe_442_Just ) ( (  op_dash_add43 ( (  op_dash_mul45 ( ( dref1974 .stuff .Maybe_442_Just_s .field0 ) , (  from_dash_integral2 ( 10 ) ) ) ) , ( (  i32_dash_i64255 ) ( ( dref1976 .stuff .Maybe_290_Just_s .field0 ) ) ) ) ) ) );
                }
            }
        }
    }
}

static  struct Maybe_442   parse_dash_int718 (    const char*  s1968 ) {
    struct ConstStrIter_279  cs1978 = ( (  chars552 ) ( (  s1968 ) ) );
    struct Maybe_276  dref1979 = ( (  head512 ) ( (  cs1978 ) ) );
    if ( dref1979.tag == Maybe_276_Just_t ) {
        return ( (  reduce441 ) ( (  cs1978 ) ,  ( ( Maybe_442_Just ) ( (  from_dash_integral2 ( 0 ) ) ) ) ,  (  sequence_dash_maybe719 ) ) );
    }
    else {
        if ( dref1979.tag == Maybe_276_None_t ) {
            return ( (struct Maybe_442) { .tag = Maybe_442_None_t } );
        }
    }
}

static  struct Maybe_442   sequence_dash_maybe721 (    char  e1971 ,    struct Maybe_442  b1973 ) {
    struct Maybe_442  dref1974 = (  b1973 );
    if ( dref1974.tag == Maybe_442_None_t ) {
        return ( (struct Maybe_442) { .tag = Maybe_442_None_t } );
    }
    else {
        if ( dref1974.tag == Maybe_442_Just_t ) {
            struct Maybe_290  dref1976 = ( (  parse_dash_digit717 ) ( (  e1971 ) ) );
            if ( dref1976.tag == Maybe_290_None_t ) {
                return ( (struct Maybe_442) { .tag = Maybe_442_None_t } );
            }
            else {
                if ( dref1976.tag == Maybe_290_Just_t ) {
                    return ( ( Maybe_442_Just ) ( (  op_dash_add43 ( (  op_dash_mul45 ( ( dref1974 .stuff .Maybe_442_Just_s .field0 ) , (  from_dash_integral2 ( 10 ) ) ) ) , ( (  i32_dash_i64255 ) ( ( dref1976 .stuff .Maybe_290_Just_s .field0 ) ) ) ) ) ) );
                }
            }
        }
    }
}

static  struct Maybe_442   parse_dash_int720 (    struct DynStr_411  s1968 ) {
    struct SliceIter_269  cs1978 = ( (  chars704 ) ( (  s1968 ) ) );
    struct Maybe_276  dref1979 = ( (  head514 ) ( (  cs1978 ) ) );
    if ( dref1979.tag == Maybe_276_Just_t ) {
        return ( (  reduce444 ) ( (  cs1978 ) ,  ( ( Maybe_442_Just ) ( (  from_dash_integral2 ( 0 ) ) ) ) ,  (  sequence_dash_maybe721 ) ) );
    }
    else {
        if ( dref1979.tag == Maybe_276_None_t ) {
            return ( (struct Maybe_442) { .tag = Maybe_442_None_t } );
        }
    }
}

static  struct Maybe_442   sequence_dash_maybe723 (    char  e1971 ,    struct Maybe_442  b1973 ) {
    struct Maybe_442  dref1974 = (  b1973 );
    if ( dref1974.tag == Maybe_442_None_t ) {
        return ( (struct Maybe_442) { .tag = Maybe_442_None_t } );
    }
    else {
        if ( dref1974.tag == Maybe_442_Just_t ) {
            struct Maybe_290  dref1976 = ( (  parse_dash_digit717 ) ( (  e1971 ) ) );
            if ( dref1976.tag == Maybe_290_None_t ) {
                return ( (struct Maybe_442) { .tag = Maybe_442_None_t } );
            }
            else {
                if ( dref1976.tag == Maybe_290_Just_t ) {
                    return ( ( Maybe_442_Just ) ( (  op_dash_add43 ( (  op_dash_mul45 ( ( dref1974 .stuff .Maybe_442_Just_s .field0 ) , (  from_dash_integral2 ( 10 ) ) ) ) , ( (  i32_dash_i64255 ) ( ( dref1976 .stuff .Maybe_290_Just_s .field0 ) ) ) ) ) ) );
                }
            }
        }
    }
}

static  struct Maybe_442   parse_dash_int722 (    struct TakeWhile_349  s1968 ) {
    struct TakeWhile_349  cs1978 = ( (  chars629 ) ( (  s1968 ) ) );
    struct Maybe_276  dref1979 = ( (  head516 ) ( (  cs1978 ) ) );
    if ( dref1979.tag == Maybe_276_Just_t ) {
        return ( (  reduce486 ) ( (  cs1978 ) ,  ( ( Maybe_442_Just ) ( (  from_dash_integral2 ( 0 ) ) ) ) ,  (  sequence_dash_maybe723 ) ) );
    }
    else {
        if ( dref1979.tag == Maybe_276_None_t ) {
            return ( (struct Maybe_442) { .tag = Maybe_442_None_t } );
        }
    }
}

static  int32_t   lam725 (    int32_t  elem2003 ,    int32_t  b2005 ) {
    return (  op_dash_add47 ( (  op_dash_mul49 ( (  b2005 ) , (  from_dash_integral3 ( 8 ) ) ) ) , (  elem2003 ) ) );
}

static  int32_t   from_dash_octal724 (    struct SmolArray_71  arr2001 ) {
    return ( (  reduce494 ) ( (  arr2001 ) ,  (  from_dash_integral3 ( 0 ) ) ,  (  lam725 ) ) );
}

static  struct Maybe_649   hex_dash_digit726 (    char  c2008 ) {
    if ( ( (  cmp635 ( (  c2008 ) , ( (  from_dash_charlike1 ) ( ( "0" ) ) ) ) != 0 ) && (  cmp635 ( (  c2008 ) , ( (  from_dash_charlike1 ) ( ( "9" ) ) ) ) != 2 ) ) ) {
        return ( ( Maybe_649_Just ) ( (  op_dash_sub57 ( ( (  char_dash_u8632 ) ( (  c2008 ) ) ) , ( (  char_dash_u8632 ) ( ( (  from_dash_charlike1 ) ( ( "0" ) ) ) ) ) ) ) ) );
    }
    if ( ( (  cmp635 ( (  c2008 ) , ( (  from_dash_charlike1 ) ( ( "a" ) ) ) ) != 0 ) && (  cmp635 ( (  c2008 ) , ( (  from_dash_charlike1 ) ( ( "f" ) ) ) ) != 2 ) ) ) {
        return ( ( Maybe_649_Just ) ( (  op_dash_add56 ( (  op_dash_sub57 ( ( (  char_dash_u8632 ) ( (  c2008 ) ) ) , ( (  char_dash_u8632 ) ( ( (  from_dash_charlike1 ) ( ( "a" ) ) ) ) ) ) ) , (  from_dash_integral6 ( 10 ) ) ) ) ) );
    }
    if ( ( (  cmp635 ( (  c2008 ) , ( (  from_dash_charlike1 ) ( ( "A" ) ) ) ) != 0 ) && (  cmp635 ( (  c2008 ) , ( (  from_dash_charlike1 ) ( ( "F" ) ) ) ) != 2 ) ) ) {
        return ( ( Maybe_649_Just ) ( (  op_dash_add56 ( (  op_dash_sub57 ( ( (  char_dash_u8632 ) ( (  c2008 ) ) ) , ( (  char_dash_u8632 ) ( ( (  from_dash_charlike1 ) ( ( "A" ) ) ) ) ) ) ) , (  from_dash_integral6 ( 10 ) ) ) ) ) );
    }
    return ( (struct Maybe_649) { .tag = Maybe_649_None_t } );
}

static  uint32_t   lam728 (    char  c2013 ) {
    return ( (  from_dash_integral4 ) ( ( (  u8_dash_i64265 ) ( ( (  or_dash_fail648 ) ( ( (  hex_dash_digit726 ) ( (  c2013 ) ) ) ,  ( ( StrConcat_590_StrConcat ) ( ( ( StrConcat_591_StrConcat ) ( ( (  from_dash_charlike1 ) ( ( "\"" ) ) ) ,  (  c2013 ) ) ) ,  ( "\" is not a hex digit." ) ) ) ) ) ) ) ) );
}

static  uint32_t   lam729 (    uint32_t  elem2015 ,    uint32_t  b2017 ) {
    return (  op_dash_add52 ( (  op_dash_mul54 ( (  b2017 ) , (  from_dash_integral4 ( 16 ) ) ) ) , (  elem2015 ) ) );
}

static  uint32_t   from_dash_hex727 (    const char*  arr2011 ) {
    return ( (  reduce484 ) ( ( (  map283 ) ( (  arr2011 ) ,  (  lam728 ) ) ) ,  (  from_dash_integral4 ( 0 ) ) ,  (  lam729 ) ) );
}

static  struct Maybe_252   get730 (    const char*  s2054 ) {
    return ( (  from_dash_nullable_dash_c_dash_str251 ) ( ( ( getenv ) ( (  s2054 ) ) ) ) );
}

static  enum Unit_160   show_dash_cursor731 (  ) {
    ( (  print_dash_str461 ) ( ( "\x1b[?25h" ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   hide_dash_cursor732 (  ) {
    ( (  print_dash_str461 ) ( ( "\x1b[?25l" ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   move_dash_cursor_dash_to733 (    uint32_t  x2031 ,    uint32_t  y2033 ) {
    uint32_t  x2034 = (  op_dash_add52 ( (  x2031 ) , (  from_dash_integral4 ( 1 ) ) ) );
    uint32_t  y2035 = (  op_dash_add52 ( (  y2033 ) , (  from_dash_integral4 ( 1 ) ) ) );
    ( (  print_dash_str607 ) ( ( ( StrConcat_608_StrConcat ) ( ( ( StrConcat_609_StrConcat ) ( ( ( StrConcat_610_StrConcat ) ( ( ( StrConcat_577_StrConcat ) ( ( "\x1b[" ) ,  (  y2035 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ";" ) ) ) ) ) ,  (  x2034 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "H" ) ) ) ) ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   reset_dash_cursor_dash_position734 (  ) {
    ( (  print_dash_str461 ) ( ( "\x1b[H" ) ) );
    return ( Unit_160_Unit );
}

static  struct Tuple2_529   get_dash_dimensions735 (  ) {
    struct Winsize_163  temp736 = ( ( (  zeroed222 ) ( ) ) );
    struct Winsize_163 *  ws2039 = ( &temp736 );
    if ( ( (  eq9 ( ( ( ioctl ) ( ( (  stdout_dash_fileno78 ) ( ) ) ,  ( (  tiocgwinsz94 ) ( ) ) ,  (  ws2039 ) ) ) , (  op_dash_neg51 ( (  from_dash_integral3 ( 1 ) ) ) ) ) ) || (  eq12 ( ( ( * (  ws2039 ) ) .f_ws_dash_col ) , (  from_dash_integral5 ( 0 ) ) ) ) ) ) {
        return ( ( Tuple2_529_Tuple2 ) ( (  from_dash_integral4 ( 80 ) ) ,  (  from_dash_integral4 ( 24 ) ) ) );
    }
    return ( ( Tuple2_529_Tuple2 ) ( ( (  u16_dash_u32262 ) ( ( ( * (  ws2039 ) ) .f_ws_dash_col ) ) ) ,  ( (  u16_dash_u32262 ) ( ( ( * (  ws2039 ) ) .f_ws_dash_row ) ) ) ) );
}

static  enum Unit_160   set_dash_default_dash_fg737 (  ) {
    ( (  print_dash_str461 ) ( ( "\x1b[39m" ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   set_dash_default_dash_bg738 (  ) {
    ( (  print_dash_str461 ) ( ( "\x1b[49m" ) ) );
    return ( Unit_160_Unit );
}

static  enum ColorPalette_434   query_dash_palette739 (  ) {
    struct Maybe_252  colorterm2055 = ( (  get730 ) ( ( "COLORTERM" ) ) );
    struct Maybe_252  dref2056 = (  colorterm2055 );
    if ( dref2056.tag == Maybe_252_Just_t ) {
        if ( ( (  eq634 ( ( dref2056 .stuff .Maybe_252_Just_s .field0 ) , ( "truecolor" ) ) ) || (  eq634 ( ( dref2056 .stuff .Maybe_252_Just_s .field0 ) , ( "24bit" ) ) ) ) ) {
            return ( ColorPalette_434_PaletteRGB );
        }
    }
    else {
        if ( dref2056.tag == Maybe_252_None_t ) {
        }
    }
    struct Maybe_252  dref2058 = ( (  get730 ) ( ( "TERM" ) ) );
    if ( dref2058.tag == Maybe_252_Just_t ) {
        if ( (  eq634 ( ( dref2058 .stuff .Maybe_252_Just_s .field0 ) , ( "linux" ) ) ) ) {
            return ( ColorPalette_434_Palette8 );
        }
    }
    else {
        if ( dref2058.tag == Maybe_252_None_t ) {
        }
    }
    return ( ColorPalette_434_Palette16 );
}

static  enum Unit_160   set_dash_fg8740 (    enum Color8_18  color2074 ) {
    enum Color8_18  dref2075 = (  color2074 );
    switch (  dref2075 ) {
        case Color8_18_Black8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[30m" ) ) );
            break;
        }
        case Color8_18_Red8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[31m" ) ) );
            break;
        }
        case Color8_18_Green8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[32m" ) ) );
            break;
        }
        case Color8_18_Yellow8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[33m" ) ) );
            break;
        }
        case Color8_18_Blue8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[34m" ) ) );
            break;
        }
        case Color8_18_Magenta8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[35m" ) ) );
            break;
        }
        case Color8_18_Cyan8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[36m" ) ) );
            break;
        }
        case Color8_18_White8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[37m" ) ) );
            break;
        }
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   set_dash_fg16741 (    enum Color16_19  color2078 ) {
    enum Color16_19  dref2079 = (  color2078 );
    switch (  dref2079 ) {
        case Color16_19_Black16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[30m" ) ) );
            break;
        }
        case Color16_19_Red16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[31m" ) ) );
            break;
        }
        case Color16_19_Green16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[32m" ) ) );
            break;
        }
        case Color16_19_Yellow16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[33m" ) ) );
            break;
        }
        case Color16_19_Blue16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[34m" ) ) );
            break;
        }
        case Color16_19_Magenta16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[35m" ) ) );
            break;
        }
        case Color16_19_Cyan16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[36m" ) ) );
            break;
        }
        case Color16_19_White16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[37m" ) ) );
            break;
        }
        case Color16_19_BrightBlack16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[90m" ) ) );
            break;
        }
        case Color16_19_BrightRed16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[91m" ) ) );
            break;
        }
        case Color16_19_BrightGreen16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[92m" ) ) );
            break;
        }
        case Color16_19_BrightYellow16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[93m" ) ) );
            break;
        }
        case Color16_19_BrightBlue16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[94m" ) ) );
            break;
        }
        case Color16_19_BrightMagenta16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[95m" ) ) );
            break;
        }
        case Color16_19_BrightCyan16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[96m" ) ) );
            break;
        }
        case Color16_19_BrightWhite16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[97m" ) ) );
            break;
        }
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   set_dash_bg8742 (    enum Color8_18  color2082 ) {
    enum Color8_18  dref2083 = (  color2082 );
    switch (  dref2083 ) {
        case Color8_18_Black8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[40m" ) ) );
            break;
        }
        case Color8_18_Red8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[41m" ) ) );
            break;
        }
        case Color8_18_Green8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[42m" ) ) );
            break;
        }
        case Color8_18_Yellow8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[43m" ) ) );
            break;
        }
        case Color8_18_Blue8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[44m" ) ) );
            break;
        }
        case Color8_18_Magenta8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[45m" ) ) );
            break;
        }
        case Color8_18_Cyan8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[46m" ) ) );
            break;
        }
        case Color8_18_White8 : {
            ( (  print_dash_str461 ) ( ( "\x1b[47m" ) ) );
            break;
        }
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   set_dash_bg16743 (    enum Color16_19  color2086 ) {
    enum Color16_19  dref2087 = (  color2086 );
    switch (  dref2087 ) {
        case Color16_19_Black16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[40m" ) ) );
            break;
        }
        case Color16_19_Red16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[41m" ) ) );
            break;
        }
        case Color16_19_Green16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[42m" ) ) );
            break;
        }
        case Color16_19_Yellow16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[43m" ) ) );
            break;
        }
        case Color16_19_Blue16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[44m" ) ) );
            break;
        }
        case Color16_19_Magenta16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[45m" ) ) );
            break;
        }
        case Color16_19_Cyan16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[46m" ) ) );
            break;
        }
        case Color16_19_White16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[47m" ) ) );
            break;
        }
        case Color16_19_BrightBlack16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[100m" ) ) );
            break;
        }
        case Color16_19_BrightRed16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[101m" ) ) );
            break;
        }
        case Color16_19_BrightGreen16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[102m" ) ) );
            break;
        }
        case Color16_19_BrightYellow16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[103m" ) ) );
            break;
        }
        case Color16_19_BrightBlue16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[104m" ) ) );
            break;
        }
        case Color16_19_BrightMagenta16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[105m" ) ) );
            break;
        }
        case Color16_19_BrightCyan16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[106m" ) ) );
            break;
        }
        case Color16_19_BrightWhite16 : {
            ( (  print_dash_str461 ) ( ( "\x1b[107m" ) ) );
            break;
        }
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   reset_dash_colors744 (  ) {
    ( (  print_dash_str461 ) ( ( "\x1b[0m" ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   clear_dash_screen745 (  ) {
    ( (  print_dash_str461 ) ( ( "\x1b[2J" ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   set_dash_fg256746 (    uint8_t  color2092 ) {
    ( (  print_dash_str624 ) ( ( ( StrConcat_619_StrConcat ) ( ( ( StrConcat_620_StrConcat ) ( ( "\x1b[38;5;" ) ,  (  color2092 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "m" ) ) ) ) ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   set_dash_bg256747 (    uint8_t  color2095 ) {
    ( (  print_dash_str624 ) ( ( ( StrConcat_619_StrConcat ) ( ( ( StrConcat_620_StrConcat ) ( ( "\x1b[48;5;" ) ,  (  color2095 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "m" ) ) ) ) ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   set_dash_fg_dash_rgb748 (    struct RGB_20  c2115 ) {
    ( (  print_dash_str614 ) ( ( ( StrConcat_615_StrConcat ) ( ( ( StrConcat_616_StrConcat ) ( ( ( StrConcat_617_StrConcat ) ( ( ( StrConcat_618_StrConcat ) ( ( ( StrConcat_619_StrConcat ) ( ( ( StrConcat_620_StrConcat ) ( ( "\x1b[38;2;" ) ,  ( (  c2115 ) .f_r ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ";" ) ) ) ) ) ,  ( (  c2115 ) .f_g ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ";" ) ) ) ) ) ,  ( (  c2115 ) .f_b ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "m" ) ) ) ) ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   set_dash_bg_dash_rgb749 (    struct RGB_20  c2118 ) {
    ( (  print_dash_str614 ) ( ( ( StrConcat_615_StrConcat ) ( ( ( StrConcat_616_StrConcat ) ( ( ( StrConcat_617_StrConcat ) ( ( ( StrConcat_618_StrConcat ) ( ( ( StrConcat_619_StrConcat ) ( ( ( StrConcat_620_StrConcat ) ( ( "\x1b[48;2;" ) ,  ( (  c2118 ) .f_r ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ";" ) ) ) ) ) ,  ( (  c2118 ) .f_g ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ";" ) ) ) ) ) ,  ( (  c2118 ) .f_b ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "m" ) ) ) ) ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   set_dash_fg750 (    struct Color_17  c2136 ) {
    struct Color_17  dref2137 = (  c2136 );
    if ( dref2137.tag == Color_17_ColorDefault_t ) {
        ( (  set_dash_default_dash_fg737 ) ( ) );
    }
    else {
        if ( dref2137.tag == Color_17_Color8_t ) {
            ( (  set_dash_fg8740 ) ( ( dref2137 .stuff .Color_17_Color8_s .field0 ) ) );
        }
        else {
            if ( dref2137.tag == Color_17_Color16_t ) {
                ( (  set_dash_fg16741 ) ( ( dref2137 .stuff .Color_17_Color16_s .field0 ) ) );
            }
            else {
                if ( dref2137.tag == Color_17_Color256_t ) {
                    ( (  set_dash_fg256746 ) ( ( dref2137 .stuff .Color_17_Color256_s .field0 ) ) );
                }
                else {
                    if ( dref2137.tag == Color_17_ColorRGB_t ) {
                        ( (  set_dash_fg_dash_rgb748 ) ( ( dref2137 .stuff .Color_17_ColorRGB_s .field0 ) ) );
                    }
                }
            }
        }
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   set_dash_bg751 (    struct Color_17  c2144 ) {
    struct Color_17  dref2145 = (  c2144 );
    if ( dref2145.tag == Color_17_ColorDefault_t ) {
        ( (  set_dash_default_dash_bg738 ) ( ) );
    }
    else {
        if ( dref2145.tag == Color_17_Color8_t ) {
            ( (  set_dash_bg8742 ) ( ( dref2145 .stuff .Color_17_Color8_s .field0 ) ) );
        }
        else {
            if ( dref2145.tag == Color_17_Color16_t ) {
                ( (  set_dash_bg16743 ) ( ( dref2145 .stuff .Color_17_Color16_s .field0 ) ) );
            }
            else {
                if ( dref2145.tag == Color_17_Color256_t ) {
                    ( (  set_dash_bg256747 ) ( ( dref2145 .stuff .Color_17_Color256_s .field0 ) ) );
                }
                else {
                    if ( dref2145.tag == Color_17_ColorRGB_t ) {
                        ( (  set_dash_bg_dash_rgb749 ) ( ( dref2145 .stuff .Color_17_ColorRGB_s .field0 ) ) );
                    }
                }
            }
        }
    }
    return ( Unit_160_Unit );
}

struct env752 {
    ;
    struct env375 envinst375;
    ;
    ;
    ;
    ;
    ;
};

static  enum Unit_160   lam374 (   struct env374 env ,    char  c2201 ) {
    struct funenv375  temp753 = ( (struct funenv375){ .fun = add375, .env =  env.envinst375  } );
    return ( temp753.fun ( temp753.env ,  ( & ( ( * ( env.builder2197 ) ) .f_chars ) ) ,  (  c2201 ) ) );
}

static  enum Unit_160   write752 (   struct env752 env ,    struct StrBuilder_379 *  builder2197 ,    struct StrConcat_564  s2199 ) {
    struct env374 envinst374 = {
        .envinst375 = env.envinst375 ,
        .builder2197 =  builder2197 ,
    };
    ( (  for_dash_each370 ) ( ( (  chars575 ) ( (  s2199 ) ) ) ,  ( (struct funenv374){ .fun = lam374, .env = envinst374 } ) ) );
    return ( Unit_160_Unit );
}

static  struct SliceIter_269   chars754 (    struct StrBuilder_379  s2245 ) {
    return ( (  into_dash_iter700 ) ( ( (  s2245 ) .f_chars ) ) );
}

static  enum Unit_160   lam415 (   struct env415 env ,    char  c2201 ) {
    struct funenv375  temp755 = ( (struct funenv375){ .fun = add375, .env =  env.envinst375  } );
    return ( temp755.fun ( temp755.env ,  ( & ( ( * ( env.builder2197 ) ) .f_chars ) ) ,  (  c2201 ) ) );
}

static  enum Unit_160   write410 (   struct env410 env ,    struct StrBuilder_379 *  builder2197 ,    struct StrBuilder_379  s2199 ) {
    struct env415 envinst415 = {
        .envinst375 = env.envinst375 ,
        .builder2197 =  builder2197 ,
    };
    ( (  for_dash_each414 ) ( ( (  chars754 ) ( (  s2199 ) ) ) ,  ( (struct funenv415){ .fun = lam415, .env = envinst415 } ) ) );
    return ( Unit_160_Unit );
}

struct env756 {
    ;
    struct env375 envinst375;
    ;
    ;
    ;
    ;
    ;
};

static  enum Unit_160   lam421 (   struct env421 env ,    char  c2201 ) {
    struct funenv375  temp757 = ( (struct funenv375){ .fun = add375, .env =  env.envinst375  } );
    return ( temp757.fun ( temp757.env ,  ( & ( ( * ( env.builder2197 ) ) .f_chars ) ) ,  (  c2201 ) ) );
}

static  enum Unit_160   write756 (   struct env756 env ,    struct StrBuilder_379 *  builder2197 ,    struct StrConcat_574  s2199 ) {
    struct env421 envinst421 = {
        .envinst375 = env.envinst375 ,
        .builder2197 =  builder2197 ,
    };
    ( (  for_dash_each419 ) ( ( (  chars627 ) ( (  s2199 ) ) ) ,  ( (struct funenv421){ .fun = lam421, .env = envinst421 } ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   write_dash_char406 (   struct env406 env ,    struct StrBuilder_379 *  builder2209 ,    char  c2211 ) {
    struct funenv375  temp758 = ( (struct funenv375){ .fun = add375, .env =  env.envinst375  } );
    ( temp758.fun ( temp758.env ,  ( & ( ( * (  builder2209 ) ) .f_chars ) ) ,  (  c2211 ) ) );
    return ( Unit_160_Unit );
}

static  size_t   count759 (    struct StrBuilder_379 *  sb2222 ) {
    return ( ( ( * (  sb2222 ) ) .f_chars ) .f_count );
}

static  struct StrBuilder_379   mk760 (    enum CAllocator_378  al2225 ) {
    return ( (struct StrBuilder_379) { .f_chars = ( (  mk701 ) ( (  al2225 ) ) ) } );
}

static  struct DynStr_411   as_dash_str761 (    struct StrBuilder_379 *  builder2231 ) {
    return ( (struct DynStr_411) { .f_contents = ( (  subslice673 ) ( ( ( ( * (  builder2231 ) ) .f_chars ) .f_elements ) ,  (  from_dash_integral8 ( 0 ) ) ,  ( ( ( * (  builder2231 ) ) .f_chars ) .f_count ) ) ) } );
}

static  enum Unit_160   free762 (    struct StrBuilder_379 *  builder2237 ) {
    ( (  free702 ) ( ( & ( ( * (  builder2237 ) ) .f_chars ) ) ) );
    return ( Unit_160_Unit );
}

struct funenv752 {
    enum Unit_160  (*fun) (  struct env752  ,    struct StrBuilder_379 *  ,    struct StrConcat_564  );
    struct env752 env;
};

struct env763 {
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    struct env752 envinst752;
    ;
    ;
    struct env406 envinst406;
    ;
};

static  struct DynStr_411   mk_dash_dyn_dash_str763 (   struct env763 env ,    struct StrConcat_564  s2251 ,    enum CAllocator_378  al2253 ) {
    struct StrBuilder_379  temp764 = ( (  mk760 ) ( (  al2253 ) ) );
    struct StrBuilder_379 *  sb2254 = ( &temp764 );
    struct funenv752  temp765 = ( (struct funenv752){ .fun = write752, .env =  env.envinst752  } );
    ( temp765.fun ( temp765.env ,  (  sb2254 ) ,  (  s2251 ) ) );
    struct funenv406  temp766 = ( (struct funenv406){ .fun = write_dash_char406, .env =  env.envinst406  } );
    ( temp766.fun ( temp766.env ,  (  sb2254 ) ,  ( (  nullchar630 ) ( ) ) ) );
    struct DynStr_411  dynstr2255 = ( (  as_dash_str761 ) ( (  sb2254 ) ) );
    return ( (struct DynStr_411) { .f_contents = ( (struct Slice_270) { .f_ptr = ( ( (  dynstr2255 ) .f_contents ) .f_ptr ) , .f_count = (  op_dash_sub59 ( ( ( (  dynstr2255 ) .f_contents ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) } ) } );
}

static  struct DynStr_411   mk_dash_dyn_dash_str409 (   struct env409 env ,    struct StrBuilder_379  s2251 ,    enum CAllocator_378  al2253 ) {
    struct StrBuilder_379  temp767 = ( (  mk760 ) ( (  al2253 ) ) );
    struct StrBuilder_379 *  sb2254 = ( &temp767 );
    struct funenv410  temp768 = ( (struct funenv410){ .fun = write410, .env =  env.envinst410  } );
    ( temp768.fun ( temp768.env ,  (  sb2254 ) ,  (  s2251 ) ) );
    struct funenv406  temp769 = ( (struct funenv406){ .fun = write_dash_char406, .env =  env.envinst406  } );
    ( temp769.fun ( temp769.env ,  (  sb2254 ) ,  ( (  nullchar630 ) ( ) ) ) );
    struct DynStr_411  dynstr2255 = ( (  as_dash_str761 ) ( (  sb2254 ) ) );
    return ( (struct DynStr_411) { .f_contents = ( (struct Slice_270) { .f_ptr = ( ( (  dynstr2255 ) .f_contents ) .f_ptr ) , .f_count = (  op_dash_sub59 ( ( ( (  dynstr2255 ) .f_contents ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) } ) } );
}

struct funenv756 {
    enum Unit_160  (*fun) (  struct env756  ,    struct StrBuilder_379 *  ,    struct StrConcat_574  );
    struct env756 env;
};

struct env770 {
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    struct env756 envinst756;
    ;
    ;
    struct env406 envinst406;
    ;
};

static  struct DynStr_411   mk_dash_dyn_dash_str770 (   struct env770 env ,    struct StrConcat_574  s2251 ,    enum CAllocator_378  al2253 ) {
    struct StrBuilder_379  temp771 = ( (  mk760 ) ( (  al2253 ) ) );
    struct StrBuilder_379 *  sb2254 = ( &temp771 );
    struct funenv756  temp772 = ( (struct funenv756){ .fun = write756, .env =  env.envinst756  } );
    ( temp772.fun ( temp772.env ,  (  sb2254 ) ,  (  s2251 ) ) );
    struct funenv406  temp773 = ( (struct funenv406){ .fun = write_dash_char406, .env =  env.envinst406  } );
    ( temp773.fun ( temp773.env ,  (  sb2254 ) ,  ( (  nullchar630 ) ( ) ) ) );
    struct DynStr_411  dynstr2255 = ( (  as_dash_str761 ) ( (  sb2254 ) ) );
    return ( (struct DynStr_411) { .f_contents = ( (struct Slice_270) { .f_ptr = ( ( (  dynstr2255 ) .f_contents ) .f_ptr ) , .f_count = (  op_dash_sub59 ( ( ( (  dynstr2255 ) .f_contents ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) } ) } );
}

struct funenv763 {
    struct DynStr_411  (*fun) (  struct env763  ,    struct StrConcat_564  ,    enum CAllocator_378  );
    struct env763 env;
};

struct env774 {
    ;
    ;
    ;
    ;
    ;
    struct env763 envinst763;
    ;
};

static  const char*   mk_dash_const_dash_str774 (   struct env774 env ,    struct StrConcat_564  s2258 ,    enum CAllocator_378  al2260 ) {
    struct funenv763  temp775 = ( (struct funenv763){ .fun = mk_dash_dyn_dash_str763, .env =  env.envinst763  } );
    return ( ( (  cast172 ) ( ( ( ( temp775.fun ( temp775.env ,  (  s2258 ) ,  (  al2260 ) ) ) .f_contents ) .f_ptr ) ) ) );
}

static  const char*   mk_dash_const_dash_str408 (   struct env408 env ,    struct StrBuilder_379  s2258 ,    enum CAllocator_378  al2260 ) {
    struct funenv409  temp776 = ( (struct funenv409){ .fun = mk_dash_dyn_dash_str409, .env =  env.envinst409  } );
    return ( ( (  cast172 ) ( ( ( ( temp776.fun ( temp776.env ,  (  s2258 ) ,  (  al2260 ) ) ) .f_contents ) .f_ptr ) ) ) );
}

struct funenv770 {
    struct DynStr_411  (*fun) (  struct env770  ,    struct StrConcat_574  ,    enum CAllocator_378  );
    struct env770 env;
};

struct env777 {
    ;
    ;
    ;
    ;
    ;
    struct env770 envinst770;
    ;
};

static  const char*   mk_dash_const_dash_str777 (   struct env777 env ,    struct StrConcat_574  s2258 ,    enum CAllocator_378  al2260 ) {
    struct funenv770  temp778 = ( (struct funenv770){ .fun = mk_dash_dyn_dash_str770, .env =  env.envinst770  } );
    return ( ( (  cast172 ) ( ( ( ( temp778.fun ( temp778.env ,  (  s2258 ) ,  (  al2260 ) ) ) .f_contents ) .f_ptr ) ) ) );
}

static  enum Unit_160   free_dash_const_dash_str779 (    const char*  s2263 ,    enum CAllocator_378  al2265 ) {
    ( (  free696 ) ( (  al2265 ) ,  ( (struct Slice_697) { .f_ptr = ( (enum Unit_160 * ) (  s2263 ) ) , .f_count = (  from_dash_integral8 ( 0 ) ) } ) ) );
    return ( Unit_160_Unit );
}

static  uint32_t   u32_dash_or780 (    uint32_t  l2268 ,    uint32_t  r2270 ) {
    return ( (  l2268 ) | (  r2270 ) );
}

static  uint32_t   u32_dash_ors781 (    struct SmolArray_68  vals2273 ) {
    return ( (  reduce446 ) ( (  vals2273 ) ,  (  from_dash_integral4 ( 0 ) ) ,  (  u32_dash_or780 ) ) );
}

static  uint32_t   u32_dash_ors782 (    struct SmolArray_65  vals2273 ) {
    return ( (  reduce470 ) ( (  vals2273 ) ,  (  from_dash_integral4 ( 0 ) ) ,  (  u32_dash_or780 ) ) );
}

static  uint32_t   u32_dash_ors783 (    struct SmolArray_62  vals2273 ) {
    return ( (  reduce477 ) ( (  vals2273 ) ,  (  from_dash_integral4 ( 0 ) ) ,  (  u32_dash_or780 ) ) );
}

static  uint32_t   u32_dash_and784 (    uint32_t  l2276 ,    uint32_t  r2278 ) {
    return ( (  l2276 ) & (  r2278 ) );
}

static  uint32_t   u32_dash_neg785 (    uint32_t  l2281 ) {
    return ( ~ (  l2281 ) );
}

static  struct Maybe_533   try_dash_read_dash_contents786 (    const char*  filename2371 ,    enum CAllocator_378  al2373 ) {
    FILE *  file2374 = ( ( fopen ) ( (  filename2371 ) ,  ( (  from_dash_charlike0 ) ( ( "r" ) ) ) ) );
    if ( ( (  is_dash_ptr_dash_null249 ) ( (  file2374 ) ) ) ) {
        return ( (struct Maybe_533) { .tag = Maybe_533_None_t } );
    }
    ( ( fseek ) ( (  file2374 ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  seek_dash_end77 ) ( ) ) ) );
    int32_t  file_dash_size2375 = ( ( ftell ) ( (  file2374 ) ) );
    ( ( fseek ) ( (  file2374 ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  seek_dash_set76 ) ( ) ) ) );
    struct Slice_270  file_dash_buf2376 = ( ( (  allocate691 ) ( (  al2373 ) ,  (  op_dash_add58 ( ( (  i32_dash_size256 ) ( (  file_dash_size2375 ) ) ) , (  from_dash_integral8 ( 1 ) ) ) ) ) ) );
    ( ( fread ) ( ( (  file_dash_buf2376 ) .f_ptr ) ,  (  from_dash_integral3 ( 1 ) ) ,  (  file_dash_size2375 ) ,  (  file2374 ) ) );
    ( (  set668 ) ( (  file_dash_buf2376 ) ,  ( (  i32_dash_size256 ) ( (  file_dash_size2375 ) ) ) ,  ( (  nullchar630 ) ( ) ) ) );
    ( ( fclose ) ( (  file2374 ) ) );
    struct DynStr_411  str2377 = ( (struct DynStr_411) { .f_contents = (  file_dash_buf2376 ) } );
    return ( ( Maybe_533_Just ) ( (  str2377 ) ) );
}

static  bool   try_dash_write_dash_contents787 (    const char*  filename2385 ,    struct StrConcat_572  contents2387 ) {
    FILE *  file2388 = ( ( fopen ) ( (  filename2385 ) ,  ( (  from_dash_charlike0 ) ( ( "w" ) ) ) ) );
    if ( ( (  is_dash_ptr_dash_null249 ) ( (  file2388 ) ) ) ) {
        return ( false );
    }
    struct StrConcatIter_562  it2389 = ( (  chars626 ) ( (  contents2387 ) ) );
    while ( ( true ) ) {
        struct Maybe_276  dref2390 = ( (  next561 ) ( ( & (  it2389 ) ) ) );
        if ( dref2390.tag == Maybe_276_None_t ) {
            ( ( fclose ) ( (  file2388 ) ) );
            return ( true );
        }
        else {
            if ( dref2390.tag == Maybe_276_Just_t ) {
                int32_t  chars_dash_written2392 = ( ( fprintf ) ( (  file2388 ) ,  ( "%c" ) ,  ( dref2390 .stuff .Maybe_276_Just_s .field0 ) ) );
                if ( (  cmp40 ( (  chars_dash_written2392 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) ) {
                    return ( false );
                }
            }
        }
    }
    return ( (  unreachable636 ) ( ) );
}

static  enum Unit_160   write_dash_contents788 (    const char*  filename2395 ,    struct StrConcat_572  contents2397 ) {
    if ( ( ! ( (  try_dash_write_dash_contents787 ) ( (  filename2395 ) ,  (  contents2397 ) ) ) ) ) {
        ( (  panic640 ) ( ( ( StrConcat_566_StrConcat ) ( ( "could not write to file " ) ,  (  filename2395 ) ) ) ) );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   mkdir407 (   struct env407 env ,    struct StrBuilder_379  path2347 ,    enum CAllocator_378  al2349 ) {
    struct funenv408  temp789 = ( (struct funenv408){ .fun = mk_dash_const_dash_str408, .env =  env.envinst408  } );
    const char*  path2350 = ( temp789.fun ( temp789.env ,  (  path2347 ) ,  (  al2349 ) ) );
    if ( ( !  eq9 ( ( ( mkdir ) ( (  path2350 ) ,  ( (  from_dash_octal724 ) ( ( (  from_dash_listlike70 ) ( ( (struct Array_72) { ._arr = { (  from_dash_integral3 ( 7 ) ) , (  from_dash_integral3 ( 7 ) ) , (  from_dash_integral3 ( 7 ) ) } } ) ) ) ) ) ) ) , (  from_dash_integral3 ( 0 ) ) ) ) ) {
        if ( ( ! ( (  errno_dash_EEXIST95 ) ( ) ) ) ) {
            ( (  panic637 ) ( ( "mkdir() failed" ) ) );
        }
        struct Stat_75  stat2351 = ( (  undefined123 ) ( ) );
        ( ( stat ) ( (  path2350 ) ,  ( (  ptr_dash_castptr74 ) ( ( & (  stat2351 ) ) ) ) ) );
        if ( ( !  eq10 ( ( (  u32_dash_and784 ) ( ( (  stat2351 ) .f_mode ) ,  ( (  s_dash_ifmt96 ) ( ) ) ) ) , ( (  s_dash_ifdir97 ) ( ) ) ) ) ) {
            ( (  panic637 ) ( ( "mkdir() failed: path exists but is not a directory" ) ) );
        }
    }
    ( (  free_dash_const_dash_str779 ) ( (  path2350 ) ,  (  al2349 ) ) );
    return ( Unit_160_Unit );
}

struct env790 {
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    struct env407 envinst407;
    struct env406 envinst406;
    ;
};

static  enum Unit_160   lam405 (   struct env405 env ,    char  c2359 ) {
    if ( (  eq14 ( (  c2359 ) , ( (  from_dash_charlike1 ) ( ( "/" ) ) ) ) ) ) {
        if ( (  cmp39 ( ( (  count759 ) ( ( env.sb2357 ) ) ) , (  from_dash_integral8 ( 0 ) ) ) == 2 ) ) {
            struct funenv407  temp792 = ( (struct funenv407){ .fun = mkdir407, .env =  env.envinst407  } );
            ( temp792.fun ( temp792.env ,  ( * ( env.sb2357 ) ) ,  ( env.al2356 ) ) );
        }
    }
    struct funenv406  temp793 = ( (struct funenv406){ .fun = write_dash_char406, .env =  env.envinst406  } );
    ( temp793.fun ( temp793.env ,  ( env.sb2357 ) ,  (  c2359 ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   mkdir_dash_p790 (   struct env790 env ,    struct StrConcat_564  path2354 ,    enum CAllocator_378  al2356 ) {
    struct StrBuilder_379  temp791 = ( (  mk760 ) ( (  al2356 ) ) );
    struct StrBuilder_379 *  sb2357 = ( &temp791 );
    struct env405 envinst405 = {
        .envinst406 = env.envinst406 ,
        .al2356 =  al2356 ,
        .envinst407 = env.envinst407 ,
        .sb2357 =  sb2357 ,
    };
    ( (  for_dash_each404 ) ( ( (  chars575 ) ( (  path2354 ) ) ) ,  ( (struct funenv405){ .fun = lam405, .env = envinst405 } ) ) );
    struct funenv407  temp794 = ( (struct funenv407){ .fun = mkdir407, .env =  env.envinst407  } );
    ( temp794.fun ( temp794.env ,  ( * (  sb2357 ) ) ,  (  al2356 ) ) );
    ( (  free762 ) ( (  sb2357 ) ) );
    return ( Unit_160_Unit );
}

static  uint32_t   next_dash_u32795 (  ) {
    return ( (  cast169 ) ( ( ( rand ) ( ) ) ) );
}

static  struct Scanner_268   mk796 (    struct DynStr_411  s2639 ) {
    return ( (struct Scanner_268) { .f_s = ( (  chars704 ) ( (  s2639 ) ) ) } );
}

static  struct Maybe_442   scan_dash_int797 (    struct Scanner_268 *  sc2642 ) {
    struct TakeWhile_349  digit_dash_chars2643 = ( (  take_dash_while352 ) ( (  sc2642 ) ,  (  is_dash_digit716 ) ) );
    if ( ( (  null524 ) ( (  digit_dash_chars2643 ) ) ) ) {
        return ( (struct Maybe_442) { .tag = Maybe_442_None_t } );
    }
    ( (  drop_prime_525 ) ( (  sc2642 ) ,  ( (  count507 ) ( (  digit_dash_chars2643 ) ) ) ) );
    return ( (  parse_dash_int722 ) ( (  digit_dash_chars2643 ) ) );
}

static  struct timespec   now798 (  ) {
    struct timespec  temp799 = ( (  undefined112 ) ( ) );
    struct timespec *  t2656 = ( &temp799 );
    ( ( clock_gettime ) ( ( (  clock_dash_monotonic73 ) ( ) ) ,  (  t2656 ) ) );
    return ( * (  t2656 ) );
}

static  struct Termios_109   enable_dash_raw_dash_mode800 (  ) {
    struct Termios_109  temp801 = ( (  undefined108 ) ( ) );
    struct Termios_109 *  orig_dash_termios2694 = ( &temp801 );
    ( ( tcgetattr ) ( ( (  stdin_dash_fileno79 ) ( ) ) ,  ( (  cast_dash_ptr195 ) ( (  orig_dash_termios2694 ) ) ) ) );
    struct Termios_109  raw2695 = ( * (  orig_dash_termios2694 ) );
    raw2695 .f_c_dash_lflag = ( (  u32_dash_and784 ) ( ( (  raw2695 ) .f_c_dash_lflag ) ,  ( (  u32_dash_neg785 ) ( ( (  u32_dash_ors783 ) ( ( (  from_dash_listlike61 ) ( ( (struct Array_63) { ._arr = { ( (  echo80 ) ( ) ) , ( (  icanon81 ) ( ) ) , ( (  isig82 ) ( ) ) , ( ( (  iexten83 ) ( ) ) ) } } ) ) ) ) ) ) ) ) );
    raw2695 .f_c_dash_iflag = ( (  u32_dash_and784 ) ( ( (  raw2695 ) .f_c_dash_iflag ) ,  ( (  u32_dash_neg785 ) ( ( (  u32_dash_ors782 ) ( ( (  from_dash_listlike64 ) ( ( (struct Array_66) { ._arr = { ( (  brkint84 ) ( ) ) , ( (  icrnl85 ) ( ) ) , ( (  inpck86 ) ( ) ) , ( (  istrip87 ) ( ) ) , ( ( (  ixon88 ) ( ) ) ) } } ) ) ) ) ) ) ) ) );
    raw2695 .f_c_dash_oflag = ( (  u32_dash_and784 ) ( ( (  raw2695 ) .f_c_dash_oflag ) ,  ( (  u32_dash_neg785 ) ( ( (  u32_dash_ors781 ) ( ( (  from_dash_listlike67 ) ( ( (struct Array_69) { ._arr = { ( ( (  opost89 ) ( ) ) ) } } ) ) ) ) ) ) ) ) );
    raw2695 .f_c_dash_cflag = ( (  u32_dash_or780 ) ( ( (  raw2695 ) .f_c_dash_cflag ) ,  ( (  cs890 ) ( ) ) ) );
    ( (  set708 ) ( ( & ( (  raw2695 ) .f_c_dash_cc ) ) ,  ( (  vmin91 ) ( ) ) ,  (  from_dash_integral6 ( 0 ) ) ) );
    ( (  set708 ) ( ( & ( (  raw2695 ) .f_c_dash_cc ) ) ,  ( (  vtime92 ) ( ) ) ,  (  from_dash_integral6 ( 0 ) ) ) );
    ( ( tcsetattr ) ( ( (  stdin_dash_fileno79 ) ( ) ) ,  ( (  tcsa_dash_flush93 ) ( ) ) ,  ( (  cast_dash_ptr195 ) ( ( & (  raw2695 ) ) ) ) ) );
    return ( * (  orig_dash_termios2694 ) );
}

static  enum Unit_160   disable_dash_raw_dash_mode802 (    struct Termios_109 *  og_dash_termios2698 ) {
    ( ( tcsetattr ) ( ( (  stdin_dash_fileno79 ) ( ) ) ,  ( (  tcsa_dash_flush93 ) ( ) ) ,  ( (  cast_dash_ptr195 ) ( (  og_dash_termios2698 ) ) ) ) );
    return ( Unit_160_Unit );
}

static  struct Maybe_276   read_dash_byte803 (    int32_t  timeout_dash_ms2702 ) {
    struct Pollfd_206  pfd2703 = ( (struct Pollfd_206) { .f_fd = (  from_dash_integral3 ( 0 ) ) , .f_events = (  from_dash_integral5 ( 1 ) ) , .f_revents = (  from_dash_integral5 ( 0 ) ) } );
    if ( (  cmp40 ( ( ( poll ) ( ( (  cast_dash_ptr205 ) ( ( & (  pfd2703 ) ) ) ) ,  (  from_dash_integral3 ( 1 ) ) ,  (  timeout_dash_ms2702 ) ) ) , (  from_dash_integral3 ( 0 ) ) ) != 2 ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    char  c2704 = ( ( (  zeroed214 ) ( ) ) );
    if ( (  cmp40 ( ( ( read ) ( ( (  stdin_dash_fileno79 ) ( ) ) ,  ( (  cast_dash_ptr187 ) ( ( & (  c2704 ) ) ) ) ,  (  from_dash_integral8 ( 1 ) ) ) ) , (  from_dash_integral3 ( 0 ) ) ) != 2 ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    return ( ( Maybe_276_Just ) ( (  c2704 ) ) );
}

static  enum Unit_160   flush_dash_stdout804 (  ) {
    ( ( fflush ) ( ( (  null_dash_ptr244 ) ( ) ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   enable_dash_mouse805 (  ) {
    ( (  print_dash_str461 ) ( ( "\x1b[?1000h\x1b[?1006h" ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   disable_dash_mouse806 (  ) {
    ( (  print_dash_str461 ) ( ( "\x1b[?1000l\x1b[?1006l" ) ) );
    return ( Unit_160_Unit );
}

struct env808 {
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    bool *  should_dash_resize2708;
    ;
    ;
    ;
    ;
    ;
};

struct env809 {
    bool *  should_dash_resize2708;
};

struct funenv809 {
    enum Unit_160  (*fun) (  struct env809  ,    int32_t  );
    struct env809 env;
};

struct funenv809  _intr_sigarr[32];

static void _intr_sighandle (    int32_t  __intr__sig810 ) {
    struct funenv809  temp811 = _intr_sigarr [  __intr__sig810 ];
    temp811.fun ( temp811.env ,  __intr__sig810 );
}

static  enum Unit_160  _intr_register_signal (    int32_t  __intr__sig812 ,   struct funenv809  __intr__fun813 ) {
    _intr_sigarr [  __intr__sig812 ] =  __intr__fun813;
    signal(  __intr__sig812 , _intr_sighandle );
    return Unit_160_Unit;
}

static  enum Unit_160   lam809 (   struct env809 env ,    int32_t  dref2715 ) {
    (* env.should_dash_resize2708 ) = ( true );
    return ( Unit_160_Unit );
}

static  struct Tui_433   mk808 (   struct env808 env ) {
    struct Termios_109  og_dash_termios2710 = ( (  enable_dash_raw_dash_mode800 ) ( ) );
    ( (  hide_dash_cursor732 ) ( ) );
    ( (  reset_dash_colors744 ) ( ) );
    ( (  clear_dash_screen745 ) ( ) );
    ( (  enable_dash_mouse805 ) ( ) );
    ( (  flush_dash_stdout804 ) ( ) );
    enum ColorPalette_434  palette2711 = ( (  query_dash_palette739 ) ( ) );
    struct Tuple2_529  dims2712 = ( (  get_dash_dimensions735 ) ( ) );
    uint32_t  fps2713 = (  from_dash_integral4 ( 60 ) );
    struct timespec  last_dash_sync2714 = ( (  now798 ) ( ) );
    struct env809 envinst809 = {
        .should_dash_resize2708 = env.should_dash_resize2708 ,
    };
    ( _intr_register_signal ( (  from_dash_integral3 ( 28 ) ) , ( (struct funenv809){ .fun = lam809, .env = envinst809 } ) ) );
    return ( (struct Tui_433) { .f_width = ( (  fst528 ) ( (  dims2712 ) ) ) , .f_height = ( (  snd531 ) ( (  dims2712 ) ) ) , .f_target_dash_fps = (  fps2713 ) , .f_actual_dash_fps = (  from_dash_integral4 ( 0 ) ) , .f_last_dash_sync = (  last_dash_sync2714 ) , .f_fps_dash_ts = (  last_dash_sync2714 ) , .f_fps_dash_count = (  from_dash_integral4 ( 0 ) ) , .f_orig_dash_termios = (  og_dash_termios2710 ) , .f_palette = (  palette2711 ) } );
}

static  enum Unit_160   sync814 (    struct Tui_433 *  tui2718 ) {
    if ( (  eq10 ( ( ( * (  tui2718 ) ) .f_target_dash_fps ) , (  from_dash_integral4 ( 0 ) ) ) ) ) {
        return ( Unit_160_Unit );
    }
    int64_t  frame_dash_ns2719 = (  op_dash_div46 ( (  from_dash_integral2 ( 1000000000 ) ) , ( (  size_dash_i64253 ) ( ( (  u32_dash_size263 ) ( ( ( * (  tui2718 ) ) .f_target_dash_fps ) ) ) ) ) ) );
    struct timespec  temp815 = ( (  undefined112 ) ( ) );
    struct timespec *  now2720 = ( &temp815 );
    ( ( clock_gettime ) ( ( (  clock_dash_monotonic73 ) ( ) ) ,  (  now2720 ) ) );
    int64_t  elapsed_dash_ns2721 = (  op_dash_add43 ( (  op_dash_mul45 ( (  op_dash_sub44 ( ( ( * (  now2720 ) ) .tv_sec ) , ( ( ( * (  tui2718 ) ) .f_last_dash_sync ) .tv_sec ) ) ) , (  from_dash_integral2 ( 1000000000 ) ) ) ) , (  op_dash_sub44 ( ( ( * (  now2720 ) ) .tv_nsec ) , ( ( ( * (  tui2718 ) ) .f_last_dash_sync ) .tv_nsec ) ) ) ) );
    int64_t  sleep_dash_ns2722 = (  op_dash_sub44 ( (  frame_dash_ns2719 ) , (  elapsed_dash_ns2721 ) ) );
    if ( (  cmp37 ( (  sleep_dash_ns2722 ) , (  from_dash_integral2 ( 0 ) ) ) == 2 ) ) {
        struct timespec  temp816 = ( (struct timespec) { .tv_sec = (  from_dash_integral2 ( 0 ) ) , .tv_nsec = (  sleep_dash_ns2722 ) } );
        struct timespec *  ts2723 = ( &temp816 );
        ( ( nanosleep ) ( (  ts2723 ) ,  ( (  null_dash_ptr247 ) ( ) ) ) );
    }
    struct timespec  temp817 = ( (  undefined112 ) ( ) );
    struct timespec *  last_dash_sync2724 = ( &temp817 );
    ( ( clock_gettime ) ( ( (  clock_dash_monotonic73 ) ( ) ) ,  (  last_dash_sync2724 ) ) );
    (*  tui2718 ) .f_last_dash_sync = ( * (  last_dash_sync2724 ) );
    (*  tui2718 ) .f_fps_dash_count = (  op_dash_add52 ( ( ( * (  tui2718 ) ) .f_fps_dash_count ) , (  from_dash_integral4 ( 1 ) ) ) );
    int64_t  fps_dash_elapsed_dash_ms2725 = (  op_dash_add43 ( (  op_dash_mul45 ( (  op_dash_sub44 ( ( ( ( * (  tui2718 ) ) .f_last_dash_sync ) .tv_sec ) , ( ( ( * (  tui2718 ) ) .f_fps_dash_ts ) .tv_sec ) ) ) , (  from_dash_integral2 ( 1000 ) ) ) ) , (  op_dash_div46 ( (  op_dash_sub44 ( ( ( ( * (  tui2718 ) ) .f_last_dash_sync ) .tv_nsec ) , ( ( ( * (  tui2718 ) ) .f_fps_dash_ts ) .tv_nsec ) ) ) , (  from_dash_integral2 ( 1000000 ) ) ) ) ) );
    if ( (  cmp37 ( (  fps_dash_elapsed_dash_ms2725 ) , (  from_dash_integral2 ( 1000 ) ) ) != 0 ) ) {
        (*  tui2718 ) .f_actual_dash_fps = ( ( * (  tui2718 ) ) .f_fps_dash_count );
        (*  tui2718 ) .f_fps_dash_count = (  from_dash_integral4 ( 0 ) );
        (*  tui2718 ) .f_fps_dash_ts = ( ( * (  tui2718 ) ) .f_last_dash_sync );
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   deinit818 (    struct Tui_433 *  tui2728 ) {
    ( (  disable_dash_mouse806 ) ( ) );
    ( (  show_dash_cursor731 ) ( ) );
    ( (  reset_dash_colors744 ) ( ) );
    ( (  clear_dash_screen745 ) ( ) );
    ( (  reset_dash_cursor_dash_position734 ) ( ) );
    ( (  disable_dash_raw_dash_mode802 ) ( ( & ( ( * (  tui2728 ) ) .f_orig_dash_termios ) ) ) );
    ( (  flush_dash_stdout804 ) ( ) );
    return ( Unit_160_Unit );
}

static  bool   eq819 (    enum MouseButton_119  l2732 ,    enum MouseButton_119  r2734 ) {
    return (  eq10 ( ( (  cast_dash_on_dash_zeroed240 ) ( (  l2732 ) ) ) , ( ( (  cast_dash_on_dash_zeroed240 ) ( (  r2734 ) ) ) ) ) );
}

static  enum MouseButton_119   btn_dash_to_dash_mouse_dash_button820 (    int64_t  btn2740 ) {
    return ( {  int32_t  dref2741 = ( (  i64_dash_i32257 ) ( (  btn2740 ) ) ) ;  dref2741 == 0 ? ( MouseButton_119_MouseLeft ) :  dref2741 == 1 ? ( MouseButton_119_MouseMiddle ) :  dref2741 == 2 ? ( MouseButton_119_MouseRight ) :  dref2741 == 64 ? ( MouseButton_119_ScrollUp ) :  dref2741 == 65 ? ( MouseButton_119_ScrollDown ) : ( (  panic_prime_641 ) ( ( ( StrConcat_598_StrConcat ) ( ( "incorrect mouse button code: " ) ,  (  btn2740 ) ) ) ) ) ; } );
}

struct Maybe_822 {
    enum {
        Maybe_822_None_t,
        Maybe_822_Just_t,
    } tag;
    union {
        struct {
            struct Key_362  field0;
        } Maybe_822_Just_s;
    } stuff;
};

static struct Maybe_822 Maybe_822_Just (  struct Key_362  field0 ) {
    return ( struct Maybe_822 ) { .tag = Maybe_822_Just_t, .stuff = { .Maybe_822_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_822   parse_dash_ss3821 (    char  c2744 ) {
    if ( (  eq14 ( (  c2744 ) , ( (  from_dash_charlike1 ) ( ( "A" ) ) ) ) ) ) {
        return ( ( Maybe_822_Just ) ( ( (struct Key_362) { .tag = Key_362_Up_t } ) ) );
    }
    if ( (  eq14 ( (  c2744 ) , ( (  from_dash_charlike1 ) ( ( "B" ) ) ) ) ) ) {
        return ( ( Maybe_822_Just ) ( ( (struct Key_362) { .tag = Key_362_Down_t } ) ) );
    }
    if ( (  eq14 ( (  c2744 ) , ( (  from_dash_charlike1 ) ( ( "C" ) ) ) ) ) ) {
        return ( ( Maybe_822_Just ) ( ( (struct Key_362) { .tag = Key_362_Right_t } ) ) );
    }
    if ( (  eq14 ( (  c2744 ) , ( (  from_dash_charlike1 ) ( ( "D" ) ) ) ) ) ) {
        return ( ( Maybe_822_Just ) ( ( (struct Key_362) { .tag = Key_362_Left_t } ) ) );
    }
    if ( (  eq14 ( (  c2744 ) , ( (  from_dash_charlike1 ) ( ( "H" ) ) ) ) ) ) {
        return ( ( Maybe_822_Just ) ( ( (struct Key_362) { .tag = Key_362_Home_t } ) ) );
    }
    if ( (  eq14 ( (  c2744 ) , ( (  from_dash_charlike1 ) ( ( "F" ) ) ) ) ) ) {
        return ( ( Maybe_822_Just ) ( ( (struct Key_362) { .tag = Key_362_End_t } ) ) );
    }
    if ( (  eq14 ( (  c2744 ) , ( (  from_dash_charlike1 ) ( ( "P" ) ) ) ) ) ) {
        return ( ( Maybe_822_Just ) ( ( (struct Key_362) { .tag = Key_362_F1_t } ) ) );
    }
    if ( (  eq14 ( (  c2744 ) , ( (  from_dash_charlike1 ) ( ( "Q" ) ) ) ) ) ) {
        return ( ( Maybe_822_Just ) ( ( (struct Key_362) { .tag = Key_362_F2_t } ) ) );
    }
    if ( (  eq14 ( (  c2744 ) , ( (  from_dash_charlike1 ) ( ( "R" ) ) ) ) ) ) {
        return ( ( Maybe_822_Just ) ( ( (struct Key_362) { .tag = Key_362_F3_t } ) ) );
    }
    if ( (  eq14 ( (  c2744 ) , ( (  from_dash_charlike1 ) ( ( "S" ) ) ) ) ) ) {
        return ( ( Maybe_822_Just ) ( ( (struct Key_362) { .tag = Key_362_F4_t } ) ) );
    }
    return ( (struct Maybe_822) { .tag = Maybe_822_None_t } );
}

static  struct Maybe_360   parse_dash_csi823 (    struct DynStr_411  seq2747 ) {
    if ( (  eq13 ( ( ( (  seq2747 ) .f_contents ) .f_count ) , (  from_dash_integral8 ( 0 ) ) ) ) ) {
        return ( (struct Maybe_360) { .tag = Maybe_360_None_t } );
    }
    char  last2748 = (  elem_dash_get682 ( ( (  seq2747 ) .f_contents ) , (  op_dash_sub59 ( ( ( (  seq2747 ) .f_contents ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) ) );
    if ( ( (  eq14 ( (  elem_dash_get682 ( ( (  seq2747 ) .f_contents ) , (  from_dash_integral8 ( 0 ) ) ) ) , ( (  from_dash_charlike1 ) ( ( "<" ) ) ) ) ) && ( (  eq14 ( (  last2748 ) , ( (  from_dash_charlike1 ) ( ( "M" ) ) ) ) ) || (  eq14 ( (  last2748 ) , ( (  from_dash_charlike1 ) ( ( "m" ) ) ) ) ) ) ) ) {
        struct Scanner_268  temp824 = ( (  mk796 ) ( ( (  substr705 ) ( (  seq2747 ) ,  (  from_dash_integral8 ( 1 ) ) ,  ( ( (  seq2747 ) .f_contents ) .f_count ) ) ) ) );
        struct Scanner_268 *  sc2749 = ( &temp824 );
        struct Maybe_442  dref2750 = ( (  scan_dash_int797 ) ( (  sc2749 ) ) );
        if ( dref2750.tag == Maybe_442_None_t ) {
            return ( (struct Maybe_360) { .tag = Maybe_360_None_t } );
        }
        else {
            if ( dref2750.tag == Maybe_442_Just_t ) {
                ( (  next351 ) ( (  sc2749 ) ) );
                struct Maybe_442  dref2752 = ( (  scan_dash_int797 ) ( (  sc2749 ) ) );
                if ( dref2752.tag == Maybe_442_None_t ) {
                    return ( (struct Maybe_360) { .tag = Maybe_360_None_t } );
                }
                else {
                    if ( dref2752.tag == Maybe_442_Just_t ) {
                        ( (  next351 ) ( (  sc2749 ) ) );
                        struct Maybe_442  dref2754 = ( (  scan_dash_int797 ) ( (  sc2749 ) ) );
                        if ( dref2754.tag == Maybe_442_None_t ) {
                            return ( (struct Maybe_360) { .tag = Maybe_360_None_t } );
                        }
                        else {
                            if ( dref2754.tag == Maybe_442_Just_t ) {
                                return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Mouse ) ( ( (struct MouseEvent_363) { .f_button = ( (  btn_dash_to_dash_mouse_dash_button820 ) ( ( dref2750 .stuff .Maybe_442_Just_s .field0 ) ) ) , .f_x = (  op_dash_sub48 ( ( (  i64_dash_i32257 ) ( ( dref2752 .stuff .Maybe_442_Just_s .field0 ) ) ) , (  from_dash_integral3 ( 1 ) ) ) ) , .f_y = (  op_dash_sub48 ( ( (  i64_dash_i32257 ) ( ( dref2754 .stuff .Maybe_442_Just_s .field0 ) ) ) , (  from_dash_integral3 ( 1 ) ) ) ) , .f_pressed = (  eq14 ( (  last2748 ) , ( (  from_dash_charlike1 ) ( ( "M" ) ) ) ) ) } ) ) ) ) );
                            }
                        }
                    }
                }
            }
        }
    }
    if ( (  eq13 ( ( ( (  seq2747 ) .f_contents ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) ) {
        if ( (  eq14 ( (  last2748 ) , ( (  from_dash_charlike1 ) ( ( "A" ) ) ) ) ) ) {
            return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_Up_t } ) ) ) ) );
        }
        if ( (  eq14 ( (  last2748 ) , ( (  from_dash_charlike1 ) ( ( "B" ) ) ) ) ) ) {
            return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_Down_t } ) ) ) ) );
        }
        if ( (  eq14 ( (  last2748 ) , ( (  from_dash_charlike1 ) ( ( "C" ) ) ) ) ) ) {
            return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_Right_t } ) ) ) ) );
        }
        if ( (  eq14 ( (  last2748 ) , ( (  from_dash_charlike1 ) ( ( "D" ) ) ) ) ) ) {
            return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_Left_t } ) ) ) ) );
        }
        if ( (  eq14 ( (  last2748 ) , ( (  from_dash_charlike1 ) ( ( "H" ) ) ) ) ) ) {
            return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_Home_t } ) ) ) ) );
        }
        if ( (  eq14 ( (  last2748 ) , ( (  from_dash_charlike1 ) ( ( "F" ) ) ) ) ) ) {
            return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_End_t } ) ) ) ) );
        }
        return ( (struct Maybe_360) { .tag = Maybe_360_None_t } );
    }
    if ( (  eq14 ( (  last2748 ) , ( (  from_dash_charlike1 ) ( ( "~" ) ) ) ) ) ) {
        struct Scanner_268  temp825 = ( (  mk796 ) ( (  seq2747 ) ) );
        struct Scanner_268 *  sc2756 = ( &temp825 );
        struct Maybe_442  dref2757 = ( (  scan_dash_int797 ) ( (  sc2756 ) ) );
        if ( dref2757.tag == Maybe_442_None_t ) {
            return ( (struct Maybe_360) { .tag = Maybe_360_None_t } );
        }
        else {
            if ( dref2757.tag == Maybe_442_Just_t ) {
                return ( {  int32_t  dref2759 = ( (  i64_dash_i32257 ) ( ( dref2757 .stuff .Maybe_442_Just_s .field0 ) ) ) ;  dref2759 == 1 ? ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_Home_t } ) ) ) ) ) :  dref2759 == 2 ? ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_Insert_t } ) ) ) ) ) :  dref2759 == 3 ? ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_Delete_t } ) ) ) ) ) :  dref2759 == 4 ? ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_End_t } ) ) ) ) ) :  dref2759 == 5 ? ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_PageUp_t } ) ) ) ) ) :  dref2759 == 6 ? ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_PageDown_t } ) ) ) ) ) :  dref2759 == 15 ? ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_F5_t } ) ) ) ) ) :  dref2759 == 17 ? ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_F6_t } ) ) ) ) ) :  dref2759 == 18 ? ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_F7_t } ) ) ) ) ) :  dref2759 == 19 ? ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_F8_t } ) ) ) ) ) :  dref2759 == 20 ? ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_F9_t } ) ) ) ) ) :  dref2759 == 21 ? ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_F10_t } ) ) ) ) ) :  dref2759 == 23 ? ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_F11_t } ) ) ) ) ) :  dref2759 == 24 ? ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_F12_t } ) ) ) ) ) : ( (struct Maybe_360) { .tag = Maybe_360_None_t } ) ; } );
            }
        }
    }
    return ( (struct Maybe_360) { .tag = Maybe_360_None_t } );
}

static  struct Maybe_360   read_dash_key826 (  ) {
    char  temp827 = ( (  undefined100 ) ( ) );
    char *  ch2761 = ( &temp827 );
    struct Maybe_276  dref2762 = ( (  read_dash_byte803 ) ( (  from_dash_integral3 ( 0 ) ) ) );
    if ( dref2762.tag == Maybe_276_None_t ) {
        return ( (struct Maybe_360) { .tag = Maybe_360_None_t } );
    }
    else {
        if ( dref2762.tag == Maybe_276_Just_t ) {
            (*  ch2761 ) = ( dref2762 .stuff .Maybe_276_Just_s .field0 );
        }
    }
    if ( (  eq11 ( ( (  char_dash_u8632 ) ( ( * (  ch2761 ) ) ) ) , (  from_dash_integral6 ( 13 ) ) ) ) ) {
        return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_Enter_t } ) ) ) ) );
    }
    if ( (  eq11 ( ( (  char_dash_u8632 ) ( ( * (  ch2761 ) ) ) ) , (  from_dash_integral6 ( 127 ) ) ) ) ) {
        return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_Backspace_t } ) ) ) ) );
    }
    if ( ( (  cmp42 ( ( (  char_dash_u8632 ) ( ( * (  ch2761 ) ) ) ) , (  from_dash_integral6 ( 27 ) ) ) == 0 ) && ( !  eq11 ( ( (  char_dash_u8632 ) ( ( * (  ch2761 ) ) ) ) , (  from_dash_integral6 ( 9 ) ) ) ) ) ) {
        char  letter2764 = ( (  i32_dash_char633 ) ( ( (  u32_dash_i32264 ) ( ( (  u32_dash_or780 ) ( ( (  i32_dash_u32254 ) ( ( (  char_dash_i32631 ) ( ( * (  ch2761 ) ) ) ) ) ) ,  ( (  from_dash_hex727 ) ( ( "60" ) ) ) ) ) ) ) ) );
        return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( ( Key_362_Ctrl ) ( (  letter2764 ) ) ) ) ) ) );
    }
    if ( ( !  eq11 ( ( (  char_dash_u8632 ) ( ( * (  ch2761 ) ) ) ) , (  from_dash_integral6 ( 27 ) ) ) ) ) {
        if ( (  cmp42 ( ( (  char_dash_u8632 ) ( ( * (  ch2761 ) ) ) ) , (  from_dash_integral6 ( 127 ) ) ) == 2 ) ) {
            return ( (  read_dash_key826 ) ( ) );
        } else {
            return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( ( Key_362_Char ) ( ( * (  ch2761 ) ) ) ) ) ) ) );
        }
    }
    char  temp828 = ( (  undefined100 ) ( ) );
    char *  ch22765 = ( &temp828 );
    struct Maybe_276  dref2766 = ( (  read_dash_byte803 ) ( (  from_dash_integral3 ( 50 ) ) ) );
    if ( dref2766.tag == Maybe_276_None_t ) {
        return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_Escape_t } ) ) ) ) );
    }
    else {
        if ( dref2766.tag == Maybe_276_Just_t ) {
            (*  ch22765 ) = ( dref2766 .stuff .Maybe_276_Just_s .field0 );
        }
    }
    if ( (  eq14 ( ( * (  ch22765 ) ) , ( (  from_dash_charlike1 ) ( ( "[" ) ) ) ) ) ) {
        struct Array_167  temp829 = ( ( (  zeroed228 ) ( ) ) );
        struct Array_167 *  seq2768 = ( &temp829 );
        int32_t  slen2769 = (  from_dash_integral3 ( 0 ) );
        while ( (  cmp40 ( (  slen2769 ) , (  from_dash_integral3 ( 31 ) ) ) == 0 ) ) {
            char  temp830 = ( (  undefined100 ) ( ) );
            char *  sc2770 = ( &temp830 );
            struct Maybe_276  dref2771 = ( (  read_dash_byte803 ) ( (  from_dash_integral3 ( 50 ) ) ) );
            if ( dref2771.tag == Maybe_276_None_t ) {
                break;
            }
            else {
                if ( dref2771.tag == Maybe_276_Just_t ) {
                    (*  sc2770 ) = ( dref2771 .stuff .Maybe_276_Just_s .field0 );
                }
            }
            ( (  set709 ) ( (  seq2768 ) ,  ( (  i32_dash_size256 ) ( (  slen2769 ) ) ) ,  ( * (  sc2770 ) ) ) );
            slen2769 = (  op_dash_add47 ( (  slen2769 ) , (  from_dash_integral3 ( 1 ) ) ) );
            if ( ( (  cmp42 ( ( (  char_dash_u8632 ) ( ( * (  sc2770 ) ) ) ) , (  from_dash_integral6 ( 64 ) ) ) != 0 ) && (  cmp42 ( ( (  char_dash_u8632 ) ( ( * (  sc2770 ) ) ) ) , (  from_dash_integral6 ( 126 ) ) ) != 2 ) ) ) {
                break;
            }
        }
        return ( (  parse_dash_csi823 ) ( ( (struct DynStr_411) { .f_contents = ( (  subslice673 ) ( ( (  as_dash_slice710 ) ( (  seq2768 ) ) ) ,  (  from_dash_integral8 ( 0 ) ) ,  ( (  i32_dash_size256 ) ( (  slen2769 ) ) ) ) ) } ) ) );
    }
    if ( (  eq14 ( ( * (  ch22765 ) ) , ( (  from_dash_charlike1 ) ( ( "O" ) ) ) ) ) ) {
        char  temp831 = ( (  undefined100 ) ( ) );
        char *  sc2773 = ( &temp831 );
        struct Maybe_276  dref2774 = ( (  read_dash_byte803 ) ( (  from_dash_integral3 ( 50 ) ) ) );
        if ( dref2774.tag == Maybe_276_None_t ) {
            return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_Escape_t } ) ) ) ) );
        }
        else {
            if ( dref2774.tag == Maybe_276_Just_t ) {
                (*  sc2773 ) = ( dref2774 .stuff .Maybe_276_Just_s .field0 );
            }
        }
        struct Maybe_822  dref2776 = ( (  parse_dash_ss3821 ) ( ( * (  sc2773 ) ) ) );
        if ( dref2776.tag == Maybe_822_None_t ) {
            return ( (struct Maybe_360) { .tag = Maybe_360_None_t } );
        }
        else {
            if ( dref2776.tag == Maybe_822_Just_t ) {
                return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( dref2776 .stuff .Maybe_822_Just_s .field0 ) ) ) ) );
            }
        }
    }
    return ( ( Maybe_360_Just ) ( ( ( InputEvent_361_Key ) ( ( (struct Key_362) { .tag = Key_362_Escape_t } ) ) ) ) );
}

struct env832 {
    ;
    ;
    ;
    bool *  should_dash_resize2708;
};

static  bool   update_dash_dimensions832 (   struct env832 env ,    struct Tui_433 *  tui2780 ) {
    if ( ( ! ( * ( env.should_dash_resize2708 ) ) ) ) {
        return ( false );
    }
    (* env.should_dash_resize2708 ) = ( false );
    struct Tuple2_529  dim2781 = ( (  get_dash_dimensions735 ) ( ) );
    uint32_t  w2782 = ( (  fst528 ) ( (  dim2781 ) ) );
    uint32_t  h2783 = ( (  snd531 ) ( (  dim2781 ) ) );
    (*  tui2780 ) .f_width = (  w2782 );
    (*  tui2780 ) .f_height = (  h2783 );
    return ( true );
}

static  struct Cell_16   lam834 (    struct Cell_16  dref2801 ) {
    return ( (struct Cell_16) { .f_c = ( (  from_dash_charlike1 ) ( ( " " ) ) ) , .f_fg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) , .f_bg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) } );
}

static  struct Cell_16   lam835 (    struct Cell_16  dref2803 ) {
    return ( (struct Cell_16) { .f_c = ( (  from_dash_charlike1 ) ( ( " " ) ) ) , .f_fg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) , .f_bg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) } );
}

static  struct Screen_432   mk_dash_screen833 (    struct Tui_433 *  tui2797 ,    enum CAllocator_378  al2799 ) {
    struct Slice_393  cur2800 = ( (  allocate694 ) ( (  al2799 ) ,  ( (  u32_dash_size263 ) ( (  op_dash_mul54 ( ( ( * (  tui2797 ) ) .f_width ) , ( ( * (  tui2797 ) ) .f_height ) ) ) ) ) ) );
    ( (  map687 ) ( (  cur2800 ) ,  (  lam834 ) ) );
    struct Slice_393  prev2802 = ( (  allocate694 ) ( (  al2799 ) ,  ( (  u32_dash_size263 ) ( (  op_dash_mul54 ( ( ( * (  tui2797 ) ) .f_width ) , ( ( * (  tui2797 ) ) .f_height ) ) ) ) ) ) );
    ( (  map688 ) ( (  prev2802 ) ,  (  lam835 ) ) );
    return ( (struct Screen_432) { .f_current = (  cur2800 ) , .f_previous = (  prev2802 ) , .f_al = (  al2799 ) , .f_tui = (  tui2797 ) , .f_requires_dash_full_dash_redraw = ( false ) , .f_default_dash_fg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) , .f_default_dash_bg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) } );
}

static  enum Unit_160   free_dash_screen836 (    struct Screen_432 *  screen2806 ) {
    enum CAllocator_378  al2807 = ( ( * (  screen2806 ) ) .f_al );
    ( (  free698 ) ( (  al2807 ) ,  ( ( * (  screen2806 ) ) .f_current ) ) );
    ( (  free698 ) ( (  al2807 ) ,  ( ( * (  screen2806 ) ) .f_previous ) ) );
    return ( Unit_160_Unit );
}

static  struct Cell_16   lam838 (    struct Cell_16  dref2811 ) {
    return ( (struct Cell_16) { .f_c = ( (  from_dash_charlike1 ) ( ( " " ) ) ) , .f_fg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) , .f_bg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) } );
}

static  enum Unit_160   clear_dash_screen837 (    struct Screen_432 *  screen2810 ) {
    ( (  map689 ) ( ( ( * (  screen2810 ) ) .f_current ) ,  (  lam838 ) ) );
    return ( Unit_160_Unit );
}

struct RenderState_840 {
    uint32_t  f_x;
    uint32_t  f_y;
    struct Color_17  f_fg;
    struct Color_17  f_bg;
    uint32_t  f_changes;
};

static  enum Unit_160   emit_dash_cell839 (    struct RenderState_840 *  rs2815 ,    struct Cell_16 *  c2817 ,    uint32_t  x2819 ,    uint32_t  y2821 ) {
    if ( ( ( !  eq10 ( (  x2819 ) , ( ( * (  rs2815 ) ) .f_x ) ) ) || ( !  eq10 ( (  y2821 ) , ( ( * (  rs2815 ) ) .f_y ) ) ) ) ) {
        ( (  move_dash_cursor_dash_to733 ) ( (  x2819 ) ,  (  y2821 ) ) );
        (*  rs2815 ) .f_x = (  x2819 );
        (*  rs2815 ) .f_y = (  y2821 );
    }
    char  char2822 = ( ( * (  c2817 ) ) .f_c );
    struct Color_17  bg2823 = ( ( * (  c2817 ) ) .f_bg );
    if ( ( ( (  eq14 ( (  char2822 ) , ( (  from_dash_charlike1 ) ( ( "\t" ) ) ) ) ) || (  eq14 ( (  char2822 ) , ( (  from_dash_charlike1 ) ( ( "\r" ) ) ) ) ) ) || (  eq14 ( (  char2822 ) , ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) ) {
        char2822 = ( (  from_dash_charlike1 ) ( ( " " ) ) );
        bg2823 = ( ( Color_17_Color8 ) ( ( Color8_18_Red8 ) ) );
    }
    if ( ( !  eq22 ( ( ( * (  rs2815 ) ) .f_fg ) , ( ( * (  c2817 ) ) .f_fg ) ) ) ) {
        ( (  set_dash_fg750 ) ( ( ( * (  c2817 ) ) .f_fg ) ) );
        (*  rs2815 ) .f_fg = ( ( * (  c2817 ) ) .f_fg );
    }
    if ( ( !  eq22 ( ( ( * (  rs2815 ) ) .f_bg ) , (  bg2823 ) ) ) ) {
        ( (  set_dash_bg751 ) ( (  bg2823 ) ) );
        (*  rs2815 ) .f_bg = (  bg2823 );
    }
    ( (  print_dash_str468 ) ( (  char2822 ) ) );
    (*  rs2815 ) .f_x = (  op_dash_add52 ( ( ( * (  rs2815 ) ) .f_x ) , (  from_dash_integral4 ( 1 ) ) ) );
    return ( Unit_160_Unit );
}

static  uint32_t   render_dash_screen841 (    struct Screen_432 *  screen2826 ) {
    int32_t  w2827 = ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2826 ) ) .f_tui ) ) .f_width ) ) );
    int32_t  h2828 = ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2826 ) ) .f_tui ) ) .f_height ) ) );
    struct RenderState_840  temp842 = ( (struct RenderState_840) { .f_x = (  from_dash_integral4 ( 0 ) ) , .f_y = (  from_dash_integral4 ( 0 ) ) , .f_fg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) , .f_bg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) , .f_changes = (  from_dash_integral4 ( 0 ) ) } );
    struct RenderState_840 *  rs2829 = ( &temp842 );
    ( (  move_dash_cursor_dash_to733 ) ( (  from_dash_integral4 ( 0 ) ) ,  (  from_dash_integral4 ( 0 ) ) ) );
    struct RangeIter_288  temp843 =  into_dash_iter287 ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  op_dash_sub48 ( (  h2828 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_290  __cond844 =  next289 (&temp843);
        if (  __cond844 .tag == 0 ) {
            break;
        }
        int32_t  y2831 =  __cond844 .stuff .Maybe_290_Just_s .field0;
        struct RangeIter_288  temp845 =  into_dash_iter287 ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  op_dash_sub48 ( (  w2827 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
        while (true) {
            struct Maybe_290  __cond846 =  next289 (&temp845);
            if (  __cond846 .tag == 0 ) {
                break;
            }
            int32_t  x2833 =  __cond846 .stuff .Maybe_290_Just_s .field0;
            size_t  i2834 = ( (  i32_dash_size256 ) ( (  op_dash_add47 ( (  op_dash_mul49 ( (  y2831 ) , (  w2827 ) ) ) , (  x2833 ) ) ) ) );
            struct Cell_16 *  cur2835 = ( (  get_dash_ptr659 ) ( ( ( * (  screen2826 ) ) .f_current ) ,  (  i2834 ) ) );
            struct Cell_16 *  prev2836 = ( (  get_dash_ptr659 ) ( ( ( * (  screen2826 ) ) .f_previous ) ,  (  i2834 ) ) );
            if ( ( ( !  eq15 ( (  cur2835 ) , (  prev2836 ) ) ) || ( ( * (  screen2826 ) ) .f_requires_dash_full_dash_redraw ) ) ) {
                (*  rs2829 ) .f_changes = (  op_dash_add52 ( ( ( * (  rs2829 ) ) .f_changes ) , (  from_dash_integral4 ( 1 ) ) ) );
                ( (  emit_dash_cell839 ) ( (  rs2829 ) ,  (  cur2835 ) ,  ( (  i32_dash_u32254 ) ( (  x2833 ) ) ) ,  ( (  i32_dash_u32254 ) ( (  y2831 ) ) ) ) );
                (*  prev2836 ) = ( * (  cur2835 ) );
            }
        }
    }
    (*  screen2826 ) .f_requires_dash_full_dash_redraw = ( false );
    ( (  reset_dash_colors744 ) ( ) );
    ( (  flush_dash_stdout804 ) ( ) );
    return ( ( * (  rs2829 ) ) .f_changes );
}

struct funenv832 {
    bool  (*fun) (  struct env832  ,    struct Tui_433 *  );
    struct env832 env;
};

struct env847 {
    ;
    ;
    ;
    ;
    ;
    struct env832 envinst832;
};

static  bool   resize_dash_screen_dash_if_dash_needed847 (   struct env847 env ,    struct Screen_432 *  screen2839 ) {
    struct Tui_433 *  tui2840 = ( ( * (  screen2839 ) ) .f_tui );
    struct funenv832  temp848 = ( (struct funenv832){ .fun = update_dash_dimensions832, .env =  env.envinst832  } );
    if ( ( ! ( temp848.fun ( temp848.env ,  (  tui2840 ) ) ) ) ) {
        return ( false );
    }
    (*  screen2839 ) .f_requires_dash_full_dash_redraw = ( true );
    uint32_t  w2841 = ( ( * ( ( * (  screen2839 ) ) .f_tui ) ) .f_width );
    uint32_t  h2842 = ( ( * ( ( * (  screen2839 ) ) .f_tui ) ) .f_height );
    size_t  nusz2843 = ( (  u32_dash_size263 ) ( (  op_dash_mul54 ( (  w2841 ) , (  h2842 ) ) ) ) );
    if ( (  cmp39 ( (  nusz2843 ) , ( ( ( * (  screen2839 ) ) .f_current ) .f_count ) ) != 2 ) ) {
        return ( true );
    }
    struct Screen_432  nuscreen2844 = ( (  mk_dash_screen833 ) ( (  tui2840 ) ,  ( ( * (  screen2839 ) ) .f_al ) ) );
    (*  screen2839 ) .f_current = ( (  nuscreen2844 ) .f_current );
    (*  screen2839 ) .f_previous = ( (  nuscreen2844 ) .f_previous );
    return ( true );
}

static  enum Unit_160   set_dash_screen_dash_fg849 (    struct Screen_432 *  screen2847 ,    struct Color_17  c2849 ) {
    (*  screen2847 ) .f_default_dash_fg = (  c2849 );
    return ( Unit_160_Unit );
}

static  enum Unit_160   set_dash_screen_dash_bg850 (    struct Screen_432 *  screen2852 ,    struct Color_17  c2854 ) {
    (*  screen2852 ) .f_default_dash_bg = (  c2854 );
    return ( Unit_160_Unit );
}

static  enum Unit_160   set_dash_screen_dash_colors851 (    struct Screen_432 *  screen2857 ,    struct Color_17  fg2859 ,    struct Color_17  bg2861 ) {
    (*  screen2857 ) .f_default_dash_fg = (  fg2859 );
    (*  screen2857 ) .f_default_dash_bg = (  bg2861 );
    return ( Unit_160_Unit );
}

static  struct Maybe_651   get_dash_cell_dash_ptr852 (    struct Screen_432 *  screen2868 ,    int32_t  x2870 ,    int32_t  y2872 ) {
    int32_t  w2873 = ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2868 ) ) .f_tui ) ) .f_width ) ) );
    if ( ( (  cmp40 ( (  x2870 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) || (  cmp40 ( (  x2870 ) , (  w2873 ) ) != 0 ) ) ) {
        return ( (struct Maybe_651) { .tag = Maybe_651_None_t } );
    }
    if ( ( (  cmp40 ( (  y2872 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) || (  cmp40 ( (  y2872 ) , ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2868 ) ) .f_tui ) ) .f_height ) ) ) ) != 0 ) ) ) {
        return ( (struct Maybe_651) { .tag = Maybe_651_None_t } );
    }
    size_t  i2874 = ( (  i32_dash_size256 ) ( (  op_dash_add47 ( (  op_dash_mul49 ( (  y2872 ) , (  w2873 ) ) ) , (  x2870 ) ) ) ) );
    return ( ( Maybe_651_Just ) ( ( (  get_dash_ptr659 ) ( ( ( * (  screen2868 ) ) .f_current ) ,  (  i2874 ) ) ) ) );
}

static  enum Unit_160   fill_dash_default853 (    struct Screen_432 *  screen2877 ) {
    struct RangeIter_288  temp854 =  into_dash_iter287 ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  op_dash_sub48 ( ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2877 ) ) .f_tui ) ) .f_height ) ) ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_290  __cond855 =  next289 (&temp854);
        if (  __cond855 .tag == 0 ) {
            break;
        }
        int32_t  y2879 =  __cond855 .stuff .Maybe_290_Just_s .field0;
        struct RangeIter_288  temp856 =  into_dash_iter287 ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  op_dash_sub48 ( ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2877 ) ) .f_tui ) ) .f_width ) ) ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
        while (true) {
            struct Maybe_290  __cond857 =  next289 (&temp856);
            if (  __cond857 .tag == 0 ) {
                break;
            }
            int32_t  x2881 =  __cond857 .stuff .Maybe_290_Just_s .field0;
            struct Cell_16 *  cell2882 = ( (  or_dash_fail650 ) ( ( (  get_dash_cell_dash_ptr852 ) ( (  screen2877 ) ,  (  x2881 ) ,  (  y2879 ) ) ) ,  ( "no cell??" ) ) );
            (*  cell2882 ) .f_bg = ( ( * (  screen2877 ) ) .f_default_dash_bg );
        }
    }
    return ( Unit_160_Unit );
}

static  enum Unit_160   put_dash_char858 (    struct Screen_432 *  screen2885 ,    char  c2887 ,    int32_t  x2889 ,    int32_t  y2891 ) {
    int32_t  w2892 = ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2885 ) ) .f_tui ) ) .f_width ) ) );
    if ( ( ( ( (  cmp40 ( (  x2889 ) , (  w2892 ) ) != 0 ) || (  cmp40 ( (  y2891 ) , ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2885 ) ) .f_tui ) ) .f_height ) ) ) ) != 0 ) ) || (  cmp40 ( (  x2889 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) ) || (  cmp40 ( (  y2891 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) ) ) {
        return ( Unit_160_Unit );
    }
    size_t  i2893 = ( (  i32_dash_size256 ) ( (  op_dash_add47 ( (  op_dash_mul49 ( (  y2891 ) , (  w2892 ) ) ) , (  x2889 ) ) ) ) );
    struct Color_17  fg2894 = ( ( * (  screen2885 ) ) .f_default_dash_fg );
    struct Color_17  bg2895 = ( ( * (  screen2885 ) ) .f_default_dash_bg );
    char  c2896 = (  c2887 );
    ( (  set670 ) ( ( ( * (  screen2885 ) ) .f_current ) ,  (  i2893 ) ,  ( (struct Cell_16) { .f_c = (  c2896 ) , .f_fg = (  fg2894 ) , .f_bg = (  bg2895 ) } ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   lam431 (   struct env431 env ,    struct Tuple2_312  dref2910 ) {
    ( (  put_dash_char858 ) ( ( env.screen2899 ) ,  ( dref2910 .field0 ) ,  (  op_dash_add47 ( ( env.x2908 ) , ( dref2910 .field1 ) ) ) ,  ( env.y2905 ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   draw_dash_str859 (    struct Screen_432 *  screen2899 ,    struct StrConcat_577  s2901 ,    int32_t  x2903 ,    int32_t  y2905 ) {
    int32_t  w2906 = ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2899 ) ) .f_tui ) ) .f_width ) ) );
    if ( ( (  cmp40 ( (  y2905 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) || (  cmp40 ( (  y2905 ) , ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2899 ) ) .f_tui ) ) .f_height ) ) ) ) != 0 ) ) ) {
        return ( Unit_160_Unit );
    }
    int32_t  i2907 = (  op_dash_add47 ( (  op_dash_mul49 ( (  y2905 ) , (  w2906 ) ) ) , (  x2903 ) ) );
    int32_t  x2908 = ( (  min551 ) ( (  x2903 ) ,  (  w2906 ) ) );
    size_t  max_dash_len2909 = ( (  i32_dash_size256 ) ( (  op_dash_sub48 ( (  w2906 ) , (  x2908 ) ) ) ) );
    struct env431 envinst431 = {
        .y2905 =  y2905 ,
        .screen2899 =  screen2899 ,
        .x2908 =  x2908 ,
    };
    ( (  for_dash_each430 ) ( ( (  zip335 ) ( ( (  chars628 ) ( (  s2901 ) ) ) ,  ( (  from291 ) ( (  from_dash_integral3 ( 0 ) ) ) ) ) ) ,  ( (struct funenv431){ .fun = lam431, .env = envinst431 } ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   lam438 (   struct env438 env ,    struct Tuple2_312  dref2910 ) {
    ( (  put_dash_char858 ) ( ( env.screen2899 ) ,  ( dref2910 .field0 ) ,  (  op_dash_add47 ( ( env.x2908 ) , ( dref2910 .field1 ) ) ) ,  ( env.y2905 ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   draw_dash_str860 (    struct Screen_432 *  screen2899 ,    const char*  s2901 ,    int32_t  x2903 ,    int32_t  y2905 ) {
    int32_t  w2906 = ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2899 ) ) .f_tui ) ) .f_width ) ) );
    if ( ( (  cmp40 ( (  y2905 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) || (  cmp40 ( (  y2905 ) , ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2899 ) ) .f_tui ) ) .f_height ) ) ) ) != 0 ) ) ) {
        return ( Unit_160_Unit );
    }
    int32_t  i2907 = (  op_dash_add47 ( (  op_dash_mul49 ( (  y2905 ) , (  w2906 ) ) ) , (  x2903 ) ) );
    int32_t  x2908 = ( (  min551 ) ( (  x2903 ) ,  (  w2906 ) ) );
    size_t  max_dash_len2909 = ( (  i32_dash_size256 ) ( (  op_dash_sub48 ( (  w2906 ) , (  x2908 ) ) ) ) );
    struct env438 envinst438 = {
        .y2905 =  y2905 ,
        .screen2899 =  screen2899 ,
        .x2908 =  x2908 ,
    };
    ( (  for_dash_each437 ) ( ( (  zip341 ) ( ( (  chars552 ) ( (  s2901 ) ) ) ,  ( (  from291 ) ( (  from_dash_integral3 ( 0 ) ) ) ) ) ) ,  ( (struct funenv438){ .fun = lam438, .env = envinst438 } ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   draw_dash_str_dash_center861 (    struct Screen_432 *  screen2927 ,    const char*  s2929 ,    int32_t  x2931 ,    int32_t  y2933 ) {
    int32_t  slen2934 = ( (  size_dash_i32260 ) ( ( (  count509 ) ( ( (  chars552 ) ( (  s2929 ) ) ) ) ) ) );
    int32_t  x2935 = (  op_dash_sub48 ( (  x2931 ) , (  op_dash_div50 ( (  slen2934 ) , (  from_dash_integral3 ( 2 ) ) ) ) ) );
    ( (  draw_dash_str860 ) ( (  screen2927 ) ,  (  s2929 ) ,  (  x2935 ) ,  (  y2933 ) ) );
    return ( Unit_160_Unit );
}

static  struct StrCase_565   xdg_dash_home862 (    const char*  name2998 ,    const char*  loc3000 ) {
    return ( {  struct Maybe_252  dref3001 = ( (  get730 ) ( (  name2998 ) ) ) ; dref3001.tag == Maybe_252_Just_t ? ( ( StrCase_565_StrCase1 ) ( ( dref3001 .stuff .Maybe_252_Just_s .field0 ) ) ) : ( ( StrCase_565_StrCase2 ) ( ( ( StrConcat_566_StrConcat ) ( ( (  or_dash_else654 ) ( ( (  get730 ) ( ( "HOME" ) ) ) ,  ( (  from_dash_charlike0 ) ( ( "~" ) ) ) ) ) ,  (  loc3000 ) ) ) ) ) ; } );
}

static  struct StrCase_565   data_dash_home863 (  ) {
    return ( (  xdg_dash_home862 ) ( ( "XDG_DATA_HOME" ) ,  ( "/.local/share" ) ) );
}

static  struct Slice_672   get864 (  ) {
    return ( (struct Slice_672) { .f_ptr = ( (  offset_dash_ptr127 ) ( ( _global_argv ) ,  (  from_dash_integral2 ( 1 ) ) ) ) , .f_count = (  op_dash_sub59 ( ( _global_argc ) , (  from_dash_integral8 ( 1 ) ) ) ) } );
}

enum GameState_866 {
    GameState_866_InProgress,
    GameState_866_Failed,
    GameState_866_Won,
};

struct Tuple2_867 {
    enum GameState_866  field0;
    enum GameState_866  field1;
};

static struct Tuple2_867 Tuple2_867_Tuple2 (  enum GameState_866  field0 ,  enum GameState_866  field1 ) {
    return ( struct Tuple2_867 ) { .field0 = field0 ,  .field1 = field1 };
};

static  bool   eq865 (    enum GameState_866  l2563 ,    enum GameState_866  r2565 ) {
    return ( {  struct Tuple2_867  dref2566 = ( ( Tuple2_867_Tuple2 ) ( (  l2563 ) ,  (  r2565 ) ) ) ;  dref2566 .field0 == GameState_866_InProgress &&  dref2566 .field1 == GameState_866_InProgress ? ( true ) :  dref2566 .field0 == GameState_866_Failed &&  dref2566 .field1 == GameState_866_Failed ? ( true ) :  dref2566 .field0 == GameState_866_Won &&  dref2566 .field1 == GameState_866_Won ? ( true ) : ( false ) ; } );
}

struct TileMap_869 {
    struct Slice_304  f_tiles;
    int32_t  f_width;
    int32_t  f_height;
};

static  struct TileMap_869   mk_dash_tiles868 (    size_t  w2571 ,    size_t  h2573 ,    enum CAllocator_378  al2575 ) {
    struct Slice_304  rows2576 = ( (  allocate692 ) ( (  al2575 ) ,  (  h2573 ) ) );
    struct SliceAddressIter_675  temp870 =  into_dash_iter676 ( ( (  addresses674 ) ( (  rows2576 ) ) ) );
    while (true) {
        struct Maybe_678  __cond871 =  next677 (&temp870);
        if (  __cond871 .tag == 0 ) {
            break;
        }
        struct Slice_103 *  row2578 =  __cond871 .stuff .Maybe_678_Just_s .field0;
        (*  row2578 ) = ( (  default699 ) ( (  al2575 ) ,  (  w2571 ) ,  ( (struct Tile_104) { .f_hidden = ( true ) , .f_is_dash_bomb = ( false ) , .f_flagged = ( false ) } ) ) );
    }
    return ( (struct TileMap_869) { .f_tiles = (  rows2576 ) , .f_width = ( (  size_dash_i32260 ) ( (  w2571 ) ) ) , .f_height = ( (  size_dash_i32260 ) ( (  h2573 ) ) ) } );
}

static  enum Unit_160   map_dash_tile872 (    struct TileMap_869  tilemap2581 ,    int32_t  x2583 ,    int32_t  y2585 ,    struct Tile_104 (*  fun2587 )(    struct Tile_104  ) ) {
    struct Tile_104 *  tp2588 = ( (  get_dash_ptr658 ) ( (  elem_dash_get679 ( ( (  tilemap2581 ) .f_tiles ) , ( (  i32_dash_size256 ) ( (  y2585 ) ) ) ) ) ,  ( (  i32_dash_size256 ) ( (  x2583 ) ) ) ) );
    (*  tp2588 ) = ( (  fun2587 ) ( ( * (  tp2588 ) ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   map_dash_tile873 (    struct TileMap_869  tilemap2581 ,    int32_t  x2583 ,    int32_t  y2585 ,    struct Tile_104 (*  fun2587 )(    struct Tile_104  ) ) {
    struct Tile_104 *  tp2588 = ( (  get_dash_ptr658 ) ( (  elem_dash_get679 ( ( (  tilemap2581 ) .f_tiles ) , ( (  i32_dash_size256 ) ( (  y2585 ) ) ) ) ) ,  ( (  i32_dash_size256 ) ( (  x2583 ) ) ) ) );
    (*  tp2588 ) = ( (  fun2587 ) ( ( * (  tp2588 ) ) ) );
    return ( Unit_160_Unit );
}

static  enum Unit_160   map_dash_tile874 (    struct TileMap_869  tilemap2581 ,    int32_t  x2583 ,    int32_t  y2585 ,    struct Tile_104 (*  fun2587 )(    struct Tile_104  ) ) {
    struct Tile_104 *  tp2588 = ( (  get_dash_ptr658 ) ( (  elem_dash_get679 ( ( (  tilemap2581 ) .f_tiles ) , ( (  i32_dash_size256 ) ( (  y2585 ) ) ) ) ) ,  ( (  i32_dash_size256 ) ( (  x2583 ) ) ) ) );
    (*  tp2588 ) = ( (  fun2587 ) ( ( * (  tp2588 ) ) ) );
    return ( Unit_160_Unit );
}

static  struct Maybe_330   lam535 (   struct env535 env ,    struct Slice_103  s2597 ) {
    return ( (  try_dash_get662 ) ( (  s2597 ) ,  ( env.x2594 ) ) );
}

static  struct Tile_104   elem_dash_get875 (    struct TileMap_869  self2591 ,    struct Tuple2_527  idx2593 ) {
    size_t  x2594 = ( (  i32_dash_size256 ) ( ( (  fst526 ) ( (  idx2593 ) ) ) ) );
    size_t  y2595 = ( (  i32_dash_size256 ) ( ( (  snd530 ) ( (  idx2593 ) ) ) ) );
    struct env535 envinst535 = {
        .x2594 =  x2594 ,
    };
    return ( (  or_dash_else655 ) ( ( (  and_dash_maybe534 ) ( ( (  try_dash_get661 ) ( ( (  self2591 ) .f_tiles ) ,  (  y2595 ) ) ) ,  ( (struct funenv535){ .fun = lam535, .env = envinst535 } ) ) ) ,  ( (struct Tile_104) { .f_is_dash_bomb = ( false ) , .f_hidden = ( false ) , .f_flagged = ( false ) } ) ) );
}

static  struct Tile_104   lam881 (    struct Tile_104  dref2614 ) {
    return ( (struct Tile_104) { .f_hidden = ( true ) , .f_is_dash_bomb = ( true ) , .f_flagged = ( false ) } );
}

static  struct TileMap_869   generate_dash_map876 (    size_t  w2600 ,    size_t  h2602 ,    int32_t  bombs2604 ,    enum CAllocator_378  al2606 ) {
    struct TileMap_869  tiles2607 = ( (  mk_dash_tiles868 ) ( (  w2600 ) ,  (  h2602 ) ,  (  al2606 ) ) );
    struct RangeIter_288  temp877 =  into_dash_iter287 ( ( (  to285 ) ( (  from_dash_integral3 ( 1 ) ) ,  (  bombs2604 ) ) ) );
    while (true) {
        struct Maybe_290  __cond878 =  next289 (&temp877);
        if (  __cond878 .tag == 0 ) {
            break;
        }
        int32_t  bomb2609 =  __cond878 .stuff .Maybe_290_Just_s .field0;
        int32_t  temp879;
        int32_t  x2610 = (  temp879 );
        int32_t  temp880;
        int32_t  y2611 = (  temp880 );
        while ( ( true ) ) {
            x2610 = ( (  u32_dash_i32264 ) ( ( (  mod548 ) ( ( (  next_dash_u32795 ) ( ) ) ,  ( (  size_dash_u32261 ) ( (  w2600 ) ) ) ) ) ) );
            y2611 = ( (  u32_dash_i32264 ) ( ( (  mod548 ) ( ( (  next_dash_u32795 ) ( ) ) ,  ( (  size_dash_u32261 ) ( (  h2602 ) ) ) ) ) ) );
            if ( ( ! ( (  elem_dash_get875 ( (  tiles2607 ) , ( ( Tuple2_527_Tuple2 ) ( (  x2610 ) ,  (  y2611 ) ) ) ) ) .f_is_dash_bomb ) ) ) {
                break;
            }
        }
        ( (  map_dash_tile872 ) ( (  tiles2607 ) ,  (  x2610 ) ,  (  y2611 ) ,  (  lam881 ) ) );
    }
    return (  tiles2607 );
}

static  int32_t   count_dash_neighbor_dash_bombs882 (    struct TileMap_869  tilemap2617 ,    int32_t  x2619 ,    int32_t  y2621 ) {
    int32_t  neighbors2622 = (  from_dash_integral3 ( 0 ) );
    struct RangeIter_288  temp883 =  into_dash_iter287 ( ( (  to285 ) ( (  op_dash_sub48 ( (  y2621 ) , (  from_dash_integral3 ( 1 ) ) ) ) ,  (  op_dash_add47 ( (  y2621 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_290  __cond884 =  next289 (&temp883);
        if (  __cond884 .tag == 0 ) {
            break;
        }
        int32_t  yy2624 =  __cond884 .stuff .Maybe_290_Just_s .field0;
        struct RangeIter_288  temp885 =  into_dash_iter287 ( ( (  to285 ) ( (  op_dash_sub48 ( (  x2619 ) , (  from_dash_integral3 ( 1 ) ) ) ) ,  (  op_dash_add47 ( (  x2619 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
        while (true) {
            struct Maybe_290  __cond886 =  next289 (&temp885);
            if (  __cond886 .tag == 0 ) {
                break;
            }
            int32_t  xx2626 =  __cond886 .stuff .Maybe_290_Just_s .field0;
            if ( ( (  elem_dash_get875 ( (  tilemap2617 ) , ( ( Tuple2_527_Tuple2 ) ( (  xx2626 ) ,  (  yy2624 ) ) ) ) ) .f_is_dash_bomb ) ) {
                neighbors2622 = (  op_dash_add47 ( (  neighbors2622 ) , (  from_dash_integral3 ( 1 ) ) ) );
            }
        }
    }
    return (  neighbors2622 );
}

static  enum Unit_160   render_dash_tiles887 (    struct Screen_432 *  screen2629 ,    struct TileMap_869  tilemap2937 ,    struct Tuple2_527  dref2938 ,    enum GameState_866  game_dash_state2942 ) {
    ( (  set_dash_screen_dash_bg850 ) ( (  screen2629 ) ,  ( ( Color_17_Color8 ) ( ( Color8_18_Magenta8 ) ) ) ) );
    struct RangeIter_288  temp888 =  into_dash_iter287 ( ( (  to285 ) ( (  op_dash_neg51 ( (  from_dash_integral3 ( 1 ) ) ) ) ,  ( (  tilemap2937 ) .f_width ) ) ) );
    while (true) {
        struct Maybe_290  __cond889 =  next289 (&temp888);
        if (  __cond889 .tag == 0 ) {
            break;
        }
        int32_t  x2944 =  __cond889 .stuff .Maybe_290_Just_s .field0;
        ( (  put_dash_char858 ) ( (  screen2629 ) ,  ( (  from_dash_charlike1 ) ( ( " " ) ) ) ,  (  op_dash_add47 ( (  x2944 ) , ( dref2938 .field0 ) ) ) ,  (  op_dash_sub48 ( ( dref2938 .field1 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) );
        ( (  put_dash_char858 ) ( (  screen2629 ) ,  ( (  from_dash_charlike1 ) ( ( " " ) ) ) ,  (  op_dash_add47 ( (  x2944 ) , ( dref2938 .field0 ) ) ) ,  (  op_dash_add47 ( ( dref2938 .field1 ) , ( (  tilemap2937 ) .f_height ) ) ) ) );
    }
    struct RangeIter_288  temp890 =  into_dash_iter287 ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  op_dash_sub48 ( ( (  tilemap2937 ) .f_height ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_290  __cond891 =  next289 (&temp890);
        if (  __cond891 .tag == 0 ) {
            break;
        }
        int32_t  y2946 =  __cond891 .stuff .Maybe_290_Just_s .field0;
        ( (  put_dash_char858 ) ( (  screen2629 ) ,  ( (  from_dash_charlike1 ) ( ( " " ) ) ) ,  (  op_dash_sub48 ( ( dref2938 .field0 ) , (  from_dash_integral3 ( 1 ) ) ) ) ,  (  op_dash_add47 ( (  y2946 ) , ( dref2938 .field1 ) ) ) ) );
        ( (  put_dash_char858 ) ( (  screen2629 ) ,  ( (  from_dash_charlike1 ) ( ( " " ) ) ) ,  (  op_dash_add47 ( ( dref2938 .field0 ) , ( (  tilemap2937 ) .f_width ) ) ) ,  (  op_dash_add47 ( (  y2946 ) , ( dref2938 .field1 ) ) ) ) );
    }
    struct Zip_302  temp892 =  into_dash_iter301 ( ( (  zip337 ) ( ( (  tilemap2937 ) .f_tiles ) ,  ( (  from291 ) ( (  from_dash_integral3 ( 0 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_323  __cond893 =  next322 (&temp892);
        if (  __cond893 .tag == 0 ) {
            break;
        }
        struct Tuple2_324  dref2947 =  __cond893 .stuff .Maybe_323_Just_s .field0;
        struct Zip_306  temp894 =  into_dash_iter305 ( ( (  zip339 ) ( ( dref2947 .field0 ) ,  ( (  from291 ) ( (  from_dash_integral3 ( 0 ) ) ) ) ) ) );
        while (true) {
            struct Maybe_328  __cond895 =  next327 (&temp894);
            if (  __cond895 .tag == 0 ) {
                break;
            }
            struct Tuple2_329  dref2950 =  __cond895 .stuff .Maybe_328_Just_s .field0;
            int32_t  x2953 = (  op_dash_add47 ( ( dref2950 .field1 ) , ( dref2938 .field0 ) ) );
            int32_t  y2954 = (  op_dash_add47 ( ( dref2947 .field1 ) , ( dref2938 .field1 ) ) );
            struct Color_17  bg2955 = ( (  eq9 ( ( (  mod549 ) ( (  op_dash_add47 ( ( dref2950 .field1 ) , ( dref2947 .field1 ) ) ) ,  (  from_dash_integral3 ( 2 ) ) ) ) , (  from_dash_integral3 ( 0 ) ) ) ) ? ( ( Color_17_Color8 ) ( ( Color8_18_White8 ) ) ) : ( ( Color_17_Color16 ) ( ( Color16_19_BrightWhite16 ) ) ) );
            if ( ( ( dref2950 .field0 ) .f_hidden ) ) {
                ( (  set_dash_screen_dash_bg850 ) ( (  screen2629 ) ,  (  bg2955 ) ) );
                if ( ( ( dref2950 .field0 ) .f_flagged ) ) {
                    ( (  set_dash_screen_dash_fg849 ) ( (  screen2629 ) ,  ( ( Color_17_Color8 ) ( ( Color8_18_Blue8 ) ) ) ) );
                    ( (  put_dash_char858 ) ( (  screen2629 ) ,  ( (  from_dash_charlike1 ) ( ( "F" ) ) ) ,  (  x2953 ) ,  (  y2954 ) ) );
                } else {
                    ( (  put_dash_char858 ) ( (  screen2629 ) ,  ( (  from_dash_charlike1 ) ( ( " " ) ) ) ,  (  x2953 ) ,  (  y2954 ) ) );
                }
            } else {
                ( (  set_dash_screen_dash_colors851 ) ( (  screen2629 ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ) );
                int32_t  num_dash_bombs2956 = ( (  count_dash_neighbor_dash_bombs882 ) ( (  tilemap2937 ) ,  ( dref2950 .field1 ) ,  ( dref2947 .field1 ) ) );
                if ( (  eq9 ( (  num_dash_bombs2956 ) , (  from_dash_integral3 ( 0 ) ) ) ) ) {
                    ( (  put_dash_char858 ) ( (  screen2629 ) ,  ( (  from_dash_charlike1 ) ( ( " " ) ) ) ,  (  x2953 ) ,  (  y2954 ) ) );
                } else {
                    char  num_dash_bombs_dash_char2957 = ( (  or_dash_fail652 ) ( ( (  head518 ) ( ( (  chars556 ) ( (  num_dash_bombs2956 ) ) ) ) ) ,  ( "impossible:)" ) ) );
                    ( (  put_dash_char858 ) ( (  screen2629 ) ,  (  num_dash_bombs_dash_char2957 ) ,  (  x2953 ) ,  (  y2954 ) ) );
                }
            }
            if ( ( (  eq865 ( (  game_dash_state2942 ) , ( GameState_866_Failed ) ) ) && ( ( dref2950 .field0 ) .f_is_dash_bomb ) ) ) {
                if ( ( ( dref2950 .field0 ) .f_hidden ) ) {
                    ( (  set_dash_screen_dash_fg849 ) ( (  screen2629 ) ,  ( ( Color_17_Color8 ) ( ( Color8_18_Red8 ) ) ) ) );
                    ( (  set_dash_screen_dash_bg850 ) ( (  screen2629 ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ) );
                    ( (  put_dash_char858 ) ( (  screen2629 ) ,  ( (  from_dash_charlike1 ) ( ( "o" ) ) ) ,  (  x2953 ) ,  (  y2954 ) ) );
                } else {
                    ( (  set_dash_screen_dash_fg849 ) ( (  screen2629 ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ) );
                    ( (  set_dash_screen_dash_bg850 ) ( (  screen2629 ) ,  ( ( Color_17_Color8 ) ( ( Color8_18_Red8 ) ) ) ) );
                    ( (  put_dash_char858 ) ( (  screen2629 ) ,  ( (  from_dash_charlike1 ) ( ( "o" ) ) ) ,  (  x2953 ) ,  (  y2954 ) ) );
                }
            }
        }
    }
    return ( Unit_160_Unit );
}

static  bool   lam897 (    struct Tile_104  tile2962 ) {
    return ( ( ( (  tile2962 ) .f_is_dash_bomb ) && ( (  tile2962 ) .f_hidden ) ) || ( ( ! ( (  tile2962 ) .f_is_dash_bomb ) ) && ( ! ( (  tile2962 ) .f_hidden ) ) ) );
}

static  bool   is_dash_game_dash_won896 (    struct TileMap_869  tilemap2960 ) {
    return ( (  all511 ) ( ( (  flatten346 ) ( ( (  tilemap2960 ) .f_tiles ) ) ) ,  (  lam897 ) ) );
}

static  struct Tile_104   lam899 (    struct Tile_104  tile2972 ) {
    struct Tile_104  temp900 = (  tile2972 );
    temp900 .  f_hidden = ( false );
    return ( temp900 );
}

static  bool   uncover_dash_tile898 (    struct TileMap_869  tilemap2965 ,    int32_t  x2967 ,    int32_t  y2969 ) {
    if ( ( ( ( (  cmp40 ( (  x2967 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) || (  cmp40 ( (  x2967 ) , ( (  tilemap2965 ) .f_width ) ) != 0 ) ) || (  cmp40 ( (  y2969 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) ) || (  cmp40 ( (  y2969 ) , ( (  tilemap2965 ) .f_height ) ) != 0 ) ) ) {
        return ( false );
    }
    struct Tile_104  tile2970 = (  elem_dash_get875 ( (  tilemap2965 ) , ( ( Tuple2_527_Tuple2 ) ( (  x2967 ) ,  (  y2969 ) ) ) ) );
    if ( ( ! ( (  tile2970 ) .f_hidden ) ) ) {
        return ( false );
    }
    ( (  map_dash_tile873 ) ( (  tilemap2965 ) ,  (  x2967 ) ,  (  y2969 ) ,  (  lam899 ) ) );
    if ( ( (  tile2970 ) .f_is_dash_bomb ) ) {
        return ( true );
    } else {
        int32_t  nb2973 = ( (  count_dash_neighbor_dash_bombs882 ) ( (  tilemap2965 ) ,  (  x2967 ) ,  (  y2969 ) ) );
        if ( (  eq9 ( (  nb2973 ) , (  from_dash_integral3 ( 0 ) ) ) ) ) {
            struct RangeIter_288  temp901 =  into_dash_iter287 ( ( (  to285 ) ( (  op_dash_sub48 ( (  y2969 ) , (  from_dash_integral3 ( 1 ) ) ) ) ,  (  op_dash_add47 ( (  y2969 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
            while (true) {
                struct Maybe_290  __cond902 =  next289 (&temp901);
                if (  __cond902 .tag == 0 ) {
                    break;
                }
                int32_t  yy2975 =  __cond902 .stuff .Maybe_290_Just_s .field0;
                struct RangeIter_288  temp903 =  into_dash_iter287 ( ( (  to285 ) ( (  op_dash_sub48 ( (  x2967 ) , (  from_dash_integral3 ( 1 ) ) ) ) ,  (  op_dash_add47 ( (  x2967 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
                while (true) {
                    struct Maybe_290  __cond904 =  next289 (&temp903);
                    if (  __cond904 .tag == 0 ) {
                        break;
                    }
                    int32_t  xx2977 =  __cond904 .stuff .Maybe_290_Just_s .field0;
                    ( (  uncover_dash_tile898 ) ( (  tilemap2965 ) ,  (  xx2977 ) ,  (  yy2975 ) ) );
                }
            }
        }
        return ( false );
    }
}

static  struct Tile_104   lam906 (    struct Tile_104  tile2986 ) {
    struct Tile_104  temp907 = (  tile2986 );
    temp907 .  f_flagged = ( ! ( (  tile2986 ) .f_flagged ) );
    return ( temp907 );
}

static  bool   toggle_dash_flag905 (    struct TileMap_869  tilemap2980 ,    int32_t  x2982 ,    int32_t  y2984 ) {
    if ( ( ( ( (  cmp40 ( (  x2982 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) || (  cmp40 ( (  x2982 ) , ( (  tilemap2980 ) .f_width ) ) != 0 ) ) || (  cmp40 ( (  y2984 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) ) || (  cmp40 ( (  y2984 ) , ( (  tilemap2980 ) .f_height ) ) != 0 ) ) ) {
        return ( false );
    }
    ( (  map_dash_tile874 ) ( (  tilemap2980 ) ,  (  x2982 ) ,  (  y2984 ) ,  (  lam906 ) ) );
}

static  struct Tuple2_527   get_dash_board_dash_off908 (    struct Tui_433 *  tui2989 ,    struct TileMap_869  tilemap2991 ) {
    return ( ( Tuple2_527_Tuple2 ) ( (  op_dash_sub48 ( (  op_dash_div50 ( ( (  u32_dash_i32264 ) ( ( ( * (  tui2989 ) ) .f_width ) ) ) , (  from_dash_integral3 ( 2 ) ) ) ) , (  op_dash_div50 ( ( (  tilemap2991 ) .f_width ) , (  from_dash_integral3 ( 2 ) ) ) ) ) ) ,  (  op_dash_sub48 ( (  op_dash_div50 ( ( (  u32_dash_i32264 ) ( ( ( * (  tui2989 ) ) .f_height ) ) ) , (  from_dash_integral3 ( 2 ) ) ) ) , (  op_dash_div50 ( ( (  tilemap2991 ) .f_height ) , (  from_dash_integral3 ( 2 ) ) ) ) ) ) ) );
}

struct funenv774 {
    const char*  (*fun) (  struct env774  ,    struct StrConcat_564  ,    enum CAllocator_378  );
    struct env774 env;
};

struct env909 {
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    struct env774 envinst774;
    ;
    ;
    ;
    ;
    ;
    ;
};

static  enum Unit_160   lam538 (   struct env538 env ,    const char*  filename3010 ) {
    return ( (  free_dash_const_dash_str779 ) ( (  filename3010 ) ,  ( env.al2995 ) ) );
}

static  struct Maybe_533   lam539 (   struct env539 env ,    const char*  filename3012 ) {
    return ( (  try_dash_read_dash_contents786 ) ( (  filename3012 ) ,  ( env.al2995 ) ) );
}

static  struct Stats_545   load_dash_score909 (   struct env909 env ,    enum CAllocator_378  al2995 ) {
    struct StrCase_565  data_dash_dir3007 = ( (  data_dash_home863 ) ( ) );
    struct StrConcat_564  stats_dash_file3008 = ( ( StrConcat_564_StrConcat ) ( (  data_dash_dir3007 ) ,  ( "/kc-minesweeper/stats" ) ) );
    struct funenv774  temp910 = ( (struct funenv774){ .fun = mk_dash_const_dash_str774, .env =  env.envinst774  } );
    struct env538 envinst538 = {
        .al2995 =  al2995 ,
    };
    struct env539 envinst539 = {
        .al2995 =  al2995 ,
    };
    struct Maybe_533  dref3013 = ( (  with537 ) ( ( temp910.fun ( temp910.env ,  (  stats_dash_file3008 ) ,  (  al2995 ) ) ) ,  ( (struct funenv538){ .fun = lam538, .env = envinst538 } ) ,  ( (struct funenv539){ .fun = lam539, .env = envinst539 } ) ) );
    if ( dref3013.tag == Maybe_533_None_t ) {
        return ( (struct Stats_545) { .f_total_dash_wins = (  from_dash_integral4 ( 0 ) ) } );
    }
    else {
        if ( dref3013.tag == Maybe_533_Just_t ) {
            struct LineIter_713  temp911 = ( (  into_dash_iter714 ) ( ( (  lines712 ) ( ( dref3013 .stuff .Maybe_533_Just_s .field0 ) ) ) ) );
            struct LineIter_713 *  it3015 = ( &temp911 );
            uint32_t  total_dash_wins3016 = ( (  i64_dash_u32258 ) ( ( (  or_dash_else653 ) ( ( (  and_dash_maybe532 ) ( ( (  next715 ) ( (  it3015 ) ) ) ,  (  parse_dash_int720 ) ) ) ,  (  from_dash_integral2 ( 0 ) ) ) ) ) );
            return ( (struct Stats_545) { .f_total_dash_wins = (  total_dash_wins3016 ) } );
        }
    }
}

struct funenv790 {
    enum Unit_160  (*fun) (  struct env790  ,    struct StrConcat_564  ,    enum CAllocator_378  );
    struct env790 env;
};

struct funenv777 {
    const char*  (*fun) (  struct env777  ,    struct StrConcat_574  ,    enum CAllocator_378  );
    struct env777 env;
};

struct env912 {
    struct env790 envinst790;
    struct env777 envinst777;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
};

static  enum Unit_160   lam543 (   struct env543 env ,    const char*  filename3026 ) {
    return ( (  free_dash_const_dash_str779 ) ( (  filename3026 ) ,  ( env.al3021 ) ) );
}

static  enum Unit_160   lam544 (   struct env544 env ,    const char*  filename3028 ) {
    return ( (  write_dash_contents788 ) ( (  filename3028 ) ,  ( ( StrConcat_572_StrConcat ) ( ( ( env.stats3019 ) .f_total_dash_wins ) ,  ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) );
}

static  enum Unit_160   save_dash_score912 (   struct env912 env ,    struct Stats_545  stats3019 ,    enum CAllocator_378  al3021 ) {
    struct StrCase_565  data_dash_dir3022 = ( (  data_dash_home863 ) ( ) );
    struct StrConcat_564  minesweeper_dash_data_dash_dir3023 = ( ( StrConcat_564_StrConcat ) ( (  data_dash_dir3022 ) ,  ( "/kc-minesweeper" ) ) );
    struct funenv790  temp913 = ( (struct funenv790){ .fun = mkdir_dash_p790, .env =  env.envinst790  } );
    ( temp913.fun ( temp913.env ,  (  minesweeper_dash_data_dash_dir3023 ) ,  (  al3021 ) ) );
    struct StrConcat_574  stats_dash_file3024 = ( ( StrConcat_574_StrConcat ) ( (  minesweeper_dash_data_dash_dir3023 ) ,  ( "/stats" ) ) );
    struct funenv777  temp914 = ( (struct funenv777){ .fun = mk_dash_const_dash_str777, .env =  env.envinst777  } );
    struct env543 envinst543 = {
        .al3021 =  al3021 ,
    };
    struct env544 envinst544 = {
        .stats3019 =  stats3019 ,
    };
    ( (  with542 ) ( ( temp914.fun ( temp914.env ,  (  stats_dash_file3024 ) ,  (  al3021 ) ) ) ,  ( (struct funenv543){ .fun = lam543, .env = envinst543 } ) ,  ( (struct funenv544){ .fun = lam544, .env = envinst544 } ) ) );
    return ( Unit_160_Unit );
}

struct funenv909 {
    struct Stats_545  (*fun) (  struct env909  ,    enum CAllocator_378  );
    struct env909 env;
};

struct funenv808 {
    struct Tui_433  (*fun) (  struct env808  );
    struct env808 env;
};

struct funenv912 {
    enum Unit_160  (*fun) (  struct env912  ,    struct Stats_545  ,    enum CAllocator_378  );
    struct env912 env;
};

struct funenv847 {
    bool  (*fun) (  struct env847  ,    struct Screen_432 *  );
    struct env847 env;
};

int main(int argc, const char **argv) {
	_global_argc = argc; _global_argv = argv;
    size_t  starting_dash_size1719 = ( (  from_dash_integral8 ( 8 ) ) );
    size_t  growth_dash_factor1720 = ( (  from_dash_integral8 ( 2 ) ) );
    size_t  shrink_dash_factor1721 = ( (  from_dash_integral8 ( 8 ) ) );
    struct env376 envinst376 = {
        .growth_dash_factor1720 =  growth_dash_factor1720 ,
        .starting_dash_size1719 =  starting_dash_size1719 ,
    };
    struct env375 envinst375 = {
        .envinst376 = envinst376 ,
    };
    struct env752 envinst752 = {
        .envinst375 = envinst375 ,
    };
    struct env410 envinst410 = {
        .envinst375 = envinst375 ,
    };
    struct env756 envinst756 = {
        .envinst375 = envinst375 ,
    };
    struct env406 envinst406 = {
        .envinst375 = envinst375 ,
    };
    struct env763 envinst763 = {
        .envinst752 = envinst752 ,
        .envinst406 = envinst406 ,
    };
    struct env409 envinst409 = {
        .envinst410 = envinst410 ,
        .envinst406 = envinst406 ,
    };
    struct env770 envinst770 = {
        .envinst756 = envinst756 ,
        .envinst406 = envinst406 ,
    };
    struct env774 envinst774 = {
        .envinst763 = envinst763 ,
    };
    struct env408 envinst408 = {
        .envinst409 = envinst409 ,
    };
    struct env777 envinst777 = {
        .envinst770 = envinst770 ,
    };
    struct env407 envinst407 = {
        .envinst408 = envinst408 ,
    };
    struct env790 envinst790 = {
        .envinst407 = envinst407 ,
        .envinst406 = envinst406 ,
    };
    ( ( srand ) ( ( (  cast169 ) ( ( ( time ) ( ( (  null_dash_c_dash_ptr248 ) ( ) ) ) ) ) ) ) );
    bool  temp807 = ( true );
    bool *  should_dash_resize2708 = ( &temp807 );
    struct env808 envinst808 = {
        .should_dash_resize2708 =  should_dash_resize2708 ,
    };
    struct env832 envinst832 = {
        .should_dash_resize2708 =  should_dash_resize2708 ,
    };
    struct env847 envinst847 = {
        .envinst832 = envinst832 ,
    };
    struct env909 envinst909 = {
        .envinst774 = envinst774 ,
    };
    struct env912 envinst912 = {
        .envinst790 = envinst790 ,
        .envinst777 = envinst777 ,
    };
    struct Slice_672  args3031 = ( (  get864 ) ( ) );
    size_t  width3032 = (  from_dash_integral8 ( 9 ) );
    size_t  height3033 = (  from_dash_integral8 ( 9 ) );
    int32_t  bombs3034 = (  from_dash_integral3 ( 10 ) );
    struct Slice_672  dref3035 = (  args3031 );
    const char*  __larr__915[3];
    const char*  *dref3036 =  __larr__915;
    if (  deconstruct683 (  dref3035 , &  dref3036 , 3 , (   struct ListSpread_684  ) { .tag = 0 } , NULL , 0 ) ) {
        width3032 = ( (  i64_dash_size259 ) ( ( (  or_dash_fail642 ) ( ( (  parse_dash_int718 ) ( ( dref3036[0] ) ) ) ,  ( "could not parse width" ) ) ) ) );
        height3033 = ( (  i64_dash_size259 ) ( ( (  or_dash_fail642 ) ( ( (  parse_dash_int718 ) ( ( dref3036[1] ) ) ) ,  ( "could not parse height" ) ) ) ) );
        bombs3034 = ( (  i64_dash_i32257 ) ( ( (  or_dash_fail642 ) ( ( (  parse_dash_int718 ) ( ( dref3036[2] ) ) ) ,  ( "could not parse bombs" ) ) ) ) );
    }
    else {
        const char*  *dref3040 = NULL;
        if (  deconstruct683 (  dref3035 , &  dref3040 , 0 , (   struct ListSpread_684  ) { .tag = 0 } , NULL , 0 ) ) {
        }
        else {
            if ( true ) {
                ( (  panic637 ) ( ( "args??" ) ) );
            }
        }
    }
    enum CAllocator_378  al3041 = ( (  idc690 ) ( ) );
    struct funenv909  temp917 = ( (struct funenv909){ .fun = load_dash_score909, .env =  envinst909  } );
    struct Stats_545  stats3042 = ( temp917.fun ( temp917.env ,  (  al3041 ) ) );
    enum GameState_866  game_dash_state3043 = ( GameState_866_InProgress );
    struct TileMap_869  tilemap3044 = ( (  generate_dash_map876 ) ( (  width3032 ) ,  (  height3033 ) ,  (  bombs3034 ) ,  (  al3041 ) ) );
    struct funenv808  temp919 = ( (struct funenv808){ .fun = mk808, .env =  envinst808  } );
    struct Tui_433  temp918 = ( temp919.fun ( temp919.env ) );
    struct Tui_433 *  tui3045 = ( &temp918 );
    enum CAllocator_378  al3046 = ( (  idc690 ) ( ) );
    struct Screen_432  temp920 = ( (  mk_dash_screen833 ) ( (  tui3045 ) ,  (  al3046 ) ) );
    struct Screen_432 *  screen3047 = ( &temp920 );
    bool  running3048 = ( true );
    while ( (  running3048 ) ) {
        bool  needs_dash_redraw3049 = ( false );
        struct FunIter_359  temp921 =  into_dash_iter358 ( ( (  from_dash_function365 ) ( (  read_dash_key826 ) ) ) );
        while (true) {
            struct Maybe_360  __cond922 =  next364 (&temp921);
            if (  __cond922 .tag == 0 ) {
                break;
            }
            struct InputEvent_361  ev3051 =  __cond922 .stuff .Maybe_360_Just_s .field0;
            needs_dash_redraw3049 = ( true );
            struct funenv832  temp923 = ( (struct funenv832){ .fun = update_dash_dimensions832, .env =  envinst832  } );
            ( temp923.fun ( temp923.env ,  (  tui3045 ) ) );
            struct InputEvent_361  dref3052 = (  ev3051 );
            if ( dref3052.tag == InputEvent_361_Key_t && dref3052 .stuff .InputEvent_361_Key_s .field0.tag == Key_362_Char_t ) {
                if ( (  eq14 ( ( dref3052 .stuff .InputEvent_361_Key_s .field0 .stuff .Key_362_Char_s .field0 ) , ( (  from_dash_charlike1 ) ( ( "q" ) ) ) ) ) ) {
                    running3048 = ( false );
                }
                if ( (  eq14 ( ( dref3052 .stuff .InputEvent_361_Key_s .field0 .stuff .Key_362_Char_s .field0 ) , ( (  from_dash_charlike1 ) ( ( "r" ) ) ) ) ) ) {
                    tilemap3044 = ( (  generate_dash_map876 ) ( (  width3032 ) ,  (  height3033 ) ,  (  bombs3034 ) ,  (  al3046 ) ) );
                    game_dash_state3043 = ( GameState_866_InProgress );
                }
            }
            else {
                if ( dref3052.tag == InputEvent_361_Mouse_t ) {
                    int32_t  x3055 = (  op_dash_sub48 ( ( ( dref3052 .stuff .InputEvent_361_Mouse_s .field0 ) .f_x ) , ( (  fst526 ) ( ( (  get_dash_board_dash_off908 ) ( (  tui3045 ) ,  (  tilemap3044 ) ) ) ) ) ) );
                    int32_t  y3056 = (  op_dash_sub48 ( ( ( dref3052 .stuff .InputEvent_361_Mouse_s .field0 ) .f_y ) , ( (  snd530 ) ( ( (  get_dash_board_dash_off908 ) ( (  tui3045 ) ,  (  tilemap3044 ) ) ) ) ) ) );
                    if ( ( (  eq819 ( ( ( dref3052 .stuff .InputEvent_361_Mouse_s .field0 ) .f_button ) , ( MouseButton_119_MouseLeft ) ) ) && ( ( dref3052 .stuff .InputEvent_361_Mouse_s .field0 ) .f_pressed ) ) ) {
                        if ( (  eq865 ( (  game_dash_state3043 ) , ( GameState_866_InProgress ) ) ) ) {
                            if ( ( ( ! ( (  elem_dash_get875 ( (  tilemap3044 ) , ( ( Tuple2_527_Tuple2 ) ( (  x3055 ) ,  (  y3056 ) ) ) ) ) .f_flagged ) ) && ( (  uncover_dash_tile898 ) ( (  tilemap3044 ) ,  (  x3055 ) ,  (  y3056 ) ) ) ) ) {
                                game_dash_state3043 = ( GameState_866_Failed );
                            }
                            if ( ( (  eq865 ( (  game_dash_state3043 ) , ( GameState_866_InProgress ) ) ) && ( (  is_dash_game_dash_won896 ) ( (  tilemap3044 ) ) ) ) ) {
                                game_dash_state3043 = ( GameState_866_Won );
                                stats3042 .f_total_dash_wins = (  op_dash_add52 ( ( (  stats3042 ) .f_total_dash_wins ) , (  from_dash_integral4 ( 1 ) ) ) );
                                struct funenv912  temp924 = ( (struct funenv912){ .fun = save_dash_score912, .env =  envinst912  } );
                                ( temp924.fun ( temp924.env ,  (  stats3042 ) ,  (  al3046 ) ) );
                            }
                        }
                    }
                    if ( ( (  eq819 ( ( ( dref3052 .stuff .InputEvent_361_Mouse_s .field0 ) .f_button ) , ( MouseButton_119_MouseRight ) ) ) && ( ( dref3052 .stuff .InputEvent_361_Mouse_s .field0 ) .f_pressed ) ) ) {
                        if ( (  eq865 ( (  game_dash_state3043 ) , ( GameState_866_InProgress ) ) ) ) {
                            ( (  toggle_dash_flag905 ) ( (  tilemap3044 ) ,  (  x3055 ) ,  (  y3056 ) ) );
                        }
                    }
                }
            }
        }
        struct funenv847  temp925 = ( (struct funenv847){ .fun = resize_dash_screen_dash_if_dash_needed847, .env =  envinst847  } );
        if ( ( temp925.fun ( temp925.env ,  (  screen3047 ) ) ) ) {
            needs_dash_redraw3049 = ( true );
        }
        if ( (  needs_dash_redraw3049 ) ) {
            ( (  clear_dash_screen837 ) ( (  screen3047 ) ) );
            ( (  set_dash_screen_dash_colors851 ) ( (  screen3047 ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ) );
            ( (  fill_dash_default853 ) ( (  screen3047 ) ) );
            ( (  draw_dash_str859 ) ( (  screen3047 ) ,  ( ( StrConcat_577_StrConcat ) ( ( "total wins: " ) ,  ( (  stats3042 ) .f_total_dash_wins ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  (  from_dash_integral3 ( 0 ) ) ) );
            ( (  render_dash_tiles887 ) ( (  screen3047 ) ,  (  tilemap3044 ) ,  ( (  get_dash_board_dash_off908 ) ( (  tui3045 ) ,  (  tilemap3044 ) ) ) ,  (  game_dash_state3043 ) ) );
            ( (  set_dash_screen_dash_colors851 ) ( (  screen3047 ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ) );
            if ( (  eq865 ( (  game_dash_state3043 ) , ( GameState_866_Failed ) ) ) ) {
                ( (  draw_dash_str_dash_center861 ) ( (  screen3047 ) ,  ( "ya failed. restart? (r)" ) ,  (  op_dash_div50 ( ( (  u32_dash_i32264 ) ( ( ( * (  tui3045 ) ) .f_width ) ) ) , (  from_dash_integral3 ( 2 ) ) ) ) ,  (  op_dash_add47 ( (  op_dash_add47 ( ( (  tilemap3044 ) .f_height ) , ( (  snd530 ) ( ( (  get_dash_board_dash_off908 ) ( (  tui3045 ) ,  (  tilemap3044 ) ) ) ) ) ) ) , (  from_dash_integral3 ( 2 ) ) ) ) ) );
            } else {
                if ( (  eq865 ( (  game_dash_state3043 ) , ( GameState_866_Won ) ) ) ) {
                    ( (  draw_dash_str_dash_center861 ) ( (  screen3047 ) ,  ( "ya won. quit? (q)" ) ,  (  op_dash_div50 ( ( (  u32_dash_i32264 ) ( ( ( * (  tui3045 ) ) .f_width ) ) ) , (  from_dash_integral3 ( 2 ) ) ) ) ,  (  op_dash_add47 ( (  op_dash_add47 ( ( (  tilemap3044 ) .f_height ) , ( (  snd530 ) ( ( (  get_dash_board_dash_off908 ) ( (  tui3045 ) ,  (  tilemap3044 ) ) ) ) ) ) ) , (  from_dash_integral3 ( 2 ) ) ) ) ) );
                }
            }
            ( (  render_dash_screen841 ) ( (  screen3047 ) ) );
        }
        ( (  sync814 ) ( (  tui3045 ) ) );
    }
    ( (  free_dash_screen836 ) ( (  screen3047 ) ) );
    ( (  deinit818 ) ( (  tui3045 ) ) );
}
