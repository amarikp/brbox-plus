#ifndef __SMARTEYE_RPC_H_
#define __SMARTEYE_RPC_H_
#include "ADJsonRpcMgr.hpp"
#include "SmarteyeJsonDef.h"
#include "ADCmnStringProcessor.hpp"
/* ------------------------------------------------------------------------- */
class  SmarteyeRpc : public ADJsonRpcMgrConsumer, public ADCmnStringProcessor
{
	SMARTEYE_CMN_DATA_CACHE *pDataCache;
public:
	 SmarteyeRpc(std::string rpcName,int myIndex,bool emu,bool log,SMARTEYE_CMN_DATA_CACHE *pData);
	~ SmarteyeRpc();
	virtual int MapJsonToBinary(JsonDataCommObj* pReq,int index);
	virtual int MapBinaryToJson(JsonDataCommObj* pReq,int index);
	virtual int ProcessWork(JsonDataCommObj* pReq,int index,ADJsonRpcMgrProducer* pObj);
	virtual RPC_SRV_RESULT ProcessWorkAsync(int index,unsigned char* pWorkData);
	virtual void ReceiveEvent(int cltToken,int evntNum,int evntArg){};

	int json_to_bin_check_id_pattern(JsonDataCommObj* pReq);
	int bin_to_json_check_id_pattern(JsonDataCommObj* pReq);
	int process_check_id_pattern(JsonDataCommObj* pReq);

	int json_to_bin_get_debug_outfile(JsonDataCommObj* pReq);
	int bin_to_json_get_debug_outfile(JsonDataCommObj* pReq);
	int process_get_debug_outfile(JsonDataCommObj* pReq);

	int json_to_bin_set_debug_outfile(JsonDataCommObj* pReq);
	int bin_to_json_set_debug_outfile(JsonDataCommObj* pReq);
	int process_set_debug_outfile(JsonDataCommObj* pReq);

	int json_to_bin_capture_jpg_img(JsonDataCommObj* pReq);
	int bin_to_json_capture_jpg_img(JsonDataCommObj* pReq);
	int process_capture_jpg_img(JsonDataCommObj* pReq);

	int json_to_bin_set_capture_resolution(JsonDataCommObj* pReq);
	int bin_to_json_set_capture_resolution(JsonDataCommObj* pReq);
	int process_set_capture_resolution(JsonDataCommObj* pReq);

	int json_to_bin_get_checkwall_file(JsonDataCommObj* pReq);
	int bin_to_json_get_checkwall_file(JsonDataCommObj* pReq);
	int process_get_checkwall_file(JsonDataCommObj* pReq);
	int json_to_bin_set_checkwall_file(JsonDataCommObj* pReq);
	int bin_to_json_set_checkwall_file(JsonDataCommObj* pReq);
	int process_set_checkwall_file(JsonDataCommObj* pReq);

	int json_to_bin_get_checkwallbase_file(JsonDataCommObj* pReq);
	int bin_to_json_get_checkwallbase_file(JsonDataCommObj* pReq);
	int process_get_checkwallbase_file(JsonDataCommObj* pReq);
	int json_to_bin_set_checkwallbase_file(JsonDataCommObj* pReq);
	int bin_to_json_set_checkwallbase_file(JsonDataCommObj* pReq);
	int process_set_checkwallbase_file(JsonDataCommObj* pReq);

};
/* ------------------------------------------------------------------------- */

#endif
