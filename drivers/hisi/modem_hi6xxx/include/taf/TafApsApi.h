
#ifndef _TAF_APS_API_H_
#define _TAF_APS_API_H_


/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include "TafClientApi.h"
#include "TafTypeDef.h"
#include "PsTypeDef.h"
#include "TafApi.h"



#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)


/*****************************************************************************
  2 �궨��
*****************************************************************************/

#define TAF_PS_MSG_ID_BASE                  (0x0000)
#define TAF_PS_EVT_ID_BASE                  (0x0A00)

/* "a1.a2.a3.a4 " */
#define TAF_IPV4_ADDR_LEN               (4)

/* "a1...a16" */
#define TAF_IPV6_ADDR_LEN               (16)
#define TAF_MAX_PREFIX_NUM_IN_RA        (6)

/* ^AUTHDATA */
#define TAF_MAX_AUTHDATA_USERNAME_LEN   (127)
#define TAF_MAX_AUTHDATA_PASSWORD_LEN   (127)
#define TAF_MAX_AUTHDATA_PLMN_LEN       (6)

/* ^CGAUTH */
#define TAF_MAX_PDP_AUTH_USERNAME_LEN   (99)
#define TAF_MAX_PDP_AUTH_PASSCODE_LEN   (99)

#define TAF_MAX_ACCESS_NUM_LEN          (32)
#define TAF_MAX_GW_AUTH_USERNAME_LEN    (255)
#define TAF_MAX_GW_AUTH_PASSWORD_LEN    (255)

#define TAF_MAX_PDP_PROFILE_NUM         (32)
#define TAF_MAX_SDF_PF_NUM              (16)

#define TAF_MAX_APN_LEN                 (99)

/*��֧������PDP��������Ŀ��*/

#if (FEATURE_ON == FEATURE_LTE)
#define TAF_MAX_CID                     (31)
#else
#define TAF_MAX_CID                     (11)
#endif
#define TAF_MAX_CID_NV                  (11)

#define TAF_INVALID_CID                 (0xFF)

/* 4 x 3 char dec nums + 3 x '.' + '\0' */
#define TAF_MAX_IPV4_ADDR_STR_LEN       (16)

/* 8 x 4 �ַ�(HEX) + 7 x ':' + '\0' */
#define TAF_MAX_IPV6_ADDR_COLON_STR_LEN (40)

/* 32 x 3 �ַ�(DEC) + 31 x '.' + '\0' */
#define TAF_MAX_IPV6_ADDR_DOT_STR_LEN   (128)

#define TAF_IPV6_STR_MAX_TOKENS         (16)                                    /* IPV6�ַ�����ʽʹ�õķָ������������ */

#define TAF_IPV6_STR_RFC2373_TOKENS     (8)                                     /* RFC2373�涨��IPV6�ַ�����ʽʹ�õķָ������������ */

#define TAF_IPV4_STR_DELIMITER          '.'                                     /* RFCЭ��ʹ�õ�IPV4�ı����﷽ʽʹ�õķָ��� */
#define TAF_IPV6_STR_DELIMITER          ':'                                     /* RFC2373ʹ�õ�IPV6�ı����﷽ʽʹ�õķָ��� */

#define TAF_IPV6_PREFIX_LEN             (8)                                     /* IPv6��ַǰ׺���� */

#define TAF_MAX_USERNAME_LEN            (99)                                    /*AUTHLEN Ϊ100������1���ֽڵ�Peer-ID Length��99�ֽڵ�Peer-ID���ʴ˴�����Ϊ99*/
#define TAF_MAX_PASSCODE_LEN            (99)                                    /*PASSWORDLEN Ϊ100������1���ֽڵ�Passwd-Length��99�ֽڵ�Passwd���ʴ˴�����Ϊ99*/


/* password+auth */
#define TAF_PPP_PAP_REQ_MAX_LEN             (100 + 100)

/* code(1B)+id(1B)+length(2B)+challenge_size(1B)+challenge+name */
#define TAF_PPP_CHAP_CHALLENGE_MAX_LEN      (1 + 1 + 2 + 1 + 48 + 100)

/* code(1B)+id(1B)+length(2B)+response_size(1B)+response+name */
#define TAF_PPP_CHAP_RESPONSE_MAX_LEN       (1 + 1 + 2 + 1 + 100 + 100)

#define TAF_PPP_AUTH_FRAME_BUF_MAX_LEN      (256)

#define TAF_PPP_IPCP_FRAME_BUF_MAX_LEN      (256)

#define TAF_PS_CAUSE_APS_SECTION_BEGIN      (0x0000)
#define TAF_PS_CAUSE_SM_SECTION_BEGIN       (0x0080)
#define TAF_PS_CAUSE_SM_NW_SECTION_BEGIN    (0x0100)
#define TAF_PS_CAUSE_SM_NW_SECTION_END      (0x01FF)
#define TAF_PS_CAUSE_GMM_SECTION_BEGIN      (0x0200)
#define TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN   (0x0300)

#define TAF_PS_IS_SM_CAUSE_VALID(sm_cause)\
            ( (((sm_cause) + TAF_PS_CAUSE_SM_NW_SECTION_BEGIN) >= TAF_PS_CAUSE_SM_NW_OPERATOR_DETERMINED_BARRING)\
             && (((sm_cause) + TAF_PS_CAUSE_SM_NW_SECTION_BEGIN) <= TAF_PS_CAUSE_SM_NW_APN_RESTRICTION_INCOMPATIBLE) )

#define TAF_PS_CONVERT_SM_CAUSE_TO_PS_CAUSE(sm_cause)\
            ((sm_cause) + TAF_PS_CAUSE_SM_NW_SECTION_BEGIN)

#define TAF_PS_GET_MSG_CONTENT(pstMsg)\
            ((VOS_VOID *)(((TAF_PS_MSG_STRU *)(pstMsg))->aucContent))


/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/


enum TAF_PS_MSG_ID_ENUM
{
    /* ������ϢΪ��׼����[0x0000, 0x0099] */
    /* +CGDCONT */
    ID_MSG_TAF_PS_SET_PRIM_PDP_CONTEXT_INFO_REQ             = TAF_PS_MSG_ID_BASE + 0x0001,  /* _H2ASN_MsgChoice TAF_PS_SET_PRIM_PDP_CONTEXT_INFO_REQ_STRU */
    ID_MSG_TAF_PS_GET_PRIM_PDP_CONTEXT_INFO_REQ             = TAF_PS_MSG_ID_BASE + 0x0002,  /* _H2ASN_MsgChoice TAF_PS_GET_PRIM_PDP_CONTEXT_INFO_REQ_STRU */

    /* +CGDSCONT */
    ID_MSG_TAF_PS_SET_SEC_PDP_CONTEXT_INFO_REQ              = TAF_PS_MSG_ID_BASE + 0x0003,  /* _H2ASN_MsgChoice TAF_PS_SET_SEC_PDP_CONTEXT_INFO_REQ_STRU */
    ID_MSG_TAF_PS_GET_SEC_PDP_CONTEXT_INFO_REQ              = TAF_PS_MSG_ID_BASE + 0x0004,  /* _H2ASN_MsgChoice TAF_PS_GET_SEC_PDP_CONTEXT_INFO_REQ_STRU */

    /* +CGTFT */
    ID_MSG_TAF_PS_SET_TFT_INFO_REQ                          = TAF_PS_MSG_ID_BASE + 0x0005,  /* _H2ASN_MsgChoice TAF_PS_SET_TFT_INFO_REQ_STRU */
    ID_MSG_TAF_PS_GET_TFT_INFO_REQ                          = TAF_PS_MSG_ID_BASE + 0x0006,  /* _H2ASN_MsgChoice TAF_PS_GET_TFT_INFO_REQ_STRU */

    /* +CGQREQ */
    ID_MSG_TAF_PS_SET_GPRS_QOS_INFO_REQ                     = TAF_PS_MSG_ID_BASE + 0x0007,  /* _H2ASN_MsgChoice */
    ID_MSG_TAF_PS_GET_GPRS_QOS_INFO_REQ                     = TAF_PS_MSG_ID_BASE + 0x0008,  /* _H2ASN_MsgChoice */

    /* +CGQMIN */
    ID_MSG_TAF_PS_SET_GPRS_QOS_MIN_INFO_REQ                 = TAF_PS_MSG_ID_BASE + 0x0009,  /* _H2ASN_MsgChoice */
    ID_MSG_TAF_PS_GET_GPRS_QOS_MIN_INFO_REQ                 = TAF_PS_MSG_ID_BASE + 0x000A,  /* _H2ASN_MsgChoice */

    /* +CGEQREQ */
    ID_MSG_TAF_PS_SET_UMTS_QOS_INFO_REQ                     = TAF_PS_MSG_ID_BASE + 0x000B,  /* _H2ASN_MsgChoice TAF_PS_SET_UMTS_QOS_INFO_REQ_STRU */
    ID_MSG_TAF_PS_GET_UMTS_QOS_INFO_REQ                     = TAF_PS_MSG_ID_BASE + 0x000C,  /* _H2ASN_MsgChoice TAF_PS_GET_UMTS_QOS_INFO_REQ_STRU */

    /* +CGEQMIN */
    ID_MSG_TAF_PS_SET_UMTS_QOS_MIN_INFO_REQ                 = TAF_PS_MSG_ID_BASE + 0x000D,  /* _H2ASN_MsgChoice TAF_PS_SET_UMTS_QOS_MIN_INFO_REQ_STRU */
    ID_MSG_TAF_PS_GET_UMTS_QOS_MIN_INFO_REQ                 = TAF_PS_MSG_ID_BASE + 0x000E,  /* _H2ASN_MsgChoice TAF_PS_GET_UMTS_QOS_MIN_INFO_REQ_STRU */

    /* +CGEQNEG */
    ID_MSG_TAF_PS_GET_DYNAMIC_UMTS_QOS_INFO_REQ             = TAF_PS_MSG_ID_BASE + 0x000F,  /* _H2ASN_MsgChoice TAF_PS_GET_DYNAMIC_UMTS_QOS_INFO_REQ_STRU */

    /* +CGACT */
    ID_MSG_TAF_PS_SET_PDP_CONTEXT_STATE_REQ                 = TAF_PS_MSG_ID_BASE + 0x0010,  /* _H2ASN_MsgChoice TAF_PS_SET_PDP_STATE_REQ_STRU */
    ID_MSG_TAF_PS_GET_PDP_CONTEXT_STATE_REQ                 = TAF_PS_MSG_ID_BASE + 0x0011,  /* _H2ASN_MsgChoice TAF_PS_GET_PDP_STATE_REQ_STRU */

    /* +CGCMOD */
    ID_MSG_TAF_PS_CALL_MODIFY_REQ                           = TAF_PS_MSG_ID_BASE + 0x0012,  /* _H2ASN_MsgChoice TAF_PS_CALL_MODIFY_REQ_STRU */

    /* +CGANS */
    ID_MSG_TAF_PS_CALL_ANSWER_REQ                           = TAF_PS_MSG_ID_BASE + 0x0013,  /* _H2ASN_MsgChoice TAF_PS_CALL_ANSWER_REQ_STRU */
    ID_MSG_TAF_PS_CALL_HANGUP_REQ                           = TAF_PS_MSG_ID_BASE + 0x0014,  /* _H2ASN_MsgChoice TAF_PS_CALL_HANGUP_REQ_STRU */

    /* +CGPADDR */
    ID_MSG_TAF_PS_GET_PDP_IP_ADDR_INFO_REQ                  = TAF_PS_MSG_ID_BASE + 0x0015,  /* _H2ASN_MsgChoice TAF_PS_GET_PDP_IP_ADDR_INFO_REQ_STRU */

    ID_MSG_TAF_PS_GET_PDPCONT_INFO_REQ                      = TAF_PS_MSG_ID_BASE + 0x0016, /* _H2ASN_MsgChoice TAF_PS_GET_PDP_CONTEXT_INFO_REQ_STRU */

    /* +CGAUTO */
    ID_MSG_TAF_PS_SET_ANSWER_MODE_INFO_REQ                  = TAF_PS_MSG_ID_BASE + 0x0017,  /* _H2ASN_MsgChoice TAF_PS_SET_ANSWER_MODE_INFO_REQ_STRU */
    ID_MSG_TAF_PS_GET_ANSWER_MODE_INFO_REQ                  = TAF_PS_MSG_ID_BASE + 0x0018,  /* _H2ASN_MsgChoice TAF_PS_GET_ANSWER_MODE_INFO_REQ_STRU */

    /* +CGCONTRDP */
    ID_MSG_TAF_PS_GET_DYNAMIC_PRIM_PDP_CONTEXT_INFO_REQ     = TAF_PS_MSG_ID_BASE + 0x0019,  /* _H2ASN_MsgChoice TAF_PS_GET_DYNAMIC_PRIM_PDP_CONTEXT_INFO_REQ_STRU */

    /* +CGSCONTRDP */
    ID_MSG_TAF_PS_GET_DYNAMIC_SEC_PDP_CONTEXT_INFO_REQ      = TAF_PS_MSG_ID_BASE + 0x001A,  /* _H2ASN_MsgChoice TAF_PS_GET_DYNAMIC_SEC_PDP_CONTEXT_INFO_REQ_STRU */

    /* +CGTFTRDP */
    ID_MSG_TAF_PS_GET_DYNAMIC_TFT_INFO_REQ                  = TAF_PS_MSG_ID_BASE + 0x001B,  /* _H2ASN_MsgChoice TAF_PS_GET_DYNAMIC_TFT_INFO_REQ_STRU */

    /* +CGEQOS */
    ID_MSG_TAF_PS_SET_EPS_QOS_INFO_REQ                      = TAF_PS_MSG_ID_BASE + 0x001C,  /* _H2ASN_MsgChoice TAF_PS_SET_EPS_QOS_INFO_REQ_STRU */
    ID_MSG_TAF_PS_GET_EPS_QOS_INFO_REQ                      = TAF_PS_MSG_ID_BASE + 0x001D,  /* _H2ASN_MsgChoice TAF_PS_GET_EPS_QOS_INFO_REQ_STRU */

    /* +CGEQOSRDP */
    ID_MSG_TAF_PS_GET_DYNAMIC_EPS_QOS_INFO_REQ              = TAF_PS_MSG_ID_BASE + 0x001E,  /* _H2ASN_MsgChoice TAF_PS_GET_DYNAMIC_EPS_QOS_INFO_REQ_STRU */

    /* ������ϢΪ˽������[0x0100, 0x0199] */
    /* ^NDISCONN/^NDISDUP */
    ID_MSG_TAF_PS_CALL_ORIG_REQ                             = TAF_PS_MSG_ID_BASE + 0x0101,  /* _H2ASN_MsgChoice TAF_PS_CALL_ORIG_REQ_STRU */
    ID_MSG_TAF_PS_CALL_END_REQ                              = TAF_PS_MSG_ID_BASE + 0x0102,  /* _H2ASN_MsgChoice TAF_PS_CALL_END_REQ_STRU */

    /* D */
    ID_MSG_TAF_PS_GET_D_GPRS_ACTIVE_TYPE_REQ                = TAF_PS_MSG_ID_BASE + 0x0103,  /* _H2ASN_MsgChoice TAF_PS_GET_D_GPRS_ACTIVE_TYPE_REQ_STRU */

    /* PPP */
    ID_MSG_TAF_PS_PPP_DIAL_ORIG_REQ                         = TAF_PS_MSG_ID_BASE + 0x0104,  /* _H2ASN_MsgChoice TAF_PS_PPP_DIAL_ORIG_REQ_STRU */

    /* ^DSFLOWQRY */
    ID_MSG_TAF_PS_GET_DSFLOW_INFO_REQ                       = TAF_PS_MSG_ID_BASE + 0x0105,  /* _H2ASN_MsgChoice TAF_PS_GET_DSFLOW_INFO_REQ_STRU */

    /* ^DSFLOWCLR */
    ID_MSG_TAF_PS_CLEAR_DSFLOW_REQ                          = TAF_PS_MSG_ID_BASE + 0x0106,  /* _H2ASN_MsgChoice TAF_PS_CLEAR_DSFLOW_REQ_STRU */

    /* ^DSFLOWRPT */
    ID_MSG_TAF_PS_CONFIG_DSFLOW_RPT_REQ                     = TAF_PS_MSG_ID_BASE + 0x0107,  /* _H2ASN_MsgChoice TAF_PS_CONFIG_DSFLOW_RPT_REQ_STRU */

    /* ^DWINS */
    ID_MSG_TAF_PS_CONFIG_NBNS_FUNCTION_REQ                  = TAF_PS_MSG_ID_BASE + 0x0108,  /* _H2ASN_MsgChoice TAF_PS_CONFIG_NBNS_FUNCTION_REQ_STRU */

    /* ^AUTHDATA */
    ID_MSG_TAF_PS_SET_AUTHDATA_INFO_REQ                     = TAF_PS_MSG_ID_BASE + 0x0109,  /* _H2ASN_MsgChoice TAF_PS_SET_AUTHDATA_INFO_REQ_STRU */
    ID_MSG_TAF_PS_GET_AUTHDATA_INFO_REQ                     = TAF_PS_MSG_ID_BASE + 0x010A,  /* _H2ASN_MsgChoice TAF_PS_GET_AUTHDATA_INFO_REQ_STRU */

    /* ^DNSQUERY */
    ID_MSG_TAF_PS_GET_NEGOTIATION_DNS_REQ                   = TAF_PS_MSG_ID_BASE + 0x010B,  /* _H2ASN_MsgChoice TAF_PS_GET_NEGOTIATION_DNS_REQ_STRU */

    /* ^CGAUTH */
    ID_MSG_TAF_PS_SET_PDP_AUTH_INFO_REQ                     = TAF_PS_MSG_ID_BASE + 0x010C,  /* _H2ASN_MsgChoice TAF_PS_SET_PDP_AUTH_INFO_REQ_STRU */
    ID_MSG_TAF_PS_GET_PDP_AUTH_INFO_REQ                     = TAF_PS_MSG_ID_BASE + 0x010D,  /* _H2ASN_MsgChoice TAF_PS_GET_PDP_AUTH_INFO_REQ_STRU */

    /* ^CGDNS */
    ID_MSG_TAF_PS_SET_PDP_DNS_INFO_REQ                      = TAF_PS_MSG_ID_BASE + 0x010E,  /* _H2ASN_MsgChoice TAF_PS_SET_PDP_DNS_INFO_REQ_STRU */
    ID_MSG_TAF_PS_GET_PDP_DNS_INFO_REQ                      = TAF_PS_MSG_ID_BASE + 0x010F,  /* _H2ASN_MsgChoice TAF_PS_GET_PDP_DNS_INFO_REQ_STRU */

    /* ^TRIG */
    ID_MSG_TAF_PS_TRIG_GPRS_DATA_REQ                        = TAF_PS_MSG_ID_BASE + 0x0110,  /* _H2ASN_MsgChoice TAF_PS_TRIG_GPRS_DATA_REQ_STRU */

    /*^LTECS*/
    ID_MSG_TAF_PS_GET_LTE_CS_REQ                            = TAF_PS_MSG_ID_BASE + 0x0111,  /* _H2ASN_MsgChoice TAF_PS_LTECS_REQ_STRU */

    /* ^PDPROFMOD */
    ID_MSG_TAF_PS_SET_PDPROFMOD_INFO_REQ                    = TAF_PS_MSG_ID_BASE + 0x0112,  /* _H2ASN_MsgChoice TAF_PS_SET_PROFILE_INFO_REQ_STRU */

    /* ^CEMODE */
    ID_MSG_TAF_PS_GET_CEMODE_REQ                            = TAF_PS_MSG_ID_BASE + 0x0113,  /* _H2ASN_MsgChoice TAF_PS_CEMODE_REQ_STRU */

