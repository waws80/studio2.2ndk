package thanatos.ndkccalljava;

import android.util.Log;


/**
 * Created by lxf52 on 2016/12/3.
 */

public class JNI {

    private static final String TAG="thanatos";

    static {
        System.loadLibrary("ccalljava");
    }

    public native void callBackAdd();

    public native void callBackFromJava();

    public native void callBackPrintString();

    public native void callBackSayHello();

    public int add(int x,int y){
        Log.w(TAG, "add: x=="+x+"  y=="+y );
        return  x+y;
    }

    public void helloFromJava(){
        Log.w(TAG, "helloFromJava: " );
    }

    public void printString(String s){
        Log.w(TAG, "printString: c中输入的："+s );
    }

    public static void sayHello(){
        Log.w(TAG, "sayHello: " );
    }
}
