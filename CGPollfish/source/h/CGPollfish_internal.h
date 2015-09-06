/*
 * Internal header for the CGPollfish extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef CGPOLLFISH_INTERNAL_H
#define CGPOLLFISH_INTERNAL_H

#include "s3eTypes.h"
#include "CGPollfish.h"
#include "CGPollfish_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult CGPollfishInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult CGPollfishInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void CGPollfishTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void CGPollfishTerminate_platform();
void PollFishInit_platform(const char* apiKey, CGPollFishPosition position, int padding, const char* userId);

void PollFishHide_platform();

void PollFishShow_platform();


#endif /* !CGPOLLFISH_INTERNAL_H */