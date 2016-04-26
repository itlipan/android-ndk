# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <jni.h>
# include <android/log.h>
# include "com_example_hellojni_JniUtil.h"

# define  TAG "JniUtil From C"
# define  LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
# define  LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)

jstring
Java_com_example_hellojni_JniUtil_getPersonName
        (JNIEnv *env, jclass jclazz) {
    return (*env)->NewStringUTF(env, "Hello from JNI !  Compiled");
}


void
Java_com_example_hellojni_JniUtil_updateFilePath
        (JNIEnv *env, jclass jclazz, jstring path) {

    const char * file_path = (*env)->GetStringUTFChars(env,path,NULL);
    if(file_path != NULL){
        LOGD("from c file path is >>> %s", file_path);
    }
    FILE * file = fopen(file_path,"a+");
    if (file != NULL){
        LOGD("from c open file success" );
    }
    char data[] = "From C  JniDemo";

    int count = fwrite(data,strlen(data),1,file);
    if(count > 0){
        LOGD("from c write file success");
    }
    if(file != NULL){
        fclose(file);
    }
    (*env) -> ReleaseStringUTFChars(env,path,file_path);
}

/*JNIEXPORT jintArray JNICALL Java_ArrayTest_initIntArray(JNIEnv *env, jclass cls, int size)
{
jintArray result;
result = (*env)->NewIntArray(env, size);
if (result == NULL) {
return NULL; *//* out of memory error thrown *//*
}
int i;
// fill a temp structure to use to populate the java int array
jint fill[256];
for (i = 0; i < size; i++) {
fill[i] = 0; // put whatever logic you want to populate the values here.
}
// move from the temp structure to the java structure
(*env)->SetIntArrayRegion(env, result, 0, size, fill);
return result;
}*/

jintArray
 Java_com_example_hellojni_JniUtil_updateIntArray
(JNIEnv * env, jclass jclazz, jintArray array){
/*    jint nativeArray[5];
    (*env)->GetIntArrayRegion(env,array,0,5,nativeArray);
    int j;
    for(j = 0;j < 5;j++){
        nativeArray[j] += 5;
    }
    (*env)->SetIntArrayRegion(env,array,0,5,nativeArray);*/

    jint * data = (*env)->GetIntArrayElements(env,array,NULL);
    jsize len = (*env)->GetArrayLength(env,array);
    int j;
    for(j = 0;j < len;j++){
        data[j] += 3;
        __android_log_print(ANDROID_LOG_DEBUG, TAG, "data[j] >> %d",data[j]);
    }
    (*env)->ReleaseIntArrayElements(env,array,data,0);
    return array;
}