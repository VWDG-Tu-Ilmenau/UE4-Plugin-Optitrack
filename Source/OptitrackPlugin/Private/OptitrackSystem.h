// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <NatNetTypes.h>
#include <NatNetCAPI.h>
#include <NatNetClient.h>

#include "CoreMinimal.h"

/**
 * 
 */
class OptitrackSystem
{
public:
	OptitrackSystem();
	~OptitrackSystem();

	void PrintVersion();

	void ConnectAndInit();

	int ConnectToMotive();
	void DisconnectAndResetClient();

	void DisconnectClient();
	void InitClient();
	float GetFrameRate();
	float GetUnitsToMillimeter();
	void InitRigidBodyIdToName();
	void GetDataDescription();
	
	FTransform GetRigidBodyTransform(int _ID);

	bool SetPrintDebugMessages(bool _newVal);

private:

	NatNetClient * g_pClient = NULL;

	sServerDescription g_serverDescription;

	sNatNetClientConnectParams g_connectParams;

	char g_discoveredMulticastGroupAddr[kNatNetIpv4AddrStrLenMax] = NATNET_DEFAULT_MULTICAST_ADDRESS;

	int g_analogSamplesPerMocapFrame = 0;

	int UnitsToMM = 0;
	int UnitsToCm = 0;

	TMap<FString, int> RigidBodyIdToName;

};