    /* �첽�ӿڻ�ȡSDF��Ϣ */
    ID_MSG_TAF_PS_GET_CID_SDF_REQ                           = TAF_PS_MSG_ID_BASE + 0x0114,  /* _H2ASN_MsgChoice TAF_SDF_PARA_QUERY_INFO_STRU */

    /* �첽�ӿڻ�ȡCID */
    ID_MSG_TAF_PS_GET_UNUSED_CID_REQ                        = TAF_PS_MSG_ID_BASE + 0x0115,  /* _H2ASN_MsgChoice */

    /* ^IMSPDPCFG */
    ID_MSG_TAF_PS_SET_IMS_PDP_CFG_REQ                       = TAF_PS_MSG_ID_BASE + 0x0121,  /* _H2ASN_MsgChoice TAF_PS_SET_IMS_PDP_CFG_REQ_STRU */

    /* ������APS�ڲ���Ϣ[0x0200, 0x0299] */
    /* APS�ڲ�ȥ�������� */
    ID_MSG_TAF_PS_APS_INTERNAL_PDP_DEACTIVATE_REQ           = TAF_PS_MSG_ID_BASE + 0x0200,  /* _H2ASN_MsgChoice */

    /* APS�ڲ�ȥ����ָʾ */
    ID_MSG_TAF_PS_APS_LOCAL_PDP_DEACTIVATE_IND              = TAF_PS_MSG_ID_BASE + 0x0201,  /* _H2ASN_MsgChoice */

#if (FEATURE_ON == FEATURE_LTE)
    /* ע����ؼ���ָʾ */
    ID_MSG_TAF_PS_ATTACH_BEARER_ACTIVATE_IND                = TAF_PS_MSG_ID_BASE + 0x0202,  /* _H2ASN_MsgChoice */
#endif

    /* ������Ϣ��ά�ɲ�[0x0300, 0x0399] */
    ID_MSG_TAF_PS_APS_MNTN_DFS_INFO                         = TAF_PS_MSG_ID_BASE + 0x0300,  /* _H2ASN_MsgChoice */

    ID_MSG_TAF_PS_BUTT

};
typedef VOS_UINT32 TAF_PS_MSG_ID_ENUM_UINT32;
enum TAF_PS_EVT_ID_ENUM
{
    /* PS CALL */
    ID_EVT_TAF_PS_CALL_PDP_ACTIVATE_CNF                     = TAF_PS_EVT_ID_BASE + 0x0001,           /* _H2ASN_MsgChoice TAF_PS_CALL_PDP_ACTIVATE_CNF_STRU           */
    ID_EVT_TAF_PS_CALL_PDP_ACTIVATE_REJ                     = TAF_PS_EVT_ID_BASE + 0x0002,           /* _H2ASN_MsgChoice TAF_PS_CALL_PDP_ACTIVATE_REJ_STRU           */
    ID_EVT_TAF_PS_CALL_PDP_ACTIVATE_IND                     = TAF_PS_EVT_ID_BASE + 0x0003,           /* _H2ASN_MsgChoice TAF_PS_CALL_PDP_ACTIVATE_IND_STRU           */
    ID_EVT_TAF_PS_CALL_PDP_MANAGE_IND                       = TAF_PS_EVT_ID_BASE + 0x0004,           /* _H2ASN_MsgChoice TAF_PS_CALL_PDP_MANAGE_IND_STRU             */
    ID_EVT_TAF_PS_CALL_PDP_MODIFY_CNF                       = TAF_PS_EVT_ID_BASE + 0x0005,           /* _H2ASN_MsgChoice TAF_PS_CALL_PDP_MODIFY_CNF_STRU             */
    ID_EVT_TAF_PS_CALL_PDP_MODIFY_REJ                       = TAF_PS_EVT_ID_BASE + 0x0006,           /* _H2ASN_MsgChoice TAF_PS_CALL_PDP_MODIFY_REJ_STRU             */
    ID_EVT_TAF_PS_CALL_PDP_MODIFY_IND                       = TAF_PS_EVT_ID_BASE + 0x0007,           /* _H2ASN_MsgChoice TAF_PS_CALL_PDP_MODIFY_IND_STRU             */
    ID_EVT_TAF_PS_CALL_PDP_DEACTIVATE_CNF                   = TAF_PS_EVT_ID_BASE + 0x0008,           /* _H2ASN_MsgChoice TAF_PS_CALL_PDP_DEACTIVATE_CNF_STRU         */
    ID_EVT_TAF_PS_CALL_PDP_DEACTIVATE_IND                   = TAF_PS_EVT_ID_BASE + 0x0009,           /* _H2ASN_MsgChoice TAF_PS_CALL_PDP_DEACTIVATE_IND_STRU         */
    ID_EVT_TAF_PS_CALL_PDP_DISCONNECT_IND                   = TAF_PS_EVT_ID_BASE + 0x000A,           /* _H2ASN_MsgChoice TAF_PS_CALL_PDP_PDP_DISCONNECT_IND_STRU     */
    ID_EVT_TAF_PS_CALL_PDP_IPV6_INFO_IND                    = TAF_PS_EVT_ID_BASE + 0x000B,           /* _H2ASN_MsgChoice TAF_PS_IPV6_INFO_IND_STRU                   */

    ID_EVT_TAF_PS_CALL_ORIG_CNF                             = TAF_PS_EVT_ID_BASE + 0x0031,           /* _H2ASN_MsgChoice TAF_PS_CALL_ORIG_CNF_STRU                   */
    ID_EVT_TAF_PS_CALL_END_CNF                              = TAF_PS_EVT_ID_BASE + 0x0032,           /* _H2ASN_MsgChoice TAF_PS_CALL_END_CNF_STRU                    */
    ID_EVT_TAF_PS_CALL_MODIFY_CNF                           = TAF_PS_EVT_ID_BASE + 0x0033,           /* _H2ASN_MsgChoice TAF_PS_CALL_MODIFY_CNF_STRU                 */
    ID_EVT_TAF_PS_CALL_ANSWER_CNF                           = TAF_PS_EVT_ID_BASE + 0x0034,           /* _H2ASN_MsgChoice TAF_PS_CALL_ANSWER_CNF_STRU                 */
    ID_EVT_TAF_PS_CALL_HANGUP_CNF                           = TAF_PS_EVT_ID_BASE + 0x0035,           /* _H2ASN_MsgChoice TAF_PS_CALL_HANGUP_CNF_STRU                 */

    /* D */
    ID_EVT_TAF_PS_GET_D_GPRS_ACTIVE_TYPE_CNF                = TAF_PS_EVT_ID_BASE + 0x0100,           /* _H2ASN_MsgChoice TAF_PS_GET_D_GPRS_ACTIVE_TYPE_CNF_STRU      */

    /* PPP */
    ID_EVT_TAF_PS_PPP_DIAL_ORIG_CNF                         = TAF_PS_EVT_ID_BASE + 0x0101,           /* _H2ASN_MsgChoice TAF_PS_PPP_DIAL_ORIG_CNF_STRU               */

    /* +CGDCONT */
    ID_EVT_TAF_PS_SET_PRIM_PDP_CONTEXT_INFO_CNF             = TAF_PS_EVT_ID_BASE + 0x0102,           /* _H2ASN_MsgChoice TAF_PS_SET_PRIM_PDP_CONTEXT_INFO_CNF_STRU   */
    ID_EVT_TAF_PS_GET_PRIM_PDP_CONTEXT_INFO_CNF             = TAF_PS_EVT_ID_BASE + 0x0103,           /* _H2ASN_MsgChoice TAF_PS_GET_PRIM_PDP_CONTEXT_INFO_CNF_STRU   */

    /* +CGDSCONT */
    ID_EVT_TAF_PS_SET_SEC_PDP_CONTEXT_INFO_CNF              = TAF_PS_EVT_ID_BASE + 0x0104,           /* _H2ASN_MsgChoice TAF_PS_SET_SEC_PDP_CONTEXT_INFO_CNF_STRU    */
    ID_EVT_TAF_PS_GET_SEC_PDP_CONTEXT_INFO_CNF              = TAF_PS_EVT_ID_BASE + 0x0105,           /* _H2ASN_MsgChoice TAF_PS_GET_SEC_PDP_CONTEXT_INFO_CNF_STRU    */

    /* +CGTFT */
    ID_EVT_TAF_PS_SET_TFT_INFO_CNF                          = TAF_PS_EVT_ID_BASE + 0x0106,           /* _H2ASN_MsgChoice TAF_PS_SET_TFT_INFO_CNF_STRU                */
    ID_EVT_TAF_PS_GET_TFT_INFO_CNF                          = TAF_PS_EVT_ID_BASE + 0x0107,           /* _H2ASN_MsgChoice TAF_PS_GET_TFT_INFO_CNF_STRU                */

    /* +CGQREQ */
    ID_EVT_TAF_PS_SET_GPRS_QOS_INFO_CNF                     = TAF_PS_EVT_ID_BASE + 0x0108,           /* _H2ASN_MsgChoice */
    ID_EVT_TAF_PS_GET_GPRS_QOS_INFO_CNF                     = TAF_PS_EVT_ID_BASE + 0x0109,           /* _H2ASN_MsgChoice */

    /* +CGQMIN */
    ID_EVT_TAF_PS_SET_GPRS_QOS_MIN_INFO_CNF                 = TAF_PS_EVT_ID_BASE + 0x010A,           /* _H2ASN_MsgChoice */
    ID_EVT_TAF_PS_GET_GPRS_QOS_MIN_INFO_CNF                 = TAF_PS_EVT_ID_BASE + 0x010B,           /* _H2ASN_MsgChoice */

    /* +CGEQREQ */
    ID_EVT_TAF_PS_SET_UMTS_QOS_INFO_CNF                     = TAF_PS_EVT_ID_BASE + 0x010C,           /* _H2ASN_MsgChoice TAF_PS_SET_UMTS_QOS_INFO_CNF_STRU           */
    ID_EVT_TAF_PS_GET_UMTS_QOS_INFO_CNF                     = TAF_PS_EVT_ID_BASE + 0x010D,           /* _H2ASN_MsgChoice TAF_PS_GET_UMTS_QOS_INFO_CNF_STRU           */

    /* +CGEQMIN */
    ID_EVT_TAF_PS_SET_UMTS_QOS_MIN_INFO_CNF                 = TAF_PS_EVT_ID_BASE + 0x010E,           /* _H2ASN_MsgChoice TAF_PS_SET_UMTS_QOS_MIN_INFO_CNF_STRU       */
    ID_EVT_TAF_PS_GET_UMTS_QOS_MIN_INFO_CNF                 = TAF_PS_EVT_ID_BASE + 0x010F,           /* _H2ASN_MsgChoice TAF_PS_GET_UMTS_QOS_MIN_INFO_CNF_STRU       */

    /* +CGEQNEG */
    ID_EVT_TAF_PS_GET_DYNAMIC_UMTS_QOS_INFO_CNF             = TAF_PS_EVT_ID_BASE + 0x0110,           /* _H2ASN_MsgChoice TAF_PS_GET_DYNAMIC_UMTS_QOS_INFO_CNF_STRU   */

    /* +CGACT */
    ID_EVT_TAF_PS_SET_PDP_CONTEXT_STATE_CNF                 = TAF_PS_EVT_ID_BASE + 0x0111,           /* _H2ASN_MsgChoice TAF_PS_SET_PDP_STATE_CNF_STRU       */
    ID_EVT_TAF_PS_GET_PDP_CONTEXT_STATE_CNF                 = TAF_PS_EVT_ID_BASE + 0x0112,           /* _H2ASN_MsgChoice TAF_PS_GET_PDP_STATE_CNF_STRU       */

    /* +CGPADDR */
    ID_EVT_TAF_PS_GET_PDP_IP_ADDR_INFO_CNF                  = TAF_PS_EVT_ID_BASE + 0x0113,           /* _H2ASN_MsgChoice TAF_PS_GET_PDP_IP_ADDR_INFO_CNF_STRU        */
    ID_EVT_TAF_PS_GET_PDP_CONTEXT_INFO_CNF                  = TAF_PS_EVT_ID_BASE + 0x0114,           /* _H2ASN_MsgChoice TAF_PS_GET_PDP_CONTEXT_INFO_CNF_STRU        */

    /* +CGAUTO */
    ID_EVT_TAF_PS_SET_ANSWER_MODE_INFO_CNF                  = TAF_PS_EVT_ID_BASE + 0x0115,           /* _H2ASN_MsgChoice TAF_PS_SET_ANSWER_MODE_INFO_CNF_STRU        */
    ID_EVT_TAF_PS_GET_ANSWER_MODE_INFO_CNF                  = TAF_PS_EVT_ID_BASE + 0x0116,           /* _H2ASN_MsgChoice TAF_PS_GET_ANSWER_MODE_INFO_CNF_STRU        */

    /* +CGCONTRDP */
    ID_EVT_TAF_PS_GET_DYNAMIC_PRIM_PDP_CONTEXT_INFO_CNF     = TAF_PS_EVT_ID_BASE + 0x0117,           /* _H2ASN_MsgChoice TAF_PS_GET_DYNAMIC_PRIM_PDP_CONTEXT_INFO_CNF_STRU */

    /* +CGSCONTRDP */
    ID_EVT_TAF_PS_GET_DYNAMIC_SEC_PDP_CONTEXT_INFO_CNF      = TAF_PS_EVT_ID_BASE + 0x0118,           /* _H2ASN_MsgChoice TAF_PS_GET_DYNAMIC_SEC_PDP_CONTEXT_INFO_CNF_STRU */

    /* +CGTFTRDP */
    ID_EVT_TAF_PS_GET_DYNAMIC_TFT_INFO_CNF                  = TAF_PS_EVT_ID_BASE + 0x0119,           /* _H2ASN_MsgChoice TAF_PS_GET_DYNAMIC_TFT_INFO_CNF_STRU        */

    /* +CGEQOS */
    ID_EVT_TAF_PS_SET_EPS_QOS_INFO_CNF                      = TAF_PS_EVT_ID_BASE + 0x011A,           /* _H2ASN_MsgChoice TAF_PS_SET_EPS_QOS_INFO_CNF_STRU            */
    ID_EVT_TAF_PS_GET_EPS_QOS_INFO_CNF                      = TAF_PS_EVT_ID_BASE + 0x011B,           /* _H2ASN_MsgChoice TAF_PS_GET_EPS_QOS_INFO_CNF_STRU            */

    /* +CGEQOSRDP */
    ID_EVT_TAF_PS_GET_DYNAMIC_EPS_QOS_INFO_CNF              = TAF_PS_EVT_ID_BASE + 0x011C,           /* _H2ASN_MsgChoice TAF_PS_GET_DYNAMIC_EPS_QOS_INFO_CNF_STRU    */

    /* ^DSFLOWQRY */
    ID_EVT_TAF_PS_GET_DSFLOW_INFO_CNF                       = TAF_PS_EVT_ID_BASE + 0x011D,           /* _H2ASN_MsgChoice TAF_PS_GET_DSFLOW_INFO_CNF_STRU             */

    /* ^DSFLOWCLR */
    ID_EVT_TAF_PS_CLEAR_DSFLOW_CNF                          = TAF_PS_EVT_ID_BASE + 0x011E,           /* _H2ASN_MsgChoice TAF_PS_CLEAR_DSFLOW_CNF_STRU                */

    /* ^DSFLOWRPT */
    ID_EVT_TAF_PS_CONFIG_DSFLOW_RPT_CNF                     = TAF_PS_EVT_ID_BASE + 0x011F,           /* _H2ASN_MsgChoice TAF_PS_CONFIG_DSFLOW_RPT_CNF_STRU           */

    /* ^DSFLOWRPT */
    ID_EVT_TAF_PS_REPORT_DSFLOW_IND                         = TAF_PS_EVT_ID_BASE + 0x0120,           /* _H2ASN_MsgChoice TAF_PS_REPORT_DSFLOW_IND_STRU               */

    /* ^CGAUTH */
    ID_EVT_TAF_PS_SET_PDP_AUTH_INFO_CNF                     = TAF_PS_EVT_ID_BASE + 0x0121,           /* _H2ASN_MsgChoice TAF_PS_SET_PDP_AUTH_INFO_CNF_STRU           */
    ID_EVT_TAF_PS_GET_PDP_AUTH_INFO_CNF                     = TAF_PS_EVT_ID_BASE + 0x0122,           /* _H2ASN_MsgChoice TAF_PS_GET_PDP_AUTH_INFO_CNF_STRU           */

    /* ^CGDNS */
    ID_EVT_TAF_PS_SET_PDP_DNS_INFO_CNF                      = TAF_PS_EVT_ID_BASE + 0x0123,           /* _H2ASN_MsgChoice TAF_PS_SET_PDP_DNS_INFO_CNF_STRU            */
    ID_EVT_TAF_PS_GET_PDP_DNS_INFO_CNF                      = TAF_PS_EVT_ID_BASE + 0x0124,           /* _H2ASN_MsgChoice TAF_PS_GET_PDP_DNS_INFO_CNF_STRU            */

    /* ^TRIG */
    ID_EVT_TAF_PS_TRIG_GPRS_DATA_CNF                        = TAF_PS_EVT_ID_BASE + 0x0125,           /* _H2ASN_MsgChoice TAF_PS_TRIG_GPRS_DATA_CNF_STRU              */

    /* ^DWINS */
    ID_EVT_TAF_PS_CONFIG_NBNS_FUNCTION_CNF                  = TAF_PS_EVT_ID_BASE + 0x0126,           /* _H2ASN_MsgChoice TAF_PS_CONFIG_NBNS_FUNCTION_CNF_STRU        */

    /* ^AUTHDATA */
    ID_EVT_TAF_PS_SET_AUTHDATA_INFO_CNF                     = TAF_PS_EVT_ID_BASE + 0x0127,           /* _H2ASN_MsgChoice TAF_PS_SET_AUTHDATA_INFO_CNF_STRU           */
    ID_EVT_TAF_PS_GET_AUTHDATA_INFO_CNF                     = TAF_PS_EVT_ID_BASE + 0x0128,           /* _H2ASN_MsgChoice TAF_PS_GET_AUTHDATA_INFO_CNF_STRU           */

    /* ^DNSQUERY */
    ID_EVT_TAF_PS_GET_NEGOTIATION_DNS_CNF                   = TAF_PS_EVT_ID_BASE + 0x0129,           /* _H2ASN_MsgChoice TAF_PS_GET_NEGOTIATION_DNS_CNF_STRU         */

    /* ^LTECS */
    ID_EVT_TAF_PS_LTECS_INFO_CNF                            = TAF_PS_EVT_ID_BASE + 0x012A,           /* _H2ASN_MsgChoice TAF_PS_LTECS_CNF_STRU                       */

    /* ^PDPROFMOD */
    ID_EVT_TAF_PS_SET_PDP_PROF_INFO_CNF                     = TAF_PS_EVT_ID_BASE + 0x012B,           /* _H2ASN_MsgChoice TAF_PS_SET_PDP_PROF_INFO_CNF_STRU           */

    /* +CEMODE */
    ID_EVT_TAF_PS_CEMODE_INFO_CNF                           = TAF_PS_EVT_ID_BASE + 0x012C,           /* _H2ASN_MsgChoice TAF_PS_CEMODE_CNF_STRU                      */

    /* �첽�ӿڻ�ȡSDF��Ϣ */
    ID_EVT_TAF_PS_GET_CID_SDF_CNF                           = TAF_PS_EVT_ID_BASE + 0x012D,           /* _H2ASN_MsgChoice TAF_PS_SDF_INFO_CNF_STRU */

