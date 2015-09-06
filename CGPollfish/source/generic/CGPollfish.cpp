/*
Generic implementation of the CGPollfish extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "CGPollfish_internal.h"
s3eResult CGPollfishInit()
{
    //Add any generic initialisation code here
    return CGPollfishInit_platform();
}

void CGPollfishTerminate()
{
    //Add any generic termination code here
    CGPollfishTerminate_platform();
}

void PollFishInit(const char* apiKey, CGPollFishPosition position, int padding, const char* userId)
{
	PollFishInit_platform(apiKey, position, padding, userId);
}

void PollFishHide()
{
	PollFishHide_platform();
}

void PollFishShow()
{
	PollFishShow_platform();
}
