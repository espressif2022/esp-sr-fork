#pragma once
#include "esp_wn_iface.h"

//Contains declarations of all available speech recognion models. Pair this up with the right coefficients and you have a model that can recognize
//a specific phrase or word.

extern const esp_wn_iface_t esp_sr_wakenet5_quantized;
extern const esp_wn_iface_t esp_sr_wakenet7_quantized;
extern const esp_wn_iface_t esp_sr_wakenet7_quantized8;

/*
 Configure network to use based on what's selected in menuconfig.
*/
#if CONFIG_SR_MODEL_WN5_QUANT
#define WAKENET_MODEL esp_sr_wakenet5_quantized
#elif CONFIG_SR_MODEL_WN7_QUANT
#define WAKENET_MODEL esp_sr_wakenet7_quantized
#elif CONFIG_SR_MODEL_WN7_QUANT8
#define WAKENET_MODEL esp_sr_wakenet7_quantized8
#else
#error No valid neural network model selected.
#endif

/*
 Configure wake word to use based on what's selected in menuconfig.
*/
#if CONFIG_SR_WN5_HILEXIN & CONFIG_SR_MODEL_WN5_QUANT
#include "hilexin_wn5.h"
#define WAKENET_COEFF get_coeff_hilexin_wn5

#elif CONFIG_SR_WN5X2_HILEXIN & CONFIG_SR_MODEL_WN5_QUANT
#include "hilexin_wn5X2.h"
#define WAKENET_COEFF get_coeff_hilexin_wn5X2

#elif CONFIG_SR_WN5X3_HILEXIN & CONFIG_SR_MODEL_WN5_QUANT
#include "hilexin_wn5X3.h"
#define WAKENET_COEFF get_coeff_hilexin_wn5X3

#elif CONFIG_SR_WN5_NIHAOXIAOZHI & CONFIG_SR_MODEL_WN5_QUANT
#include "nihaoxiaozhi_wn5.h"
#define WAKENET_COEFF get_coeff_nihaoxiaozhi_wn5

#elif CONFIG_SR_WN5X2_NIHAOXIAOZHI & CONFIG_SR_MODEL_WN5_QUANT
#include "nihaoxiaozhi_wn5X2.h"
#define WAKENET_COEFF get_coeff_nihaoxiaozhi_wn5X2

#elif CONFIG_SR_WN5X3_NIHAOXIAOZHI & CONFIG_SR_MODEL_WN5_QUANT
#include "nihaoxiaozhi_wn5X3.h"
#define WAKENET_COEFF get_coeff_nihaoxiaozhi_wn5X3

#elif CONFIG_SR_WN5X3_NIHAOXIAOXIN & CONFIG_SR_MODEL_WN5_QUANT
#include "nihaoxiaoxin_wn5X3.h"
#define WAKENET_COEFF get_coeff_nihaoxiaoxin_wn5X3

#elif CONFIG_SR_WN5X3_HIJESON & CONFIG_SR_MODEL_WN5_QUANT
#include "hijeson_wn5X3.h"
#define WAKENET_COEFF get_coeff_hijeson_wn5X3

#elif CONFIG_SR_WN5_CUSTOMIZED_WORD
#include "customized_word_wn5.h"
#define WAKENET_COEFF get_coeff_customized_word_wn5

#elif CONFIG_SR_WN7_CUSTOMIZED_WORD
#include "customized_word_wn7.h"
#define WAKENET_COEFF get_coeff_customized_word_wn7

#elif CONFIG_SR_WN7_XIAOAITONGXUE & CONFIG_SR_MODEL_WN7_QUANT
#include "xiaoaitongxue_wn7.h"
#define WAKENET_COEFF get_coeff_xiaoaitongxue_wn7

#elif CONFIG_SR_WN7_XIAOAITONGXUE & CONFIG_SR_MODEL_WN7_QUANT8
#include "xiaoaitongxue_wn7_q8.h"
#define WAKENET_COEFF get_coeff_xiaoaitongxue_wn7_q8

#elif CONFIG_SR_WN7_HILEXIN & CONFIG_SR_MODEL_WN7_QUANT
#include "hilexin_wn7.h"
#define WAKENET_COEFF get_coeff_hilexin_wn7

#elif CONFIG_SR_WN7_HILEXIN & CONFIG_SR_MODEL_WN7_QUANT8
#include "hilexin_wn7_q8.h"
#define WAKENET_COEFF get_coeff_hilexin_wn7_q8

#elif CONFIG_SR_WN7_ALEXA & CONFIG_SR_MODEL_WN7_QUANT
#include "alexa_wn7.h"
#define WAKENET_COEFF get_coeff_alexa_wn7

#elif CONFIG_SR_WN7_ALEXA & CONFIG_SR_MODEL_WN7_QUANT8
#include "alexa_wn7_q8.h"
#define WAKENET_COEFF get_coeff_alexa_wn7_q8

#else
#error No valid wake word selected.
#endif


/* example

static const sr_model_iface_t *model = &WAKENET_MODEL;

//Initialize wakeNet model data
static model_iface_data_t *model_data=model->create(DET_MODE_90);

//Set parameters of buffer
int audio_chunksize=model->get_samp_chunksize(model_data);
int frequency = model->get_samp_rate(model_data);
int16_t *buffer=malloc(audio_chunksize*sizeof(int16_t));

//Detect
int r=model->detect(model_data, buffer);
if (r>0) {
    printf("Detection triggered output %d.\n",  r);
}

//Destroy model
model->destroy(model_data)

*/
