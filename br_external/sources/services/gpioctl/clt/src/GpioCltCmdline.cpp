#include "GpioCltCmdline.h"

using namespace std;
/*****************************************************************************/
GpioCltCmdline::GpioCltCmdline()
{
	CmdlineHelper.attach_helper(this);
	CmdlineHelper.insert_options_entry((char*)"gpio" ,optional_argument,EJSON_GPIOCTL_RPC_IO_GET);
	CmdlineHelper.insert_help_entry((char*)"--gpio=addr,data             (read/write gpio bit value)");

	//CmdlineHelper.insert_options_entry((char*)"imgcheck" ,optional_argument,EJSON_SMARTEYE_RPC_CHECK_ID_PATTERN);
	//CmdlineHelper.insert_help_entry((char*)"--imgcheck=imgtype         [checks captured image against<ident/red/green/blue/white>]");
	//CmdlineHelper.insert_options_entry((char*)"debugimgfile" ,optional_argument,EJSON_SMARTEYE_RPC_DEBUG_OUTFILE_GET);
	//CmdlineHelper.insert_help_entry((char*)"--debugimgfile=filepath    [read/write debug image file path]");
}
/*****************************************************************************/
GpioCltCmdline::~GpioCltCmdline()
{
}
/*****************************************************************************/
//override virtual functions of ADGeneric Chain
int GpioCltCmdline::parse_my_cmdline_options(int arg, char* sub_arg)
{
	EJSON_GPIOCTL_RPC_TYPES command =(EJSON_GPIOCTL_RPC_TYPES)arg;
	switch(command)
	{
		case EJSON_GPIOCTL_RPC_IO_GET:
			CmdlineHelper.push_int_get_set_with_dev_addr_arg_command(EJSON_GPIOCTL_RPC_IO_GET,EJSON_GPIOCTL_RPC_IO_SET,
			GPIOCTL_RPC_IO_GET,GPIOCTL_RPC_IO_SET,(char*)GPIOCTL_RPC_IO_DATA_ARG,(char*)GPIOCTL_RPC_IO_ADDR_ARG,-1,sub_arg);
			break;
		//case EJSON_GPIOCTL_RPC_IO_GET:
			//CmdlineHelper.push_string_get_set_command(EJSON_SMARTEYE_RPC_DEBUG_OUTFILE_GET,EJSON_SMARTEYE_RPC_DEBUG_OUTFILE_SET,
			//SMARTEYE_RPC_DEBUG_OUTFILE_GET,SMARTEYE_RPC_DEBUG_OUTFILE_SET,
			//(char*)SMARTEYE_RPC_DEBUG_OUTFILE_ARG,sub_arg);
		//	break;
		default:
			return 0;
			break;	
	}
	return 0;
}

int GpioCltCmdline::run_my_commands(CmdExecutionObj *pCmdObj,ADJsonRpcClient *pSrvSockConn,ADGenericChain *pOutMsgList,ADThreadedSockClientProducer *pWorker)
{
	switch(pCmdObj->command)
	{
		default:return -1;
			break;
	}
	return 0;
}
/*****************************************************************************/
int GpioCltCmdline::run_my_autotest(char* ip,int interval_us,int max_loop,int test_num)
{
	return 0;
}
/*****************************************************************************/
#include "SrcControlVersion.h"
int GpioCltCmdline::print_my_version()
{
	printf("version - %05d\n",SRC_CONTROL_VERSION);
	return 0;
}
int GpioCltCmdline::get_my_server_port()
{
	return GPIOCTL_JSON_PORT_NUMBER;
}
/*****************************************************************************/
int GpioCltCmdline::parse_cmdline_arguments(int argc, char **argv)
{
	return CmdlineHelper.parse_cmdline_arguments(argc,argv);
}
/*****************************************************************************/

