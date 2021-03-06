/* This software is available to you under a choice of one of two
* licenses.  You may choose to be licensed under the terms of the GNU
* General Public License (GPL) Version 2, available from the file
* COPYING, or the Open Ethernet BSD license below:
*
*     Redistribution and use in source and binary forms, with or
*     without modification, are permitted provided that the following
*     conditions are met:
*
*      - Redistributions of source code must retain the above
*        copyright notice, this list of conditions and the following
*        disclaimer.
*
*      - Redistributions in binary form must reproduce the above
*        copyright notice, this list of conditions and the following
*        disclaimer in the documentation and/or other materials
*        provided with the distribution.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
* BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE. 
*/

#ifndef __OES_API_FDB_H__
#define __OES_API_FDB_H__

/***********************************************
 *  API functions
 ***********************************************/

/**
 * This function sets the log verbosity level of FDB MODULE
 * @param[in]  verbosity_level  - FDB module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_fdb_log_verbosity_level_set(
                               int   verbosity_level
                               );

/**
 * This function gets the log verbosity level of FDB MODULE
 * @param[out]  verbosity_level  - FDB module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_fdb_log_verbosity_level_get(
                                   int   * verbosity_level
                                   );

/**
 * This function sets the FDB age time, in seconds. Age time is
 *  the time after which auto learned addresses are deleted from
 *  the FDB if they receive no traffic.
 *  
 * @param[in] br_id - Bridge id 
 * @param[out] age_time - Time in seconds.
 * @param[in,out] fdb_age_time_vs_ext - vendor specific 
 *       extention .
 * 
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error.
 */

oes_status_e 
oes_api_fdb_age_time_set(
                        int br_id,
                        unsigned int  age_time,
                        void * fdb_age_time_vs_ext
                        );

/**
 * This function gets the FDB age time, in seconds. Age time is
 *  the time after which auto learned addresses are deleted from
 *  the FDB if they receive no traffic.
 *  
 * @param[in] br_id - Bridge id 
 * @param[out] age_time- Time in seconds.
 * @param[in,out] fdb_age_time_vs_ext - vendor specific 
 *       extention .
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e 
oes_api_fdb_age_time_get(
                        int br_id,
                        unsigned int  * age_time,
                        void * fdb_age_time_vs_ext
                        );

/**
 *  This function adds UC MAC and UC LAG MAC entries in the FDB.
 *  currently it support only static mac insertion.
 *  
 * @param[in] access_cmd - add/ delete 
 * @param[in] br_id - Bridge id  
 * @param[in] mac_entry_list- mac record arry pointer . On 
 *       deletion, entry_type is DONT_CARE
 * @param[in] mac_cnt - mac record arry size  
 * @param[in] fdb_uc_mac_addr_vs_ext - vendor specific extention
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e 
oes_api_fdb_uc_mac_addr_set(
                           enum oes_access_cmd access_cmd,
                           int br_id,
                           struct oes_fdb_uc_mac_addr_params * mac_entry_list,
                           unsigned short   mac_cnt,
                           void * fdb_uc_mac_addr_vs_ext
                           );

/**
 * This function reads MAC entries from the SDK 
 *
 * The function can receive three types of input: 
 * @param[in] access_cmd -  get, get_next, get first 
 * @param[in] br_id - Bridge id   
 * @param[out] mac_entry- mac record arry pointer . On 
 *       deletion, entry_type is DONT_CARE
 * @param[in] mac_cnt - mac record arry size  
 * @param[in,out] fdb_uc_mac_addr_vs_ext - vendor specific 
 *       extention
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e 
oes_api_fdb_uc_mac_addr_get(
                           enum oes_access_cmd access_cmd,
                           int br_id,
                           struct oes_fdb_uc_mac_addr_params * mac_entry_list,
                           unsigned short  * mac_cnt,
                           void * fdb_uc_mac_addr_vs_ext
                           );

/**
 *  This function counts all MAC entries in SW FDB table (static + dynamic).
 * 
 * @param[in] br_id - Bridge id 
 * @param[out] mac_cnt- retrieved number of entries 
 * @param[in,out] fdb_uc_count_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e 
oes_api_fdb_uc_count(
    `               int br_id,
	                unsigned short  * mac_cnt,
                    void * fdb_uc_count_vs_ext
                    );

/**
 * This function sets/removes limit on the amount of dynamic MACs learned on port.
 *
 * @param[in] br_id - Bridge id
 * @param[in] access_cmd - SET/DELETE
 * @param[in] log_port - logical port ID
 * @param[in] limit - When SET command is used, this is the new limit to set
 *                    (between 0 and OES_FDB_MAX_ENTRIES)
 * @param[in,out] fdb_uc_limit_port_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_fdb_uc_limit_port_set(
                             int br_id,
                             enum oes_access_cmd 	 access_cmd,
                             unsigned long  log_port,
                             unsigned int		limit,
                             void * fdb_uc_limit_port_vs_ext
                             );

/**
 * This function sets/removes limit on the amount of dynamic 
 * MACs learned on VID. 
 *
 * @param[in] br_id - Bridge id
 * @param[in] access_cmd - SET/DELETE 
 * @param[in] vid - vlan ID 
 * @param[in] limit - When SET command is used, this is the new limit to set
 *                    (between 0 and OES_FDB_MAX_ENTRIES)
 * @param[in,out] fdb_uc_limit_vlan_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_fdb_uc_limit_vlan_set(
		                     int br_id,
                             enum oes_access_cmd   access_cmd,
                             unsigned short 	vid,
                             unsigned int		limit,
                             void * fdb_uc_limit_port_vs_ext
                             );

/**
 * This function returns the maximum amount of dynamic MACs that can be learned on port.
 *
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - logical port ID
 * @param[out] limit- the limit configure on the port 
 * @param[in,out] ffdb_uc_limit_port_vs_ext- vendor specific 
 *       extention
 * 
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_fdb_uc_limit_port_get(
		                     int br_id,
                             unsigned long  log_port,
                             unsigned int	*	limit,
                             void * fdb_uc_limit_port_vs_ext
                             );

/**
 * This function returns the maximum amount of dynamic MACs that 
 * can be learned on VID. 
 *  
 * @param[in] br_id - Bridge id  
 * @param[in]  vid- Vlan ID 
 * @param[out] limit- the limit configure on the port 
 * @param[in,out] fdb_uc_limit_vlan_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_fdb_uc_limit_vid_get(
                            int br_id,
                            unsigned short	vid,
                            unsigned int	* limit,
                            void * fdb_uc_limit_vid_vs_ext
                            );

/**
 *  This function adds, deletes MC MAC entries from the FDB.
 *  
 * @param[in] br_id - bridge id
 * @param[in] access_cmd - add/ delete (vendor can chose to add 
 *       additional command support
 * @param[in] vid - vlan ID 
 * @param[in] mac_addr - multicast group  MAC address 
 * @param[in] log_port_list- a pointer to a port list arry
 * @param[in] port_cnt - sizeof port list
 * @param[in,out] fdb_mc_mac_addr_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_mc_mac_addr_set(
                           int br_id,
	                       enum oes_access_cmd access_cmd,
                           unsigned short vid,
                           struct ether_addr  mc_addr,
                           unsigned long * log_port_list,
                           unsigned short port_cnt,
                           void * fdb_mc_mac_addr_vs_ext
                           );
	

/**
*  This function returns MC MAC entries data.
*  
 * @param[in] br_id - bridge id
 * @param[in] vid - vlan ID 
 * @param[in] mac_addr - multicast group  MAC address 
 * @param[out] log_port_list- a pointer to a port list arry
*  @param[out] port_cnt - sizeof port list
*  @param[in,out] fdb_mc_mac_addr_vs_ext- vendor specific 
*        extention
*  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error.
 */
 
