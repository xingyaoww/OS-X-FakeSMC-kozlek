/*
 *  Radeon.h
 *  HWSensors
 *
 *  Created by Sergey on 20.12.10.
 *  Copyright 2010 Slice. All rights reserved.
 *  Copyright 2013 kozlek. All rights reserved.
 *
 */

#include "FakeSMCPlugin.h"
#include "radeon.h"

class EXPORT RadeonSensors : public FakeSMCPlugin
{
    OSDeclareDefaultStructors(RadeonSensors)    
	
private:
    radeon_device           card;
    
    IOWorkLoop*             workloop;
    IOTimerEventSource*     timerEventSource;
    int                     probeCounter;
    
    IOReturn                probeEvent();
    bool                    activate();
    
protected:	
    virtual float       getSensorValue(FakeSMCSensor *sensor);
    
public:
    virtual bool        start(IOService *provider);
    virtual void		stop(IOService *provider);
};
