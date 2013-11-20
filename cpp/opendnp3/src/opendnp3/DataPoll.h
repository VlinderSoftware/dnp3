
//
// Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
// more contributor license agreements. See the NOTICE file distributed
// with this work for additional information regarding copyright ownership.
// Green Energy Corp licenses this file to you under the Apache License,
// Version 2.0 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// This file was forked on 01/01/2013 by Automatak, LLC and modifications
// have been made to this file. Automatak, LLC licenses these modifications to
// you under the terms of the License.
//

#ifndef __DATA_POLL_H_
#define __DATA_POLL_H_

#include "MasterTaskBase.h"

#include <openpal/Visibility.h>

namespace opendnp3
{

class IMeasurementHandler;

/**
 * Base class for all data acquistion polls
 */
class DLL_LOCAL DataPoll : public MasterTaskBase
{
public:

	DataPoll(openpal::Logger&, IMeasurementHandler*);

private:

	void ReadData(const APDU&);

	//Implement MasterTaskBase
	TaskResult _OnPartialResponse(const APDU&);
	TaskResult _OnFinalResponse(const APDU&);

	IMeasurementHandler* mpMeasurementHandler;

};

/** Task that acquires class data from the outstation
*/
class DLL_LOCAL ClassPoll : public DataPoll
{
public:

	ClassPoll(openpal::Logger&, IMeasurementHandler*);

	void Set(int aClassMask);

	//Implement MasterTaskBase
	void ConfigureRequest(APDU& arAPDU);
	virtual std::string Name() const {
		return "Class Poll";
	}

private:

	int mClassMask;

};

} //ens ns

/* vim: set ts=4 sw=4: */

#endif