    /* �����¼� */
    /* APS->IMSA֪ͨSRVCC CANCEL */
    ID_EVT_TAF_PS_SRVCC_CANCEL_NOTIFY_IND                   = TAF_PS_EVT_ID_BASE + 0x0200,           /* _H2ASN_MsgChoice TAF_SRVCC_CANCEL_NOTIFY_IND_STRU */

    ID_EVT_TAF_PS_SET_IMS_PDP_CFG_CNF                       = TAF_PS_EVT_ID_BASE + 0x0201,           /* _H2ASN_MsgChoice TAF_PS_SET_IMS_PDP_CFG_CNF_STRU */

    ID_EVT_TAF_PS_BUTT
};
typedef VOS_UINT32 TAF_PS_EVT_ID_ENUM_UINT32;
enum TAF_PS_CAUSE_ENUM
{
    /*----------------------------------------------------------------------
       TAF�ϱ����ڲ�ԭ��ֵ, ȡֵ��Χ[0x0000, 0x007F]
    *---------------------------------------------------------------------*/
    TAF_PS_CAUSE_SUCCESS                                    = (TAF_PS_CAUSE_APS_SECTION_BEGIN + 0),
    TAF_PS_CAUSE_INVALID_PARAMETER                          = (TAF_PS_CAUSE_APS_SECTION_BEGIN + 1),
    TAF_PS_CAUSE_CID_INVALID                                = (TAF_PS_CAUSE_APS_SECTION_BEGIN + 2),
    TAF_PS_CAUSE_PDP_ACTIVATE_LIMIT                         = (TAF_PS_CAUSE_APS_SECTION_BEGIN + 3),
    TAF_PS_CAUSE_SIM_INVALID                                = (TAF_PS_CAUSE_APS_SECTION_BEGIN + 4),
    TAF_PS_CAUSE_APS_TIME_OUT                               = (TAF_PS_CAUSE_APS_SECTION_BEGIN + 5),
    TAF_PS_CAUSE_OPERATION_CONFLICT                         = (TAF_PS_CAUSE_APS_SECTION_BEGIN + 6),
    TAF_PS_CAUSE_UNSUPPORT_PCSCF                            = (TAF_PS_CAUSE_APS_SECTION_BEGIN + 20),
    TAF_PS_CAUSE_UNKNOWN                                    = (TAF_PS_CAUSE_APS_SECTION_BEGIN + 127),

    /*----------------------------------------------------------------------
       TAF�ϱ���SM�ڲ�ԭ��ֵ, ȡֵ��Χ[0x0080, 0x00FF]
    *---------------------------------------------------------------------*/
    TAF_PS_CAUSE_SM_CONN_ESTABLISH_MAX_TIME_OUT             = (TAF_PS_CAUSE_SM_SECTION_BEGIN + 1),
    TAF_PS_CAUSE_SM_MAX_TIME_OUT                            = (TAF_PS_CAUSE_SM_SECTION_BEGIN + 2),
    TAF_PS_CAUSE_SM_INVALID_NSAPI                           = (TAF_PS_CAUSE_SM_SECTION_BEGIN + 3),
    TAF_PS_CAUSE_SM_MODIFY_COLLISION                        = (TAF_PS_CAUSE_SM_SECTION_BEGIN + 4),
    TAF_PS_CAUSE_SM_DUPLICATE                               = (TAF_PS_CAUSE_SM_SECTION_BEGIN + 5),
    TAF_PS_CAUSE_SM_RAB_SETUP_FAILURE                       = (TAF_PS_CAUSE_SM_SECTION_BEGIN + 6),
    TAF_PS_CAUSE_SM_SGSN_VER_PRE_R99                        = (TAF_PS_CAUSE_SM_SECTION_BEGIN + 7),

    /*----------------------------------------------------------------------
       TAF�ϱ���SM����ԭ��ֵ, ȡֵ��Χ[0x0100, 0x01FF]
       ����3GPPЭ���Ѿ������˾����(E)SM����ԭ��ֵ, (E)SM�ϱ���ȡֵΪЭ��
       �����ԭ��ֵ����ƫ����(0x100)
       (1) SM Cause : Refer to TS 24.008 section 10.5.6.6
       (2) ESM Cause: Refer to TS 24.301 section 9.9.4.4
    *---------------------------------------------------------------------*/
    TAF_PS_CAUSE_SM_NW_OPERATOR_DETERMINED_BARRING          = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 8),
    TAF_PS_CAUSE_SM_NW_MBMS_BC_INSUFFICIENT                 = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 24),
    TAF_PS_CAUSE_SM_NW_LLC_OR_SNDCP_FAILURE                 = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 25),
    TAF_PS_CAUSE_SM_NW_INSUFFICIENT_RESOURCES               = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 26),
    TAF_PS_CAUSE_SM_NW_MISSING_OR_UKNOWN_APN                = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 27),
    TAF_PS_CAUSE_SM_NW_UNKNOWN_PDP_ADDR_OR_TYPE             = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 28),
    TAF_PS_CAUSE_SM_NW_USER_AUTHENTICATION_FAIL             = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 29),
    TAF_PS_CAUSE_SM_NW_ACTIVATION_REJECTED_BY_GGSN          = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 30),
    TAF_PS_CAUSE_SM_NW_ACTIVATION_REJECTED_UNSPECIFIED      = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 31),
    TAF_PS_CAUSE_SM_NW_SERVICE_OPTION_NOT_SUPPORTED         = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 32),
    TAF_PS_CAUSE_SM_NW_REQUESTED_SERVICE_NOT_SUBSCRIBED     = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 33),
    TAF_PS_CAUSE_SM_NW_SERVICE_OPTION_TEMP_OUT_ORDER        = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 34),
    TAF_PS_CAUSE_SM_NW_NSAPI_ALREADY_USED                   = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 35),
    TAF_PS_CAUSE_SM_NW_REGULAR_DEACTIVATION                 = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 36),
    TAF_PS_CAUSE_SM_NW_QOS_NOT_ACCEPTED                     = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 37),
    TAF_PS_CAUSE_SM_NW_NETWORK_FAILURE                      = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 38),
    TAF_PS_CAUSE_SM_NW_REACTIVATION_REQUESTED               = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 39),
    TAF_PS_CAUSE_SM_NW_FEATURE_NOT_SUPPORT                  = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 40),
    TAF_PS_CAUSE_SM_NW_SEMANTIC_ERR_IN_TFT                  = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 41),
    TAF_PS_CAUSE_SM_NW_SYNTACTIC_ERR_IN_TFT                 = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 42),
    TAF_PS_CAUSE_SM_NW_UKNOWN_PDP_CONTEXT                   = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 43),
    TAF_PS_CAUSE_SM_NW_SEMANTIC_ERR_IN_PACKET_FILTER        = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 44),
    TAF_PS_CAUSE_SM_NW_SYNCTACTIC_ERR_IN_PACKET_FILTER      = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 45),
    TAF_PS_CAUSE_SM_NW_PDP_CONTEXT_WITHOUT_TFT_ACTIVATED    = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 46),
    TAF_PS_CAUSE_SM_NW_MULTICAST_GROUP_MEMBERHHSHIP_TIMEOUT = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 47),
    TAF_PS_CAUSE_SM_NW_REQUEST_REJECTED_BCM_VIOLATION       = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 48),
    TAF_PS_CAUSE_SM_NW_LAST_PDN_DISCONN_NOT_ALLOWED         = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 49),
    TAF_PS_CAUSE_SM_NW_PDP_TYPE_IPV4_ONLY_ALLOWED           = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 50),
    TAF_PS_CAUSE_SM_NW_PDP_TYPE_IPV6_ONLY_ALLOWED           = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 51),
    TAF_PS_CAUSE_SM_NW_SINGLE_ADDR_BEARERS_ONLY_ALLOWED     = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 52),
    TAF_PS_CAUSE_SM_NW_INFORMATION_NOT_RECEIVED             = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 53),
    TAF_PS_CAUSE_SM_NW_PDN_CONNECTION_DOES_NOT_EXIST        = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 54),
    TAF_PS_CAUSE_SM_NW_SAME_APN_MULTI_PDN_CONNECTION_NOT_ALLOWED = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 55),
    TAF_PS_CAUSE_SM_NW_COLLISION_WITH_NW_INITIATED_REQUEST  = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 56),
    TAF_PS_CAUSE_SM_NW_UNSUPPORTED_QCI_VALUE                = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 59),
    TAF_PS_CAUSE_SM_NW_BEARER_HANDLING_NOT_SUPPORTED        = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 60),
    TAF_PS_CAUSE_SM_NW_INVALID_TI                           = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 81),
    TAF_PS_CAUSE_SM_NW_SEMANTICALLY_INCORRECT_MESSAGE       = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 95),
    TAF_PS_CAUSE_SM_NW_INVALID_MANDATORY_INFO               = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 96),
    TAF_PS_CAUSE_SM_NW_MSG_TYPE_NON_EXISTENT                = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 97),
    TAF_PS_CAUSE_SM_NW_MSG_TYPE_NOT_COMPATIBLE              = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 98),
    TAF_PS_CAUSE_SM_NW_IE_NON_EXISTENT                      = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 99),
    TAF_PS_CAUSE_SM_NW_CONDITIONAL_IE_ERR                   = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 100),
    TAF_PS_CAUSE_SM_NW_MSG_NOT_COMPATIBLE                   = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 101),
    TAF_PS_CAUSE_SM_NW_PROTOCOL_ERR_UNSPECIFIED             = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 111),
    TAF_PS_CAUSE_SM_NW_APN_RESTRICTION_INCOMPATIBLE         = (TAF_PS_CAUSE_SM_NW_SECTION_BEGIN + 112),

    /*----------------------------------------------------------------------
       TAF�ϱ���GMM�ڲ�ԭ��ֵ, ȡֵ��Χ[0x0200, 0x02FF]
    *---------------------------------------------------------------------*/
    TAF_PS_CAUSE_GMM_GPRS_NOT_SUPPORT                       = (TAF_PS_CAUSE_GMM_SECTION_BEGIN + 1),
    TAF_PS_CAUSE_GMM_FORBID_LA                              = (TAF_PS_CAUSE_GMM_SECTION_BEGIN + 2),
    TAF_PS_CAUSE_GMM_AUTHENTICATION_FAIL                    = (TAF_PS_CAUSE_GMM_SECTION_BEGIN + 3),
    TAF_PS_CAUSE_GMM_PS_DETACH                              = (TAF_PS_CAUSE_GMM_SECTION_BEGIN + 4),
    TAF_PS_CAUSE_GMM_ACCESS_BARRED                          = (TAF_PS_CAUSE_GMM_SECTION_BEGIN + 5),
    TAF_PS_CAUSE_GMM_NO_PDP_CONTEXT                         = (TAF_PS_CAUSE_GMM_SECTION_BEGIN + 6),

    /*----------------------------------------------------------------------
       TAF�ϱ���GMM����ԭ��ֵ, ȡֵ��Χ[0x0300, 0x03FF]
       ����3GPPЭ���Ѿ������˾����GMM����ԭ��ֵ, ƽ̨�ϱ���GMM����ԭ��ֵ
       ȡֵΪЭ�鶨���ԭ��ֵ����ƫ����(0x100)
       Gmm Cause: Refer to TS 24.008 section 10.5.5.14
    *---------------------------------------------------------------------*/
    TAF_PS_CAUSE_GMM_NW_IMSI_UNKNOWN_IN_HLR                 = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 2),
    TAF_PS_CAUSE_GMM_NW_ILLEGAL_MS                          = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 3),
    TAF_PS_CAUSE_GMM_NW_IMSI_NOT_ACCEPTED                   = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 5),
    TAF_PS_CAUSE_GMM_NW_ILLEGAL_ME                          = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 6),
    TAF_PS_CAUSE_GMM_NW_GPRS_SERV_NOT_ALLOW                 = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 7),
    TAF_PS_CAUSE_GMM_NW_GPRS_SERV_AND_NON_GPRS_SERV_NOT_ALLOW = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 8),
    TAF_PS_CAUSE_GMM_NW_MS_ID_NOT_DERIVED                   = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 9),
    TAF_PS_CAUSE_GMM_NW_IMPLICIT_DETACHED                   = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 10),
    TAF_PS_CAUSE_GMM_NW_PLMN_NOT_ALLOW                      = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 11),
    TAF_PS_CAUSE_GMM_NW_LA_NOT_ALLOW                        = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 12),
    TAF_PS_CAUSE_GMM_NW_ROAMING_NOT_ALLOW_IN_LA             = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 13),
    TAF_PS_CAUSE_GMM_NW_GPRS_SERV_NOT_ALLOW_IN_PLMN         = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 14),
    TAF_PS_CAUSE_GMM_NW_NO_SUITABL_CELL                     = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 15),
    TAF_PS_CAUSE_GMM_NW_MSC_UNREACHABLE                     = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 16),
    TAF_PS_CAUSE_GMM_NW_NETWORK_FAILURE                     = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 17),
    TAF_PS_CAUSE_GMM_NW_MAC_FAILURE                         = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 20),
    TAF_PS_CAUSE_GMM_NW_SYNCH_FAILURE                       = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 21),
    TAF_PS_CAUSE_GMM_NW_PROCEDURE_CONGESTION                = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 22),
    TAF_PS_CAUSE_GMM_NW_GSM_AUT_UNACCEPTABLE                = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 23),
    TAF_PS_CAUSE_GMM_NW_NOT_AUTHORIZED_FOR_THIS_CSG         = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 25),
    TAF_PS_CAUSE_GMM_NW_NO_PDP_CONTEXT_ACT                  = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 40),
    TAF_PS_CAUSE_GMM_NW_RETRY_UPON_ENTRY_CELL               = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 60),
    TAF_PS_CAUSE_GMM_NW_SEMANTICALLY_INCORRECT_MSG          = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 95),
    TAF_PS_CAUSE_GMM_NW_INVALID_MANDATORY_INF               = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 96),
    TAF_PS_CAUSE_GMM_NW_MSG_NONEXIST_NOTIMPLEMENTE          = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 97),
    TAF_PS_CAUSE_GMM_NW_MSG_TYPE_NOT_COMPATIBLE             = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 98),
    TAF_PS_CAUSE_GMM_NW_IE_NONEXIST_NOTIMPLEMENTED          = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 99),
    TAF_PS_CAUSE_GMM_NW_CONDITIONAL_IE_ERROR                = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 100),
    TAF_PS_CAUSE_GMM_NW_MSG_NOT_COMPATIBLE                  = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 101),
    TAF_PS_CAUSE_GMM_NW_PROTOCOL_ERROR                      = (TAF_PS_CAUSE_GMM_NW_SECTION_BEGIN + 111),

    TAF_PS_CAUSE_BUTT                                       = 0xFFFFFFFF
};
typedef VOS_UINT32 TAF_PS_CAUSE_ENUM_UINT32;



enum TAF_PDP_TYPE_ENUM
{
    TAF_PDP_IPV4                        = 0x01,
    TAF_PDP_IPV6                        = 0x02,
    TAF_PDP_IPV4V6                      = 0x03,
    TAF_PDP_PPP                         = 0x04,

    TAF_PDP_TYPE_BUTT                   = 0xFF
};
typedef VOS_UINT8 TAF_PDP_TYPE_ENUM_UINT8;



enum TAF_PDP_AUTH_TYPE_ENUM
{
    TAF_PDP_AUTH_TYPE_NONE              = 0x00,
    TAF_PDP_AUTH_TYPE_PAP               = 0x01,
    TAF_PDP_AUTH_TYPE_CHAP              = 0x02,
    TAF_PDP_AUTH_TYPE_MS_CHAP_V2        = 0x03,

    TAF_PDP_AUTH_TYPE_BUTT
};
typedef VOS_UINT8 TAF_PDP_AUTH_TYPE_ENUM_UINT8;



enum TAF_AUTH_TYPE_ENUM
{
    TAF_PDP_ACTIVATE_NO_AUTH            = 0x00,                                 /*PDP����ʱ����Ҫ��Ȩ�û�*/
    TAF_PDP_ACTIVATE_AUTH               = 0x01,                                 /*PDP����ʱ��Ҫ��Ȩ�û�*/

    TAF_AUTH_BUTT                       = 0xFF
};
typedef VOS_UINT8 TAF_AUTH_TYPE_ENUM_UINT8;



enum TAF_PDP_ACTIVE_STATUS_ENUM
{
    TAF_PDP_INACTIVE                    = 0x00,                                 /*PDPδ����*/
    TAF_PDP_ACTIVE                      = 0x01,                                 /*PDP�Ѽ���*/

    TAF_PDP_ACTIVE_BUTT                 = 0xFF
};
typedef VOS_UINT8 TAF_PDP_ACTIVE_STATUS_ENUM_UINT8;



enum TAF_GPRS_ACTIVE_TYPE_ENUM
{
    TAF_IP_ACTIVE_TE_PPP_MT_PPP_TYPE            = 0x00,
    TAF_PPP_ACTIVE_TE_PPP_MT_NOT_PPP_TYPE       = 0x01,
    TAF_IP_ACTIVE_TE_NOT_PPP_MT_NOT_PPP_TYPE    = 0x02,

    TAF_IP_ACTIVE_TE_BUTT
};
typedef VOS_UINT8 TAF_GPRS_ACTIVE_TYPE_UINT8;



enum TAF_L2P_TYPE_ENUM
{
    TAF_L2P_PPP                         = 0x00,
    TAF_L2P_NULL                        = 0x01,

    TAF_L2P_BUTT
};
typedef VOS_UINT8 TAF_L2P_TYPE_ENUM_UINT8;



enum TAF_PDP_H_COMP_ENUM
{
    TAF_PDP_H_COMP_OFF                  = 0x00,             /* default if value is omitted */
    TAF_PDP_H_COMP_ON                   = 0x01,             /* manufacturer preferred compression */
    TAF_PDP_H_COMP_RFC1144              = 0x02,             /* RFC 1144 */
    TAF_PDP_H_COMP_RFC2507              = 0x03,             /* RFC 2507 */

    TAF_PDP_H_COMP_BUTT                 = 0xFF
};
typedef VOS_UINT8 TAF_PDP_H_COMP_ENUM_UINT8;



enum TAF_PDP_D_COMP_ENUM
{
    TAF_PDP_D_COMP_OFF                  = 0x00,             /* default if value is omitted */
    TAF_PDP_D_COMP_ON                   = 0x01,             /* manufacturer preferred compression */
    TAF_PDP_D_COMP_V42                  = 0x02,             /* V.42 compression */

    TAF_PDP_D_COMP_BUTT                 = 0xFF
};
typedef VOS_UINT8 TAF_PDP_D_COMP_ENUM_UINT8;
enum TAF_UMTS_QOS_TRAFFIC_CLASS_ENUM
{
    TAF_UMTS_QOS_TRAFFIC_CLASS_SUBS     = 0x00,                                 /* Subscribed                  */
    TAF_UMTS_QOS_TRAFFIC_CLASS_CONV     = 0x01,                                 /* Conversational              */
    TAF_UMTS_QOS_TRAFFIC_CLASS_STRM     = 0x02,                                 /* Streaming                   */
    TAF_UMTS_QOS_TRAFFIC_CLASS_INTR     = 0x03,                                 /* Interactive                 */
    TAF_UMTS_QOS_TRAFFIC_CLASS_BACK     = 0x04,                                 /* Background                  */
    TAF_UMTS_QOS_TRAFFIC_CLASS_BUTT     = 0xff                                  /* force max to 0xff so that
                                                                                    enum is defined as a byte   */
};
typedef VOS_UINT8 TAF_UMTS_QOS_TRAFFIC_CLASS_ENUM_UINT8;



