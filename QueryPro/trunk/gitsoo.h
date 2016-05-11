#ifndef __GITSOO_H__
#define __GITSOO_H__

#include <utlist.h>
#include <uthash.h>
#include <utarray.h>
#include <mysql.h>

/* 2-gram */
#define N_GRAM 2

/* 倒排列表（以文档编号和位置信息为元素的链表结构）*/
typedef struct _postings_list {
  int document_id;             /* 文档编号 */
  UT_array *positions;         /* 位置信息的数组 */
  int positions_count;         /* 位置信息的条数 */
  struct _postings_list *next; /* 指向下一个倒排列表的指针 */
} postings_list;

/* 倒排索引（以词元编号为键，以倒排列表为值的关联数组） */
typedef struct {
  int token_id;                 /* 词元编号（Token ID）*/
  postings_list *postings_list; /* 指向包含该词元的倒排列表的指针 */
  int docs_count;               /* 出现过该词元的文档数 */
  int positions_count;          /* 该词元在所有文档中的出现次数之和 */
  UT_hash_handle hh;            /* 用于将该结构体转化为哈希表 */
} inverted_index_hash, inverted_index_value;

/* 应用程序的全局配置 */
typedef struct _gitsoo_env {
  const char *db_path;

  int token_len;                  //词元的长度。N-gram中N的取值
  int enable_phrase_search;       // 是否进行短语检索

  inverted_index_hash *ii_buffer; //用于更新倒排索引的缓冲区（Buffer）
  int ii_buffer_count;            //用于更新倒排索引的缓冲区中的文档数
  int ii_buffer_update_threshold; //缓冲区中文档数的阈值
  int indexed_count;              //建立了索引的文档数

  /* 与mysql相关的配置 */
  mysql *db; /* mysql的实例 */
  /* mysql的准备语句 */
  mysql_stmt *...
  
} gitsoo_env;

#ifndef FALSE
#define FALSE 0
#define TRUE 1
#endif

#define DEFAULT_II_BUFFER_UPDATE_THRESHOLD 2048

#endif