oes_status_e 
oes_api_fdb_mc_mac_addr_get(
                           int br_id,
                           unsigned short vid,
                           struct ether_addr mc_addr,
                           unsigned long * log_port_list_p
                           unsigned short  *    port_cnt_p,
                           void * fdb_mc_mac_addr_vs_ext
                           ):


/**
 * This function deletes all FDB table on a switch partition. 
 *  
 * @param[in] br_id - bridge id 
 * @param[in,out] fdb_uc_flush_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if parameters exceed range. 
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_uc_flush_set(
                        int br_id,
                        void * fdb_uc_flush_vs_ext
                        );

/**
 *  This function deletes the FDB table entries that are related
 *  to a flushed port.
 *  
 * @param[in] br_id - bridge id 
 * @param[in] log_port- logical port ID
 * @param[in,out] fdb_uc_flush_port_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if parameters exceed range. 
 * @return OES_STATUS_ERROR general error.
 *
 */
oes_status_e 
oes_api_fdb_uc_flush_port_set(
                             int br_id,
                             unsigned long log_port,
                             void * fdb_uc_flush_port_vs_ext
                             );

/**
 * This function deletes all FDB table entries that were 
 * learnedon the flushed VID
 *  
 * @param[in] br_id - bridge id 
 * @param[in] vid- vlan ID
 * @param[in,out] fdb_uc_flush_vid_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if parameters exceed range. 
 * @return OES_STATUS_ERROR general error.
 *
 */
oes_status_e 
oes_api_fdb_uc_flush_vid_set(
                            int br_id,
                            unsigned short vid,
                            void * fdb_uc_flush_vid_vs_ext
                            );

