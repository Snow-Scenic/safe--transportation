/**
  ******************************************************************************
  * @file    drive_int.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Jul 19 11:07:58 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "drive_int.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"




#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_drive_int
 
#undef AI_DRIVE_INT_MODEL_SIGNATURE
#define AI_DRIVE_INT_MODEL_SIGNATURE     "e46e3c208f279b27f16e0af278c81dda"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Jul 19 11:07:58 2023"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_DRIVE_INT_N_BATCHES
#define AI_DRIVE_INT_N_BATCHES         (1)




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_input_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 12288, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conversion_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 15376, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  dense_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  dense_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  dense_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  dense_10_fmt_conv_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  nl_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  nl_11_fmt_conv_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 3, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  dense_8_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 589824, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  dense_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  dense_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  dense_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  dense_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  dense_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 3, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1196, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1984, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1856, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7168, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_input_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003406889969483018f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007820198312401772f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.027903776615858078f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0746912807226181f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09708395600318909f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3161768615245819f),
    AI_PACK_INTQ_ZP(-51)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_11_fmt_conv_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0021803691051900387f, 0.002088306238874793f, 0.0017469326267018914f, 0.001877863658592105f, 0.002588542876765132f, 0.0023715279530733824f, 0.0028685410507023335f, 0.001990110147744417f, 0.001972066704183817f, 0.0022483423817902803f, 0.002173365093767643f, 0.0023434769827872515f, 0.0019078935729339719f, 0.0018964337650686502f, 0.0018498931312933564f, 0.0017885593697428703f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.5504680100712e-06f, 8.189436812244821e-06f, 6.85071654515923e-06f, 7.364171779045137e-06f, 1.0151149581361096e-05f, 9.300109923060518e-06f, 1.124918162531685e-05f, 7.804354027030058e-06f, 7.733595339232124e-06f, 8.817029083729722e-06f, 8.523001270077657e-06f, 9.190106538881082e-06f, 7.481935881514801e-06f, 7.436995474563446e-06f, 7.254483080032514e-06f, 7.013958565948997e-06f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0032511986792087555f, 0.0025938537437468767f, 0.0031264584977179766f, 0.0027116958517581224f, 0.0032149329781532288f, 0.0035137729719281197f, 0.0025222874246537685f, 0.00256323697976768f, 0.0026357818860560656f, 0.0025234140921384096f, 0.002349758753553033f, 0.0022718363907188177f, 0.002185262506827712f, 0.0022339820861816406f, 0.002715272130444646f, 0.0022818930447101593f, 0.002257365733385086f, 0.002862317953258753f, 0.002446090104058385f, 0.002225648844614625f, 0.002611435018479824f, 0.0042589884251356125f, 0.0021192855201661587f, 0.0027941714506596327f, 0.0022448573727160692f, 0.0032294506672769785f, 0.0021306483540683985f, 0.00321548362262547f, 0.0027259045746177435f, 0.002948789158836007f, 0.003579086856916547f, 0.004521103575825691f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.1076475857407786e-05f, 8.836974302539602e-06f, 1.0651499906089157e-05f, 9.23844982025912e-06f, 1.0952922821161337e-05f, 1.1971037565672304e-05f, 8.593156053393614e-06f, 8.732666174182668e-06f, 8.979818630905356e-06f, 8.596994121035095e-06f, 8.005369636521209e-06f, 7.739896318526007e-06f, 7.44494900573045e-06f, 7.610931334056659e-06f, 9.25063341128407e-06f, 7.774158802931197e-06f, 7.690596248721704e-06f, 9.751602192409337e-06f, 8.333559890161268e-06f, 7.582540547446115e-06f, 8.896871804608963e-06f, 1.4509904758597258e-05f, 7.220172392408131e-06f, 9.51943457039306e-06f, 7.647981874470133e-06f, 1.1002382962033153e-05f, 7.2588845796417445e-06f, 1.0954799108731095e-05f, 9.286856766266283e-06f, 1.0046200259239413e-05f, 1.2193555448902771e-05f, 1.5402902135974728e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003169147064909339f, 0.002756755566224456f, 0.002692026784643531f, 0.0030174802523106337f, 0.0024936143308877945f, 0.003406030125916004f, 0.0038991954643279314f, 0.0027210095431655645f, 0.0032399226911365986f, 0.002552331192418933f, 0.0034657856449484825f, 0.0029646980110555887f, 0.0029349271208047867f, 0.002967357635498047f, 0.0023774546571075916f, 0.002485384698957205f, 0.002643873216584325f, 0.0034571827854961157f, 0.002045416971668601f, 0.003342960961163044f, 0.0023053919430822134f, 0.0034659425728023052f, 0.0026496148202568293f, 0.0027835131622850895f, 0.0031231401953846216f, 0.002255611354485154f, 0.0033206380903720856f, 0.002230806741863489f, 0.0025069857947528362f, 0.0029522080440074205f, 0.003081008093431592f, 0.002816369291394949f, 0.0028753485530614853f, 0.002966909669339657f, 0.0031908454839140177f, 0.003381249960511923f, 0.0024899612180888653f, 0.0016494571464136243f, 0.0021140691824257374f, 0.0020748001988977194f, 0.003141028108075261f, 0.002327573951333761f, 0.002290552482008934f, 0.0036738987546414137f, 0.0031363361049443483f, 0.003153813537210226f, 0.003106991294771433f, 0.0034209880977869034f, 0.0032580040860921144f, 0.002634634729474783f, 0.0030911248177289963f, 0.0032224918249994516f, 0.003999999258667231f, 0.0031840824522078037f, 0.003131467616185546f, 0.0022768680937588215f, 0.0030530192889273167f, 0.002722008153796196f, 0.0025732519570738077f, 0.003645308082923293f, 0.0030685928650200367f, 0.0028062083292752504f, 0.00260968878865242f, 0.0028832396492362022f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.4783357730484568e-05f, 2.155837501049973e-05f, 2.1052183001302183e-05f, 2.359729478484951e-05f, 1.9500557755236514e-05f, 2.6635831090970896e-05f, 3.0492481528199278e-05f, 2.1278834537952207e-05f, 2.5336838007206097e-05f, 1.9959736164310016e-05f, 2.710313128773123e-05f, 2.3184526071418077e-05f, 2.295171179866884e-05f, 2.320532439625822e-05f, 1.8592167180031538e-05f, 1.943620191013906e-05f, 2.0675612177001312e-05f, 2.7035854145651683e-05f, 1.5995567082427442e-05f, 2.6142617571167648e-05f, 1.802862243494019e-05f, 2.7104359105578624e-05f, 2.0720513930427842e-05f, 2.1767624275526032e-05f, 2.4423576178378426e-05f, 1.7639327779761516e-05f, 2.5968049158109352e-05f, 1.7445350749767385e-05f, 1.9605125999078155e-05f, 2.3086851797415875e-05f, 2.4094093532767147e-05f, 2.2024565623723902e-05f, 2.2485795852844603e-05f, 2.3201822841656394e-05f, 2.4953043975983746e-05f, 2.644204505486414e-05f, 1.9471990526653826e-05f, 1.2899082321382593e-05f, 1.6532439985894598e-05f, 1.622534909984097e-05f, 2.4563461920479313e-05f, 1.820209035940934e-05f, 1.791257454897277e-05f, 2.873061748687178e-05f, 2.452677108522039e-05f, 2.466344813001342e-05f, 2.4297287382069044e-05f, 2.675280484254472e-05f, 2.5478237148490734e-05f, 2.0603365555871278e-05f, 2.417320865788497e-05f, 2.5200524760293774e-05f, 3.128078606096096e-05f, 2.490015685907565e-05f, 2.448869781801477e-05f, 1.780555976438336e-05f, 2.3875216356827877e-05f, 2.128664345946163e-05f, 2.0123339709243737e-05f, 2.8507032766356133e-05f, 2.3997004973352887e-05f, 2.1945104890619405e-05f, 2.0408284399309196e-05f, 2.2547505068359897e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003988723270595074f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011130044003948569f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003788221860304475f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002829471486620605f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0033095034305006266f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003212996816728264f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003406889969483018f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007820198312401772f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.027903776615858078f),
    AI_PACK_INTQ_ZP(-128)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_input_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 64, 64), AI_STRIDE_INIT(4, 1, 1, 3, 192),
  1, &conv2d_input_output_array, &conv2d_input_output_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 64, 64), AI_STRIDE_INIT(4, 1, 1, 3, 192),
  1, &conversion_0_output_array, &conversion_0_output_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 31, 31), AI_STRIDE_INIT(4, 1, 1, 16, 496),
  1, &conv2d_1_output_array, &conv2d_1_output_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 14, 14), AI_STRIDE_INIT(4, 1, 1, 32, 448),
  1, &conv2d_3_output_array, &conv2d_3_output_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 6, 6), AI_STRIDE_INIT(4, 1, 1, 64, 384),
  1, &conv2d_5_output_array, &conv2d_5_output_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output0, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 2304, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2304, 2304),
  1, &conv2d_5_output_array, &conv2d_5_output_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  dense_8_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &dense_8_output_array, &dense_8_output_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  dense_9_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &dense_9_output_array, &dense_9_output_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  dense_10_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3, 3),
  1, &dense_10_output_array, &dense_10_output_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  dense_10_fmt_conv_output, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_10_fmt_conv_output_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  nl_11_output, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &nl_11_output_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  nl_11_fmt_conv_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3, 3),
  1, &nl_11_fmt_conv_output_array, &nl_11_fmt_conv_output_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 16), AI_STRIDE_INIT(4, 1, 3, 9, 27),
  1, &conv2d_1_weights_array, &conv2d_1_weights_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_1_bias_array, &conv2d_1_bias_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 32), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &conv2d_3_weights_array, &conv2d_3_weights_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_3_bias_array, &conv2d_3_bias_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 64), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_5_weights_array, &conv2d_5_weights_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_5_bias_array, &conv2d_5_bias_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  dense_8_weights, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 2304, 256, 1, 1), AI_STRIDE_INIT(4, 1, 2304, 589824, 589824),
  1, &dense_8_weights_array, &dense_8_weights_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  dense_8_bias, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &dense_8_bias_array, &dense_8_bias_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  dense_9_weights, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 256, 128, 1, 1), AI_STRIDE_INIT(4, 1, 256, 32768, 32768),
  1, &dense_9_weights_array, &dense_9_weights_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  dense_9_bias, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_9_bias_array, &dense_9_bias_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  dense_10_weights, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 1, 1), AI_STRIDE_INIT(4, 1, 128, 384, 384),
  1, &dense_10_weights_array, &dense_10_weights_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  dense_10_bias, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_10_bias_array, &dense_10_bias_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch0, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 1196, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1196, 1196),
  1, &conv2d_1_scratch0_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch1, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 62, 2), AI_STRIDE_INIT(4, 1, 1, 16, 992),
  1, &conv2d_1_scratch1_array, &conv2d_1_scratch1_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 6144, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6144, 6144),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch1, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 29, 2), AI_STRIDE_INIT(4, 1, 1, 32, 928),
  1, &conv2d_3_scratch1_array, &conv2d_3_scratch1_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch0, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 7168, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7168, 7168),
  1, &conv2d_5_scratch0_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch1, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 12, 2), AI_STRIDE_INIT(4, 1, 1, 64, 768),
  1, &conv2d_5_scratch1_array, &conv2d_5_scratch1_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_11_fmt_conv_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_11_fmt_conv_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_11_fmt_conv_layer, 11,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &nl_11_fmt_conv_chain,
  NULL, &nl_11_fmt_conv_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_10_fmt_conv_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_11_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_11_layer, 11,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &nl_11_chain,
  NULL, &nl_11_fmt_conv_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_10_fmt_conv_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_10_fmt_conv_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_10_fmt_conv_layer, 10,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &dense_10_fmt_conv_chain,
  NULL, &nl_11_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_10_weights, &dense_10_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_10_layer, 10,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &dense_10_chain,
  NULL, &dense_10_fmt_conv_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_9_weights, &dense_9_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_9_layer, 9,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &dense_9_chain,
  NULL, &dense_10_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_8_weights, &dense_8_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_8_layer, 8,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &dense_8_chain,
  NULL, &dense_9_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_5_weights, &conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_5_scratch0, &conv2d_5_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_5_layer, 6,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_SSSA_ch,
  &conv2d_5_chain,
  NULL, &dense_8_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_ap_array_integer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_3_scratch0, &conv2d_3_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 4,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_SSSA_ch,
  &conv2d_3_chain,
  NULL, &conv2d_5_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_ap_array_integer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_1_scratch0, &conv2d_1_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 2,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_SSSA_ch,
  &conv2d_1_chain,
  NULL, &conv2d_3_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_ap_array_integer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_input_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_0_layer, 0,
  NL_TYPE, 0x0, NULL,
  nl, node_convert_integer,
  &conversion_0_chain,
  NULL, &conv2d_1_layer, AI_STATIC, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 648444, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 23856, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_DRIVE_INT_IN_NUM, &conv2d_input_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_DRIVE_INT_OUT_NUM, &nl_11_fmt_conv_output),
  &conversion_0_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool drive_int_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)
  AI_UNUSED(net_ctx)

  ai_ptr activations_map[1] = AI_C_ARRAY_INIT;

  if (ai_platform_get_activations_map(activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    conv2d_input_output_array.data = AI_PTR(NULL);
    conv2d_input_output_array.data_start = AI_PTR(NULL);
    conversion_0_output_array.data = AI_PTR(activations_map[0] + 4080);
    conversion_0_output_array.data_start = AI_PTR(activations_map[0] + 4080);
    conv2d_1_output_array.data = AI_PTR(activations_map[0] + 480);
    conv2d_1_output_array.data_start = AI_PTR(activations_map[0] + 480);
    conv2d_3_output_array.data = AI_PTR(activations_map[0] + 0);
    conv2d_3_output_array.data_start = AI_PTR(activations_map[0] + 0);
    conv2d_5_output_array.data = AI_PTR(activations_map[0] + 14976);
    conv2d_5_output_array.data_start = AI_PTR(activations_map[0] + 14976);
    dense_8_output_array.data = AI_PTR(activations_map[0] + 0);
    dense_8_output_array.data_start = AI_PTR(activations_map[0] + 0);
    dense_9_output_array.data = AI_PTR(activations_map[0] + 256);
    dense_9_output_array.data_start = AI_PTR(activations_map[0] + 256);
    dense_10_output_array.data = AI_PTR(activations_map[0] + 0);
    dense_10_output_array.data_start = AI_PTR(activations_map[0] + 0);
    dense_10_fmt_conv_output_array.data = AI_PTR(activations_map[0] + 4);
    dense_10_fmt_conv_output_array.data_start = AI_PTR(activations_map[0] + 4);
    nl_11_output_array.data = AI_PTR(activations_map[0] + 16);
    nl_11_output_array.data_start = AI_PTR(activations_map[0] + 16);
    nl_11_fmt_conv_output_array.data = AI_PTR(NULL);
    nl_11_fmt_conv_output_array.data_start = AI_PTR(NULL);
    conv2d_1_scratch0_array.data = AI_PTR(activations_map[0] + 16368);
    conv2d_1_scratch0_array.data_start = AI_PTR(activations_map[0] + 16368);
    conv2d_1_scratch1_array.data = AI_PTR(activations_map[0] + 17564);
    conv2d_1_scratch1_array.data_start = AI_PTR(activations_map[0] + 17564);
    conv2d_3_scratch0_array.data = AI_PTR(activations_map[0] + 15856);
    conv2d_3_scratch0_array.data_start = AI_PTR(activations_map[0] + 15856);
    conv2d_3_scratch1_array.data = AI_PTR(activations_map[0] + 22000);
    conv2d_3_scratch1_array.data_start = AI_PTR(activations_map[0] + 22000);
    conv2d_5_scratch0_array.data = AI_PTR(activations_map[0] + 6272);
    conv2d_5_scratch0_array.data_start = AI_PTR(activations_map[0] + 6272);
    conv2d_5_scratch1_array.data = AI_PTR(activations_map[0] + 13440);
    conv2d_5_scratch1_array.data_start = AI_PTR(activations_map[0] + 13440);
    
    return true;
  }
  return false;
}



AI_DECLARE_STATIC
ai_bool drive_int_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)
  AI_UNUSED(net_ctx)

  ai_ptr weights_map[1] = AI_C_ARRAY_INIT;

  if (ai_platform_get_weights_map(weights_map, 1, params)) {
    /* Updating weights with array addresses */
    
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(weights_map[0] + 0);
    conv2d_1_weights_array.data_start = AI_PTR(weights_map[0] + 0);
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(weights_map[0] + 432);
    conv2d_1_bias_array.data_start = AI_PTR(weights_map[0] + 432);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(weights_map[0] + 496);
    conv2d_3_weights_array.data_start = AI_PTR(weights_map[0] + 496);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(weights_map[0] + 5104);
    conv2d_3_bias_array.data_start = AI_PTR(weights_map[0] + 5104);
    conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_weights_array.data = AI_PTR(weights_map[0] + 5232);
    conv2d_5_weights_array.data_start = AI_PTR(weights_map[0] + 5232);
    conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_bias_array.data = AI_PTR(weights_map[0] + 23664);
    conv2d_5_bias_array.data_start = AI_PTR(weights_map[0] + 23664);
    dense_8_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_8_weights_array.data = AI_PTR(weights_map[0] + 23920);
    dense_8_weights_array.data_start = AI_PTR(weights_map[0] + 23920);
    dense_8_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_8_bias_array.data = AI_PTR(weights_map[0] + 613744);
    dense_8_bias_array.data_start = AI_PTR(weights_map[0] + 613744);
    dense_9_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_9_weights_array.data = AI_PTR(weights_map[0] + 614768);
    dense_9_weights_array.data_start = AI_PTR(weights_map[0] + 614768);
    dense_9_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_9_bias_array.data = AI_PTR(weights_map[0] + 647536);
    dense_9_bias_array.data_start = AI_PTR(weights_map[0] + 647536);
    dense_10_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_10_weights_array.data = AI_PTR(weights_map[0] + 648048);
    dense_10_weights_array.data_start = AI_PTR(weights_map[0] + 648048);
    dense_10_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_10_bias_array.data = AI_PTR(weights_map[0] + 648432);
    dense_10_bias_array.data_start = AI_PTR(weights_map[0] + 648432);
    return true;
  }
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/
AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_drive_int_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_DRIVE_INT_MODEL_NAME,
      .model_signature   = AI_DRIVE_INT_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 8934060,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_bool ai_drive_int_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_DRIVE_INT_MODEL_NAME,
      .model_signature   = AI_DRIVE_INT_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 8934060,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_drive_int_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_drive_int_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_drive_int_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_drive_int_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= drive_int_configure_weights(net_ctx, params);
  ok &= drive_int_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_drive_int_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_drive_int_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_DRIVE_INT_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