enum TAF_PF_TRANS_DIRECTION_ENUM
{
    TAF_PF_TRANS_DIRECTION_PRE_REL7     = 0x00,             /* 0 - Pre-Release 7 TFT filter (see 3GPP TS 24.008 [8], table 10.5.162) */
    TAF_PF_TRANS_DIRECTION_UPLINK       = 0x01,             /* 1 - Uplink */
    TAF_PF_TRANS_DIRECTION_DOWNLINK     = 0x02,             /* 2 - Downlink */
    TAF_PF_TRANS_DIRECTION_BIDIRECTION  = 0x03,             /* 3 - Birectional (Up & Downlink) (default if omitted) */

    TAF_PF_TRANS_DIRECTION_BUTT         = 0xFF
};
typedef VOS_UINT8 TAF_PF_TRANS_DIRECTION_ENUM_UINT8;



enum TAF_DSFLOW_CLEAR_MODE_ENUM
{
    TAF_DSFLOW_CLEAR_TOTAL              = 1,   /*��������RABID������*/
    TAF_DSFLOW_CLEAR_WITH_RABID,               /*����ָ��RABID������*/

    TAF_DSFLOW_CLEAR_BUTT
};
typedef VOS_UINT8 TAF_DSFLOW_CLEAR_MODE_ENUM_UINT8;



enum TAF_PDP_EMC_IND_ENUM
{
    TAF_PDP_NOT_FOR_EMC                 = 0x00,
    TAF_PDP_FOR_EMC                     = 0x01,

    TAF_PDP_EMC_IND_BUTT                = 0xFF
};
typedef VOS_UINT8 TAF_PDP_EMC_IND_ENUM_UINT8;



enum TAF_PDP_IPV4_ADDR_ALLOC_TYPE_ENUM
{
    TAF_PDP_IPV4_ADDR_ALLOC_TYPE_NAS    = 0x00,
    TAF_PDP_IPV4_ADDR_ALLOC_TYPE_DHCP   = 0x01,

    TAF_PDP_IPV4_ADDR_ALLOC_BUTT        = 0xFF
};
typedef VOS_UINT8 TAF_PDP_IPV4_ADDR_ALLOC_TYPE_ENUM_UINT8;



enum TAF_PDP_PCSCF_DISCOVERY_ENUM
{
    TAF_PDP_PCSCF_DISCOVERY_NOT_INFLUENCED  = 0x00,
    TAF_PDP_PCSCF_DISCOVERY_THROUGH_NAS_SIG = 0x01,
    TAF_PDP_PCSCF_DISCOVERY_THROUGH_DHCP    = 0x02,

    TAF_PDP_PCSCF_DISCOVERY_BUTT            = 0xFF
};
typedef VOS_UINT8 TAF_PDP_PCSCF_DISCOVERY_ENUM_UINT8;



enum TAF_PDP_IM_CN_SIG_FLAG_ENUM
{
    TAF_PDP_NOT_FOR_IMS_CN_SIG_ONLY     = 0x00,
    TAF_PDP_FOR_IM_CN_SIG_ONLY          = 0x01,

    TAF_PDP_IM_CN_SIG_FLAG_BUTT         = 0xFF
};
typedef VOS_UINT8 TAF_PDP_IM_CN_SIG_FLAG_ENUM_UINT8;



enum TAF_PDP_ANSWER_TYPE_ENUM
{
    TAF_PDP_ANSWER_TYPE_ACCEPT             = 0x00,             /* ���ܺ��� */
    TAF_PDP_ANSWER_TYPE_REJECT             = 0x01,             /* �ܾ����� */

    TAF_PDP_ANSWER_TYPE_BUTT
};
typedef VOS_UINT8 TAF_PDP_ANSWER_TYPE_ENUM_UINT8;



enum TAF_PDP_ANSWER_MODE_ENUM
{
    TAF_PDP_ANSWER_MODE_MANUAL             = 0x00,             /* �˹�Ӧ��ʽ */
    TAF_PDP_ANSWER_MODE_AUTO               = 0x01,             /* �Զ�Ӧ��ʽ */

    TAF_PDP_ANSWER_MODE_BUTT
};
typedef VOS_UINT8 TAF_PDP_ANSWER_MODE_ENUM_UINT8;

#if (FEATURE_ON == FEATURE_IMS)
/*****************************************************************************
 �ṹ����: TAF_SRVCC_CANCEL_NOTIFY_ENUM
 �ṹ˵��: APS->IMSA֪ͨSRVCC CANECL
*****************************************************************************/
enum TAF_SRVCC_CANCEL_NOTIFY_ENUM
{
    TAF_SRVCC_CANCEL_NOTIFY_HO_CANCELLED    = 0,

    TAF_SRVCC_CANCEL_NOTIFY_IND_BUTT
};
typedef VOS_UINT32 TAF_SRVCC_CANCEL_NOTIFY_ENUM_UINT32;

#endif

/* Added by l60609 for L-C��������Ŀ, 2014-01-06, Begin */
/*****************************************************************************
 ö����   :TAF_PDP_REQUEST_TYPE_ENUM_UINT8
 ö��˵�� :PDN������������
 1.��    ��   : 2014��01��08��
   ��    ��   : l60609
   �޸�����   : �½�
*****************************************************************************/
enum TAF_PDP_REQUEST_TYPE_ENUM
{
    TAF_PDP_REQUEST_TYPE_INITIAL        = 0x1,
    TAF_PDP_REQUEST_TYPE_HANDOVER       = 0x2,
    TAF_PDP_REQUEST_TYPE_UNUSED         = 0x3,
    TAF_PDP_REQUEST_TYPE_EMERGENCY      = 0x4,
    TAF_PDP_REQUEST_TYPE_BUTT
};
typedef VOS_UINT8 TAF_PDP_REQUEST_TYPE_ENUM_UINT8;
/* Added by l60609 for L-C��������Ŀ, 2014-01-06, End */

/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/


typedef struct
{
    MSG_HEADER_STRU                     stHeader;
    VOS_UINT32                          ulEvtId;
    VOS_UINT8                           aucContent[4];

} TAF_PS_EVT_STRU;



typedef struct
{
    VOS_UINT32                          ulDSLinkTime;                           /* DS����ʱ�� */
    VOS_UINT32                          ulDSSendFluxLow;                        /* DS�����������ĸ��ֽ� */
    VOS_UINT32                          ulDSSendFluxHigh;                       /* DS�����������ĸ��ֽ� */
    VOS_UINT32                          ulDSReceiveFluxLow;                     /* DS�����������ĸ��ֽ� */
    VOS_UINT32                          ulDSReceiveFluxHigh;                    /* DS�����������ĸ��ֽ� */

} TAF_DSFLOW_INFO_STRU;
typedef struct
{
    VOS_UINT32                          ulCurrentSendRate;                      /*��ǰ��������*/
    VOS_UINT32                          ulCurrentReceiveRate;                   /*��ǰ��������*/
    VOS_UINT32                          ulQosSendRate;                          /*QOSЭ�̷�������*/
    VOS_UINT32                          ulQosReceiveRate;                       /*QOSЭ�̽�������*/
    TAF_DSFLOW_INFO_STRU                stCurrentFlowInfo;                      /*��ǰ����������Ϣ*/

} TAF_DSFLOW_REPORT_STRU;
typedef struct
{
    TAF_DSFLOW_INFO_STRU                stCurrentFlowInfo;  /*��ǰ����������Ϣ*/
    TAF_DSFLOW_INFO_STRU                stTotalFlowInfo;    /*�ۼ�������Ϣ*/

} TAF_DSFLOW_QUERY_INFO_STRU;



typedef struct
{
    /* 0 QCI is selected by network
       [1 - 4]value range for guranteed bit rate Traffic Flows
       [5 - 9]value range for non-guarenteed bit rate Traffic Flows */
    VOS_UINT8                           ucQCI;

    VOS_UINT8                           aucReserved[3];

    /* DL GBR in case of GBR QCI, The value is in kbit/s */
    VOS_UINT32                          ulDLGBR;

    /* UL GBR in case of GBR QCI, The value is in kbit/s */
    VOS_UINT32                          ulULGBR;

    /* DL MBR in case of GBR QCI, The value is in kbit/s */
    VOS_UINT32                          ulDLMBR;

    /* UL MBR in case of GBR QCI, The value is in kbit/s */
    VOS_UINT32                          ulULMBR;

}TAF_EPS_QOS_STRU;



typedef struct
{
    TAF_AUTH_TYPE_ENUM_UINT8            enAuth;                                   /*Ŀǰ��֧���Ƿ��Ȩ���Ժ�����Ϊ֧�����ּ�Ȩ�㷨*/

    VOS_UINT8                           aucReserved[3];

    /* aucUserName[0]�����û������� */
    VOS_UINT8                           aucUserName[TAF_MAX_GW_AUTH_USERNAME_LEN + 1];

    /* aucPassword[0]�������볤�� */
    VOS_UINT8                           aucPassword[TAF_MAX_GW_AUTH_PASSWORD_LEN + 1];

} TAF_PDP_AUTH_STRU;
typedef struct
{
    VOS_UINT8                           ucLength;
    VOS_UINT8                           aucValue[TAF_MAX_APN_LEN];

} TAF_PDP_APN_STRU;



typedef struct
{
    VOS_UINT32                          bitOpPrimDnsAddr    : 1;
    VOS_UINT32                          bitOpSecDnsAddr     : 1;
    VOS_UINT32                          bitOpSpare          : 30;

    VOS_UINT8                           aucPrimDnsAddr[TAF_IPV4_ADDR_LEN];
    VOS_UINT8                           aucSecDnsAddr[TAF_IPV4_ADDR_LEN];

} TAF_PDP_DNS_STRU;



typedef struct
{
    VOS_UINT32                          bitOpPrimNbnsAddr   : 1;
    VOS_UINT32                          bitOpSecNbnsAddr    : 1;
    VOS_UINT32                          bitOpSpare          : 30;

    VOS_UINT8                           aucPrimNbnsAddr[TAF_IPV4_ADDR_LEN];
    VOS_UINT8                           aucSecNbnsAddr[TAF_IPV4_ADDR_LEN];

} TAF_PDP_NBNS_STRU;



typedef struct
{
    VOS_UINT32                          bitOpGateWayAddr    : 1;
    VOS_UINT32                          bitOpSpare          : 31;

    VOS_UINT8                           aucGateWayAddr[TAF_IPV4_ADDR_LEN];

} TAF_PDP_GATEWAY_STRU;



typedef struct
{
    VOS_UINT32                          bitOpPrimPcscfAddr  : 1;
    VOS_UINT32                          bitOpSecPcscfAddr   : 1;
    VOS_UINT32                          bitOpThiPcscfAddr   : 1;
    VOS_UINT32                          bitOpSpare          : 29;

    VOS_UINT8                           aucPrimPcscfAddr[TAF_IPV4_ADDR_LEN];
    VOS_UINT8                           aucSecPcscfAddr[TAF_IPV4_ADDR_LEN];
    VOS_UINT8                           aucThiPcscfAddr[TAF_IPV4_ADDR_LEN];

} TAF_PDP_PCSCF_STRU;



typedef struct
{
    VOS_UINT32                          bitOpPrimPcscfAddr  : 1;
    VOS_UINT32                          bitOpSecPcscfAddr   : 1;
    VOS_UINT32                          bitOpThiPcscfAddr   : 1;
    VOS_UINT32                          bitOpSpare          : 29;

    VOS_UINT8                           aucPrimPcscfAddr[TAF_IPV6_ADDR_LEN];
    VOS_UINT8                           aucSecPcscfAddr[TAF_IPV6_ADDR_LEN];
    VOS_UINT8                           aucThiPcscfAddr[TAF_IPV6_ADDR_LEN];

} TAF_PDP_IPV6_PCSCF_STRU;



typedef struct
{
    VOS_UINT32                          bitOpPrimDnsAddr    : 1;
    VOS_UINT32                          bitOpSecDnsAddr     : 1;
    VOS_UINT32                          bitOpSpare          : 30;

    VOS_UINT8                           aucPrimDnsAddr[TAF_IPV6_ADDR_LEN];
    VOS_UINT8                           aucSecDnsAddr[TAF_IPV6_ADDR_LEN];

} TAF_PDP_IPV6_DNS_STRU;



typedef struct
{
    /* IPV4:1, IPV6:2, IPV4V6:3, PPP:4 */
    TAF_PDP_TYPE_ENUM_UINT8             enPdpType;
    VOS_UINT8                           aucReserved[3];
    VOS_UINT8                           aucIpv4Addr[TAF_IPV4_ADDR_LEN];
    VOS_UINT8                           aucIpv6Addr[TAF_IPV6_ADDR_LEN];
} TAF_PDP_ADDR_STRU;
typedef struct
{
    TAF_PDP_ADDR_STRU                   stPdpAddr;
    TAF_PDP_APN_STRU                    stApn;
    TAF_PDP_D_COMP_ENUM_UINT8           enPdpDcomp;
    TAF_PDP_H_COMP_ENUM_UINT8           enPdpHcomp;

    /* 0 - IPv4 Address Allocation through NAS Signaling (default if omitted)
       1 - IPv4 Address Allocated through DHCP */
    TAF_PDP_IPV4_ADDR_ALLOC_TYPE_ENUM_UINT8 enIpv4AddrAlloc;

    /* 0 - PDP context is not for emergency bearer services
       1 - PDP context is for emergency bearer services */
    TAF_PDP_EMC_IND_ENUM_UINT8          enEmergencyInd;

    TAF_PDP_PCSCF_DISCOVERY_ENUM_UINT8  enPcscfDiscovery;

    TAF_PDP_IM_CN_SIG_FLAG_ENUM_UINT8   enImCnSignalFlg;

    VOS_UINT8                           aucReserved2[2];

}TAF_PDP_PRIM_CONTEXT_STRU;


typedef struct
{
    TAF_PDP_AUTH_TYPE_ENUM_UINT8        enAuthType;
    VOS_UINT8                           aucPlmn[TAF_MAX_AUTHDATA_PLMN_LEN + 1];
    VOS_UINT8                           aucPassword[TAF_MAX_AUTHDATA_PASSWORD_LEN + 1];
    VOS_UINT8                           aucUsername[TAF_MAX_AUTHDATA_USERNAME_LEN + 1];
}TAF_PDP_AUTHDATA_STRU;



typedef struct
{
    VOS_UINT32                          bitOpRmtIpv4AddrAndMask     : 1;
    VOS_UINT32                          bitOpRmtIpv6AddrAndMask     : 1;
    VOS_UINT32                          bitOpProtocolId             : 1;
    VOS_UINT32                          bitOpSingleLocalPort        : 1;
    VOS_UINT32                          bitOpLocalPortRange         : 1;
    VOS_UINT32                          bitOpSingleRemotePort       : 1;
    VOS_UINT32                          bitOpRemotePortRange        : 1;
    VOS_UINT32                          bitOpSecuParaIndex          : 1;
    VOS_UINT32                          bitOpTypeOfService          : 1;
    VOS_UINT32                          bitOpFlowLabelType          : 1;
    VOS_UINT32                          bitOpSpare                  : 22;

    VOS_UINT8                           ucPacketFilterId;
    VOS_UINT8                           ucNwPacketFilterId;
    TAF_PF_TRANS_DIRECTION_ENUM_UINT8   enDirection;
    VOS_UINT8                           ucPrecedence;                           /* packet filter evaluation precedence */

    VOS_UINT32                          ulSecuParaIndex;                        /* SPI */
    VOS_UINT16                          usSingleLcPort;
    VOS_UINT16                          usLcPortHighLimit;
    VOS_UINT16                          usLcPortLowLimit;
    VOS_UINT16                          usSingleRmtPort;
    VOS_UINT16                          usRmtPortHighLimit;
    VOS_UINT16                          usRmtPortLowLimit;
    VOS_UINT8                           ucProtocolId;                           /* Э��� */
    VOS_UINT8                           ucTypeOfService;                        /* TOS */
    VOS_UINT8                           ucTypeOfServiceMask;                    /* TOS Mask */
    VOS_UINT8                           aucReserved[1];

    /* aucRmtIpv4Address[0]ΪIP��ַ���ֽ�λ
       aucRmtIpv4Address[3]Ϊ���ֽ�λ */
    VOS_UINT8                           aucRmtIpv4Address[TAF_IPV4_ADDR_LEN];

    /* aucRmtIpv4Mask[0]ΪIP��ַ���ֽ�λ ,
       aucRmtIpv4Mask[3]Ϊ���ֽ�λ*/
    VOS_UINT8                           aucRmtIpv4Mask[TAF_IPV4_ADDR_LEN];

    /* ucRmtIpv6Address[0]ΪIPv6�ӿڱ�ʶ���ֽ�λ
       ucRmtIpv6Address[7]ΪIPv6�ӿڱ�ʶ���ֽ�λ */
    VOS_UINT8                           aucRmtIpv6Address[TAF_IPV6_ADDR_LEN];

    /* ucRmtIpv6Mask[0]Ϊ���ֽ�λ
       ucRmtIpv6Mask[7]Ϊ���ֽ�λ*/
    VOS_UINT8                           aucRmtIpv6Mask[TAF_IPV6_ADDR_LEN];

    VOS_UINT32                          ulFlowLabelType;                        /*FlowLabelType*/
}TAF_PDP_PF_STRU;
typedef struct
{
    VOS_UINT8                           ucTrafficClass;                         /*UMTS���ط����Ż�����*/
    VOS_UINT8                           ucDeliverOrder;                         /*SDU�����Ƿ���UMTS����*/
    VOS_UINT8                           ucDeliverErrSdu;                        /*SDU�����Ƿ���*/
    VOS_UINT8                           aucReserved1[1];
    VOS_UINT16                          usMaxSduSize;                           /*SDU��С���ֵ*/
    VOS_UINT8                           aucReserved2[2];
    VOS_UINT32                          ulMaxBitUl;                             /*����������� kbits/s*/
    VOS_UINT32                          ulMaxBitDl;                             /*����������� kbits/s*/
    VOS_UINT8                           ucResidualBer;
    VOS_UINT8                           ucSduErrRatio;                          /*SDU������*/
    VOS_UINT16                          usTransDelay;                           /*������ʱ, ��λ����*/
    VOS_UINT8                           ucTraffHandlePrior;                     /*����UMTS���ص�SDU�Ա��������ص�SDU*/
    VOS_UINT8                           aucReserved3[1];
    VOS_UINT8                           ucSrcStatisticsDescriptor;
    VOS_UINT8                           ucSignallingIndication;
    VOS_UINT32                          ulGuarantBitUl;                         /*��֤���д������� kbits/s*/
    VOS_UINT32                          ulGuarantBitDl;                         /*��֤���д������� kbits/s*/
}TAF_UMTS_QOS_STRU;
typedef struct
{
    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];
    TAF_PDP_PRIM_CONTEXT_STRU           stPriPdpInfo;

}TAF_PRI_PDP_QUERY_INFO_STRU;



typedef struct
{
    VOS_UINT8                           ucCid;
    VOS_UINT8                           ucPfNum;                                /* pf���� */
    VOS_UINT8                           aucReserved[2];
    TAF_PDP_PF_STRU                     astPfInfo[TAF_MAX_SDF_PF_NUM];          /* pf�� */

}TAF_TFT_QUREY_INFO_STRU;


typedef struct
{
    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];
    TAF_UMTS_QOS_STRU                   stQosInfo;

} TAF_UMTS_QOS_QUERY_INFO_STRU;



typedef struct
{
    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];
    TAF_PDP_DNS_STRU                    stDnsInfo;

}TAF_DNS_QUERY_INFO_STRU;


typedef struct
{
    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];
    TAF_PDP_AUTH_STRU                   stAuthInfo;

}TAF_AUTH_QUERY_INFO_STRU;


