//
// Created by lxf52 on 2016/12/3.
//
#include "thanatos_ndkccalljava_JNI.h"
#include <stdlib.h>
#include <stdio.h>
#include <android/log.h>
//定义TAG之后，我们可以在LogCat通过TAG过滤出NDK打印的日志
#define TAG "thanatos"
// 定义info信息
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)
// 定义debug信息
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
// 定义error信息
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
// 定义error信息
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)
/**
 * 让c代码调用JNI中的 add(******)方法
 */
JNIEXPORT void JNICALL Java_thanatos_ndkccalljava_JNI_callBackAdd
  (JNIEnv * env, jobject obj){
      //1.得到字节码  jclass      (*FindClass)(JNIEnv*, const char*);  第二个参数是类的名字（加包名）
      jclass  clazz=(*env)->FindClass(env,"thanatos/ndkccalljava/JNI");
      //2.得到方法
      // jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
     //第二个参数是方法名   第三个参数是方法的签名
      jmethodID methodId=(*env)->GetMethodID(env,clazz,"add","(II)I");
      //3.实例化对象   jobject     (*AllocObject)(JNIEnv*, jclass);
      jobject jobject1=(*env)->AllocObject(env,clazz);
      //4.调用方法    jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
      jint  value=(*env)->CallIntMethod(env,jobject1,methodId,9,1);
        LOGW("value===%d\n",value);

  };
