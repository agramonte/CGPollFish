/*
 * android-specific implementation of the CGPollfish extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "CGPollfish_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_PollFishInit;
static jmethodID g_PollFishHide;
static jmethodID g_PollFishShow;

s3eResult CGPollfishInit_platform()
{

//---------------

void native_notifyReceived(JNIEnv * env, jobject obj){
    s3eEdkCallbacksEnqueue(S3E_EXT_CGPOLLFISH_HASH, CGPOLLFISH_CALLBACK_RECEIVED);
}
void native_notifyNotAvailable(JNIEnv * env, jobject obj){
    s3eEdkCallbacksEnqueue(S3E_EXT_CGPOLLFISH_HASH, CGPOLLFISH_CALLBACK_NOTAVAILABLE);
}
void native_notifyCompleted(JNIEnv * env, jobject obj){
    s3eEdkCallbacksEnqueue(S3E_EXT_CGPOLLFISH_HASH, CGPOLLFISH_CALLBACK_COMPLETED);
}
void native_notifyOpened(JNIEnv * env, jobject obj){
    s3eEdkCallbacksEnqueue(S3E_EXT_CGPOLLFISH_HASH, CGPOLLFISH_CALLBACK_OPENED);
}
void native_notifyClosed(JNIEnv * env, jobject obj){
    s3eEdkCallbacksEnqueue(S3E_EXT_CGPOLLFISH_HASH, CGPOLLFISH_CALLBACK_CLOSED);
}
void native_notifyNotEligible(JNIEnv * env, jobject obj){
    s3eEdkCallbacksEnqueue(S3E_EXT_CGPOLLFISH_HASH, CGPOLLFISH_CALLBACK_NOTELIGIBLE);
}


    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;
    
    
    const JNINativeMethod nativeMethodDefs[] = {
        { "native_notifyReceived", "()V", (void *)&native_notifyReceived },
        { "native_notifyNotAvailable", "()V", (void *)&native_notifyNotAvailable },
        { "native_notifyCompleted", "()V", (void *)&native_notifyCompleted },
        { "native_notifyOpened", "()V", (void *)&native_notifyOpened },
        { "native_notifyClosed", "()V", (void *)&native_notifyClosed },
        { "native_notifyNotEligible", "()V", (void *)&native_notifyNotEligible },
        
    };

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("CGPollfish");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_PollFishInit = env->GetMethodID(cls, "PollFishInit", "(Ljava/lang/String;IILjava/lang/String;)V");
    if (!g_PollFishInit)
        goto fail;

    g_PollFishHide = env->GetMethodID(cls, "PollFishHide", "()V");
    if (!g_PollFishHide)
        goto fail;

    g_PollFishShow = env->GetMethodID(cls, "PollFishShow", "()V");
    if (!g_PollFishShow)
        goto fail;



    IwTrace(CGPOLLFISH, ("CGPOLLFISH init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(CGPollfish, ("One or more java methods could not be found"));
    }

    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);
    return S3E_RESULT_ERROR;

}

void CGPollfishTerminate_platform()
{ 
    // Add any platform-specific termination code here
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->DeleteGlobalRef(g_Obj);
    g_Obj = NULL;
}

void PollFishInit_platform(const char* apiKey, CGPollFishPosition position, int padding, const char* userId)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring apiKey_jstr = env->NewStringUTF(apiKey);
    jstring userId_jstr = env->NewStringUTF(userId);
    env->CallVoidMethod(g_Obj, g_PollFishInit, apiKey_jstr, position, padding, userId_jstr);
}

void PollFishHide_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_PollFishHide);
}

void PollFishShow_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_PollFishShow);
}
