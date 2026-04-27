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

static  void *   cast_dash_ptr29 (    int32_t *  p496 ) {
    return ( (void * ) (  p496 ) );
}

static  size_t   size_dash_of30 (    int32_t  x487 ) {
    return ( sizeof( (  x487 ) ) );
}

static  int32_t   zeroed27 (  ) {
    int32_t  temp28;
    int32_t  x503 = (  temp28 );
    ( ( memset ) ( ( (  cast_dash_ptr29 ) ( ( & (  x503 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of30 ) ( (  x503 ) ) ) ) );
    return (  x503 );
}

static  enum Color8_18 *   cast31 (    int32_t *  x493 ) {
    return ( (enum Color8_18 * ) (  x493 ) );
}

static  int32_t   cast_dash_on_dash_zeroed25 (    enum Color8_18  x506 ) {
    int32_t  temp26 = ( (  zeroed27 ) ( ) );
    int32_t *  y507 = ( &temp26 );
    enum Color8_18 *  yp508 = ( (  cast31 ) ( (  y507 ) ) );
    (*  yp508 ) = (  x506 );
    return ( * (  y507 ) );
}

static  bool   eq24 (    enum Color8_18  l2066 ,    enum Color8_18  r2068 ) {
    return (  eq9 ( ( ( (  cast_dash_on_dash_zeroed25 ) ( (  l2066 ) ) ) ) , ( (  cast_dash_on_dash_zeroed25 ) ( (  r2068 ) ) ) ) );
}

static  enum Color16_19 *   cast35 (    int32_t *  x493 ) {
    return ( (enum Color16_19 * ) (  x493 ) );
}

static  int32_t   cast_dash_on_dash_zeroed33 (    enum Color16_19  x506 ) {
    int32_t  temp34 = ( (  zeroed27 ) ( ) );
    int32_t *  y507 = ( &temp34 );
    enum Color16_19 *  yp508 = ( (  cast35 ) ( (  y507 ) ) );
    (*  yp508 ) = (  x506 );
    return ( * (  y507 ) );
}

static  bool   eq32 (    enum Color16_19  l2072 ,    enum Color16_19  r2074 ) {
    return (  eq9 ( ( ( (  cast_dash_on_dash_zeroed33 ) ( (  l2072 ) ) ) ) , ( (  cast_dash_on_dash_zeroed33 ) ( (  r2074 ) ) ) ) );
}

static  bool   eq36 (    struct RGB_20  l2102 ,    struct RGB_20  r2104 ) {
    return ( ( (  eq11 ( ( (  l2102 ) .f_r ) , ( (  r2104 ) .f_r ) ) ) && (  eq11 ( ( (  l2102 ) .f_g ) , ( (  r2104 ) .f_g ) ) ) ) && (  eq11 ( ( (  l2102 ) .f_b ) , ( (  r2104 ) .f_b ) ) ) );
}

static  bool   eq22 (    struct Color_17  l2125 ,    struct Color_17  r2127 ) {
    return ( {  struct Tuple2_23  dref2128 = ( ( Tuple2_23_Tuple2 ) ( (  l2125 ) ,  (  r2127 ) ) ) ; dref2128 .field0.tag == Color_17_ColorDefault_t && dref2128 .field1.tag == Color_17_ColorDefault_t ? ( true ) : dref2128 .field0.tag == Color_17_Color8_t && dref2128 .field1.tag == Color_17_Color8_t ? (  eq24 ( ( dref2128 .field0 .stuff .Color_17_Color8_s .field0 ) , ( dref2128 .field1 .stuff .Color_17_Color8_s .field0 ) ) ) : dref2128 .field0.tag == Color_17_Color16_t && dref2128 .field1.tag == Color_17_Color16_t ? (  eq32 ( ( dref2128 .field0 .stuff .Color_17_Color16_s .field0 ) , ( dref2128 .field1 .stuff .Color_17_Color16_s .field0 ) ) ) : dref2128 .field0.tag == Color_17_Color256_t && dref2128 .field1.tag == Color_17_Color256_t ? (  eq11 ( ( dref2128 .field0 .stuff .Color_17_Color256_s .field0 ) , ( dref2128 .field1 .stuff .Color_17_Color256_s .field0 ) ) ) : dref2128 .field0.tag == Color_17_ColorRGB_t && dref2128 .field1.tag == Color_17_ColorRGB_t ? (  eq36 ( ( dref2128 .field0 .stuff .Color_17_ColorRGB_s .field0 ) , ( dref2128 .field1 .stuff .Color_17_ColorRGB_s .field0 ) ) ) : ( false ) ; } );
}

static  bool   eq21 (    struct Cell_16  l2812 ,    struct Cell_16  r2814 ) {
    if ( ( !  eq14 ( ( (  l2812 ) .f_c ) , ( (  r2814 ) .f_c ) ) ) ) {
        return ( false );
    }
    if ( ( !  eq22 ( ( (  l2812 ) .f_fg ) , ( (  r2814 ) .f_fg ) ) ) ) {
        return ( false );
    }
    if ( ( !  eq22 ( ( (  l2812 ) .f_bg ) , ( (  r2814 ) .f_bg ) ) ) ) {
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

static  struct timespec   undefined108 (  ) {
    struct timespec  temp109;
    return (  temp109 );
}

struct Array_112 {
    uint8_t _arr [32];
};

struct Termios_111 {
    uint32_t  f_c_dash_iflag;
    uint32_t  f_c_dash_oflag;
    uint32_t  f_c_dash_cflag;
    uint32_t  f_c_dash_lflag;
    uint8_t  f_c_dash_line;
    struct Array_112  f_c_dash_cc;
    uint32_t  f_c_dash_ispeed;
    uint32_t  f_c_dash_ospeed;
};

static  struct Termios_111   undefined110 (  ) {
    struct Termios_111  temp113;
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

static  struct Stat_75   undefined121 (  ) {
    struct Stat_75  temp122;
    return (  temp122 );
}

static  bool   undefined123 (  ) {
    bool  temp124;
    return (  temp124 );
}

static  struct Cell_16 *   undefined125 (  ) {
    struct Cell_16 *  temp126;
    return (  temp126 );
}

static  const char* *   offset_dash_ptr127 (    const char* *  x480 ,    int64_t  count482 ) {
    const char*  temp128;
    return ( (const char* * ) ( ( (void*) (  x480 ) ) + (  op_dash_mul45 ( (  count482 ) , ( (int64_t ) ( sizeof( ( (  temp128 ) ) ) ) ) ) ) ) );
}

static  char *   offset_dash_ptr129 (    char *  x480 ,    int64_t  count482 ) {
    char  temp130;
    return ( (char * ) ( ( (void*) (  x480 ) ) + (  op_dash_mul45 ( (  count482 ) , ( (int64_t ) ( sizeof( ( (  temp130 ) ) ) ) ) ) ) ) );
}

static  struct Slice_103 *   offset_dash_ptr131 (    struct Slice_103 *  x480 ,    int64_t  count482 ) {
    struct Slice_103  temp132;
    return ( (struct Slice_103 * ) ( ( (void*) (  x480 ) ) + (  op_dash_mul45 ( (  count482 ) , ( (int64_t ) ( sizeof( ( (  temp132 ) ) ) ) ) ) ) ) );
}

static  struct Tile_104 *   offset_dash_ptr133 (    struct Tile_104 *  x480 ,    int64_t  count482 ) {
    struct Tile_104  temp134;
    return ( (struct Tile_104 * ) ( ( (void*) (  x480 ) ) + (  op_dash_mul45 ( (  count482 ) , ( (int64_t ) ( sizeof( ( (  temp134 ) ) ) ) ) ) ) ) );
}

static  uint8_t *   offset_dash_ptr135 (    uint8_t *  x480 ,    int64_t  count482 ) {
    uint8_t  temp136;
    return ( (uint8_t * ) ( ( (void*) (  x480 ) ) + (  op_dash_mul45 ( (  count482 ) , ( (int64_t ) ( sizeof( ( (  temp136 ) ) ) ) ) ) ) ) );
}

static  uint32_t *   offset_dash_ptr137 (    uint32_t *  x480 ,    int64_t  count482 ) {
    uint32_t  temp138;
    return ( (uint32_t * ) ( ( (void*) (  x480 ) ) + (  op_dash_mul45 ( (  count482 ) , ( (int64_t ) ( sizeof( ( (  temp138 ) ) ) ) ) ) ) ) );
}

static  struct Cell_16 *   offset_dash_ptr139 (    struct Cell_16 *  x480 ,    int64_t  count482 ) {
    struct Cell_16  temp140;
    return ( (struct Cell_16 * ) ( ( (void*) (  x480 ) ) + (  op_dash_mul45 ( (  count482 ) , ( (int64_t ) ( sizeof( ( (  temp140 ) ) ) ) ) ) ) ) );
}

static  int32_t *   offset_dash_ptr141 (    int32_t *  x480 ,    int64_t  count482 ) {
    int32_t  temp142;
    return ( (int32_t * ) ( ( (void*) (  x480 ) ) + (  op_dash_mul45 ( (  count482 ) , ( (int64_t ) ( sizeof( ( (  temp142 ) ) ) ) ) ) ) ) );
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

static  size_t   size_dash_of155 (    void *  x487 ) {
    return ( sizeof( (  x487 ) ) );
}

enum Unit_157 {
    Unit_157_Unit,
};

static  size_t   size_dash_of156 (    enum Unit_157 *  x487 ) {
    return ( sizeof( (  x487 ) ) );
}

static  size_t   size_dash_of158 (    char  x487 ) {
    return ( sizeof( (  x487 ) ) );
}

static  size_t   size_dash_of159 (    FILE *  x487 ) {
    return ( sizeof( (  x487 ) ) );
}

static  size_t   size_dash_of160 (    char *  x487 ) {
    return ( sizeof( (  x487 ) ) );
}

struct Winsize_162 {
    uint16_t  f_ws_dash_row;
    uint16_t  f_ws_dash_col;
    uint16_t  f_ws_dash_xpixel;
    uint16_t  f_ws_dash_ypixel;
};

static  size_t   size_dash_of161 (    struct Winsize_162  x487 ) {
    return ( sizeof( (  x487 ) ) );
}

static  size_t   size_dash_of163 (    uint32_t  x487 ) {
    return ( sizeof( (  x487 ) ) );
}

static  size_t   size_dash_of164 (    size_t  x487 ) {
    return ( sizeof( (  x487 ) ) );
}

static  size_t   size_dash_of165 (    int64_t  x487 ) {
    return ( sizeof( (  x487 ) ) );
}

struct Array_167 {
    char _arr [32];
};

static  size_t   size_dash_of166 (    struct Array_167  x487 ) {
    return ( sizeof( (  x487 ) ) );
}

static  size_t   size_dash_of168 (    struct timespec *  x487 ) {
    return ( sizeof( (  x487 ) ) );
}

static  uint32_t   cast169 (    int32_t  x493 ) {
    return ( (uint32_t ) (  x493 ) );
}

static  char *   cast170 (    const char*  x493 ) {
    return ( (char * ) (  x493 ) );
}

static  char *   cast171 (    int32_t *  x493 ) {
    return ( (char * ) (  x493 ) );
}

static  enum Unit_157 *   cast172 (    const char*  x493 ) {
    return ( (enum Unit_157 * ) (  x493 ) );
}

static  const char*   cast173 (    char *  x493 ) {
    return ( (const char* ) (  x493 ) );
}

static  int32_t   cast174 (    uint32_t  x493 ) {
    return ( (int32_t ) (  x493 ) );
}

static  uint16_t *   cast175 (    uint32_t *  x493 ) {
    return ( (uint16_t * ) (  x493 ) );
}

static  uint32_t *   cast176 (    size_t *  x493 ) {
    return ( (uint32_t * ) (  x493 ) );
}

static  char   cast177 (    int32_t  x493 ) {
    return ( (char ) (  x493 ) );
}

static  uint8_t *   cast178 (    int64_t *  x493 ) {
    return ( (uint8_t * ) (  x493 ) );
}

static  uint8_t   cast179 (    char  x493 ) {
    return ( (uint8_t ) (  x493 ) );
}

static  char *   cast180 (    struct Array_167 *  x493 ) {
    return ( (char * ) (  x493 ) );
}

static  enum MouseButton_119 *   cast181 (    uint32_t *  x493 ) {
    return ( (enum MouseButton_119 * ) (  x493 ) );
}

static  char   cast182 (    uint32_t  x493 ) {
    return ( (char ) (  x493 ) );
}

static  uint8_t *   cast183 (    int32_t *  x493 ) {
    return ( (uint8_t * ) (  x493 ) );
}

static  void *   cast_dash_ptr184 (    void * *  p496 ) {
    return ( (void * ) (  p496 ) );
}

static  void *   cast_dash_ptr185 (    enum Unit_157 * *  p496 ) {
    return ( (void * ) (  p496 ) );
}

static  void *   cast_dash_ptr186 (    enum Unit_157 *  p496 ) {
    return ( (void * ) (  p496 ) );
}

static  char *   cast_dash_ptr187 (    void *  p496 ) {
    return ( (char * ) (  p496 ) );
}

static  void *   cast_dash_ptr188 (    char *  p496 ) {
    return ( (void * ) (  p496 ) );
}

static  void *   cast_dash_ptr189 (    FILE * *  p496 ) {
    return ( (void * ) (  p496 ) );
}

static  void *   cast_dash_ptr190 (    char * *  p496 ) {
    return ( (void * ) (  p496 ) );
}

static  struct Slice_103 *   cast_dash_ptr191 (    void *  p496 ) {
    return ( (struct Slice_103 * ) (  p496 ) );
}

static  struct Tile_104 *   cast_dash_ptr192 (    void *  p496 ) {
    return ( (struct Tile_104 * ) (  p496 ) );
}

static  void *   cast_dash_ptr193 (    struct Winsize_162 *  p496 ) {
    return ( (void * ) (  p496 ) );
}

static  void *   cast_dash_ptr194 (    uint32_t *  p496 ) {
    return ( (void * ) (  p496 ) );
}

static  struct termios *   cast_dash_ptr195 (    struct Termios_111 *  p496 ) {
    return ( (struct termios * ) (  p496 ) );
}

static  uint8_t *   cast_dash_ptr196 (    struct Array_112 *  p496 ) {
    return ( (uint8_t * ) (  p496 ) );
}

static  uint32_t *   cast_dash_ptr197 (    struct Array_63 *  p496 ) {
    return ( (uint32_t * ) (  p496 ) );
}

static  uint32_t *   cast_dash_ptr198 (    struct Array_66 *  p496 ) {
    return ( (uint32_t * ) (  p496 ) );
}

static  uint32_t *   cast_dash_ptr199 (    struct Array_69 *  p496 ) {
    return ( (uint32_t * ) (  p496 ) );
}

static  struct Cell_16 *   cast_dash_ptr200 (    void *  p496 ) {
    return ( (struct Cell_16 * ) (  p496 ) );
}

static  void *   cast_dash_ptr201 (    size_t *  p496 ) {
    return ( (void * ) (  p496 ) );
}

struct Pollfd_203 {
    int32_t  f_fd;
    uint16_t  f_events;
    uint16_t  f_revents;
};

static  struct pollfd *   cast_dash_ptr202 (    struct Pollfd_203 *  p496 ) {
    return ( (struct pollfd * ) (  p496 ) );
}

static  void *   cast_dash_ptr204 (    int64_t *  p496 ) {
    return ( (void * ) (  p496 ) );
}

static  char *   cast_dash_ptr205 (    struct Array_167 *  p496 ) {
    return ( (char * ) (  p496 ) );
}

static  void *   cast_dash_ptr206 (    struct Array_167 *  p496 ) {
    return ( (void * ) (  p496 ) );
}

static  int32_t *   cast_dash_ptr207 (    struct Array_72 *  p496 ) {
    return ( (int32_t * ) (  p496 ) );
}

static  void *   cast_dash_ptr208 (    struct timespec * *  p496 ) {
    return ( (void * ) (  p496 ) );
}

static  void *   cast_dash_ptr209 (    struct Cell_16 *  p496 ) {
    return ( (void * ) (  p496 ) );
}

static  void *   zeroed210 (  ) {
    void *  temp211;
    void *  x503 = (  temp211 );
    ( ( memset ) ( ( (  cast_dash_ptr184 ) ( ( & (  x503 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of155 ) ( (  x503 ) ) ) ) );
    return (  x503 );
}

static  enum Unit_157 *   zeroed212 (  ) {
    enum Unit_157 *  temp213;
    enum Unit_157 *  x503 = (  temp213 );
    ( ( memset ) ( ( (  cast_dash_ptr185 ) ( ( & (  x503 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of156 ) ( (  x503 ) ) ) ) );
    return (  x503 );
}

static  char   zeroed214 (  ) {
    char  temp215;
    char  x503 = (  temp215 );
    ( ( memset ) ( ( (  cast_dash_ptr188 ) ( ( & (  x503 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of158 ) ( (  x503 ) ) ) ) );
    return (  x503 );
}

static  FILE *   zeroed216 (  ) {
    FILE *  temp217;
    FILE *  x503 = (  temp217 );
    ( ( memset ) ( ( (  cast_dash_ptr189 ) ( ( & (  x503 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of159 ) ( (  x503 ) ) ) ) );
    return (  x503 );
}

static  char *   zeroed218 (  ) {
    char *  temp219;
    char *  x503 = (  temp219 );
    ( ( memset ) ( ( (  cast_dash_ptr190 ) ( ( & (  x503 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of160 ) ( (  x503 ) ) ) ) );
    return (  x503 );
}

static  struct Winsize_162   zeroed220 (  ) {
    struct Winsize_162  temp221;
    struct Winsize_162  x503 = (  temp221 );
    ( ( memset ) ( ( (  cast_dash_ptr193 ) ( ( & (  x503 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of161 ) ( (  x503 ) ) ) ) );
    return (  x503 );
}

static  uint32_t   zeroed222 (  ) {
    uint32_t  temp223;
    uint32_t  x503 = (  temp223 );
    ( ( memset ) ( ( (  cast_dash_ptr194 ) ( ( & (  x503 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of163 ) ( (  x503 ) ) ) ) );
    return (  x503 );
}

static  size_t   zeroed224 (  ) {
    size_t  temp225;
    size_t  x503 = (  temp225 );
    ( ( memset ) ( ( (  cast_dash_ptr201 ) ( ( & (  x503 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of164 ) ( (  x503 ) ) ) ) );
    return (  x503 );
}

static  int64_t   zeroed226 (  ) {
    int64_t  temp227;
    int64_t  x503 = (  temp227 );
    ( ( memset ) ( ( (  cast_dash_ptr204 ) ( ( & (  x503 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of165 ) ( (  x503 ) ) ) ) );
    return (  x503 );
}

static  struct Array_167   zeroed228 (  ) {
    struct Array_167  temp229;
    struct Array_167  x503 = (  temp229 );
    ( ( memset ) ( ( (  cast_dash_ptr206 ) ( ( & (  x503 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of166 ) ( (  x503 ) ) ) ) );
    return (  x503 );
}

static  struct timespec *   zeroed230 (  ) {
    struct timespec *  temp231;
    struct timespec *  x503 = (  temp231 );
    ( ( memset ) ( ( (  cast_dash_ptr208 ) ( ( & (  x503 ) ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_of168 ) ( (  x503 ) ) ) ) );
    return (  x503 );
}

static  int32_t   cast_dash_on_dash_zeroed232 (    char  x506 ) {
    int32_t  temp233 = ( (  zeroed27 ) ( ) );
    int32_t *  y507 = ( &temp233 );
    char *  yp508 = ( (  cast171 ) ( (  y507 ) ) );
    (*  yp508 ) = (  x506 );
    return ( * (  y507 ) );
}

static  uint32_t   cast_dash_on_dash_zeroed234 (    uint16_t  x506 ) {
    uint32_t  temp235 = ( (  zeroed222 ) ( ) );
    uint32_t *  y507 = ( &temp235 );
    uint16_t *  yp508 = ( (  cast175 ) ( (  y507 ) ) );
    (*  yp508 ) = (  x506 );
    return ( * (  y507 ) );
}

static  size_t   cast_dash_on_dash_zeroed236 (    uint32_t  x506 ) {
    size_t  temp237 = ( (  zeroed224 ) ( ) );
    size_t *  y507 = ( &temp237 );
    uint32_t *  yp508 = ( (  cast176 ) ( (  y507 ) ) );
    (*  yp508 ) = (  x506 );
    return ( * (  y507 ) );
}

static  int64_t   cast_dash_on_dash_zeroed238 (    uint8_t  x506 ) {
    int64_t  temp239 = ( (  zeroed226 ) ( ) );
    int64_t *  y507 = ( &temp239 );
    uint8_t *  yp508 = ( (  cast178 ) ( (  y507 ) ) );
    (*  yp508 ) = (  x506 );
    return ( * (  y507 ) );
}

static  uint32_t   cast_dash_on_dash_zeroed240 (    enum MouseButton_119  x506 ) {
    uint32_t  temp241 = ( (  zeroed222 ) ( ) );
    uint32_t *  y507 = ( &temp241 );
    enum MouseButton_119 *  yp508 = ( (  cast181 ) ( (  y507 ) ) );
    (*  yp508 ) = (  x506 );
    return ( * (  y507 ) );
}

static  int32_t   cast_dash_on_dash_zeroed242 (    uint8_t  x506 ) {
    int32_t  temp243 = ( (  zeroed27 ) ( ) );
    int32_t *  y507 = ( &temp243 );
    uint8_t *  yp508 = ( (  cast183 ) ( (  y507 ) ) );
    (*  yp508 ) = (  x506 );
    return ( * (  y507 ) );
}

static  enum Unit_157 *   null_dash_ptr244 (  ) {
    return ( (  zeroed212 ) ( ) );
}

static  FILE *   null_dash_ptr245 (  ) {
    return ( (  zeroed216 ) ( ) );
}

static  char *   null_dash_ptr246 (  ) {
    return ( (  zeroed218 ) ( ) );
}

static  struct timespec *   null_dash_ptr247 (  ) {
    return ( (  zeroed230 ) ( ) );
}

static  void *   null_dash_c_dash_ptr248 (  ) {
    return ( (  zeroed210 ) ( ) );
}

static  bool   is_dash_ptr_dash_null249 (    FILE *  p513 ) {
    return ( (  p513 ) == ( (  null_dash_ptr245 ) ( ) ) );
}

static  bool   ptr_dash_eq250 (    enum Unit_157 *  l519 ,    enum Unit_157 *  r521 ) {
    return ( (  l519 ) == (  r521 ) );
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

static  struct Maybe_252   from_dash_nullable_dash_c_dash_str251 (    const char*  s524 ) {
    if ( ( (  ptr_dash_eq250 ) ( ( (  cast172 ) ( (  s524 ) ) ) ,  ( ( (  null_dash_ptr244 ) ( ) ) ) ) ) ) {
        return ( (struct Maybe_252) { .tag = Maybe_252_None_t } );
    } else {
        return ( ( Maybe_252_Just ) ( (  s524 ) ) );
    }
}

static  int64_t   size_dash_i64253 (    size_t  x527 ) {
    return ( (int64_t ) (  x527 ) );
}

static  uint32_t   i32_dash_u32254 (    int32_t  x533 ) {
    return ( (uint32_t ) (  x533 ) );
}

static  int64_t   i32_dash_i64255 (    int32_t  x536 ) {
    return ( (int64_t ) (  x536 ) );
}

static  size_t   i32_dash_size256 (    int32_t  x539 ) {
    return ( (size_t ) ( (int64_t ) (  x539 ) ) );
}

static  int32_t   i64_dash_i32257 (    int64_t  x545 ) {
    return ( (int32_t ) (  x545 ) );
}

static  uint32_t   i64_dash_u32258 (    int64_t  x548 ) {
    return ( (uint32_t ) (  x548 ) );
}

static  size_t   i64_dash_size259 (    int64_t  x551 ) {
    return ( (size_t ) (  x551 ) );
}

static  int32_t   size_dash_i32260 (    size_t  x554 ) {
    return ( (int32_t ) (  x554 ) );
}

static  uint32_t   size_dash_u32261 (    size_t  x557 ) {
    return ( (uint32_t ) (  x557 ) );
}

static  uint32_t   u16_dash_u32262 (    uint16_t  x560 ) {
    return ( (  cast_dash_on_dash_zeroed234 ) ( (  x560 ) ) );
}

static  size_t   u32_dash_size263 (    uint32_t  x566 ) {
    return ( (  cast_dash_on_dash_zeroed236 ) ( (  x566 ) ) );
}

static  int32_t   u32_dash_i32264 (    uint32_t  x575 ) {
    return ( (  cast174 ) ( (  x575 ) ) );
}

static  int64_t   u8_dash_i64265 (    uint8_t  x581 ) {
    return ( (  cast_dash_on_dash_zeroed238 ) ( (  x581 ) ) );
}

static  int32_t   u8_dash_i32266 (    uint8_t  x584 ) {
    return ( (  cast_dash_on_dash_zeroed242 ) ( (  x584 ) ) );
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

static  struct Scanner_268   into_dash_iter271 (    struct Scanner_268  self2652 ) {
    return (  self2652 );
}

static  struct Scanner_268   into_dash_iter267 (    struct Scanner_268 *  self590 ) {
    return ( (  into_dash_iter271 ) ( ( * (  self590 ) ) ) );
}

enum EmptyIter_273 {
    EmptyIter_273_EmptyIter,
};

static  enum EmptyIter_273   nil272 (  ) {
    return ( EmptyIter_273_EmptyIter );
}

static  enum EmptyIter_273   into_dash_iter274 (    enum EmptyIter_273  self595 ) {
    return (  self595 );
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

static  struct Maybe_276   next275 (    enum EmptyIter_273 *  dref597 ) {
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

static  struct Map_278   into_dash_iter277 (    struct Map_278  self601 ) {
    return (  self601 );
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

static  struct Maybe_276   next282 (    struct ConstStrIter_279 *  self1119 ) {
    if ( (  cmp39 ( ( ( * (  self1119 ) ) .f_i ) , ( (  i32_dash_size256 ) ( ( ( strlen ) ( ( ( * (  self1119 ) ) .f_ogstr ) ) ) ) ) ) != 0 ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    char *  char_dash_ptr1120 = ( ( (  cast170 ) ( ( ( * (  self1119 ) ) .f_ogstr ) ) ) );
    char  c1121 = ( * ( (  offset_dash_ptr129 ) ( (  char_dash_ptr1120 ) ,  ( (  size_dash_i64253 ) ( ( ( * (  self1119 ) ) .f_i ) ) ) ) ) );
    (*  self1119 ) .f_i = (  op_dash_add58 ( ( ( * (  self1119 ) ) .f_i ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_276_Just ) ( (  c1121 ) ) );
}

static  struct Maybe_281   next280 (    struct Map_278 *  dref603 ) {
    struct Maybe_276  dref606 = ( (  next282 ) ( ( & ( (* dref603 ) .field0 ) ) ) );
    if ( dref606.tag == Maybe_276_None_t ) {
        return ( (struct Maybe_281) { .tag = Maybe_281_None_t } );
    }
    else {
        if ( dref606.tag == Maybe_276_Just_t ) {
            return ( ( Maybe_281_Just ) ( ( ( (* dref603 ) .field1 ) ( ( dref606 .stuff .Maybe_276_Just_s .field0 ) ) ) ) );
        }
    }
}

static  struct ConstStrIter_279   into_dash_iter284 (    const char*  self1113 ) {
    return ( (struct ConstStrIter_279) { .f_ogstr = (  self1113 ) , .f_i = (  from_dash_integral8 ( 0 ) ) } );
}

static  struct Map_278   map283 (    const char*  iterable610 ,    uint32_t (*  fun612 )(    char  ) ) {
    struct ConstStrIter_279  it613 = ( (  into_dash_iter284 ) ( (  iterable610 ) ) );
    return ( ( Map_278_Map ) ( (  it613 ) ,  (  fun612 ) ) );
}

struct Range_286 {
    int32_t  field0;
    int32_t  field1;
};

static struct Range_286 Range_286_Range (  int32_t  field0 ,  int32_t  field1 ) {
    return ( struct Range_286 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct Range_286   to285 (    int32_t  from679 ,    int32_t  to681 ) {
    return ( ( Range_286_Range ) ( (  from679 ) ,  (  to681 ) ) );
}

struct RangeIter_288 {
    struct Range_286  field0;
    int32_t  field1;
};

static struct RangeIter_288 RangeIter_288_RangeIter (  struct Range_286  field0 ,  int32_t  field1 ) {
    return ( struct RangeIter_288 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct RangeIter_288   into_dash_iter287 (    struct Range_286  dref688 ) {
    return ( ( RangeIter_288_RangeIter ) ( ( ( Range_286_Range ) ( ( dref688 .field0 ) ,  ( dref688 .field1 ) ) ) ,  ( dref688 .field0 ) ) );
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

static  struct Maybe_290   next289 (    struct RangeIter_288 *  self696 ) {
    struct RangeIter_288  dref697 = ( * (  self696 ) );
    if ( true ) {
        if ( (  cmp40 ( ( dref697 .field1 ) , ( dref697 .field0 .field1 ) ) == 2 ) ) {
            return ( (struct Maybe_290) { .tag = Maybe_290_None_t } );
        }
        struct Maybe_290  x701 = ( ( Maybe_290_Just ) ( ( dref697 .field1 ) ) );
        (*  self696 ) = ( ( RangeIter_288_RangeIter ) ( ( ( Range_286_Range ) ( ( dref697 .field0 .field0 ) ,  ( dref697 .field0 .field1 ) ) ) ,  (  op_dash_add47 ( ( dref697 .field1 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) );
        return (  x701 );
    }
}

struct FromIter_292 {
    int32_t  f_from;
};

static  struct FromIter_292   from291 (    int32_t  f705 ) {
    return ( (struct FromIter_292) { .f_from = (  f705 ) } );
}

static  struct FromIter_292   into_dash_iter293 (    struct FromIter_292  it708 ) {
    return (  it708 );
}

static  struct Maybe_290   next294 (    struct FromIter_292 *  dref710 ) {
    int32_t  v712 = ( ( (* dref710 ) ) .f_from );
    (* dref710 ) .f_from = (  op_dash_add47 ( ( ( (* dref710 ) ) .f_from ) , (  from_dash_integral3 ( 1 ) ) ) );
    return ( ( Maybe_290_Just ) ( (  v712 ) ) );
}

struct Zip_296 {
    struct SliceIter_269  f_left_dash_it;
    struct FromIter_292  f_right_dash_it;
};

static  struct Zip_296   into_dash_iter295 (    struct Zip_296  self716 ) {
    return (  self716 );
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

static  struct Zip_298   into_dash_iter297 (    struct Zip_298  self716 ) {
    return (  self716 );
}

struct SliceIter_303 {
    struct Slice_103  f_slice;
    size_t  f_current_dash_offset;
};

struct Zip_302 {
    struct SliceIter_303  f_left_dash_it;
    struct FromIter_292  f_right_dash_it;
};

static  struct Zip_302   into_dash_iter301 (    struct Zip_302  self716 ) {
    return (  self716 );
}

struct Slice_307 {
    struct Slice_103 *  f_ptr;
    size_t  f_count;
};

struct SliceIter_306 {
    struct Slice_307  f_slice;
    size_t  f_current_dash_offset;
};

struct Zip_305 {
    struct SliceIter_306  f_left_dash_it;
    struct FromIter_292  f_right_dash_it;
};

static  struct Zip_305   into_dash_iter304 (    struct Zip_305  self716 ) {
    return (  self716 );
}

struct Zip_309 {
    struct ConstStrIter_279  f_left_dash_it;
    struct FromIter_292  f_right_dash_it;
};

static  struct Zip_309   into_dash_iter308 (    struct Zip_309  self716 ) {
    return (  self716 );
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

static  struct Maybe_276   next313 (    struct SliceIter_269 *  self1514 ) {
    size_t  off1515 = ( ( * (  self1514 ) ) .f_current_dash_offset );
    if ( (  cmp39 ( (  op_dash_add58 ( (  off1515 ) , (  from_dash_integral8 ( 1 ) ) ) ) , ( ( ( * (  self1514 ) ) .f_slice ) .f_count ) ) == 2 ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    char  elem1516 = ( * ( (  offset_dash_ptr129 ) ( ( ( ( * (  self1514 ) ) .f_slice ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  off1515 ) ) ) ) ) );
    (*  self1514 ) .f_current_dash_offset = (  op_dash_add58 ( (  off1515 ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_276_Just ) ( (  elem1516 ) ) );
}

static  struct Maybe_311   next310 (    struct Zip_296 *  self719 ) {
    struct Zip_296  copy720 = ( * (  self719 ) );
    while ( ( true ) ) {
        struct Maybe_276  dref721 = ( (  next313 ) ( ( & ( (  copy720 ) .f_left_dash_it ) ) ) );
        if ( dref721.tag == Maybe_276_None_t ) {
            return ( (struct Maybe_311) { .tag = Maybe_311_None_t } );
        }
        else {
            if ( dref721.tag == Maybe_276_Just_t ) {
                struct Maybe_290  dref723 = ( (  next294 ) ( ( & ( (  copy720 ) .f_right_dash_it ) ) ) );
                if ( dref723.tag == Maybe_290_None_t ) {
                    return ( (struct Maybe_311) { .tag = Maybe_311_None_t } );
                }
                else {
                    if ( dref723.tag == Maybe_290_Just_t ) {
                        ( (  next313 ) ( ( & ( ( * (  self719 ) ) .f_left_dash_it ) ) ) );
                        ( (  next294 ) ( ( & ( ( * (  self719 ) ) .f_right_dash_it ) ) ) );
                        return ( ( Maybe_311_Just ) ( ( ( Tuple2_312_Tuple2 ) ( ( dref721 .stuff .Maybe_276_Just_s .field0 ) ,  ( dref723 .stuff .Maybe_290_Just_s .field0 ) ) ) ) );
                    }
                }
            }
        }
    }
}

struct env319 {
    uint32_t  base980;
    ;
};

struct funenv319 {
    uint32_t  (*fun) (  struct env319  ,    int32_t  ,    uint32_t  );
    struct env319 env;
};

static  uint32_t   reduce318 (    struct Range_286  iterable863 ,    uint32_t  base865 ,   struct funenv319  fun867 ) {
    uint32_t  x868 = (  base865 );
    struct RangeIter_288  it869 = ( (  into_dash_iter287 ) ( (  iterable863 ) ) );
    while ( ( true ) ) {
        struct Maybe_290  dref870 = ( (  next289 ) ( ( & (  it869 ) ) ) );
        if ( dref870.tag == Maybe_290_None_t ) {
            return (  x868 );
        }
        else {
            if ( dref870.tag == Maybe_290_Just_t ) {
                struct funenv319  temp320 = (  fun867 );
                x868 = ( temp320.fun ( temp320.env ,  ( dref870 .stuff .Maybe_290_Just_s .field0 ) ,  (  x868 ) ) );
            }
        }
    }
    uint32_t  temp321;
    return (  temp321 );
}

static  uint32_t   lam319 (   struct env319 env ,    int32_t  item984 ,    uint32_t  x986 ) {
    return (  op_dash_mul54 ( (  x986 ) , ( env.base980 ) ) );
}

static  uint32_t   pow317 (    uint32_t  base980 ,    int32_t  p982 ) {
    struct env319 envinst319 = {
        .base980 =  base980 ,
    };
    return ( (  reduce318 ) ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  op_dash_sub48 ( (  p982 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) ,  (  from_dash_integral4 ( 1 ) ) ,  ( (struct funenv319){ .fun = lam319, .env = envinst319 } ) ) );
}

static  struct Maybe_276   next316 (    struct IntStrIter_300 *  self1145 ) {
    if ( (  cmp40 ( ( ( * (  self1145 ) ) .f_len ) , (  from_dash_integral3 ( 0 ) ) ) != 2 ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    uint32_t  trim_dash_down1146 = ( (  pow317 ) ( (  from_dash_integral4 ( 10 ) ) ,  (  op_dash_sub48 ( ( ( * (  self1145 ) ) .f_len ) , (  from_dash_integral3 ( 1 ) ) ) ) ) );
    uint32_t  upper1147 = (  op_dash_div55 ( ( ( * (  self1145 ) ) .f_int ) , (  trim_dash_down1146 ) ) );
    uint32_t  upper_dash_mask1148 = (  op_dash_mul54 ( (  op_dash_div55 ( (  upper1147 ) , (  from_dash_integral4 ( 10 ) ) ) ) , (  from_dash_integral4 ( 10 ) ) ) );
    uint32_t  digit1149 = (  op_dash_sub53 ( (  upper1147 ) , (  upper_dash_mask1148 ) ) );
    (*  self1145 ) .f_len = (  op_dash_sub48 ( ( ( * (  self1145 ) ) .f_len ) , (  from_dash_integral3 ( 1 ) ) ) );
    char  digit_dash_char1150 = ( (  cast182 ) ( (  op_dash_add52 ( (  digit1149 ) , (  from_dash_integral4 ( 48 ) ) ) ) ) );
    return ( ( Maybe_276_Just ) ( (  digit_dash_char1150 ) ) );
}

static  struct Maybe_276   next315 (    struct StrConcatIter_299 *  self1211 ) {
    struct Maybe_276  dref1212 = ( (  next282 ) ( ( & ( ( * (  self1211 ) ) .f_left ) ) ) );
    if ( dref1212.tag == Maybe_276_Just_t ) {
        return ( ( Maybe_276_Just ) ( ( dref1212 .stuff .Maybe_276_Just_s .field0 ) ) );
    }
    else {
        if ( dref1212.tag == Maybe_276_None_t ) {
            return ( (  next316 ) ( ( & ( ( * (  self1211 ) ) .f_right ) ) ) );
        }
    }
}

static  struct Maybe_311   next314 (    struct Zip_298 *  self719 ) {
    struct Zip_298  copy720 = ( * (  self719 ) );
    while ( ( true ) ) {
        struct Maybe_276  dref721 = ( (  next315 ) ( ( & ( (  copy720 ) .f_left_dash_it ) ) ) );
        if ( dref721.tag == Maybe_276_None_t ) {
            return ( (struct Maybe_311) { .tag = Maybe_311_None_t } );
        }
        else {
            if ( dref721.tag == Maybe_276_Just_t ) {
                struct Maybe_290  dref723 = ( (  next294 ) ( ( & ( (  copy720 ) .f_right_dash_it ) ) ) );
                if ( dref723.tag == Maybe_290_None_t ) {
                    return ( (struct Maybe_311) { .tag = Maybe_311_None_t } );
                }
                else {
                    if ( dref723.tag == Maybe_290_Just_t ) {
                        ( (  next315 ) ( ( & ( ( * (  self719 ) ) .f_left_dash_it ) ) ) );
                        ( (  next294 ) ( ( & ( ( * (  self719 ) ) .f_right_dash_it ) ) ) );
                        return ( ( Maybe_311_Just ) ( ( ( Tuple2_312_Tuple2 ) ( ( dref721 .stuff .Maybe_276_Just_s .field0 ) ,  ( dref723 .stuff .Maybe_290_Just_s .field0 ) ) ) ) );
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

static  struct Maybe_325   next326 (    struct SliceIter_306 *  self1514 ) {
    size_t  off1515 = ( ( * (  self1514 ) ) .f_current_dash_offset );
    if ( (  cmp39 ( (  op_dash_add58 ( (  off1515 ) , (  from_dash_integral8 ( 1 ) ) ) ) , ( ( ( * (  self1514 ) ) .f_slice ) .f_count ) ) == 2 ) ) {
        return ( (struct Maybe_325) { .tag = Maybe_325_None_t } );
    }
    struct Slice_103  elem1516 = ( * ( (  offset_dash_ptr131 ) ( ( ( ( * (  self1514 ) ) .f_slice ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  off1515 ) ) ) ) ) );
    (*  self1514 ) .f_current_dash_offset = (  op_dash_add58 ( (  off1515 ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_325_Just ) ( (  elem1516 ) ) );
}

static  struct Maybe_323   next322 (    struct Zip_305 *  self719 ) {
    struct Zip_305  copy720 = ( * (  self719 ) );
    while ( ( true ) ) {
        struct Maybe_325  dref721 = ( (  next326 ) ( ( & ( (  copy720 ) .f_left_dash_it ) ) ) );
        if ( dref721.tag == Maybe_325_None_t ) {
            return ( (struct Maybe_323) { .tag = Maybe_323_None_t } );
        }
        else {
            if ( dref721.tag == Maybe_325_Just_t ) {
                struct Maybe_290  dref723 = ( (  next294 ) ( ( & ( (  copy720 ) .f_right_dash_it ) ) ) );
                if ( dref723.tag == Maybe_290_None_t ) {
                    return ( (struct Maybe_323) { .tag = Maybe_323_None_t } );
                }
                else {
                    if ( dref723.tag == Maybe_290_Just_t ) {
                        ( (  next326 ) ( ( & ( ( * (  self719 ) ) .f_left_dash_it ) ) ) );
                        ( (  next294 ) ( ( & ( ( * (  self719 ) ) .f_right_dash_it ) ) ) );
                        return ( ( Maybe_323_Just ) ( ( ( Tuple2_324_Tuple2 ) ( ( dref721 .stuff .Maybe_325_Just_s .field0 ) ,  ( dref723 .stuff .Maybe_290_Just_s .field0 ) ) ) ) );
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

static  struct Maybe_330   next331 (    struct SliceIter_303 *  self1514 ) {
    size_t  off1515 = ( ( * (  self1514 ) ) .f_current_dash_offset );
    if ( (  cmp39 ( (  op_dash_add58 ( (  off1515 ) , (  from_dash_integral8 ( 1 ) ) ) ) , ( ( ( * (  self1514 ) ) .f_slice ) .f_count ) ) == 2 ) ) {
        return ( (struct Maybe_330) { .tag = Maybe_330_None_t } );
    }
    struct Tile_104  elem1516 = ( * ( (  offset_dash_ptr133 ) ( ( ( ( * (  self1514 ) ) .f_slice ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  off1515 ) ) ) ) ) );
    (*  self1514 ) .f_current_dash_offset = (  op_dash_add58 ( (  off1515 ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_330_Just ) ( (  elem1516 ) ) );
}

static  struct Maybe_328   next327 (    struct Zip_302 *  self719 ) {
    struct Zip_302  copy720 = ( * (  self719 ) );
    while ( ( true ) ) {
        struct Maybe_330  dref721 = ( (  next331 ) ( ( & ( (  copy720 ) .f_left_dash_it ) ) ) );
        if ( dref721.tag == Maybe_330_None_t ) {
            return ( (struct Maybe_328) { .tag = Maybe_328_None_t } );
        }
        else {
            if ( dref721.tag == Maybe_330_Just_t ) {
                struct Maybe_290  dref723 = ( (  next294 ) ( ( & ( (  copy720 ) .f_right_dash_it ) ) ) );
                if ( dref723.tag == Maybe_290_None_t ) {
                    return ( (struct Maybe_328) { .tag = Maybe_328_None_t } );
                }
                else {
                    if ( dref723.tag == Maybe_290_Just_t ) {
                        ( (  next331 ) ( ( & ( ( * (  self719 ) ) .f_left_dash_it ) ) ) );
                        ( (  next294 ) ( ( & ( ( * (  self719 ) ) .f_right_dash_it ) ) ) );
                        return ( ( Maybe_328_Just ) ( ( ( Tuple2_329_Tuple2 ) ( ( dref721 .stuff .Maybe_330_Just_s .field0 ) ,  ( dref723 .stuff .Maybe_290_Just_s .field0 ) ) ) ) );
                    }
                }
            }
        }
    }
}

static  struct Maybe_311   next332 (    struct Zip_309 *  self719 ) {
    struct Zip_309  copy720 = ( * (  self719 ) );
    while ( ( true ) ) {
        struct Maybe_276  dref721 = ( (  next282 ) ( ( & ( (  copy720 ) .f_left_dash_it ) ) ) );
        if ( dref721.tag == Maybe_276_None_t ) {
            return ( (struct Maybe_311) { .tag = Maybe_311_None_t } );
        }
        else {
            if ( dref721.tag == Maybe_276_Just_t ) {
                struct Maybe_290  dref723 = ( (  next294 ) ( ( & ( (  copy720 ) .f_right_dash_it ) ) ) );
                if ( dref723.tag == Maybe_290_None_t ) {
                    return ( (struct Maybe_311) { .tag = Maybe_311_None_t } );
                }
                else {
                    if ( dref723.tag == Maybe_290_Just_t ) {
                        ( (  next282 ) ( ( & ( ( * (  self719 ) ) .f_left_dash_it ) ) ) );
                        ( (  next294 ) ( ( & ( ( * (  self719 ) ) .f_right_dash_it ) ) ) );
                        return ( ( Maybe_311_Just ) ( ( ( Tuple2_312_Tuple2 ) ( ( dref721 .stuff .Maybe_276_Just_s .field0 ) ,  ( dref723 .stuff .Maybe_290_Just_s .field0 ) ) ) ) );
                    }
                }
            }
        }
    }
}

static  struct SliceIter_269   into_dash_iter334 (    struct Slice_270  self1508 ) {
    return ( (struct SliceIter_269) { .f_slice = (  self1508 ) , .f_current_dash_offset = (  from_dash_integral8 ( 0 ) ) } );
}

static  struct Zip_296   zip333 (    struct Slice_270  left727 ,    struct FromIter_292  right729 ) {
    struct SliceIter_269  left_dash_it730 = ( (  into_dash_iter334 ) ( (  left727 ) ) );
    struct FromIter_292  right_dash_it731 = ( (  into_dash_iter293 ) ( (  right729 ) ) );
    return ( (struct Zip_296) { .f_left_dash_it = (  left_dash_it730 ) , .f_right_dash_it = (  right_dash_it731 ) } );
}

static  struct StrConcatIter_299   into_dash_iter336 (    struct StrConcatIter_299  self1208 ) {
    return (  self1208 );
}

static  struct Zip_298   zip335 (    struct StrConcatIter_299  left727 ,    struct FromIter_292  right729 ) {
    struct StrConcatIter_299  left_dash_it730 = ( (  into_dash_iter336 ) ( (  left727 ) ) );
    struct FromIter_292  right_dash_it731 = ( (  into_dash_iter293 ) ( (  right729 ) ) );
    return ( (struct Zip_298) { .f_left_dash_it = (  left_dash_it730 ) , .f_right_dash_it = (  right_dash_it731 ) } );
}

static  struct SliceIter_303   into_dash_iter338 (    struct Slice_103  self1508 ) {
    return ( (struct SliceIter_303) { .f_slice = (  self1508 ) , .f_current_dash_offset = (  from_dash_integral8 ( 0 ) ) } );
}

static  struct Zip_302   zip337 (    struct Slice_103  left727 ,    struct FromIter_292  right729 ) {
    struct SliceIter_303  left_dash_it730 = ( (  into_dash_iter338 ) ( (  left727 ) ) );
    struct FromIter_292  right_dash_it731 = ( (  into_dash_iter293 ) ( (  right729 ) ) );
    return ( (struct Zip_302) { .f_left_dash_it = (  left_dash_it730 ) , .f_right_dash_it = (  right_dash_it731 ) } );
}

static  struct SliceIter_306   into_dash_iter340 (    struct Slice_307  self1508 ) {
    return ( (struct SliceIter_306) { .f_slice = (  self1508 ) , .f_current_dash_offset = (  from_dash_integral8 ( 0 ) ) } );
}

static  struct Zip_305   zip339 (    struct Slice_307  left727 ,    struct FromIter_292  right729 ) {
    struct SliceIter_306  left_dash_it730 = ( (  into_dash_iter340 ) ( (  left727 ) ) );
    struct FromIter_292  right_dash_it731 = ( (  into_dash_iter293 ) ( (  right729 ) ) );
    return ( (struct Zip_305) { .f_left_dash_it = (  left_dash_it730 ) , .f_right_dash_it = (  right_dash_it731 ) } );
}

static  struct ConstStrIter_279   into_dash_iter342 (    struct ConstStrIter_279  self1116 ) {
    return (  self1116 );
}

static  struct Zip_309   zip341 (    struct ConstStrIter_279  left727 ,    struct FromIter_292  right729 ) {
    struct ConstStrIter_279  left_dash_it730 = ( (  into_dash_iter342 ) ( (  left727 ) ) );
    struct FromIter_292  right_dash_it731 = ( (  into_dash_iter293 ) ( (  right729 ) ) );
    return ( (struct Zip_309) { .f_left_dash_it = (  left_dash_it730 ) , .f_right_dash_it = (  right_dash_it731 ) } );
}

struct FlattenIter_344 {
    struct SliceIter_306  f_super;
    struct SliceIter_303  f_inner;
    bool  f_empty;
};

static  struct FlattenIter_344   into_dash_iter343 (    struct FlattenIter_344  self735 ) {
    return (  self735 );
}

static  struct Maybe_330   next345 (    struct FlattenIter_344 *  self738 ) {
    if ( ( ( * (  self738 ) ) .f_empty ) ) {
        return ( (struct Maybe_330) { .tag = Maybe_330_None_t } );
    }
    while ( ( true ) ) {
        struct Maybe_330  dref739 = ( (  next331 ) ( ( & ( ( * (  self738 ) ) .f_inner ) ) ) );
        if ( dref739.tag == Maybe_330_Just_t ) {
            return ( ( Maybe_330_Just ) ( ( dref739 .stuff .Maybe_330_Just_s .field0 ) ) );
        }
        else {
            if ( dref739.tag == Maybe_330_None_t ) {
                struct Maybe_325  dref741 = ( (  next326 ) ( ( & ( ( * (  self738 ) ) .f_super ) ) ) );
                if ( dref741.tag == Maybe_325_Just_t ) {
                    (*  self738 ) .f_inner = ( (  into_dash_iter338 ) ( ( dref741 .stuff .Maybe_325_Just_s .field0 ) ) );
                }
                else {
                    if ( dref741.tag == Maybe_325_None_t ) {
                        return ( (struct Maybe_330) { .tag = Maybe_330_None_t } );
                    }
                }
            }
        }
    }
}

static  struct FlattenIter_344   flatten346 (    struct Slice_307  it745 ) {
    struct SliceIter_306  it746 = ( (  into_dash_iter340 ) ( (  it745 ) ) );
    struct Maybe_325  dref747 = ( (  next326 ) ( ( & (  it746 ) ) ) );
    if ( dref747.tag == Maybe_325_Just_t ) {
        return ( (struct FlattenIter_344) { .f_super = (  it746 ) , .f_inner = ( (  into_dash_iter338 ) ( ( dref747 .stuff .Maybe_325_Just_s .field0 ) ) ) , .f_empty = ( false ) } );
    }
    else {
        if ( dref747.tag == Maybe_325_None_t ) {
            struct SliceIter_303  temp347;
            return ( (struct FlattenIter_344) { .f_super = (  it746 ) , .f_inner = (  temp347 ) , .f_empty = ( true ) } );
        }
    }
}

struct TakeWhile_349 {
    struct Scanner_268  f_it;
    bool (*  f_pred )(    char  );
};

static  struct TakeWhile_349   into_dash_iter348 (    struct TakeWhile_349  self766 ) {
    return (  self766 );
}

static  struct Maybe_276   next351 (    struct Scanner_268 *  self2649 ) {
    return ( (  next313 ) ( ( & ( ( * (  self2649 ) ) .f_s ) ) ) );
}

static  struct Maybe_276   next350 (    struct TakeWhile_349 *  self769 ) {
    struct Maybe_276  mx770 = ( (  next351 ) ( ( & ( ( * (  self769 ) ) .f_it ) ) ) );
    struct Maybe_276  dref771 = (  mx770 );
    if ( dref771.tag == Maybe_276_None_t ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    else {
        if ( dref771.tag == Maybe_276_Just_t ) {
            if ( ( ( ( * (  self769 ) ) .f_pred ) ( ( dref771 .stuff .Maybe_276_Just_s .field0 ) ) ) ) {
                return ( ( Maybe_276_Just ) ( ( dref771 .stuff .Maybe_276_Just_s .field0 ) ) );
            } else {
                return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
            }
        }
    }
}

static  struct TakeWhile_349   take_dash_while352 (    struct Scanner_268 *  it775 ,    bool (*  pred777 )(    char  ) ) {
    return ( (struct TakeWhile_349) { .f_it = ( (  into_dash_iter267 ) ( (  it775 ) ) ) , .f_pred = (  pred777 ) } );
}

struct AppendIter_354 {
    enum EmptyIter_273  f_it;
    char  f_elem;
    bool  f_appended;
};

static  struct AppendIter_354   append353 (    enum EmptyIter_273  it811 ,    char  e813 ) {
    return ( (struct AppendIter_354) { .f_it = ( (  into_dash_iter274 ) ( (  it811 ) ) ) , .f_elem = (  e813 ) , .f_appended = ( false ) } );
}

static  struct AppendIter_354   cons355 (    enum EmptyIter_273  it816 ,    char  e818 ) {
    return ( (  append353 ) ( (  it816 ) ,  (  e818 ) ) );
}

static  struct AppendIter_354   single356 (    char  e821 ) {
    return ( (  cons355 ) ( ( (  nil272 ) ( ) ) ,  (  e821 ) ) );
}

static  struct Maybe_276   next357 (    struct AppendIter_354 *  self827 ) {
    struct Maybe_276  dref828 = ( (  next275 ) ( ( & ( ( * (  self827 ) ) .f_it ) ) ) );
    if ( dref828.tag == Maybe_276_Just_t ) {
        return ( ( Maybe_276_Just ) ( ( dref828 .stuff .Maybe_276_Just_s .field0 ) ) );
    }
    else {
        if ( dref828.tag == Maybe_276_None_t ) {
            if ( ( ! ( ( * (  self827 ) ) .f_appended ) ) ) {
                (*  self827 ) .f_appended = ( true );
                return ( ( Maybe_276_Just ) ( ( ( * (  self827 ) ) .f_elem ) ) );
            }
            return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
        }
    }
}

struct env362 {
    ;
    ;
    ;
    bool *  should_dash_resize2724;
};

enum ColorPalette_364 {
    ColorPalette_364_Palette8,
    ColorPalette_364_Palette16,
    ColorPalette_364_Palette256,
    ColorPalette_364_PaletteRGB,
};

struct Tui_363 {
    uint32_t  f_width;
    uint32_t  f_height;
    uint32_t  f_target_dash_fps;
    uint32_t  f_actual_dash_fps;
    enum ColorPalette_364  f_palette;
    struct timespec  f_last_dash_sync;
    struct timespec  f_fps_dash_ts;
    uint32_t  f_fps_dash_count;
    struct Termios_111  f_orig_dash_termios;
    bool  f_should_dash_redraw;
};

struct funenv362 {
    bool  (*fun) (  struct env362  ,    struct Tui_363 *  );
    struct env362 env;
};

struct env361 {
    ;
    struct env362 envinst362;
};

struct Key_367 {
    enum {
        Key_367_Escape_t,
        Key_367_Enter_t,
        Key_367_Tab_t,
        Key_367_Backspace_t,
        Key_367_Char_t,
        Key_367_Ctrl_t,
        Key_367_Up_t,
        Key_367_Down_t,
        Key_367_Left_t,
        Key_367_Right_t,
        Key_367_Home_t,
        Key_367_End_t,
        Key_367_PageUp_t,
        Key_367_PageDown_t,
        Key_367_Delete_t,
        Key_367_Insert_t,
        Key_367_F1_t,
        Key_367_F2_t,
        Key_367_F3_t,
        Key_367_F4_t,
        Key_367_F5_t,
        Key_367_F6_t,
        Key_367_F7_t,
        Key_367_F8_t,
        Key_367_F9_t,
        Key_367_F10_t,
        Key_367_F11_t,
        Key_367_F12_t,
    } tag;
    union {
        struct {
            char  field0;
        } Key_367_Char_s;
        struct {
            char  field0;
        } Key_367_Ctrl_s;
    } stuff;
};

static struct Key_367 Key_367_Char (  char  field0 ) {
    return ( struct Key_367 ) { .tag = Key_367_Char_t, .stuff = { .Key_367_Char_s = { .field0 = field0 } } };
};

static struct Key_367 Key_367_Ctrl (  char  field0 ) {
    return ( struct Key_367 ) { .tag = Key_367_Ctrl_t, .stuff = { .Key_367_Ctrl_s = { .field0 = field0 } } };
};

struct MouseEvent_368 {
    enum MouseButton_119  f_button;
    int32_t  f_x;
    int32_t  f_y;
    bool  f_pressed;
};

struct InputEvent_366 {
    enum {
        InputEvent_366_Key_t,
        InputEvent_366_Mouse_t,
    } tag;
    union {
        struct {
            struct Key_367  field0;
        } InputEvent_366_Key_s;
        struct {
            struct MouseEvent_368  field0;
        } InputEvent_366_Mouse_s;
    } stuff;
};

static struct InputEvent_366 InputEvent_366_Key (  struct Key_367  field0 ) {
    return ( struct InputEvent_366 ) { .tag = InputEvent_366_Key_t, .stuff = { .InputEvent_366_Key_s = { .field0 = field0 } } };
};

static struct InputEvent_366 InputEvent_366_Mouse (  struct MouseEvent_368  field0 ) {
    return ( struct InputEvent_366 ) { .tag = InputEvent_366_Mouse_t, .stuff = { .InputEvent_366_Mouse_s = { .field0 = field0 } } };
};

struct Maybe_365 {
    enum {
        Maybe_365_None_t,
        Maybe_365_Just_t,
    } tag;
    union {
        struct {
            struct InputEvent_366  field0;
        } Maybe_365_Just_s;
    } stuff;
};

static struct Maybe_365 Maybe_365_Just (  struct InputEvent_366  field0 ) {
    return ( struct Maybe_365 ) { .tag = Maybe_365_Just_t, .stuff = { .Maybe_365_Just_s = { .field0 = field0 } } };
};

struct funenv361 {
    struct Maybe_365  (*fun) (  struct env361  ,    struct Tui_363 *  );
    struct env361 env;
};

struct env360 {
    struct env361 envinst361;
    struct Tui_363 *  tui3070;
};

struct funenv360 {
    struct Maybe_365  (*fun) (  struct env360  );
    struct env360 env;
};

struct FunIter_359 {
    struct funenv360  f_fun;
    bool  f_finished;
};

static  struct FunIter_359   into_dash_iter358 (    struct FunIter_359  self833 ) {
    return (  self833 );
}

static  struct Maybe_365   next369 (    struct FunIter_359 *  self836 ) {
    if ( ( ( * (  self836 ) ) .f_finished ) ) {
        return ( (struct Maybe_365) { .tag = Maybe_365_None_t } );
    }
    struct funenv360  temp370 = ( ( * (  self836 ) ) .f_fun );
    struct Maybe_365  dref837 = ( temp370.fun ( temp370.env ) );
    if ( dref837.tag == Maybe_365_Just_t ) {
        return ( ( Maybe_365_Just ) ( ( dref837 .stuff .Maybe_365_Just_s .field0 ) ) );
    }
    else {
        if ( dref837.tag == Maybe_365_None_t ) {
            (*  self836 ) .f_finished = ( true );
            return ( (struct Maybe_365) { .tag = Maybe_365_None_t } );
        }
    }
}

static  struct FunIter_359   from_dash_function371 (   struct funenv360  fun841 ) {
    return ( (struct FunIter_359) { .f_fun = (  fun841 ) , .f_finished = ( false ) } );
}

struct env373 {
    struct Slice_270  new_dash_slice1728;
    ;
    ;
};

struct funenv373 {
    enum Unit_157  (*fun) (  struct env373  ,    struct Tuple2_312  );
    struct env373 env;
};

static  enum Unit_157   for_dash_each372 (    struct Zip_296  iterable844 ,   struct funenv373  fun846 ) {
    struct Zip_296  temp374 = ( (  into_dash_iter295 ) ( (  iterable844 ) ) );
    struct Zip_296 *  it847 = ( &temp374 );
    while ( ( true ) ) {
        struct Maybe_311  dref848 = ( (  next310 ) ( (  it847 ) ) );
        if ( dref848.tag == Maybe_311_None_t ) {
            return ( Unit_157_Unit );
        }
        else {
            if ( dref848.tag == Maybe_311_Just_t ) {
                struct funenv373  temp375 = (  fun846 );
                ( temp375.fun ( temp375.env ,  ( dref848 .stuff .Maybe_311_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_157_Unit );
}

struct StrConcatIter_379 {
    struct ConstStrIter_279  f_left;
    struct ConstStrIter_279  f_right;
};

struct StrCaseIter_378 {
    enum {
        StrCaseIter_378_StrCaseIter1_t,
        StrCaseIter_378_StrCaseIter2_t,
    } tag;
    union {
        struct {
            struct ConstStrIter_279  field0;
        } StrCaseIter_378_StrCaseIter1_s;
        struct {
            struct StrConcatIter_379  field0;
        } StrCaseIter_378_StrCaseIter2_s;
    } stuff;
};

static struct StrCaseIter_378 StrCaseIter_378_StrCaseIter1 (  struct ConstStrIter_279  field0 ) {
    return ( struct StrCaseIter_378 ) { .tag = StrCaseIter_378_StrCaseIter1_t, .stuff = { .StrCaseIter_378_StrCaseIter1_s = { .field0 = field0 } } };
};

static struct StrCaseIter_378 StrCaseIter_378_StrCaseIter2 (  struct StrConcatIter_379  field0 ) {
    return ( struct StrCaseIter_378 ) { .tag = StrCaseIter_378_StrCaseIter2_t, .stuff = { .StrCaseIter_378_StrCaseIter2_s = { .field0 = field0 } } };
};

struct StrConcatIter_377 {
    struct StrCaseIter_378  f_left;
    struct ConstStrIter_279  f_right;
};

enum CAllocator_383 {
    CAllocator_383_CAllocator,
};

struct List_382 {
    enum CAllocator_383  f_al;
    struct Slice_270  f_elements;
    size_t  f_count;
};

struct StrBuilder_381 {
    struct List_382  f_chars;
};

struct env385 {
    ;
    size_t  growth_dash_factor1723;
    ;
    size_t  starting_dash_size1722;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
};

struct funenv385 {
    enum Unit_157  (*fun) (  struct env385  ,    struct List_382 *  );
    struct env385 env;
};

struct env384 {
    struct env385 envinst385;
    ;
    ;
    ;
    ;
    ;
};

struct funenv384 {
    enum Unit_157  (*fun) (  struct env384  ,    struct List_382 *  ,    char  );
    struct env384 env;
};

struct env380 {
    struct StrBuilder_381 *  builder2200;
    struct env384 envinst384;
};

struct funenv380 {
    enum Unit_157  (*fun) (  struct env380  ,    char  );
    struct env380 env;
};

static  struct StrConcatIter_377   into_dash_iter387 (    struct StrConcatIter_377  self1208 ) {
    return (  self1208 );
}

static  struct Maybe_276   next390 (    struct StrConcatIter_379 *  self1211 ) {
    struct Maybe_276  dref1212 = ( (  next282 ) ( ( & ( ( * (  self1211 ) ) .f_left ) ) ) );
    if ( dref1212.tag == Maybe_276_Just_t ) {
        return ( ( Maybe_276_Just ) ( ( dref1212 .stuff .Maybe_276_Just_s .field0 ) ) );
    }
    else {
        if ( dref1212.tag == Maybe_276_None_t ) {
            return ( (  next282 ) ( ( & ( ( * (  self1211 ) ) .f_right ) ) ) );
        }
    }
}

static  struct Maybe_276   next389 (    struct StrCaseIter_378 *  self1233 ) {
    struct StrCaseIter_378 *  dref1234 = (  self1233 );
    if ( (* dref1234 ).tag == StrCaseIter_378_StrCaseIter1_t ) {
        return ( (  next282 ) ( ( & ( (* dref1234 ) .stuff .StrCaseIter_378_StrCaseIter1_s .field0 ) ) ) );
    }
    else {
        if ( (* dref1234 ).tag == StrCaseIter_378_StrCaseIter2_t ) {
            return ( (  next390 ) ( ( & ( (* dref1234 ) .stuff .StrCaseIter_378_StrCaseIter2_s .field0 ) ) ) );
        }
    }
}

static  struct Maybe_276   next388 (    struct StrConcatIter_377 *  self1211 ) {
    struct Maybe_276  dref1212 = ( (  next389 ) ( ( & ( ( * (  self1211 ) ) .f_left ) ) ) );
    if ( dref1212.tag == Maybe_276_Just_t ) {
        return ( ( Maybe_276_Just ) ( ( dref1212 .stuff .Maybe_276_Just_s .field0 ) ) );
    }
    else {
        if ( dref1212.tag == Maybe_276_None_t ) {
            return ( (  next282 ) ( ( & ( ( * (  self1211 ) ) .f_right ) ) ) );
        }
    }
}

static  enum Unit_157   for_dash_each376 (    struct StrConcatIter_377  iterable844 ,   struct funenv380  fun846 ) {
    struct StrConcatIter_377  temp386 = ( (  into_dash_iter387 ) ( (  iterable844 ) ) );
    struct StrConcatIter_377 *  it847 = ( &temp386 );
    while ( ( true ) ) {
        struct Maybe_276  dref848 = ( (  next388 ) ( (  it847 ) ) );
        if ( dref848.tag == Maybe_276_None_t ) {
            return ( Unit_157_Unit );
        }
        else {
            if ( dref848.tag == Maybe_276_Just_t ) {
                struct funenv380  temp391 = (  fun846 );
                ( temp391.fun ( temp391.env ,  ( dref848 .stuff .Maybe_276_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_157_Unit );
}

struct env394 {
    struct Tile_104  x1637;
};

struct funenv394 {
    struct Tile_104  (*fun) (  struct env394  ,    struct Tile_104  );
    struct env394 env;
};

struct env393 {
    struct funenv394  fun1593;
    ;
    ;
    ;
    struct Slice_103  s1591;
};

struct funenv393 {
    enum Unit_157  (*fun) (  struct env393  ,    int32_t  );
    struct env393 env;
};

static  enum Unit_157   for_dash_each392 (    struct Range_286  iterable844 ,   struct funenv393  fun846 ) {
    struct RangeIter_288  temp395 = ( (  into_dash_iter287 ) ( (  iterable844 ) ) );
    struct RangeIter_288 *  it847 = ( &temp395 );
    while ( ( true ) ) {
        struct Maybe_290  dref848 = ( (  next289 ) ( (  it847 ) ) );
        if ( dref848.tag == Maybe_290_None_t ) {
            return ( Unit_157_Unit );
        }
        else {
            if ( dref848.tag == Maybe_290_Just_t ) {
                struct funenv393  temp396 = (  fun846 );
                ( temp396.fun ( temp396.env ,  ( dref848 .stuff .Maybe_290_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_157_Unit );
}

struct Slice_399 {
    struct Cell_16 *  f_ptr;
    size_t  f_count;
};

struct env398 {
    struct Cell_16 (*  fun1593 )(    struct Cell_16  );
    ;
    ;
    ;
    struct Slice_399  s1591;
};

struct funenv398 {
    enum Unit_157  (*fun) (  struct env398  ,    int32_t  );
    struct env398 env;
};

static  enum Unit_157   for_dash_each397 (    struct Range_286  iterable844 ,   struct funenv398  fun846 ) {
    struct RangeIter_288  temp400 = ( (  into_dash_iter287 ) ( (  iterable844 ) ) );
    struct RangeIter_288 *  it847 = ( &temp400 );
    while ( ( true ) ) {
        struct Maybe_290  dref848 = ( (  next289 ) ( (  it847 ) ) );
        if ( dref848.tag == Maybe_290_None_t ) {
            return ( Unit_157_Unit );
        }
        else {
            if ( dref848.tag == Maybe_290_Just_t ) {
                struct funenv398  temp401 = (  fun846 );
                ( temp401.fun ( temp401.env ,  ( dref848 .stuff .Maybe_290_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_157_Unit );
}

struct env403 {
    struct Cell_16 (*  fun1593 )(    struct Cell_16  );
    ;
    ;
    ;
    struct Slice_399  s1591;
};

struct funenv403 {
    enum Unit_157  (*fun) (  struct env403  ,    int32_t  );
    struct env403 env;
};

static  enum Unit_157   for_dash_each402 (    struct Range_286  iterable844 ,   struct funenv403  fun846 ) {
    struct RangeIter_288  temp404 = ( (  into_dash_iter287 ) ( (  iterable844 ) ) );
    struct RangeIter_288 *  it847 = ( &temp404 );
    while ( ( true ) ) {
        struct Maybe_290  dref848 = ( (  next289 ) ( (  it847 ) ) );
        if ( dref848.tag == Maybe_290_None_t ) {
            return ( Unit_157_Unit );
        }
        else {
            if ( dref848.tag == Maybe_290_Just_t ) {
                struct funenv403  temp405 = (  fun846 );
                ( temp405.fun ( temp405.env ,  ( dref848 .stuff .Maybe_290_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_157_Unit );
}

struct env407 {
    struct Scanner_268 *  it956;
    ;
};

struct funenv407 {
    struct Maybe_276  (*fun) (  struct env407  ,    int32_t  );
    struct env407 env;
};

static  enum Unit_157   for_dash_each406 (    struct Range_286  iterable844 ,   struct funenv407  fun846 ) {
    struct RangeIter_288  temp408 = ( (  into_dash_iter287 ) ( (  iterable844 ) ) );
    struct RangeIter_288 *  it847 = ( &temp408 );
    while ( ( true ) ) {
        struct Maybe_290  dref848 = ( (  next289 ) ( (  it847 ) ) );
        if ( dref848.tag == Maybe_290_None_t ) {
            return ( Unit_157_Unit );
        }
        else {
            if ( dref848.tag == Maybe_290_Just_t ) {
                struct funenv407  temp409 = (  fun846 );
                ( temp409.fun ( temp409.env ,  ( dref848 .stuff .Maybe_290_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_157_Unit );
}

struct env412 {
    ;
    struct env384 envinst384;
    ;
};

struct funenv412 {
    enum Unit_157  (*fun) (  struct env412  ,    struct StrBuilder_381 *  ,    char  );
    struct env412 env;
};

struct env416 {
    ;
    ;
    ;
    ;
    struct env384 envinst384;
    ;
    ;
};

struct funenv416 {
    enum Unit_157  (*fun) (  struct env416  ,    struct StrBuilder_381 *  ,    struct StrBuilder_381  );
    struct env416 env;
};

struct env415 {
    ;
    ;
    struct env416 envinst416;
    ;
    ;
    struct env412 envinst412;
    ;
    ;
    ;
    ;
    ;
    ;
};

struct DynStr_417 {
    struct Slice_270  f_contents;
};

struct funenv415 {
    struct DynStr_417  (*fun) (  struct env415  ,    struct StrBuilder_381  ,    enum CAllocator_383  );
    struct env415 env;
};

struct env414 {
    ;
    ;
    ;
    ;
    struct env415 envinst415;
    ;
    ;
};

struct funenv414 {
    const char*  (*fun) (  struct env414  ,    struct StrBuilder_381  ,    enum CAllocator_383  );
    struct env414 env;
};

struct env413 {
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
    ;
    ;
    struct env414 envinst414;
    ;
    ;
    ;
    ;
};

struct funenv413 {
    enum Unit_157  (*fun) (  struct env413  ,    struct StrBuilder_381  ,    enum CAllocator_383  );
    struct env413 env;
};

struct env411 {
    ;
    ;
    enum CAllocator_383  al2372;
    ;
    struct env412 envinst412;
    struct env413 envinst413;
    ;
    ;
    struct StrBuilder_381 *  sb2373;
};

struct funenv411 {
    enum Unit_157  (*fun) (  struct env411  ,    char  );
    struct env411 env;
};

static  enum Unit_157   for_dash_each410 (    struct StrConcatIter_377  iterable844 ,   struct funenv411  fun846 ) {
    struct StrConcatIter_377  temp418 = ( (  into_dash_iter387 ) ( (  iterable844 ) ) );
    struct StrConcatIter_377 *  it847 = ( &temp418 );
    while ( ( true ) ) {
        struct Maybe_276  dref848 = ( (  next388 ) ( (  it847 ) ) );
        if ( dref848.tag == Maybe_276_None_t ) {
            return ( Unit_157_Unit );
        }
        else {
            if ( dref848.tag == Maybe_276_Just_t ) {
                struct funenv411  temp419 = (  fun846 );
                ( temp419.fun ( temp419.env ,  ( dref848 .stuff .Maybe_276_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_157_Unit );
}

struct env421 {
    struct StrBuilder_381 *  builder2200;
    struct env384 envinst384;
};

struct funenv421 {
    enum Unit_157  (*fun) (  struct env421  ,    char  );
    struct env421 env;
};

static  struct SliceIter_269   into_dash_iter423 (    struct SliceIter_269  self1511 ) {
    return (  self1511 );
}

static  enum Unit_157   for_dash_each420 (    struct SliceIter_269  iterable844 ,   struct funenv421  fun846 ) {
    struct SliceIter_269  temp422 = ( (  into_dash_iter423 ) ( (  iterable844 ) ) );
    struct SliceIter_269 *  it847 = ( &temp422 );
    while ( ( true ) ) {
        struct Maybe_276  dref848 = ( (  next313 ) ( (  it847 ) ) );
        if ( dref848.tag == Maybe_276_None_t ) {
            return ( Unit_157_Unit );
        }
        else {
            if ( dref848.tag == Maybe_276_Just_t ) {
                struct funenv421  temp424 = (  fun846 );
                ( temp424.fun ( temp424.env ,  ( dref848 .stuff .Maybe_276_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_157_Unit );
}

struct StrConcatIter_426 {
    struct StrConcatIter_377  f_left;
    struct ConstStrIter_279  f_right;
};

struct env427 {
    struct StrBuilder_381 *  builder2200;
    struct env384 envinst384;
};

struct funenv427 {
    enum Unit_157  (*fun) (  struct env427  ,    char  );
    struct env427 env;
};

static  struct StrConcatIter_426   into_dash_iter429 (    struct StrConcatIter_426  self1208 ) {
    return (  self1208 );
}

static  struct Maybe_276   next430 (    struct StrConcatIter_426 *  self1211 ) {
    struct Maybe_276  dref1212 = ( (  next388 ) ( ( & ( ( * (  self1211 ) ) .f_left ) ) ) );
    if ( dref1212.tag == Maybe_276_Just_t ) {
        return ( ( Maybe_276_Just ) ( ( dref1212 .stuff .Maybe_276_Just_s .field0 ) ) );
    }
    else {
        if ( dref1212.tag == Maybe_276_None_t ) {
            return ( (  next282 ) ( ( & ( ( * (  self1211 ) ) .f_right ) ) ) );
        }
    }
}

static  enum Unit_157   for_dash_each425 (    struct StrConcatIter_426  iterable844 ,   struct funenv427  fun846 ) {
    struct StrConcatIter_426  temp428 = ( (  into_dash_iter429 ) ( (  iterable844 ) ) );
    struct StrConcatIter_426 *  it847 = ( &temp428 );
    while ( ( true ) ) {
        struct Maybe_276  dref848 = ( (  next430 ) ( (  it847 ) ) );
        if ( dref848.tag == Maybe_276_None_t ) {
            return ( Unit_157_Unit );
        }
        else {
            if ( dref848.tag == Maybe_276_Just_t ) {
                struct funenv427  temp431 = (  fun846 );
                ( temp431.fun ( temp431.env ,  ( dref848 .stuff .Maybe_276_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_157_Unit );
}

struct env433 {
    struct Cell_16 (*  fun1593 )(    struct Cell_16  );
    ;
    ;
    ;
    struct Slice_399  s1591;
};

struct funenv433 {
    enum Unit_157  (*fun) (  struct env433  ,    int32_t  );
    struct env433 env;
};

static  enum Unit_157   for_dash_each432 (    struct Range_286  iterable844 ,   struct funenv433  fun846 ) {
    struct RangeIter_288  temp434 = ( (  into_dash_iter287 ) ( (  iterable844 ) ) );
    struct RangeIter_288 *  it847 = ( &temp434 );
    while ( ( true ) ) {
        struct Maybe_290  dref848 = ( (  next289 ) ( (  it847 ) ) );
        if ( dref848.tag == Maybe_290_None_t ) {
            return ( Unit_157_Unit );
        }
        else {
            if ( dref848.tag == Maybe_290_Just_t ) {
                struct funenv433  temp435 = (  fun846 );
                ( temp435.fun ( temp435.env ,  ( dref848 .stuff .Maybe_290_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_157_Unit );
}

struct Screen_438 {
    enum CAllocator_383  f_al;
    struct Tui_363 *  f_tui;
    struct Slice_399  f_current;
    struct Slice_399  f_previous;
    bool  f_requires_dash_full_dash_redraw;
    struct Color_17  f_default_dash_fg;
    struct Color_17  f_default_dash_bg;
};

struct env437 {
    int32_t  y2930;
    ;
    struct Screen_438 *  screen2924;
    ;
    int32_t  x2933;
};

struct funenv437 {
    enum Unit_157  (*fun) (  struct env437  ,    struct Tuple2_312  );
    struct env437 env;
};

static  enum Unit_157   for_dash_each436 (    struct Zip_298  iterable844 ,   struct funenv437  fun846 ) {
    struct Zip_298  temp439 = ( (  into_dash_iter297 ) ( (  iterable844 ) ) );
    struct Zip_298 *  it847 = ( &temp439 );
    while ( ( true ) ) {
        struct Maybe_311  dref848 = ( (  next314 ) ( (  it847 ) ) );
        if ( dref848.tag == Maybe_311_None_t ) {
            return ( Unit_157_Unit );
        }
        else {
            if ( dref848.tag == Maybe_311_Just_t ) {
                struct funenv437  temp440 = (  fun846 );
                ( temp440.fun ( temp440.env ,  ( dref848 .stuff .Maybe_311_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_157_Unit );
}

struct env442 {
    int32_t  y2930;
    ;
    struct Screen_438 *  screen2924;
    ;
    int32_t  x2933;
};

struct funenv442 {
    enum Unit_157  (*fun) (  struct env442  ,    struct Tuple2_312  );
    struct env442 env;
};

static  enum Unit_157   for_dash_each441 (    struct Zip_309  iterable844 ,   struct funenv442  fun846 ) {
    struct Zip_309  temp443 = ( (  into_dash_iter308 ) ( (  iterable844 ) ) );
    struct Zip_309 *  it847 = ( &temp443 );
    while ( ( true ) ) {
        struct Maybe_311  dref848 = ( (  next332 ) ( (  it847 ) ) );
        if ( dref848.tag == Maybe_311_None_t ) {
            return ( Unit_157_Unit );
        }
        else {
            if ( dref848.tag == Maybe_311_Just_t ) {
                struct funenv442  temp444 = (  fun846 );
                ( temp444.fun ( temp444.env ,  ( dref848 .stuff .Maybe_311_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_157_Unit );
}

struct Maybe_446 {
    enum {
        Maybe_446_None_t,
        Maybe_446_Just_t,
    } tag;
    union {
        struct {
            int64_t  field0;
        } Maybe_446_Just_s;
    } stuff;
};

static struct Maybe_446 Maybe_446_Just (  int64_t  field0 ) {
    return ( struct Maybe_446 ) { .tag = Maybe_446_Just_t, .stuff = { .Maybe_446_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_446   reduce445 (    struct ConstStrIter_279  iterable863 ,    struct Maybe_446  base865 ,    struct Maybe_446 (*  fun867 )(    char  ,    struct Maybe_446  ) ) {
    struct Maybe_446  x868 = (  base865 );
    struct ConstStrIter_279  it869 = ( (  into_dash_iter342 ) ( (  iterable863 ) ) );
    while ( ( true ) ) {
        struct Maybe_276  dref870 = ( (  next282 ) ( ( & (  it869 ) ) ) );
        if ( dref870.tag == Maybe_276_None_t ) {
            return (  x868 );
        }
        else {
            if ( dref870.tag == Maybe_276_Just_t ) {
                x868 = ( (  fun867 ) ( ( dref870 .stuff .Maybe_276_Just_s .field0 ) ,  (  x868 ) ) );
            }
        }
    }
    struct Maybe_446  temp447;
    return (  temp447 );
}

static  struct Maybe_446   reduce448 (    struct SliceIter_269  iterable863 ,    struct Maybe_446  base865 ,    struct Maybe_446 (*  fun867 )(    char  ,    struct Maybe_446  ) ) {
    struct Maybe_446  x868 = (  base865 );
    struct SliceIter_269  it869 = ( (  into_dash_iter423 ) ( (  iterable863 ) ) );
    while ( ( true ) ) {
        struct Maybe_276  dref870 = ( (  next313 ) ( ( & (  it869 ) ) ) );
        if ( dref870.tag == Maybe_276_None_t ) {
            return (  x868 );
        }
        else {
            if ( dref870.tag == Maybe_276_Just_t ) {
                x868 = ( (  fun867 ) ( ( dref870 .stuff .Maybe_276_Just_s .field0 ) ,  (  x868 ) ) );
            }
        }
    }
    struct Maybe_446  temp449;
    return (  temp449 );
}

struct SmolArrayIter_451 {
    struct SmolArray_62  f_backing;
    size_t  f_cur;
};

static  struct SmolArrayIter_451   into_dash_iter452 (    struct SmolArray_62  self1872 ) {
    return ( (struct SmolArrayIter_451) { .f_backing = (  self1872 ) , .f_cur = (  from_dash_integral8 ( 0 ) ) } );
}

struct StrConcat_460 {
    const char*  field0;
    size_t  field1;
};

static struct StrConcat_460 StrConcat_460_StrConcat (  const char*  field0 ,  size_t  field1 ) {
    return ( struct StrConcat_460 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_459 {
    struct StrConcat_460  field0;
    const char*  field1;
};

static struct StrConcat_459 StrConcat_459_StrConcat (  struct StrConcat_460  field0 ,  const char*  field1 ) {
    return ( struct StrConcat_459 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_458 {
    struct StrConcat_459  field0;
    int32_t  field1;
};

static struct StrConcat_458 StrConcat_458_StrConcat (  struct StrConcat_459  field0 ,  int32_t  field1 ) {
    return ( struct StrConcat_458 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_457 {
    struct StrConcat_458  field0;
    char  field1;
};

static struct StrConcat_457 StrConcat_457_StrConcat (  struct StrConcat_458  field0 ,  char  field1 ) {
    return ( struct StrConcat_457 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_463 {
    const char*  field0;
    struct StrConcat_457  field1;
};

static struct StrConcat_463 StrConcat_463_StrConcat (  const char*  field0 ,  struct StrConcat_457  field1 ) {
    return ( struct StrConcat_463 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_462 {
    struct StrConcat_463  field0;
    char  field1;
};

static struct StrConcat_462 StrConcat_462_StrConcat (  struct StrConcat_463  field0 ,  char  field1 ) {
    return ( struct StrConcat_462 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_157   print_dash_str465 (    const char*  self1124 ) {
    ( ( printf ) ( ( "%s" ) ,  (  self1124 ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str470 (    size_t  self1181 ) {
    ( ( printf ) ( ( "%lu" ) ,  (  self1181 ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str469 (    struct StrConcat_460  self1220 ) {
    struct StrConcat_460  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str465 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str470 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str468 (    struct StrConcat_459  self1220 ) {
    struct StrConcat_459  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str469 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str465 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str471 (    int32_t  self1157 ) {
    ( ( printf ) ( ( "%d" ) ,  (  self1157 ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str467 (    struct StrConcat_458  self1220 ) {
    struct StrConcat_458  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str468 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str471 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str472 (    char  self1130 ) {
    ( ( printf ) ( ( "%c" ) ,  (  self1130 ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str466 (    struct StrConcat_457  self1220 ) {
    struct StrConcat_457  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str467 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str472 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str464 (    struct StrConcat_463  self1220 ) {
    struct StrConcat_463  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str465 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str466 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str461 (    struct StrConcat_462  self1220 ) {
    struct StrConcat_462  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str464 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str472 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   panic456 (    struct StrConcat_457  errmsg1397 ) {
    ( (  print_dash_str461 ) ( ( ( StrConcat_462_StrConcat ) ( ( ( StrConcat_463_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1397 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral3 ( 1 ) ) ) );
    return ( Unit_157_Unit );
}

static  uint32_t *   get_dash_ptr455 (    struct Array_63 *  arr1834 ,    size_t  i1837 ) {
    if ( ( (  cmp39 ( (  i1837 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1837 ) , ( (size_t ) ( 4 ) ) ) != 0 ) ) ) {
        ( (  panic456 ) ( ( ( StrConcat_457_StrConcat ) ( ( ( StrConcat_458_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( "Access to array at index " ) ,  (  i1837 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 4 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    uint32_t *  p1838 = ( ( (  cast_dash_ptr197 ) ( (  arr1834 ) ) ) );
    return ( (  offset_dash_ptr137 ) ( (  p1838 ) ,  ( (int64_t ) (  i1837 ) ) ) );
}

static  uint32_t   get454 (    struct Array_63 *  arr1841 ,    size_t  i1844 ) {
    return ( * ( (  get_dash_ptr455 ) ( (  arr1841 ) ,  (  i1844 ) ) ) );
}

static  struct Maybe_281   next453 (    struct SmolArrayIter_451 *  self1879 ) {
    if ( (  cmp39 ( ( ( * (  self1879 ) ) .f_cur ) , ( (size_t ) ( 4 ) ) ) != 0 ) ) {
        return ( (struct Maybe_281) { .tag = Maybe_281_None_t } );
    }
    uint32_t  e1881 = ( (  get454 ) ( ( & ( ( ( * (  self1879 ) ) .f_backing ) .f_arr ) ) ,  ( ( * (  self1879 ) ) .f_cur ) ) );
    (*  self1879 ) .f_cur = (  op_dash_add58 ( ( ( * (  self1879 ) ) .f_cur ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_281_Just ) ( (  e1881 ) ) );
}

static  uint32_t   reduce450 (    struct SmolArray_62  iterable863 ,    uint32_t  base865 ,    uint32_t (*  fun867 )(    uint32_t  ,    uint32_t  ) ) {
    uint32_t  x868 = (  base865 );
    struct SmolArrayIter_451  it869 = ( (  into_dash_iter452 ) ( (  iterable863 ) ) );
    while ( ( true ) ) {
        struct Maybe_281  dref870 = ( (  next453 ) ( ( & (  it869 ) ) ) );
        if ( dref870.tag == Maybe_281_None_t ) {
            return (  x868 );
        }
        else {
            if ( dref870.tag == Maybe_281_Just_t ) {
                x868 = ( (  fun867 ) ( ( dref870 .stuff .Maybe_281_Just_s .field0 ) ,  (  x868 ) ) );
            }
        }
    }
    uint32_t  temp473;
    return (  temp473 );
}

struct SmolArrayIter_475 {
    struct SmolArray_65  f_backing;
    size_t  f_cur;
};

static  struct SmolArrayIter_475   into_dash_iter476 (    struct SmolArray_65  self1872 ) {
    return ( (struct SmolArrayIter_475) { .f_backing = (  self1872 ) , .f_cur = (  from_dash_integral8 ( 0 ) ) } );
}

static  uint32_t *   get_dash_ptr479 (    struct Array_66 *  arr1834 ,    size_t  i1837 ) {
    if ( ( (  cmp39 ( (  i1837 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1837 ) , ( (size_t ) ( 5 ) ) ) != 0 ) ) ) {
        ( (  panic456 ) ( ( ( StrConcat_457_StrConcat ) ( ( ( StrConcat_458_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( "Access to array at index " ) ,  (  i1837 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 5 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    uint32_t *  p1838 = ( ( (  cast_dash_ptr198 ) ( (  arr1834 ) ) ) );
    return ( (  offset_dash_ptr137 ) ( (  p1838 ) ,  ( (int64_t ) (  i1837 ) ) ) );
}

static  uint32_t   get478 (    struct Array_66 *  arr1841 ,    size_t  i1844 ) {
    return ( * ( (  get_dash_ptr479 ) ( (  arr1841 ) ,  (  i1844 ) ) ) );
}

static  struct Maybe_281   next477 (    struct SmolArrayIter_475 *  self1879 ) {
    if ( (  cmp39 ( ( ( * (  self1879 ) ) .f_cur ) , ( (size_t ) ( 5 ) ) ) != 0 ) ) {
        return ( (struct Maybe_281) { .tag = Maybe_281_None_t } );
    }
    uint32_t  e1881 = ( (  get478 ) ( ( & ( ( ( * (  self1879 ) ) .f_backing ) .f_arr ) ) ,  ( ( * (  self1879 ) ) .f_cur ) ) );
    (*  self1879 ) .f_cur = (  op_dash_add58 ( ( ( * (  self1879 ) ) .f_cur ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_281_Just ) ( (  e1881 ) ) );
}

static  uint32_t   reduce474 (    struct SmolArray_65  iterable863 ,    uint32_t  base865 ,    uint32_t (*  fun867 )(    uint32_t  ,    uint32_t  ) ) {
    uint32_t  x868 = (  base865 );
    struct SmolArrayIter_475  it869 = ( (  into_dash_iter476 ) ( (  iterable863 ) ) );
    while ( ( true ) ) {
        struct Maybe_281  dref870 = ( (  next477 ) ( ( & (  it869 ) ) ) );
        if ( dref870.tag == Maybe_281_None_t ) {
            return (  x868 );
        }
        else {
            if ( dref870.tag == Maybe_281_Just_t ) {
                x868 = ( (  fun867 ) ( ( dref870 .stuff .Maybe_281_Just_s .field0 ) ,  (  x868 ) ) );
            }
        }
    }
    uint32_t  temp480;
    return (  temp480 );
}

struct SmolArrayIter_482 {
    struct SmolArray_68  f_backing;
    size_t  f_cur;
};

static  struct SmolArrayIter_482   into_dash_iter483 (    struct SmolArray_68  self1872 ) {
    return ( (struct SmolArrayIter_482) { .f_backing = (  self1872 ) , .f_cur = (  from_dash_integral8 ( 0 ) ) } );
}

static  uint32_t *   get_dash_ptr486 (    struct Array_69 *  arr1834 ,    size_t  i1837 ) {
    if ( ( (  cmp39 ( (  i1837 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1837 ) , ( (size_t ) ( 1 ) ) ) != 0 ) ) ) {
        ( (  panic456 ) ( ( ( StrConcat_457_StrConcat ) ( ( ( StrConcat_458_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( "Access to array at index " ) ,  (  i1837 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 1 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    uint32_t *  p1838 = ( ( (  cast_dash_ptr199 ) ( (  arr1834 ) ) ) );
    return ( (  offset_dash_ptr137 ) ( (  p1838 ) ,  ( (int64_t ) (  i1837 ) ) ) );
}

static  uint32_t   get485 (    struct Array_69 *  arr1841 ,    size_t  i1844 ) {
    return ( * ( (  get_dash_ptr486 ) ( (  arr1841 ) ,  (  i1844 ) ) ) );
}

static  struct Maybe_281   next484 (    struct SmolArrayIter_482 *  self1879 ) {
    if ( (  cmp39 ( ( ( * (  self1879 ) ) .f_cur ) , ( (size_t ) ( 1 ) ) ) != 0 ) ) {
        return ( (struct Maybe_281) { .tag = Maybe_281_None_t } );
    }
    uint32_t  e1881 = ( (  get485 ) ( ( & ( ( ( * (  self1879 ) ) .f_backing ) .f_arr ) ) ,  ( ( * (  self1879 ) ) .f_cur ) ) );
    (*  self1879 ) .f_cur = (  op_dash_add58 ( ( ( * (  self1879 ) ) .f_cur ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_281_Just ) ( (  e1881 ) ) );
}

static  uint32_t   reduce481 (    struct SmolArray_68  iterable863 ,    uint32_t  base865 ,    uint32_t (*  fun867 )(    uint32_t  ,    uint32_t  ) ) {
    uint32_t  x868 = (  base865 );
    struct SmolArrayIter_482  it869 = ( (  into_dash_iter483 ) ( (  iterable863 ) ) );
    while ( ( true ) ) {
        struct Maybe_281  dref870 = ( (  next484 ) ( ( & (  it869 ) ) ) );
        if ( dref870.tag == Maybe_281_None_t ) {
            return (  x868 );
        }
        else {
            if ( dref870.tag == Maybe_281_Just_t ) {
                x868 = ( (  fun867 ) ( ( dref870 .stuff .Maybe_281_Just_s .field0 ) ,  (  x868 ) ) );
            }
        }
    }
    uint32_t  temp487;
    return (  temp487 );
}

static  uint32_t   reduce488 (    struct Map_278  iterable863 ,    uint32_t  base865 ,    uint32_t (*  fun867 )(    uint32_t  ,    uint32_t  ) ) {
    uint32_t  x868 = (  base865 );
    struct Map_278  it869 = ( (  into_dash_iter277 ) ( (  iterable863 ) ) );
    while ( ( true ) ) {
        struct Maybe_281  dref870 = ( (  next280 ) ( ( & (  it869 ) ) ) );
        if ( dref870.tag == Maybe_281_None_t ) {
            return (  x868 );
        }
        else {
            if ( dref870.tag == Maybe_281_Just_t ) {
                x868 = ( (  fun867 ) ( ( dref870 .stuff .Maybe_281_Just_s .field0 ) ,  (  x868 ) ) );
            }
        }
    }
    uint32_t  temp489;
    return (  temp489 );
}

static  struct Maybe_446   reduce490 (    struct TakeWhile_349  iterable863 ,    struct Maybe_446  base865 ,    struct Maybe_446 (*  fun867 )(    char  ,    struct Maybe_446  ) ) {
    struct Maybe_446  x868 = (  base865 );
    struct TakeWhile_349  it869 = ( (  into_dash_iter348 ) ( (  iterable863 ) ) );
    while ( ( true ) ) {
        struct Maybe_276  dref870 = ( (  next350 ) ( ( & (  it869 ) ) ) );
        if ( dref870.tag == Maybe_276_None_t ) {
            return (  x868 );
        }
        else {
            if ( dref870.tag == Maybe_276_Just_t ) {
                x868 = ( (  fun867 ) ( ( dref870 .stuff .Maybe_276_Just_s .field0 ) ,  (  x868 ) ) );
            }
        }
    }
    struct Maybe_446  temp491;
    return (  temp491 );
}

static  size_t   reduce492 (    struct TakeWhile_349  iterable863 ,    size_t  base865 ,    size_t (*  fun867 )(    char  ,    size_t  ) ) {
    size_t  x868 = (  base865 );
    struct TakeWhile_349  it869 = ( (  into_dash_iter348 ) ( (  iterable863 ) ) );
    while ( ( true ) ) {
        struct Maybe_276  dref870 = ( (  next350 ) ( ( & (  it869 ) ) ) );
        if ( dref870.tag == Maybe_276_None_t ) {
            return (  x868 );
        }
        else {
            if ( dref870.tag == Maybe_276_Just_t ) {
                x868 = ( (  fun867 ) ( ( dref870 .stuff .Maybe_276_Just_s .field0 ) ,  (  x868 ) ) );
            }
        }
    }
    size_t  temp493;
    return (  temp493 );
}

struct env495 {
    bool (*  fun896 )(    struct Tile_104  );
};

struct funenv495 {
    bool  (*fun) (  struct env495  ,    struct Tile_104  ,    bool  );
    struct env495 env;
};

static  bool   reduce494 (    struct FlattenIter_344  iterable863 ,    bool  base865 ,   struct funenv495  fun867 ) {
    bool  x868 = (  base865 );
    struct FlattenIter_344  it869 = ( (  into_dash_iter343 ) ( (  iterable863 ) ) );
    while ( ( true ) ) {
        struct Maybe_330  dref870 = ( (  next345 ) ( ( & (  it869 ) ) ) );
        if ( dref870.tag == Maybe_330_None_t ) {
            return (  x868 );
        }
        else {
            if ( dref870.tag == Maybe_330_Just_t ) {
                struct funenv495  temp496 = (  fun867 );
                x868 = ( temp496.fun ( temp496.env ,  ( dref870 .stuff .Maybe_330_Just_s .field0 ) ,  (  x868 ) ) );
            }
        }
    }
    bool  temp497;
    return (  temp497 );
}

struct SmolArrayIter_499 {
    struct SmolArray_71  f_backing;
    size_t  f_cur;
};

static  struct SmolArrayIter_499   into_dash_iter500 (    struct SmolArray_71  self1872 ) {
    return ( (struct SmolArrayIter_499) { .f_backing = (  self1872 ) , .f_cur = (  from_dash_integral8 ( 0 ) ) } );
}

static  int32_t *   get_dash_ptr503 (    struct Array_72 *  arr1834 ,    size_t  i1837 ) {
    if ( ( (  cmp39 ( (  i1837 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1837 ) , ( (size_t ) ( 3 ) ) ) != 0 ) ) ) {
        ( (  panic456 ) ( ( ( StrConcat_457_StrConcat ) ( ( ( StrConcat_458_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( "Access to array at index " ) ,  (  i1837 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 3 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    int32_t *  p1838 = ( ( (  cast_dash_ptr207 ) ( (  arr1834 ) ) ) );
    return ( (  offset_dash_ptr141 ) ( (  p1838 ) ,  ( (int64_t ) (  i1837 ) ) ) );
}

static  int32_t   get502 (    struct Array_72 *  arr1841 ,    size_t  i1844 ) {
    return ( * ( (  get_dash_ptr503 ) ( (  arr1841 ) ,  (  i1844 ) ) ) );
}

static  struct Maybe_290   next501 (    struct SmolArrayIter_499 *  self1879 ) {
    if ( (  cmp39 ( ( ( * (  self1879 ) ) .f_cur ) , ( (size_t ) ( 3 ) ) ) != 0 ) ) {
        return ( (struct Maybe_290) { .tag = Maybe_290_None_t } );
    }
    int32_t  e1881 = ( (  get502 ) ( ( & ( ( ( * (  self1879 ) ) .f_backing ) .f_arr ) ) ,  ( ( * (  self1879 ) ) .f_cur ) ) );
    (*  self1879 ) .f_cur = (  op_dash_add58 ( ( ( * (  self1879 ) ) .f_cur ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_290_Just ) ( (  e1881 ) ) );
}

static  int32_t   reduce498 (    struct SmolArray_71  iterable863 ,    int32_t  base865 ,    int32_t (*  fun867 )(    int32_t  ,    int32_t  ) ) {
    int32_t  x868 = (  base865 );
    struct SmolArrayIter_499  it869 = ( (  into_dash_iter500 ) ( (  iterable863 ) ) );
    while ( ( true ) ) {
        struct Maybe_290  dref870 = ( (  next501 ) ( ( & (  it869 ) ) ) );
        if ( dref870.tag == Maybe_290_None_t ) {
            return (  x868 );
        }
        else {
            if ( dref870.tag == Maybe_290_Just_t ) {
                x868 = ( (  fun867 ) ( ( dref870 .stuff .Maybe_290_Just_s .field0 ) ,  (  x868 ) ) );
            }
        }
    }
    int32_t  temp504;
    return (  temp504 );
}

struct env506 {
    ;
    int32_t  base980;
};

struct funenv506 {
    int32_t  (*fun) (  struct env506  ,    int32_t  ,    int32_t  );
    struct env506 env;
};

static  int32_t   reduce505 (    struct Range_286  iterable863 ,    int32_t  base865 ,   struct funenv506  fun867 ) {
    int32_t  x868 = (  base865 );
    struct RangeIter_288  it869 = ( (  into_dash_iter287 ) ( (  iterable863 ) ) );
    while ( ( true ) ) {
        struct Maybe_290  dref870 = ( (  next289 ) ( ( & (  it869 ) ) ) );
        if ( dref870.tag == Maybe_290_None_t ) {
            return (  x868 );
        }
        else {
            if ( dref870.tag == Maybe_290_Just_t ) {
                struct funenv506  temp507 = (  fun867 );
                x868 = ( temp507.fun ( temp507.env ,  ( dref870 .stuff .Maybe_290_Just_s .field0 ) ,  (  x868 ) ) );
            }
        }
    }
    int32_t  temp508;
    return (  temp508 );
}

static  size_t   reduce509 (    struct ConstStrIter_279  iterable863 ,    size_t  base865 ,    size_t (*  fun867 )(    char  ,    size_t  ) ) {
    size_t  x868 = (  base865 );
    struct ConstStrIter_279  it869 = ( (  into_dash_iter342 ) ( (  iterable863 ) ) );
    while ( ( true ) ) {
        struct Maybe_276  dref870 = ( (  next282 ) ( ( & (  it869 ) ) ) );
        if ( dref870.tag == Maybe_276_None_t ) {
            return (  x868 );
        }
        else {
            if ( dref870.tag == Maybe_276_Just_t ) {
                x868 = ( (  fun867 ) ( ( dref870 .stuff .Maybe_276_Just_s .field0 ) ,  (  x868 ) ) );
            }
        }
    }
    size_t  temp510;
    return (  temp510 );
}

static  size_t   lam512 (    char  dref875 ,    size_t  x877 ) {
    return (  op_dash_add58 ( (  x877 ) , (  from_dash_integral8 ( 1 ) ) ) );
}

static  size_t   count511 (    struct TakeWhile_349  it874 ) {
    return ( (  reduce492 ) ( (  it874 ) ,  (  from_dash_integral8 ( 0 ) ) ,  (  lam512 ) ) );
}

static  size_t   lam514 (    char  dref875 ,    size_t  x877 ) {
    return (  op_dash_add58 ( (  x877 ) , (  from_dash_integral8 ( 1 ) ) ) );
}

static  size_t   count513 (    struct ConstStrIter_279  it874 ) {
    return ( (  reduce509 ) ( (  it874 ) ,  (  from_dash_integral8 ( 0 ) ) ,  (  lam514 ) ) );
}

static  bool   lam495 (   struct env495 env ,    struct Tile_104  e898 ,    bool  x900 ) {
    return ( ( ( env.fun896 ) ( (  e898 ) ) ) && (  x900 ) );
}

static  bool   all515 (    struct FlattenIter_344  it894 ,    bool (*  fun896 )(    struct Tile_104  ) ) {
    struct env495 envinst495 = {
        .fun896 =  fun896 ,
    };
    return ( (  reduce494 ) ( (  it894 ) ,  ( true ) ,  ( (struct funenv495){ .fun = lam495, .env = envinst495 } ) ) );
}

static  struct Maybe_276   head516 (    struct ConstStrIter_279  it912 ) {
    struct ConstStrIter_279  temp517 = ( (  into_dash_iter342 ) ( (  it912 ) ) );
    return ( (  next282 ) ( ( &temp517 ) ) );
}

static  struct Maybe_276   head518 (    struct SliceIter_269  it912 ) {
    struct SliceIter_269  temp519 = ( (  into_dash_iter423 ) ( (  it912 ) ) );
    return ( (  next313 ) ( ( &temp519 ) ) );
}

static  struct Maybe_276   head520 (    struct TakeWhile_349  it912 ) {
    struct TakeWhile_349  temp521 = ( (  into_dash_iter348 ) ( (  it912 ) ) );
    return ( (  next350 ) ( ( &temp521 ) ) );
}

struct IntStrIter_523 {
    int32_t  f_int;
    int32_t  f_len;
};

static  int32_t   lam506 (   struct env506 env ,    int32_t  item984 ,    int32_t  x986 ) {
    return (  op_dash_mul49 ( (  x986 ) , ( env.base980 ) ) );
}

static  int32_t   pow525 (    int32_t  base980 ,    int32_t  p982 ) {
    struct env506 envinst506 = {
        .base980 =  base980 ,
    };
    return ( (  reduce505 ) ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  op_dash_sub48 ( (  p982 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) ,  (  from_dash_integral3 ( 1 ) ) ,  ( (struct funenv506){ .fun = lam506, .env = envinst506 } ) ) );
}

static  struct Maybe_276   next524 (    struct IntStrIter_523 *  self1145 ) {
    if ( (  cmp40 ( ( ( * (  self1145 ) ) .f_len ) , (  from_dash_integral3 ( 0 ) ) ) != 2 ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    int32_t  trim_dash_down1146 = ( (  pow525 ) ( (  from_dash_integral3 ( 10 ) ) ,  (  op_dash_sub48 ( ( ( * (  self1145 ) ) .f_len ) , (  from_dash_integral3 ( 1 ) ) ) ) ) );
    int32_t  upper1147 = (  op_dash_div50 ( ( ( * (  self1145 ) ) .f_int ) , (  trim_dash_down1146 ) ) );
    int32_t  upper_dash_mask1148 = (  op_dash_mul49 ( (  op_dash_div50 ( (  upper1147 ) , (  from_dash_integral3 ( 10 ) ) ) ) , (  from_dash_integral3 ( 10 ) ) ) );
    int32_t  digit1149 = (  op_dash_sub48 ( (  upper1147 ) , (  upper_dash_mask1148 ) ) );
    (*  self1145 ) .f_len = (  op_dash_sub48 ( ( ( * (  self1145 ) ) .f_len ) , (  from_dash_integral3 ( 1 ) ) ) );
    char  digit_dash_char1150 = ( (  cast177 ) ( (  op_dash_add47 ( (  digit1149 ) , (  from_dash_integral3 ( 48 ) ) ) ) ) );
    return ( ( Maybe_276_Just ) ( (  digit_dash_char1150 ) ) );
}

static  struct IntStrIter_523   into_dash_iter527 (    struct IntStrIter_523  self1142 ) {
    return (  self1142 );
}

static  struct Maybe_276   head522 (    struct IntStrIter_523  it912 ) {
    struct IntStrIter_523  temp526 = ( (  into_dash_iter527 ) ( (  it912 ) ) );
    return ( (  next524 ) ( ( &temp526 ) ) );
}

static  bool   null528 (    struct TakeWhile_349  it921 ) {
    struct Maybe_276  dref922 = ( (  head520 ) ( (  it921 ) ) );
    if ( dref922.tag == Maybe_276_None_t ) {
        return ( true );
    }
    else {
        if ( true ) {
            return ( false );
        }
    }
}

static  struct Maybe_276   lam407 (   struct env407 env ,    int32_t  dref959 ) {
    return ( (  next351 ) ( ( env.it956 ) ) );
}

static  enum Unit_157   drop_prime_529 (    struct Scanner_268 *  it956 ,    size_t  n958 ) {
    struct env407 envinst407 = {
        .it956 =  it956 ,
    };
    ( (  for_dash_each406 ) ( ( (  to285 ) ( (  from_dash_integral3 ( 1 ) ) ,  ( (  size_dash_i32260 ) ( (  n958 ) ) ) ) ) ,  ( (struct funenv407){ .fun = lam407, .env = envinst407 } ) ) );
    return ( Unit_157_Unit );
}

struct Tuple2_531 {
    int32_t  field0;
    int32_t  field1;
};

static struct Tuple2_531 Tuple2_531_Tuple2 (  int32_t  field0 ,  int32_t  field1 ) {
    return ( struct Tuple2_531 ) { .field0 = field0 ,  .field1 = field1 };
};

static  int32_t   fst530 (    struct Tuple2_531  dref1020 ) {
    return ( dref1020 .field0 );
}

struct Tuple2_533 {
    uint32_t  field0;
    uint32_t  field1;
};

static struct Tuple2_533 Tuple2_533_Tuple2 (  uint32_t  field0 ,  uint32_t  field1 ) {
    return ( struct Tuple2_533 ) { .field0 = field0 ,  .field1 = field1 };
};

static  uint32_t   fst532 (    struct Tuple2_533  dref1020 ) {
    return ( dref1020 .field0 );
}

static  int32_t   snd534 (    struct Tuple2_531  dref1023 ) {
    return ( dref1023 .field1 );
}

static  uint32_t   snd535 (    struct Tuple2_533  dref1023 ) {
    return ( dref1023 .field1 );
}

struct Maybe_537 {
    enum {
        Maybe_537_None_t,
        Maybe_537_Just_t,
    } tag;
    union {
        struct {
            struct DynStr_417  field0;
        } Maybe_537_Just_s;
    } stuff;
};

static struct Maybe_537 Maybe_537_Just (  struct DynStr_417  field0 ) {
    return ( struct Maybe_537 ) { .tag = Maybe_537_Just_t, .stuff = { .Maybe_537_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_446   and_dash_maybe536 (    struct Maybe_537  m1031 ,    struct Maybe_446 (*  fun1033 )(    struct DynStr_417  ) ) {
    struct Maybe_537  dref1034 = (  m1031 );
    if ( dref1034.tag == Maybe_537_None_t ) {
        return ( (struct Maybe_446) { .tag = Maybe_446_None_t } );
    }
    else {
        if ( dref1034.tag == Maybe_537_Just_t ) {
            return ( (  fun1033 ) ( ( dref1034 .stuff .Maybe_537_Just_s .field0 ) ) );
        }
    }
}

struct env539 {
    size_t  x2610;
    ;
};

struct funenv539 {
    struct Maybe_330  (*fun) (  struct env539  ,    struct Slice_103  );
    struct env539 env;
};

static  struct Maybe_330   and_dash_maybe538 (    struct Maybe_325  m1031 ,   struct funenv539  fun1033 ) {
    struct Maybe_325  dref1034 = (  m1031 );
    if ( dref1034.tag == Maybe_325_None_t ) {
        return ( (struct Maybe_330) { .tag = Maybe_330_None_t } );
    }
    else {
        if ( dref1034.tag == Maybe_325_Just_t ) {
            struct funenv539  temp540 = (  fun1033 );
            return ( temp540.fun ( temp540.env ,  ( dref1034 .stuff .Maybe_325_Just_s .field0 ) ) );
        }
    }
}

struct env542 {
    ;
    enum CAllocator_383  al3020;
};

struct funenv542 {
    enum Unit_157  (*fun) (  struct env542  ,    const char*  );
    struct env542 env;
};

struct env543 {
    ;
    enum CAllocator_383  al3020;
};

struct funenv543 {
    struct Maybe_537  (*fun) (  struct env543  ,    const char*  );
    struct env543 env;
};

static  struct Maybe_537   with541 (    const char*  res1054 ,   struct funenv542  free_dash_fun1056 ,   struct funenv543  fun1058 ) {
    struct funenv543  temp544 = (  fun1058 );
    struct Maybe_537  ret1059 = ( temp544.fun ( temp544.env ,  (  res1054 ) ) );
    struct funenv542  temp545 = (  free_dash_fun1056 );
    ( temp545.fun ( temp545.env ,  (  res1054 ) ) );
    return (  ret1059 );
}

struct env547 {
    ;
    enum CAllocator_383  al3046;
};

struct funenv547 {
    enum Unit_157  (*fun) (  struct env547  ,    const char*  );
    struct env547 env;
};

struct Stats_549 {
    uint32_t  f_total_dash_wins;
};

struct env548 {
    ;
    struct Stats_549  stats3044;
    ;
};

struct funenv548 {
    enum Unit_157  (*fun) (  struct env548  ,    const char*  );
    struct env548 env;
};

static  enum Unit_157   with546 (    const char*  res1054 ,   struct funenv547  free_dash_fun1056 ,   struct funenv548  fun1058 ) {
    struct funenv548  temp550 = (  fun1058 );
    enum Unit_157  ret1059 = ( temp550.fun ( temp550.env ,  (  res1054 ) ) );
    struct funenv547  temp551 = (  free_dash_fun1056 );
    ( temp551.fun ( temp551.env ,  (  res1054 ) ) );
    return (  ret1059 );
}

static  uint32_t   mod552 (    uint32_t  l999 ,    uint32_t  d1001 ) {
    uint32_t  r1002 = (  op_dash_div55 ( (  l999 ) , (  d1001 ) ) );
    uint32_t  m1003 = (  op_dash_sub53 ( (  l999 ) , (  op_dash_mul54 ( (  r1002 ) , (  d1001 ) ) ) ) );
    if ( (  cmp41 ( (  m1003 ) , (  from_dash_integral4 ( 0 ) ) ) == 0 ) ) {
        return (  op_dash_add52 ( (  d1001 ) , (  m1003 ) ) );
    } else {
        return (  m1003 );
    }
}

static  int32_t   mod553 (    int32_t  l999 ,    int32_t  d1001 ) {
    int32_t  r1002 = (  op_dash_div50 ( (  l999 ) , (  d1001 ) ) );
    int32_t  m1003 = (  op_dash_sub48 ( (  l999 ) , (  op_dash_mul49 ( (  r1002 ) , (  d1001 ) ) ) ) );
    if ( (  cmp40 ( (  m1003 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) ) {
        return (  op_dash_add47 ( (  d1001 ) , (  m1003 ) ) );
    } else {
        return (  m1003 );
    }
}

static  size_t   min554 (    size_t  l1006 ,    size_t  r1008 ) {
    if ( (  cmp39 ( (  l1006 ) , (  r1008 ) ) == 0 ) ) {
        return (  l1006 );
    } else {
        return (  r1008 );
    }
}

static  int32_t   min555 (    int32_t  l1006 ,    int32_t  r1008 ) {
    if ( (  cmp40 ( (  l1006 ) , (  r1008 ) ) == 0 ) ) {
        return (  l1006 );
    } else {
        return (  r1008 );
    }
}

static  struct ConstStrIter_279   chars556 (    const char*  self1127 ) {
    return ( (  into_dash_iter284 ) ( (  self1127 ) ) );
}

static  struct AppendIter_354   chars557 (    char  self1133 ) {
    return ( (  single356 ) ( (  self1133 ) ) );
}

static  int32_t   count_dash_digits558 (    uint32_t  self1153 ) {
    if ( (  eq10 ( (  self1153 ) , (  from_dash_integral4 ( 0 ) ) ) ) ) {
        return (  from_dash_integral3 ( 1 ) );
    }
    int32_t  digits1154 = (  from_dash_integral3 ( 0 ) );
    while ( (  cmp41 ( (  self1153 ) , (  from_dash_integral4 ( 0 ) ) ) == 2 ) ) {
        self1153 = (  op_dash_div55 ( (  self1153 ) , (  from_dash_integral4 ( 10 ) ) ) );
        digits1154 = (  op_dash_add47 ( (  digits1154 ) , (  from_dash_integral3 ( 1 ) ) ) );
    }
    return (  digits1154 );
}

static  int32_t   count_dash_digits559 (    int32_t  self1153 ) {
    if ( (  eq9 ( (  self1153 ) , (  from_dash_integral3 ( 0 ) ) ) ) ) {
        return (  from_dash_integral3 ( 1 ) );
    }
    int32_t  digits1154 = (  from_dash_integral3 ( 0 ) );
    while ( (  cmp40 ( (  self1153 ) , (  from_dash_integral3 ( 0 ) ) ) == 2 ) ) {
        self1153 = (  op_dash_div50 ( (  self1153 ) , (  from_dash_integral3 ( 10 ) ) ) );
        digits1154 = (  op_dash_add47 ( (  digits1154 ) , (  from_dash_integral3 ( 1 ) ) ) );
    }
    return (  digits1154 );
}

static  struct IntStrIter_523   chars560 (    int32_t  self1160 ) {
    return ( (struct IntStrIter_523) { .f_int = (  self1160 ) , .f_len = ( (  count_dash_digits559 ) ( (  self1160 ) ) ) } );
}

static  enum Unit_157   print_dash_str561 (    uint32_t  self1163 ) {
    ( ( printf ) ( ( "%u" ) ,  (  self1163 ) ) );
    return ( Unit_157_Unit );
}

static  struct IntStrIter_300   chars562 (    uint32_t  self1166 ) {
    return ( (struct IntStrIter_300) { .f_int = (  self1166 ) , .f_len = ( (  count_dash_digits558 ) ( (  self1166 ) ) ) } );
}

static  enum Unit_157   print_dash_str563 (    uint8_t  self1169 ) {
    ( ( printf ) ( ( "%d" ) ,  ( (  u8_dash_i32266 ) ( (  self1169 ) ) ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str564 (    int64_t  self1175 ) {
    ( ( printf ) ( ( "%ld" ) ,  (  self1175 ) ) );
    return ( Unit_157_Unit );
}

struct StrConcatIter_566 {
    struct IntStrIter_300  f_left;
    struct AppendIter_354  f_right;
};

static  struct Maybe_276   next565 (    struct StrConcatIter_566 *  self1211 ) {
    struct Maybe_276  dref1212 = ( (  next316 ) ( ( & ( ( * (  self1211 ) ) .f_left ) ) ) );
    if ( dref1212.tag == Maybe_276_Just_t ) {
        return ( ( Maybe_276_Just ) ( ( dref1212 .stuff .Maybe_276_Just_s .field0 ) ) );
    }
    else {
        if ( dref1212.tag == Maybe_276_None_t ) {
            return ( (  next357 ) ( ( & ( ( * (  self1211 ) ) .f_right ) ) ) );
        }
    }
}

struct StrConcat_570 {
    const char*  field0;
    const char*  field1;
};

static struct StrConcat_570 StrConcat_570_StrConcat (  const char*  field0 ,  const char*  field1 ) {
    return ( struct StrConcat_570 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrCase_569 {
    enum {
        StrCase_569_StrCase1_t,
        StrCase_569_StrCase2_t,
    } tag;
    union {
        struct {
            const char*  field0;
        } StrCase_569_StrCase1_s;
        struct {
            struct StrConcat_570  field0;
        } StrCase_569_StrCase2_s;
    } stuff;
};

static struct StrCase_569 StrCase_569_StrCase1 (  const char*  field0 ) {
    return ( struct StrCase_569 ) { .tag = StrCase_569_StrCase1_t, .stuff = { .StrCase_569_StrCase1_s = { .field0 = field0 } } };
};

static struct StrCase_569 StrCase_569_StrCase2 (  struct StrConcat_570  field0 ) {
    return ( struct StrCase_569 ) { .tag = StrCase_569_StrCase2_t, .stuff = { .StrCase_569_StrCase2_s = { .field0 = field0 } } };
};

struct StrConcat_568 {
    struct StrCase_569  field0;
    const char*  field1;
};

static struct StrConcat_568 StrConcat_568_StrConcat (  struct StrCase_569  field0 ,  const char*  field1 ) {
    return ( struct StrConcat_568 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct StrConcatIter_379   into_dash_iter574 (    struct StrConcat_570  dref1215 ) {
    return ( (struct StrConcatIter_379) { .f_left = ( (  chars556 ) ( ( dref1215 .field0 ) ) ) , .f_right = ( (  chars556 ) ( ( dref1215 .field1 ) ) ) } );
}

static  struct StrConcatIter_379   chars573 (    struct StrConcat_570  self1226 ) {
    return ( (  into_dash_iter574 ) ( (  self1226 ) ) );
}

static  struct StrCaseIter_378   into_dash_iter572 (    struct StrCase_569  self1239 ) {
    struct StrCase_569  dref1240 = (  self1239 );
    if ( dref1240.tag == StrCase_569_StrCase1_t ) {
        return ( ( StrCaseIter_378_StrCaseIter1 ) ( ( (  chars556 ) ( ( dref1240 .stuff .StrCase_569_StrCase1_s .field0 ) ) ) ) );
    }
    else {
        if ( dref1240.tag == StrCase_569_StrCase2_t ) {
            return ( ( StrCaseIter_378_StrCaseIter2 ) ( ( (  chars573 ) ( ( dref1240 .stuff .StrCase_569_StrCase2_s .field0 ) ) ) ) );
        }
    }
}

static  struct StrCaseIter_378   chars571 (    struct StrCase_569  self1251 ) {
    return ( (  into_dash_iter572 ) ( (  self1251 ) ) );
}

static  struct StrConcatIter_377   into_dash_iter567 (    struct StrConcat_568  dref1215 ) {
    return ( (struct StrConcatIter_377) { .f_left = ( (  chars571 ) ( ( dref1215 .field0 ) ) ) , .f_right = ( (  chars556 ) ( ( dref1215 .field1 ) ) ) } );
}

struct StrConcat_576 {
    struct StrConcat_568  field0;
    const char*  field1;
};

static struct StrConcat_576 StrConcat_576_StrConcat (  struct StrConcat_568  field0 ,  const char*  field1 ) {
    return ( struct StrConcat_576 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct StrConcatIter_377   chars577 (    struct StrConcat_568  self1226 ) {
    return ( (  into_dash_iter567 ) ( (  self1226 ) ) );
}

static  struct StrConcatIter_426   into_dash_iter575 (    struct StrConcat_576  dref1215 ) {
    return ( (struct StrConcatIter_426) { .f_left = ( (  chars577 ) ( ( dref1215 .field0 ) ) ) , .f_right = ( (  chars556 ) ( ( dref1215 .field1 ) ) ) } );
}

struct StrConcat_579 {
    uint32_t  field0;
    char  field1;
};

static struct StrConcat_579 StrConcat_579_StrConcat (  uint32_t  field0 ,  char  field1 ) {
    return ( struct StrConcat_579 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct StrConcatIter_566   into_dash_iter578 (    struct StrConcat_579  dref1215 ) {
    return ( (struct StrConcatIter_566) { .f_left = ( (  chars562 ) ( ( dref1215 .field0 ) ) ) , .f_right = ( (  chars557 ) ( ( dref1215 .field1 ) ) ) } );
}

struct StrConcat_581 {
    const char*  field0;
    uint32_t  field1;
};

static struct StrConcat_581 StrConcat_581_StrConcat (  const char*  field0 ,  uint32_t  field1 ) {
    return ( struct StrConcat_581 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct StrConcatIter_299   into_dash_iter580 (    struct StrConcat_581  dref1215 ) {
    return ( (struct StrConcatIter_299) { .f_left = ( (  chars556 ) ( ( dref1215 .field0 ) ) ) , .f_right = ( (  chars562 ) ( ( dref1215 .field1 ) ) ) } );
}

struct StrConcat_583 {
    struct StrConcat_570  field0;
    char  field1;
};

static struct StrConcat_583 StrConcat_583_StrConcat (  struct StrConcat_570  field0 ,  char  field1 ) {
    return ( struct StrConcat_583 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_157   print_dash_str584 (    struct StrConcat_570  self1220 ) {
    struct StrConcat_570  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str465 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str465 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str582 (    struct StrConcat_583  self1220 ) {
    struct StrConcat_583  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str584 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str472 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

struct StrConcat_587 {
    struct StrConcat_459  field0;
    size_t  field1;
};

static struct StrConcat_587 StrConcat_587_StrConcat (  struct StrConcat_459  field0 ,  size_t  field1 ) {
    return ( struct StrConcat_587 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_586 {
    struct StrConcat_587  field0;
    char  field1;
};

static struct StrConcat_586 StrConcat_586_StrConcat (  struct StrConcat_587  field0 ,  char  field1 ) {
    return ( struct StrConcat_586 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_157   print_dash_str588 (    struct StrConcat_587  self1220 ) {
    struct StrConcat_587  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str468 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str470 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str585 (    struct StrConcat_586  self1220 ) {
    struct StrConcat_586  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str588 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str472 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

struct StrConcat_591 {
    const char*  field0;
    struct StrConcat_586  field1;
};

static struct StrConcat_591 StrConcat_591_StrConcat (  const char*  field0 ,  struct StrConcat_586  field1 ) {
    return ( struct StrConcat_591 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_590 {
    struct StrConcat_591  field0;
    char  field1;
};

static struct StrConcat_590 StrConcat_590_StrConcat (  struct StrConcat_591  field0 ,  char  field1 ) {
    return ( struct StrConcat_590 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_157   print_dash_str592 (    struct StrConcat_591  self1220 ) {
    struct StrConcat_591  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str465 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str585 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str589 (    struct StrConcat_590  self1220 ) {
    struct StrConcat_590  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str592 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str472 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

struct StrConcat_595 {
    char  field0;
    char  field1;
};

static struct StrConcat_595 StrConcat_595_StrConcat (  char  field0 ,  char  field1 ) {
    return ( struct StrConcat_595 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_594 {
    struct StrConcat_595  field0;
    const char*  field1;
};

static struct StrConcat_594 StrConcat_594_StrConcat (  struct StrConcat_595  field0 ,  const char*  field1 ) {
    return ( struct StrConcat_594 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_157   print_dash_str596 (    struct StrConcat_595  self1220 ) {
    struct StrConcat_595  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str472 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str472 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str593 (    struct StrConcat_594  self1220 ) {
    struct StrConcat_594  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str596 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str465 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

struct StrConcat_599 {
    const char*  field0;
    struct StrConcat_594  field1;
};

static struct StrConcat_599 StrConcat_599_StrConcat (  const char*  field0 ,  struct StrConcat_594  field1 ) {
    return ( struct StrConcat_599 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_598 {
    struct StrConcat_599  field0;
    char  field1;
};

static struct StrConcat_598 StrConcat_598_StrConcat (  struct StrConcat_599  field0 ,  char  field1 ) {
    return ( struct StrConcat_598 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_157   print_dash_str600 (    struct StrConcat_599  self1220 ) {
    struct StrConcat_599  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str465 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str593 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str597 (    struct StrConcat_598  self1220 ) {
    struct StrConcat_598  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str600 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str472 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

struct StrConcat_602 {
    const char*  field0;
    int64_t  field1;
};

static struct StrConcat_602 StrConcat_602_StrConcat (  const char*  field0 ,  int64_t  field1 ) {
    return ( struct StrConcat_602 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_157   print_dash_str601 (    struct StrConcat_602  self1220 ) {
    struct StrConcat_602  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str465 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str564 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

struct StrConcat_605 {
    const char*  field0;
    struct StrConcat_602  field1;
};

static struct StrConcat_605 StrConcat_605_StrConcat (  const char*  field0 ,  struct StrConcat_602  field1 ) {
    return ( struct StrConcat_605 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_604 {
    struct StrConcat_605  field0;
    char  field1;
};

static struct StrConcat_604 StrConcat_604_StrConcat (  struct StrConcat_605  field0 ,  char  field1 ) {
    return ( struct StrConcat_604 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_157   print_dash_str606 (    struct StrConcat_605  self1220 ) {
    struct StrConcat_605  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str465 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str601 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str603 (    struct StrConcat_604  self1220 ) {
    struct StrConcat_604  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str606 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str472 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

struct StrConcat_609 {
    const char*  field0;
    struct StrConcat_570  field1;
};

static struct StrConcat_609 StrConcat_609_StrConcat (  const char*  field0 ,  struct StrConcat_570  field1 ) {
    return ( struct StrConcat_609 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_608 {
    struct StrConcat_609  field0;
    char  field1;
};

static struct StrConcat_608 StrConcat_608_StrConcat (  struct StrConcat_609  field0 ,  char  field1 ) {
    return ( struct StrConcat_608 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_157   print_dash_str610 (    struct StrConcat_609  self1220 ) {
    struct StrConcat_609  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str465 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str584 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str607 (    struct StrConcat_608  self1220 ) {
    struct StrConcat_608  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str610 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str472 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

struct StrConcat_614 {
    struct StrConcat_581  field0;
    char  field1;
};

static struct StrConcat_614 StrConcat_614_StrConcat (  struct StrConcat_581  field0 ,  char  field1 ) {
    return ( struct StrConcat_614 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_613 {
    struct StrConcat_614  field0;
    uint32_t  field1;
};

static struct StrConcat_613 StrConcat_613_StrConcat (  struct StrConcat_614  field0 ,  uint32_t  field1 ) {
    return ( struct StrConcat_613 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_612 {
    struct StrConcat_613  field0;
    char  field1;
};

static struct StrConcat_612 StrConcat_612_StrConcat (  struct StrConcat_613  field0 ,  char  field1 ) {
    return ( struct StrConcat_612 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_157   print_dash_str617 (    struct StrConcat_581  self1220 ) {
    struct StrConcat_581  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str465 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str561 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str616 (    struct StrConcat_614  self1220 ) {
    struct StrConcat_614  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str617 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str472 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str615 (    struct StrConcat_613  self1220 ) {
    struct StrConcat_613  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str616 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str561 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str611 (    struct StrConcat_612  self1220 ) {
    struct StrConcat_612  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str615 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str472 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
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

static  enum Unit_157   print_dash_str621 (    struct StrConcat_620  self1220 ) {
    struct StrConcat_620  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str465 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str563 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str618 (    struct StrConcat_619  self1220 ) {
    struct StrConcat_619  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str621 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str472 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

struct StrConcat_626 {
    struct StrConcat_619  field0;
    uint8_t  field1;
};

static struct StrConcat_626 StrConcat_626_StrConcat (  struct StrConcat_619  field0 ,  uint8_t  field1 ) {
    return ( struct StrConcat_626 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_625 {
    struct StrConcat_626  field0;
    char  field1;
};

static struct StrConcat_625 StrConcat_625_StrConcat (  struct StrConcat_626  field0 ,  char  field1 ) {
    return ( struct StrConcat_625 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_624 {
    struct StrConcat_625  field0;
    uint8_t  field1;
};

static struct StrConcat_624 StrConcat_624_StrConcat (  struct StrConcat_625  field0 ,  uint8_t  field1 ) {
    return ( struct StrConcat_624 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_623 {
    struct StrConcat_624  field0;
    char  field1;
};

static struct StrConcat_623 StrConcat_623_StrConcat (  struct StrConcat_624  field0 ,  char  field1 ) {
    return ( struct StrConcat_623 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_157   print_dash_str629 (    struct StrConcat_626  self1220 ) {
    struct StrConcat_626  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str618 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str563 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str628 (    struct StrConcat_625  self1220 ) {
    struct StrConcat_625  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str629 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str472 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str627 (    struct StrConcat_624  self1220 ) {
    struct StrConcat_624  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str628 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str563 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   print_dash_str622 (    struct StrConcat_623  self1220 ) {
    struct StrConcat_623  dref1221 = (  self1220 );
    if ( true ) {
        ( (  print_dash_str627 ) ( ( dref1221 .field0 ) ) );
        ( (  print_dash_str472 ) ( ( dref1221 .field1 ) ) );
    }
    return ( Unit_157_Unit );
}

static  struct StrConcatIter_426   chars630 (    struct StrConcat_576  self1226 ) {
    return ( (  into_dash_iter575 ) ( (  self1226 ) ) );
}

static  struct StrConcatIter_566   chars631 (    struct StrConcat_579  self1226 ) {
    return ( (  into_dash_iter578 ) ( (  self1226 ) ) );
}

static  struct StrConcatIter_299   chars632 (    struct StrConcat_581  self1226 ) {
    return ( (  into_dash_iter580 ) ( (  self1226 ) ) );
}

static  struct TakeWhile_349   chars633 (    struct TakeWhile_349  self1336 ) {
    return (  self1336 );
}

static  char   nullchar634 (  ) {
    return ( (  zeroed214 ) ( ) );
}

static  int32_t   char_dash_i32635 (    char  c1363 ) {
    return ( (  cast_dash_on_dash_zeroed232 ) ( (  c1363 ) ) );
}

static  uint8_t   char_dash_u8636 (    char  c1366 ) {
    return ( (  cast179 ) ( (  c1366 ) ) );
}

static  char   i32_dash_char637 (    int32_t  i1369 ) {
    return ( (  cast177 ) ( (  i1369 ) ) );
}

static  bool   eq638 (    const char*  l1382 ,    const char*  r1384 ) {
    return (  eq9 ( ( ( strcmp ) ( (  l1382 ) ,  (  r1384 ) ) ) , (  from_dash_integral3 ( 0 ) ) ) );
}

static  enum Ordering_38   cmp639 (    char  l1387 ,    char  r1389 ) {
    return ( (  cmp40 ) ( ( (  char_dash_i32635 ) ( (  l1387 ) ) ) ,  ( (  char_dash_i32635 ) ( (  r1389 ) ) ) ) );
}

static  bool   unreachable640 (  ) {
    ( (  print_dash_str465 ) ( ( "unreachable\n" ) ) );
    ( ( exit ) ( (  from_dash_integral3 ( 1 ) ) ) );
    return ( (  undefined123 ) ( ) );
}

static  enum Unit_157   panic641 (    const char*  errmsg1397 ) {
    ( (  print_dash_str582 ) ( ( ( StrConcat_583_StrConcat ) ( ( ( StrConcat_570_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1397 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral3 ( 1 ) ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   panic642 (    struct StrConcat_586  errmsg1397 ) {
    ( (  print_dash_str589 ) ( ( ( StrConcat_590_StrConcat ) ( ( ( StrConcat_591_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1397 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral3 ( 1 ) ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   panic643 (    struct StrConcat_594  errmsg1397 ) {
    ( (  print_dash_str597 ) ( ( ( StrConcat_598_StrConcat ) ( ( ( StrConcat_599_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1397 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral3 ( 1 ) ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   panic644 (    struct StrConcat_570  errmsg1397 ) {
    ( (  print_dash_str607 ) ( ( ( StrConcat_608_StrConcat ) ( ( ( StrConcat_609_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1397 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral3 ( 1 ) ) ) );
    return ( Unit_157_Unit );
}

static  enum MouseButton_119   panic_prime_645 (    struct StrConcat_602  errmsg1400 ) {
    ( (  print_dash_str603 ) ( ( ( StrConcat_604_StrConcat ) ( ( ( StrConcat_605_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1400 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral3 ( 1 ) ) ) );
    return ( (  undefined118 ) ( ) );
}

static  int64_t   or_dash_fail646 (    struct Maybe_446  x1410 ,    const char*  errmsg1412 ) {
    struct Maybe_446  dref1413 = (  x1410 );
    if ( dref1413.tag == Maybe_446_None_t ) {
        ( (  panic641 ) ( (  errmsg1412 ) ) );
        return ( (  undefined98 ) ( ) );
    }
    else {
        if ( dref1413.tag == Maybe_446_Just_t ) {
            return ( dref1413 .stuff .Maybe_446_Just_s .field0 );
        }
    }
}

static  char   or_dash_fail647 (    struct Maybe_276  x1410 ,    struct StrConcat_586  errmsg1412 ) {
    struct Maybe_276  dref1413 = (  x1410 );
    if ( dref1413.tag == Maybe_276_None_t ) {
        ( (  panic642 ) ( (  errmsg1412 ) ) );
        return ( (  undefined100 ) ( ) );
    }
    else {
        if ( dref1413.tag == Maybe_276_Just_t ) {
            return ( dref1413 .stuff .Maybe_276_Just_s .field0 );
        }
    }
}

static  struct Slice_103   or_dash_fail648 (    struct Maybe_325  x1410 ,    struct StrConcat_586  errmsg1412 ) {
    struct Maybe_325  dref1413 = (  x1410 );
    if ( dref1413.tag == Maybe_325_None_t ) {
        ( (  panic642 ) ( (  errmsg1412 ) ) );
        return ( (  undefined102 ) ( ) );
    }
    else {
        if ( dref1413.tag == Maybe_325_Just_t ) {
            return ( dref1413 .stuff .Maybe_325_Just_s .field0 );
        }
    }
}

static  struct Tile_104   or_dash_fail649 (    struct Maybe_330  x1410 ,    struct StrConcat_586  errmsg1412 ) {
    struct Maybe_330  dref1413 = (  x1410 );
    if ( dref1413.tag == Maybe_330_None_t ) {
        ( (  panic642 ) ( (  errmsg1412 ) ) );
        return ( (  undefined106 ) ( ) );
    }
    else {
        if ( dref1413.tag == Maybe_330_Just_t ) {
            return ( dref1413 .stuff .Maybe_330_Just_s .field0 );
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
            struct Cell_16  field0;
        } Maybe_651_Just_s;
    } stuff;
};

static struct Maybe_651 Maybe_651_Just (  struct Cell_16  field0 ) {
    return ( struct Maybe_651 ) { .tag = Maybe_651_Just_t, .stuff = { .Maybe_651_Just_s = { .field0 = field0 } } };
};

static  struct Cell_16   or_dash_fail650 (    struct Maybe_651  x1410 ,    struct StrConcat_586  errmsg1412 ) {
    struct Maybe_651  dref1413 = (  x1410 );
    if ( dref1413.tag == Maybe_651_None_t ) {
        ( (  panic642 ) ( (  errmsg1412 ) ) );
        return ( (  undefined114 ) ( ) );
    }
    else {
        if ( dref1413.tag == Maybe_651_Just_t ) {
            return ( dref1413 .stuff .Maybe_651_Just_s .field0 );
        }
    }
}

struct Maybe_653 {
    enum {
        Maybe_653_None_t,
        Maybe_653_Just_t,
    } tag;
    union {
        struct {
            uint8_t  field0;
        } Maybe_653_Just_s;
    } stuff;
};

static struct Maybe_653 Maybe_653_Just (  uint8_t  field0 ) {
    return ( struct Maybe_653 ) { .tag = Maybe_653_Just_t, .stuff = { .Maybe_653_Just_s = { .field0 = field0 } } };
};

static  uint8_t   or_dash_fail652 (    struct Maybe_653  x1410 ,    struct StrConcat_594  errmsg1412 ) {
    struct Maybe_653  dref1413 = (  x1410 );
    if ( dref1413.tag == Maybe_653_None_t ) {
        ( (  panic643 ) ( (  errmsg1412 ) ) );
        return ( (  undefined116 ) ( ) );
    }
    else {
        if ( dref1413.tag == Maybe_653_Just_t ) {
            return ( dref1413 .stuff .Maybe_653_Just_s .field0 );
        }
    }
}

struct Maybe_655 {
    enum {
        Maybe_655_None_t,
        Maybe_655_Just_t,
    } tag;
    union {
        struct {
            struct Cell_16 *  field0;
        } Maybe_655_Just_s;
    } stuff;
};

static struct Maybe_655 Maybe_655_Just (  struct Cell_16 *  field0 ) {
    return ( struct Maybe_655 ) { .tag = Maybe_655_Just_t, .stuff = { .Maybe_655_Just_s = { .field0 = field0 } } };
};

static  struct Cell_16 *   or_dash_fail654 (    struct Maybe_655  x1410 ,    const char*  errmsg1412 ) {
    struct Maybe_655  dref1413 = (  x1410 );
    if ( dref1413.tag == Maybe_655_None_t ) {
        ( (  panic641 ) ( (  errmsg1412 ) ) );
        return ( (  undefined125 ) ( ) );
    }
    else {
        if ( dref1413.tag == Maybe_655_Just_t ) {
            return ( dref1413 .stuff .Maybe_655_Just_s .field0 );
        }
    }
}

static  char   or_dash_fail656 (    struct Maybe_276  x1410 ,    const char*  errmsg1412 ) {
    struct Maybe_276  dref1413 = (  x1410 );
    if ( dref1413.tag == Maybe_276_None_t ) {
        ( (  panic641 ) ( (  errmsg1412 ) ) );
        return ( (  undefined100 ) ( ) );
    }
    else {
        if ( dref1413.tag == Maybe_276_Just_t ) {
            return ( dref1413 .stuff .Maybe_276_Just_s .field0 );
        }
    }
}

static  const char*   or_dash_else657 (    struct Maybe_252  self1417 ,    const char*  alt1419 ) {
    struct Maybe_252  dref1420 = (  self1417 );
    if ( dref1420.tag == Maybe_252_None_t ) {
        return (  alt1419 );
    }
    else {
        if ( dref1420.tag == Maybe_252_Just_t ) {
            return ( dref1420 .stuff .Maybe_252_Just_s .field0 );
        }
    }
}

static  int64_t   or_dash_else658 (    struct Maybe_446  self1417 ,    int64_t  alt1419 ) {
    struct Maybe_446  dref1420 = (  self1417 );
    if ( dref1420.tag == Maybe_446_None_t ) {
        return (  alt1419 );
    }
    else {
        if ( dref1420.tag == Maybe_446_Just_t ) {
            return ( dref1420 .stuff .Maybe_446_Just_s .field0 );
        }
    }
}

static  struct Tile_104   or_dash_else659 (    struct Maybe_330  self1417 ,    struct Tile_104  alt1419 ) {
    struct Maybe_330  dref1420 = (  self1417 );
    if ( dref1420.tag == Maybe_330_None_t ) {
        return (  alt1419 );
    }
    else {
        if ( dref1420.tag == Maybe_330_Just_t ) {
            return ( dref1420 .stuff .Maybe_330_Just_s .field0 );
        }
    }
}

static  struct Slice_270   empty660 (  ) {
    return ( (struct Slice_270) { .f_ptr = ( (  null_dash_ptr246 ) ( ) ) , .f_count = (  from_dash_integral8 ( 0 ) ) } );
}

static  char *   get_dash_ptr661 (    struct Slice_270  slice1443 ,    size_t  i1445 ) {
    if ( ( (  cmp39 ( (  i1445 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1445 ) , ( (  slice1443 ) .f_count ) ) != 0 ) ) ) {
        ( (  panic642 ) ( ( ( StrConcat_586_StrConcat ) ( ( ( StrConcat_587_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1445 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1443 ) .f_count ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    char *  elem_dash_ptr1446 = ( (  offset_dash_ptr129 ) ( ( (  slice1443 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  i1445 ) ) ) ) );
    return (  elem_dash_ptr1446 );
}

static  struct Tile_104 *   get_dash_ptr662 (    struct Slice_103  slice1443 ,    size_t  i1445 ) {
    if ( ( (  cmp39 ( (  i1445 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1445 ) , ( (  slice1443 ) .f_count ) ) != 0 ) ) ) {
        ( (  panic642 ) ( ( ( StrConcat_586_StrConcat ) ( ( ( StrConcat_587_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1445 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1443 ) .f_count ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    struct Tile_104 *  elem_dash_ptr1446 = ( (  offset_dash_ptr133 ) ( ( (  slice1443 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  i1445 ) ) ) ) );
    return (  elem_dash_ptr1446 );
}

static  struct Cell_16 *   get_dash_ptr663 (    struct Slice_399  slice1443 ,    size_t  i1445 ) {
    if ( ( (  cmp39 ( (  i1445 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1445 ) , ( (  slice1443 ) .f_count ) ) != 0 ) ) ) {
        ( (  panic642 ) ( ( ( StrConcat_586_StrConcat ) ( ( ( StrConcat_587_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1445 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1443 ) .f_count ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    struct Cell_16 *  elem_dash_ptr1446 = ( (  offset_dash_ptr139 ) ( ( (  slice1443 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  i1445 ) ) ) ) );
    return (  elem_dash_ptr1446 );
}

static  struct Maybe_276   try_dash_get664 (    struct Slice_270  slice1449 ,    size_t  i1451 ) {
    if ( ( (  cmp39 ( (  i1451 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1451 ) , ( (  slice1449 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    char *  elem_dash_ptr1452 = ( (  offset_dash_ptr129 ) ( ( (  slice1449 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  i1451 ) ) ) ) );
    return ( ( Maybe_276_Just ) ( ( * (  elem_dash_ptr1452 ) ) ) );
}

static  struct Maybe_325   try_dash_get665 (    struct Slice_307  slice1449 ,    size_t  i1451 ) {
    if ( ( (  cmp39 ( (  i1451 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1451 ) , ( (  slice1449 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Maybe_325) { .tag = Maybe_325_None_t } );
    }
    struct Slice_103 *  elem_dash_ptr1452 = ( (  offset_dash_ptr131 ) ( ( (  slice1449 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  i1451 ) ) ) ) );
    return ( ( Maybe_325_Just ) ( ( * (  elem_dash_ptr1452 ) ) ) );
}

static  struct Maybe_330   try_dash_get666 (    struct Slice_103  slice1449 ,    size_t  i1451 ) {
    if ( ( (  cmp39 ( (  i1451 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1451 ) , ( (  slice1449 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Maybe_330) { .tag = Maybe_330_None_t } );
    }
    struct Tile_104 *  elem_dash_ptr1452 = ( (  offset_dash_ptr133 ) ( ( (  slice1449 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  i1451 ) ) ) ) );
    return ( ( Maybe_330_Just ) ( ( * (  elem_dash_ptr1452 ) ) ) );
}

static  struct Maybe_651   try_dash_get667 (    struct Slice_399  slice1449 ,    size_t  i1451 ) {
    if ( ( (  cmp39 ( (  i1451 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1451 ) , ( (  slice1449 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Maybe_651) { .tag = Maybe_651_None_t } );
    }
    struct Cell_16 *  elem_dash_ptr1452 = ( (  offset_dash_ptr139 ) ( ( (  slice1449 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  i1451 ) ) ) ) );
    return ( ( Maybe_651_Just ) ( ( * (  elem_dash_ptr1452 ) ) ) );
}

static  char   get668 (    struct Slice_270  slice1455 ,    size_t  i1457 ) {
    return ( (  or_dash_fail647 ) ( ( (  try_dash_get664 ) ( (  slice1455 ) ,  (  i1457 ) ) ) ,  ( ( StrConcat_586_StrConcat ) ( ( ( StrConcat_587_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1457 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1455 ) .f_count ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
}

static  struct Slice_103   get669 (    struct Slice_307  slice1455 ,    size_t  i1457 ) {
    return ( (  or_dash_fail648 ) ( ( (  try_dash_get665 ) ( (  slice1455 ) ,  (  i1457 ) ) ) ,  ( ( StrConcat_586_StrConcat ) ( ( ( StrConcat_587_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1457 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1455 ) .f_count ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
}

static  struct Tile_104   get670 (    struct Slice_103  slice1455 ,    size_t  i1457 ) {
    return ( (  or_dash_fail649 ) ( ( (  try_dash_get666 ) ( (  slice1455 ) ,  (  i1457 ) ) ) ,  ( ( StrConcat_586_StrConcat ) ( ( ( StrConcat_587_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1457 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1455 ) .f_count ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
}

static  struct Cell_16   get671 (    struct Slice_399  slice1455 ,    size_t  i1457 ) {
    return ( (  or_dash_fail650 ) ( ( (  try_dash_get667 ) ( (  slice1455 ) ,  (  i1457 ) ) ) ,  ( ( StrConcat_586_StrConcat ) ( ( ( StrConcat_587_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1457 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1455 ) .f_count ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
}

static  enum Unit_157   set672 (    struct Slice_270  slice1460 ,    size_t  i1462 ,    char  x1464 ) {
    char *  ep1465 = ( (  get_dash_ptr661 ) ( (  slice1460 ) ,  (  i1462 ) ) );
    (*  ep1465 ) = (  x1464 );
    return ( Unit_157_Unit );
}

static  enum Unit_157   set673 (    struct Slice_103  slice1460 ,    size_t  i1462 ,    struct Tile_104  x1464 ) {
    struct Tile_104 *  ep1465 = ( (  get_dash_ptr662 ) ( (  slice1460 ) ,  (  i1462 ) ) );
    (*  ep1465 ) = (  x1464 );
    return ( Unit_157_Unit );
}

static  enum Unit_157   set674 (    struct Slice_399  slice1460 ,    size_t  i1462 ,    struct Cell_16  x1464 ) {
    struct Cell_16 *  ep1465 = ( (  get_dash_ptr663 ) ( (  slice1460 ) ,  (  i1462 ) ) );
    (*  ep1465 ) = (  x1464 );
    return ( Unit_157_Unit );
}

struct Slice_676 {
    const char* *  f_ptr;
    size_t  f_count;
};

static  struct Slice_676   subslice675 (    struct Slice_676  slice1468 ,    size_t  from1470 ,    size_t  to1472 ) {
    const char* *  begin_dash_ptr1473 = ( (  offset_dash_ptr127 ) ( ( (  slice1468 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  from1470 ) ) ) ) );
    if ( ( (  cmp39 ( (  from1470 ) , (  to1472 ) ) != 0 ) || (  cmp39 ( (  from1470 ) , ( (  slice1468 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Slice_676) { .f_ptr = (  begin_dash_ptr1473 ) , .f_count = (  from_dash_integral8 ( 0 ) ) } );
    }
    size_t  count1474 = (  op_dash_sub59 ( ( (  min554 ) ( (  to1472 ) ,  ( (  slice1468 ) .f_count ) ) ) , (  from1470 ) ) );
    return ( (struct Slice_676) { .f_ptr = (  begin_dash_ptr1473 ) , .f_count = (  count1474 ) } );
}

static  struct Slice_270   subslice677 (    struct Slice_270  slice1468 ,    size_t  from1470 ,    size_t  to1472 ) {
    char *  begin_dash_ptr1473 = ( (  offset_dash_ptr129 ) ( ( (  slice1468 ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  from1470 ) ) ) ) );
    if ( ( (  cmp39 ( (  from1470 ) , (  to1472 ) ) != 0 ) || (  cmp39 ( (  from1470 ) , ( (  slice1468 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Slice_270) { .f_ptr = (  begin_dash_ptr1473 ) , .f_count = (  from_dash_integral8 ( 0 ) ) } );
    }
    size_t  count1474 = (  op_dash_sub59 ( ( (  min554 ) ( (  to1472 ) ,  ( (  slice1468 ) .f_count ) ) ) , (  from1470 ) ) );
    return ( (struct Slice_270) { .f_ptr = (  begin_dash_ptr1473 ) , .f_count = (  count1474 ) } );
}

struct SliceAddressIter_679 {
    struct Slice_307  f_slice;
    size_t  f_current_dash_offset;
};

static  struct SliceAddressIter_679   addresses678 (    struct Slice_307  slice1526 ) {
    return ( (struct SliceAddressIter_679) { .f_slice = (  slice1526 ) , .f_current_dash_offset = (  from_dash_integral8 ( 0 ) ) } );
}

static  struct SliceAddressIter_679   into_dash_iter680 (    struct SliceAddressIter_679  self1529 ) {
    return (  self1529 );
}

struct Maybe_682 {
    enum {
        Maybe_682_None_t,
        Maybe_682_Just_t,
    } tag;
    union {
        struct {
            struct Slice_103 *  field0;
        } Maybe_682_Just_s;
    } stuff;
};

static struct Maybe_682 Maybe_682_Just (  struct Slice_103 *  field0 ) {
    return ( struct Maybe_682 ) { .tag = Maybe_682_Just_t, .stuff = { .Maybe_682_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_682   next681 (    struct SliceAddressIter_679 *  self1532 ) {
    size_t  off1533 = ( ( * (  self1532 ) ) .f_current_dash_offset );
    if ( (  cmp39 ( (  op_dash_add58 ( (  off1533 ) , (  from_dash_integral8 ( 1 ) ) ) ) , ( ( ( * (  self1532 ) ) .f_slice ) .f_count ) ) == 2 ) ) {
        return ( (struct Maybe_682) { .tag = Maybe_682_None_t } );
    }
    struct Slice_103 *  elem1534 = ( (  offset_dash_ptr131 ) ( ( ( ( * (  self1532 ) ) .f_slice ) .f_ptr ) ,  ( (  size_dash_i64253 ) ( (  off1533 ) ) ) ) );
    (*  self1532 ) .f_current_dash_offset = (  op_dash_add58 ( (  off1533 ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( ( Maybe_682_Just ) ( (  elem1534 ) ) );
}

static  struct Slice_103   elem_dash_get683 (    struct Slice_307  self1553 ,    size_t  idx1555 ) {
    return ( (  get669 ) ( (  self1553 ) ,  (  idx1555 ) ) );
}

static  struct Tile_104   elem_dash_get684 (    struct Slice_103  self1553 ,    size_t  idx1555 ) {
    return ( (  get670 ) ( (  self1553 ) ,  (  idx1555 ) ) );
}

static  struct Cell_16   elem_dash_get685 (    struct Slice_399  self1553 ,    size_t  idx1555 ) {
    return ( (  get671 ) ( (  self1553 ) ,  (  idx1555 ) ) );
}

static  char   elem_dash_get686 (    struct Slice_270  self1553 ,    size_t  idx1555 ) {
    return ( (  get668 ) ( (  self1553 ) ,  (  idx1555 ) ) );
}

struct ListSpread_688 {
    enum {
        ListSpread_688_NoSpread_t,
        ListSpread_688_UnassignedSpread_t,
        ListSpread_688_AssignedSpread_t,
    } tag;
    union {
        struct {
            struct Slice_676 *  field0;
        } ListSpread_688_AssignedSpread_s;
    } stuff;
};

static struct ListSpread_688 ListSpread_688_AssignedSpread (  struct Slice_676 *  field0 ) {
    return ( struct ListSpread_688 ) { .tag = ListSpread_688_AssignedSpread_t, .stuff = { .ListSpread_688_AssignedSpread_s = { .field0 = field0 } } };
};

static  bool   deconstruct687 (    struct Slice_676  self1564 ,    const char* * *  lp1566 ,    size_t  lc1568 ,    struct ListSpread_688  spread1570 ,    const char* * *  rp1572 ,    size_t  rc1574 ) {
    if ( (  cmp39 ( (  lc1568 ) , (  from_dash_integral8 ( 0 ) ) ) == 2 ) ) {
        if ( (  cmp39 ( (  lc1568 ) , ( (  self1564 ) .f_count ) ) == 2 ) ) {
            return ( false );
        }
        (*  lp1566 ) = ( (  self1564 ) .f_ptr );
    }
    if ( (  cmp39 ( (  rc1574 ) , (  from_dash_integral8 ( 0 ) ) ) == 2 ) ) {
        if ( (  cmp39 ( (  op_dash_add58 ( (  rc1574 ) , (  lc1568 ) ) ) , ( (  self1564 ) .f_count ) ) == 2 ) ) {
            return ( false );
        }
        struct Slice_676  cut1575 = ( (  subslice675 ) ( (  self1564 ) ,  (  op_dash_sub59 ( ( (  self1564 ) .f_count ) , (  rc1574 ) ) ) ,  ( (  self1564 ) .f_count ) ) );
        (*  rp1572 ) = ( (  cut1575 ) .f_ptr );
    }
    struct ListSpread_688  dref1576 = (  spread1570 );
    if ( dref1576.tag == ListSpread_688_NoSpread_t ) {
        return (  eq13 ( (  op_dash_add58 ( (  lc1568 ) , (  rc1574 ) ) ) , ( (  self1564 ) .f_count ) ) );
    }
    else {
        if ( dref1576.tag == ListSpread_688_UnassignedSpread_t ) {
            return ( true );
        }
        else {
            if ( dref1576.tag == ListSpread_688_AssignedSpread_t ) {
                (* dref1576 .stuff .ListSpread_688_AssignedSpread_s .field0 ) = ( (  subslice675 ) ( (  self1564 ) ,  (  lc1568 ) ,  (  op_dash_sub59 ( ( (  self1564 ) .f_count ) , (  rc1574 ) ) ) ) );
                return ( true );
            }
        }
    }
}

static  enum Unit_157   lam393 (   struct env393 env ,    int32_t  i1595 ) {
    struct funenv394  temp690 = ( env.fun1593 );
    return ( (  set673 ) ( ( env.s1591 ) ,  ( (  i32_dash_size256 ) ( (  i1595 ) ) ) ,  ( temp690.fun ( temp690.env ,  (  elem_dash_get684 ( ( env.s1591 ) , ( (  i32_dash_size256 ) ( (  i1595 ) ) ) ) ) ) ) ) );
}

static  enum Unit_157   map689 (    struct Slice_103  s1591 ,   struct funenv394  fun1593 ) {
    struct env393 envinst393 = {
        .fun1593 =  fun1593 ,
        .s1591 =  s1591 ,
    };
    ( (  for_dash_each392 ) ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_i32260 ) ( (  op_dash_sub59 ( ( (  s1591 ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) ) ) ) ) ,  ( (struct funenv393){ .fun = lam393, .env = envinst393 } ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   lam398 (   struct env398 env ,    int32_t  i1595 ) {
    return ( (  set674 ) ( ( env.s1591 ) ,  ( (  i32_dash_size256 ) ( (  i1595 ) ) ) ,  ( ( env.fun1593 ) ( (  elem_dash_get685 ( ( env.s1591 ) , ( (  i32_dash_size256 ) ( (  i1595 ) ) ) ) ) ) ) ) );
}

static  enum Unit_157   map691 (    struct Slice_399  s1591 ,    struct Cell_16 (*  fun1593 )(    struct Cell_16  ) ) {
    struct env398 envinst398 = {
        .fun1593 =  fun1593 ,
        .s1591 =  s1591 ,
    };
    ( (  for_dash_each397 ) ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_i32260 ) ( (  op_dash_sub59 ( ( (  s1591 ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) ) ) ) ) ,  ( (struct funenv398){ .fun = lam398, .env = envinst398 } ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   lam403 (   struct env403 env ,    int32_t  i1595 ) {
    return ( (  set674 ) ( ( env.s1591 ) ,  ( (  i32_dash_size256 ) ( (  i1595 ) ) ) ,  ( ( env.fun1593 ) ( (  elem_dash_get685 ( ( env.s1591 ) , ( (  i32_dash_size256 ) ( (  i1595 ) ) ) ) ) ) ) ) );
}

static  enum Unit_157   map692 (    struct Slice_399  s1591 ,    struct Cell_16 (*  fun1593 )(    struct Cell_16  ) ) {
    struct env403 envinst403 = {
        .fun1593 =  fun1593 ,
        .s1591 =  s1591 ,
    };
    ( (  for_dash_each402 ) ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_i32260 ) ( (  op_dash_sub59 ( ( (  s1591 ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) ) ) ) ) ,  ( (struct funenv403){ .fun = lam403, .env = envinst403 } ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   lam433 (   struct env433 env ,    int32_t  i1595 ) {
    return ( (  set674 ) ( ( env.s1591 ) ,  ( (  i32_dash_size256 ) ( (  i1595 ) ) ) ,  ( ( env.fun1593 ) ( (  elem_dash_get685 ( ( env.s1591 ) , ( (  i32_dash_size256 ) ( (  i1595 ) ) ) ) ) ) ) ) );
}

static  enum Unit_157   map693 (    struct Slice_399  s1591 ,    struct Cell_16 (*  fun1593 )(    struct Cell_16  ) ) {
    struct env433 envinst433 = {
        .fun1593 =  fun1593 ,
        .s1591 =  s1591 ,
    };
    ( (  for_dash_each432 ) ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  ( (  size_dash_i32260 ) ( (  op_dash_sub59 ( ( (  s1591 ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) ) ) ) ) ,  ( (struct funenv433){ .fun = lam433, .env = envinst433 } ) ) );
    return ( Unit_157_Unit );
}

static  enum CAllocator_383   idc694 (  ) {
    return ( CAllocator_383_CAllocator );
}

static  struct Slice_270   allocate695 (    enum CAllocator_383  dref1622 ,    size_t  count1624 ) {
    if (!(  dref1622 == CAllocator_383_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    size_t  size1625 = ( ( ( (  get_dash_typesize143 ) ( ) ) ) .f_size );
    char *  ptr1626 = ( (  cast_dash_ptr187 ) ( ( ( malloc ) ( (  op_dash_mul60 ( (  size1625 ) , (  count1624 ) ) ) ) ) ) );
    return ( (struct Slice_270) { .f_ptr = (  ptr1626 ) , .f_count = (  count1624 ) } );
}

static  struct Slice_307   allocate696 (    enum CAllocator_383  dref1622 ,    size_t  count1624 ) {
    if (!(  dref1622 == CAllocator_383_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    size_t  size1625 = ( ( ( (  get_dash_typesize146 ) ( ) ) ) .f_size );
    struct Slice_103 *  ptr1626 = ( (  cast_dash_ptr191 ) ( ( ( malloc ) ( (  op_dash_mul60 ( (  size1625 ) , (  count1624 ) ) ) ) ) ) );
    return ( (struct Slice_307) { .f_ptr = (  ptr1626 ) , .f_count = (  count1624 ) } );
}

static  struct Slice_103   allocate697 (    enum CAllocator_383  dref1622 ,    size_t  count1624 ) {
    if (!(  dref1622 == CAllocator_383_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    size_t  size1625 = ( ( ( (  get_dash_typesize149 ) ( ) ) ) .f_size );
    struct Tile_104 *  ptr1626 = ( (  cast_dash_ptr192 ) ( ( ( malloc ) ( (  op_dash_mul60 ( (  size1625 ) , (  count1624 ) ) ) ) ) ) );
    return ( (struct Slice_103) { .f_ptr = (  ptr1626 ) , .f_count = (  count1624 ) } );
}

static  struct Slice_399   allocate698 (    enum CAllocator_383  dref1622 ,    size_t  count1624 ) {
    if (!(  dref1622 == CAllocator_383_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    size_t  size1625 = ( ( ( (  get_dash_typesize152 ) ( ) ) ) .f_size );
    struct Cell_16 *  ptr1626 = ( (  cast_dash_ptr200 ) ( ( ( malloc ) ( (  op_dash_mul60 ( (  size1625 ) , (  count1624 ) ) ) ) ) ) );
    return ( (struct Slice_399) { .f_ptr = (  ptr1626 ) , .f_count = (  count1624 ) } );
}

struct Slice_700 {
    enum Unit_157 *  f_ptr;
    size_t  f_count;
};

static  enum Unit_157   free699 (    enum CAllocator_383  dref1628 ,    struct Slice_700  slice1630 ) {
    if (!(  dref1628 == CAllocator_383_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    ( ( free ) ( ( (  cast_dash_ptr186 ) ( ( (  slice1630 ) .f_ptr ) ) ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   free701 (    enum CAllocator_383  dref1628 ,    struct Slice_270  slice1630 ) {
    if (!(  dref1628 == CAllocator_383_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    ( ( free ) ( ( (  cast_dash_ptr188 ) ( ( (  slice1630 ) .f_ptr ) ) ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   free702 (    enum CAllocator_383  dref1628 ,    struct Slice_399  slice1630 ) {
    if (!(  dref1628 == CAllocator_383_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    ( ( free ) ( ( (  cast_dash_ptr209 ) ( ( (  slice1630 ) .f_ptr ) ) ) ) );
    return ( Unit_157_Unit );
}

static  struct Tile_104   lam394 (   struct env394 env ,    struct Tile_104  dref1639 ) {
    return ( env.x1637 );
}

static  struct Slice_103   default703 (    enum CAllocator_383  al1633 ,    size_t  count1635 ,    struct Tile_104  x1637 ) {
    struct Slice_103  s1638 = ( (  allocate697 ) ( (  al1633 ) ,  (  count1635 ) ) );
    struct env394 envinst394 = {
        .x1637 =  x1637 ,
    };
    ( (  map689 ) ( (  s1638 ) ,  ( (struct funenv394){ .fun = lam394, .env = envinst394 } ) ) );
    return (  s1638 );
}

static  struct SliceIter_269   into_dash_iter704 (    struct List_382  self1714 ) {
    return ( (  into_dash_iter334 ) ( ( (  subslice677 ) ( ( (  self1714 ) .f_elements ) ,  (  from_dash_integral8 ( 0 ) ) ,  ( (  self1714 ) .f_count ) ) ) ) );
}

static  struct List_382   mk705 (    enum CAllocator_383  al1717 ) {
    struct Slice_270  elements1718 = ( (  empty660 ) ( ) );
    return ( (struct List_382) { .f_al = (  al1717 ) , .f_elements = (  elements1718 ) , .f_count = (  from_dash_integral8 ( 0 ) ) } );
}

static  enum Unit_157   free706 (    struct List_382 *  list1721 ) {
    ( (  free701 ) ( ( ( * (  list1721 ) ) .f_al ) ,  ( ( * (  list1721 ) ) .f_elements ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   lam373 (   struct env373 env ,    struct Tuple2_312  dref1729 ) {
    return ( (  set672 ) ( ( env.new_dash_slice1728 ) ,  ( (  i32_dash_size256 ) ( ( dref1729 .field1 ) ) ) ,  ( dref1729 .field0 ) ) );
}

static  enum Unit_157   grow_dash_if_dash_full385 (   struct env385 env ,    struct List_382 *  list1727 ) {
    if ( (  eq13 ( ( ( * (  list1727 ) ) .f_count ) , (  from_dash_integral8 ( 0 ) ) ) ) ) {
        (*  list1727 ) .f_elements = ( (  allocate695 ) ( ( ( * (  list1727 ) ) .f_al ) ,  ( env.starting_dash_size1722 ) ) );
    } else {
        if ( (  eq13 ( ( ( * (  list1727 ) ) .f_count ) , ( ( ( * (  list1727 ) ) .f_elements ) .f_count ) ) ) ) {
            struct Slice_270  new_dash_slice1728 = ( (  allocate695 ) ( ( ( * (  list1727 ) ) .f_al ) ,  (  op_dash_mul60 ( ( ( * (  list1727 ) ) .f_count ) , ( env.growth_dash_factor1723 ) ) ) ) );
            struct env373 envinst373 = {
                .new_dash_slice1728 =  new_dash_slice1728 ,
            };
            ( (  for_dash_each372 ) ( ( (  zip333 ) ( ( ( * (  list1727 ) ) .f_elements ) ,  ( (  from291 ) ( (  from_dash_integral3 ( 0 ) ) ) ) ) ) ,  ( (struct funenv373){ .fun = lam373, .env = envinst373 } ) ) );
            ( (  free701 ) ( ( ( * (  list1727 ) ) .f_al ) ,  ( ( * (  list1727 ) ) .f_elements ) ) );
            (*  list1727 ) .f_elements = (  new_dash_slice1728 );
        }
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   add384 (   struct env384 env ,    struct List_382 *  list1734 ,    char  elem1736 ) {
    struct funenv385  temp707 = ( (struct funenv385){ .fun = grow_dash_if_dash_full385, .env =  env.envinst385  } );
    ( temp707.fun ( temp707.env ,  (  list1734 ) ) );
    ( (  set672 ) ( ( ( * (  list1734 ) ) .f_elements ) ,  ( ( * (  list1734 ) ) .f_count ) ,  (  elem1736 ) ) );
    (*  list1734 ) .f_count = (  op_dash_add58 ( ( ( * (  list1734 ) ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) );
    return ( Unit_157_Unit );
}

static  struct SliceIter_269   chars708 (    struct DynStr_417  self1664 ) {
    return ( (  into_dash_iter334 ) ( ( (  self1664 ) .f_contents ) ) );
}

static  struct DynStr_417   substr709 (    struct DynStr_417  s1670 ,    size_t  from1672 ,    size_t  to1674 ) {
    return ( (struct DynStr_417) { .f_contents = ( (  subslice677 ) ( ( (  s1670 ) .f_contents ) ,  (  from1672 ) ,  (  to1674 ) ) ) } );
}

static  uint8_t *   get_dash_ptr710 (    struct Array_112 *  arr1834 ,    size_t  i1837 ) {
    if ( ( (  cmp39 ( (  i1837 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1837 ) , ( (size_t ) ( 32 ) ) ) != 0 ) ) ) {
        ( (  panic456 ) ( ( ( StrConcat_457_StrConcat ) ( ( ( StrConcat_458_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( "Access to array at index " ) ,  (  i1837 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 32 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    uint8_t *  p1838 = ( ( (  cast_dash_ptr196 ) ( (  arr1834 ) ) ) );
    return ( (  offset_dash_ptr135 ) ( (  p1838 ) ,  ( (int64_t ) (  i1837 ) ) ) );
}

static  char *   get_dash_ptr711 (    struct Array_167 *  arr1834 ,    size_t  i1837 ) {
    if ( ( (  cmp39 ( (  i1837 ) , (  from_dash_integral8 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  i1837 ) , ( (size_t ) ( 32 ) ) ) != 0 ) ) ) {
        ( (  panic456 ) ( ( ( StrConcat_457_StrConcat ) ( ( ( StrConcat_458_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( "Access to array at index " ) ,  (  i1837 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 32 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ")" ) ) ) ) ) ) );
    }
    char *  p1838 = ( ( (  cast_dash_ptr205 ) ( (  arr1834 ) ) ) );
    return ( (  offset_dash_ptr129 ) ( (  p1838 ) ,  ( (int64_t ) (  i1837 ) ) ) );
}

static  enum Unit_157   set712 (    struct Array_112 *  arr1847 ,    size_t  i1850 ,    uint8_t  e1852 ) {
    uint8_t *  p1853 = ( (  get_dash_ptr710 ) ( (  arr1847 ) ,  (  i1850 ) ) );
    (*  p1853 ) = (  e1852 );
    return ( Unit_157_Unit );
}

static  enum Unit_157   set713 (    struct Array_167 *  arr1847 ,    size_t  i1850 ,    char  e1852 ) {
    char *  p1853 = ( (  get_dash_ptr711 ) ( (  arr1847 ) ,  (  i1850 ) ) );
    (*  p1853 ) = (  e1852 );
    return ( Unit_157_Unit );
}

static  struct Slice_270   as_dash_slice714 (    struct Array_167 *  arr1856 ) {
    return ( (struct Slice_270) { .f_ptr = ( (  cast180 ) ( (  arr1856 ) ) ) , .f_count = ( (size_t ) ( 32 ) ) } );
}

static  char   newline715 (  ) {
    return ( (  from_dash_charlike1 ) ( ( "\n" ) ) );
}

struct LineIter_717 {
    struct DynStr_417  f_og;
    size_t  f_last;
};

static  struct LineIter_717   lines716 (    struct DynStr_417  s1936 ) {
    return ( (struct LineIter_717) { .f_og = (  s1936 ) , .f_last = (  from_dash_integral8 ( 0 ) ) } );
}

static  struct LineIter_717   into_dash_iter718 (    struct LineIter_717  self1939 ) {
    return (  self1939 );
}

static  struct Maybe_537   next719 (    struct LineIter_717 *  self1942 ) {
    if ( ( (  cmp39 ( ( ( * (  self1942 ) ) .f_last ) , ( ( ( ( * (  self1942 ) ) .f_og ) .f_contents ) .f_count ) ) != 0 ) || (  eq14 ( ( (  get668 ) ( ( ( ( * (  self1942 ) ) .f_og ) .f_contents ) ,  ( ( * (  self1942 ) ) .f_last ) ) ) , ( (  nullchar634 ) ( ) ) ) ) ) ) {
        return ( (struct Maybe_537) { .tag = Maybe_537_None_t } );
    }
    size_t  i1943 = ( ( * (  self1942 ) ) .f_last );
    while ( ( (  cmp39 ( (  i1943 ) , ( ( ( ( * (  self1942 ) ) .f_og ) .f_contents ) .f_count ) ) == 0 ) && ( !  eq14 ( ( (  get668 ) ( ( ( ( * (  self1942 ) ) .f_og ) .f_contents ) ,  (  i1943 ) ) ) , ( (  newline715 ) ( ) ) ) ) ) ) {
        i1943 = (  op_dash_add58 ( (  i1943 ) , (  from_dash_integral8 ( 1 ) ) ) );
    }
    struct DynStr_417  line1944 = ( (  substr709 ) ( ( ( * (  self1942 ) ) .f_og ) ,  ( ( * (  self1942 ) ) .f_last ) ,  (  i1943 ) ) );
    if ( (  cmp39 ( (  i1943 ) , ( ( ( ( * (  self1942 ) ) .f_og ) .f_contents ) .f_count ) ) == 0 ) ) {
        i1943 = (  op_dash_add58 ( (  i1943 ) , (  from_dash_integral8 ( 1 ) ) ) );
    }
    (*  self1942 ) .f_last = (  i1943 );
    return ( ( Maybe_537_Just ) ( (  line1944 ) ) );
}

static  bool   is_dash_digit720 (    char  c1965 ) {
    return ( (  cmp40 ( ( (  char_dash_i32635 ) ( (  c1965 ) ) ) , ( (  char_dash_i32635 ) ( ( (  from_dash_charlike1 ) ( ( "0" ) ) ) ) ) ) != 0 ) && (  cmp40 ( ( (  char_dash_i32635 ) ( (  c1965 ) ) ) , ( (  char_dash_i32635 ) ( ( (  from_dash_charlike1 ) ( ( "9" ) ) ) ) ) ) != 2 ) );
}

static  struct Maybe_290   parse_dash_digit721 (    char  c1968 ) {
    if ( ( (  is_dash_digit720 ) ( (  c1968 ) ) ) ) {
        return ( ( Maybe_290_Just ) ( (  op_dash_sub48 ( ( (  char_dash_i32635 ) ( (  c1968 ) ) ) , ( (  char_dash_i32635 ) ( ( (  from_dash_charlike1 ) ( ( "0" ) ) ) ) ) ) ) ) );
    } else {
        return ( (struct Maybe_290) { .tag = Maybe_290_None_t } );
    }
}

static  struct Maybe_446   sequence_dash_maybe723 (    char  e1974 ,    struct Maybe_446  b1976 ) {
    struct Maybe_446  dref1977 = (  b1976 );
    if ( dref1977.tag == Maybe_446_None_t ) {
        return ( (struct Maybe_446) { .tag = Maybe_446_None_t } );
    }
    else {
        if ( dref1977.tag == Maybe_446_Just_t ) {
            struct Maybe_290  dref1979 = ( (  parse_dash_digit721 ) ( (  e1974 ) ) );
            if ( dref1979.tag == Maybe_290_None_t ) {
                return ( (struct Maybe_446) { .tag = Maybe_446_None_t } );
            }
            else {
                if ( dref1979.tag == Maybe_290_Just_t ) {
                    return ( ( Maybe_446_Just ) ( (  op_dash_add43 ( (  op_dash_mul45 ( ( dref1977 .stuff .Maybe_446_Just_s .field0 ) , (  from_dash_integral2 ( 10 ) ) ) ) , ( (  i32_dash_i64255 ) ( ( dref1979 .stuff .Maybe_290_Just_s .field0 ) ) ) ) ) ) );
                }
            }
        }
    }
}

static  struct Maybe_446   parse_dash_int722 (    const char*  s1971 ) {
    struct ConstStrIter_279  cs1981 = ( (  chars556 ) ( (  s1971 ) ) );
    struct Maybe_276  dref1982 = ( (  head516 ) ( (  cs1981 ) ) );
    if ( dref1982.tag == Maybe_276_Just_t ) {
        return ( (  reduce445 ) ( (  cs1981 ) ,  ( ( Maybe_446_Just ) ( (  from_dash_integral2 ( 0 ) ) ) ) ,  (  sequence_dash_maybe723 ) ) );
    }
    else {
        if ( dref1982.tag == Maybe_276_None_t ) {
            return ( (struct Maybe_446) { .tag = Maybe_446_None_t } );
        }
    }
}

static  struct Maybe_446   sequence_dash_maybe725 (    char  e1974 ,    struct Maybe_446  b1976 ) {
    struct Maybe_446  dref1977 = (  b1976 );
    if ( dref1977.tag == Maybe_446_None_t ) {
        return ( (struct Maybe_446) { .tag = Maybe_446_None_t } );
    }
    else {
        if ( dref1977.tag == Maybe_446_Just_t ) {
            struct Maybe_290  dref1979 = ( (  parse_dash_digit721 ) ( (  e1974 ) ) );
            if ( dref1979.tag == Maybe_290_None_t ) {
                return ( (struct Maybe_446) { .tag = Maybe_446_None_t } );
            }
            else {
                if ( dref1979.tag == Maybe_290_Just_t ) {
                    return ( ( Maybe_446_Just ) ( (  op_dash_add43 ( (  op_dash_mul45 ( ( dref1977 .stuff .Maybe_446_Just_s .field0 ) , (  from_dash_integral2 ( 10 ) ) ) ) , ( (  i32_dash_i64255 ) ( ( dref1979 .stuff .Maybe_290_Just_s .field0 ) ) ) ) ) ) );
                }
            }
        }
    }
}

static  struct Maybe_446   parse_dash_int724 (    struct DynStr_417  s1971 ) {
    struct SliceIter_269  cs1981 = ( (  chars708 ) ( (  s1971 ) ) );
    struct Maybe_276  dref1982 = ( (  head518 ) ( (  cs1981 ) ) );
    if ( dref1982.tag == Maybe_276_Just_t ) {
        return ( (  reduce448 ) ( (  cs1981 ) ,  ( ( Maybe_446_Just ) ( (  from_dash_integral2 ( 0 ) ) ) ) ,  (  sequence_dash_maybe725 ) ) );
    }
    else {
        if ( dref1982.tag == Maybe_276_None_t ) {
            return ( (struct Maybe_446) { .tag = Maybe_446_None_t } );
        }
    }
}

static  struct Maybe_446   sequence_dash_maybe727 (    char  e1974 ,    struct Maybe_446  b1976 ) {
    struct Maybe_446  dref1977 = (  b1976 );
    if ( dref1977.tag == Maybe_446_None_t ) {
        return ( (struct Maybe_446) { .tag = Maybe_446_None_t } );
    }
    else {
        if ( dref1977.tag == Maybe_446_Just_t ) {
            struct Maybe_290  dref1979 = ( (  parse_dash_digit721 ) ( (  e1974 ) ) );
            if ( dref1979.tag == Maybe_290_None_t ) {
                return ( (struct Maybe_446) { .tag = Maybe_446_None_t } );
            }
            else {
                if ( dref1979.tag == Maybe_290_Just_t ) {
                    return ( ( Maybe_446_Just ) ( (  op_dash_add43 ( (  op_dash_mul45 ( ( dref1977 .stuff .Maybe_446_Just_s .field0 ) , (  from_dash_integral2 ( 10 ) ) ) ) , ( (  i32_dash_i64255 ) ( ( dref1979 .stuff .Maybe_290_Just_s .field0 ) ) ) ) ) ) );
                }
            }
        }
    }
}

static  struct Maybe_446   parse_dash_int726 (    struct TakeWhile_349  s1971 ) {
    struct TakeWhile_349  cs1981 = ( (  chars633 ) ( (  s1971 ) ) );
    struct Maybe_276  dref1982 = ( (  head520 ) ( (  cs1981 ) ) );
    if ( dref1982.tag == Maybe_276_Just_t ) {
        return ( (  reduce490 ) ( (  cs1981 ) ,  ( ( Maybe_446_Just ) ( (  from_dash_integral2 ( 0 ) ) ) ) ,  (  sequence_dash_maybe727 ) ) );
    }
    else {
        if ( dref1982.tag == Maybe_276_None_t ) {
            return ( (struct Maybe_446) { .tag = Maybe_446_None_t } );
        }
    }
}

static  int32_t   lam729 (    int32_t  elem2006 ,    int32_t  b2008 ) {
    return (  op_dash_add47 ( (  op_dash_mul49 ( (  b2008 ) , (  from_dash_integral3 ( 8 ) ) ) ) , (  elem2006 ) ) );
}

static  int32_t   from_dash_octal728 (    struct SmolArray_71  arr2004 ) {
    return ( (  reduce498 ) ( (  arr2004 ) ,  (  from_dash_integral3 ( 0 ) ) ,  (  lam729 ) ) );
}

static  struct Maybe_653   hex_dash_digit730 (    char  c2011 ) {
    if ( ( (  cmp639 ( (  c2011 ) , ( (  from_dash_charlike1 ) ( ( "0" ) ) ) ) != 0 ) && (  cmp639 ( (  c2011 ) , ( (  from_dash_charlike1 ) ( ( "9" ) ) ) ) != 2 ) ) ) {
        return ( ( Maybe_653_Just ) ( (  op_dash_sub57 ( ( (  char_dash_u8636 ) ( (  c2011 ) ) ) , ( (  char_dash_u8636 ) ( ( (  from_dash_charlike1 ) ( ( "0" ) ) ) ) ) ) ) ) );
    }
    if ( ( (  cmp639 ( (  c2011 ) , ( (  from_dash_charlike1 ) ( ( "a" ) ) ) ) != 0 ) && (  cmp639 ( (  c2011 ) , ( (  from_dash_charlike1 ) ( ( "f" ) ) ) ) != 2 ) ) ) {
        return ( ( Maybe_653_Just ) ( (  op_dash_add56 ( (  op_dash_sub57 ( ( (  char_dash_u8636 ) ( (  c2011 ) ) ) , ( (  char_dash_u8636 ) ( ( (  from_dash_charlike1 ) ( ( "a" ) ) ) ) ) ) ) , (  from_dash_integral6 ( 10 ) ) ) ) ) );
    }
    if ( ( (  cmp639 ( (  c2011 ) , ( (  from_dash_charlike1 ) ( ( "A" ) ) ) ) != 0 ) && (  cmp639 ( (  c2011 ) , ( (  from_dash_charlike1 ) ( ( "F" ) ) ) ) != 2 ) ) ) {
        return ( ( Maybe_653_Just ) ( (  op_dash_add56 ( (  op_dash_sub57 ( ( (  char_dash_u8636 ) ( (  c2011 ) ) ) , ( (  char_dash_u8636 ) ( ( (  from_dash_charlike1 ) ( ( "A" ) ) ) ) ) ) ) , (  from_dash_integral6 ( 10 ) ) ) ) ) );
    }
    return ( (struct Maybe_653) { .tag = Maybe_653_None_t } );
}

static  uint32_t   lam732 (    char  c2016 ) {
    return ( (  from_dash_integral4 ) ( ( (  u8_dash_i64265 ) ( ( (  or_dash_fail652 ) ( ( (  hex_dash_digit730 ) ( (  c2016 ) ) ) ,  ( ( StrConcat_594_StrConcat ) ( ( ( StrConcat_595_StrConcat ) ( ( (  from_dash_charlike1 ) ( ( "\"" ) ) ) ,  (  c2016 ) ) ) ,  ( "\" is not a hex digit." ) ) ) ) ) ) ) ) );
}

static  uint32_t   lam733 (    uint32_t  elem2018 ,    uint32_t  b2020 ) {
    return (  op_dash_add52 ( (  op_dash_mul54 ( (  b2020 ) , (  from_dash_integral4 ( 16 ) ) ) ) , (  elem2018 ) ) );
}

static  uint32_t   from_dash_hex731 (    const char*  arr2014 ) {
    return ( (  reduce488 ) ( ( (  map283 ) ( (  arr2014 ) ,  (  lam732 ) ) ) ,  (  from_dash_integral4 ( 0 ) ) ,  (  lam733 ) ) );
}

static  struct Maybe_252   get734 (    const char*  s2057 ) {
    return ( (  from_dash_nullable_dash_c_dash_str251 ) ( ( ( getenv ) ( (  s2057 ) ) ) ) );
}

static  enum Unit_157   show_dash_cursor735 (  ) {
    ( (  print_dash_str465 ) ( ( "\x1b[?25h" ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   hide_dash_cursor736 (  ) {
    ( (  print_dash_str465 ) ( ( "\x1b[?25l" ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   move_dash_cursor_dash_to737 (    uint32_t  x2034 ,    uint32_t  y2036 ) {
    uint32_t  x2037 = (  op_dash_add52 ( (  x2034 ) , (  from_dash_integral4 ( 1 ) ) ) );
    uint32_t  y2038 = (  op_dash_add52 ( (  y2036 ) , (  from_dash_integral4 ( 1 ) ) ) );
    ( (  print_dash_str611 ) ( ( ( StrConcat_612_StrConcat ) ( ( ( StrConcat_613_StrConcat ) ( ( ( StrConcat_614_StrConcat ) ( ( ( StrConcat_581_StrConcat ) ( ( "\x1b[" ) ,  (  y2038 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ";" ) ) ) ) ) ,  (  x2037 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "H" ) ) ) ) ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   reset_dash_cursor_dash_position738 (  ) {
    ( (  print_dash_str465 ) ( ( "\x1b[H" ) ) );
    return ( Unit_157_Unit );
}

static  struct Tuple2_533   get_dash_dimensions739 (  ) {
    struct Winsize_162  temp740 = ( ( (  zeroed220 ) ( ) ) );
    struct Winsize_162 *  ws2042 = ( &temp740 );
    if ( ( (  eq9 ( ( ( ioctl ) ( ( (  stdout_dash_fileno78 ) ( ) ) ,  ( (  tiocgwinsz94 ) ( ) ) ,  (  ws2042 ) ) ) , (  op_dash_neg51 ( (  from_dash_integral3 ( 1 ) ) ) ) ) ) || (  eq12 ( ( ( * (  ws2042 ) ) .f_ws_dash_col ) , (  from_dash_integral5 ( 0 ) ) ) ) ) ) {
        return ( ( Tuple2_533_Tuple2 ) ( (  from_dash_integral4 ( 80 ) ) ,  (  from_dash_integral4 ( 24 ) ) ) );
    }
    return ( ( Tuple2_533_Tuple2 ) ( ( (  u16_dash_u32262 ) ( ( ( * (  ws2042 ) ) .f_ws_dash_col ) ) ) ,  ( (  u16_dash_u32262 ) ( ( ( * (  ws2042 ) ) .f_ws_dash_row ) ) ) ) );
}

static  enum Unit_157   set_dash_default_dash_fg741 (  ) {
    ( (  print_dash_str465 ) ( ( "\x1b[39m" ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   set_dash_default_dash_bg742 (  ) {
    ( (  print_dash_str465 ) ( ( "\x1b[49m" ) ) );
    return ( Unit_157_Unit );
}

static  enum ColorPalette_364   query_dash_palette743 (  ) {
    struct Maybe_252  colorterm2058 = ( (  get734 ) ( ( "COLORTERM" ) ) );
    struct Maybe_252  dref2059 = (  colorterm2058 );
    if ( dref2059.tag == Maybe_252_Just_t ) {
        if ( ( (  eq638 ( ( dref2059 .stuff .Maybe_252_Just_s .field0 ) , ( "truecolor" ) ) ) || (  eq638 ( ( dref2059 .stuff .Maybe_252_Just_s .field0 ) , ( "24bit" ) ) ) ) ) {
            return ( ColorPalette_364_PaletteRGB );
        }
    }
    else {
        if ( dref2059.tag == Maybe_252_None_t ) {
        }
    }
    struct Maybe_252  dref2061 = ( (  get734 ) ( ( "TERM" ) ) );
    if ( dref2061.tag == Maybe_252_Just_t ) {
        if ( (  eq638 ( ( dref2061 .stuff .Maybe_252_Just_s .field0 ) , ( "linux" ) ) ) ) {
            return ( ColorPalette_364_Palette8 );
        }
    }
    else {
        if ( dref2061.tag == Maybe_252_None_t ) {
        }
    }
    return ( ColorPalette_364_Palette16 );
}

static  enum Unit_157   set_dash_fg8744 (    enum Color8_18  color2077 ) {
    enum Color8_18  dref2078 = (  color2077 );
    switch (  dref2078 ) {
        case Color8_18_Black8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[30m" ) ) );
            break;
        }
        case Color8_18_Red8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[31m" ) ) );
            break;
        }
        case Color8_18_Green8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[32m" ) ) );
            break;
        }
        case Color8_18_Yellow8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[33m" ) ) );
            break;
        }
        case Color8_18_Blue8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[34m" ) ) );
            break;
        }
        case Color8_18_Magenta8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[35m" ) ) );
            break;
        }
        case Color8_18_Cyan8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[36m" ) ) );
            break;
        }
        case Color8_18_White8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[37m" ) ) );
            break;
        }
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   set_dash_fg16745 (    enum Color16_19  color2081 ) {
    enum Color16_19  dref2082 = (  color2081 );
    switch (  dref2082 ) {
        case Color16_19_Black16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[30m" ) ) );
            break;
        }
        case Color16_19_Red16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[31m" ) ) );
            break;
        }
        case Color16_19_Green16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[32m" ) ) );
            break;
        }
        case Color16_19_Yellow16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[33m" ) ) );
            break;
        }
        case Color16_19_Blue16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[34m" ) ) );
            break;
        }
        case Color16_19_Magenta16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[35m" ) ) );
            break;
        }
        case Color16_19_Cyan16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[36m" ) ) );
            break;
        }
        case Color16_19_White16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[37m" ) ) );
            break;
        }
        case Color16_19_BrightBlack16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[90m" ) ) );
            break;
        }
        case Color16_19_BrightRed16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[91m" ) ) );
            break;
        }
        case Color16_19_BrightGreen16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[92m" ) ) );
            break;
        }
        case Color16_19_BrightYellow16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[93m" ) ) );
            break;
        }
        case Color16_19_BrightBlue16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[94m" ) ) );
            break;
        }
        case Color16_19_BrightMagenta16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[95m" ) ) );
            break;
        }
        case Color16_19_BrightCyan16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[96m" ) ) );
            break;
        }
        case Color16_19_BrightWhite16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[97m" ) ) );
            break;
        }
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   set_dash_bg8746 (    enum Color8_18  color2085 ) {
    enum Color8_18  dref2086 = (  color2085 );
    switch (  dref2086 ) {
        case Color8_18_Black8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[40m" ) ) );
            break;
        }
        case Color8_18_Red8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[41m" ) ) );
            break;
        }
        case Color8_18_Green8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[42m" ) ) );
            break;
        }
        case Color8_18_Yellow8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[43m" ) ) );
            break;
        }
        case Color8_18_Blue8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[44m" ) ) );
            break;
        }
        case Color8_18_Magenta8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[45m" ) ) );
            break;
        }
        case Color8_18_Cyan8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[46m" ) ) );
            break;
        }
        case Color8_18_White8 : {
            ( (  print_dash_str465 ) ( ( "\x1b[47m" ) ) );
            break;
        }
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   set_dash_bg16747 (    enum Color16_19  color2089 ) {
    enum Color16_19  dref2090 = (  color2089 );
    switch (  dref2090 ) {
        case Color16_19_Black16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[40m" ) ) );
            break;
        }
        case Color16_19_Red16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[41m" ) ) );
            break;
        }
        case Color16_19_Green16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[42m" ) ) );
            break;
        }
        case Color16_19_Yellow16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[43m" ) ) );
            break;
        }
        case Color16_19_Blue16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[44m" ) ) );
            break;
        }
        case Color16_19_Magenta16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[45m" ) ) );
            break;
        }
        case Color16_19_Cyan16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[46m" ) ) );
            break;
        }
        case Color16_19_White16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[47m" ) ) );
            break;
        }
        case Color16_19_BrightBlack16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[100m" ) ) );
            break;
        }
        case Color16_19_BrightRed16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[101m" ) ) );
            break;
        }
        case Color16_19_BrightGreen16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[102m" ) ) );
            break;
        }
        case Color16_19_BrightYellow16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[103m" ) ) );
            break;
        }
        case Color16_19_BrightBlue16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[104m" ) ) );
            break;
        }
        case Color16_19_BrightMagenta16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[105m" ) ) );
            break;
        }
        case Color16_19_BrightCyan16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[106m" ) ) );
            break;
        }
        case Color16_19_BrightWhite16 : {
            ( (  print_dash_str465 ) ( ( "\x1b[107m" ) ) );
            break;
        }
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   reset_dash_colors748 (  ) {
    ( (  print_dash_str465 ) ( ( "\x1b[0m" ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   clear_dash_screen749 (  ) {
    ( (  print_dash_str465 ) ( ( "\x1b[2J" ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   set_dash_fg256750 (    uint8_t  color2095 ) {
    ( (  print_dash_str618 ) ( ( ( StrConcat_619_StrConcat ) ( ( ( StrConcat_620_StrConcat ) ( ( "\x1b[38;5;" ) ,  (  color2095 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "m" ) ) ) ) ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   set_dash_bg256751 (    uint8_t  color2098 ) {
    ( (  print_dash_str618 ) ( ( ( StrConcat_619_StrConcat ) ( ( ( StrConcat_620_StrConcat ) ( ( "\x1b[48;5;" ) ,  (  color2098 ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "m" ) ) ) ) ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   set_dash_fg_dash_rgb752 (    struct RGB_20  c2118 ) {
    ( (  print_dash_str622 ) ( ( ( StrConcat_623_StrConcat ) ( ( ( StrConcat_624_StrConcat ) ( ( ( StrConcat_625_StrConcat ) ( ( ( StrConcat_626_StrConcat ) ( ( ( StrConcat_619_StrConcat ) ( ( ( StrConcat_620_StrConcat ) ( ( "\x1b[38;2;" ) ,  ( (  c2118 ) .f_r ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ";" ) ) ) ) ) ,  ( (  c2118 ) .f_g ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ";" ) ) ) ) ) ,  ( (  c2118 ) .f_b ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "m" ) ) ) ) ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   set_dash_bg_dash_rgb753 (    struct RGB_20  c2121 ) {
    ( (  print_dash_str622 ) ( ( ( StrConcat_623_StrConcat ) ( ( ( StrConcat_624_StrConcat ) ( ( ( StrConcat_625_StrConcat ) ( ( ( StrConcat_626_StrConcat ) ( ( ( StrConcat_619_StrConcat ) ( ( ( StrConcat_620_StrConcat ) ( ( "\x1b[48;2;" ) ,  ( (  c2121 ) .f_r ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ";" ) ) ) ) ) ,  ( (  c2121 ) .f_g ) ) ) ,  ( (  from_dash_charlike1 ) ( ( ";" ) ) ) ) ) ,  ( (  c2121 ) .f_b ) ) ) ,  ( (  from_dash_charlike1 ) ( ( "m" ) ) ) ) ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   set_dash_fg754 (    struct Color_17  c2139 ) {
    struct Color_17  dref2140 = (  c2139 );
    if ( dref2140.tag == Color_17_ColorDefault_t ) {
        ( (  set_dash_default_dash_fg741 ) ( ) );
    }
    else {
        if ( dref2140.tag == Color_17_Color8_t ) {
            ( (  set_dash_fg8744 ) ( ( dref2140 .stuff .Color_17_Color8_s .field0 ) ) );
        }
        else {
            if ( dref2140.tag == Color_17_Color16_t ) {
                ( (  set_dash_fg16745 ) ( ( dref2140 .stuff .Color_17_Color16_s .field0 ) ) );
            }
            else {
                if ( dref2140.tag == Color_17_Color256_t ) {
                    ( (  set_dash_fg256750 ) ( ( dref2140 .stuff .Color_17_Color256_s .field0 ) ) );
                }
                else {
                    if ( dref2140.tag == Color_17_ColorRGB_t ) {
                        ( (  set_dash_fg_dash_rgb752 ) ( ( dref2140 .stuff .Color_17_ColorRGB_s .field0 ) ) );
                    }
                }
            }
        }
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   set_dash_bg755 (    struct Color_17  c2147 ) {
    struct Color_17  dref2148 = (  c2147 );
    if ( dref2148.tag == Color_17_ColorDefault_t ) {
        ( (  set_dash_default_dash_bg742 ) ( ) );
    }
    else {
        if ( dref2148.tag == Color_17_Color8_t ) {
            ( (  set_dash_bg8746 ) ( ( dref2148 .stuff .Color_17_Color8_s .field0 ) ) );
        }
        else {
            if ( dref2148.tag == Color_17_Color16_t ) {
                ( (  set_dash_bg16747 ) ( ( dref2148 .stuff .Color_17_Color16_s .field0 ) ) );
            }
            else {
                if ( dref2148.tag == Color_17_Color256_t ) {
                    ( (  set_dash_bg256751 ) ( ( dref2148 .stuff .Color_17_Color256_s .field0 ) ) );
                }
                else {
                    if ( dref2148.tag == Color_17_ColorRGB_t ) {
                        ( (  set_dash_bg_dash_rgb753 ) ( ( dref2148 .stuff .Color_17_ColorRGB_s .field0 ) ) );
                    }
                }
            }
        }
    }
    return ( Unit_157_Unit );
}

struct env756 {
    ;
    ;
    ;
    ;
    struct env384 envinst384;
    ;
    ;
};

static  enum Unit_157   lam380 (   struct env380 env ,    char  c2204 ) {
    struct funenv384  temp757 = ( (struct funenv384){ .fun = add384, .env =  env.envinst384  } );
    return ( temp757.fun ( temp757.env ,  ( & ( ( * ( env.builder2200 ) ) .f_chars ) ) ,  (  c2204 ) ) );
}

static  enum Unit_157   write756 (   struct env756 env ,    struct StrBuilder_381 *  builder2200 ,    struct StrConcat_568  s2202 ) {
    struct env380 envinst380 = {
        .builder2200 =  builder2200 ,
        .envinst384 = env.envinst384 ,
    };
    ( (  for_dash_each376 ) ( ( (  chars577 ) ( (  s2202 ) ) ) ,  ( (struct funenv380){ .fun = lam380, .env = envinst380 } ) ) );
    return ( Unit_157_Unit );
}

static  struct SliceIter_269   chars758 (    struct StrBuilder_381  s2248 ) {
    return ( (  into_dash_iter704 ) ( ( (  s2248 ) .f_chars ) ) );
}

static  enum Unit_157   lam421 (   struct env421 env ,    char  c2204 ) {
    struct funenv384  temp759 = ( (struct funenv384){ .fun = add384, .env =  env.envinst384  } );
    return ( temp759.fun ( temp759.env ,  ( & ( ( * ( env.builder2200 ) ) .f_chars ) ) ,  (  c2204 ) ) );
}

static  enum Unit_157   write416 (   struct env416 env ,    struct StrBuilder_381 *  builder2200 ,    struct StrBuilder_381  s2202 ) {
    struct env421 envinst421 = {
        .builder2200 =  builder2200 ,
        .envinst384 = env.envinst384 ,
    };
    ( (  for_dash_each420 ) ( ( (  chars758 ) ( (  s2202 ) ) ) ,  ( (struct funenv421){ .fun = lam421, .env = envinst421 } ) ) );
    return ( Unit_157_Unit );
}

struct env760 {
    ;
    ;
    ;
    ;
    struct env384 envinst384;
    ;
    ;
};

static  enum Unit_157   lam427 (   struct env427 env ,    char  c2204 ) {
    struct funenv384  temp761 = ( (struct funenv384){ .fun = add384, .env =  env.envinst384  } );
    return ( temp761.fun ( temp761.env ,  ( & ( ( * ( env.builder2200 ) ) .f_chars ) ) ,  (  c2204 ) ) );
}

static  enum Unit_157   write760 (   struct env760 env ,    struct StrBuilder_381 *  builder2200 ,    struct StrConcat_576  s2202 ) {
    struct env427 envinst427 = {
        .builder2200 =  builder2200 ,
        .envinst384 = env.envinst384 ,
    };
    ( (  for_dash_each425 ) ( ( (  chars630 ) ( (  s2202 ) ) ) ,  ( (struct funenv427){ .fun = lam427, .env = envinst427 } ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   write_dash_char412 (   struct env412 env ,    struct StrBuilder_381 *  builder2212 ,    char  c2214 ) {
    struct funenv384  temp762 = ( (struct funenv384){ .fun = add384, .env =  env.envinst384  } );
    ( temp762.fun ( temp762.env ,  ( & ( ( * (  builder2212 ) ) .f_chars ) ) ,  (  c2214 ) ) );
    return ( Unit_157_Unit );
}

static  size_t   count763 (    struct StrBuilder_381 *  sb2225 ) {
    return ( ( ( * (  sb2225 ) ) .f_chars ) .f_count );
}

static  struct StrBuilder_381   mk764 (    enum CAllocator_383  al2228 ) {
    return ( (struct StrBuilder_381) { .f_chars = ( (  mk705 ) ( (  al2228 ) ) ) } );
}

static  struct DynStr_417   as_dash_str765 (    struct StrBuilder_381 *  builder2234 ) {
    return ( (struct DynStr_417) { .f_contents = ( (  subslice677 ) ( ( ( ( * (  builder2234 ) ) .f_chars ) .f_elements ) ,  (  from_dash_integral8 ( 0 ) ) ,  ( ( ( * (  builder2234 ) ) .f_chars ) .f_count ) ) ) } );
}

static  enum Unit_157   free766 (    struct StrBuilder_381 *  builder2240 ) {
    ( (  free706 ) ( ( & ( ( * (  builder2240 ) ) .f_chars ) ) ) );
    return ( Unit_157_Unit );
}

struct funenv756 {
    enum Unit_157  (*fun) (  struct env756  ,    struct StrBuilder_381 *  ,    struct StrConcat_568  );
    struct env756 env;
};

struct env767 {
    ;
    struct env756 envinst756;
    ;
    ;
    struct env412 envinst412;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
};

static  struct DynStr_417   mk_dash_dyn_dash_str767 (   struct env767 env ,    struct StrConcat_568  s2254 ,    enum CAllocator_383  al2256 ) {
    struct StrBuilder_381  temp768 = ( (  mk764 ) ( (  al2256 ) ) );
    struct StrBuilder_381 *  sb2257 = ( &temp768 );
    struct funenv756  temp769 = ( (struct funenv756){ .fun = write756, .env =  env.envinst756  } );
    ( temp769.fun ( temp769.env ,  (  sb2257 ) ,  (  s2254 ) ) );
    struct funenv412  temp770 = ( (struct funenv412){ .fun = write_dash_char412, .env =  env.envinst412  } );
    ( temp770.fun ( temp770.env ,  (  sb2257 ) ,  ( (  nullchar634 ) ( ) ) ) );
    struct DynStr_417  dynstr2258 = ( (  as_dash_str765 ) ( (  sb2257 ) ) );
    return ( (struct DynStr_417) { .f_contents = ( (struct Slice_270) { .f_ptr = ( ( (  dynstr2258 ) .f_contents ) .f_ptr ) , .f_count = (  op_dash_sub59 ( ( ( (  dynstr2258 ) .f_contents ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) } ) } );
}

static  struct DynStr_417   mk_dash_dyn_dash_str415 (   struct env415 env ,    struct StrBuilder_381  s2254 ,    enum CAllocator_383  al2256 ) {
    struct StrBuilder_381  temp771 = ( (  mk764 ) ( (  al2256 ) ) );
    struct StrBuilder_381 *  sb2257 = ( &temp771 );
    struct funenv416  temp772 = ( (struct funenv416){ .fun = write416, .env =  env.envinst416  } );
    ( temp772.fun ( temp772.env ,  (  sb2257 ) ,  (  s2254 ) ) );
    struct funenv412  temp773 = ( (struct funenv412){ .fun = write_dash_char412, .env =  env.envinst412  } );
    ( temp773.fun ( temp773.env ,  (  sb2257 ) ,  ( (  nullchar634 ) ( ) ) ) );
    struct DynStr_417  dynstr2258 = ( (  as_dash_str765 ) ( (  sb2257 ) ) );
    return ( (struct DynStr_417) { .f_contents = ( (struct Slice_270) { .f_ptr = ( ( (  dynstr2258 ) .f_contents ) .f_ptr ) , .f_count = (  op_dash_sub59 ( ( ( (  dynstr2258 ) .f_contents ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) } ) } );
}

struct funenv760 {
    enum Unit_157  (*fun) (  struct env760  ,    struct StrBuilder_381 *  ,    struct StrConcat_576  );
    struct env760 env;
};

struct env774 {
    ;
    struct env760 envinst760;
    ;
    ;
    struct env412 envinst412;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
};

static  struct DynStr_417   mk_dash_dyn_dash_str774 (   struct env774 env ,    struct StrConcat_576  s2254 ,    enum CAllocator_383  al2256 ) {
    struct StrBuilder_381  temp775 = ( (  mk764 ) ( (  al2256 ) ) );
    struct StrBuilder_381 *  sb2257 = ( &temp775 );
    struct funenv760  temp776 = ( (struct funenv760){ .fun = write760, .env =  env.envinst760  } );
    ( temp776.fun ( temp776.env ,  (  sb2257 ) ,  (  s2254 ) ) );
    struct funenv412  temp777 = ( (struct funenv412){ .fun = write_dash_char412, .env =  env.envinst412  } );
    ( temp777.fun ( temp777.env ,  (  sb2257 ) ,  ( (  nullchar634 ) ( ) ) ) );
    struct DynStr_417  dynstr2258 = ( (  as_dash_str765 ) ( (  sb2257 ) ) );
    return ( (struct DynStr_417) { .f_contents = ( (struct Slice_270) { .f_ptr = ( ( (  dynstr2258 ) .f_contents ) .f_ptr ) , .f_count = (  op_dash_sub59 ( ( ( (  dynstr2258 ) .f_contents ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) } ) } );
}

struct funenv767 {
    struct DynStr_417  (*fun) (  struct env767  ,    struct StrConcat_568  ,    enum CAllocator_383  );
    struct env767 env;
};

struct env778 {
    ;
    ;
    ;
    struct env767 envinst767;
    ;
    ;
    ;
};

static  const char*   mk_dash_const_dash_str778 (   struct env778 env ,    struct StrConcat_568  s2261 ,    enum CAllocator_383  al2263 ) {
    struct funenv767  temp779 = ( (struct funenv767){ .fun = mk_dash_dyn_dash_str767, .env =  env.envinst767  } );
    return ( ( (  cast173 ) ( ( ( ( temp779.fun ( temp779.env ,  (  s2261 ) ,  (  al2263 ) ) ) .f_contents ) .f_ptr ) ) ) );
}

static  const char*   mk_dash_const_dash_str414 (   struct env414 env ,    struct StrBuilder_381  s2261 ,    enum CAllocator_383  al2263 ) {
    struct funenv415  temp780 = ( (struct funenv415){ .fun = mk_dash_dyn_dash_str415, .env =  env.envinst415  } );
    return ( ( (  cast173 ) ( ( ( ( temp780.fun ( temp780.env ,  (  s2261 ) ,  (  al2263 ) ) ) .f_contents ) .f_ptr ) ) ) );
}

struct funenv774 {
    struct DynStr_417  (*fun) (  struct env774  ,    struct StrConcat_576  ,    enum CAllocator_383  );
    struct env774 env;
};

struct env781 {
    ;
    ;
    ;
    struct env774 envinst774;
    ;
    ;
    ;
};

static  const char*   mk_dash_const_dash_str781 (   struct env781 env ,    struct StrConcat_576  s2261 ,    enum CAllocator_383  al2263 ) {
    struct funenv774  temp782 = ( (struct funenv774){ .fun = mk_dash_dyn_dash_str774, .env =  env.envinst774  } );
    return ( ( (  cast173 ) ( ( ( ( temp782.fun ( temp782.env ,  (  s2261 ) ,  (  al2263 ) ) ) .f_contents ) .f_ptr ) ) ) );
}

static  enum Unit_157   free_dash_const_dash_str783 (    const char*  s2266 ,    enum CAllocator_383  al2268 ) {
    ( (  free699 ) ( (  al2268 ) ,  ( (struct Slice_700) { .f_ptr = ( (enum Unit_157 * ) (  s2266 ) ) , .f_count = (  from_dash_integral8 ( 0 ) ) } ) ) );
    return ( Unit_157_Unit );
}

static  uint32_t   u32_dash_or784 (    uint32_t  l2271 ,    uint32_t  r2273 ) {
    return ( (  l2271 ) | (  r2273 ) );
}

static  uint32_t   u32_dash_ors785 (    struct SmolArray_62  vals2276 ) {
    return ( (  reduce450 ) ( (  vals2276 ) ,  (  from_dash_integral4 ( 0 ) ) ,  (  u32_dash_or784 ) ) );
}

static  uint32_t   u32_dash_ors786 (    struct SmolArray_65  vals2276 ) {
    return ( (  reduce474 ) ( (  vals2276 ) ,  (  from_dash_integral4 ( 0 ) ) ,  (  u32_dash_or784 ) ) );
}

static  uint32_t   u32_dash_ors787 (    struct SmolArray_68  vals2276 ) {
    return ( (  reduce481 ) ( (  vals2276 ) ,  (  from_dash_integral4 ( 0 ) ) ,  (  u32_dash_or784 ) ) );
}

static  uint32_t   u32_dash_and788 (    uint32_t  l2279 ,    uint32_t  r2281 ) {
    return ( (  l2279 ) & (  r2281 ) );
}

static  uint32_t   u32_dash_neg789 (    uint32_t  l2284 ) {
    return ( ~ (  l2284 ) );
}

static  struct Maybe_537   try_dash_read_dash_contents790 (    const char*  filename2387 ,    enum CAllocator_383  al2389 ) {
    FILE *  file2390 = ( ( fopen ) ( (  filename2387 ) ,  ( (  from_dash_charlike0 ) ( ( "r" ) ) ) ) );
    if ( ( (  is_dash_ptr_dash_null249 ) ( (  file2390 ) ) ) ) {
        return ( (struct Maybe_537) { .tag = Maybe_537_None_t } );
    }
    ( ( fseek ) ( (  file2390 ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  seek_dash_end77 ) ( ) ) ) );
    int32_t  file_dash_size2391 = ( ( ftell ) ( (  file2390 ) ) );
    ( ( fseek ) ( (  file2390 ) ,  (  from_dash_integral3 ( 0 ) ) ,  ( (  seek_dash_set76 ) ( ) ) ) );
    struct Slice_270  file_dash_buf2392 = ( ( (  allocate695 ) ( (  al2389 ) ,  (  op_dash_add58 ( ( (  i32_dash_size256 ) ( (  file_dash_size2391 ) ) ) , (  from_dash_integral8 ( 1 ) ) ) ) ) ) );
    ( ( fread ) ( ( (  file_dash_buf2392 ) .f_ptr ) ,  (  from_dash_integral3 ( 1 ) ) ,  (  file_dash_size2391 ) ,  (  file2390 ) ) );
    ( (  set672 ) ( (  file_dash_buf2392 ) ,  ( (  i32_dash_size256 ) ( (  file_dash_size2391 ) ) ) ,  ( (  nullchar634 ) ( ) ) ) );
    ( ( fclose ) ( (  file2390 ) ) );
    struct DynStr_417  str2393 = ( (struct DynStr_417) { .f_contents = (  file_dash_buf2392 ) } );
    return ( ( Maybe_537_Just ) ( (  str2393 ) ) );
}

static  bool   try_dash_write_dash_contents791 (    const char*  filename2401 ,    struct StrConcat_579  contents2403 ) {
    FILE *  file2404 = ( ( fopen ) ( (  filename2401 ) ,  ( (  from_dash_charlike0 ) ( ( "w" ) ) ) ) );
    if ( ( (  is_dash_ptr_dash_null249 ) ( (  file2404 ) ) ) ) {
        return ( false );
    }
    struct StrConcatIter_566  it2405 = ( (  chars631 ) ( (  contents2403 ) ) );
    while ( ( true ) ) {
        struct Maybe_276  dref2406 = ( (  next565 ) ( ( & (  it2405 ) ) ) );
        if ( dref2406.tag == Maybe_276_None_t ) {
            ( ( fclose ) ( (  file2404 ) ) );
            return ( true );
        }
        else {
            if ( dref2406.tag == Maybe_276_Just_t ) {
                int32_t  chars_dash_written2408 = ( ( fprintf ) ( (  file2404 ) ,  ( "%c" ) ,  ( dref2406 .stuff .Maybe_276_Just_s .field0 ) ) );
                if ( (  cmp40 ( (  chars_dash_written2408 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) ) {
                    return ( false );
                }
            }
        }
    }
    return ( (  unreachable640 ) ( ) );
}

static  enum Unit_157   write_dash_contents792 (    const char*  filename2411 ,    struct StrConcat_579  contents2413 ) {
    if ( ( ! ( (  try_dash_write_dash_contents791 ) ( (  filename2411 ) ,  (  contents2413 ) ) ) ) ) {
        ( (  panic644 ) ( ( ( StrConcat_570_StrConcat ) ( ( "could not write to file " ) ,  (  filename2411 ) ) ) ) );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   mkdir413 (   struct env413 env ,    struct StrBuilder_381  path2363 ,    enum CAllocator_383  al2365 ) {
    struct funenv414  temp793 = ( (struct funenv414){ .fun = mk_dash_const_dash_str414, .env =  env.envinst414  } );
    const char*  path2366 = ( temp793.fun ( temp793.env ,  (  path2363 ) ,  (  al2365 ) ) );
    if ( ( !  eq9 ( ( ( mkdir ) ( (  path2366 ) ,  ( (  from_dash_octal728 ) ( ( (  from_dash_listlike70 ) ( ( (struct Array_72) { ._arr = { (  from_dash_integral3 ( 7 ) ) , (  from_dash_integral3 ( 7 ) ) , (  from_dash_integral3 ( 7 ) ) } } ) ) ) ) ) ) ) , (  from_dash_integral3 ( 0 ) ) ) ) ) {
        if ( ( ! ( (  errno_dash_EEXIST95 ) ( ) ) ) ) {
            ( (  panic641 ) ( ( "mkdir() failed" ) ) );
        }
        struct Stat_75  stat2367 = ( (  undefined121 ) ( ) );
        ( ( stat ) ( (  path2366 ) ,  ( (  ptr_dash_castptr74 ) ( ( & (  stat2367 ) ) ) ) ) );
        if ( ( !  eq10 ( ( (  u32_dash_and788 ) ( ( (  stat2367 ) .f_mode ) ,  ( (  s_dash_ifmt96 ) ( ) ) ) ) , ( (  s_dash_ifdir97 ) ( ) ) ) ) ) {
            ( (  panic641 ) ( ( "mkdir() failed: path exists but is not a directory" ) ) );
        }
    }
    ( (  free_dash_const_dash_str783 ) ( (  path2366 ) ,  (  al2365 ) ) );
    return ( Unit_157_Unit );
}

struct env794 {
    ;
    ;
    ;
    struct env412 envinst412;
    ;
    struct env413 envinst413;
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
};

static  enum Unit_157   lam411 (   struct env411 env ,    char  c2375 ) {
    if ( (  eq14 ( (  c2375 ) , ( (  from_dash_charlike1 ) ( ( "/" ) ) ) ) ) ) {
        if ( (  cmp39 ( ( (  count763 ) ( ( env.sb2373 ) ) ) , (  from_dash_integral8 ( 0 ) ) ) == 2 ) ) {
            struct funenv413  temp796 = ( (struct funenv413){ .fun = mkdir413, .env =  env.envinst413  } );
            ( temp796.fun ( temp796.env ,  ( * ( env.sb2373 ) ) ,  ( env.al2372 ) ) );
        }
    }
    struct funenv412  temp797 = ( (struct funenv412){ .fun = write_dash_char412, .env =  env.envinst412  } );
    ( temp797.fun ( temp797.env ,  ( env.sb2373 ) ,  (  c2375 ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   mkdir_dash_p794 (   struct env794 env ,    struct StrConcat_568  path2370 ,    enum CAllocator_383  al2372 ) {
    struct StrBuilder_381  temp795 = ( (  mk764 ) ( (  al2372 ) ) );
    struct StrBuilder_381 *  sb2373 = ( &temp795 );
    struct env411 envinst411 = {
        .al2372 =  al2372 ,
        .envinst412 = env.envinst412 ,
        .envinst413 = env.envinst413 ,
        .sb2373 =  sb2373 ,
    };
    ( (  for_dash_each410 ) ( ( (  chars577 ) ( (  path2370 ) ) ) ,  ( (struct funenv411){ .fun = lam411, .env = envinst411 } ) ) );
    struct funenv413  temp798 = ( (struct funenv413){ .fun = mkdir413, .env =  env.envinst413  } );
    ( temp798.fun ( temp798.env ,  ( * (  sb2373 ) ) ,  (  al2372 ) ) );
    ( (  free766 ) ( (  sb2373 ) ) );
    return ( Unit_157_Unit );
}

static  uint32_t   next_dash_u32799 (  ) {
    return ( (  cast169 ) ( ( ( rand ) ( ) ) ) );
}

static  struct Scanner_268   mk800 (    struct DynStr_417  s2655 ) {
    return ( (struct Scanner_268) { .f_s = ( (  chars708 ) ( (  s2655 ) ) ) } );
}

static  struct Maybe_446   scan_dash_int801 (    struct Scanner_268 *  sc2658 ) {
    struct TakeWhile_349  digit_dash_chars2659 = ( (  take_dash_while352 ) ( (  sc2658 ) ,  (  is_dash_digit720 ) ) );
    if ( ( (  null528 ) ( (  digit_dash_chars2659 ) ) ) ) {
        return ( (struct Maybe_446) { .tag = Maybe_446_None_t } );
    }
    ( (  drop_prime_529 ) ( (  sc2658 ) ,  ( (  count511 ) ( (  digit_dash_chars2659 ) ) ) ) );
    return ( (  parse_dash_int726 ) ( (  digit_dash_chars2659 ) ) );
}

static  struct timespec   now802 (  ) {
    struct timespec  temp803 = ( (  undefined108 ) ( ) );
    struct timespec *  t2672 = ( &temp803 );
    ( ( clock_gettime ) ( ( (  clock_dash_monotonic73 ) ( ) ) ,  (  t2672 ) ) );
    return ( * (  t2672 ) );
}

static  struct Termios_111   enable_dash_raw_dash_mode804 (  ) {
    struct Termios_111  temp805 = ( (  undefined110 ) ( ) );
    struct Termios_111 *  orig_dash_termios2710 = ( &temp805 );
    ( ( tcgetattr ) ( ( (  stdin_dash_fileno79 ) ( ) ) ,  ( (  cast_dash_ptr195 ) ( (  orig_dash_termios2710 ) ) ) ) );
    struct Termios_111  raw2711 = ( * (  orig_dash_termios2710 ) );
    raw2711 .f_c_dash_lflag = ( (  u32_dash_and788 ) ( ( (  raw2711 ) .f_c_dash_lflag ) ,  ( (  u32_dash_neg789 ) ( ( (  u32_dash_ors785 ) ( ( (  from_dash_listlike61 ) ( ( (struct Array_63) { ._arr = { ( (  echo80 ) ( ) ) , ( (  icanon81 ) ( ) ) , ( (  isig82 ) ( ) ) , ( ( (  iexten83 ) ( ) ) ) } } ) ) ) ) ) ) ) ) );
    raw2711 .f_c_dash_iflag = ( (  u32_dash_and788 ) ( ( (  raw2711 ) .f_c_dash_iflag ) ,  ( (  u32_dash_neg789 ) ( ( (  u32_dash_ors786 ) ( ( (  from_dash_listlike64 ) ( ( (struct Array_66) { ._arr = { ( (  brkint84 ) ( ) ) , ( (  icrnl85 ) ( ) ) , ( (  inpck86 ) ( ) ) , ( (  istrip87 ) ( ) ) , ( ( (  ixon88 ) ( ) ) ) } } ) ) ) ) ) ) ) ) );
    raw2711 .f_c_dash_oflag = ( (  u32_dash_and788 ) ( ( (  raw2711 ) .f_c_dash_oflag ) ,  ( (  u32_dash_neg789 ) ( ( (  u32_dash_ors787 ) ( ( (  from_dash_listlike67 ) ( ( (struct Array_69) { ._arr = { ( ( (  opost89 ) ( ) ) ) } } ) ) ) ) ) ) ) ) );
    raw2711 .f_c_dash_cflag = ( (  u32_dash_or784 ) ( ( (  raw2711 ) .f_c_dash_cflag ) ,  ( (  cs890 ) ( ) ) ) );
    ( (  set712 ) ( ( & ( (  raw2711 ) .f_c_dash_cc ) ) ,  ( (  vmin91 ) ( ) ) ,  (  from_dash_integral6 ( 0 ) ) ) );
    ( (  set712 ) ( ( & ( (  raw2711 ) .f_c_dash_cc ) ) ,  ( (  vtime92 ) ( ) ) ,  (  from_dash_integral6 ( 0 ) ) ) );
    ( ( tcsetattr ) ( ( (  stdin_dash_fileno79 ) ( ) ) ,  ( (  tcsa_dash_flush93 ) ( ) ) ,  ( (  cast_dash_ptr195 ) ( ( & (  raw2711 ) ) ) ) ) );
    return ( * (  orig_dash_termios2710 ) );
}

static  enum Unit_157   disable_dash_raw_dash_mode806 (    struct Termios_111 *  og_dash_termios2714 ) {
    ( ( tcsetattr ) ( ( (  stdin_dash_fileno79 ) ( ) ) ,  ( (  tcsa_dash_flush93 ) ( ) ) ,  ( (  cast_dash_ptr195 ) ( (  og_dash_termios2714 ) ) ) ) );
    return ( Unit_157_Unit );
}

static  struct Maybe_276   read_dash_byte807 (    int32_t  timeout_dash_ms2718 ) {
    struct Pollfd_203  pfd2719 = ( (struct Pollfd_203) { .f_fd = (  from_dash_integral3 ( 0 ) ) , .f_events = (  from_dash_integral5 ( 1 ) ) , .f_revents = (  from_dash_integral5 ( 0 ) ) } );
    if ( (  cmp40 ( ( ( poll ) ( ( (  cast_dash_ptr202 ) ( ( & (  pfd2719 ) ) ) ) ,  (  from_dash_integral3 ( 1 ) ) ,  (  timeout_dash_ms2718 ) ) ) , (  from_dash_integral3 ( 0 ) ) ) != 2 ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    char  c2720 = ( ( (  zeroed214 ) ( ) ) );
    if ( (  cmp40 ( ( ( read ) ( ( (  stdin_dash_fileno79 ) ( ) ) ,  ( (  cast_dash_ptr188 ) ( ( & (  c2720 ) ) ) ) ,  (  from_dash_integral8 ( 1 ) ) ) ) , (  from_dash_integral3 ( 0 ) ) ) != 2 ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    return ( ( Maybe_276_Just ) ( (  c2720 ) ) );
}

static  enum Unit_157   flush_dash_stdout808 (  ) {
    ( ( fflush ) ( ( (  null_dash_ptr245 ) ( ) ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   enable_dash_mouse809 (  ) {
    ( (  print_dash_str465 ) ( ( "\x1b[?1000h\x1b[?1006h" ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   disable_dash_mouse810 (  ) {
    ( (  print_dash_str465 ) ( ( "\x1b[?1000l\x1b[?1006l" ) ) );
    return ( Unit_157_Unit );
}

struct env812 {
    ;
    ;
    ;
    bool *  should_dash_resize2724;
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
};

struct env813 {
    bool *  should_dash_resize2724;
};

struct funenv813 {
    enum Unit_157  (*fun) (  struct env813  ,    int32_t  );
    struct env813 env;
};

struct funenv813  _intr_sigarr[32];

static void _intr_sighandle (    int32_t  __intr__sig814 ) {
    struct funenv813  temp815 = _intr_sigarr [  __intr__sig814 ];
    temp815.fun ( temp815.env ,  __intr__sig814 );
}

static  enum Unit_157  _intr_register_signal (    int32_t  __intr__sig816 ,   struct funenv813  __intr__fun817 ) {
    _intr_sigarr [  __intr__sig816 ] =  __intr__fun817;
    signal(  __intr__sig816 , _intr_sighandle );
    return Unit_157_Unit;
}

static  enum Unit_157   lam813 (   struct env813 env ,    int32_t  dref2731 ) {
    (* env.should_dash_resize2724 ) = ( false );
    return ( Unit_157_Unit );
}

static  struct Tui_363   mk812 (   struct env812 env ) {
    struct Termios_111  og_dash_termios2726 = ( (  enable_dash_raw_dash_mode804 ) ( ) );
    ( (  hide_dash_cursor736 ) ( ) );
    ( (  reset_dash_colors748 ) ( ) );
    ( (  clear_dash_screen749 ) ( ) );
    ( (  enable_dash_mouse809 ) ( ) );
    ( (  flush_dash_stdout808 ) ( ) );
    enum ColorPalette_364  palette2727 = ( (  query_dash_palette743 ) ( ) );
    struct Tuple2_533  dims2728 = ( (  get_dash_dimensions739 ) ( ) );
    uint32_t  fps2729 = (  from_dash_integral4 ( 60 ) );
    struct timespec  last_dash_sync2730 = ( (  now802 ) ( ) );
    struct env813 envinst813 = {
        .should_dash_resize2724 = env.should_dash_resize2724 ,
    };
    ( _intr_register_signal ( (  from_dash_integral3 ( 28 ) ) , ( (struct funenv813){ .fun = lam813, .env = envinst813 } ) ) );
    return ( (struct Tui_363) { .f_width = ( (  fst532 ) ( (  dims2728 ) ) ) , .f_height = ( (  snd535 ) ( (  dims2728 ) ) ) , .f_target_dash_fps = (  fps2729 ) , .f_actual_dash_fps = (  from_dash_integral4 ( 0 ) ) , .f_last_dash_sync = (  last_dash_sync2730 ) , .f_fps_dash_ts = (  last_dash_sync2730 ) , .f_fps_dash_count = (  from_dash_integral4 ( 0 ) ) , .f_orig_dash_termios = (  og_dash_termios2726 ) , .f_palette = (  palette2727 ) , .f_should_dash_redraw = ( true ) } );
}

static  enum Unit_157   sync818 (    struct Tui_363 *  tui2734 ) {
    if ( (  eq10 ( ( ( * (  tui2734 ) ) .f_target_dash_fps ) , (  from_dash_integral4 ( 0 ) ) ) ) ) {
        return ( Unit_157_Unit );
    }
    int64_t  frame_dash_ns2735 = (  op_dash_div46 ( (  from_dash_integral2 ( 1000000000 ) ) , ( (  size_dash_i64253 ) ( ( (  u32_dash_size263 ) ( ( ( * (  tui2734 ) ) .f_target_dash_fps ) ) ) ) ) ) );
    struct timespec  temp819 = ( (  undefined108 ) ( ) );
    struct timespec *  now2736 = ( &temp819 );
    ( ( clock_gettime ) ( ( (  clock_dash_monotonic73 ) ( ) ) ,  (  now2736 ) ) );
    int64_t  elapsed_dash_ns2737 = (  op_dash_add43 ( (  op_dash_mul45 ( (  op_dash_sub44 ( ( ( * (  now2736 ) ) .tv_sec ) , ( ( ( * (  tui2734 ) ) .f_last_dash_sync ) .tv_sec ) ) ) , (  from_dash_integral2 ( 1000000000 ) ) ) ) , (  op_dash_sub44 ( ( ( * (  now2736 ) ) .tv_nsec ) , ( ( ( * (  tui2734 ) ) .f_last_dash_sync ) .tv_nsec ) ) ) ) );
    int64_t  sleep_dash_ns2738 = (  op_dash_sub44 ( (  frame_dash_ns2735 ) , (  elapsed_dash_ns2737 ) ) );
    if ( (  cmp37 ( (  sleep_dash_ns2738 ) , (  from_dash_integral2 ( 0 ) ) ) == 2 ) ) {
        struct timespec  temp820 = ( (struct timespec) { .tv_sec = (  from_dash_integral2 ( 0 ) ) , .tv_nsec = (  sleep_dash_ns2738 ) } );
        struct timespec *  ts2739 = ( &temp820 );
        ( ( nanosleep ) ( (  ts2739 ) ,  ( (  null_dash_ptr247 ) ( ) ) ) );
    }
    struct timespec  temp821 = ( (  undefined108 ) ( ) );
    struct timespec *  last_dash_sync2740 = ( &temp821 );
    ( ( clock_gettime ) ( ( (  clock_dash_monotonic73 ) ( ) ) ,  (  last_dash_sync2740 ) ) );
    (*  tui2734 ) .f_last_dash_sync = ( * (  last_dash_sync2740 ) );
    (*  tui2734 ) .f_fps_dash_count = (  op_dash_add52 ( ( ( * (  tui2734 ) ) .f_fps_dash_count ) , (  from_dash_integral4 ( 1 ) ) ) );
    int64_t  fps_dash_elapsed_dash_ms2741 = (  op_dash_add43 ( (  op_dash_mul45 ( (  op_dash_sub44 ( ( ( ( * (  tui2734 ) ) .f_last_dash_sync ) .tv_sec ) , ( ( ( * (  tui2734 ) ) .f_fps_dash_ts ) .tv_sec ) ) ) , (  from_dash_integral2 ( 1000 ) ) ) ) , (  op_dash_div46 ( (  op_dash_sub44 ( ( ( ( * (  tui2734 ) ) .f_last_dash_sync ) .tv_nsec ) , ( ( ( * (  tui2734 ) ) .f_fps_dash_ts ) .tv_nsec ) ) ) , (  from_dash_integral2 ( 1000000 ) ) ) ) ) );
    if ( (  cmp37 ( (  fps_dash_elapsed_dash_ms2741 ) , (  from_dash_integral2 ( 1000 ) ) ) != 0 ) ) {
        (*  tui2734 ) .f_actual_dash_fps = ( ( * (  tui2734 ) ) .f_fps_dash_count );
        (*  tui2734 ) .f_fps_dash_count = (  from_dash_integral4 ( 0 ) );
        (*  tui2734 ) .f_fps_dash_ts = ( ( * (  tui2734 ) ) .f_last_dash_sync );
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   deinit822 (    struct Tui_363 *  tui2744 ) {
    ( (  disable_dash_mouse810 ) ( ) );
    ( (  show_dash_cursor735 ) ( ) );
    ( (  reset_dash_colors748 ) ( ) );
    ( (  clear_dash_screen749 ) ( ) );
    ( (  reset_dash_cursor_dash_position738 ) ( ) );
    ( (  disable_dash_raw_dash_mode806 ) ( ( & ( ( * (  tui2744 ) ) .f_orig_dash_termios ) ) ) );
    ( (  flush_dash_stdout808 ) ( ) );
    return ( Unit_157_Unit );
}

static  bool   eq823 (    enum MouseButton_119  l2748 ,    enum MouseButton_119  r2750 ) {
    return (  eq10 ( ( (  cast_dash_on_dash_zeroed240 ) ( (  l2748 ) ) ) , ( ( (  cast_dash_on_dash_zeroed240 ) ( (  r2750 ) ) ) ) ) );
}

static  enum MouseButton_119   btn_dash_to_dash_mouse_dash_button824 (    int64_t  btn2756 ) {
    return ( {  int32_t  dref2757 = ( (  i64_dash_i32257 ) ( (  btn2756 ) ) ) ;  dref2757 == 0 ? ( MouseButton_119_MouseLeft ) :  dref2757 == 1 ? ( MouseButton_119_MouseMiddle ) :  dref2757 == 2 ? ( MouseButton_119_MouseRight ) :  dref2757 == 64 ? ( MouseButton_119_ScrollUp ) :  dref2757 == 65 ? ( MouseButton_119_ScrollDown ) : ( (  panic_prime_645 ) ( ( ( StrConcat_602_StrConcat ) ( ( "incorrect mouse button code: " ) ,  (  btn2756 ) ) ) ) ) ; } );
}

struct Maybe_826 {
    enum {
        Maybe_826_None_t,
        Maybe_826_Just_t,
    } tag;
    union {
        struct {
            struct Key_367  field0;
        } Maybe_826_Just_s;
    } stuff;
};

static struct Maybe_826 Maybe_826_Just (  struct Key_367  field0 ) {
    return ( struct Maybe_826 ) { .tag = Maybe_826_Just_t, .stuff = { .Maybe_826_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_826   parse_dash_ss3825 (    char  c2760 ) {
    if ( (  eq14 ( (  c2760 ) , ( (  from_dash_charlike1 ) ( ( "A" ) ) ) ) ) ) {
        return ( ( Maybe_826_Just ) ( ( (struct Key_367) { .tag = Key_367_Up_t } ) ) );
    }
    if ( (  eq14 ( (  c2760 ) , ( (  from_dash_charlike1 ) ( ( "B" ) ) ) ) ) ) {
        return ( ( Maybe_826_Just ) ( ( (struct Key_367) { .tag = Key_367_Down_t } ) ) );
    }
    if ( (  eq14 ( (  c2760 ) , ( (  from_dash_charlike1 ) ( ( "C" ) ) ) ) ) ) {
        return ( ( Maybe_826_Just ) ( ( (struct Key_367) { .tag = Key_367_Right_t } ) ) );
    }
    if ( (  eq14 ( (  c2760 ) , ( (  from_dash_charlike1 ) ( ( "D" ) ) ) ) ) ) {
        return ( ( Maybe_826_Just ) ( ( (struct Key_367) { .tag = Key_367_Left_t } ) ) );
    }
    if ( (  eq14 ( (  c2760 ) , ( (  from_dash_charlike1 ) ( ( "H" ) ) ) ) ) ) {
        return ( ( Maybe_826_Just ) ( ( (struct Key_367) { .tag = Key_367_Home_t } ) ) );
    }
    if ( (  eq14 ( (  c2760 ) , ( (  from_dash_charlike1 ) ( ( "F" ) ) ) ) ) ) {
        return ( ( Maybe_826_Just ) ( ( (struct Key_367) { .tag = Key_367_End_t } ) ) );
    }
    if ( (  eq14 ( (  c2760 ) , ( (  from_dash_charlike1 ) ( ( "P" ) ) ) ) ) ) {
        return ( ( Maybe_826_Just ) ( ( (struct Key_367) { .tag = Key_367_F1_t } ) ) );
    }
    if ( (  eq14 ( (  c2760 ) , ( (  from_dash_charlike1 ) ( ( "Q" ) ) ) ) ) ) {
        return ( ( Maybe_826_Just ) ( ( (struct Key_367) { .tag = Key_367_F2_t } ) ) );
    }
    if ( (  eq14 ( (  c2760 ) , ( (  from_dash_charlike1 ) ( ( "R" ) ) ) ) ) ) {
        return ( ( Maybe_826_Just ) ( ( (struct Key_367) { .tag = Key_367_F3_t } ) ) );
    }
    if ( (  eq14 ( (  c2760 ) , ( (  from_dash_charlike1 ) ( ( "S" ) ) ) ) ) ) {
        return ( ( Maybe_826_Just ) ( ( (struct Key_367) { .tag = Key_367_F4_t } ) ) );
    }
    return ( (struct Maybe_826) { .tag = Maybe_826_None_t } );
}

static  struct Maybe_365   parse_dash_csi827 (    struct DynStr_417  seq2763 ) {
    if ( (  eq13 ( ( ( (  seq2763 ) .f_contents ) .f_count ) , (  from_dash_integral8 ( 0 ) ) ) ) ) {
        return ( (struct Maybe_365) { .tag = Maybe_365_None_t } );
    }
    char  last2764 = (  elem_dash_get686 ( ( (  seq2763 ) .f_contents ) , (  op_dash_sub59 ( ( ( (  seq2763 ) .f_contents ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) ) );
    if ( ( (  eq14 ( (  elem_dash_get686 ( ( (  seq2763 ) .f_contents ) , (  from_dash_integral8 ( 0 ) ) ) ) , ( (  from_dash_charlike1 ) ( ( "<" ) ) ) ) ) && ( (  eq14 ( (  last2764 ) , ( (  from_dash_charlike1 ) ( ( "M" ) ) ) ) ) || (  eq14 ( (  last2764 ) , ( (  from_dash_charlike1 ) ( ( "m" ) ) ) ) ) ) ) ) {
        struct Scanner_268  temp828 = ( (  mk800 ) ( ( (  substr709 ) ( (  seq2763 ) ,  (  from_dash_integral8 ( 1 ) ) ,  ( ( (  seq2763 ) .f_contents ) .f_count ) ) ) ) );
        struct Scanner_268 *  sc2765 = ( &temp828 );
        struct Maybe_446  dref2766 = ( (  scan_dash_int801 ) ( (  sc2765 ) ) );
        if ( dref2766.tag == Maybe_446_None_t ) {
            return ( (struct Maybe_365) { .tag = Maybe_365_None_t } );
        }
        else {
            if ( dref2766.tag == Maybe_446_Just_t ) {
                ( (  next351 ) ( (  sc2765 ) ) );
                struct Maybe_446  dref2768 = ( (  scan_dash_int801 ) ( (  sc2765 ) ) );
                if ( dref2768.tag == Maybe_446_None_t ) {
                    return ( (struct Maybe_365) { .tag = Maybe_365_None_t } );
                }
                else {
                    if ( dref2768.tag == Maybe_446_Just_t ) {
                        ( (  next351 ) ( (  sc2765 ) ) );
                        struct Maybe_446  dref2770 = ( (  scan_dash_int801 ) ( (  sc2765 ) ) );
                        if ( dref2770.tag == Maybe_446_None_t ) {
                            return ( (struct Maybe_365) { .tag = Maybe_365_None_t } );
                        }
                        else {
                            if ( dref2770.tag == Maybe_446_Just_t ) {
                                return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Mouse ) ( ( (struct MouseEvent_368) { .f_button = ( (  btn_dash_to_dash_mouse_dash_button824 ) ( ( dref2766 .stuff .Maybe_446_Just_s .field0 ) ) ) , .f_x = (  op_dash_sub48 ( ( (  i64_dash_i32257 ) ( ( dref2768 .stuff .Maybe_446_Just_s .field0 ) ) ) , (  from_dash_integral3 ( 1 ) ) ) ) , .f_y = (  op_dash_sub48 ( ( (  i64_dash_i32257 ) ( ( dref2770 .stuff .Maybe_446_Just_s .field0 ) ) ) , (  from_dash_integral3 ( 1 ) ) ) ) , .f_pressed = (  eq14 ( (  last2764 ) , ( (  from_dash_charlike1 ) ( ( "M" ) ) ) ) ) } ) ) ) ) );
                            }
                        }
                    }
                }
            }
        }
    }
    if ( (  eq13 ( ( ( (  seq2763 ) .f_contents ) .f_count ) , (  from_dash_integral8 ( 1 ) ) ) ) ) {
        if ( (  eq14 ( (  last2764 ) , ( (  from_dash_charlike1 ) ( ( "A" ) ) ) ) ) ) {
            return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_Up_t } ) ) ) ) );
        }
        if ( (  eq14 ( (  last2764 ) , ( (  from_dash_charlike1 ) ( ( "B" ) ) ) ) ) ) {
            return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_Down_t } ) ) ) ) );
        }
        if ( (  eq14 ( (  last2764 ) , ( (  from_dash_charlike1 ) ( ( "C" ) ) ) ) ) ) {
            return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_Right_t } ) ) ) ) );
        }
        if ( (  eq14 ( (  last2764 ) , ( (  from_dash_charlike1 ) ( ( "D" ) ) ) ) ) ) {
            return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_Left_t } ) ) ) ) );
        }
        if ( (  eq14 ( (  last2764 ) , ( (  from_dash_charlike1 ) ( ( "H" ) ) ) ) ) ) {
            return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_Home_t } ) ) ) ) );
        }
        if ( (  eq14 ( (  last2764 ) , ( (  from_dash_charlike1 ) ( ( "F" ) ) ) ) ) ) {
            return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_End_t } ) ) ) ) );
        }
        return ( (struct Maybe_365) { .tag = Maybe_365_None_t } );
    }
    if ( (  eq14 ( (  last2764 ) , ( (  from_dash_charlike1 ) ( ( "~" ) ) ) ) ) ) {
        struct Scanner_268  temp829 = ( (  mk800 ) ( (  seq2763 ) ) );
        struct Scanner_268 *  sc2772 = ( &temp829 );
        struct Maybe_446  dref2773 = ( (  scan_dash_int801 ) ( (  sc2772 ) ) );
        if ( dref2773.tag == Maybe_446_None_t ) {
            return ( (struct Maybe_365) { .tag = Maybe_365_None_t } );
        }
        else {
            if ( dref2773.tag == Maybe_446_Just_t ) {
                return ( {  int32_t  dref2775 = ( (  i64_dash_i32257 ) ( ( dref2773 .stuff .Maybe_446_Just_s .field0 ) ) ) ;  dref2775 == 1 ? ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_Home_t } ) ) ) ) ) :  dref2775 == 2 ? ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_Insert_t } ) ) ) ) ) :  dref2775 == 3 ? ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_Delete_t } ) ) ) ) ) :  dref2775 == 4 ? ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_End_t } ) ) ) ) ) :  dref2775 == 5 ? ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_PageUp_t } ) ) ) ) ) :  dref2775 == 6 ? ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_PageDown_t } ) ) ) ) ) :  dref2775 == 15 ? ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_F5_t } ) ) ) ) ) :  dref2775 == 17 ? ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_F6_t } ) ) ) ) ) :  dref2775 == 18 ? ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_F7_t } ) ) ) ) ) :  dref2775 == 19 ? ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_F8_t } ) ) ) ) ) :  dref2775 == 20 ? ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_F9_t } ) ) ) ) ) :  dref2775 == 21 ? ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_F10_t } ) ) ) ) ) :  dref2775 == 23 ? ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_F11_t } ) ) ) ) ) :  dref2775 == 24 ? ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_F12_t } ) ) ) ) ) : ( (struct Maybe_365) { .tag = Maybe_365_None_t } ) ; } );
            }
        }
    }
    return ( (struct Maybe_365) { .tag = Maybe_365_None_t } );
}

static  struct Maybe_365   read_dash_key830 (  ) {
    char  temp831 = ( (  undefined100 ) ( ) );
    char *  ch2777 = ( &temp831 );
    struct Maybe_276  dref2778 = ( (  read_dash_byte807 ) ( (  from_dash_integral3 ( 0 ) ) ) );
    if ( dref2778.tag == Maybe_276_None_t ) {
        return ( (struct Maybe_365) { .tag = Maybe_365_None_t } );
    }
    else {
        if ( dref2778.tag == Maybe_276_Just_t ) {
            (*  ch2777 ) = ( dref2778 .stuff .Maybe_276_Just_s .field0 );
        }
    }
    if ( (  eq11 ( ( (  char_dash_u8636 ) ( ( * (  ch2777 ) ) ) ) , (  from_dash_integral6 ( 13 ) ) ) ) ) {
        return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_Enter_t } ) ) ) ) );
    }
    if ( (  eq11 ( ( (  char_dash_u8636 ) ( ( * (  ch2777 ) ) ) ) , (  from_dash_integral6 ( 127 ) ) ) ) ) {
        return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_Backspace_t } ) ) ) ) );
    }
    if ( ( (  cmp42 ( ( (  char_dash_u8636 ) ( ( * (  ch2777 ) ) ) ) , (  from_dash_integral6 ( 27 ) ) ) == 0 ) && ( !  eq11 ( ( (  char_dash_u8636 ) ( ( * (  ch2777 ) ) ) ) , (  from_dash_integral6 ( 9 ) ) ) ) ) ) {
        char  letter2780 = ( (  i32_dash_char637 ) ( ( (  u32_dash_i32264 ) ( ( (  u32_dash_or784 ) ( ( (  i32_dash_u32254 ) ( ( (  char_dash_i32635 ) ( ( * (  ch2777 ) ) ) ) ) ) ,  ( (  from_dash_hex731 ) ( ( "60" ) ) ) ) ) ) ) ) );
        return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( ( Key_367_Ctrl ) ( (  letter2780 ) ) ) ) ) ) );
    }
    if ( ( !  eq11 ( ( (  char_dash_u8636 ) ( ( * (  ch2777 ) ) ) ) , (  from_dash_integral6 ( 27 ) ) ) ) ) {
        if ( (  cmp42 ( ( (  char_dash_u8636 ) ( ( * (  ch2777 ) ) ) ) , (  from_dash_integral6 ( 127 ) ) ) == 2 ) ) {
            return ( (  read_dash_key830 ) ( ) );
        } else {
            return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( ( Key_367_Char ) ( ( * (  ch2777 ) ) ) ) ) ) ) );
        }
    }
    char  temp832 = ( (  undefined100 ) ( ) );
    char *  ch22781 = ( &temp832 );
    struct Maybe_276  dref2782 = ( (  read_dash_byte807 ) ( (  from_dash_integral3 ( 50 ) ) ) );
    if ( dref2782.tag == Maybe_276_None_t ) {
        return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_Escape_t } ) ) ) ) );
    }
    else {
        if ( dref2782.tag == Maybe_276_Just_t ) {
            (*  ch22781 ) = ( dref2782 .stuff .Maybe_276_Just_s .field0 );
        }
    }
    if ( (  eq14 ( ( * (  ch22781 ) ) , ( (  from_dash_charlike1 ) ( ( "[" ) ) ) ) ) ) {
        struct Array_167  temp833 = ( ( (  zeroed228 ) ( ) ) );
        struct Array_167 *  seq2784 = ( &temp833 );
        int32_t  slen2785 = (  from_dash_integral3 ( 0 ) );
        while ( (  cmp40 ( (  slen2785 ) , (  from_dash_integral3 ( 31 ) ) ) == 0 ) ) {
            char  temp834 = ( (  undefined100 ) ( ) );
            char *  sc2786 = ( &temp834 );
            struct Maybe_276  dref2787 = ( (  read_dash_byte807 ) ( (  from_dash_integral3 ( 50 ) ) ) );
            if ( dref2787.tag == Maybe_276_None_t ) {
                break;
            }
            else {
                if ( dref2787.tag == Maybe_276_Just_t ) {
                    (*  sc2786 ) = ( dref2787 .stuff .Maybe_276_Just_s .field0 );
                }
            }
            ( (  set713 ) ( (  seq2784 ) ,  ( (  i32_dash_size256 ) ( (  slen2785 ) ) ) ,  ( * (  sc2786 ) ) ) );
            slen2785 = (  op_dash_add47 ( (  slen2785 ) , (  from_dash_integral3 ( 1 ) ) ) );
            if ( ( (  cmp42 ( ( (  char_dash_u8636 ) ( ( * (  sc2786 ) ) ) ) , (  from_dash_integral6 ( 64 ) ) ) != 0 ) && (  cmp42 ( ( (  char_dash_u8636 ) ( ( * (  sc2786 ) ) ) ) , (  from_dash_integral6 ( 126 ) ) ) != 2 ) ) ) {
                break;
            }
        }
        return ( (  parse_dash_csi827 ) ( ( (struct DynStr_417) { .f_contents = ( (  subslice677 ) ( ( (  as_dash_slice714 ) ( (  seq2784 ) ) ) ,  (  from_dash_integral8 ( 0 ) ) ,  ( (  i32_dash_size256 ) ( (  slen2785 ) ) ) ) ) } ) ) );
    }
    if ( (  eq14 ( ( * (  ch22781 ) ) , ( (  from_dash_charlike1 ) ( ( "O" ) ) ) ) ) ) {
        char  temp835 = ( (  undefined100 ) ( ) );
        char *  sc2789 = ( &temp835 );
        struct Maybe_276  dref2790 = ( (  read_dash_byte807 ) ( (  from_dash_integral3 ( 50 ) ) ) );
        if ( dref2790.tag == Maybe_276_None_t ) {
            return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_Escape_t } ) ) ) ) );
        }
        else {
            if ( dref2790.tag == Maybe_276_Just_t ) {
                (*  sc2789 ) = ( dref2790 .stuff .Maybe_276_Just_s .field0 );
            }
        }
        struct Maybe_826  dref2792 = ( (  parse_dash_ss3825 ) ( ( * (  sc2789 ) ) ) );
        if ( dref2792.tag == Maybe_826_None_t ) {
            return ( (struct Maybe_365) { .tag = Maybe_365_None_t } );
        }
        else {
            if ( dref2792.tag == Maybe_826_Just_t ) {
                return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( dref2792 .stuff .Maybe_826_Just_s .field0 ) ) ) ) );
            }
        }
    }
    return ( ( Maybe_365_Just ) ( ( ( InputEvent_366_Key ) ( ( (struct Key_367) { .tag = Key_367_Escape_t } ) ) ) ) );
}

static  bool   update_dash_dimensions362 (   struct env362 env ,    struct Tui_363 *  tui2796 ) {
    if ( ( ! ( * ( env.should_dash_resize2724 ) ) ) ) {
        return ( false );
    }
    (* env.should_dash_resize2724 ) = ( false );
    struct Tuple2_533  dim2797 = ( (  get_dash_dimensions739 ) ( ) );
    uint32_t  w2798 = ( (  fst532 ) ( (  dim2797 ) ) );
    uint32_t  h2799 = ( (  snd535 ) ( (  dim2797 ) ) );
    (*  tui2796 ) .f_width = (  w2798 );
    (*  tui2796 ) .f_height = (  h2799 );
    return ( true );
}

static  struct Maybe_365   read_dash_event361 (   struct env361 env ,    struct Tui_363 *  tui2802 ) {
    struct funenv362  temp836 = ( (struct funenv362){ .fun = update_dash_dimensions362, .env =  env.envinst362  } );
    if ( ( temp836.fun ( temp836.env ,  (  tui2802 ) ) ) ) {
        (*  tui2802 ) .f_should_dash_redraw = ( true );
    }
    struct Maybe_365  dref2803 = ( (  read_dash_key830 ) ( ) );
    if ( dref2803.tag == Maybe_365_None_t ) {
        return ( (struct Maybe_365) { .tag = Maybe_365_None_t } );
    }
    else {
        if ( dref2803.tag == Maybe_365_Just_t ) {
            (*  tui2802 ) .f_should_dash_redraw = ( true );
            return ( ( Maybe_365_Just ) ( ( dref2803 .stuff .Maybe_365_Just_s .field0 ) ) );
        }
    }
}

static  bool   should_dash_redraw837 (    struct Tui_363 *  tui2807 ) {
    bool  redraw2808 = ( ( * (  tui2807 ) ) .f_should_dash_redraw );
    (*  tui2807 ) .f_should_dash_redraw = ( false );
    return (  redraw2808 );
}

static  struct Cell_16   lam839 (    struct Cell_16  dref2826 ) {
    return ( (struct Cell_16) { .f_c = ( (  from_dash_charlike1 ) ( ( " " ) ) ) , .f_fg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) , .f_bg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) } );
}

static  struct Cell_16   lam840 (    struct Cell_16  dref2828 ) {
    return ( (struct Cell_16) { .f_c = ( (  from_dash_charlike1 ) ( ( " " ) ) ) , .f_fg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) , .f_bg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) } );
}

static  struct Screen_438   mk_dash_screen838 (    struct Tui_363 *  tui2822 ,    enum CAllocator_383  al2824 ) {
    struct Slice_399  cur2825 = ( (  allocate698 ) ( (  al2824 ) ,  ( (  u32_dash_size263 ) ( (  op_dash_mul54 ( ( ( * (  tui2822 ) ) .f_width ) , ( ( * (  tui2822 ) ) .f_height ) ) ) ) ) ) );
    ( (  map691 ) ( (  cur2825 ) ,  (  lam839 ) ) );
    struct Slice_399  prev2827 = ( (  allocate698 ) ( (  al2824 ) ,  ( (  u32_dash_size263 ) ( (  op_dash_mul54 ( ( ( * (  tui2822 ) ) .f_width ) , ( ( * (  tui2822 ) ) .f_height ) ) ) ) ) ) );
    ( (  map692 ) ( (  prev2827 ) ,  (  lam840 ) ) );
    return ( (struct Screen_438) { .f_current = (  cur2825 ) , .f_previous = (  prev2827 ) , .f_al = (  al2824 ) , .f_tui = (  tui2822 ) , .f_requires_dash_full_dash_redraw = ( false ) , .f_default_dash_fg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) , .f_default_dash_bg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) } );
}

static  enum Unit_157   free_dash_screen841 (    struct Screen_438 *  screen2831 ) {
    enum CAllocator_383  al2832 = ( ( * (  screen2831 ) ) .f_al );
    ( (  free702 ) ( (  al2832 ) ,  ( ( * (  screen2831 ) ) .f_current ) ) );
    ( (  free702 ) ( (  al2832 ) ,  ( ( * (  screen2831 ) ) .f_previous ) ) );
    return ( Unit_157_Unit );
}

static  struct Cell_16   lam843 (    struct Cell_16  dref2836 ) {
    return ( (struct Cell_16) { .f_c = ( (  from_dash_charlike1 ) ( ( " " ) ) ) , .f_fg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) , .f_bg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) } );
}

static  enum Unit_157   clear_dash_screen842 (    struct Screen_438 *  screen2835 ) {
    ( (  map693 ) ( ( ( * (  screen2835 ) ) .f_current ) ,  (  lam843 ) ) );
    return ( Unit_157_Unit );
}

struct RenderState_845 {
    uint32_t  f_x;
    uint32_t  f_y;
    struct Color_17  f_fg;
    struct Color_17  f_bg;
    uint32_t  f_changes;
};

static  enum Unit_157   emit_dash_cell844 (    struct RenderState_845 *  rs2840 ,    struct Cell_16 *  c2842 ,    uint32_t  x2844 ,    uint32_t  y2846 ) {
    if ( ( ( !  eq10 ( (  x2844 ) , ( ( * (  rs2840 ) ) .f_x ) ) ) || ( !  eq10 ( (  y2846 ) , ( ( * (  rs2840 ) ) .f_y ) ) ) ) ) {
        ( (  move_dash_cursor_dash_to737 ) ( (  x2844 ) ,  (  y2846 ) ) );
        (*  rs2840 ) .f_x = (  x2844 );
        (*  rs2840 ) .f_y = (  y2846 );
    }
    char  char2847 = ( ( * (  c2842 ) ) .f_c );
    struct Color_17  bg2848 = ( ( * (  c2842 ) ) .f_bg );
    if ( ( ( (  eq14 ( (  char2847 ) , ( (  from_dash_charlike1 ) ( ( "\t" ) ) ) ) ) || (  eq14 ( (  char2847 ) , ( (  from_dash_charlike1 ) ( ( "\r" ) ) ) ) ) ) || (  eq14 ( (  char2847 ) , ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) ) {
        char2847 = ( (  from_dash_charlike1 ) ( ( " " ) ) );
        bg2848 = ( ( Color_17_Color8 ) ( ( Color8_18_Red8 ) ) );
    }
    if ( ( !  eq22 ( ( ( * (  rs2840 ) ) .f_fg ) , ( ( * (  c2842 ) ) .f_fg ) ) ) ) {
        ( (  set_dash_fg754 ) ( ( ( * (  c2842 ) ) .f_fg ) ) );
        (*  rs2840 ) .f_fg = ( ( * (  c2842 ) ) .f_fg );
    }
    if ( ( !  eq22 ( ( ( * (  rs2840 ) ) .f_bg ) , (  bg2848 ) ) ) ) {
        ( (  set_dash_bg755 ) ( (  bg2848 ) ) );
        (*  rs2840 ) .f_bg = (  bg2848 );
    }
    ( (  print_dash_str472 ) ( (  char2847 ) ) );
    (*  rs2840 ) .f_x = (  op_dash_add52 ( ( ( * (  rs2840 ) ) .f_x ) , (  from_dash_integral4 ( 1 ) ) ) );
    return ( Unit_157_Unit );
}

static  uint32_t   render_dash_screen846 (    struct Screen_438 *  screen2851 ) {
    int32_t  w2852 = ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2851 ) ) .f_tui ) ) .f_width ) ) );
    int32_t  h2853 = ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2851 ) ) .f_tui ) ) .f_height ) ) );
    struct RenderState_845  temp847 = ( (struct RenderState_845) { .f_x = (  from_dash_integral4 ( 0 ) ) , .f_y = (  from_dash_integral4 ( 0 ) ) , .f_fg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) , .f_bg = ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) , .f_changes = (  from_dash_integral4 ( 0 ) ) } );
    struct RenderState_845 *  rs2854 = ( &temp847 );
    ( (  move_dash_cursor_dash_to737 ) ( (  from_dash_integral4 ( 0 ) ) ,  (  from_dash_integral4 ( 0 ) ) ) );
    struct RangeIter_288  temp848 =  into_dash_iter287 ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  op_dash_sub48 ( (  h2853 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_290  __cond849 =  next289 (&temp848);
        if (  __cond849 .tag == 0 ) {
            break;
        }
        int32_t  y2856 =  __cond849 .stuff .Maybe_290_Just_s .field0;
        struct RangeIter_288  temp850 =  into_dash_iter287 ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  op_dash_sub48 ( (  w2852 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
        while (true) {
            struct Maybe_290  __cond851 =  next289 (&temp850);
            if (  __cond851 .tag == 0 ) {
                break;
            }
            int32_t  x2858 =  __cond851 .stuff .Maybe_290_Just_s .field0;
            size_t  i2859 = ( (  i32_dash_size256 ) ( (  op_dash_add47 ( (  op_dash_mul49 ( (  y2856 ) , (  w2852 ) ) ) , (  x2858 ) ) ) ) );
            struct Cell_16 *  cur2860 = ( (  get_dash_ptr663 ) ( ( ( * (  screen2851 ) ) .f_current ) ,  (  i2859 ) ) );
            struct Cell_16 *  prev2861 = ( (  get_dash_ptr663 ) ( ( ( * (  screen2851 ) ) .f_previous ) ,  (  i2859 ) ) );
            if ( ( ( !  eq15 ( (  cur2860 ) , (  prev2861 ) ) ) || ( ( * (  screen2851 ) ) .f_requires_dash_full_dash_redraw ) ) ) {
                (*  rs2854 ) .f_changes = (  op_dash_add52 ( ( ( * (  rs2854 ) ) .f_changes ) , (  from_dash_integral4 ( 1 ) ) ) );
                ( (  emit_dash_cell844 ) ( (  rs2854 ) ,  (  cur2860 ) ,  ( (  i32_dash_u32254 ) ( (  x2858 ) ) ) ,  ( (  i32_dash_u32254 ) ( (  y2856 ) ) ) ) );
                (*  prev2861 ) = ( * (  cur2860 ) );
            }
        }
    }
    (*  screen2851 ) .f_requires_dash_full_dash_redraw = ( false );
    ( (  reset_dash_colors748 ) ( ) );
    ( (  flush_dash_stdout808 ) ( ) );
    return ( ( * (  rs2854 ) ) .f_changes );
}

struct env852 {
    struct env362 envinst362;
    ;
    ;
    ;
    ;
    ;
};

static  bool   resize_dash_screen_dash_if_dash_needed852 (   struct env852 env ,    struct Screen_438 *  screen2864 ) {
    struct Tui_363 *  tui2865 = ( ( * (  screen2864 ) ) .f_tui );
    struct funenv362  temp853 = ( (struct funenv362){ .fun = update_dash_dimensions362, .env =  env.envinst362  } );
    if ( ( ! ( temp853.fun ( temp853.env ,  (  tui2865 ) ) ) ) ) {
        return ( false );
    }
    (*  screen2864 ) .f_requires_dash_full_dash_redraw = ( true );
    uint32_t  w2866 = ( ( * ( ( * (  screen2864 ) ) .f_tui ) ) .f_width );
    uint32_t  h2867 = ( ( * ( ( * (  screen2864 ) ) .f_tui ) ) .f_height );
    size_t  nusz2868 = ( (  u32_dash_size263 ) ( (  op_dash_mul54 ( (  w2866 ) , (  h2867 ) ) ) ) );
    if ( (  cmp39 ( (  nusz2868 ) , ( ( ( * (  screen2864 ) ) .f_current ) .f_count ) ) != 2 ) ) {
        return ( true );
    }
    struct Screen_438  nuscreen2869 = ( (  mk_dash_screen838 ) ( (  tui2865 ) ,  ( ( * (  screen2864 ) ) .f_al ) ) );
    (*  screen2864 ) .f_current = ( (  nuscreen2869 ) .f_current );
    (*  screen2864 ) .f_previous = ( (  nuscreen2869 ) .f_previous );
    return ( true );
}

static  enum Unit_157   set_dash_screen_dash_fg854 (    struct Screen_438 *  screen2872 ,    struct Color_17  c2874 ) {
    (*  screen2872 ) .f_default_dash_fg = (  c2874 );
    return ( Unit_157_Unit );
}

static  enum Unit_157   set_dash_screen_dash_bg855 (    struct Screen_438 *  screen2877 ,    struct Color_17  c2879 ) {
    (*  screen2877 ) .f_default_dash_bg = (  c2879 );
    return ( Unit_157_Unit );
}

static  enum Unit_157   set_dash_screen_dash_colors856 (    struct Screen_438 *  screen2882 ,    struct Color_17  fg2884 ,    struct Color_17  bg2886 ) {
    (*  screen2882 ) .f_default_dash_fg = (  fg2884 );
    (*  screen2882 ) .f_default_dash_bg = (  bg2886 );
    return ( Unit_157_Unit );
}

static  struct Maybe_655   get_dash_cell_dash_ptr857 (    struct Screen_438 *  screen2893 ,    int32_t  x2895 ,    int32_t  y2897 ) {
    int32_t  w2898 = ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2893 ) ) .f_tui ) ) .f_width ) ) );
    if ( ( (  cmp40 ( (  x2895 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) || (  cmp40 ( (  x2895 ) , (  w2898 ) ) != 0 ) ) ) {
        return ( (struct Maybe_655) { .tag = Maybe_655_None_t } );
    }
    if ( ( (  cmp40 ( (  y2897 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) || (  cmp40 ( (  y2897 ) , ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2893 ) ) .f_tui ) ) .f_height ) ) ) ) != 0 ) ) ) {
        return ( (struct Maybe_655) { .tag = Maybe_655_None_t } );
    }
    size_t  i2899 = ( (  i32_dash_size256 ) ( (  op_dash_add47 ( (  op_dash_mul49 ( (  y2897 ) , (  w2898 ) ) ) , (  x2895 ) ) ) ) );
    return ( ( Maybe_655_Just ) ( ( (  get_dash_ptr663 ) ( ( ( * (  screen2893 ) ) .f_current ) ,  (  i2899 ) ) ) ) );
}

static  enum Unit_157   fill_dash_default858 (    struct Screen_438 *  screen2902 ) {
    struct RangeIter_288  temp859 =  into_dash_iter287 ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  op_dash_sub48 ( ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2902 ) ) .f_tui ) ) .f_height ) ) ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_290  __cond860 =  next289 (&temp859);
        if (  __cond860 .tag == 0 ) {
            break;
        }
        int32_t  y2904 =  __cond860 .stuff .Maybe_290_Just_s .field0;
        struct RangeIter_288  temp861 =  into_dash_iter287 ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  op_dash_sub48 ( ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2902 ) ) .f_tui ) ) .f_width ) ) ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
        while (true) {
            struct Maybe_290  __cond862 =  next289 (&temp861);
            if (  __cond862 .tag == 0 ) {
                break;
            }
            int32_t  x2906 =  __cond862 .stuff .Maybe_290_Just_s .field0;
            struct Cell_16 *  cell2907 = ( (  or_dash_fail654 ) ( ( (  get_dash_cell_dash_ptr857 ) ( (  screen2902 ) ,  (  x2906 ) ,  (  y2904 ) ) ) ,  ( "no cell??" ) ) );
            (*  cell2907 ) .f_bg = ( ( * (  screen2902 ) ) .f_default_dash_bg );
        }
    }
    return ( Unit_157_Unit );
}

static  enum Unit_157   put_dash_char863 (    struct Screen_438 *  screen2910 ,    char  c2912 ,    int32_t  x2914 ,    int32_t  y2916 ) {
    int32_t  w2917 = ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2910 ) ) .f_tui ) ) .f_width ) ) );
    if ( ( ( ( (  cmp40 ( (  x2914 ) , (  w2917 ) ) != 0 ) || (  cmp40 ( (  y2916 ) , ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2910 ) ) .f_tui ) ) .f_height ) ) ) ) != 0 ) ) || (  cmp40 ( (  x2914 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) ) || (  cmp40 ( (  y2916 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) ) ) {
        return ( Unit_157_Unit );
    }
    size_t  i2918 = ( (  i32_dash_size256 ) ( (  op_dash_add47 ( (  op_dash_mul49 ( (  y2916 ) , (  w2917 ) ) ) , (  x2914 ) ) ) ) );
    struct Color_17  fg2919 = ( ( * (  screen2910 ) ) .f_default_dash_fg );
    struct Color_17  bg2920 = ( ( * (  screen2910 ) ) .f_default_dash_bg );
    char  c2921 = (  c2912 );
    ( (  set674 ) ( ( ( * (  screen2910 ) ) .f_current ) ,  (  i2918 ) ,  ( (struct Cell_16) { .f_c = (  c2921 ) , .f_fg = (  fg2919 ) , .f_bg = (  bg2920 ) } ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   lam437 (   struct env437 env ,    struct Tuple2_312  dref2935 ) {
    ( (  put_dash_char863 ) ( ( env.screen2924 ) ,  ( dref2935 .field0 ) ,  (  op_dash_add47 ( ( env.x2933 ) , ( dref2935 .field1 ) ) ) ,  ( env.y2930 ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   draw_dash_str864 (    struct Screen_438 *  screen2924 ,    struct StrConcat_581  s2926 ,    int32_t  x2928 ,    int32_t  y2930 ) {
    int32_t  w2931 = ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2924 ) ) .f_tui ) ) .f_width ) ) );
    if ( ( (  cmp40 ( (  y2930 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) || (  cmp40 ( (  y2930 ) , ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2924 ) ) .f_tui ) ) .f_height ) ) ) ) != 0 ) ) ) {
        return ( Unit_157_Unit );
    }
    int32_t  i2932 = (  op_dash_add47 ( (  op_dash_mul49 ( (  y2930 ) , (  w2931 ) ) ) , (  x2928 ) ) );
    int32_t  x2933 = ( (  min555 ) ( (  x2928 ) ,  (  w2931 ) ) );
    size_t  max_dash_len2934 = ( (  i32_dash_size256 ) ( (  op_dash_sub48 ( (  w2931 ) , (  x2933 ) ) ) ) );
    struct env437 envinst437 = {
        .y2930 =  y2930 ,
        .screen2924 =  screen2924 ,
        .x2933 =  x2933 ,
    };
    ( (  for_dash_each436 ) ( ( (  zip335 ) ( ( (  chars632 ) ( (  s2926 ) ) ) ,  ( (  from291 ) ( (  from_dash_integral3 ( 0 ) ) ) ) ) ) ,  ( (struct funenv437){ .fun = lam437, .env = envinst437 } ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   lam442 (   struct env442 env ,    struct Tuple2_312  dref2935 ) {
    ( (  put_dash_char863 ) ( ( env.screen2924 ) ,  ( dref2935 .field0 ) ,  (  op_dash_add47 ( ( env.x2933 ) , ( dref2935 .field1 ) ) ) ,  ( env.y2930 ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   draw_dash_str865 (    struct Screen_438 *  screen2924 ,    const char*  s2926 ,    int32_t  x2928 ,    int32_t  y2930 ) {
    int32_t  w2931 = ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2924 ) ) .f_tui ) ) .f_width ) ) );
    if ( ( (  cmp40 ( (  y2930 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) || (  cmp40 ( (  y2930 ) , ( (  u32_dash_i32264 ) ( ( ( * ( ( * (  screen2924 ) ) .f_tui ) ) .f_height ) ) ) ) != 0 ) ) ) {
        return ( Unit_157_Unit );
    }
    int32_t  i2932 = (  op_dash_add47 ( (  op_dash_mul49 ( (  y2930 ) , (  w2931 ) ) ) , (  x2928 ) ) );
    int32_t  x2933 = ( (  min555 ) ( (  x2928 ) ,  (  w2931 ) ) );
    size_t  max_dash_len2934 = ( (  i32_dash_size256 ) ( (  op_dash_sub48 ( (  w2931 ) , (  x2933 ) ) ) ) );
    struct env442 envinst442 = {
        .y2930 =  y2930 ,
        .screen2924 =  screen2924 ,
        .x2933 =  x2933 ,
    };
    ( (  for_dash_each441 ) ( ( (  zip341 ) ( ( (  chars556 ) ( (  s2926 ) ) ) ,  ( (  from291 ) ( (  from_dash_integral3 ( 0 ) ) ) ) ) ) ,  ( (struct funenv442){ .fun = lam442, .env = envinst442 } ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   draw_dash_str_dash_center866 (    struct Screen_438 *  screen2952 ,    const char*  s2954 ,    int32_t  x2956 ,    int32_t  y2958 ) {
    int32_t  slen2959 = ( (  size_dash_i32260 ) ( ( (  count513 ) ( ( (  chars556 ) ( (  s2954 ) ) ) ) ) ) );
    int32_t  x2960 = (  op_dash_sub48 ( (  x2956 ) , (  op_dash_div50 ( (  slen2959 ) , (  from_dash_integral3 ( 2 ) ) ) ) ) );
    ( (  draw_dash_str865 ) ( (  screen2952 ) ,  (  s2954 ) ,  (  x2960 ) ,  (  y2958 ) ) );
    return ( Unit_157_Unit );
}

static  struct StrCase_569   xdg_dash_home867 (    const char*  name3023 ,    const char*  loc3025 ) {
    return ( {  struct Maybe_252  dref3026 = ( (  get734 ) ( (  name3023 ) ) ) ; dref3026.tag == Maybe_252_Just_t ? ( ( StrCase_569_StrCase1 ) ( ( dref3026 .stuff .Maybe_252_Just_s .field0 ) ) ) : ( ( StrCase_569_StrCase2 ) ( ( ( StrConcat_570_StrConcat ) ( ( (  or_dash_else657 ) ( ( (  get734 ) ( ( "HOME" ) ) ) ,  ( (  from_dash_charlike0 ) ( ( "~" ) ) ) ) ) ,  (  loc3025 ) ) ) ) ) ; } );
}

static  struct StrCase_569   data_dash_home868 (  ) {
    return ( (  xdg_dash_home867 ) ( ( "XDG_DATA_HOME" ) ,  ( "/.local/share" ) ) );
}

static  struct Slice_676   get869 (  ) {
    return ( (struct Slice_676) { .f_ptr = ( (  offset_dash_ptr127 ) ( ( _global_argv ) ,  (  from_dash_integral2 ( 1 ) ) ) ) , .f_count = (  op_dash_sub59 ( ( _global_argc ) , (  from_dash_integral8 ( 1 ) ) ) ) } );
}

enum GameState_871 {
    GameState_871_InProgress,
    GameState_871_Failed,
    GameState_871_Won,
};

struct Tuple2_872 {
    enum GameState_871  field0;
    enum GameState_871  field1;
};

static struct Tuple2_872 Tuple2_872_Tuple2 (  enum GameState_871  field0 ,  enum GameState_871  field1 ) {
    return ( struct Tuple2_872 ) { .field0 = field0 ,  .field1 = field1 };
};

static  bool   eq870 (    enum GameState_871  l2579 ,    enum GameState_871  r2581 ) {
    return ( {  struct Tuple2_872  dref2582 = ( ( Tuple2_872_Tuple2 ) ( (  l2579 ) ,  (  r2581 ) ) ) ;  dref2582 .field0 == GameState_871_InProgress &&  dref2582 .field1 == GameState_871_InProgress ? ( true ) :  dref2582 .field0 == GameState_871_Failed &&  dref2582 .field1 == GameState_871_Failed ? ( true ) :  dref2582 .field0 == GameState_871_Won &&  dref2582 .field1 == GameState_871_Won ? ( true ) : ( false ) ; } );
}

struct TileMap_874 {
    struct Slice_307  f_tiles;
    int32_t  f_width;
    int32_t  f_height;
};

static  struct TileMap_874   mk_dash_tiles873 (    size_t  w2587 ,    size_t  h2589 ,    enum CAllocator_383  al2591 ) {
    struct Slice_307  rows2592 = ( (  allocate696 ) ( (  al2591 ) ,  (  h2589 ) ) );
    struct SliceAddressIter_679  temp875 =  into_dash_iter680 ( ( (  addresses678 ) ( (  rows2592 ) ) ) );
    while (true) {
        struct Maybe_682  __cond876 =  next681 (&temp875);
        if (  __cond876 .tag == 0 ) {
            break;
        }
        struct Slice_103 *  row2594 =  __cond876 .stuff .Maybe_682_Just_s .field0;
        (*  row2594 ) = ( (  default703 ) ( (  al2591 ) ,  (  w2587 ) ,  ( (struct Tile_104) { .f_hidden = ( true ) , .f_is_dash_bomb = ( false ) , .f_flagged = ( false ) } ) ) );
    }
    return ( (struct TileMap_874) { .f_tiles = (  rows2592 ) , .f_width = ( (  size_dash_i32260 ) ( (  w2587 ) ) ) , .f_height = ( (  size_dash_i32260 ) ( (  h2589 ) ) ) } );
}

static  enum Unit_157   map_dash_tile877 (    struct TileMap_874  tilemap2597 ,    int32_t  x2599 ,    int32_t  y2601 ,    struct Tile_104 (*  fun2603 )(    struct Tile_104  ) ) {
    struct Tile_104 *  tp2604 = ( (  get_dash_ptr662 ) ( (  elem_dash_get683 ( ( (  tilemap2597 ) .f_tiles ) , ( (  i32_dash_size256 ) ( (  y2601 ) ) ) ) ) ,  ( (  i32_dash_size256 ) ( (  x2599 ) ) ) ) );
    (*  tp2604 ) = ( (  fun2603 ) ( ( * (  tp2604 ) ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   map_dash_tile878 (    struct TileMap_874  tilemap2597 ,    int32_t  x2599 ,    int32_t  y2601 ,    struct Tile_104 (*  fun2603 )(    struct Tile_104  ) ) {
    struct Tile_104 *  tp2604 = ( (  get_dash_ptr662 ) ( (  elem_dash_get683 ( ( (  tilemap2597 ) .f_tiles ) , ( (  i32_dash_size256 ) ( (  y2601 ) ) ) ) ) ,  ( (  i32_dash_size256 ) ( (  x2599 ) ) ) ) );
    (*  tp2604 ) = ( (  fun2603 ) ( ( * (  tp2604 ) ) ) );
    return ( Unit_157_Unit );
}

static  enum Unit_157   map_dash_tile879 (    struct TileMap_874  tilemap2597 ,    int32_t  x2599 ,    int32_t  y2601 ,    struct Tile_104 (*  fun2603 )(    struct Tile_104  ) ) {
    struct Tile_104 *  tp2604 = ( (  get_dash_ptr662 ) ( (  elem_dash_get683 ( ( (  tilemap2597 ) .f_tiles ) , ( (  i32_dash_size256 ) ( (  y2601 ) ) ) ) ) ,  ( (  i32_dash_size256 ) ( (  x2599 ) ) ) ) );
    (*  tp2604 ) = ( (  fun2603 ) ( ( * (  tp2604 ) ) ) );
    return ( Unit_157_Unit );
}

static  struct Maybe_330   lam539 (   struct env539 env ,    struct Slice_103  s2613 ) {
    return ( (  try_dash_get666 ) ( (  s2613 ) ,  ( env.x2610 ) ) );
}

static  struct Tile_104   elem_dash_get880 (    struct TileMap_874  self2607 ,    struct Tuple2_531  idx2609 ) {
    size_t  x2610 = ( (  i32_dash_size256 ) ( ( (  fst530 ) ( (  idx2609 ) ) ) ) );
    size_t  y2611 = ( (  i32_dash_size256 ) ( ( (  snd534 ) ( (  idx2609 ) ) ) ) );
    struct env539 envinst539 = {
        .x2610 =  x2610 ,
    };
    return ( (  or_dash_else659 ) ( ( (  and_dash_maybe538 ) ( ( (  try_dash_get665 ) ( ( (  self2607 ) .f_tiles ) ,  (  y2611 ) ) ) ,  ( (struct funenv539){ .fun = lam539, .env = envinst539 } ) ) ) ,  ( (struct Tile_104) { .f_is_dash_bomb = ( false ) , .f_hidden = ( false ) , .f_flagged = ( false ) } ) ) );
}

static  struct Tile_104   lam886 (    struct Tile_104  dref2630 ) {
    return ( (struct Tile_104) { .f_hidden = ( true ) , .f_is_dash_bomb = ( true ) , .f_flagged = ( false ) } );
}

static  struct TileMap_874   generate_dash_map881 (    size_t  w2616 ,    size_t  h2618 ,    int32_t  bombs2620 ,    enum CAllocator_383  al2622 ) {
    struct TileMap_874  tiles2623 = ( (  mk_dash_tiles873 ) ( (  w2616 ) ,  (  h2618 ) ,  (  al2622 ) ) );
    struct RangeIter_288  temp882 =  into_dash_iter287 ( ( (  to285 ) ( (  from_dash_integral3 ( 1 ) ) ,  (  bombs2620 ) ) ) );
    while (true) {
        struct Maybe_290  __cond883 =  next289 (&temp882);
        if (  __cond883 .tag == 0 ) {
            break;
        }
        int32_t  bomb2625 =  __cond883 .stuff .Maybe_290_Just_s .field0;
        int32_t  temp884;
        int32_t  x2626 = (  temp884 );
        int32_t  temp885;
        int32_t  y2627 = (  temp885 );
        while ( ( true ) ) {
            x2626 = ( (  u32_dash_i32264 ) ( ( (  mod552 ) ( ( (  next_dash_u32799 ) ( ) ) ,  ( (  size_dash_u32261 ) ( (  w2616 ) ) ) ) ) ) );
            y2627 = ( (  u32_dash_i32264 ) ( ( (  mod552 ) ( ( (  next_dash_u32799 ) ( ) ) ,  ( (  size_dash_u32261 ) ( (  h2618 ) ) ) ) ) ) );
            if ( ( ! ( (  elem_dash_get880 ( (  tiles2623 ) , ( ( Tuple2_531_Tuple2 ) ( (  x2626 ) ,  (  y2627 ) ) ) ) ) .f_is_dash_bomb ) ) ) {
                break;
            }
        }
        ( (  map_dash_tile877 ) ( (  tiles2623 ) ,  (  x2626 ) ,  (  y2627 ) ,  (  lam886 ) ) );
    }
    return (  tiles2623 );
}

static  int32_t   count_dash_neighbor_dash_bombs887 (    struct TileMap_874  tilemap2633 ,    int32_t  x2635 ,    int32_t  y2637 ) {
    int32_t  neighbors2638 = (  from_dash_integral3 ( 0 ) );
    struct RangeIter_288  temp888 =  into_dash_iter287 ( ( (  to285 ) ( (  op_dash_sub48 ( (  y2637 ) , (  from_dash_integral3 ( 1 ) ) ) ) ,  (  op_dash_add47 ( (  y2637 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_290  __cond889 =  next289 (&temp888);
        if (  __cond889 .tag == 0 ) {
            break;
        }
        int32_t  yy2640 =  __cond889 .stuff .Maybe_290_Just_s .field0;
        struct RangeIter_288  temp890 =  into_dash_iter287 ( ( (  to285 ) ( (  op_dash_sub48 ( (  x2635 ) , (  from_dash_integral3 ( 1 ) ) ) ) ,  (  op_dash_add47 ( (  x2635 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
        while (true) {
            struct Maybe_290  __cond891 =  next289 (&temp890);
            if (  __cond891 .tag == 0 ) {
                break;
            }
            int32_t  xx2642 =  __cond891 .stuff .Maybe_290_Just_s .field0;
            if ( ( (  elem_dash_get880 ( (  tilemap2633 ) , ( ( Tuple2_531_Tuple2 ) ( (  xx2642 ) ,  (  yy2640 ) ) ) ) ) .f_is_dash_bomb ) ) {
                neighbors2638 = (  op_dash_add47 ( (  neighbors2638 ) , (  from_dash_integral3 ( 1 ) ) ) );
            }
        }
    }
    return (  neighbors2638 );
}

static  enum Unit_157   render_dash_tiles892 (    struct Screen_438 *  screen2645 ,    struct TileMap_874  tilemap2962 ,    struct Tuple2_531  dref2963 ,    enum GameState_871  game_dash_state2967 ) {
    ( (  set_dash_screen_dash_bg855 ) ( (  screen2645 ) ,  ( ( Color_17_Color8 ) ( ( Color8_18_Magenta8 ) ) ) ) );
    struct RangeIter_288  temp893 =  into_dash_iter287 ( ( (  to285 ) ( (  op_dash_neg51 ( (  from_dash_integral3 ( 1 ) ) ) ) ,  ( (  tilemap2962 ) .f_width ) ) ) );
    while (true) {
        struct Maybe_290  __cond894 =  next289 (&temp893);
        if (  __cond894 .tag == 0 ) {
            break;
        }
        int32_t  x2969 =  __cond894 .stuff .Maybe_290_Just_s .field0;
        ( (  put_dash_char863 ) ( (  screen2645 ) ,  ( (  from_dash_charlike1 ) ( ( " " ) ) ) ,  (  op_dash_add47 ( (  x2969 ) , ( dref2963 .field0 ) ) ) ,  (  op_dash_sub48 ( ( dref2963 .field1 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) );
        ( (  put_dash_char863 ) ( (  screen2645 ) ,  ( (  from_dash_charlike1 ) ( ( " " ) ) ) ,  (  op_dash_add47 ( (  x2969 ) , ( dref2963 .field0 ) ) ) ,  (  op_dash_add47 ( ( dref2963 .field1 ) , ( (  tilemap2962 ) .f_height ) ) ) ) );
    }
    struct RangeIter_288  temp895 =  into_dash_iter287 ( ( (  to285 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  op_dash_sub48 ( ( (  tilemap2962 ) .f_height ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_290  __cond896 =  next289 (&temp895);
        if (  __cond896 .tag == 0 ) {
            break;
        }
        int32_t  y2971 =  __cond896 .stuff .Maybe_290_Just_s .field0;
        ( (  put_dash_char863 ) ( (  screen2645 ) ,  ( (  from_dash_charlike1 ) ( ( " " ) ) ) ,  (  op_dash_sub48 ( ( dref2963 .field0 ) , (  from_dash_integral3 ( 1 ) ) ) ) ,  (  op_dash_add47 ( (  y2971 ) , ( dref2963 .field1 ) ) ) ) );
        ( (  put_dash_char863 ) ( (  screen2645 ) ,  ( (  from_dash_charlike1 ) ( ( " " ) ) ) ,  (  op_dash_add47 ( ( dref2963 .field0 ) , ( (  tilemap2962 ) .f_width ) ) ) ,  (  op_dash_add47 ( (  y2971 ) , ( dref2963 .field1 ) ) ) ) );
    }
    struct Zip_305  temp897 =  into_dash_iter304 ( ( (  zip339 ) ( ( (  tilemap2962 ) .f_tiles ) ,  ( (  from291 ) ( (  from_dash_integral3 ( 0 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_323  __cond898 =  next322 (&temp897);
        if (  __cond898 .tag == 0 ) {
            break;
        }
        struct Tuple2_324  dref2972 =  __cond898 .stuff .Maybe_323_Just_s .field0;
        struct Zip_302  temp899 =  into_dash_iter301 ( ( (  zip337 ) ( ( dref2972 .field0 ) ,  ( (  from291 ) ( (  from_dash_integral3 ( 0 ) ) ) ) ) ) );
        while (true) {
            struct Maybe_328  __cond900 =  next327 (&temp899);
            if (  __cond900 .tag == 0 ) {
                break;
            }
            struct Tuple2_329  dref2975 =  __cond900 .stuff .Maybe_328_Just_s .field0;
            int32_t  x2978 = (  op_dash_add47 ( ( dref2975 .field1 ) , ( dref2963 .field0 ) ) );
            int32_t  y2979 = (  op_dash_add47 ( ( dref2972 .field1 ) , ( dref2963 .field1 ) ) );
            struct Color_17  bg2980 = ( (  eq9 ( ( (  mod553 ) ( (  op_dash_add47 ( ( dref2975 .field1 ) , ( dref2972 .field1 ) ) ) ,  (  from_dash_integral3 ( 2 ) ) ) ) , (  from_dash_integral3 ( 0 ) ) ) ) ? ( ( Color_17_Color8 ) ( ( Color8_18_White8 ) ) ) : ( ( Color_17_Color16 ) ( ( Color16_19_BrightWhite16 ) ) ) );
            if ( ( ( dref2975 .field0 ) .f_hidden ) ) {
                ( (  set_dash_screen_dash_bg855 ) ( (  screen2645 ) ,  (  bg2980 ) ) );
                if ( ( ( dref2975 .field0 ) .f_flagged ) ) {
                    ( (  set_dash_screen_dash_fg854 ) ( (  screen2645 ) ,  ( ( Color_17_Color8 ) ( ( Color8_18_Red8 ) ) ) ) );
                    ( (  put_dash_char863 ) ( (  screen2645 ) ,  ( (  from_dash_charlike1 ) ( ( "F" ) ) ) ,  (  x2978 ) ,  (  y2979 ) ) );
                } else {
                    ( (  put_dash_char863 ) ( (  screen2645 ) ,  ( (  from_dash_charlike1 ) ( ( " " ) ) ) ,  (  x2978 ) ,  (  y2979 ) ) );
                }
            } else {
                ( (  set_dash_screen_dash_colors856 ) ( (  screen2645 ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ) );
                int32_t  num_dash_bombs2981 = ( (  count_dash_neighbor_dash_bombs887 ) ( (  tilemap2962 ) ,  ( dref2975 .field1 ) ,  ( dref2972 .field1 ) ) );
                if ( (  eq9 ( (  num_dash_bombs2981 ) , (  from_dash_integral3 ( 0 ) ) ) ) ) {
                    ( (  put_dash_char863 ) ( (  screen2645 ) ,  ( (  from_dash_charlike1 ) ( ( " " ) ) ) ,  (  x2978 ) ,  (  y2979 ) ) );
                } else {
                    char  num_dash_bombs_dash_char2982 = ( (  or_dash_fail656 ) ( ( (  head522 ) ( ( (  chars560 ) ( (  num_dash_bombs2981 ) ) ) ) ) ,  ( "impossible:)" ) ) );
                    ( (  put_dash_char863 ) ( (  screen2645 ) ,  (  num_dash_bombs_dash_char2982 ) ,  (  x2978 ) ,  (  y2979 ) ) );
                }
            }
            if ( ( (  eq870 ( (  game_dash_state2967 ) , ( GameState_871_Failed ) ) ) && ( ( dref2975 .field0 ) .f_is_dash_bomb ) ) ) {
                if ( ( ( dref2975 .field0 ) .f_hidden ) ) {
                    ( (  set_dash_screen_dash_fg854 ) ( (  screen2645 ) ,  ( ( Color_17_Color8 ) ( ( Color8_18_Red8 ) ) ) ) );
                    ( (  set_dash_screen_dash_bg855 ) ( (  screen2645 ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ) );
                    ( (  put_dash_char863 ) ( (  screen2645 ) ,  ( (  from_dash_charlike1 ) ( ( "o" ) ) ) ,  (  x2978 ) ,  (  y2979 ) ) );
                } else {
                    ( (  set_dash_screen_dash_fg854 ) ( (  screen2645 ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ) );
                    ( (  set_dash_screen_dash_bg855 ) ( (  screen2645 ) ,  ( ( Color_17_Color8 ) ( ( Color8_18_Red8 ) ) ) ) );
                    ( (  put_dash_char863 ) ( (  screen2645 ) ,  ( (  from_dash_charlike1 ) ( ( "o" ) ) ) ,  (  x2978 ) ,  (  y2979 ) ) );
                }
            }
        }
    }
    return ( Unit_157_Unit );
}

static  bool   lam902 (    struct Tile_104  tile2987 ) {
    return ( ( ( (  tile2987 ) .f_is_dash_bomb ) && ( (  tile2987 ) .f_hidden ) ) || ( ( ! ( (  tile2987 ) .f_is_dash_bomb ) ) && ( ! ( (  tile2987 ) .f_hidden ) ) ) );
}

static  bool   is_dash_game_dash_won901 (    struct TileMap_874  tilemap2985 ) {
    return ( (  all515 ) ( ( (  flatten346 ) ( ( (  tilemap2985 ) .f_tiles ) ) ) ,  (  lam902 ) ) );
}

static  struct Tile_104   lam904 (    struct Tile_104  tile2997 ) {
    struct Tile_104  temp905 = (  tile2997 );
    temp905 .  f_hidden = ( false );
    return ( temp905 );
}

static  bool   uncover_dash_tile903 (    struct TileMap_874  tilemap2990 ,    int32_t  x2992 ,    int32_t  y2994 ) {
    if ( ( ( ( (  cmp40 ( (  x2992 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) || (  cmp40 ( (  x2992 ) , ( (  tilemap2990 ) .f_width ) ) != 0 ) ) || (  cmp40 ( (  y2994 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) ) || (  cmp40 ( (  y2994 ) , ( (  tilemap2990 ) .f_height ) ) != 0 ) ) ) {
        return ( false );
    }
    struct Tile_104  tile2995 = (  elem_dash_get880 ( (  tilemap2990 ) , ( ( Tuple2_531_Tuple2 ) ( (  x2992 ) ,  (  y2994 ) ) ) ) );
    if ( ( ! ( (  tile2995 ) .f_hidden ) ) ) {
        return ( false );
    }
    ( (  map_dash_tile878 ) ( (  tilemap2990 ) ,  (  x2992 ) ,  (  y2994 ) ,  (  lam904 ) ) );
    if ( ( (  tile2995 ) .f_is_dash_bomb ) ) {
        return ( true );
    } else {
        int32_t  nb2998 = ( (  count_dash_neighbor_dash_bombs887 ) ( (  tilemap2990 ) ,  (  x2992 ) ,  (  y2994 ) ) );
        if ( (  eq9 ( (  nb2998 ) , (  from_dash_integral3 ( 0 ) ) ) ) ) {
            struct RangeIter_288  temp906 =  into_dash_iter287 ( ( (  to285 ) ( (  op_dash_sub48 ( (  y2994 ) , (  from_dash_integral3 ( 1 ) ) ) ) ,  (  op_dash_add47 ( (  y2994 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
            while (true) {
                struct Maybe_290  __cond907 =  next289 (&temp906);
                if (  __cond907 .tag == 0 ) {
                    break;
                }
                int32_t  yy3000 =  __cond907 .stuff .Maybe_290_Just_s .field0;
                struct RangeIter_288  temp908 =  into_dash_iter287 ( ( (  to285 ) ( (  op_dash_sub48 ( (  x2992 ) , (  from_dash_integral3 ( 1 ) ) ) ) ,  (  op_dash_add47 ( (  x2992 ) , (  from_dash_integral3 ( 1 ) ) ) ) ) ) );
                while (true) {
                    struct Maybe_290  __cond909 =  next289 (&temp908);
                    if (  __cond909 .tag == 0 ) {
                        break;
                    }
                    int32_t  xx3002 =  __cond909 .stuff .Maybe_290_Just_s .field0;
                    ( (  uncover_dash_tile903 ) ( (  tilemap2990 ) ,  (  xx3002 ) ,  (  yy3000 ) ) );
                }
            }
        }
        return ( false );
    }
}

static  struct Tile_104   lam911 (    struct Tile_104  tile3011 ) {
    struct Tile_104  temp912 = (  tile3011 );
    temp912 .  f_flagged = ( ! ( (  tile3011 ) .f_flagged ) );
    return ( temp912 );
}

static  bool   toggle_dash_flag910 (    struct TileMap_874  tilemap3005 ,    int32_t  x3007 ,    int32_t  y3009 ) {
    if ( ( ( ( (  cmp40 ( (  x3007 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) || (  cmp40 ( (  x3007 ) , ( (  tilemap3005 ) .f_width ) ) != 0 ) ) || (  cmp40 ( (  y3009 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) ) || (  cmp40 ( (  y3009 ) , ( (  tilemap3005 ) .f_height ) ) != 0 ) ) ) {
        return ( false );
    }
    ( (  map_dash_tile879 ) ( (  tilemap3005 ) ,  (  x3007 ) ,  (  y3009 ) ,  (  lam911 ) ) );
}

static  struct Tuple2_531   get_dash_board_dash_off913 (    struct Tui_363 *  tui3014 ,    struct TileMap_874  tilemap3016 ) {
    return ( ( Tuple2_531_Tuple2 ) ( (  op_dash_sub48 ( (  op_dash_div50 ( ( (  u32_dash_i32264 ) ( ( ( * (  tui3014 ) ) .f_width ) ) ) , (  from_dash_integral3 ( 2 ) ) ) ) , (  op_dash_div50 ( ( (  tilemap3016 ) .f_width ) , (  from_dash_integral3 ( 2 ) ) ) ) ) ) ,  (  op_dash_sub48 ( (  op_dash_div50 ( ( (  u32_dash_i32264 ) ( ( ( * (  tui3014 ) ) .f_height ) ) ) , (  from_dash_integral3 ( 2 ) ) ) ) , (  op_dash_div50 ( ( (  tilemap3016 ) .f_height ) , (  from_dash_integral3 ( 2 ) ) ) ) ) ) ) );
}

struct funenv778 {
    const char*  (*fun) (  struct env778  ,    struct StrConcat_568  ,    enum CAllocator_383  );
    struct env778 env;
};

struct env914 {
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
    ;
    struct env778 envinst778;
    ;
    ;
};

static  enum Unit_157   lam542 (   struct env542 env ,    const char*  filename3035 ) {
    return ( (  free_dash_const_dash_str783 ) ( (  filename3035 ) ,  ( env.al3020 ) ) );
}

static  struct Maybe_537   lam543 (   struct env543 env ,    const char*  filename3037 ) {
    return ( (  try_dash_read_dash_contents790 ) ( (  filename3037 ) ,  ( env.al3020 ) ) );
}

static  struct Stats_549   load_dash_score914 (   struct env914 env ,    enum CAllocator_383  al3020 ) {
    struct StrCase_569  data_dash_dir3032 = ( (  data_dash_home868 ) ( ) );
    struct StrConcat_568  stats_dash_file3033 = ( ( StrConcat_568_StrConcat ) ( (  data_dash_dir3032 ) ,  ( "/kc-minesweeper/stats" ) ) );
    struct funenv778  temp915 = ( (struct funenv778){ .fun = mk_dash_const_dash_str778, .env =  env.envinst778  } );
    struct env542 envinst542 = {
        .al3020 =  al3020 ,
    };
    struct env543 envinst543 = {
        .al3020 =  al3020 ,
    };
    struct Maybe_537  dref3038 = ( (  with541 ) ( ( temp915.fun ( temp915.env ,  (  stats_dash_file3033 ) ,  (  al3020 ) ) ) ,  ( (struct funenv542){ .fun = lam542, .env = envinst542 } ) ,  ( (struct funenv543){ .fun = lam543, .env = envinst543 } ) ) );
    if ( dref3038.tag == Maybe_537_None_t ) {
        return ( (struct Stats_549) { .f_total_dash_wins = (  from_dash_integral4 ( 0 ) ) } );
    }
    else {
        if ( dref3038.tag == Maybe_537_Just_t ) {
            struct LineIter_717  temp916 = ( (  into_dash_iter718 ) ( ( (  lines716 ) ( ( dref3038 .stuff .Maybe_537_Just_s .field0 ) ) ) ) );
            struct LineIter_717 *  it3040 = ( &temp916 );
            uint32_t  total_dash_wins3041 = ( (  i64_dash_u32258 ) ( ( (  or_dash_else658 ) ( ( (  and_dash_maybe536 ) ( ( (  next719 ) ( (  it3040 ) ) ) ,  (  parse_dash_int724 ) ) ) ,  (  from_dash_integral2 ( 0 ) ) ) ) ) );
            return ( (struct Stats_549) { .f_total_dash_wins = (  total_dash_wins3041 ) } );
        }
    }
}

struct funenv794 {
    enum Unit_157  (*fun) (  struct env794  ,    struct StrConcat_568  ,    enum CAllocator_383  );
    struct env794 env;
};

struct funenv781 {
    const char*  (*fun) (  struct env781  ,    struct StrConcat_576  ,    enum CAllocator_383  );
    struct env781 env;
};

struct env917 {
    struct env794 envinst794;
    ;
    ;
    ;
    ;
    ;
    struct env781 envinst781;
    ;
    ;
    ;
};

static  enum Unit_157   lam547 (   struct env547 env ,    const char*  filename3051 ) {
    return ( (  free_dash_const_dash_str783 ) ( (  filename3051 ) ,  ( env.al3046 ) ) );
}

static  enum Unit_157   lam548 (   struct env548 env ,    const char*  filename3053 ) {
    return ( (  write_dash_contents792 ) ( (  filename3053 ) ,  ( ( StrConcat_579_StrConcat ) ( ( ( env.stats3044 ) .f_total_dash_wins ) ,  ( (  from_dash_charlike1 ) ( ( "\n" ) ) ) ) ) ) );
}

static  enum Unit_157   save_dash_score917 (   struct env917 env ,    struct Stats_549  stats3044 ,    enum CAllocator_383  al3046 ) {
    struct StrCase_569  data_dash_dir3047 = ( (  data_dash_home868 ) ( ) );
    struct StrConcat_568  minesweeper_dash_data_dash_dir3048 = ( ( StrConcat_568_StrConcat ) ( (  data_dash_dir3047 ) ,  ( "/kc-minesweeper" ) ) );
    struct funenv794  temp918 = ( (struct funenv794){ .fun = mkdir_dash_p794, .env =  env.envinst794  } );
    ( temp918.fun ( temp918.env ,  (  minesweeper_dash_data_dash_dir3048 ) ,  (  al3046 ) ) );
    struct StrConcat_576  stats_dash_file3049 = ( ( StrConcat_576_StrConcat ) ( (  minesweeper_dash_data_dash_dir3048 ) ,  ( "/stats" ) ) );
    struct funenv781  temp919 = ( (struct funenv781){ .fun = mk_dash_const_dash_str781, .env =  env.envinst781  } );
    struct env547 envinst547 = {
        .al3046 =  al3046 ,
    };
    struct env548 envinst548 = {
        .stats3044 =  stats3044 ,
    };
    ( (  with546 ) ( ( temp919.fun ( temp919.env ,  (  stats_dash_file3049 ) ,  (  al3046 ) ) ) ,  ( (struct funenv547){ .fun = lam547, .env = envinst547 } ) ,  ( (struct funenv548){ .fun = lam548, .env = envinst548 } ) ) );
    return ( Unit_157_Unit );
}

struct funenv914 {
    struct Stats_549  (*fun) (  struct env914  ,    enum CAllocator_383  );
    struct env914 env;
};

struct funenv812 {
    struct Tui_363  (*fun) (  struct env812  );
    struct env812 env;
};

static  struct Maybe_365   lam360 (   struct env360 env ) {
    struct funenv361  temp927 = ( (struct funenv361){ .fun = read_dash_event361, .env =  env.envinst361  } );
    return ( temp927.fun ( temp927.env ,  ( env.tui3070 ) ) );
}

struct funenv917 {
    enum Unit_157  (*fun) (  struct env917  ,    struct Stats_549  ,    enum CAllocator_383  );
    struct env917 env;
};

struct funenv852 {
    bool  (*fun) (  struct env852  ,    struct Screen_438 *  );
    struct env852 env;
};

int main(int argc, const char **argv) {
	_global_argc = argc; _global_argv = argv;
    size_t  starting_dash_size1722 = ( (  from_dash_integral8 ( 8 ) ) );
    size_t  growth_dash_factor1723 = ( (  from_dash_integral8 ( 2 ) ) );
    size_t  shrink_dash_factor1724 = ( (  from_dash_integral8 ( 8 ) ) );
    struct env385 envinst385 = {
        .growth_dash_factor1723 =  growth_dash_factor1723 ,
        .starting_dash_size1722 =  starting_dash_size1722 ,
    };
    struct env384 envinst384 = {
        .envinst385 = envinst385 ,
    };
    struct env756 envinst756 = {
        .envinst384 = envinst384 ,
    };
    struct env416 envinst416 = {
        .envinst384 = envinst384 ,
    };
    struct env760 envinst760 = {
        .envinst384 = envinst384 ,
    };
    struct env412 envinst412 = {
        .envinst384 = envinst384 ,
    };
    struct env767 envinst767 = {
        .envinst756 = envinst756 ,
        .envinst412 = envinst412 ,
    };
    struct env415 envinst415 = {
        .envinst416 = envinst416 ,
        .envinst412 = envinst412 ,
    };
    struct env774 envinst774 = {
        .envinst760 = envinst760 ,
        .envinst412 = envinst412 ,
    };
    struct env778 envinst778 = {
        .envinst767 = envinst767 ,
    };
    struct env414 envinst414 = {
        .envinst415 = envinst415 ,
    };
    struct env781 envinst781 = {
        .envinst774 = envinst774 ,
    };
    struct env413 envinst413 = {
        .envinst414 = envinst414 ,
    };
    struct env794 envinst794 = {
        .envinst412 = envinst412 ,
        .envinst413 = envinst413 ,
    };
    ( ( srand ) ( ( (  cast169 ) ( ( ( time ) ( ( (  null_dash_c_dash_ptr248 ) ( ) ) ) ) ) ) ) );
    bool  temp811 = ( true );
    bool *  should_dash_resize2724 = ( &temp811 );
    struct env812 envinst812 = {
        .should_dash_resize2724 =  should_dash_resize2724 ,
    };
    struct env362 envinst362 = {
        .should_dash_resize2724 =  should_dash_resize2724 ,
    };
    struct env361 envinst361 = {
        .envinst362 = envinst362 ,
    };
    struct env852 envinst852 = {
        .envinst362 = envinst362 ,
    };
    struct env914 envinst914 = {
        .envinst778 = envinst778 ,
    };
    struct env917 envinst917 = {
        .envinst794 = envinst794 ,
        .envinst781 = envinst781 ,
    };
    struct Slice_676  args3056 = ( (  get869 ) ( ) );
    size_t  width3057 = (  from_dash_integral8 ( 9 ) );
    size_t  height3058 = (  from_dash_integral8 ( 9 ) );
    int32_t  bombs3059 = (  from_dash_integral3 ( 10 ) );
    struct Slice_676  dref3060 = (  args3056 );
    const char*  __larr__920[3];
    const char*  *dref3061 =  __larr__920;
    if (  deconstruct687 (  dref3060 , &  dref3061 , 3 , (   struct ListSpread_688  ) { .tag = 0 } , NULL , 0 ) ) {
        width3057 = ( (  i64_dash_size259 ) ( ( (  or_dash_fail646 ) ( ( (  parse_dash_int722 ) ( ( dref3061[0] ) ) ) ,  ( "could not parse width" ) ) ) ) );
        height3058 = ( (  i64_dash_size259 ) ( ( (  or_dash_fail646 ) ( ( (  parse_dash_int722 ) ( ( dref3061[1] ) ) ) ,  ( "could not parse height" ) ) ) ) );
        bombs3059 = ( (  i64_dash_i32257 ) ( ( (  or_dash_fail646 ) ( ( (  parse_dash_int722 ) ( ( dref3061[2] ) ) ) ,  ( "could not parse bombs" ) ) ) ) );
    }
    else {
        const char*  *dref3065 = NULL;
        if (  deconstruct687 (  dref3060 , &  dref3065 , 0 , (   struct ListSpread_688  ) { .tag = 0 } , NULL , 0 ) ) {
        }
        else {
            if ( true ) {
                ( (  panic641 ) ( ( "args??" ) ) );
            }
        }
    }
    enum CAllocator_383  al3066 = ( (  idc694 ) ( ) );
    struct funenv914  temp922 = ( (struct funenv914){ .fun = load_dash_score914, .env =  envinst914  } );
    struct Stats_549  stats3067 = ( temp922.fun ( temp922.env ,  (  al3066 ) ) );
    enum GameState_871  game_dash_state3068 = ( GameState_871_InProgress );
    struct TileMap_874  tilemap3069 = ( (  generate_dash_map881 ) ( (  width3057 ) ,  (  height3058 ) ,  (  bombs3059 ) ,  (  al3066 ) ) );
    struct funenv812  temp924 = ( (struct funenv812){ .fun = mk812, .env =  envinst812  } );
    struct Tui_363  temp923 = ( temp924.fun ( temp924.env ) );
    struct Tui_363 *  tui3070 = ( &temp923 );
    enum CAllocator_383  al3071 = ( (  idc694 ) ( ) );
    struct Screen_438  temp925 = ( (  mk_dash_screen838 ) ( (  tui3070 ) ,  (  al3071 ) ) );
    struct Screen_438 *  screen3072 = ( &temp925 );
    bool  running3073 = ( true );
    while ( (  running3073 ) ) {
        struct env360 envinst360 = {
            .envinst361 = envinst361 ,
            .tui3070 =  tui3070 ,
        };
        struct FunIter_359  temp926 =  into_dash_iter358 ( ( (  from_dash_function371 ) ( ( (struct funenv360){ .fun = lam360, .env = envinst360 } ) ) ) );
        while (true) {
            struct Maybe_365  __cond928 =  next369 (&temp926);
            if (  __cond928 .tag == 0 ) {
                break;
            }
            struct InputEvent_366  ev3075 =  __cond928 .stuff .Maybe_365_Just_s .field0;
            struct InputEvent_366  dref3076 = (  ev3075 );
            if ( dref3076.tag == InputEvent_366_Key_t && dref3076 .stuff .InputEvent_366_Key_s .field0.tag == Key_367_Char_t ) {
                if ( (  eq14 ( ( dref3076 .stuff .InputEvent_366_Key_s .field0 .stuff .Key_367_Char_s .field0 ) , ( (  from_dash_charlike1 ) ( ( "q" ) ) ) ) ) ) {
                    running3073 = ( false );
                }
                if ( (  eq14 ( ( dref3076 .stuff .InputEvent_366_Key_s .field0 .stuff .Key_367_Char_s .field0 ) , ( (  from_dash_charlike1 ) ( ( "r" ) ) ) ) ) ) {
                    tilemap3069 = ( (  generate_dash_map881 ) ( (  width3057 ) ,  (  height3058 ) ,  (  bombs3059 ) ,  (  al3071 ) ) );
                    game_dash_state3068 = ( GameState_871_InProgress );
                }
            }
            else {
                if ( dref3076.tag == InputEvent_366_Mouse_t ) {
                    int32_t  x3079 = (  op_dash_sub48 ( ( ( dref3076 .stuff .InputEvent_366_Mouse_s .field0 ) .f_x ) , ( (  fst530 ) ( ( (  get_dash_board_dash_off913 ) ( (  tui3070 ) ,  (  tilemap3069 ) ) ) ) ) ) );
                    int32_t  y3080 = (  op_dash_sub48 ( ( ( dref3076 .stuff .InputEvent_366_Mouse_s .field0 ) .f_y ) , ( (  snd534 ) ( ( (  get_dash_board_dash_off913 ) ( (  tui3070 ) ,  (  tilemap3069 ) ) ) ) ) ) );
                    if ( ( (  eq823 ( ( ( dref3076 .stuff .InputEvent_366_Mouse_s .field0 ) .f_button ) , ( MouseButton_119_MouseLeft ) ) ) && ( ( dref3076 .stuff .InputEvent_366_Mouse_s .field0 ) .f_pressed ) ) ) {
                        if ( (  eq870 ( (  game_dash_state3068 ) , ( GameState_871_InProgress ) ) ) ) {
                            if ( ( ( ! ( (  elem_dash_get880 ( (  tilemap3069 ) , ( ( Tuple2_531_Tuple2 ) ( (  x3079 ) ,  (  y3080 ) ) ) ) ) .f_flagged ) ) && ( (  uncover_dash_tile903 ) ( (  tilemap3069 ) ,  (  x3079 ) ,  (  y3080 ) ) ) ) ) {
                                game_dash_state3068 = ( GameState_871_Failed );
                            }
                            if ( ( (  eq870 ( (  game_dash_state3068 ) , ( GameState_871_InProgress ) ) ) && ( (  is_dash_game_dash_won901 ) ( (  tilemap3069 ) ) ) ) ) {
                                game_dash_state3068 = ( GameState_871_Won );
                                stats3067 .f_total_dash_wins = (  op_dash_add52 ( ( (  stats3067 ) .f_total_dash_wins ) , (  from_dash_integral4 ( 1 ) ) ) );
                                struct funenv917  temp929 = ( (struct funenv917){ .fun = save_dash_score917, .env =  envinst917  } );
                                ( temp929.fun ( temp929.env ,  (  stats3067 ) ,  (  al3071 ) ) );
                            }
                        }
                    }
                    if ( ( (  eq823 ( ( ( dref3076 .stuff .InputEvent_366_Mouse_s .field0 ) .f_button ) , ( MouseButton_119_MouseRight ) ) ) && ( ( dref3076 .stuff .InputEvent_366_Mouse_s .field0 ) .f_pressed ) ) ) {
                        if ( (  eq870 ( (  game_dash_state3068 ) , ( GameState_871_InProgress ) ) ) ) {
                            ( (  toggle_dash_flag910 ) ( (  tilemap3069 ) ,  (  x3079 ) ,  (  y3080 ) ) );
                        }
                    }
                }
            }
        }
        struct funenv852  temp930 = ( (struct funenv852){ .fun = resize_dash_screen_dash_if_dash_needed852, .env =  envinst852  } );
        ( temp930.fun ( temp930.env ,  (  screen3072 ) ) );
        if ( ( (  should_dash_redraw837 ) ( (  tui3070 ) ) ) ) {
            ( (  clear_dash_screen842 ) ( (  screen3072 ) ) );
            ( (  set_dash_screen_dash_colors856 ) ( (  screen3072 ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ) );
            ( (  fill_dash_default858 ) ( (  screen3072 ) ) );
            ( (  draw_dash_str864 ) ( (  screen3072 ) ,  ( ( StrConcat_581_StrConcat ) ( ( "total wins: " ) ,  ( (  stats3067 ) .f_total_dash_wins ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  (  from_dash_integral3 ( 0 ) ) ) );
            ( (  render_dash_tiles892 ) ( (  screen3072 ) ,  (  tilemap3069 ) ,  ( (  get_dash_board_dash_off913 ) ( (  tui3070 ) ,  (  tilemap3069 ) ) ) ,  (  game_dash_state3068 ) ) );
            ( (  set_dash_screen_dash_colors856 ) ( (  screen3072 ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ,  ( (struct Color_17) { .tag = Color_17_ColorDefault_t } ) ) );
            if ( (  eq870 ( (  game_dash_state3068 ) , ( GameState_871_Failed ) ) ) ) {
                ( (  draw_dash_str_dash_center866 ) ( (  screen3072 ) ,  ( "ya failed. restart? (r)" ) ,  (  op_dash_div50 ( ( (  u32_dash_i32264 ) ( ( ( * (  tui3070 ) ) .f_width ) ) ) , (  from_dash_integral3 ( 2 ) ) ) ) ,  (  op_dash_add47 ( (  op_dash_add47 ( ( (  tilemap3069 ) .f_height ) , ( (  snd534 ) ( ( (  get_dash_board_dash_off913 ) ( (  tui3070 ) ,  (  tilemap3069 ) ) ) ) ) ) ) , (  from_dash_integral3 ( 2 ) ) ) ) ) );
            } else {
                if ( (  eq870 ( (  game_dash_state3068 ) , ( GameState_871_Won ) ) ) ) {
                    ( (  draw_dash_str_dash_center866 ) ( (  screen3072 ) ,  ( "ya won. quit? (q)" ) ,  (  op_dash_div50 ( ( (  u32_dash_i32264 ) ( ( ( * (  tui3070 ) ) .f_width ) ) ) , (  from_dash_integral3 ( 2 ) ) ) ) ,  (  op_dash_add47 ( (  op_dash_add47 ( ( (  tilemap3069 ) .f_height ) , ( (  snd534 ) ( ( (  get_dash_board_dash_off913 ) ( (  tui3070 ) ,  (  tilemap3069 ) ) ) ) ) ) ) , (  from_dash_integral3 ( 2 ) ) ) ) ) );
                }
            }
            ( (  render_dash_screen846 ) ( (  screen3072 ) ) );
        }
        ( (  sync818 ) ( (  tui3070 ) ) );
    }
    ( (  free_dash_screen841 ) ( (  screen3072 ) ) );
    ( (  deinit822 ) ( (  tui3070 ) ) );
}
