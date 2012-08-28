//
//  Created by David Rodrigues on 28/08/12.
//  Copyright (c) 2012 n/a. All rights reserved.
//

#include <stdio.h>

#include "macrologger.h"

int main(int argc, const char * argv[]) {
    
    LOG_DEBUG("Maybe i can touch this button...");
    
    LOG_INFO("Pressure is dropping...");
    
    LOG_ERROR("Houston we have a problem!");
    
    return 0;
}