typedef struct
{
    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];
    TAF_PDP_AUTHDATA_STRU               stAuthDataInfo;

}TAF_AUTHDATA_QUERY_INFO_STRU;


typedef struct
{
    VOS_UINT32                          ulPfNum;                                /* pf���� */
    TAF_PDP_PF_STRU                     astPf[TAF_MAX_SDF_PF_NUM];              /* pf�� */
}TAF_PDP_TFT_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    VOS_UINT32                          bitOpLinkdRabId     : 1;
    VOS_UINT32                          bitOpPdpAddr        : 1;
    VOS_UINT32                          bitOpApn            : 1;
    VOS_UINT32                          bitOpEmergencyInd   : 1;
    VOS_UINT32                          bitOpImCnSignalFlg  : 1;
    VOS_UINT32                          bitOpCause          : 1;
    VOS_UINT32                          bitOpUmtsQos        : 1;
    VOS_UINT32                          bitOpEpsQos         : 1;
    VOS_UINT32                          bitOpTft            : 1;
    VOS_UINT32                          bitOpSpare          : 23;

    VOS_UINT8                           ucCid;
    VOS_UINT8                           ucRabId;
    VOS_UINT8                           ucLinkdRabId;
    TAF_PDP_EMC_IND_ENUM_UINT8          enEmergencyInd;
    TAF_PDP_IM_CN_SIG_FLAG_ENUM_UINT8   enImCnSignalFlg;
    VOS_UINT8                           aucReserved[3];
    TAF_PS_CAUSE_ENUM_UINT32            enCause;

    TAF_PDP_ADDR_STRU                   stPdpAddr;
    TAF_PDP_APN_STRU                    stApn;
    TAF_UMTS_QOS_STRU                   stUmtsQos;
    TAF_EPS_QOS_STRU                    stEpsQos;

    TAF_PDP_DNS_STRU                    stDns;
    TAF_PDP_NBNS_STRU                   stNbns;
    TAF_PDP_PCSCF_STRU                  stPcscf;
    TAF_PDP_GATEWAY_STRU                stGateWay;
    TAF_PDP_IPV6_DNS_STRU               stIpv6Dns;
    TAF_PDP_IPV6_PCSCF_STRU             stIpv6Pcscf;
    TAF_PDP_TFT_STRU                    stTft;

} TAF_PS_CALL_PDP_ACTIVATE_CNF_STRU;



typedef TAF_PS_CALL_PDP_ACTIVATE_CNF_STRU TAF_PS_CALL_PDP_ACTIVATE_IND_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    VOS_UINT32                          bitOpCauseEx        : 1;
    VOS_UINT32                          bitOpSpare          : 31;

    VOS_UINT8                           ucCid;
    TAF_PDP_TYPE_ENUM_UINT8             enPdpType;
    VOS_UINT8                           aucReserved[2];
    TAF_PS_CAUSE_ENUM_UINT32            enCause;

    /*----------------------------------------------------------------------
       enCauseEx��������:
       enPdpTypeΪIPv4/IPv6/PPP.

       enCauseEx���ܵ�ȡֵ:
       TAF_PS_CAUSE_SM_NW_PDP_TYPE_IPV4_ONLY_ALLOWED
       TAF_PS_CAUSE_SM_NW_PDP_TYPE_IPV6_ONLY_ALLOWED
       TAF_PS_CAUSE_SM_NW_SINGLE_ADDR_BEARERS_ONLY_ALLOWED

       enCauseEx���ʹ��:
       �û�����˫ջҵ��������(IPv4v6), TAF�ϱ���REJECT�¼�, ���enPdpType
       Ϊ��ջ(IPv4/IPv6), �û���Ҫ����enCauseEx, �����Ƿ��������ҵ������.

       enCauseExʹ������:
       �û�����˫ջҵ��������(IPv4v6), ���ཨ��IPv4���ͳ���, ͬʱЯ��ԭ��ֵ
       TAF_PS_CAUSE_SM_NW_SINGLE_ADDR_BEARERS_ONLY_ALLOWED, ���ڸó��ز�����
       ��СQOS, ���ڲ�ȥ����, TAF�ϱ�REJECT�¼�, IP����ΪIPv4, enCauseΪ
       QOS_NOT_ACCEPT, enCauseExΪTAF_PS_CAUSE_SM_NW_SINGLE_ADDR_BEARERS_ONLY_ALLOWED,
       �û���Ҫ���Է���IPv6ҵ��������.
    *---------------------------------------------------------------------*/
    TAF_PS_CAUSE_ENUM_UINT32            enCauseEx;

} TAF_PS_CALL_PDP_ACTIVATE_REJ_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    VOS_UINT32                          bitOpApn            : 1;
    VOS_UINT32                          bitOpPdpAddr        : 1;
    VOS_UINT32                          bitLinkdRabId       : 1;
    VOS_UINT32                          bitEmergencyInd     : 1;
    VOS_UINT32                          bitImCnSignalFlg    : 1;
    VOS_UINT32                          bitOpSpare          : 27;

    VOS_UINT8                           ucCid;
    VOS_UINT8                           ucRabId;
    VOS_UINT8                           ucLinkdRabId;
    TAF_PDP_EMC_IND_ENUM_UINT8          enEmergencyInd;
    TAF_PDP_IM_CN_SIG_FLAG_ENUM_UINT8   enImCnSignalFlg;
    VOS_UINT8                           aucReserved[3];

    TAF_PDP_ADDR_STRU                   stPdpAddr;
    TAF_PDP_APN_STRU                    stApn;

} TAF_PS_CALL_PDP_MANAGE_IND_STRU;



typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    VOS_UINT32                          bitLinkdRabId       : 1;
    VOS_UINT32                          bitOpUmtsQos        : 1;
    VOS_UINT32                          bitOpEpsQos         : 1;
    VOS_UINT32                          bitOpTft            : 1;
    VOS_UINT32                          bitOpSpare          : 28;

    VOS_UINT8                           ucCid;
    VOS_UINT8                           ucRabId;
    VOS_UINT8                           ucLinkdRabId;
    VOS_UINT8                           aucReserved[1];

    TAF_UMTS_QOS_STRU                   stUmtsQos;
    TAF_EPS_QOS_STRU                    stEpsQos;

    TAF_PDP_DNS_STRU                    stDns;
    TAF_PDP_NBNS_STRU                   stNbns;
    TAF_PDP_PCSCF_STRU                  stPcscf;
    TAF_PDP_IPV6_DNS_STRU               stIpv6Dns;
    TAF_PDP_IPV6_PCSCF_STRU             stIpv6Pcscf;
    TAF_PDP_TFT_STRU                    stTft;
} TAF_PS_CALL_PDP_MODIFY_CNF_STRU;


typedef TAF_PS_CALL_PDP_MODIFY_CNF_STRU TAF_PS_CALL_PDP_MODIFY_IND_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    VOS_UINT8                           ucCid;
    VOS_UINT8                           ucRabId;
    VOS_UINT8                           aucReserved[2];
    TAF_PS_CAUSE_ENUM_UINT32            enCause;

} TAF_PS_CALL_PDP_MODIFY_REJ_STRU;



typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    VOS_UINT8                           ucCid;
    VOS_UINT8                           ucRabId;
    TAF_PDP_TYPE_ENUM_UINT8             enPdpType;
    VOS_UINT8                           aucReserved[1];
    TAF_PS_CAUSE_ENUM_UINT32            enCause;

} TAF_PS_CALL_PDP_DEACTIVATE_CNF_STRU;



typedef TAF_PS_CALL_PDP_DEACTIVATE_CNF_STRU TAF_PS_CALL_PDP_DEACTIVATE_IND_STRU;



typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

} TAF_PS_CALL_PDP_PDP_DISCONNECT_IND_STRU;



typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
} TAF_PS_COMMON_CNF_STRU;



typedef struct
{
    VOS_UINT32                          bitOpPdpType        : 1;                /* PdpType*/
    VOS_UINT32                          bitOpApn            : 1;                /* aucApn*/
    VOS_UINT32                          bitOpPdpAddr        : 1;                /* aucPdpAddr*/
    VOS_UINT32                          bitOpPdpDcomp       : 1;                /* PdpDcomp*/
    VOS_UINT32                          bitOpPdpHcomp       : 1;                /* PdpHcomp*/
    VOS_UINT32                          bitOpIpv4AddrAlloc  : 1;                /* Ipv4AddrAlloc*/
    VOS_UINT32                          bitOpEmergencyInd   : 1;                /* Emergency Indication*/
    VOS_UINT32                          bitOpPcscfDiscovery : 1;                /* P-CSCF discovery */
    VOS_UINT32                          bitOpImCnSignalFlg  : 1;                /* IM CN Signalling Flag */
    VOS_UINT32                          bitOpSpare          : 23;

    VOS_UINT8                           ucDefined;                              /* 0:undefined, 1:defined */

    VOS_UINT8                           ucCid;

    /* 1 IP Internet Protocol (IETF STD 5) */
    /* 2 IPV6 Internet Protocol, version 6 (IETF RFC 2460) */
    /* 3 IPV4V6 Virtual <PDP_type> introduced to handle dual IP stack UE capability. (See 3GPP TS 24.301 [83]) */
    TAF_PDP_TYPE_ENUM_UINT8             enPdpType;

    VOS_UINT8                           aucReserved[1];

    /* Access Point Name*/
    VOS_UINT8                           aucApn[TAF_MAX_APN_LEN + 1];

    /* the MT in the address space applicable to the PDP.*/
    TAF_PDP_ADDR_STRU                   stPdpAddr;

    /* 0 - off  (default if value is omitted) */
    /* 1 - on (manufacturer preferred compression) */
    /* 2 - V.42bis */
    /* 3 - V.44 */
    TAF_PDP_D_COMP_ENUM_UINT8           enPdpDcomp;

    /* 0 - off (default if value is omitted) */
    /* 1 - on (manufacturer preferred compression) */
    /* 2 - RFC1144 (applicable for SNDCP only) */
    /* 3 - RFC2507*/
    /* 4 - RFC3095 (applicable for PDCP only)*/
    TAF_PDP_H_COMP_ENUM_UINT8           enPdpHcomp;

    /* 0 - IPv4 Address Allocation through NAS Signaling (default if omitted) */
    /* 1 - IPv4 Address Allocated through DHCP */
    TAF_PDP_IPV4_ADDR_ALLOC_TYPE_ENUM_UINT8 enIpv4AddrAlloc;

    /* 0 - PDP context is not for emergency bearer services */
    /* 1 - PDP context is for emergency bearer services */
    TAF_PDP_EMC_IND_ENUM_UINT8          enEmergencyFlg;

    /* 0 - Preference of P-CSCF address discovery not influenced by +CGDCONT */
    /* 1 - Preference of P-CSCF address discovery through NAS Signalling */
    /* 2 - Preference of P-CSCF address discovery through DHCP */
    TAF_PDP_PCSCF_DISCOVERY_ENUM_UINT8  enPcscfDiscovery;

    /* 0 - UE indicates that the PDP context is not for IM CN subsystem-related signalling only */
    /* 1 - UE indicates that the PDP context is for IM CN subsystem-related signalling only */
    TAF_PDP_IM_CN_SIG_FLAG_ENUM_UINT8   enImCnSignalFlg;

    VOS_UINT8                           aucReserved2[2];

}TAF_PDP_PRIM_CONTEXT_EXT_STRU;
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PDP_PRIM_CONTEXT_EXT_STRU       stPdpContextInfo;
} TAF_PS_SET_PRIM_PDP_CONTEXT_INFO_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_SET_PRIM_PDP_CONTEXT_INFO_CNF_STRU;

/*****************************************************************************
 �ṹ����: TAF_SET_IMS_PDP_CFG_STRU
 �ṹ˵��: ^IMSPDPCFG�������

 �޸���ʷ      :
  1.��    ��   : 2015��07��30��
    ��    ��   : z00301431
    �޸�����   : �����ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucCid;
    VOS_UINT8                           ucImsFlag;
    VOS_UINT8                           aucReserved[2];
} TAF_IMS_PDP_CFG_STRU;

/*****************************************************************************
 �ṹ����: TAF_PS_SET_IMS_PDP_CFG_REQ_STRU
 �ṹ˵��: ID_MSG_TAF_PS_SET_IMS_PDP_CFG_REQ
           ID_EVT_TAF_PS_SET_IMS_PDP_CFG_CNF��Ϣ

 �޸���ʷ      :
  1.��    ��   : 2015��07��30��
    ��    ��   : z00301431
    �޸�����   : �����ṹ
*****************************************************************************/
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_IMS_PDP_CFG_STRU                stImsPdpCfg;
} TAF_PS_SET_IMS_PDP_CFG_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_SET_IMS_PDP_CFG_CNF_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
} TAF_PS_GET_PRIM_PDP_CONTEXT_INFO_REQ_STRU;



typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_PRI_PDP_QUERY_INFO_STRU         astPdpContextQueryInfo[0];
} TAF_PS_GET_PRIM_PDP_CONTEXT_INFO_CNF_STRU;

/*****************************************************************************
 ���� : ������� +CGDSCONT
 ID   : ID_MSG_TAF_PS_SET_SEC_PDP_CONTEXT_INFO_REQ
        ID_MSG_TAF_PS_SET_SEC_PDP_CONTEXT_INFO_CNF
        ID_MSG_TAF_PS_GET_SEC_PDP_CONTEXT_INFO_REQ
        ID_MSG_TAF_PS_GET_SEC_PDP_CONTEXT_INFO_CNF
 REQ  : TAF_PS_SET_SEC_PDP_CONTEXT_INFO_REQ_STRU; TAF_PS_GET_SEC_PDP_CONTEXT_INFO_REQ_STRU
 CNF  : TAF_PS_SET_SEC_PDP_CONTEXT_INFO_CNF_STRU; TAF_PS_GET_SEC_PDP_CONTEXT_INFO_CNF_STRU
 IND  : -
 ˵�� : ...
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpLinkdCid       : 1;
    VOS_UINT32                          bitOpPdpDcomp       : 1;
    VOS_UINT32                          bitOpPdpHcomp       : 1;
    VOS_UINT32                          bitOpSpare          : 29;

    VOS_UINT8                           ucDefined;          /* 0:undefined, 1:defined */
    VOS_UINT8                           ucCid;              /* dedicated EPS Bearer context */
    VOS_UINT8                           ucLinkdCid;         /* Default EPS Bearer context */
    TAF_PDP_D_COMP_ENUM_UINT8           enPdpDcomp;         /* no used in LTE */
    TAF_PDP_H_COMP_ENUM_UINT8           enPdpHcomp;         /* no used in LTE */
    VOS_UINT8                           aucReserved[3];

} TAF_PDP_SEC_CONTEXT_EXT_STRU;
typedef struct
{
    VOS_UINT8                           ucCid;              /* [1��11] */
    VOS_UINT8                           ucLinkdCid;         /* [1��11] */
    TAF_PDP_D_COMP_ENUM_UINT8           enPdpDcomp;         /*����ѹ���㷨*/
    TAF_PDP_H_COMP_ENUM_UINT8           enPdpHcomp;         /*ͷѹ���㷨*/

}TAF_PDP_SEC_CONTEXT_STRU;



typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PDP_SEC_CONTEXT_EXT_STRU        stPdpContextInfo;

} TAF_PS_SET_SEC_PDP_CONTEXT_INFO_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_SET_SEC_PDP_CONTEXT_INFO_CNF_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
} TAF_PS_GET_SEC_PDP_CONTEXT_INFO_REQ_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_PDP_SEC_CONTEXT_STRU            astPdpContextQueryInfo[0];
} TAF_PS_GET_SEC_PDP_CONTEXT_INFO_CNF_STRU;



typedef struct
{
    VOS_UINT8                           aucCid[TAF_MAX_CID + 1];
} TAF_CID_LIST_STRU;


typedef struct
{
    VOS_UINT8                           ucCid;
    VOS_UINT8                           ucState;
    VOS_UINT8                           aucReserved[2];
} TAF_CID_STATE_STRU;


typedef struct
{
    VOS_UINT8                           ucState;                                /* 0 - deactivated,1 - activated */
    VOS_UINT8                           aucReserved[3];

    VOS_UINT8                           aucCid[TAF_MAX_CID + 1];
} TAF_CID_LIST_STATE_STRU;
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_CID_LIST_STATE_STRU             stCidListStateInfo;
} TAF_PS_SET_PDP_STATE_REQ_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
} TAF_PS_SET_PDP_STATE_CNF_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
} TAF_PS_GET_PDP_STATE_REQ_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_CID_STATE_STRU                  astCidStateInfo[0];
} TAF_PS_GET_PDP_STATE_CNF_STRU;


/*****************************************************************************
 ���� : ������� +CGTFT
 ID   : ID_MSG_L4A_SET_CGTFT_REQ
        ID_MSG_L4A_SET_CGTFT_CNF
        ID_MSG_L4A_READ_CGTFT_REQ
        ID_MSG_L4A_READ_CGTFT_CNF
 REQ  : L4A_SET_CGTFT_REQ_STRU;L4A_READ_CGTFT_REQ_STRU;
 CNF  : L4A_SET_CGTFT_CNF_STRU;L4A_READ_CGTFT_CNF_STRU;
 IND  : -
 ˵�� : ...
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpPktFilterId    : 1;    /* ucPacketFilterId*/
    VOS_UINT32                          bitOpPrecedence     : 1;    /* ucPrecedence*/
    VOS_UINT32                          bitOpSrcIp          : 1;    /* aucSourceIpAddr,Mask*/
    VOS_UINT32                          bitOpProtocolId     : 1;    /* ucProtocolId*/
    VOS_UINT32                          bitOpDestPortRange  : 1;    /* destination port range*/
    VOS_UINT32                          bitOpSrcPortRange   : 1;    /* source port range*/
    VOS_UINT32                          bitOpSpi            : 1;    /* ipsec security parameter index*/
    VOS_UINT32                          bitOpTosMask        : 1;    /* type of service*/
    VOS_UINT32                          bitOpFlowLable      : 1;    /* ulFlowLable*/
    VOS_UINT32                          bitOpDirection      : 1;    /* Direction*/
    VOS_UINT32                          bitOpNwPktFilterId  : 1;    /* NWPacketFltId*/
    VOS_UINT32                          bitOpSpare          : 21;

    VOS_UINT8                           ucCid;

    VOS_UINT8                           ucDefined;

    VOS_UINT8                           ucPacketFilterId;       /* Packet Filter Id,value range from 1 to 16*/

    VOS_UINT8                           ucPrecedence;           /* evaluation precedence index,The value range is from 0 to 255*/

    VOS_UINT8                           ucProtocolId;           /* protocol number,value range from 0 to 255*/

    VOS_UINT8                           aucReserved[3];

    /* source address and subnet mask*/
    TAF_PDP_ADDR_STRU                   stSourceIpaddr;
    TAF_PDP_ADDR_STRU                   stSourceIpMask;

    /* destination port range*/
    VOS_UINT16                          usLowDestPort;                          /* value range from 0 to 65535*/
    VOS_UINT16                          usHighDestPort;                         /* value range from 0 to 65535*/

    /* source port range*/
    VOS_UINT16                          usLowSourcePort;                        /* value range from 0 to 65535*/
    VOS_UINT16                          usHighSourcePort;                       /* value range from 0 to 65535*/

    /* ipsec security parameter index*/
    VOS_UINT32                          ulSecuParaIndex;

    /* only for ipv6*/
    VOS_UINT32                          ulFlowLable;                            /* value range is from 00000 to FFFFF*/

    /* type of service*/
    VOS_UINT8                           ucTypeOfService;                        /* value range from 0 to 255*/
    VOS_UINT8                           ucTypeOfServiceMask;                    /* value range from 0 to 255*/

    /* 0 - Pre-Release 7 TFT filter (see 3GPP TS 24.008 [8], table 10.5.162)*/
    /* 1 - Uplink*/
    /* 2 - Downlink*/
    /* 3 - Birectional (Up & Downlink) (default if omitted)*/
    VOS_UINT8                           ucDirection;

    /* only for CGTFTRDP*/
    VOS_UINT8                           ucNwPktFilterId;                        /* value range from 1 to 16*/
} TAF_TFT_EXT_STRU;

