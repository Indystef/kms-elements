
#ifndef _KMS_JACK_VADER_H_
#define _KMS_JACK_VADER_H_

#include <gst/video/gstvideofilter.h>
#include <opencv/cv.h>

G_BEGIN_DECLS

#define KMS_TYPE_JACK_VADER   (kms_jack_vader_get_type())
#define KMS_JACK_VADER(obj)   (G_TYPE_CHECK_INSTANCE_CAST((obj),KMS_TYPE_JACK_VADER,KmsJackVader))
#define KMS_JACK_VADER_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass),KMS_TYPE_JACK_VADER,KmsJackVaderClass))
#define KMS_IS_JACK_VADER(obj)   (G_TYPE_CHECK_INSTANCE_TYPE((obj),KMS_TYPE_JACK_VADER))
#define KMS_IS_JACK_VADER_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass),KMS_TYPE_JACK_VADER))

typedef struct _KmsJackVader KmsJackVader;
typedef struct _KmsJackVaderClass KmsJackVaderClass;

struct _KmsJackVader
{
  GstVideoFilter base;

  IplImage *cvImage,  *originalCostume1, *originalCostume2,
  *costume3Channels1, *costume3Channels2, *costume1Mask,
  *costume2Mask;

  gboolean show_debug_info;
  const char *images_path;

  CvHaarClassifierCascade * pCascadeFace;
  CvMemStorage * pStorageFace;
  CvSeq * pFaceRectSeq;
};

struct _KmsJackVaderClass
{
  GstVideoFilterClass base_facedetector_class;
};

GType kms_jack_vader_get_type (void);

gboolean kms_jack_vader_plugin_init (GstPlugin * plugin);

G_END_DECLS

#endif  /* _KMS_JACK_VADER_H_ */
