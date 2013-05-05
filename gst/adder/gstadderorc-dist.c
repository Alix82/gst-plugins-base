
/* autogenerated from gstadderorc.orc */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifndef DISABLE_ORC
#include <orc/orc.h>
#endif
#include <glib.h>

#ifndef _ORC_INTEGER_TYPEDEFS_
#define _ORC_INTEGER_TYPEDEFS_
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <stdint.h>
typedef int8_t orc_int8;
typedef int16_t orc_int16;
typedef int32_t orc_int32;
typedef int64_t orc_int64;
typedef uint8_t orc_uint8;
typedef uint16_t orc_uint16;
typedef uint32_t orc_uint32;
typedef uint64_t orc_uint64;
#elif defined(_MSC_VER)
typedef signed __int8 orc_int8;
typedef signed __int16 orc_int16;
typedef signed __int32 orc_int32;
typedef signed __int64 orc_int64;
typedef unsigned __int8 orc_uint8;
typedef unsigned __int16 orc_uint16;
typedef unsigned __int32 orc_uint32;
typedef unsigned __int64 orc_uint64;
#else
#include <limits.h>
typedef signed char orc_int8;
typedef short orc_int16;
typedef int orc_int32;
typedef unsigned char orc_uint8;
typedef unsigned short orc_uint16;
typedef unsigned int orc_uint32;
#if INT_MAX == LONG_MAX
typedef long long orc_int64;
typedef unsigned long long orc_uint64;
#else
typedef long orc_int64;
typedef unsigned long orc_uint64;
#endif
#endif
typedef union
{
  orc_int32 i;
  float f;
} orc_union32;
typedef union
{
  orc_int64 i;
  double f;
} orc_union64;
#endif

void add_int32 (gint32 * d1, const gint32 * s1, int n);
void add_int16 (gint16 * d1, const gint16 * s1, int n);
void add_int8 (gint8 * d1, const gint8 * s1, int n);
void add_uint32 (guint32 * d1, const guint32 * s1, int n);
void add_uint16 (guint16 * d1, const guint16 * s1, int n);
void add_uint8 (guint8 * d1, const guint8 * s1, int n);
void add_float32 (float *d1, const float *s1, int n);


/* begin Orc C target preamble */
#define ORC_CLAMP(x,a,b) ((x)<(a) ? (a) : ((x)>(b) ? (b) : (x)))
#define ORC_ABS(a) ((a)<0 ? -(a) : (a))
#define ORC_MIN(a,b) ((a)<(b) ? (a) : (b))
#define ORC_MAX(a,b) ((a)>(b) ? (a) : (b))
#define ORC_SB_MAX 127
#define ORC_SB_MIN (-1-ORC_SB_MAX)
#define ORC_UB_MAX 255
#define ORC_UB_MIN 0
#define ORC_SW_MAX 32767
#define ORC_SW_MIN (-1-ORC_SW_MAX)
#define ORC_UW_MAX 65535
#define ORC_UW_MIN 0
#define ORC_SL_MAX 2147483647
#define ORC_SL_MIN (-1-ORC_SL_MAX)
#define ORC_UL_MAX 4294967295U
#define ORC_UL_MIN 0
#define ORC_CLAMP_SB(x) ORC_CLAMP(x,ORC_SB_MIN,ORC_SB_MAX)
#define ORC_CLAMP_UB(x) ORC_CLAMP(x,ORC_UB_MIN,ORC_UB_MAX)
#define ORC_CLAMP_SW(x) ORC_CLAMP(x,ORC_SW_MIN,ORC_SW_MAX)
#define ORC_CLAMP_UW(x) ORC_CLAMP(x,ORC_UW_MIN,ORC_UW_MAX)
#define ORC_CLAMP_SL(x) ORC_CLAMP(x,ORC_SL_MIN,ORC_SL_MAX)
#define ORC_CLAMP_UL(x) ORC_CLAMP(x,ORC_UL_MIN,ORC_UL_MAX)
#define ORC_SWAP_W(x) ((((x)&0xff)<<8) | (((x)&0xff00)>>8))
#define ORC_SWAP_L(x) ((((x)&0xff)<<24) | (((x)&0xff00)<<8) | (((x)&0xff0000)>>8) | (((x)&0xff000000)>>24))
#define ORC_PTR_OFFSET(ptr,offset) ((void *)(((unsigned char *)(ptr)) + (offset)))
/* end Orc C target preamble */