typedef struct
{
    VOS_UINT32                          ulCid;
    VOS_UINT32                          ulPFNum;
    TAF_TFT_EXT_STRU                    astTftInfo[TAF_MAX_SDF_PF_NUM];
} TAF_PF_TFT_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_TFT_EXT_STRU                    stTftInfo;
} TAF_PS_SET_TFT_INFO_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_SET_TFT_INFO_CNF_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
} TAF_PS_GET_TFT_INFO_REQ_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_TFT_QUREY_INFO_STRU             astTftQueryInfo[0];
} TAF_PS_GET_TFT_INFO_CNF_STRU;


/*****************************************************************************
 ���� : ������� +CGEQREQ
 ID   :



 REQ  :
 CNF  :
 IND  : -
 ˵�� : ...
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpTrafficClass       : 1;
    VOS_UINT32                          bitOpDeliverOrder       : 1;
    VOS_UINT32                          bitOpDeliverErrSdu      : 1;
    VOS_UINT32                          bitOpMaxSduSize         : 1;
    VOS_UINT32                          bitOpMaxBitUl           : 1;
    VOS_UINT32                          bitOpMaxBitDl           : 1;
    VOS_UINT32                          bitOpResidualBer        : 1;
    VOS_UINT32                          bitOpSduErrRatio        : 1;
    VOS_UINT32                          bitOpTransDelay         : 1;
    VOS_UINT32                          bitOpTraffHandlePrior   : 1;
    VOS_UINT32                          bitOpGtdBitUl           : 1;
    VOS_UINT32                          bitOpGtdBitDl           : 1;
    VOS_UINT32                          bitOpSpare              : 20;

    VOS_UINT8                           ucDefined;

    VOS_UINT8                           ucCid;

    VOS_UINT8                           ucTrafficClass;     /* 0 : Conversational class
                                                               1 : Streaming class
                                                               2 : Interactive class
                                                               3 : Background class
                                                               4 : Subscribed value */
    VOS_UINT8                           ucSduErrRatio;      /* 0 : subscribed value
                                                               1 : 1*10-2
                                                               2 : 7*10-3
                                                               3 : 1*10-3
                                                               4 : 1*10-4
                                                               5 : 1*10-5
                                                               6 : 1*10-6
                                                               7 : 1*10-1 */
    VOS_UINT16                          usMaxSduSize;       /* 0 : Subscribed value
                                                               1~1520: 1 ~1520 octets */

    VOS_UINT8                           ucDeliverOrder;     /* 0 : Without delivery order
                                                               1 : With delivery order
                                                               2 : Subscribed value */

    VOS_UINT8                           ucDeliverErrSdu;    /* 0 : Erroneous SDUs are not delivered
                                                               1 : Erroneous SDUs are delivered
                                                               2 : No detect
                                                               3 : subscribed value */

    VOS_UINT32                          ulMaxBitUl;         /* 0 : Subscribed value
                                                               1~256000: 1kbps ~ 256000kbps*/
    VOS_UINT32                          ulMaxBitDl;         /* ͬulMaxBitUl */
    VOS_UINT32                          ulGtdBitUl;         /* ͬulMaxBitUl */
    VOS_UINT32                          ulGtdBitDl;         /* ͬulMaxBitUl */
    VOS_UINT8                           ucResidualBer;      /* 0 : subscribed value
                                                               1 : 5*10-2
                                                               2 : 1*10-2
                                                               3 : 5*10-3
                                                               4 : 4*10-3
                                                               5 : 1*10-3
                                                               6 : 1*10-4
                                                               7 : 1*10-5
                                                               8 : 1*10-6
                                                               9 : 6*10-8 */
    VOS_UINT8                           ucTraffHandlePrior; /* 0 : Subscribed value
                                                               1 : Priority level 1
                                                               2 : Priority level 2
                                                               3 : Priority level 3 */
    VOS_UINT16                          usTransDelay;       /* 0 : Subscribed value
                                                               1~4100 : 1ms~4100ms */

} TAF_UMTS_QOS_EXT_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_UMTS_QOS_EXT_STRU               stUmtsQosInfo;
} TAF_PS_SET_UMTS_QOS_INFO_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_SET_UMTS_QOS_INFO_CNF_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
} TAF_PS_GET_UMTS_QOS_INFO_REQ_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_UMTS_QOS_QUERY_INFO_STRU        astUmtsQosQueryInfo[0];
} TAF_PS_GET_UMTS_QOS_INFO_CNF_STRU;


/*****************************************************************************
 ���� : ������� +CGEQMIN
 ID   :



 REQ  :
 CNF  :
 IND  : -
 ˵�� : ...
*****************************************************************************/
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_UMTS_QOS_EXT_STRU               stUmtsQosMinInfo;
} TAF_PS_SET_UMTS_QOS_MIN_INFO_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_SET_UMTS_QOS_MIN_INFO_CNF_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
} TAF_PS_GET_UMTS_QOS_MIN_INFO_REQ_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_UMTS_QOS_QUERY_INFO_STRU        astUmtsQosQueryInfo[0];
} TAF_PS_GET_UMTS_QOS_MIN_INFO_CNF_STRU;


/*****************************************************************************
 ���� : ������� +CGEQNEG
 ID   :



 REQ  :
 CNF  :
 IND  : -
 ˵�� : ...
*****************************************************************************/
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_CID_LIST_STRU                   stCidListInfo;
} TAF_PS_GET_DYNAMIC_UMTS_QOS_INFO_REQ_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_UMTS_QOS_QUERY_INFO_STRU        astUmtsQosQueryInfo[0];
} TAF_PS_GET_DYNAMIC_UMTS_QOS_INFO_CNF_STRU;


/*****************************************************************************
 ���� : ������� +CGMOD
 ID   :



 REQ  :
 CNF  :
 IND  : -
 ˵�� : ...
*****************************************************************************/

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_CID_LIST_STRU                   stCidListInfo;
} TAF_PS_CALL_MODIFY_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_CALL_MODIFY_CNF_STRU;


/*****************************************************************************
 ���� : ������� +CGANS
 ID   : ID_MSG_L4A_SET_CGANS_RSP
        ID_MSG_L4A_SET_CGANS_CNF
        ID_MSG_L4A_CGANS_IND
 RSP  : L4A_SET_CGANS_RSP_STRU
 CNF  : L4A_SET_CGANS_CNF_STRU
 IND  : L4A_CGANS_IND_STRU
 ˵�� : L4A_CGANS_IND_STRU �����緢���¼�,�������ܲ���ʹ�ø�ԭ��
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucL2P[20];
    VOS_UINT8                           ucCid;
    /* Added by l60609 for V3R3 PPP RPOJECT 2013-06-07, Begin */
    VOS_UINT8                           ucAnsExtFlg;                            /* �����^CGANS���ΪVOS_TRUE������ΪVOS_FALSE */
    VOS_UINT8                           aucReserved[2];
    /* Added by l60609 for V3R3 PPP RPOJECT 2013-06-07, End */
} TAF_PS_ANSWER_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_ANSWER_STRU                  stAnsInfo;
} TAF_PS_CALL_ANSWER_REQ_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;

    VOS_UINT8                           ucCid;

    VOS_UINT8                           aucReserved[3];
}TAF_PS_CALL_ANSWER_CNF_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
} TAF_PS_CALL_HANGUP_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_CALL_HANGUP_CNF_STRU;


/*****************************************************************************
 ���� : ������� +CGPADDR
 ID   :


 REQ  :
 CNF  :
 IND  : -
 ˵�� : ...
*****************************************************************************/
/*****************************************************************************
 �ṹ����   : TAF_PDP_ADDR_STRU
 Э�����   :
 �ṹ˵��   :
*****************************************************************************/

typedef struct
{
    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];

    /* the MT in the address space applicable to the PDP */
    TAF_PDP_ADDR_STRU                   stPdpAddr;
} TAF_PDP_ADDR_QUERY_INFO_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_CID_LIST_STRU                   stCidListInfo;
} TAF_PS_GET_PDP_IP_ADDR_INFO_REQ_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_PDP_ADDR_QUERY_INFO_STRU        astPdpAddrQueryInfo[0];
} TAF_PS_GET_PDP_IP_ADDR_INFO_CNF_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    VOS_UINT32                          ulCid[TAF_MAX_CID+1];
} TAF_PS_GET_PDP_CONTEXT_INFO_CNF_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
} TAF_PS_GET_PDP_CONTEXT_INFO_REQ_STRU;

/*****************************************************************************
 ���� : ������� +CGAUTO
 ID   : ID_MSG_L4A_SET_CGAUTO_REQ
        ID_MSG_L4A_SET_CGAUTO_CNF
        ID_MSG_L4A_READ_CGAUTO_REQ
        ID_MSG_L4A_READ_CGAUTO_CNF
 REQ  : L4A_SET_CGAUTO_REQ_STRU; L4A_READ_CGAUTO_REQ_STRU
 CNF  : L4A_SET_CGAUTO_CNF_STRU; L4A_READ_CGAUTO_CNF_STRU
 IND  : -
 ˵�� : ...
*****************************************************************************/
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    VOS_UINT32                          ulAnsMode;
} TAF_PS_SET_ANSWER_MODE_INFO_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_SET_ANSWER_MODE_INFO_CNF_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
} TAF_PS_GET_ANSWER_MODE_INFO_REQ_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulAnsMode;
} TAF_PS_GET_ANSWER_MODE_INFO_CNF_STRU;


/*****************************************************************************
 ���� : ������� +CGCONTRDP
 ID   : ID_MSG_L4A_SET_CGCONTRDP_REQ
        ID_MSG_L4A_SET_CGCONTRDP_CNF
 REQ  : L4A_SET_CGCONTRDP_REQ_STRU
 CNF  : L4A_SET_CGCONTRDP_CNF_STRU
 IND  : -
 ˵�� : ...
******************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpBearerId       : 1;                /* BearerId*/
    VOS_UINT32                          bitOpApn            : 1;                /* aucApn*/
    VOS_UINT32                          bitOpIpAddr         : 1;                /* aucIpaddr*/
    VOS_UINT32                          bitOpSubMask        : 1;                /* aucSubnetMask*/
    VOS_UINT32                          bitOpGwAddr         : 1;                /* aucGWAddr*/
    VOS_UINT32                          bitOpDNSPrimAddr    : 1;                /* aucDNSPrimAddr*/
    VOS_UINT32                          bitOpDNSSecAddr     : 1;                /* aucDNSSecAddr*/
    VOS_UINT32                          bitOpPCSCFPrimAddr  : 1;                /* aucPCSCFPrimAddr*/
    VOS_UINT32                          bitOpPCSCFSecAddr   : 1;                /* aucPCSCFSecAddr*/
    VOS_UINT32                          bitOpImCnSignalFlg  : 1;
    VOS_UINT32                          bitOpSpare          : 22;

    VOS_UINT8                           ucPrimayCid;                            /* default EPS bearer context*/
    VOS_UINT8                           ucBearerId;                             /* a numeric parameter which identifies the bearer*/

    /* the IM CN subsystem-related signalling flag */
    TAF_PDP_IM_CN_SIG_FLAG_ENUM_UINT8   enImCnSignalFlg;

    VOS_UINT8                           aucReserved[1];

    /* Access Pointer Name*/
    VOS_UINT8                           aucApn[TAF_MAX_APN_LEN + 1];

    /* the IP Address of the MT*/
    TAF_PDP_ADDR_STRU                   stPdpAddr;

    /* the subnet mask for the IP Address of the MT*/
    TAF_PDP_ADDR_STRU                   stSubnetMask;

    /* the Gateway Address of the MT*/
    TAF_PDP_ADDR_STRU                   stGWAddr;

    /* the IP Address of the primary DNS Server*/
    TAF_PDP_ADDR_STRU                   stDNSPrimAddr;

    /* the IP address of the secondary DNS Server*/
    TAF_PDP_ADDR_STRU                   stDNSSecAddr;

    /* the IP Address of the primary P-CSCF Server*/
    TAF_PDP_ADDR_STRU                   stPCSCFPrimAddr;

    /* the IP Address of the secondary P-CSCF Server*/
    TAF_PDP_ADDR_STRU                   stPCSCFSecAddr;

} TAF_PDP_DYNAMIC_PRIM_EXT_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    /* 0xff-if the parameter <cid> is omitted */
    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];
} TAF_PS_GET_DYNAMIC_PRIM_PDP_CONTEXT_INFO_REQ_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_PDP_DYNAMIC_PRIM_EXT_STRU       astPdpContxtInfo[0];
} TAF_PS_GET_DYNAMIC_PRIM_PDP_CONTEXT_INFO_CNF_STRU;


/*****************************************************************************
 ���� : ������� +CGSCONTRDP
 ID   : ID_MSG_L4A_SET_CGSCONTRDP_REQ
        ID_MSG_L4A_SET_CGSCONTRDP_CNF
 REQ  : L4A_SET_CGSCONTRDP_REQ_STRU
 CNF  : L4A_SET_CGSCONTRDP_CNF_STRU
 IND  : -
 ˵�� : ...
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucCid;

    /* default EPS bearer context */
    VOS_UINT8                           ucPrimaryCid;

    /* a numeric parameter which identifies the bearer */
    VOS_UINT8                           ucBearerId;

    VOS_UINT8                           ucReserved[1];
} TAF_PDP_DYNAMIC_SEC_EXT_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    /* 0xff-if the parameter <cid> is omitted */
    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];
} TAF_PS_GET_DYNAMIC_SEC_PDP_CONTEXT_INFO_REQ_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_PDP_DYNAMIC_SEC_EXT_STRU        astPdpContxtInfo[0];
} TAF_PS_GET_DYNAMIC_SEC_PDP_CONTEXT_INFO_CNF_STRU;


/*****************************************************************************
 ���� : ������� +CGTFTRDP
 ID   : ID_MSG_L4A_SET_CGTFTRDP_REQ
        ID_MSG_L4A_SET_CGTFTRDP_CNF
 REQ  : L4A_SET_CGTFTRDP_REQ_STRU
 CNF  : L4A_SET_CGTFTRDP_CNF_STRU
 IND  : -
 ˵�� : ...
*****************************************************************************/
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    /* 0xff-if the parameter <cid> is omitted */
    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];
} TAF_PS_GET_DYNAMIC_TFT_INFO_REQ_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_PF_TFT_STRU                     astPfTftInfo[0];
} TAF_PS_GET_DYNAMIC_TFT_INFO_CNF_STRU;


/*****************************************************************************
 ���� : ������� +CGEQOS
 ID   : ID_MSG_L4A_SET_CGEQOS_REQ
        ID_MSG_L4A_SET_CGEQOS_CNF
        ID_MSG_L4A_READ_CGEQOS_REQ
        ID_MSG_L4A_READ_CGEQOS_CNF
 REQ  : L4A_SET_CGEQOS_REQ_STRU L4A_READ_CGEQOS_REQ_STRU
 CNF  : L4A_SET_CGEQOS_CNF_STRU L4A_READ_CGEQOS_CNF_STRU
 IND  : -
 ˵�� : ...
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpQCI            : 1;                /* QCI*/
    VOS_UINT32                          bitOpDLGBR          : 1;                /* DLGBR*/
    VOS_UINT32                          bitOpULGBR          : 1;                /* ULGBR*/
    VOS_UINT32                          bitOpDLMBR          : 1;                /* DLMBR*/
    VOS_UINT32                          bitOpULMBR          : 1;                /* ULMBR*/
    VOS_UINT32                          bitOpSpare          : 27;

    VOS_UINT8                           ucCid;

    /* 0 QCI is selected by network*/
    /* [1 - 4]value range for guranteed bit rate Traffic Flows*/
    /* [5 - 9]value range for non-guarenteed bit rate Traffic Flows*/
    VOS_UINT8                           ucQCI;

    VOS_UINT8                           ucReserved[2];

    /* DL GBR in case of GBR QCI, The value is in kbit/s*/
    VOS_UINT32                          ulDLGBR;

    /* UL GBR in case of GBR QCI, The value is in kbit/s*/
    VOS_UINT32                          ulULGBR;

    /* DL MBR in case of GBR QCI, The value is in kbit/s*/
    VOS_UINT32                          ulDLMBR;

    /* UL MBR in case of GBR QCI, The value is in kbit/s*/
    VOS_UINT32                          ulULMBR;
}TAF_EPS_QOS_EXT_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_EPS_QOS_EXT_STRU                stEpsQosInfo;
} TAF_PS_SET_EPS_QOS_INFO_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_SET_EPS_QOS_INFO_CNF_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
} TAF_PS_GET_EPS_QOS_INFO_REQ_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_EPS_QOS_EXT_STRU                astEpsQosInfo[0];
} TAF_PS_GET_EPS_QOS_INFO_CNF_STRU;


/*****************************************************************************
 ���� : ������� +CGEQOSRDP
 ID   : ID_MSG_L4A_SET_CGEQOSRDP_REQ
        ID_MSG_L4A_SET_CGEQOSRDP_CNF
 REQ  : L4A_SET_CGEQOSRDP_REQ_STRU
 CNF  : L4A_SET_CGEQOSRDP_CNF_STRU
 IND  : -
 ˵�� : ...
*****************************************************************************/
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    /* 0xff-if the parameter <cid> is omitted */
    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];
} TAF_PS_GET_DYNAMIC_EPS_QOS_INFO_REQ_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_EPS_QOS_EXT_STRU                astEpsQosInfo[0];
} TAF_PS_GET_DYNAMIC_EPS_QOS_INFO_CNF_STRU;
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    VOS_UINT8                           aucReserve[4];
} TAF_PS_GET_DSFLOW_INFO_REQ_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    TAF_DSFLOW_QUERY_INFO_STRU          stQueryInfo;
} TAF_PS_GET_DSFLOW_INFO_CNF_STRU;


/*****************************************************************************
 ���� : ������� ^DSFLOWCLR
 ID   :

 REQ  :
 CNF  :
 IND  : -
 ˵�� : ...
*****************************************************************************/
/*****************************************************************************
 �ṹ��    : TAF_DSFLOW_CLEAR_CONFIG_STRU
 �ṹ˵��  : �����������
*****************************************************************************/
typedef struct
{
    TAF_DSFLOW_CLEAR_MODE_ENUM_UINT8    enClearMode;
    VOS_UINT8                           ucNsapi;
    VOS_UINT8                           aucReserved[2];
} TAF_DSFLOW_CLEAR_CONFIG_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_DSFLOW_CLEAR_CONFIG_STRU        stClearConfigInfo;
} TAF_PS_CLEAR_DSFLOW_REQ_STRU;


typedef TAF_PS_COMMON_CNF_STRU TAF_PS_CLEAR_DSFLOW_CNF_STRU;


/*****************************************************************************
 ���� : ������� ^DSFLOWRPT
 ID   :

 REQ  :
 CNF  :
 IND  : -
 ˵�� : ...
*****************************************************************************/

typedef struct
{
    VOS_UINT32                          ulRptEnabled;       /* �����ϱ��������   */
    VOS_UINT32                          ulTimerLength;      /* �����ϱ���ʱ��ʱ�� */
} TAF_DSFLOW_REPORT_CONFIG_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_DSFLOW_REPORT_CONFIG_STRU       stReportConfigInfo;
} TAF_PS_CONFIG_DSFLOW_RPT_REQ_STRU;


