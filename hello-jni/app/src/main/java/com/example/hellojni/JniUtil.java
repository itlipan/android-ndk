package com.example.hellojni;

/**
 * Created by Lee on 2016/4/26.
 */
public class JniUtil {

    static {
        System.loadLibrary("jni-demo");
    }

    public static native String getPersonName();

    public static  native  void  updateFilePath(String path);

    public static  native  int[]  updateIntArray(int[] array);

}
