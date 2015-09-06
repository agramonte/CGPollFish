/*
java implementation of the CGPollfish extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;
import android.util.*;
import android.view.*;
import com.pollfish.main.PollFish;
import com.pollfish.constants.Position;
import com.pollfish.interfaces.PollfishSurveyCompletedListener;
import com.pollfish.interfaces.PollfishSurveyReceivedListener;
import com.pollfish.interfaces.PollfishSurveyNotAvailableListener;
import com.pollfish.interfaces.PollfishOpenedListener;
import com.pollfish.interfaces.PollfishClosedListener;
import com.pollfish.interfaces.PollfishUserNotEligibleListener;

class CGPollfish
{
    
    public final static int POSITION_TOP_LEFT   = 1;
    public final static int POSITION_BOTTOM_LEFT = 2;
    public final static int POSITION_MIDDLE_LEFT = 3;
    public final static int POSITION_TOP_RIGHT = 4;
    public final static int POSITION_BOTTOM_RIGHT = 5;
    public final static int POSITION_MIDDLE_RIGHT = 6;
    
    public void PollFishInit(String apiKey, int position, int padding, String userId) {
        Position currentPosition;

        switch (position) {
            case 1: currentPosition = Position.TOP_LEFT;
                break;
            case 2: currentPosition = Position.BOTTOM_LEFT;
                break;
            case 3: currentPosition = Position.MIDDLE_LEFT;
                break;
            case 4: currentPosition = Position.TOP_RIGHT;
                break;
            case 5: currentPosition = Position.BOTTOM_RIGHT;
                break;
            default: currentPosition = Position.MIDDLE_RIGHT;
                break;
        }
       
        ViewGroup rootView = (ViewGroup) LoaderActivity.m_Activity.findViewById(android.R.id.content);
        
        
        PollFish.init(LoaderActivity.m_Activity, apiKey, currentPosition, padding,
                      new PollfishSurveyReceivedListener() {
            @Override
            public void onPollfishSurveyReceived(boolean playfulSurvey, int surveyPrice) {
                native_notifyReceived();
            }
                    },
                      
                      new PollfishSurveyNotAvailableListener() {
            @Override
            public void onPollfishSurveyNotAvailable() {
                native_notifyNotAvailable();
                
            }
            
                    },
                      
                      new PollfishSurveyCompletedListener() {
            
            @Override
            public void onPollfishSurveyCompleted(boolean playfulSurvey, int surveyPrice) {
                native_notifyCompleted();
            }
        
                      },
                      
                      new PollfishOpenedListener(){
            @Override
            public void onPollfishOpened() {
                native_notifyOpened();
            }
                      },
                      
                      new PollfishClosedListener(){
            @Override
            public void onPollfishClosed() {
                native_notifyClosed();
            }
                      },
                      
                      new PollfishUserNotEligibleListener(){
            @Override
            public void onUserNotEligible() {
                native_notifyNotEligible();
                              
            }
                      },
                      rootView);
        
    }
    public void PollFishHide()
    {
        PollFish.hide();
    }
    public void PollFishShow()
    {
        PollFish.show();
        
    }


}

    
    
    ////////////////////////////////////////////////////////////////
    // Native interface
    public static native void native_notifyReceived();
    public static native void native_notifyNotAvailable();
    public static native void native_notifyCompleted();
    public static native void native_notifyOpened();
    public static native void native_notifyClosed();
    public static native void native_notifyNotEligible();
    ////////////////////////////////////////////////////////////////