/**
 * This function deletes all FDB table entries that were 
 * learnedon the flushed VID and port. 
 *  
 * @param[in] br_id - bridge id 
 * @param[in] vid- vlan ID 
 * @param[in] log_port- logical port ID 
 * @param[in,out] fdb_uc_flush_port_vid_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if parameters exceed range. 
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_uc_flush_port_fid_set(
	                             int br_id,
                                 unsigned short vid,
                                 unsigned long log_port,
                                 void * fdb_uc_flush_port_vid_vs_ext
                                 );
	

/**
 * This function deletes all FDB MC tables on a switch
 *  partition.
 *  
 * @param[in] br_id - bridge id  
 * @param[in,out] fdb_mc_flush_vs_ext- vendor specific extention 
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if parameters exceed range. 
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_mc_flush_all_set(
                            int br_id,
                            void * fdb_mc_flush_vs_ext
                            );

/**
 * This function deletes all FDB MC table entries that 
 * werelearned on the flushed VID, on a switch partition. 
 *  
 * @param[in] br_id - bridge id 
 * @param[in] vid - Vlan ID 
 * @param[in,out] fdb_mc_vid_flush_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if parameters exceed range. 
 * @return OES_STATUS_ERROR general error.
*/
oes_status_e 
oes_api_fdb_mc_flush_vid_set(
                            int br_id,
                            unsigned short vid,
                            void * fdb_mc_fid_flush_vs_ext
                            );
/**
 *  This function sets the FDB learning mode 
 *  to disable learning or enable controlled,automatic  learning
 *  
 *  @param[in] br_id  - bridge id
 *  @param[in] learn_mode - enumerator for the following values:
 *       dont_learn, automatic_learnin, controled_learn,
 * @param[in,out] fdb_learn_mode_set_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if parameters exceed range. 
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_learn_mode_set(
                          int br_id,
                          enum oes_fdb_learn_mode learn_mode,
                          void * fdb_learn_mode_set_vs_ext
                          );

/**
 * This function gets  the FDB learning mode to disable learning
 * or enable controlled,automatic  learning 
 *  
 * @param[in] br_id - bridge id
 * @param[out] learn_mode- enumerator for the following
 *       values: dont_learn, automatic_learnin, controled_learn,
 * @param[in,out] fdb_learn_mode_set_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if parameters exceed range. 
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_learn_mode_get(
                          int br_id,
                          enum oes_fdb_learn_mode *learn_mode_p,
                          void * fdb_learn_mode_set_vs_ext
                          );



/**
 *  This function sets the FDB learning mode 
 *  to disable learning or enable controlled,automatic  learning
 *  
 *  @param[in] br_id - bridge id
 *  @param[in] vid - vlan ID 
 *  @param[in] learn_mode - enumerator for the following values:
 *       dont_learn, automatic_learnin, controled_learn,
 * @param[in,out] fdb_learn_mode_set_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if parameters exceed range. 
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_vid_learn_mode_set(
                              int br_id,
                              unsigned long vid,
                              enum oes_fdb_learn_mode learn_mode,
                              void * fdb_vid_learn_mode_set_vs_ext
                              );

/**
 *  This function gets  the FDB learning mode to disable
 *  learning or enable controlled,automatic  learning
 *  
 *  @param[in] br_id  - bridge id
 *  @param[in] vid   - vlan ID 
 *  @param[out] learn_mode- enumerator for the following
 *       values: dont_learn, automatic_learnin, controled_learn,
 * @param[in,out] fdb_learn_mode_set_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if parameters exceed range. 
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_vid_learn_mode_get(
                              int br_id,
                              unsigned long vid,
                              enum oes_fdb_learn_mode *learn_mode_p,
                              void * fdb_vid_learn_mode_set_vs_ext
                              );


/**
 * This function sets the FDB learning mode to disable learning 
 * or enable controlled,automatic  learning 
 *  
 * @param[in] br_id  - bridge id
 * @param[in] log_port  - logical port ID 
 * @param[in] learn_mode - enumerator for the following values:
 *       dont_learn, automatic_learnin, controled_learn,
 * @param[in,out] fdb_port_learn_mode_set_vs_ext- vendor 
 *       specific extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if parameters exceed range. 
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_port_learn_mode_set(
                               int br_id,
                               unsigned long log_port,
                               enum oes_fdb_learn_mode learn_mode,
                               void * fdb_port_learn_mode_set_vs_ext
                               );

/**
 * This function gets  the FDB learning mode to disable learning
 * or enable controlled,automatic  learning 
 *  
 * @param[in] br_id  - bridge id
 * @param[in] log_port  - logical port ID 
 * @param[out] learn_mode- enumerator for the following
 *       values: dont_learn, automatic_learnin, controled_learn,
 * @param[in,out] fdb_port_learn_mode_set_vs_ext- vendor 
 *       specific extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if parameters exceed range. 
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_port_learn_mode_get(
                               int br_id,
                               unsigned long log_port,
                               enum oes_fdb_learn_mode *learn_mode_p,
                               void * fdb_port_learn_mode_set_vs_ext
                               );

#endif /* __OES_API_FDB_H__ */