/* add_int32 */
#ifdef DISABLE_ORC
void
add_int32 (gint32 * d1, const gint32 * s1, int n)
{
  int i;
  orc_union32 var0;
  orc_union32 *ptr0;
  orc_union32 var4;
  const orc_union32 *ptr4;

  ptr0 = (orc_union32 *) d1;
  ptr4 = (orc_union32 *) s1;

  for (i = 0; i < n; i++) {
    var0 = *ptr0;
    var4 = *ptr4;
    ptr4++;
    /* 0: addssl */
    var0.i = ORC_CLAMP_SL ((orc_int64) var0.i + (orc_int64) var4.i);
    *ptr0 = var0;
    ptr0++;
  }

}

#else
static void
_backup_add_int32 (OrcExecutor * ex)
{
  int i;
  int n = ex->n;
  orc_union32 var0;
  orc_union32 *ptr0;
  orc_union32 var4;
  const orc_union32 *ptr4;

  ptr0 = (orc_union32 *) ex->arrays[0];
  ptr4 = (orc_union32 *) ex->arrays[4];

  for (i = 0; i < n; i++) {
    var0 = *ptr0;
    var4 = *ptr4;
    ptr4++;
    /* 0: addssl */
    var0.i = ORC_CLAMP_SL ((orc_int64) var0.i + (orc_int64) var4.i);
    *ptr0 = var0;
    ptr0++;
  }

}

void
add_int32 (gint32 * d1, const gint32 * s1, int n)
{
  OrcExecutor _ex, *ex = &_ex;
  static int p_inited = 0;
  static OrcProgram *p = 0;
  void (*func) (OrcExecutor *);

  if (!p_inited) {
    orc_once_mutex_lock ();
    if (!p_inited) {
      OrcCompileResult result;

      p = orc_program_new ();
      orc_program_set_name (p, "add_int32");
      orc_program_set_backup_function (p, _backup_add_int32);
      orc_program_add_destination (p, 4, "d1");
      orc_program_add_source (p, 4, "s1");

      orc_program_append (p, "addssl", ORC_VAR_D1, ORC_VAR_D1, ORC_VAR_S1);

      result = orc_program_compile (p);
    }
    p_inited = TRUE;
    orc_once_mutex_unlock ();
  }
  ex->program = p;

  ex->n = n;
  ex->arrays[ORC_VAR_D1] = d1;
  ex->arrays[ORC_VAR_S1] = (void *) s1;

  func = p->code_exec;
  func (ex);
}
#endif


/* add_int16 */
#ifdef DISABLE_ORC
void
add_int16 (gint16 * d1, const gint16 * s1, int n)
{
  int i;
  orc_int16 var0;
  orc_int16 *ptr0;
  orc_int16 var4;
  const orc_int16 *ptr4;

  ptr0 = (orc_int16 *) d1;
  ptr4 = (orc_int16 *) s1;

  for (i = 0; i < n; i++) {
    var0 = *ptr0;
    var4 = *ptr4;
    ptr4++;
    /* 0: addssw */
    var0 = ORC_CLAMP_SW (var0 + var4);
    *ptr0 = var0;
    ptr0++;
  }

}

#else
static void
_backup_add_int16 (OrcExecutor * ex)
{
  int i;
  int n = ex->n;
  orc_int16 var0;
  orc_int16 *ptr0;
  orc_int16 var4;
  const orc_int16 *ptr4;

  ptr0 = (orc_int16 *) ex->arrays[0];
  ptr4 = (orc_int16 *) ex->arrays[4];

  for (i = 0; i < n; i++) {
    var0 = *ptr0;
    var4 = *ptr4;
    ptr4++;
    /* 0: addssw */
    var0 = ORC_CLAMP_SW (var0 + var4);
    *ptr0 = var0;
    ptr0++;
  }

}

