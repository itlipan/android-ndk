# A simple test for the minimal standard C++ library
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := maexec
LOCAL_SRC_FILES := maexec.c
TARGET_ARCH := arm
TARGET_PLATFORM := android-15
TARGET_ARCH_ABI := armeabi-v7a

include $(BUILD_EXECUTABLE)
