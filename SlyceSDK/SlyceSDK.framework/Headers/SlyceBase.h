#ifndef SlyceBase_h
#define SlyceBase_h

#if !defined(SLYCE_SDK_EXPORT)
#  define SLYCE_SDK_EXPORT __attribute__((visibility("default")))
#endif /* !defined(SLYCE_SDK_EXPORT) */

#if !defined(SLYCE_SDK_EXTERN)
#  if defined(__cplusplus)
#   define SLYCE_SDK_EXTERN extern "C"
#  else
#   define SLYCE_SDK_EXTERN extern
#  endif
#endif /* !defined(SLYCE_SDK_EXTERN) */

#if !defined(SLYCE_SDK_BOXABLE)
#  if defined(__has_attribute) && __has_attribute(objc_boxable)
#    define SLYCE_SDK_BOXABLE __attribute__((objc_boxable))
#  else
#    define SLYCE_SDK_BOXABLE
#  endif
#endif /* !defined(SLYCE_SDK_BOXABLE) */

#if !defined(SLYCE_SDK_INLINE)
#  if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#    define SLYCE_SDK_INLINE static inline
#  elif defined(__cplusplus)
#    define SLYCE_SDK_INLINE /* __cplusplus */ static inline // the __cplusplus broke everything
#  elif defined(__GNUC__)
#    define SLYCE_SDK_INLINE static __inline__
#  else
#    define SLYCE_SDK_INLINE static
#  endif
#endif /* SLYCE_SDK_INLINE */

#endif /* SlyceBase_h */