void
add_int16 (gint16 * d1, const gint16 * s1, int n)
{
  OrcExecutor _ex, *ex = &_ex;
  static int p_inited = 0;
  static OrcProgram *p = 0;
  void (*func) (OrcExecutor *);

  if (!p_inited) {
    orc_once_mutex_lock ();
    if (!p_inited) {
      OrcCompileResult result;

      p = orc_program_new ();
      orc_program_set_name (p, "add_int16");
      orc_program_set_backup_function (p, _backup_add_int16);
      orc_program_add_destination (p, 2, "d1");
      orc_program_add_source (p, 2, "s1");

      orc_program_append (p, "addssw", ORC_VAR_D1, ORC_VAR_D1, ORC_VAR_S1);

      result = orc_program_compile (p);
    }
    p_inited = TRUE;
    orc_once_mutex_unlock ();
  }
  ex->program = p;

  ex->n = n;
  ex->arrays[ORC_VAR_D1] = d1;
  ex->arrays[ORC_VAR_S1] = (void *) s1;

  func = p->code_exec;
  func (ex);
}
#endif


/* add_int8 */
#ifdef DISABLE_ORC
void
add_int8 (gint8 * d1, const gint8 * s1, int n)
{
  int i;
  orc_int8 var0;
  orc_int8 *ptr0;
  orc_int8 var4;
  const orc_int8 *ptr4;

  ptr0 = (orc_int8 *) d1;
  ptr4 = (orc_int8 *) s1;

  for (i = 0; i < n; i++) {
    var0 = *ptr0;
    var4 = *ptr4;
    ptr4++;
    /* 0: addssb */
    var0 = ORC_CLAMP_SB (var0 + var4);
    *ptr0 = var0;
    ptr0++;
  }

}

#else
static void
_backup_add_int8 (OrcExecutor * ex)
{
  int i;
  int n = ex->n;
  orc_int8 var0;
  orc_int8 *ptr0;
  orc_int8 var4;
  const orc_int8 *ptr4;

  ptr0 = (orc_int8 *) ex->arrays[0];
  ptr4 = (orc_int8 *) ex->arrays[4];

  for (i = 0; i < n; i++) {
    var0 = *ptr0;
    var4 = *ptr4;
    ptr4++;
    /* 0: addssb */
    var0 = ORC_CLAMP_SB (var0 + var4);
    *ptr0 = var0;
    ptr0++;
  }

}

void
add_int8 (gint8 * d1, const gint8 * s1, int n)
{
  OrcExecutor _ex, *ex = &_ex;
  static int p_inited = 0;
  static OrcProgram *p = 0;
  void (*func) (OrcExecutor *);

  if (!p_inited) {
    orc_once_mutex_lock ();
    if (!p_inited) {
      OrcCompileResult result;

      p = orc_program_new ();
      orc_program_set_name (p, "add_int8");
      orc_program_set_backup_function (p, _backup_add_int8);
      orc_program_add_destination (p, 1, "d1");
      orc_program_add_source (p, 1, "s1");

      orc_program_append (p, "addssb", ORC_VAR_D1, ORC_VAR_D1, ORC_VAR_S1);

      result = orc_program_compile (p);
    }
    p_inited = TRUE;
    orc_once_mutex_unlock ();
  }
  ex->program = p;

  ex->n = n;
  ex->arrays[ORC_VAR_D1] = d1;
  ex->arrays[ORC_VAR_S1] = (void *) s1;

  func = p->code_exec;
  func (ex);
}
#endif


/* add_uint32 */
#ifdef DISABLE_ORC
void
add_uint32 (guint32 * d1, const guint32 * s1, int n)
{
  int i;
  orc_union32 var0;
  orc_union32 *ptr0;
  orc_union32 var4;
  const orc_union32 *ptr4;

  ptr0 = (orc_union32 *) d1;
  ptr4 = (orc_union32 *) s1;

  for (i = 0; i < n; i++) {
    var0 = *ptr0;
    var4 = *ptr4;
    ptr4++;
    /* 0: addusl */
    var0.i =
        ORC_CLAMP_UL ((orc_int64) (orc_uint32) var0.i +
        (orc_int64) (orc_uint32) var4.i);
    *ptr0 = var0;
    ptr0++;
  }

}

#else
static void
_backup_add_uint32 (OrcExecutor * ex)
{
  int i;
  int n = ex->n;
  orc_union32 var0;
  orc_union32 *ptr0;
  orc_union32 var4;
  const orc_union32 *ptr4;

  ptr0 = (orc_union32 *) ex->arrays[0];
  ptr4 = (orc_union32 *) ex->arrays[4];

  for (i = 0; i < n; i++) {
    var0 = *ptr0;
    var4 = *ptr4;
    ptr4++;
    /* 0: addusl */
    var0.i =
        ORC_CLAMP_UL ((orc_int64) (orc_uint32) var0.i +
        (orc_int64) (orc_uint32) var4.i);
    *ptr0 = var0;
    ptr0++;
  }

}