typedef TAF_PS_COMMON_CNF_STRU TAF_PS_CONFIG_DSFLOW_RPT_CNF_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    TAF_DSFLOW_REPORT_STRU              stDsFlowRptInfo;
} TAF_PS_REPORT_DSFLOW_IND_STRU;


/*****************************************************************************
 ���� : ������� ^CGAUTH
 ID   :

 REQ  :
 CNF  :
 IND  : -
 ˵�� : ...
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpAuth           : 1;
    VOS_UINT32                          bitOpUserName       : 1;
    VOS_UINT32                          bitOpPassword       : 1;
    VOS_UINT32                          bitOpSpare          : 29;

    VOS_UINT8                           ucCid;
    VOS_UINT8                           ucDefined;          /* 0:undefined, 1:defined */
    VOS_UINT8                           ucAuth;             /* Ŀǰ��֧���Ƿ��Ȩ���Ժ�����Ϊ֧�����ּ�Ȩ�㷨*/
    VOS_UINT8                           aucReserved[1];
    VOS_UINT8                           aucUserName[TAF_MAX_PDP_AUTH_USERNAME_LEN + 1];
    VOS_UINT8                           aucPassWord[TAF_MAX_PDP_AUTH_PASSCODE_LEN + 1];
} TAF_PDP_AUTH_EXT_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PDP_AUTH_EXT_STRU               stPdpAuthInfo;
} TAF_PS_SET_PDP_AUTH_INFO_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_SET_PDP_AUTH_INFO_CNF_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
} TAF_PS_GET_PDP_AUTH_INFO_REQ_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_AUTH_QUERY_INFO_STRU            astPdpAuthQueryInfo[0];
} TAF_PS_GET_PDP_AUTH_INFO_CNF_STRU;


/*****************************************************************************
 ���� : ������� ^CGDNS
 ID   :

 REQ  :
 CNF  :
 IND  : -
 ˵�� : ...
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpPrimDnsAddr    : 1;
    VOS_UINT32                          bitOpSecDnsAddr     : 1;
    VOS_UINT32                          bitOpSpare          : 30;

    VOS_UINT8                           ucCid;              /* [1��11] ����������˲�������ʾɾ����Cid��DNS */
    VOS_UINT8                           ucDefined;          /* 0:undefined, 1:defined */
    VOS_UINT8                           aucReserved[2];
    VOS_UINT8                           aucPrimDnsAddr[TAF_IPV4_ADDR_LEN];
    VOS_UINT8                           aucSecDnsAddr[TAF_IPV4_ADDR_LEN];
} TAF_PDP_DNS_EXT_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PDP_DNS_EXT_STRU                stPdpDnsInfo;
} TAF_PS_SET_PDP_DNS_INFO_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_SET_PDP_DNS_INFO_CNF_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
} TAF_PS_GET_PDP_DNS_INFO_REQ_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_DNS_QUERY_INFO_STRU             astPdpDnsQueryInfo[0];
} TAF_PS_GET_PDP_DNS_INFO_CNF_STRU;


/*****************************************************************************
 ���� : ������� ^TRIG
 ID   :

 REQ  :
 CNF  :
 IND  : -
 ˵�� : ...
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucMode;
    VOS_UINT8                           ucNsapi;
    VOS_UINT8                           ucTimes;
    VOS_UINT8                           aucReserved[1];
    VOS_UINT32                          ulLength;
    VOS_UINT32                          ulMillisecond;
} TAF_GPRS_DATA_STRU;

typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_GPRS_DATA_STRU                  stGprsDataInfo;
} TAF_PS_TRIG_GPRS_DATA_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_TRIG_GPRS_DATA_CNF_STRU;


/*****************************************************************************
 ���� : ������� ^DWINS
 ID   :

 REQ  :
 CNF  :
 IND  : -
 ˵�� : ...
*****************************************************************************/
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    /* 0:disabled, 1:enabled */
    VOS_UINT32                          ulEnabled;
} TAF_PS_CONFIG_NBNS_FUNCTION_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_CONFIG_NBNS_FUNCTION_CNF_STRU;


/*****************************************************************************
 �ṹ����  : TAF_PS_DIAL_PARA_STRU
 �ṹ˵��  : ���Ų���
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpAuthType       : 1;
    VOS_UINT32                          bitOpApn            : 1;
    VOS_UINT32                          bitOpIpAddr         : 1;
    VOS_UINT32                          bitOpUserName       : 1;
    VOS_UINT32                          bitOpPassWord       : 1;
    VOS_UINT32                          bitOpReqType        : 1;
    VOS_UINT32                          bitOpPdpDcomp       : 1;
    VOS_UINT32                          bitOpPdpHcomp       : 1;
    VOS_UINT32                          bitOpIpv4AddrAlloc  : 1;
    VOS_UINT32                          bitOpEmergencyInd   : 1;
    VOS_UINT32                          bitOpPcscfDiscovery : 1;
    VOS_UINT32                          bitOpImCnSignalFlg  : 1;
    VOS_UINT32                          bitOpSpare          : 20;

    /* connect id [1, 20] */
    VOS_UINT8                           ucCid;

    /* 0 - no auth */
    /* 1 - PAP */
    /* 2 - CHAP */
    /* 3 - MS_CHAP_V2 */
    TAF_PDP_AUTH_TYPE_ENUM_UINT8        enAuthType;

    /* 0 - IPv4 */
    /* 1 - IPv6 */
    /* 2 - IPv4v6 */
    /* 3 - PPP */
    TAF_PDP_TYPE_ENUM_UINT8             enPdpType;

    /* 1 - initial request */
    /* 2 - Handover */
    /* 3 - Unused. If received, the network shall interpret this as "initial request". */
    /* 4 - emergency */
    TAF_PDP_REQUEST_TYPE_ENUM_UINT8     enPdpRequestType;

    /* access point name string with '\0' end */
    VOS_UINT8                           aucApn[TAF_MAX_APN_LEN + 1];

    /* staitc address if needed */
    TAF_PDP_ADDR_STRU                   stPdpAddr;

    /* user name string with '\0' end */
    VOS_UINT8                           aucUserName[TAF_MAX_GW_AUTH_USERNAME_LEN + 1];

    /* user name string with '\0' end */
    VOS_UINT8                           aucPassWord[TAF_MAX_GW_AUTH_PASSWORD_LEN + 1];

    /* 0 - off (default if value is omitted) */
    /* 1 - on (manufacturer preferred compression) */
    /* 2 - V.42bis */
    /* 3 - V.44 */
    TAF_PDP_D_COMP_ENUM_UINT8           enPdpDcomp;

    /* 0 - off (default if value is omitted) */
    /* 1 - on (manufacturer preferred compression) */
    /* 2 - RFC1144 (applicable for SNDCP only) */
    /* 3 - RFC2507 */
    /* 4 - RFC3095 (applicable for PDCP only) */
    TAF_PDP_H_COMP_ENUM_UINT8           enPdpHcomp;

    /* 0 - IPv4 Address Allocation through NAS Signaling (default if omitted) */
    /* 1 - IPv4 Address Allocated through DHCP */
    TAF_PDP_IPV4_ADDR_ALLOC_TYPE_ENUM_UINT8 enIpv4AddrAlloc;

    /* 0 - PDP context is not for emergency bearer services */
    /* 1 - PDP context is for emergency bearer services */
    TAF_PDP_EMC_IND_ENUM_UINT8          enEmergencyInd;

    /* 0 - Preference of P-CSCF address discovery not influenced by +CGDCONT */
    /* 1 - Preference of P-CSCF address discovery through NAS Signalling */
    /* 2 - Preference of P-CSCF address discovery through DHCP */
    TAF_PDP_PCSCF_DISCOVERY_ENUM_UINT8  enPcscfDiscovery;

    /* 0 - UE indicates that the PDP context is not for IM CN subsystem-related signalling only */
    /* 1 - UE indicates that the PDP context is for IM CN subsystem-related signalling only */
    TAF_PDP_IM_CN_SIG_FLAG_ENUM_UINT8   enImCnSignalFlg;

    VOS_UINT8                           aucReserved[2];

} TAF_PS_DIAL_PARA_STRU;
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_DIAL_PARA_STRU               stDialParaInfo;
} TAF_PS_CALL_ORIG_REQ_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];
    TAF_PS_CAUSE_ENUM_UINT32            enCause;
} TAF_PS_CALL_ORIG_CNF_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];
} TAF_PS_CALL_END_REQ_STRU;

/*****************************************************************************
 �ṹ����: TAF_PS_CALL_END_CNF_STRU
 �ṹ˵��: ID_MSG_TAF_PS_CALL_END_CNF��Ϣ�ṹ
           �Ͽ��������� - enCauseΪTAF_PS_CAUSE_SUCCESS
           �Ͽ������쳣 - enCauseΪTAF_PS_CAUSE_CID_INVALID
                          ָ����CIDû�ж�Ӧ�ĺ���ʵ�弤��
*****************************************************************************/
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];
    TAF_PS_CAUSE_ENUM_UINT32            enCause;

} TAF_PS_CALL_END_CNF_STRU;

/*****************************************************************************
 ���� : ������� ^AUTHDATA
 ID   : ID_MSG_TAF_PS_SET_AUTHDATA_INFO_REQ
      : ID_MSG_TAF_PS_SET_AUTHDATA_INFO_CNF
      : ID_MSG_TAF_PS_GET_AUTHDATA_INFO_REQ
      : ID_MSG_TAF_PS_GET_AUTHDATA_INFO_CNF
 REQ  : TAF_PS_SET_AUTHDATA_INFO_REQ_STRU; TAF_PS_GET_AUTHDATA_INFO_REQ_STRU
 CNF  : TAF_PS_SET_AUTHDATA_INFO_CNF_STRU; TAF_PS_GET_AUTHDATA_INFO_CNF_STRU
 ˵�� : ...
*****************************************************************************/

typedef struct
{
    VOS_UINT32                          bitOpAuthType       : 1;
    VOS_UINT32                          bitOpPlmn           : 1;
    VOS_UINT32                          bitOpPassWord       : 1;
    VOS_UINT32                          bitOpUserName       : 1;
    VOS_UINT32                          bitOpSpare          : 28;

    VOS_UINT8                           ucDefined;          /* 0:undefined, 1:defined */
    VOS_UINT8                           ucCid;
    TAF_PDP_AUTH_TYPE_ENUM_UINT8        enAuthType;
    VOS_UINT8                           aucReserved1[1];
    VOS_UINT8                           aucPlmn[TAF_MAX_AUTHDATA_PLMN_LEN + 1];
    VOS_UINT8                           aucReserved2[1];
    VOS_UINT8                           aucPassWord[TAF_MAX_AUTHDATA_USERNAME_LEN + 1];
    VOS_UINT8                           aucUserName[TAF_MAX_AUTHDATA_PASSWORD_LEN + 1];
} TAF_AUTHDATA_EXT_STRU;
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_AUTHDATA_EXT_STRU               stAuthDataInfo;
} TAF_PS_SET_AUTHDATA_INFO_REQ_STRU;


typedef TAF_PS_COMMON_CNF_STRU TAF_PS_SET_AUTHDATA_INFO_CNF_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
} TAF_PS_GET_AUTHDATA_INFO_REQ_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    VOS_UINT32                          ulCidNum;
    TAF_AUTHDATA_QUERY_INFO_STRU        astAuthDataQueryInfo[0];
} TAF_PS_GET_AUTHDATA_INFO_CNF_STRU;


/*****************************************************************************
 ���� : ������� D
 ID   : ID_MSG_TAF_PS_GET_D_GPRS_ACTIVE_TYPE_REQ
      : ID_EVT_TAF_PS_GET_D_GPRS_ACTIVE_TYPE_CNF
      :
      :
 REQ  : TAF_PS_GET_D_GPRS_ACTIVE_TYPE_REQ_STRU
 CNF  : TAF_PS_GET_D_GPRS_ACTIVE_TYPE_CNF_STRU
 ˵�� : ...
*****************************************************************************/


typedef struct
{
    VOS_UINT32                          bitOpL2p            : 1;
    VOS_UINT32                          bitOpSpare          : 31;

    VOS_UINT8                           ucCid;
    TAF_L2P_TYPE_ENUM_UINT8             enL2p;
    VOS_UINT8                           aucReserved[2];
} TAF_ATD_PARA_STRU;


typedef struct
{
    VOS_UINT8                           ucCid;
    TAF_GPRS_ACTIVE_TYPE_UINT8          enActiveType;
    VOS_UINT8                           aucReserved[2];
} TAF_CID_GPRS_ACTIVE_TYPE_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_ATD_PARA_STRU                   stAtdPara;
} TAF_PS_GET_D_GPRS_ACTIVE_TYPE_REQ_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    TAF_CID_GPRS_ACTIVE_TYPE_STRU       stCidGprsActiveType;
} TAF_PS_GET_D_GPRS_ACTIVE_TYPE_CNF_STRU;


/*****************************************************************************
 �ṹ����: TAF_PPP_AUTH_PAP_CONTENT_STRU
 �ṹ˵��:
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usPapReqLen;                            /*request����: 24.008Ҫ����[3,253]�ֽ�*/
    VOS_UINT8                           aucReserve[2];                          /* ���뱣�� */
    VOS_UINT8                           aucPapReqBuf[TAF_PPP_PAP_REQ_MAX_LEN];  /*request*/
} TAF_PPP_AUTH_PAP_CONTENT_STRU;

/*****************************************************************************
 �ṹ����: TAF_PPP_AUTH_CHAP_CONTENT_STRU
 �ṹ˵��:
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usChapChallengeLen;                     /*challenge����: 24.008Ҫ����[3,253]�ֽ�*/
    VOS_UINT16                          usChapResponseLen;                      /*response����: 24.008Ҫ����[3,253]�ֽ�*/
    VOS_UINT8                           aucChapChallengeBuf[TAF_PPP_CHAP_CHALLENGE_MAX_LEN];    /*challenge,153B*/
    VOS_UINT8                           aucChapResponseBuf[TAF_PPP_CHAP_RESPONSE_MAX_LEN];      /*response,205B*/
    VOS_UINT8                           aucReserve[2];                          /* ���뱣�� */
} TAF_PPP_AUTH_CHAP_CONTENT_STRU;

/*****************************************************************************
 �ṹ����: TAF_PPP_REQ_AUTH_CONFIG_INFO_STRU
 �ṹ˵��:
*****************************************************************************/
typedef struct
{
    TAF_PDP_AUTH_TYPE_ENUM_UINT8        enAuthType;
    VOS_UINT8                           aucReserve[3];

    union
    {
        TAF_PPP_AUTH_PAP_CONTENT_STRU   stPapContent;
        TAF_PPP_AUTH_CHAP_CONTENT_STRU  stChapContent;
    } enAuthContent;

} TAF_PPP_REQ_AUTH_CONFIG_INFO_STRU;

/*****************************************************************************
 �ṹ����: TAF_PPP_REQ_CONFIG_INFO_STRU
 �ṹ˵��:
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usIpcpLen;                              /*Ipcp֡����*/
    VOS_UINT8                           aucReserve[2];                          /* ���뱣�� */
    VOS_UINT8                           aucIpcp[TAF_PPP_IPCP_FRAME_BUF_MAX_LEN];/*Ipcp֡*/
} TAF_PPP_REQ_IPCP_CONFIG_INFO_STRU;

/*****************************************************************************
 �ṹ����: TAF_PPP_REQ_CONFIG_INFO_STRU
 �ṹ˵��:
*****************************************************************************/
typedef struct
{
    TAF_PPP_REQ_AUTH_CONFIG_INFO_STRU   stAuth;
    TAF_PPP_REQ_IPCP_CONFIG_INFO_STRU   stIPCP;
} TAF_PPP_REQ_CONFIG_INFO_STRU;

/*****************************************************************************
 ���� : ���PPP����
 ID   : ID_MSG_TAF_PS_PPP_DIAL_ORIG_REQ
      : ID_EVT_TAF_PS_PPP_DIAL_ORIG_CNF
      :
      :
 REQ  : TAF_PS_PPP_DIAL_ORIG_REQ_STRU
 CNF  : TAF_PS_PPP_DIAL_ORIG_CNF_STRU
 ˵�� : ...
*****************************************************************************/

typedef struct
{
    VOS_UINT32                          bitOpPppConfigInfo  : 1;
    VOS_UINT32                          bitOpSpare          : 31;

    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];
    TAF_PPP_REQ_CONFIG_INFO_STRU        stPppReqConfigInfo;
} TAF_PPP_DIAL_PARA_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PPP_DIAL_PARA_STRU              stPppDialParaInfo;
} TAF_PS_PPP_DIAL_ORIG_REQ_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
} TAF_PS_PPP_DIAL_ORIG_CNF_STRU;

/*****************************************************************************
�ṹ��    : TAF_PDP_IPV6_PREFIX_STRU
�ṹ˵��  : IPV6 ǰ׺��Ϣ�ṹ
  1.��    ��   : 2011��12��24��
    ��    ��   : ��־��/c00173809
    �޸�����   : ����ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulBitL          :1;                     /* 1: VALID; 0: INVALID*/
    VOS_UINT32                          ulBitA          :1;
    VOS_UINT32                          ulBitPrefixLen  :8;
    VOS_UINT32                          ulBitRsv        :22;

    VOS_UINT32                          ulValidLifeTime;
    VOS_UINT32                          ulPreferredLifeTime;
    VOS_UINT8                           aucPrefix[TAF_IPV6_ADDR_LEN];
}TAF_PDP_IPV6_PREFIX_STRU;

/*****************************************************************************
�ṹ��    : TAF_PDP_IPV6_RA_INFO_STRU
�ṹ˵��  : IPV6 RA�����ṹ
  1.��    ��   : 2011��12��24��
    ��    ��   : ��־��/c00173809
    �޸�����   : ����ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpMtu            :1;
    VOS_UINT32                          bitOpSpare          :31;

    VOS_UINT32                          ulBitCurHopLimit    :8;
    VOS_UINT32                          ulBitM              :1;
    VOS_UINT32                          ulBitO              :1;
    VOS_UINT32                          ulBitRsv            :22;

    VOS_UINT32                          ulMtu;                                  /* MTU��С */
    VOS_UINT32                          ulPrefixNum;                            /* IPV6��ַǰ׺���� */
    TAF_PDP_IPV6_PREFIX_STRU            astPrefixList[TAF_MAX_PREFIX_NUM_IN_RA];/* IPV6��ַǰ׺���� */

} TAF_PDP_IPV6_RA_INFO_STRU;
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    VOS_UINT8                           ucCid;
    VOS_UINT8                           ucRabId;
    VOS_UINT8                           aucReserved[2];
    TAF_PDP_IPV6_RA_INFO_STRU           stIpv6RaInfo;

} TAF_PS_IPV6_INFO_IND_STRU;
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    VOS_UINT8                           ucCid;
    VOS_UINT8                           aucReserved[3];
} TAF_PS_GET_NEGOTIATION_DNS_REQ_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    TAF_DNS_QUERY_INFO_STRU             stNegotiationDns;
} TAF_PS_GET_NEGOTIATION_DNS_CNF_STRU;


#if (FEATURE_ON == FEATURE_LTE)


typedef struct
{
    VOS_UINT8                           ucSG;
    VOS_UINT8                           ucIMS;
    VOS_UINT8                           ucCSFB;
    VOS_UINT8                           ucVCC;
    VOS_UINT8                           ucVoLGA;
    VOS_UINT8                           aucReserved[3];
}TAF_PH_LTECS_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
}TAF_PS_LTECS_REQ_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    TAF_PH_LTECS_STRU                   stLteCs;
}TAF_PS_LTECS_CNF_STRU;



