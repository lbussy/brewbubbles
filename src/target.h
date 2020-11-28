/* Copyright (C) 2019-2020 Lee C. Bussy (@LBussy)

This file is part of Lee Bussy's Brew Bubbles (brew-bubbles).

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

#ifndef _URLTARGET_H
#define _URLTARGET_H

#include "pushtarget.h"
#include "pushhelper.h"
#include "jsonconfig.h"
#include <LCBUrl.h>
#include <ArduinoLog.h>
#include <Arduino.h>

class Target
{
private:
    // Singleton Declarations
    Target() {}
    static Target *single;
    // External Declarations
    PushTarget *target;
    // Private Methods

    // Private Properties

    /////////////////////////////////////////////////////////////////////
    //  Configure Target - Below are configuration items per target type
    /////////////////////////////////////////////////////////////////////

    // Enable target and target name
    const bool target_enabled = true;
    String target_name = "URL Target";
    //
    // Check return body for success
    const bool checkbody_enabled = false;
    String checkbody_name = "";
    //
    // Turn JSON points on/off and provide JSON field name per target type
    //
    const bool apiname_enabled = true;
    String apiname_name = "api_name";
    //
    const bool bubname_enabled = true;
    String bubname_name = "name";
    //
    const bool bpm_enabled = true;
    String bpm_name = "bpm";
    //
    const bool ambienttemp_enabled = true;
    String ambienttemp_name = "ambient";
    //
    const bool vesseltemp_enabled = true;
    String vesseltemp_name = "temp";
    //
    const bool tempformat_enabled = true;
    String tempformat_name = "temp_unit";
    //
    // Main URL for endpoint
    String targeturl = "";
    //
    const bool apikey_enabled = true;
    String apikey_name = ""; // Will pick this up from config

    /////////////////////////////////////////////////////////////////////
    //  Configure Target - Above are configuration items per target type
    /////////////////////////////////////////////////////////////////////

public:
    // Singleton Declarations
    static Target *getInstance();
    ~Target() { single = NULL; }
    // External Declarations

    // Public Methods
    bool push();
    // Public Properties
};

extern struct Config config;

#endif // _URLTARGET_H