void
add_uint32 (guint32 * d1, const guint32 * s1, int n)
{
  OrcExecutor _ex, *ex = &_ex;
  static int p_inited = 0;
  static OrcProgram *p = 0;
  void (*func) (OrcExecutor *);

  if (!p_inited) {
    orc_once_mutex_lock ();
    if (!p_inited) {
      OrcCompileResult result;

      p = orc_program_new ();
      orc_program_set_name (p, "add_uint32");
      orc_program_set_backup_function (p, _backup_add_uint32);
      orc_program_add_destination (p, 4, "d1");
      orc_program_add_source (p, 4, "s1");

      orc_program_append (p, "addusl", ORC_VAR_D1, ORC_VAR_D1, ORC_VAR_S1);

      result = orc_program_compile (p);
    }
    p_inited = TRUE;
    orc_once_mutex_unlock ();
  }
  ex->program = p;

  ex->n = n;
  ex->arrays[ORC_VAR_D1] = d1;
  ex->arrays[ORC_VAR_S1] = (void *) s1;

  func = p->code_exec;
  func (ex);
}
#endif


/* add_uint16 */
#ifdef DISABLE_ORC
void
add_uint16 (guint16 * d1, const guint16 * s1, int n)
{
  int i;
  orc_int16 var0;
  orc_int16 *ptr0;
  orc_int16 var4;
  const orc_int16 *ptr4;

  ptr0 = (orc_int16 *) d1;
  ptr4 = (orc_int16 *) s1;

  for (i = 0; i < n; i++) {
    var0 = *ptr0;
    var4 = *ptr4;
    ptr4++;
    /* 0: addusw */
    var0 = ORC_CLAMP_UW ((orc_uint16) var0 + (orc_uint16) var4);
    *ptr0 = var0;
    ptr0++;
  }

}

#else
static void
_backup_add_uint16 (OrcExecutor * ex)
{
  int i;
  int n = ex->n;
  orc_int16 var0;
  orc_int16 *ptr0;
  orc_int16 var4;
  const orc_int16 *ptr4;

  ptr0 = (orc_int16 *) ex->arrays[0];
  ptr4 = (orc_int16 *) ex->arrays[4];

  for (i = 0; i < n; i++) {
    var0 = *ptr0;
    var4 = *ptr4;
    ptr4++;
    /* 0: addusw */
    var0 = ORC_CLAMP_UW ((orc_uint16) var0 + (orc_uint16) var4);
    *ptr0 = var0;
    ptr0++;
  }

}

void
add_uint16 (guint16 * d1, const guint16 * s1, int n)
{
  OrcExecutor _ex, *ex = &_ex;
  static int p_inited = 0;
  static OrcProgram *p = 0;
  void (*func) (OrcExecutor *);

  if (!p_inited) {
    orc_once_mutex_lock ();
    if (!p_inited) {
      OrcCompileResult result;

      p = orc_program_new ();
      orc_program_set_name (p, "add_uint16");
      orc_program_set_backup_function (p, _backup_add_uint16);
      orc_program_add_destination (p, 2, "d1");
      orc_program_add_source (p, 2, "s1");

      orc_program_append (p, "addusw", ORC_VAR_D1, ORC_VAR_D1, ORC_VAR_S1);

      result = orc_program_compile (p);
    }
    p_inited = TRUE;
    orc_once_mutex_unlock ();
  }
  ex->program = p;

  ex->n = n;
  ex->arrays[ORC_VAR_D1] = d1;
  ex->arrays[ORC_VAR_S1] = (void *) s1;

  func = p->code_exec;
  func (ex);
}
#endif


/* add_uint8 */
#ifdef DISABLE_ORC
void
add_uint8 (guint8 * d1, const guint8 * s1, int n)
{
  int i;
  orc_int8 var0;
  orc_int8 *ptr0;
  orc_int8 var4;
  const orc_int8 *ptr4;

  ptr0 = (orc_int8 *) d1;
  ptr4 = (orc_int8 *) s1;

  for (i = 0; i < n; i++) {
    var0 = *ptr0;
    var4 = *ptr4;
    ptr4++;
    /* 0: addusb */
    var0 = ORC_CLAMP_UB ((orc_uint8) var0 + (orc_uint8) var4);
    *ptr0 = var0;
    ptr0++;
  }

}

#else
static void
_backup_add_uint8 (OrcExecutor * ex)
{
  int i;
  int n = ex->n;
  orc_int8 var0;
  orc_int8 *ptr0;
  orc_int8 var4;
  const orc_int8 *ptr4;

  ptr0 = (orc_int8 *) ex->arrays[0];
  ptr4 = (orc_int8 *) ex->arrays[4];

  for (i = 0; i < n; i++) {
    var0 = *ptr0;
    var4 = *ptr4;
    ptr4++;
    /* 0: addusb */
    var0 = ORC_CLAMP_UB ((orc_uint8) var0 + (orc_uint8) var4);
    *ptr0 = var0;
    ptr0++;
  }

}

void
add_uint8 (guint8 * d1, const guint8 * s1, int n)
{
  OrcExecutor _ex, *ex = &_ex;
  static int p_inited = 0;
  static OrcProgram *p = 0;
  void (*func) (OrcExecutor *);

  if (!p_inited) {
    orc_once_mutex_lock ();
    if (!p_inited) {
      OrcCompileResult result;

      p = orc_program_new ();
      orc_program_set_name (p, "add_uint8");
      orc_program_set_backup_function (p, _backup_add_uint8);
      orc_program_add_destination (p, 1, "d1");
      orc_program_add_source (p, 1, "s1");

      orc_program_append (p, "addusb", ORC_VAR_D1, ORC_VAR_D1, ORC_VAR_S1);

      result = orc_program_compile (p);
    }
    p_inited = TRUE;
    orc_once_mutex_unlock ();
  }
  ex->program = p;

  ex->n = n;
  ex->arrays[ORC_VAR_D1] = d1;
  ex->arrays[ORC_VAR_S1] = (void *) s1;

  func = p->code_exec;
  func (ex);
}
#endif


/* add_float32 */
#ifdef DISABLE_ORC
void
add_float32 (float *d1, const float *s1, int n)
{
  int i;
  orc_union32 var0;
  orc_union32 *ptr0;
  orc_union32 var4;
  const orc_union32 *ptr4;

  ptr0 = (orc_union32 *) d1;
  ptr4 = (orc_union32 *) s1;

  for (i = 0; i < n; i++) {
    var0 = *ptr0;
    var4 = *ptr4;
    ptr4++;
    /* 0: addf */
    var0.f = var0.f + var4.f;
    *ptr0 = var0;
    ptr0++;
  }

}

#else
static void
_backup_add_float32 (OrcExecutor * ex)
{
  int i;
  int n = ex->n;
  orc_union32 var0;
  orc_union32 *ptr0;
  orc_union32 var4;
  const orc_union32 *ptr4;

  ptr0 = (orc_union32 *) ex->arrays[0];
  ptr4 = (orc_union32 *) ex->arrays[4];

  for (i = 0; i < n; i++) {
    var0 = *ptr0;
    var4 = *ptr4;
    ptr4++;
    /* 0: addf */
    var0.f = var0.f + var4.f;
    *ptr0 = var0;
    ptr0++;
  }

}

void
add_float32 (float *d1, const float *s1, int n)
{
  OrcExecutor _ex, *ex = &_ex;
  static int p_inited = 0;
  static OrcProgram *p = 0;
  void (*func) (OrcExecutor *);

  if (!p_inited) {
    orc_once_mutex_lock ();
    if (!p_inited) {
      OrcCompileResult result;

      p = orc_program_new ();
      orc_program_set_name (p, "add_float32");
      orc_program_set_backup_function (p, _backup_add_float32);
      orc_program_add_destination (p, 4, "d1");
      orc_program_add_source (p, 4, "s1");

      orc_program_append (p, "addf", ORC_VAR_D1, ORC_VAR_D1, ORC_VAR_S1);

      result = orc_program_compile (p);
    }
    p_inited = TRUE;
    orc_once_mutex_unlock ();
  }
  ex->program = p;

  ex->n = n;
  ex->arrays[ORC_VAR_D1] = d1;
  ex->arrays[ORC_VAR_S1] = (void *) s1;

  func = p->code_exec;
  func (ex);
}
#endif