typedef struct
{
    VOS_UINT32                          enCurrentUeMode;                        /*��ǰUEģʽ*/
    VOS_UINT32                          ulSupportModeCnt;                       /*UE�ܹ�֧�ֵ�ģʽ�ĸ���*/
    VOS_UINT32                          aenSupportModeList[4];                  /*UE�ܹ�֧�ֵ�ģʽ*/
}TAF_PH_CEMODE_STRU;
typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
}TAF_PS_CEMODE_REQ_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
    TAF_PS_CAUSE_ENUM_UINT32            enCause;
    TAF_PH_CEMODE_STRU                  stCemode;
}TAF_PS_CEMODE_CNF_STRU;




typedef struct
{
    VOS_UINT32                          bitOpPdpType        : 1;                /* PdpType*/
    VOS_UINT32                          bitOpApn            : 1;                /* aucApn*/
    VOS_UINT32                          bitOpUsername       : 1;                /* AuthUsername*/
    VOS_UINT32                          bitOpPassword       : 1;                /* AuthPassword*/
    VOS_UINT32                          bitOpAuthType       : 1;                /* AuthType*/
    VOS_UINT32                          bitOpSpare          : 27;

    VOS_UINT8                           ucDefined;                              /* 0:undefined, 1:defined */

    VOS_UINT8                           ucCid;

    /* 1 IP Internet Protocol (IETF STD 5)*/
    /* 2 IPV6 Internet Protocol, version 6 (IETF RFC 2460)*/
    /* 3 IPV4V6 Virtual <PDP_type> introduced to handle dual IP stack UE capability. (See 3GPP TS 24.301 [83])*/
    TAF_PDP_TYPE_ENUM_UINT8             enPdpType;

    VOS_UINT8                           aucReserved1[1];

    /* Access Point Name*/
    VOS_UINT8                           aucApn[TAF_MAX_APN_LEN + 1];

    VOS_UINT8                           aucPassWord[TAF_MAX_AUTHDATA_USERNAME_LEN + 1];
    VOS_UINT8                           aucUserName[TAF_MAX_AUTHDATA_PASSWORD_LEN + 1];
    VOS_UINT8                           ucAuthType;
    VOS_UINT8                           aucReserved2[3];

}TAF_PDP_PROFILE_EXT_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_PDP_PROFILE_EXT_STRU            stPdpProfInfo;
} TAF_PS_SET_PROFILE_INFO_REQ_STRU;

typedef TAF_PS_COMMON_CNF_STRU TAF_PS_SET_PDP_PROF_INFO_CNF_STRU;

#endif

/*****************************************************************************
 �ṹ����: TAF_GW_AUTH_STRU
 �ṹ˵��: ���ؼ�Ȩ�����ṹ��
*****************************************************************************/
typedef struct
{
    TAF_PDP_AUTH_TYPE_ENUM_UINT8        enAuthType;
    VOS_UINT8                           ucAccNumLen;
    VOS_UINT8                           aucReserved[2];
    VOS_UINT8                           auAccessNum[TAF_MAX_ACCESS_NUM_LEN];
    VOS_UINT8                           ucUserNameLen;
    VOS_UINT8                           aucUserName[TAF_MAX_GW_AUTH_USERNAME_LEN];
    VOS_UINT8                           ucPwdLen;
    VOS_UINT8                           aucPwd[TAF_MAX_GW_AUTH_PASSWORD_LEN];

} TAF_GW_AUTH_STRU;


/*****************************************************************************
 �ṹ����: TAF_SDF_PARA_STRU
 �ṹ˵��: SDF�����ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpLinkdCid       : 1;
    VOS_UINT32                          bitOpPdnType        : 1;
    VOS_UINT32                          bitOpApn            : 1;
    VOS_UINT32                          bitOpUmtsQos        : 1;
    VOS_UINT32                          bitOpEpsQos         : 1;
    VOS_UINT32                          bitOpGwAuthInfo     : 1;
    VOS_UINT32                          bitOpEmergencyInd   : 1;
    VOS_UINT32                          bitOpIpv4AddrAllocType: 1;
    VOS_UINT32                          bitOpPcscfDiscovery : 1;
    VOS_UINT32                          bitOpImCnSignalFlg  : 1;
    VOS_UINT32                          bitOpImsSuppFlg     : 1;
    VOS_UINT32                          bitOpSpare          : 21;

    VOS_UINT8                           ucCid;
    VOS_UINT8                           ucLinkdCid;
    TAF_PDP_TYPE_ENUM_UINT8             enPdnType;
    TAF_PDP_IPV4_ADDR_ALLOC_TYPE_ENUM_UINT8 enIpv4AddrAllocType;

    TAF_PDP_EMC_IND_ENUM_UINT8          enEmergencyInd;
    TAF_PDP_PCSCF_DISCOVERY_ENUM_UINT8  enPcscfDiscovery;
    TAF_PDP_IM_CN_SIG_FLAG_ENUM_UINT8   enImCnSignalFlg;
    VOS_UINT8                           ucPfNum;
    VOS_UINT8                           ucImsSuppFlg;
    VOS_UINT8                           aucReserved[3];

    TAF_UMTS_QOS_STRU                   stUmtsQosInfo;
    TAF_EPS_QOS_STRU                    stEpsQosInfo;
    TAF_PDP_APN_STRU                    stApnInfo;
    TAF_GW_AUTH_STRU                    stGwAuthInfo;
    TAF_PDP_PF_STRU                     astCntxtTftInfo[TAF_MAX_SDF_PF_NUM];

}TAF_SDF_PARA_STRU;


/*****************************************************************************
 �ṹ����: TAF_SDF_PARA_QUERY_INFO_STRU
 �ṹ˵��: SDF���ò�����ѯ�ṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulSdfNum;
    TAF_SDF_PARA_STRU                   astSdfPara[TAF_MAX_CID_NV];

} TAF_SDF_PARA_QUERY_INFO_STRU;


typedef struct
{
    TAF_CTRL_STRU                       stCtrl;
}TAF_PS_SDF_INFO_REQ_STRU;



typedef struct
{
    TAF_CTRL_STRU                       stCtrl;

    TAF_SDF_PARA_QUERY_INFO_STRU        stSdfInfo;
}TAF_PS_SDF_INFO_CNF_STRU;


/*****************************************************************************
 �ṹ��    : TAF_PS_PDP_QOS_QUERY_PARA_STRU
 �ṹ˵��  : QOS��ѯ������������QOS������MIN QOS����
 1.��    ��   : 2013��06��29��
   ��    ��   : l60609
   �޸�����   : �����ļ�
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucQosFlag;                              /* 0��Qos����Ч��1��Qos����Ч */
    VOS_UINT8                           ucMinQosFlag;                           /* 0:��������С�ɽ���Qos,1:û����С�ɽ���Qos */
    VOS_UINT8                           aucReserved[2];

    TAF_UMTS_QOS_STRU                   stQos;                                  /* Qos�� */
    TAF_UMTS_QOS_STRU                   stMinQos;                               /* MINQos�� */
}TAF_PS_PDP_QOS_QUERY_PARA_STRU;

/*****************************************************************************
 �ṹ��    : TAF_PS_PDP_QOS_SET_PARA_STRU
 �ṹ˵��  : QOS��ѯ������������QOS������MIN QOS����
 1.��    ��   : 2013��06��29��
   ��    ��   : l60609
   �޸�����   : �����ļ�
*****************************************************************************/
typedef struct
{
    TAF_UMTS_QOS_EXT_STRU               stQos;                                  /* Qos�� */
    TAF_UMTS_QOS_EXT_STRU               stMinQos;                               /* MINQos�� */
}TAF_PS_PDP_QOS_SET_PARA_STRU;


#if (FEATURE_ON == FEATURE_IMS)
/*****************************************************************************
 �ṹ����: TAF_SRVCC_CANCEL_NOTIFY_IND_STRU
 �ṹ˵��: APS->IMSA֪ͨSRVCC CANECL
*****************************************************************************/
typedef struct
{
    TAF_CTRL_STRU                           stCtrl;
    TAF_SRVCC_CANCEL_NOTIFY_ENUM_UINT32     enNotificationIndicator;
}TAF_SRVCC_CANCEL_NOTIFY_IND_STRU;
#endif

/*****************************************************************************
  H2ASN������Ϣ�ṹ����
*****************************************************************************/
typedef struct
{
    TAF_PS_MSG_ID_ENUM_UINT32           ulMsgId;                                /*_H2ASN_MsgChoice_Export TAF_PS_MSG_ID_ENUM_UINT32*/
    VOS_UINT8                           aucMsgBlock[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          TAF_PS_MSG_ID_ENUM_UINT32
    ****************************************************************************/
}TAF_PS_MSG_REQ;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    TAF_PS_MSG_REQ                      stMsgReq;
}TafApsApi_MSG;

typedef struct
{
    TAF_PS_EVT_ID_ENUM_UINT32           ulEvtId;                                /*_H2ASN_MsgChoice_Export TAF_PS_EVT_ID_ENUM_UINT32*/
    VOS_UINT8                           aucEvtBlock[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          TAF_PS_EVT_ID_ENUM_UINT32
    ****************************************************************************/
}TAF_PS_EVT_CNF;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    TAF_PS_EVT_CNF                      stEvtCnf;
}TafApsApi_EVT;

/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/



/*****************************************************************************
  10 ��������
*****************************************************************************/

/*****************************************************************************
 �� �� ��  : TAF_PS_SetPrimPdpContextInfo
 ��������  : ����Primary PDP��������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstPdpContextInfo          - Primary PDP��������Ϣ
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_SetPrimPdpContextInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_PDP_PRIM_CONTEXT_EXT_STRU      *pstPdpContextInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetPrimPdpContextInfo
 ��������  : ��ȡPrimary PDP��������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetPrimPdpContextInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetPdpContextInfo
 ��������  : ��ȡPDP��������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetPdpContextInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);
/*****************************************************************************
 �� �� ��  : TAF_PS_SetSecPdpContextInfo
 ��������  : ����Secondary PDP��������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstPdpContextInfo          - Secondary PDP��������Ϣ
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_SetSecPdpContextInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_PDP_SEC_CONTEXT_EXT_STRU       *pstPdpContextInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetSecPdpContextInfo
 ��������  : ��ȡSecondary PDP��������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetSecPdpContextInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_SetTftInfo
 ��������  : ����PDP TFT����
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstTftInfo                 - TFT����
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_SetTftInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_TFT_EXT_STRU                   *pstTftInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetTftInfo
 ��������  : ��ȡPDP TFT����
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetTftInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_SetUmtsQosInfo
 ��������  : ����UMTS QOS������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstUmtsQosInfo             - UMTS QOS����
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_SetUmtsQosInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_UMTS_QOS_EXT_STRU              *pstUmtsQosInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetUmtsQosInfo
 ��������  : ��ȡUMTS QOS������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetUmtsQosInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_SetUmtsQosMinInfo
 ��������  : ����UMTS MIN QOS������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstUmtsQosMinInfo          - UMTS MIN QOS����
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_SetUmtsQosMinInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_UMTS_QOS_EXT_STRU              *pstUmtsQosMinInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetUmtsQosMinInfo
 ��������  : ��ȡUMTS MIN QOS������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetUmtsQosMinInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetDynamicUmtsQosInfo
 ��������  : ��ȡ��̬UMTS QOS������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstCidListInfo             - CID�б�
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetDynamicUmtsQosInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_CID_LIST_STRU                  *pstCidListInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_SetPdpContextState
 ��������  : ����ָ��CID(��)��Ӧ��PDP��״̬
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstCidListStateInfo        - CID�б�״̬
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_SetPdpContextState(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_CID_LIST_STATE_STRU            *pstCidListStateInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetPdpContextState
 ��������  : ��ȡ�����Ѷ���CID��Ӧ��PDP��״̬
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetPdpContextState(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_CallModify
 ��������  : �޸�PS CALL����
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             TAF_CID_LIST_STRU          - CID�б�
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_CallModify(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_CID_LIST_STRU                  *pstCidListInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_CallAnswer
 ��������  : Ӧ��PS CALL
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstAnsInfo                 - PS CALLӦ����Ϣ
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_CallAnswer(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_PS_ANSWER_STRU                 *pstAnsInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_CallHangup
 ��������  : �Ҷ�PS CALL
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_CallHangup(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_CallOrig
 ��������  : ����PS CALL
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstDialParaInfo            - PS CALL����
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_CallOrig(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_PS_DIAL_PARA_STRU              *pstDialParaInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_CallEnd
 ��������  : ����PS CALL
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             stCidListInfo              - CID�б�
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_CallEnd(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    VOS_UINT8                           ucCid
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetPdpIpAddrInfo
 ��������  : ��ȡָ��CID(��)��PDP IP��ַ��Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstCidListInfo             - CID�б�
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetPdpIpAddrInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_CID_LIST_STRU                  *pstCidListInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_SetAnsModeInfo
 ��������  : ����PS�����Ӧ��ģʽ��Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             ulAnsMode                  - Ӧ��ģʽ��Ϣ
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_SetAnsModeInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    VOS_UINT32                          ulAnsMode
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetAnsModeInfo
 ��������  : ��ȡPS�����Ӧ��ģʽ��Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetAnsModeInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetDynamicPrimPdpContextInfo
 ��������  : ��ȡָ�����Ѷ���CID�Ķ�̬Primary PDP��������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             ucCid                      - CID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetDynamicPrimPdpContextInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    VOS_UINT8                           ucCid
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetDynamicSecPdpContextInfo
 ��������  : ��ȡָ�����Ѷ���CID�Ķ�̬Secondary PDP��������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             ucCid                      - CID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetDynamicSecPdpContextInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    VOS_UINT8                           ucCid
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetDynamicTftInfo
 ��������  : ��ȡָ�����Ѷ���CID�Ķ�̬TFT��Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             ucCid                      - CID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetDynamicTftInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    VOS_UINT8                           ucCid
);

/*****************************************************************************
 �� �� ��  : TAF_PS_SetEpsQosInfo
 ��������  : ����ָ��CID��EPS QOS������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstEpsQosInfo              - EPS QOS������Ϣ
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_SetEpsQosInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_EPS_QOS_EXT_STRU               *pstEpsQosInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetEpsQosInfo
 ��������  : ��ȡEPS QOS������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetEpsQosInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetDynamicEpsQosInfo
 ��������  : ��ȡָ�����Ѷ���CID�Ķ�̬EPS QOS����
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             ucCid                      - CID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetDynamicEpsQosInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    VOS_UINT8                           ucCid
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetDsFlowInfo
 ��������  : ��ȡ����������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstQueryConfigInfo         - DSFLOW��ѯ���ò���
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetDsFlowInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_ClearDsFlowInfo
 ��������  : �������������Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstClearConfigInfo         - ����������ò�����Ϣ
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_ClearDsFlowInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_DSFLOW_CLEAR_CONFIG_STRU       *pstClearConfigInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_ConfigDsFlowRpt
 ��������  : ���������ϱ�ģʽ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstReportConfigInfo        - �����ϱ����ò�����Ϣ
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_ConfigDsFlowRpt(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_DSFLOW_REPORT_CONFIG_STRU      *pstReportConfigInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_SetPdpAuthInfo
 ��������  : ����PDP��Ȩ����
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstPdpAuthInfo             - PDP��Ȩ����
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_SetPdpAuthInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_PDP_AUTH_EXT_STRU              *pstPdpAuthInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetPdpAuthInfo
 ��������  : ��ȡPDP��Ȩ����
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetPdpAuthInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_SetPdpDnsInfo
 ��������  : ����PDP DNS��Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstPdpDnsInfo              - PDP DNS��Ϣ
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_SetPdpDnsInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_PDP_DNS_EXT_STRU               *pstPdpDnsInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetPdpDnsInfo
 ��������  : ��ȡPDP DNS��Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetPdpDnsInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_TrigGprsData
 ��������  : ��������GPRS����
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstGprsDataInfo            - GPRS������Ϣ
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_TrigGprsData(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_GPRS_DATA_STRU                 *pstGprsDataInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_ConfigNbnsFunction
 ��������  : ����NBNS����
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             ulEnabled                  - NBNS����ʹ�ܱ��
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_ConfigNbnsFunction(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    VOS_UINT32                          ulEnabled
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetNdisStateInfo
 ��������  : ��ȡNDIS״̬��Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetNdisStateInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_SetAuthDataInfo
 ��������  : ���ü�Ȩ������Ϣ(NDIS)
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstAuthDataInfo            - ��Ȩ����
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_SetAuthDataInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_AUTHDATA_EXT_STRU              *pstAuthDataInfo
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetAuthDataInfo
 ��������  : ��ȡ��Ȩ������Ϣ(NDIS)
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetAuthDataInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetGprsActiveType
 ��������  : ��ȡD����GPRS����(PPP����)
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstAtdPara                 - D����Ų���
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetGprsActiveType(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_ATD_PARA_STRU                  *pstAtdPara
);

/*****************************************************************************
 �� �� ��  : TAF_PS_PppDialOrig
 ��������  : ����PPP����
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             ucCid                      - CID
             pstPppReqConfigInfo        - PPP���ò���
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_PppDialOrig(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    VOS_UINT8                           ucCid,
    TAF_PPP_REQ_CONFIG_INFO_STRU       *pstPppReqConfigInfo
);

#if(FEATURE_ON == FEATURE_LTE)
/*****************************************************************************
 �� �� ��  : TAF_PS_GetLteCsInfo
 ��������  :
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetLteCsInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetCemodeInfo
 ��������  :
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetCemodeInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId
);

/*****************************************************************************
 �� �� ��  : TAF_PS_SetPdpProfInfo
 ��������  :
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             pstPdpProfInfo             - PdpProfile ���ò���
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_SetPdpProfInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_PDP_PROFILE_EXT_STRU           *pstPdpProfInfo
);
#endif

/*****************************************************************************
 �� �� ��  : TAF_PS_GetCidSdfParaInfo
 ��������  : ��ȡ����NV���е�SDF������Ϣ, ֧��ͬ�����첽���ַ�ʽ
             ��������ǿ� --- ͬ����ʽ(Ŀǰ��֧��C��)
             �������Ϊ�� --- �첽��ʽ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : pstSdfQueryInfo            - SDF������Ϣ
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetCidSdfParaInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_SDF_PARA_QUERY_INFO_STRU       *pstSdfQueryInfo
);


/*****************************************************************************
 �� �� ��  : TAF_PS_GetUnusedCid
 ��������  : ��ȡ����δ�����CID
             ��������ǿ� --- ͬ����ʽ(Ŀǰ��֧��C��)
             �������Ϊ�� --- �첽��ʽ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
 �������  : puCid                      - ����δ����CID
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetUnusedCid(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    VOS_UINT8                          *puCid
);

/*****************************************************************************
 �� �� ��  : TAF_PS_GetDynamicDnsInfo
 ��������  : ��ȡָ��CID��DNS��Ϣ
 �������  : ulModuleId                 - ��дPID
             usClientId                 - �ͻ���ID
             ucOpId                     - ������ID
             ucCid                      - CID
 �������  : ��
 �� �� ֵ  : VOS_OK                     - �ɹ�
             VOS_ERR                    - ʧ��
*****************************************************************************/
VOS_UINT32 TAF_PS_GetDynamicDnsInfo(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    VOS_UINT8                           ucCid
);


VOS_UINT32 TAF_PS_SetImsPdpCfg(
    VOS_UINT32                          ulModuleId,
    VOS_UINT16                          usClientId,
    VOS_UINT8                           ucOpId,
    TAF_IMS_PDP_CFG_STRU               *pstImsPdpCfg
);

#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif



#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif
