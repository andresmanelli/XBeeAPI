#ifndef _XBEE_UTIL_
#define _XBEE_UTIL_

/**********************************************************************/
/*						API Frame Types								  */
/**********************************************************************/

//TODO: Definir toutes les trames utilisées
#define XBEE_TR_REQ_FRAME				0x10 //
#define XBEE_AT_CMD_FRAME				0x08 //
#define XBEE_AT_CMD_RESP_FRAME			0x88 //
#define XBEE_REM_AT_CMD_FRAME			0x17
#define XBEE_REM_AT_CMD_RESP_FRAME		0x97
#define XBEE_ND_ID_INDICATOR			0x95 //
#define XBEE_RECEIVE_PACKET				0x90 //
#define XBEE_TR_STATUS_FRAME			0x8B //
#define XBEE_MODEM_STATUS_FRAME			0x8A

/**********************************************************************/
/*							AT Commands Defs    					  */
/**********************************************************************/

//TODO: Definir toutes les commandes utilisées
/*  Special Commands                                */
#define XBEE_AT_CMD_WR                       ('W'*256+'R')
#define XBEE_AT_CMD_WB                       ('W'*256+'B')
#define XBEE_AT_CMD_RE                       ('R'*256+'E')
#define XBEE_AT_CMD_FR                       ('F'*256+'R')
#define XBEE_AT_CMD_NR                       ('N'*256+'R')
/*  Addressing                                      */
#define XBEE_AT_CMD_DH                       ('D'*256+'H')
#define XBEE_AT_CMD_DL                       ('D'*256+'L')
#define XBEE_AT_CMD_ZA                       ('Z'*256+'A')
#define XBEE_AT_CMD_SE                       ('S'*256+'E')
#define XBEE_AT_CMD_DE                       ('D'*256+'E')
#define XBEE_AT_CMD_CI                       ('C'*256+'I')
#define XBEE_AT_CMD_BI                       ('B'*256+'I')
#define XBEE_AT_CMD_MY                       ('M'*256+'Y')
#define XBEE_AT_CMD_MP                       ('M'*256+'P')
#define XBEE_AT_CMD_SH                       ('S'*256+'H')
#define XBEE_AT_CMD_SL                       ('S'*256+'L')
#define XBEE_AT_CMD_NI                       ('N'*256+'I')
/*  Networking & Security                           */
#define XBEE_AT_CMD_CH                       ('C'*256+'H')
#define XBEE_AT_CMD_ID                       ('I'*256+'D')
#define XBEE_AT_CMD_BH                       ('B'*256+'H')
#define XBEE_AT_CMD_NT                       ('N'*256+'T')
#define XBEE_AT_CMD_ND                       ('N'*256+'D')
#define XBEE_AT_CMD_DN                       ('D'*256+'N')
#define XBEE_AT_CMD_JN                       ('J'*256+'N')
#define XBEE_AT_CMD_SC                       ('S'*256+'C')
#define XBEE_AT_CMD_SD                       ('S'*256+'D')
#define XBEE_AT_CMD_NJ                       ('N'*256+'J')
#define XBEE_AT_CMD_AR                       ('A'*256+'R')
#define XBEE_AT_CMD_AI                       ('A'*256+'I')
/*  RF Interfacing                                  */
#define XBEE_AT_CMD_PL                       ('P'*256+'L')
#define XBEE_AT_CMD_PM                       ('P'*256+'M')
/*  Serial Interfacing (I/O)                        */
#define XBEE_AT_CMD_AP                       ('A'*256+'P')
#define XBEE_AT_CMD_AO                       ('A'*256+'O')
#define XBEE_AT_CMD_BD                       ('B'*256+'D')
#define XBEE_AT_CMD_RO                       ('R'*256+'O')
#define XBEE_AT_CMD_D7                       ('D'*256+'7')
#define XBEE_AT_CMD_D6                       ('D'*256+'6')
#define XBEE_AT_CMD_D5                       ('D'*256+'5')
/*  I/O Commands                                    */
#define XBEE_AT_CMD_P0                       ('P'*256+'0')
#define XBEE_AT_CMD_P1                       ('P'*256+'1')
#define XBEE_AT_CMD_P2                       ('P'*256+'2')
#define XBEE_AT_CMD_RP                       ('R'*256+'P')
#define XBEE_AT_CMD_IS                       ('I'*256+'S')
#define XBEE_AT_CMD_D0                       ('D'*256+'0')
#define XBEE_AT_CMD_D1                       ('D'*256+'1')
#define XBEE_AT_CMD_D2                       ('D'*256+'2')
#define XBEE_AT_CMD_D3                       ('D'*256+'3')
#define XBEE_AT_CMD_D4                       ('D'*256+'4')
/*  Diagnostics                                     */
#define XBEE_AT_CMD_VR                       ('V'*256+'R')
#define XBEE_AT_CMD_HV                       ('H'*256+'V')
/*  AT Command Options                              */
#define XBEE_AT_CMD_CT                       ('C'*256+'T')
#define XBEE_AT_CMD_CN                       ('C'*256+'N')
#define XBEE_AT_CMD_GT                       ('G'*256+'T')
#define XBEE_AT_CMD_CC                       ('C'*256+'C')
/*  Sleep Commands                                  */
#define XBEE_AT_CMD_SM                       ('S'*256+'M')
#define XBEE_AT_CMD_SN                       ('S'*256+'N')
#define XBEE_AT_CMD_SP                       ('S'*256+'P')
#define XBEE_AT_CMD_ST                       ('S'*256+'T')

/**********************************************************************/
/*							Misc Defs								  */
/**********************************************************************/

#define XBEE_MAX_LENGTH_RF_DATA			72
#define XBEE_BROADCAST_ADDR				0x000000000000FFFF
#define XBEE_OPTS_ACK_DISABLED			0x01
#define XBEE_OPTS_ACK_ENABLED			0x00
#define XBEE_OPTS_NET_ADD_DISCOVERY_EN	0x02
#define XBEE_OPTS_NET_ADD_DISCOVERY_DIS	0x00
#define XBEE_MIN_FRAME_LENGTH			4
#define XBEE_START_DELIMITER			0x7E
#define XBEE_MAP_TITLE_KEY              0x8000

/**********************************************************************/
/*  		Remote AT Command Response Status Codes				  	  */
/**********************************************************************/
#define XBEE_REM_AT_RESP_STATUS_FAILED	0x04
#define XBEE_REM_AT_RESP_STATUS_INV_PAR	0x03
#define XBEE_REM_AT_RESP_STATUS_INV_CMD	0x02
#define XBEE_REM_AT_RESP_STATUS_ERROR	0x01
#define XBEE_REM_AT_RESP_STATUS_OK		0x00

/**********************************************************************/
/*              AT Command Response Status Codes				  	  */
/**********************************************************************/
#define XBEE_AT_RESP_STATUS_OK          0x00
#define XBEE_AT_RESP_STATUS_ERR         0x01
#define XBEE_AT_RESP_STATUS_INV_CMD		0x02
#define XBEE_AT_RESP_STATUS_INV_PAR		0x03

/**********************************************************************/
/*							Defaults values							  */
/**********************************************************************/
#define XBEE_DEFAULT_ADDR				XBEE_BROADCAST_ADDR
#define XBEE_DEFAULT_MY					0xFFFE
#define XBEE_DEFAULT_AT_CMD				XBEE_AT_CMD_MY
#define XBEE_DEFAULT_BCST_RADIUS		0x00
#define XBEE_DEFAULT_FRAME_ID			0x01

/**********************************************************************/
/*					Remote AT Command Options						  */
/**********************************************************************/
#define XBEE_DIS_RET_DIS_ROUTE_REP		0x01
#define XBEE_APPLY_CHANGES				0x02
#define XBEE_EN_APS_ENCRYPT				0x20
#define XBEE_EXT_TRANS_TIMEOUT			0x40
#define	XBEE_NO_OPTS					0x00

/**********************************************************************/
/*					Node Identification Indicator Options			  */
/**********************************************************************/
#define XBEE_PACKET_ACK					0x01
#define XBEE_PACKET_BDCAST				0x02
#define XBEE_PACKET_CRYPT_APS			0x20
#define XBEE_P_SENT_END_DEV				0x40

/**********************************************************************/
/*					ZigBee Receive Packet Options					  */
/**********************************************************************/
#define XBEE_RPACKET_ACK				0x00
#define XBEE_RPACKET_BDCAST				0x01

/**********************************************************************/
/*					ZigBee Transmit Request Options					  */
/**********************************************************************/
#define XBEE_TR_REQ_DIS_ACK				0x01
#define XBEE_TR_REQ_DIS_NET_ADD_DIS 	0x02

/**********************************************************************/
/*							Device Type 					  	 	  */
/**********************************************************************/
#define XBEE_COORD						0x00
#define XBEE_ROUTER						0x01
#define XBEE_END_DEV					0x02

/**********************************************************************/
/*							Source Event 					  	 	  */
/**********************************************************************/
#define XBEE_PUSHBUTTON_EVT				0x01
#define	XBEE_JOINING_EVT				0x02
#define XBEE_PWR_CYCLE_EVT				0x03

/**********************************************************************/
/*							Digi's Ids	 					  	 	  */
/**********************************************************************/
#define XBEE_DIGI_APP_ID				0xC105
#define XBEE_DIGI_MANUF_ID				0x101E

/**********************************************************************/
/*							Debug Constants					  	 	  */
/**********************************************************************/
#define XBEE_SETW_TXT					30
#define XBEE_TRACE_SPACE                10
#define XBEE_TRACE_LINE                 10

/**********************************************************************/
/*							Delivery Status					  	 	  */
/**********************************************************************/
#define XBEE_DEL_STAT_SUCCESS			0x00
#define XBEE_DEL_STAT_CCAFAIL			0x02
#define XBEE_DEL_STAT_NETFAIL			0x21
#define XBEE_DEL_STAT_NOTJOIN			0x22
#define XBEE_DEL_STAT_SELFADR			0x23
#define XBEE_DEL_STAT_ADRNOTF			0x24
#define XBEE_DEL_STAT_ROUTNOTF			0x25

/**********************************************************************/
/*							Discovery Status				  	 	  */
/**********************************************************************/
#define XBEE_DISC_STAT_NODISCO			0x00
#define XBEE_DISC_STAT_ADRDISCO			0x01
#define XBEE_DISC_STAT_ROUDISCO			0x02
#define XBEE_DISC_STAT_BOTDISCO			0x03

/**********************************************************************/
/*								Modem Status				  	 	  */
/**********************************************************************/
#define XBEE_HARDWARE_RESET			0x00
#define XBEE_WATCHDOG_RESET			0x01
#define XBEE_JOINED					0x02
#define XBEE_UNJOINED				0x03
#define XBEE_SYNCHRO_LOST			0x04
#define XBEE_COORD_REALIGNMENT		0x05
#define XBEE_COORD_STARTED			0x06

#endif
