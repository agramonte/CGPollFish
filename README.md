# CGPollFish
Marmalade PollFish Extension

I am using the Google Play version of the jar.

I am in no way associated or employed by PollFish other than the fact that I use the service. Information about their service can be found here: http://pollfish.com/

How to use the extension:
1. Add the extension to your project by adding it to the subproject section of the .mbk.

2. Close and reopen your project.

3. Import CGPollfish.h.

4. Call PollFishInit(“<your api key>”, <one of the position from the enum CGPollFishPosition>, <padding from position number>, “<not implemented. tested with a random string, but null should work>”). Make sure you check if the extension is available before making this call: CGPollfishAvailable();.

typedef enum CGPollFishPosition
{
    POSITION_TOP_LEFT   = 1,
    POSITION_BOTTOM_LEFT = 2,
    POSITION_MIDDLE_LEFT = 3,
    POSITION_TOP_RIGHT = 4,
    POSITION_BOTTOM_RIGHT = 5,
    POSITION_MIDDLE_RIGHT = 6
} CGPollFishPosition;


Optional:
1. The following callbacks have been implemented. I have only tested Completed.
CGPOLLFISH_CALLBACK_RECEIVED
CGPOLLFISH_CALLBACK_NOTAVAILABLE
CGPOLLFISH_CALLBACK_COMPLETED
CGPOLLFISH_CALLBACK_OPENED
CGPOLLFISH_CALLBACK_CLOSED
CGPOLLFISH_CALLBACK_NOTELIGIBLE
CGPOLLFISH_CALLBACK_MAX

