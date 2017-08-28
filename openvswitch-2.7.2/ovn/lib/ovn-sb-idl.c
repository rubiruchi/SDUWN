/* Generated automatically -- do not modify!    -*- buffer-read-only: t -*- */

#include <config.h>
#include "ovn/lib/ovn-sb-idl.h"
#include <limits.h>
#include "ovs-thread.h"
#include "ovsdb-data.h"
#include "ovsdb-error.h"
#include "util.h"



static struct sbrec_address_set *
sbrec_address_set_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct sbrec_address_set, header_) : NULL;
}

static struct sbrec_chassis *
sbrec_chassis_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct sbrec_chassis, header_) : NULL;
}

static struct sbrec_connection *
sbrec_connection_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct sbrec_connection, header_) : NULL;
}

static struct sbrec_dhcp_options *
sbrec_dhcp_options_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct sbrec_dhcp_options, header_) : NULL;
}

static struct sbrec_dhcpv6_options *
sbrec_dhcpv6_options_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct sbrec_dhcpv6_options, header_) : NULL;
}

static struct sbrec_datapath_binding *
sbrec_datapath_binding_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct sbrec_datapath_binding, header_) : NULL;
}

static struct sbrec_encap *
sbrec_encap_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct sbrec_encap, header_) : NULL;
}

static struct sbrec_logical_flow *
sbrec_logical_flow_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct sbrec_logical_flow, header_) : NULL;
}

static struct sbrec_mac_binding *
sbrec_mac_binding_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct sbrec_mac_binding, header_) : NULL;
}

static struct sbrec_multicast_group *
sbrec_multicast_group_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct sbrec_multicast_group, header_) : NULL;
}

static struct sbrec_port_binding *
sbrec_port_binding_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct sbrec_port_binding, header_) : NULL;
}

static struct sbrec_sb_global *
sbrec_sb_global_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct sbrec_sb_global, header_) : NULL;
}

static struct sbrec_ssl *
sbrec_ssl_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct sbrec_ssl, header_) : NULL;
}

/* Address_Set table. */

static void
sbrec_address_set_parse_addresses(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_address_set *row = sbrec_address_set_cast(row_);
    row->addresses = NULL;
    row->n_addresses = 0;
    for (size_t i = 0; i < datum->n; i++) {
        if (!row->n_addresses) {
            row->addresses = xmalloc(datum->n * sizeof *row->addresses);
        }
        row->addresses[row->n_addresses] = datum->keys[i].string;
        row->n_addresses++;
    }
}

static void
sbrec_address_set_parse_name(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_address_set *row = sbrec_address_set_cast(row_);

    if (datum->n >= 1) {
        row->name = datum->keys[0].string;
    } else {
        row->name = "";
    }
}

static void
sbrec_address_set_unparse_addresses(struct ovsdb_idl_row *row_)
{
    struct sbrec_address_set *row = sbrec_address_set_cast(row_);
    free(row->addresses);
}

static void
sbrec_address_set_unparse_name(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_address_set_init__(struct ovsdb_idl_row *row)
{
    sbrec_address_set_init(sbrec_address_set_cast(row));
}

/* Clears the contents of 'row' in table "Address_Set". */
void
sbrec_address_set_init(struct sbrec_address_set *row)
{
    memset(row, 0, sizeof *row); 
    row->name = "";
}

/* Searches table "Address_Set" in 'idl' for a row with UUID 'uuid'.  Returns
 * a pointer to the row if there is one, otherwise a null pointer.  */
const struct sbrec_address_set *
sbrec_address_set_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return sbrec_address_set_cast(ovsdb_idl_get_row_for_uuid(idl, &sbrec_table_address_set, uuid));
}

/* Returns a row in table "Address_Set" in 'idl', or a null pointer if that
 * table is empty.
 *
 * Database tables are internally maintained as hash tables, so adding or
 * removing rows while traversing the same table can cause some rows to be
 * visited twice or not at apply. */
const struct sbrec_address_set *
sbrec_address_set_first(const struct ovsdb_idl *idl)
{
    return sbrec_address_set_cast(ovsdb_idl_first_row(idl, &sbrec_table_address_set));
}

/* Returns a row following 'row' within its table, or a null pointer if 'row'
 * is the last row in its table. */
const struct sbrec_address_set *
sbrec_address_set_next(const struct sbrec_address_set *row)
{
    return sbrec_address_set_cast(ovsdb_idl_next_row(&row->header_));
}

unsigned int sbrec_address_set_get_seqno(const struct ovsdb_idl *idl)
{
    return ovsdb_idl_table_get_seqno(idl, &sbrec_table_address_set);
}

unsigned int sbrec_address_set_row_get_seqno(const struct sbrec_address_set *row, enum ovsdb_idl_change change)
{
    return ovsdb_idl_row_get_seqno(&row->header_, change);
}

const struct sbrec_address_set *
sbrec_address_set_track_get_first(const struct ovsdb_idl *idl)
{
    return sbrec_address_set_cast(ovsdb_idl_track_get_first(idl, &sbrec_table_address_set));
}

const struct sbrec_address_set
*sbrec_address_set_track_get_next(const struct sbrec_address_set *row)
{
    return sbrec_address_set_cast(ovsdb_idl_track_get_next(&row->header_));
}


/* Deletes 'row' from table "Address_Set".  'row' may be freed, so it must not be
 * accessed afterward.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_address_set_delete(const struct sbrec_address_set *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

/* Inserts and returns a new row in the table "Address_Set" in the database
 * with open transaction 'txn'.
 *
 * The new row is assigned a randomly generated provisional UUID.
 * ovsdb-server will assign a different UUID when 'txn' is committed,
 * but the IDL will replace any uses of the provisional UUID in the
 * data to be to be committed by the UUID assigned by ovsdb-server. */
struct sbrec_address_set *
sbrec_address_set_insert(struct ovsdb_idl_txn *txn)
{
    return sbrec_address_set_cast(ovsdb_idl_txn_insert(txn, &sbrec_table_address_set, NULL));
}

bool
sbrec_address_set_is_updated(const struct sbrec_address_set *row, enum sbrec_address_set_column_id column)
{
    return ovsdb_idl_track_is_updated(&row->header_, &sbrec_address_set_columns[column]);
}

/* Causes the original contents of column "addresses" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "addresses" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "addresses" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "addresses" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_address_set_insert()).
 *
 *   - If "addresses" has already been modified (with
 *     sbrec_address_set_set_addresses()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_address_set_set_addresses() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_address_set_verify_addresses(const struct sbrec_address_set *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_address_set_col_addresses);
}

/* Causes the original contents of column "name" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "name" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "name" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "name" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_address_set_insert()).
 *
 *   - If "name" has already been modified (with
 *     sbrec_address_set_set_name()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_address_set_set_name() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_address_set_verify_name(const struct sbrec_address_set *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_address_set_col_name);
}

/* Returns the "addresses" column's value from the "Address_Set" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes addresses's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "addresses" member in sbrec_address_set. */
const struct ovsdb_datum *
sbrec_address_set_get_addresses(const struct sbrec_address_set *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_address_set_col_addresses);
}

/* Returns the "name" column's value from the "Address_Set" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes name's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "name" member in sbrec_address_set. */
const struct ovsdb_datum *
sbrec_address_set_get_name(const struct sbrec_address_set *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_address_set_col_name);
}

/* Sets the "addresses" column from the "Address_Set" table in 'row' to
 * the 'addresses' set with 'n_addresses' entries.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_address_set_set_addresses(const struct sbrec_address_set *row, const char **addresses, size_t n_addresses)
{
    struct ovsdb_datum datum;

    datum.n = n_addresses;
    datum.keys = n_addresses ? xmalloc(n_addresses * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (size_t i = 0; i < n_addresses; i++) {
        datum.keys[i].string = xstrdup(addresses[i]);
    }
    ovsdb_idl_txn_write(&row->header_, &sbrec_address_set_col_addresses, &datum);
}

/* Sets the "name" column from the "Address_Set" table in 'row' to
 * 'name'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_address_set_set_name(const struct sbrec_address_set *row, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_address_set_col_name, &datum);
}

/* Adds the value 'new_value' to the "addresses" set column from the "Address_Set" table
 * in 'row'.
 *
 */
void
sbrec_address_set_update_addresses_addvalue(const struct sbrec_address_set *row, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &sbrec_address_set_col_addresses,
                                    datum);
}

/* Deletes the value 'delete_value' from the "addresses" set column from the
 * "Address_Set" table in 'row'.
 *
 */
void
sbrec_address_set_update_addresses_delvalue(const struct sbrec_address_set *row, const char *delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_value);

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &sbrec_address_set_col_addresses,
                                    datum);
}

/* Sets the "addresses" column from the "Address_Set" table in 'row' to
 * the 'addresses' set with 'n_addresses' entries.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_address_set_add_clause_addresses(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char **addresses, size_t n_addresses)
{
    struct ovsdb_datum datum;
    datum.n = n_addresses;
    datum.keys = n_addresses ? xmalloc(n_addresses * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (size_t i = 0; i < n_addresses; i++) {
        datum.keys[i].string = CONST_CAST(char *, addresses[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_VOID);
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_address_set_col_addresses,
                          &datum);
    free(datum.keys);
}

/* Sets the "name" column from the "Address_Set" table in 'row' to
 * 'name'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_address_set_add_clause_name(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_address_set_col_name,
                          &datum);
}

void
sbrec_address_set_set_condition(struct ovsdb_idl *idl, struct ovsdb_idl_condition *condition)
{
    ovsdb_idl_set_condition(idl, &sbrec_table_address_set, condition);
}

struct ovsdb_idl_column sbrec_address_set_columns[SBREC_ADDRESS_SET_N_COLUMNS] = {
    [SBREC_ADDRESS_SET_COL_ADDRESSES] = {
         .name = "addresses",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 0,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_address_set_parse_addresses,
         .unparse = sbrec_address_set_unparse_addresses,
    },

    [SBREC_ADDRESS_SET_COL_NAME] = {
         .name = "name",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_address_set_parse_name,
         .unparse = sbrec_address_set_unparse_name,
    },

};

/* Chassis table. */

static void
sbrec_chassis_parse_encaps(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_chassis *row = sbrec_chassis_cast(row_);
    row->encaps = NULL;
    row->n_encaps = 0;
    for (size_t i = 0; i < datum->n; i++) {
        struct sbrec_encap *keyRow = sbrec_encap_cast(ovsdb_idl_get_row_arc(row_, &sbrec_table_encap, &datum->keys[i].uuid));
        if (!keyRow) {
            continue;
        }
        if (!row->n_encaps) {
            row->encaps = xmalloc(datum->n * sizeof *row->encaps);
        }
        row->encaps[row->n_encaps] = keyRow;
        row->n_encaps++;
    }
}

static void
sbrec_chassis_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_chassis *row = sbrec_chassis_cast(row_);
    smap_init(&row->external_ids);
    for (size_t i = 0; i < datum->n; i++) {
        smap_add(&row->external_ids,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
sbrec_chassis_parse_hostname(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_chassis *row = sbrec_chassis_cast(row_);

    if (datum->n >= 1) {
        row->hostname = datum->keys[0].string;
    } else {
        row->hostname = "";
    }
}

static void
sbrec_chassis_parse_name(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_chassis *row = sbrec_chassis_cast(row_);

    if (datum->n >= 1) {
        row->name = datum->keys[0].string;
    } else {
        row->name = "";
    }
}

static void
sbrec_chassis_parse_nb_cfg(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_chassis *row = sbrec_chassis_cast(row_);

    if (datum->n >= 1) {
        row->nb_cfg = datum->keys[0].integer;
    } else {
        row->nb_cfg = 0;
    }
}

static void
sbrec_chassis_parse_vtep_logical_switches(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_chassis *row = sbrec_chassis_cast(row_);
    row->vtep_logical_switches = NULL;
    row->n_vtep_logical_switches = 0;
    for (size_t i = 0; i < datum->n; i++) {
        if (!row->n_vtep_logical_switches) {
            row->vtep_logical_switches = xmalloc(datum->n * sizeof *row->vtep_logical_switches);
        }
        row->vtep_logical_switches[row->n_vtep_logical_switches] = datum->keys[i].string;
        row->n_vtep_logical_switches++;
    }
}

static void
sbrec_chassis_unparse_encaps(struct ovsdb_idl_row *row_)
{
    struct sbrec_chassis *row = sbrec_chassis_cast(row_);
    free(row->encaps);
}

static void
sbrec_chassis_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct sbrec_chassis *row = sbrec_chassis_cast(row_);
    smap_destroy(&row->external_ids);
}

static void
sbrec_chassis_unparse_hostname(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_chassis_unparse_name(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_chassis_unparse_nb_cfg(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_chassis_unparse_vtep_logical_switches(struct ovsdb_idl_row *row_)
{
    struct sbrec_chassis *row = sbrec_chassis_cast(row_);
    free(row->vtep_logical_switches);
}

static void
sbrec_chassis_init__(struct ovsdb_idl_row *row)
{
    sbrec_chassis_init(sbrec_chassis_cast(row));
}

/* Clears the contents of 'row' in table "Chassis". */
void
sbrec_chassis_init(struct sbrec_chassis *row)
{
    memset(row, 0, sizeof *row); 
    smap_init(&row->external_ids);
    row->hostname = "";
    row->name = "";
}

/* Searches table "Chassis" in 'idl' for a row with UUID 'uuid'.  Returns
 * a pointer to the row if there is one, otherwise a null pointer.  */
const struct sbrec_chassis *
sbrec_chassis_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return sbrec_chassis_cast(ovsdb_idl_get_row_for_uuid(idl, &sbrec_table_chassis, uuid));
}

/* Returns a row in table "Chassis" in 'idl', or a null pointer if that
 * table is empty.
 *
 * Database tables are internally maintained as hash tables, so adding or
 * removing rows while traversing the same table can cause some rows to be
 * visited twice or not at apply. */
const struct sbrec_chassis *
sbrec_chassis_first(const struct ovsdb_idl *idl)
{
    return sbrec_chassis_cast(ovsdb_idl_first_row(idl, &sbrec_table_chassis));
}

/* Returns a row following 'row' within its table, or a null pointer if 'row'
 * is the last row in its table. */
const struct sbrec_chassis *
sbrec_chassis_next(const struct sbrec_chassis *row)
{
    return sbrec_chassis_cast(ovsdb_idl_next_row(&row->header_));
}

unsigned int sbrec_chassis_get_seqno(const struct ovsdb_idl *idl)
{
    return ovsdb_idl_table_get_seqno(idl, &sbrec_table_chassis);
}

unsigned int sbrec_chassis_row_get_seqno(const struct sbrec_chassis *row, enum ovsdb_idl_change change)
{
    return ovsdb_idl_row_get_seqno(&row->header_, change);
}

const struct sbrec_chassis *
sbrec_chassis_track_get_first(const struct ovsdb_idl *idl)
{
    return sbrec_chassis_cast(ovsdb_idl_track_get_first(idl, &sbrec_table_chassis));
}

const struct sbrec_chassis
*sbrec_chassis_track_get_next(const struct sbrec_chassis *row)
{
    return sbrec_chassis_cast(ovsdb_idl_track_get_next(&row->header_));
}


/* Deletes 'row' from table "Chassis".  'row' may be freed, so it must not be
 * accessed afterward.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_chassis_delete(const struct sbrec_chassis *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

/* Inserts and returns a new row in the table "Chassis" in the database
 * with open transaction 'txn'.
 *
 * The new row is assigned a randomly generated provisional UUID.
 * ovsdb-server will assign a different UUID when 'txn' is committed,
 * but the IDL will replace any uses of the provisional UUID in the
 * data to be to be committed by the UUID assigned by ovsdb-server. */
struct sbrec_chassis *
sbrec_chassis_insert(struct ovsdb_idl_txn *txn)
{
    return sbrec_chassis_cast(ovsdb_idl_txn_insert(txn, &sbrec_table_chassis, NULL));
}

bool
sbrec_chassis_is_updated(const struct sbrec_chassis *row, enum sbrec_chassis_column_id column)
{
    return ovsdb_idl_track_is_updated(&row->header_, &sbrec_chassis_columns[column]);
}

/* Causes the original contents of column "encaps" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "encaps" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "encaps" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "encaps" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_chassis_insert()).
 *
 *   - If "encaps" has already been modified (with
 *     sbrec_chassis_set_encaps()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_chassis_set_encaps() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_chassis_verify_encaps(const struct sbrec_chassis *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_chassis_col_encaps);
}

/* Causes the original contents of column "external_ids" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "external_ids" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "external_ids" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "external_ids" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_chassis_insert()).
 *
 *   - If "external_ids" has already been modified (with
 *     sbrec_chassis_set_external_ids()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_chassis_set_external_ids() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_chassis_verify_external_ids(const struct sbrec_chassis *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_chassis_col_external_ids);
}

/* Causes the original contents of column "hostname" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "hostname" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "hostname" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "hostname" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_chassis_insert()).
 *
 *   - If "hostname" has already been modified (with
 *     sbrec_chassis_set_hostname()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_chassis_set_hostname() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_chassis_verify_hostname(const struct sbrec_chassis *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_chassis_col_hostname);
}

/* Causes the original contents of column "name" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "name" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "name" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "name" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_chassis_insert()).
 *
 *   - If "name" has already been modified (with
 *     sbrec_chassis_set_name()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_chassis_set_name() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_chassis_verify_name(const struct sbrec_chassis *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_chassis_col_name);
}

/* Causes the original contents of column "nb_cfg" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "nb_cfg" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "nb_cfg" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "nb_cfg" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_chassis_insert()).
 *
 *   - If "nb_cfg" has already been modified (with
 *     sbrec_chassis_set_nb_cfg()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_chassis_set_nb_cfg() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_chassis_verify_nb_cfg(const struct sbrec_chassis *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_chassis_col_nb_cfg);
}

/* Causes the original contents of column "vtep_logical_switches" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "vtep_logical_switches" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "vtep_logical_switches" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "vtep_logical_switches" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_chassis_insert()).
 *
 *   - If "vtep_logical_switches" has already been modified (with
 *     sbrec_chassis_set_vtep_logical_switches()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_chassis_set_vtep_logical_switches() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_chassis_verify_vtep_logical_switches(const struct sbrec_chassis *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_chassis_col_vtep_logical_switches);
}

/* Returns the "encaps" column's value from the "Chassis" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes encaps's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "encaps" member in sbrec_chassis. */
const struct ovsdb_datum *
sbrec_chassis_get_encaps(const struct sbrec_chassis *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &sbrec_chassis_col_encaps);
}

/* Returns the "external_ids" column's value from the "Chassis" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "external_ids" member in sbrec_chassis. */
const struct ovsdb_datum *
sbrec_chassis_get_external_ids(const struct sbrec_chassis *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_chassis_col_external_ids);
}

/* Returns the "hostname" column's value from the "Chassis" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes hostname's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "hostname" member in sbrec_chassis. */
const struct ovsdb_datum *
sbrec_chassis_get_hostname(const struct sbrec_chassis *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_chassis_col_hostname);
}

/* Returns the "name" column's value from the "Chassis" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes name's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "name" member in sbrec_chassis. */
const struct ovsdb_datum *
sbrec_chassis_get_name(const struct sbrec_chassis *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_chassis_col_name);
}

/* Returns the "nb_cfg" column's value from the "Chassis" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes nb_cfg's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "nb_cfg" member in sbrec_chassis. */
const struct ovsdb_datum *
sbrec_chassis_get_nb_cfg(const struct sbrec_chassis *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &sbrec_chassis_col_nb_cfg);
}

/* Returns the "vtep_logical_switches" column's value from the "Chassis" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes vtep_logical_switches's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "vtep_logical_switches" member in sbrec_chassis. */
const struct ovsdb_datum *
sbrec_chassis_get_vtep_logical_switches(const struct sbrec_chassis *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_chassis_col_vtep_logical_switches);
}

/* Sets the "encaps" column from the "Chassis" table in 'row' to
 * the 'encaps' set with 'n_encaps' entries.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_chassis_set_encaps(const struct sbrec_chassis *row, struct sbrec_encap **encaps, size_t n_encaps)
{
    struct ovsdb_datum datum;

    datum.n = n_encaps;
    datum.keys = n_encaps ? xmalloc(n_encaps * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (size_t i = 0; i < n_encaps; i++) {
        datum.keys[i].uuid = encaps[i]->header_.uuid;
    }
    ovsdb_idl_txn_write(&row->header_, &sbrec_chassis_col_encaps, &datum);
}

/* Sets the "external_ids" column's value from the "Chassis" table in 'row'
 * to 'external_ids'.
 *
 * The caller retains ownership of 'external_ids' and everything in it. */
void
sbrec_chassis_set_external_ids(const struct sbrec_chassis *row, const struct smap *external_ids)
{
    struct ovsdb_datum datum;

    if (external_ids) {
        ovsdb_datum_from_smap(&datum, external_ids);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &sbrec_chassis_col_external_ids,
                        &datum);
}


/* Sets the "hostname" column from the "Chassis" table in 'row' to
 * 'hostname'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_chassis_set_hostname(const struct sbrec_chassis *row, const char *hostname)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, hostname);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_chassis_col_hostname, &datum);
}

/* Sets the "name" column from the "Chassis" table in 'row' to
 * 'name'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_chassis_set_name(const struct sbrec_chassis *row, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_chassis_col_name, &datum);
}

/* Sets the "nb_cfg" column from the "Chassis" table in 'row' to
 * 'nb_cfg'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_chassis_set_nb_cfg(const struct sbrec_chassis *row, int64_t nb_cfg)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = nb_cfg;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_chassis_col_nb_cfg, &datum);
}

/* Sets the "vtep_logical_switches" column from the "Chassis" table in 'row' to
 * the 'vtep_logical_switches' set with 'n_vtep_logical_switches' entries.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_chassis_set_vtep_logical_switches(const struct sbrec_chassis *row, const char **vtep_logical_switches, size_t n_vtep_logical_switches)
{
    struct ovsdb_datum datum;

    datum.n = n_vtep_logical_switches;
    datum.keys = n_vtep_logical_switches ? xmalloc(n_vtep_logical_switches * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (size_t i = 0; i < n_vtep_logical_switches; i++) {
        datum.keys[i].string = xstrdup(vtep_logical_switches[i]);
    }
    ovsdb_idl_txn_write(&row->header_, &sbrec_chassis_col_vtep_logical_switches, &datum);
}

/* Adds the value 'new_value' to the "encaps" set column from the "Chassis" table
 * in 'row'.
 *
 */
void
sbrec_chassis_update_encaps_addvalue(const struct sbrec_chassis *row, const struct sbrec_encap *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].uuid = new_value->header_.uuid;

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &sbrec_chassis_col_encaps,
                                    datum);
}

/* Deletes the value 'delete_value' from the "encaps" set column from the
 * "Chassis" table in 'row'.
 *
 */
void
sbrec_chassis_update_encaps_delvalue(const struct sbrec_chassis *row, const struct sbrec_encap *delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].uuid = delete_value->header_.uuid;

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &sbrec_chassis_col_encaps,
                                    datum);
}

/* Sets an element of the "external_ids" map column from the "Chassis" table in 'row'
 * to 'new_value' given the key value 'new_key'.
 *
 */
void
sbrec_chassis_update_external_ids_setkey(const struct sbrec_chassis *row, const char *new_key, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = xmalloc(datum->n * sizeof *datum->values);

    datum->keys[0].string = xstrdup(new_key);
    datum->values[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_map(&row->header_,
                                    &sbrec_chassis_col_external_ids,
                                    datum);
}

/* Deletes an element of the "external_ids" map column from the "Chassis" table in 'row'
 * given the key value 'delete_key'.
 *
 */
void
sbrec_chassis_update_external_ids_delkey(const struct sbrec_chassis *row, const char *delete_key)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_key);

    ovsdb_idl_txn_delete_partial_map(&row->header_,
                                    &sbrec_chassis_col_external_ids,
                                    datum);
}

/* Adds the value 'new_value' to the "vtep_logical_switches" set column from the "Chassis" table
 * in 'row'.
 *
 */
void
sbrec_chassis_update_vtep_logical_switches_addvalue(const struct sbrec_chassis *row, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &sbrec_chassis_col_vtep_logical_switches,
                                    datum);
}

/* Deletes the value 'delete_value' from the "vtep_logical_switches" set column from the
 * "Chassis" table in 'row'.
 *
 */
void
sbrec_chassis_update_vtep_logical_switches_delvalue(const struct sbrec_chassis *row, const char *delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_value);

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &sbrec_chassis_col_vtep_logical_switches,
                                    datum);
}

/* Sets the "encaps" column from the "Chassis" table in 'row' to
 * the 'encaps' set with 'n_encaps' entries.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_chassis_add_clause_encaps(struct ovsdb_idl_condition *cond, enum ovsdb_function function, struct uuid **encaps, size_t n_encaps)
{
    struct ovsdb_datum datum;
    datum.n = n_encaps;
    datum.keys = n_encaps ? xmalloc(n_encaps * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (size_t i = 0; i < n_encaps; i++) {
        datum.keys[i].uuid = *encaps[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_chassis_col_encaps,
                          &datum);
    free(datum.keys);
}

/* Sets the "external_ids" column's value from the "Chassis" table in 'row'
 * to 'external_ids'.
 *
 * The caller retains ownership of 'external_ids' and everything in it. */
void
sbrec_chassis_add_clause_external_ids(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct smap *external_ids)
{
    struct ovsdb_datum datum;

    if (external_ids) {
        ovsdb_datum_from_smap(&datum, external_ids);
    } else {
        ovsdb_datum_init_empty(&datum);
    }

    ovsdb_idl_condition_add_clause(cond,
                                   function,
                                   &sbrec_chassis_col_external_ids,
                                   &datum);

    ovsdb_datum_destroy(&datum, &sbrec_chassis_col_external_ids.type);
}


/* Sets the "hostname" column from the "Chassis" table in 'row' to
 * 'hostname'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_chassis_add_clause_hostname(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *hostname)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, hostname);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_chassis_col_hostname,
                          &datum);
}

/* Sets the "name" column from the "Chassis" table in 'row' to
 * 'name'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_chassis_add_clause_name(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_chassis_col_name,
                          &datum);
}

/* Sets the "nb_cfg" column from the "Chassis" table in 'row' to
 * 'nb_cfg'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_chassis_add_clause_nb_cfg(struct ovsdb_idl_condition *cond, enum ovsdb_function function, int64_t nb_cfg)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = nb_cfg;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_chassis_col_nb_cfg,
                          &datum);
}

/* Sets the "vtep_logical_switches" column from the "Chassis" table in 'row' to
 * the 'vtep_logical_switches' set with 'n_vtep_logical_switches' entries.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_chassis_add_clause_vtep_logical_switches(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char **vtep_logical_switches, size_t n_vtep_logical_switches)
{
    struct ovsdb_datum datum;
    datum.n = n_vtep_logical_switches;
    datum.keys = n_vtep_logical_switches ? xmalloc(n_vtep_logical_switches * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (size_t i = 0; i < n_vtep_logical_switches; i++) {
        datum.keys[i].string = CONST_CAST(char *, vtep_logical_switches[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_VOID);
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_chassis_col_vtep_logical_switches,
                          &datum);
    free(datum.keys);
}

void
sbrec_chassis_set_condition(struct ovsdb_idl *idl, struct ovsdb_idl_condition *condition)
{
    ovsdb_idl_set_condition(idl, &sbrec_table_chassis, condition);
}

struct ovsdb_idl_column sbrec_chassis_columns[SBREC_CHASSIS_N_COLUMNS] = {
    [SBREC_CHASSIS_COL_ENCAPS] = {
         .name = "encaps",
         .type = {
            .key = {
               .type = OVSDB_TYPE_UUID,
               .u.uuid = { .refTableName = "Encap", .refType = OVSDB_REF_STRONG },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_chassis_parse_encaps,
         .unparse = sbrec_chassis_unparse_encaps,
    },

    [SBREC_CHASSIS_COL_EXTERNAL_IDS] = {
         .name = "external_ids",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = {
                .type = OVSDB_TYPE_STRING,
                .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .n_min = 0,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_chassis_parse_external_ids,
         .unparse = sbrec_chassis_unparse_external_ids,
    },

    [SBREC_CHASSIS_COL_HOSTNAME] = {
         .name = "hostname",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_chassis_parse_hostname,
         .unparse = sbrec_chassis_unparse_hostname,
    },

    [SBREC_CHASSIS_COL_NAME] = {
         .name = "name",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_chassis_parse_name,
         .unparse = sbrec_chassis_unparse_name,
    },

    [SBREC_CHASSIS_COL_NB_CFG] = {
         .name = "nb_cfg",
         .type = {
            .key = {
               .type = OVSDB_TYPE_INTEGER,
               .u.integer = { .min = INT64_MIN, .max = INT64_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_chassis_parse_nb_cfg,
         .unparse = sbrec_chassis_unparse_nb_cfg,
    },

    [SBREC_CHASSIS_COL_VTEP_LOGICAL_SWITCHES] = {
         .name = "vtep_logical_switches",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 0,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_chassis_parse_vtep_logical_switches,
         .unparse = sbrec_chassis_unparse_vtep_logical_switches,
    },

};

/* Connection table. */

static void
sbrec_connection_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_connection *row = sbrec_connection_cast(row_);
    smap_init(&row->external_ids);
    for (size_t i = 0; i < datum->n; i++) {
        smap_add(&row->external_ids,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
sbrec_connection_parse_inactivity_probe(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_connection *row = sbrec_connection_cast(row_);
    size_t n = MIN(1, datum->n);
    row->inactivity_probe = NULL;
    row->n_inactivity_probe = 0;
    for (size_t i = 0; i < n; i++) {
        if (!row->n_inactivity_probe) {
            row->inactivity_probe = xmalloc(n * sizeof *row->inactivity_probe);
        }
        row->inactivity_probe[row->n_inactivity_probe] = datum->keys[i].integer;
        row->n_inactivity_probe++;
    }
}

static void
sbrec_connection_parse_is_connected(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_connection *row = sbrec_connection_cast(row_);

    if (datum->n >= 1) {
        row->is_connected = datum->keys[0].boolean;
    } else {
        row->is_connected = false;
    }
}

static void
sbrec_connection_parse_max_backoff(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_connection *row = sbrec_connection_cast(row_);
    size_t n = MIN(1, datum->n);
    row->max_backoff = NULL;
    row->n_max_backoff = 0;
    for (size_t i = 0; i < n; i++) {
        if (!row->n_max_backoff) {
            row->max_backoff = xmalloc(n * sizeof *row->max_backoff);
        }
        row->max_backoff[row->n_max_backoff] = datum->keys[i].integer;
        row->n_max_backoff++;
    }
}

static void
sbrec_connection_parse_other_config(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_connection *row = sbrec_connection_cast(row_);
    smap_init(&row->other_config);
    for (size_t i = 0; i < datum->n; i++) {
        smap_add(&row->other_config,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
sbrec_connection_parse_read_only(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_connection *row = sbrec_connection_cast(row_);

    if (datum->n >= 1) {
        row->read_only = datum->keys[0].boolean;
    } else {
        row->read_only = false;
    }
}

static void
sbrec_connection_parse_status(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_connection *row = sbrec_connection_cast(row_);
    smap_init(&row->status);
    for (size_t i = 0; i < datum->n; i++) {
        smap_add(&row->status,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
sbrec_connection_parse_target(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_connection *row = sbrec_connection_cast(row_);

    if (datum->n >= 1) {
        row->target = datum->keys[0].string;
    } else {
        row->target = "";
    }
}

static void
sbrec_connection_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct sbrec_connection *row = sbrec_connection_cast(row_);
    smap_destroy(&row->external_ids);
}

static void
sbrec_connection_unparse_inactivity_probe(struct ovsdb_idl_row *row_)
{
    struct sbrec_connection *row = sbrec_connection_cast(row_);
    free(row->inactivity_probe);
}

static void
sbrec_connection_unparse_is_connected(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_connection_unparse_max_backoff(struct ovsdb_idl_row *row_)
{
    struct sbrec_connection *row = sbrec_connection_cast(row_);
    free(row->max_backoff);
}

static void
sbrec_connection_unparse_other_config(struct ovsdb_idl_row *row_)
{
    struct sbrec_connection *row = sbrec_connection_cast(row_);
    smap_destroy(&row->other_config);
}

static void
sbrec_connection_unparse_read_only(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_connection_unparse_status(struct ovsdb_idl_row *row_)
{
    struct sbrec_connection *row = sbrec_connection_cast(row_);
    smap_destroy(&row->status);
}

static void
sbrec_connection_unparse_target(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_connection_init__(struct ovsdb_idl_row *row)
{
    sbrec_connection_init(sbrec_connection_cast(row));
}

/* Clears the contents of 'row' in table "Connection". */
void
sbrec_connection_init(struct sbrec_connection *row)
{
    memset(row, 0, sizeof *row); 
    smap_init(&row->external_ids);
    smap_init(&row->other_config);
    smap_init(&row->status);
    row->target = "";
}

/* Searches table "Connection" in 'idl' for a row with UUID 'uuid'.  Returns
 * a pointer to the row if there is one, otherwise a null pointer.  */
const struct sbrec_connection *
sbrec_connection_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return sbrec_connection_cast(ovsdb_idl_get_row_for_uuid(idl, &sbrec_table_connection, uuid));
}

/* Returns a row in table "Connection" in 'idl', or a null pointer if that
 * table is empty.
 *
 * Database tables are internally maintained as hash tables, so adding or
 * removing rows while traversing the same table can cause some rows to be
 * visited twice or not at apply. */
const struct sbrec_connection *
sbrec_connection_first(const struct ovsdb_idl *idl)
{
    return sbrec_connection_cast(ovsdb_idl_first_row(idl, &sbrec_table_connection));
}

/* Returns a row following 'row' within its table, or a null pointer if 'row'
 * is the last row in its table. */
const struct sbrec_connection *
sbrec_connection_next(const struct sbrec_connection *row)
{
    return sbrec_connection_cast(ovsdb_idl_next_row(&row->header_));
}

unsigned int sbrec_connection_get_seqno(const struct ovsdb_idl *idl)
{
    return ovsdb_idl_table_get_seqno(idl, &sbrec_table_connection);
}

unsigned int sbrec_connection_row_get_seqno(const struct sbrec_connection *row, enum ovsdb_idl_change change)
{
    return ovsdb_idl_row_get_seqno(&row->header_, change);
}

const struct sbrec_connection *
sbrec_connection_track_get_first(const struct ovsdb_idl *idl)
{
    return sbrec_connection_cast(ovsdb_idl_track_get_first(idl, &sbrec_table_connection));
}

const struct sbrec_connection
*sbrec_connection_track_get_next(const struct sbrec_connection *row)
{
    return sbrec_connection_cast(ovsdb_idl_track_get_next(&row->header_));
}


/* Deletes 'row' from table "Connection".  'row' may be freed, so it must not be
 * accessed afterward.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_connection_delete(const struct sbrec_connection *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

/* Inserts and returns a new row in the table "Connection" in the database
 * with open transaction 'txn'.
 *
 * The new row is assigned a randomly generated provisional UUID.
 * ovsdb-server will assign a different UUID when 'txn' is committed,
 * but the IDL will replace any uses of the provisional UUID in the
 * data to be to be committed by the UUID assigned by ovsdb-server. */
struct sbrec_connection *
sbrec_connection_insert(struct ovsdb_idl_txn *txn)
{
    return sbrec_connection_cast(ovsdb_idl_txn_insert(txn, &sbrec_table_connection, NULL));
}

bool
sbrec_connection_is_updated(const struct sbrec_connection *row, enum sbrec_connection_column_id column)
{
    return ovsdb_idl_track_is_updated(&row->header_, &sbrec_connection_columns[column]);
}

/* Causes the original contents of column "external_ids" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "external_ids" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "external_ids" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "external_ids" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_connection_insert()).
 *
 *   - If "external_ids" has already been modified (with
 *     sbrec_connection_set_external_ids()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_connection_set_external_ids() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_connection_verify_external_ids(const struct sbrec_connection *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_connection_col_external_ids);
}

/* Causes the original contents of column "inactivity_probe" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "inactivity_probe" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "inactivity_probe" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "inactivity_probe" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_connection_insert()).
 *
 *   - If "inactivity_probe" has already been modified (with
 *     sbrec_connection_set_inactivity_probe()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_connection_set_inactivity_probe() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_connection_verify_inactivity_probe(const struct sbrec_connection *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_connection_col_inactivity_probe);
}

/* Causes the original contents of column "is_connected" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "is_connected" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "is_connected" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "is_connected" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_connection_insert()).
 *
 *   - If "is_connected" has already been modified (with
 *     sbrec_connection_set_is_connected()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_connection_set_is_connected() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_connection_verify_is_connected(const struct sbrec_connection *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_connection_col_is_connected);
}

/* Causes the original contents of column "max_backoff" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "max_backoff" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "max_backoff" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "max_backoff" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_connection_insert()).
 *
 *   - If "max_backoff" has already been modified (with
 *     sbrec_connection_set_max_backoff()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_connection_set_max_backoff() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_connection_verify_max_backoff(const struct sbrec_connection *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_connection_col_max_backoff);
}

/* Causes the original contents of column "other_config" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "other_config" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "other_config" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "other_config" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_connection_insert()).
 *
 *   - If "other_config" has already been modified (with
 *     sbrec_connection_set_other_config()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_connection_set_other_config() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_connection_verify_other_config(const struct sbrec_connection *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_connection_col_other_config);
}

/* Causes the original contents of column "read_only" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "read_only" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "read_only" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "read_only" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_connection_insert()).
 *
 *   - If "read_only" has already been modified (with
 *     sbrec_connection_set_read_only()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_connection_set_read_only() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_connection_verify_read_only(const struct sbrec_connection *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_connection_col_read_only);
}

/* Causes the original contents of column "status" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "status" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "status" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "status" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_connection_insert()).
 *
 *   - If "status" has already been modified (with
 *     sbrec_connection_set_status()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_connection_set_status() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_connection_verify_status(const struct sbrec_connection *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_connection_col_status);
}

/* Causes the original contents of column "target" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "target" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "target" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "target" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_connection_insert()).
 *
 *   - If "target" has already been modified (with
 *     sbrec_connection_set_target()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_connection_set_target() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_connection_verify_target(const struct sbrec_connection *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_connection_col_target);
}

/* Returns the "external_ids" column's value from the "Connection" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "external_ids" member in sbrec_connection. */
const struct ovsdb_datum *
sbrec_connection_get_external_ids(const struct sbrec_connection *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_connection_col_external_ids);
}

/* Returns the "inactivity_probe" column's value from the "Connection" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes inactivity_probe's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "inactivity_probe" member in sbrec_connection. */
const struct ovsdb_datum *
sbrec_connection_get_inactivity_probe(const struct sbrec_connection *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &sbrec_connection_col_inactivity_probe);
}

/* Returns the "is_connected" column's value from the "Connection" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes is_connected's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "is_connected" member in sbrec_connection. */
const struct ovsdb_datum *
sbrec_connection_get_is_connected(const struct sbrec_connection *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &sbrec_connection_col_is_connected);
}

/* Returns the "max_backoff" column's value from the "Connection" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes max_backoff's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "max_backoff" member in sbrec_connection. */
const struct ovsdb_datum *
sbrec_connection_get_max_backoff(const struct sbrec_connection *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &sbrec_connection_col_max_backoff);
}

/* Returns the "other_config" column's value from the "Connection" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes other_config's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "other_config" member in sbrec_connection. */
const struct ovsdb_datum *
sbrec_connection_get_other_config(const struct sbrec_connection *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_connection_col_other_config);
}

/* Returns the "read_only" column's value from the "Connection" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes read_only's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "read_only" member in sbrec_connection. */
const struct ovsdb_datum *
sbrec_connection_get_read_only(const struct sbrec_connection *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &sbrec_connection_col_read_only);
}

/* Returns the "status" column's value from the "Connection" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes status's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "status" member in sbrec_connection. */
const struct ovsdb_datum *
sbrec_connection_get_status(const struct sbrec_connection *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_connection_col_status);
}

/* Returns the "target" column's value from the "Connection" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes target's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "target" member in sbrec_connection. */
const struct ovsdb_datum *
sbrec_connection_get_target(const struct sbrec_connection *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_connection_col_target);
}

/* Sets the "external_ids" column's value from the "Connection" table in 'row'
 * to 'external_ids'.
 *
 * The caller retains ownership of 'external_ids' and everything in it. */
void
sbrec_connection_set_external_ids(const struct sbrec_connection *row, const struct smap *external_ids)
{
    struct ovsdb_datum datum;

    if (external_ids) {
        ovsdb_datum_from_smap(&datum, external_ids);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &sbrec_connection_col_external_ids,
                        &datum);
}


/* Sets the "inactivity_probe" column from the "Connection" table in 'row' to
 * the 'inactivity_probe' set with 'n_inactivity_probe' entries.
 *
 * 'n_inactivity_probe' may be 0 or 1; if it is 0, then 'inactivity_probe'
 * may be NULL.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_connection_set_inactivity_probe(const struct sbrec_connection *row, const int64_t *inactivity_probe, size_t n_inactivity_probe)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (n_inactivity_probe) {
        datum.n = 1;
        datum.keys = &key;
        key.integer = *inactivity_probe;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_connection_col_inactivity_probe, &datum);
}

/* Sets the "is_connected" column from the "Connection" table in 'row' to
 * 'is_connected'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_connection_set_is_connected(const struct sbrec_connection *row, bool is_connected)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.boolean = is_connected;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_connection_col_is_connected, &datum);
}

/* Sets the "max_backoff" column from the "Connection" table in 'row' to
 * the 'max_backoff' set with 'n_max_backoff' entries.
 *
 * 'n_max_backoff' may be 0 or 1; if it is 0, then 'max_backoff'
 * may be NULL.
 *
 * Argument constraints: at least 1,000
 *
 * The caller retains ownership of the arguments. */
void
sbrec_connection_set_max_backoff(const struct sbrec_connection *row, const int64_t *max_backoff, size_t n_max_backoff)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (n_max_backoff) {
        datum.n = 1;
        datum.keys = &key;
        key.integer = *max_backoff;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_connection_col_max_backoff, &datum);
}

/* Sets the "other_config" column's value from the "Connection" table in 'row'
 * to 'other_config'.
 *
 * The caller retains ownership of 'other_config' and everything in it. */
void
sbrec_connection_set_other_config(const struct sbrec_connection *row, const struct smap *other_config)
{
    struct ovsdb_datum datum;

    if (other_config) {
        ovsdb_datum_from_smap(&datum, other_config);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &sbrec_connection_col_other_config,
                        &datum);
}


/* Sets the "read_only" column from the "Connection" table in 'row' to
 * 'read_only'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_connection_set_read_only(const struct sbrec_connection *row, bool read_only)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.boolean = read_only;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_connection_col_read_only, &datum);
}

/* Sets the "status" column's value from the "Connection" table in 'row'
 * to 'status'.
 *
 * The caller retains ownership of 'status' and everything in it. */
void
sbrec_connection_set_status(const struct sbrec_connection *row, const struct smap *status)
{
    struct ovsdb_datum datum;

    if (status) {
        ovsdb_datum_from_smap(&datum, status);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &sbrec_connection_col_status,
                        &datum);
}


/* Sets the "target" column from the "Connection" table in 'row' to
 * 'target'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_connection_set_target(const struct sbrec_connection *row, const char *target)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, target);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_connection_col_target, &datum);
}

/* Sets an element of the "external_ids" map column from the "Connection" table in 'row'
 * to 'new_value' given the key value 'new_key'.
 *
 */
void
sbrec_connection_update_external_ids_setkey(const struct sbrec_connection *row, const char *new_key, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = xmalloc(datum->n * sizeof *datum->values);

    datum->keys[0].string = xstrdup(new_key);
    datum->values[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_map(&row->header_,
                                    &sbrec_connection_col_external_ids,
                                    datum);
}

/* Deletes an element of the "external_ids" map column from the "Connection" table in 'row'
 * given the key value 'delete_key'.
 *
 */
void
sbrec_connection_update_external_ids_delkey(const struct sbrec_connection *row, const char *delete_key)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_key);

    ovsdb_idl_txn_delete_partial_map(&row->header_,
                                    &sbrec_connection_col_external_ids,
                                    datum);
}

/* Adds the value 'new_value' to the "inactivity_probe" set column from the "Connection" table
 * in 'row'.
 *
 */
void
sbrec_connection_update_inactivity_probe_addvalue(const struct sbrec_connection *row, int64_t new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].integer = new_value;

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &sbrec_connection_col_inactivity_probe,
                                    datum);
}

/* Deletes the value 'delete_value' from the "inactivity_probe" set column from the
 * "Connection" table in 'row'.
 *
 */
void
sbrec_connection_update_inactivity_probe_delvalue(const struct sbrec_connection *row, int64_t delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].integer = delete_value;

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &sbrec_connection_col_inactivity_probe,
                                    datum);
}

/* Adds the value 'new_value' to the "max_backoff" set column from the "Connection" table
 * in 'row'.
 *
 */
void
sbrec_connection_update_max_backoff_addvalue(const struct sbrec_connection *row, int64_t new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].integer = new_value;

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &sbrec_connection_col_max_backoff,
                                    datum);
}

/* Deletes the value 'delete_value' from the "max_backoff" set column from the
 * "Connection" table in 'row'.
 *
 */
void
sbrec_connection_update_max_backoff_delvalue(const struct sbrec_connection *row, int64_t delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].integer = delete_value;

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &sbrec_connection_col_max_backoff,
                                    datum);
}

/* Sets an element of the "other_config" map column from the "Connection" table in 'row'
 * to 'new_value' given the key value 'new_key'.
 *
 */
void
sbrec_connection_update_other_config_setkey(const struct sbrec_connection *row, const char *new_key, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = xmalloc(datum->n * sizeof *datum->values);

    datum->keys[0].string = xstrdup(new_key);
    datum->values[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_map(&row->header_,
                                    &sbrec_connection_col_other_config,
                                    datum);
}

/* Deletes an element of the "other_config" map column from the "Connection" table in 'row'
 * given the key value 'delete_key'.
 *
 */
void
sbrec_connection_update_other_config_delkey(const struct sbrec_connection *row, const char *delete_key)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_key);

    ovsdb_idl_txn_delete_partial_map(&row->header_,
                                    &sbrec_connection_col_other_config,
                                    datum);
}

/* Sets an element of the "status" map column from the "Connection" table in 'row'
 * to 'new_value' given the key value 'new_key'.
 *
 */
void
sbrec_connection_update_status_setkey(const struct sbrec_connection *row, const char *new_key, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = xmalloc(datum->n * sizeof *datum->values);

    datum->keys[0].string = xstrdup(new_key);
    datum->values[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_map(&row->header_,
                                    &sbrec_connection_col_status,
                                    datum);
}

/* Deletes an element of the "status" map column from the "Connection" table in 'row'
 * given the key value 'delete_key'.
 *
 */
void
sbrec_connection_update_status_delkey(const struct sbrec_connection *row, const char *delete_key)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_key);

    ovsdb_idl_txn_delete_partial_map(&row->header_,
                                    &sbrec_connection_col_status,
                                    datum);
}

/* Sets the "external_ids" column's value from the "Connection" table in 'row'
 * to 'external_ids'.
 *
 * The caller retains ownership of 'external_ids' and everything in it. */
void
sbrec_connection_add_clause_external_ids(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct smap *external_ids)
{
    struct ovsdb_datum datum;

    if (external_ids) {
        ovsdb_datum_from_smap(&datum, external_ids);
    } else {
        ovsdb_datum_init_empty(&datum);
    }

    ovsdb_idl_condition_add_clause(cond,
                                   function,
                                   &sbrec_connection_col_external_ids,
                                   &datum);

    ovsdb_datum_destroy(&datum, &sbrec_connection_col_external_ids.type);
}


/* Sets the "inactivity_probe" column from the "Connection" table in 'row' to
 * the 'inactivity_probe' set with 'n_inactivity_probe' entries.
 *
 * 'n_inactivity_probe' may be 0 or 1; if it is 0, then 'inactivity_probe'
 * may be NULL.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_connection_add_clause_inactivity_probe(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const int64_t *inactivity_probe, size_t n_inactivity_probe)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (n_inactivity_probe) {
        datum.n = 1;
        datum.keys = &key;
        key.integer = *inactivity_probe;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_connection_col_inactivity_probe,
                          &datum);
}

/* Sets the "is_connected" column from the "Connection" table in 'row' to
 * 'is_connected'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_connection_add_clause_is_connected(struct ovsdb_idl_condition *cond, enum ovsdb_function function, bool is_connected)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.boolean = is_connected;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_connection_col_is_connected,
                          &datum);
}

/* Sets the "max_backoff" column from the "Connection" table in 'row' to
 * the 'max_backoff' set with 'n_max_backoff' entries.
 *
 * 'n_max_backoff' may be 0 or 1; if it is 0, then 'max_backoff'
 * may be NULL.
 *
 * Argument constraints: at least 1,000
 *
 * The caller retains ownership of the arguments. */
void
sbrec_connection_add_clause_max_backoff(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const int64_t *max_backoff, size_t n_max_backoff)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (n_max_backoff) {
        datum.n = 1;
        datum.keys = &key;
        key.integer = *max_backoff;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_connection_col_max_backoff,
                          &datum);
}

/* Sets the "other_config" column's value from the "Connection" table in 'row'
 * to 'other_config'.
 *
 * The caller retains ownership of 'other_config' and everything in it. */
void
sbrec_connection_add_clause_other_config(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct smap *other_config)
{
    struct ovsdb_datum datum;

    if (other_config) {
        ovsdb_datum_from_smap(&datum, other_config);
    } else {
        ovsdb_datum_init_empty(&datum);
    }

    ovsdb_idl_condition_add_clause(cond,
                                   function,
                                   &sbrec_connection_col_other_config,
                                   &datum);

    ovsdb_datum_destroy(&datum, &sbrec_connection_col_other_config.type);
}


/* Sets the "read_only" column from the "Connection" table in 'row' to
 * 'read_only'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_connection_add_clause_read_only(struct ovsdb_idl_condition *cond, enum ovsdb_function function, bool read_only)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.boolean = read_only;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_connection_col_read_only,
                          &datum);
}

/* Sets the "status" column's value from the "Connection" table in 'row'
 * to 'status'.
 *
 * The caller retains ownership of 'status' and everything in it. */
void
sbrec_connection_add_clause_status(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct smap *status)
{
    struct ovsdb_datum datum;

    if (status) {
        ovsdb_datum_from_smap(&datum, status);
    } else {
        ovsdb_datum_init_empty(&datum);
    }

    ovsdb_idl_condition_add_clause(cond,
                                   function,
                                   &sbrec_connection_col_status,
                                   &datum);

    ovsdb_datum_destroy(&datum, &sbrec_connection_col_status.type);
}


/* Sets the "target" column from the "Connection" table in 'row' to
 * 'target'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_connection_add_clause_target(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *target)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, target);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_connection_col_target,
                          &datum);
}

void
sbrec_connection_set_condition(struct ovsdb_idl *idl, struct ovsdb_idl_condition *condition)
{
    ovsdb_idl_set_condition(idl, &sbrec_table_connection, condition);
}

struct ovsdb_idl_column sbrec_connection_columns[SBREC_CONNECTION_N_COLUMNS] = {
    [SBREC_CONNECTION_COL_EXTERNAL_IDS] = {
         .name = "external_ids",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = {
                .type = OVSDB_TYPE_STRING,
                .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .n_min = 0,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_connection_parse_external_ids,
         .unparse = sbrec_connection_unparse_external_ids,
    },

    [SBREC_CONNECTION_COL_INACTIVITY_PROBE] = {
         .name = "inactivity_probe",
         .type = {
            .key = {
               .type = OVSDB_TYPE_INTEGER,
               .u.integer = { .min = INT64_MIN, .max = INT64_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 0,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_connection_parse_inactivity_probe,
         .unparse = sbrec_connection_unparse_inactivity_probe,
    },

    [SBREC_CONNECTION_COL_IS_CONNECTED] = {
         .name = "is_connected",
         .type = {
            .key = {
               .type = OVSDB_TYPE_BOOLEAN,
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_connection_parse_is_connected,
         .unparse = sbrec_connection_unparse_is_connected,
    },

    [SBREC_CONNECTION_COL_MAX_BACKOFF] = {
         .name = "max_backoff",
         .type = {
            .key = {
               .type = OVSDB_TYPE_INTEGER,
               .u.integer = { .min = INT64_C(1000), .max = INT64_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 0,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_connection_parse_max_backoff,
         .unparse = sbrec_connection_unparse_max_backoff,
    },

    [SBREC_CONNECTION_COL_OTHER_CONFIG] = {
         .name = "other_config",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = {
                .type = OVSDB_TYPE_STRING,
                .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .n_min = 0,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_connection_parse_other_config,
         .unparse = sbrec_connection_unparse_other_config,
    },

    [SBREC_CONNECTION_COL_READ_ONLY] = {
         .name = "read_only",
         .type = {
            .key = {
               .type = OVSDB_TYPE_BOOLEAN,
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_connection_parse_read_only,
         .unparse = sbrec_connection_unparse_read_only,
    },

    [SBREC_CONNECTION_COL_STATUS] = {
         .name = "status",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = {
                .type = OVSDB_TYPE_STRING,
                .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .n_min = 0,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_connection_parse_status,
         .unparse = sbrec_connection_unparse_status,
    },

    [SBREC_CONNECTION_COL_TARGET] = {
         .name = "target",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_connection_parse_target,
         .unparse = sbrec_connection_unparse_target,
    },

};

/* DHCP_Options table. */

static void
sbrec_dhcp_options_parse_code(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_dhcp_options *row = sbrec_dhcp_options_cast(row_);

    if (datum->n >= 1) {
        row->code = datum->keys[0].integer;
    } else {
        row->code = 0;
    }
}

static void
sbrec_dhcp_options_parse_name(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_dhcp_options *row = sbrec_dhcp_options_cast(row_);

    if (datum->n >= 1) {
        row->name = datum->keys[0].string;
    } else {
        row->name = "";
    }
}

static void
sbrec_dhcp_options_parse_type(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_dhcp_options *row = sbrec_dhcp_options_cast(row_);

    if (datum->n >= 1) {
        row->type = datum->keys[0].string;
    } else {
        row->type = "";
    }
}

static void
sbrec_dhcp_options_unparse_code(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_dhcp_options_unparse_name(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_dhcp_options_unparse_type(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_dhcp_options_init__(struct ovsdb_idl_row *row)
{
    sbrec_dhcp_options_init(sbrec_dhcp_options_cast(row));
}

/* Clears the contents of 'row' in table "DHCP_Options". */
void
sbrec_dhcp_options_init(struct sbrec_dhcp_options *row)
{
    memset(row, 0, sizeof *row); 
    row->name = "";
    row->type = "";
}

/* Searches table "DHCP_Options" in 'idl' for a row with UUID 'uuid'.  Returns
 * a pointer to the row if there is one, otherwise a null pointer.  */
const struct sbrec_dhcp_options *
sbrec_dhcp_options_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return sbrec_dhcp_options_cast(ovsdb_idl_get_row_for_uuid(idl, &sbrec_table_dhcp_options, uuid));
}

/* Returns a row in table "DHCP_Options" in 'idl', or a null pointer if that
 * table is empty.
 *
 * Database tables are internally maintained as hash tables, so adding or
 * removing rows while traversing the same table can cause some rows to be
 * visited twice or not at apply. */
const struct sbrec_dhcp_options *
sbrec_dhcp_options_first(const struct ovsdb_idl *idl)
{
    return sbrec_dhcp_options_cast(ovsdb_idl_first_row(idl, &sbrec_table_dhcp_options));
}

/* Returns a row following 'row' within its table, or a null pointer if 'row'
 * is the last row in its table. */
const struct sbrec_dhcp_options *
sbrec_dhcp_options_next(const struct sbrec_dhcp_options *row)
{
    return sbrec_dhcp_options_cast(ovsdb_idl_next_row(&row->header_));
}

unsigned int sbrec_dhcp_options_get_seqno(const struct ovsdb_idl *idl)
{
    return ovsdb_idl_table_get_seqno(idl, &sbrec_table_dhcp_options);
}

unsigned int sbrec_dhcp_options_row_get_seqno(const struct sbrec_dhcp_options *row, enum ovsdb_idl_change change)
{
    return ovsdb_idl_row_get_seqno(&row->header_, change);
}

const struct sbrec_dhcp_options *
sbrec_dhcp_options_track_get_first(const struct ovsdb_idl *idl)
{
    return sbrec_dhcp_options_cast(ovsdb_idl_track_get_first(idl, &sbrec_table_dhcp_options));
}

const struct sbrec_dhcp_options
*sbrec_dhcp_options_track_get_next(const struct sbrec_dhcp_options *row)
{
    return sbrec_dhcp_options_cast(ovsdb_idl_track_get_next(&row->header_));
}


/* Deletes 'row' from table "DHCP_Options".  'row' may be freed, so it must not be
 * accessed afterward.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_dhcp_options_delete(const struct sbrec_dhcp_options *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

/* Inserts and returns a new row in the table "DHCP_Options" in the database
 * with open transaction 'txn'.
 *
 * The new row is assigned a randomly generated provisional UUID.
 * ovsdb-server will assign a different UUID when 'txn' is committed,
 * but the IDL will replace any uses of the provisional UUID in the
 * data to be to be committed by the UUID assigned by ovsdb-server. */
struct sbrec_dhcp_options *
sbrec_dhcp_options_insert(struct ovsdb_idl_txn *txn)
{
    return sbrec_dhcp_options_cast(ovsdb_idl_txn_insert(txn, &sbrec_table_dhcp_options, NULL));
}

bool
sbrec_dhcp_options_is_updated(const struct sbrec_dhcp_options *row, enum sbrec_dhcp_options_column_id column)
{
    return ovsdb_idl_track_is_updated(&row->header_, &sbrec_dhcp_options_columns[column]);
}

/* Causes the original contents of column "code" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "code" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "code" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "code" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_dhcp_options_insert()).
 *
 *   - If "code" has already been modified (with
 *     sbrec_dhcp_options_set_code()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_dhcp_options_set_code() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_dhcp_options_verify_code(const struct sbrec_dhcp_options *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_dhcp_options_col_code);
}

/* Causes the original contents of column "name" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "name" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "name" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "name" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_dhcp_options_insert()).
 *
 *   - If "name" has already been modified (with
 *     sbrec_dhcp_options_set_name()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_dhcp_options_set_name() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_dhcp_options_verify_name(const struct sbrec_dhcp_options *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_dhcp_options_col_name);
}

/* Causes the original contents of column "type" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "type" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "type" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "type" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_dhcp_options_insert()).
 *
 *   - If "type" has already been modified (with
 *     sbrec_dhcp_options_set_type()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_dhcp_options_set_type() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_dhcp_options_verify_type(const struct sbrec_dhcp_options *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_dhcp_options_col_type);
}

/* Returns the "code" column's value from the "DHCP_Options" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes code's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "code" member in sbrec_dhcp_options. */
const struct ovsdb_datum *
sbrec_dhcp_options_get_code(const struct sbrec_dhcp_options *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &sbrec_dhcp_options_col_code);
}

/* Returns the "name" column's value from the "DHCP_Options" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes name's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "name" member in sbrec_dhcp_options. */
const struct ovsdb_datum *
sbrec_dhcp_options_get_name(const struct sbrec_dhcp_options *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_dhcp_options_col_name);
}

/* Returns the "type" column's value from the "DHCP_Options" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes type's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "type" member in sbrec_dhcp_options. */
const struct ovsdb_datum *
sbrec_dhcp_options_get_type(const struct sbrec_dhcp_options *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_dhcp_options_col_type);
}

/* Sets the "code" column from the "DHCP_Options" table in 'row' to
 * 'code'.
 *
 * Argument constraints: in range 0 to 254
 *
 * The caller retains ownership of the arguments. */
void
sbrec_dhcp_options_set_code(const struct sbrec_dhcp_options *row, int64_t code)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = code;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_dhcp_options_col_code, &datum);
}

/* Sets the "name" column from the "DHCP_Options" table in 'row' to
 * 'name'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_dhcp_options_set_name(const struct sbrec_dhcp_options *row, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_dhcp_options_col_name, &datum);
}

/* Sets the "type" column from the "DHCP_Options" table in 'row' to
 * 'type'.
 *
 * Argument constraints: one of "static_routes", "uint8", "uint16", "bool", "ipv4", "str", or "uint32"
 *
 * The caller retains ownership of the arguments. */
void
sbrec_dhcp_options_set_type(const struct sbrec_dhcp_options *row, const char *type)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, type);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_dhcp_options_col_type, &datum);
}

/* Sets the "code" column from the "DHCP_Options" table in 'row' to
 * 'code'.
 *
 * Argument constraints: in range 0 to 254
 *
 * The caller retains ownership of the arguments. */
void
sbrec_dhcp_options_add_clause_code(struct ovsdb_idl_condition *cond, enum ovsdb_function function, int64_t code)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = code;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_dhcp_options_col_code,
                          &datum);
}

/* Sets the "name" column from the "DHCP_Options" table in 'row' to
 * 'name'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_dhcp_options_add_clause_name(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_dhcp_options_col_name,
                          &datum);
}

/* Sets the "type" column from the "DHCP_Options" table in 'row' to
 * 'type'.
 *
 * Argument constraints: one of "static_routes", "uint8", "uint16", "bool", "ipv4", "str", or "uint32"
 *
 * The caller retains ownership of the arguments. */
void
sbrec_dhcp_options_add_clause_type(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *type)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, type);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_dhcp_options_col_type,
                          &datum);
}

void
sbrec_dhcp_options_set_condition(struct ovsdb_idl *idl, struct ovsdb_idl_condition *condition)
{
    ovsdb_idl_set_condition(idl, &sbrec_table_dhcp_options, condition);
}
static union ovsdb_atom DHCP_Options_col_type_key_enum_keys[7] = {
    { .string = "bool" },
    { .string = "ipv4" },
    { .string = "static_routes" },
    { .string = "str" },
    { .string = "uint16" },
    { .string = "uint32" },
    { .string = "uint8" },
};
static struct ovsdb_datum DHCP_Options_col_type_key_enum = {
    .n = 7,
    .keys = DHCP_Options_col_type_key_enum_keys,
};

struct ovsdb_idl_column sbrec_dhcp_options_columns[SBREC_DHCP_OPTIONS_N_COLUMNS] = {
    [SBREC_DHCP_OPTIONS_COL_CODE] = {
         .name = "code",
         .type = {
            .key = {
               .type = OVSDB_TYPE_INTEGER,
               .u.integer = { .min = INT64_C(0), .max = INT64_C(254) },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_dhcp_options_parse_code,
         .unparse = sbrec_dhcp_options_unparse_code,
    },

    [SBREC_DHCP_OPTIONS_COL_NAME] = {
         .name = "name",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_dhcp_options_parse_name,
         .unparse = sbrec_dhcp_options_unparse_name,
    },

    [SBREC_DHCP_OPTIONS_COL_TYPE] = {
         .name = "type",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .enum_ = &DHCP_Options_col_type_key_enum,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_dhcp_options_parse_type,
         .unparse = sbrec_dhcp_options_unparse_type,
    },

};

/* DHCPv6_Options table. */

static void
sbrec_dhcpv6_options_parse_code(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_dhcpv6_options *row = sbrec_dhcpv6_options_cast(row_);

    if (datum->n >= 1) {
        row->code = datum->keys[0].integer;
    } else {
        row->code = 0;
    }
}

static void
sbrec_dhcpv6_options_parse_name(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_dhcpv6_options *row = sbrec_dhcpv6_options_cast(row_);

    if (datum->n >= 1) {
        row->name = datum->keys[0].string;
    } else {
        row->name = "";
    }
}

static void
sbrec_dhcpv6_options_parse_type(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_dhcpv6_options *row = sbrec_dhcpv6_options_cast(row_);

    if (datum->n >= 1) {
        row->type = datum->keys[0].string;
    } else {
        row->type = "";
    }
}

static void
sbrec_dhcpv6_options_unparse_code(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_dhcpv6_options_unparse_name(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_dhcpv6_options_unparse_type(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_dhcpv6_options_init__(struct ovsdb_idl_row *row)
{
    sbrec_dhcpv6_options_init(sbrec_dhcpv6_options_cast(row));
}

/* Clears the contents of 'row' in table "DHCPv6_Options". */
void
sbrec_dhcpv6_options_init(struct sbrec_dhcpv6_options *row)
{
    memset(row, 0, sizeof *row); 
    row->name = "";
    row->type = "";
}

/* Searches table "DHCPv6_Options" in 'idl' for a row with UUID 'uuid'.  Returns
 * a pointer to the row if there is one, otherwise a null pointer.  */
const struct sbrec_dhcpv6_options *
sbrec_dhcpv6_options_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return sbrec_dhcpv6_options_cast(ovsdb_idl_get_row_for_uuid(idl, &sbrec_table_dhcpv6_options, uuid));
}

/* Returns a row in table "DHCPv6_Options" in 'idl', or a null pointer if that
 * table is empty.
 *
 * Database tables are internally maintained as hash tables, so adding or
 * removing rows while traversing the same table can cause some rows to be
 * visited twice or not at apply. */
const struct sbrec_dhcpv6_options *
sbrec_dhcpv6_options_first(const struct ovsdb_idl *idl)
{
    return sbrec_dhcpv6_options_cast(ovsdb_idl_first_row(idl, &sbrec_table_dhcpv6_options));
}

/* Returns a row following 'row' within its table, or a null pointer if 'row'
 * is the last row in its table. */
const struct sbrec_dhcpv6_options *
sbrec_dhcpv6_options_next(const struct sbrec_dhcpv6_options *row)
{
    return sbrec_dhcpv6_options_cast(ovsdb_idl_next_row(&row->header_));
}

unsigned int sbrec_dhcpv6_options_get_seqno(const struct ovsdb_idl *idl)
{
    return ovsdb_idl_table_get_seqno(idl, &sbrec_table_dhcpv6_options);
}

unsigned int sbrec_dhcpv6_options_row_get_seqno(const struct sbrec_dhcpv6_options *row, enum ovsdb_idl_change change)
{
    return ovsdb_idl_row_get_seqno(&row->header_, change);
}

const struct sbrec_dhcpv6_options *
sbrec_dhcpv6_options_track_get_first(const struct ovsdb_idl *idl)
{
    return sbrec_dhcpv6_options_cast(ovsdb_idl_track_get_first(idl, &sbrec_table_dhcpv6_options));
}

const struct sbrec_dhcpv6_options
*sbrec_dhcpv6_options_track_get_next(const struct sbrec_dhcpv6_options *row)
{
    return sbrec_dhcpv6_options_cast(ovsdb_idl_track_get_next(&row->header_));
}


/* Deletes 'row' from table "DHCPv6_Options".  'row' may be freed, so it must not be
 * accessed afterward.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_dhcpv6_options_delete(const struct sbrec_dhcpv6_options *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

/* Inserts and returns a new row in the table "DHCPv6_Options" in the database
 * with open transaction 'txn'.
 *
 * The new row is assigned a randomly generated provisional UUID.
 * ovsdb-server will assign a different UUID when 'txn' is committed,
 * but the IDL will replace any uses of the provisional UUID in the
 * data to be to be committed by the UUID assigned by ovsdb-server. */
struct sbrec_dhcpv6_options *
sbrec_dhcpv6_options_insert(struct ovsdb_idl_txn *txn)
{
    return sbrec_dhcpv6_options_cast(ovsdb_idl_txn_insert(txn, &sbrec_table_dhcpv6_options, NULL));
}

bool
sbrec_dhcpv6_options_is_updated(const struct sbrec_dhcpv6_options *row, enum sbrec_dhcpv6_options_column_id column)
{
    return ovsdb_idl_track_is_updated(&row->header_, &sbrec_dhcpv6_options_columns[column]);
}

/* Causes the original contents of column "code" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "code" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "code" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "code" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_dhcpv6_options_insert()).
 *
 *   - If "code" has already been modified (with
 *     sbrec_dhcpv6_options_set_code()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_dhcpv6_options_set_code() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_dhcpv6_options_verify_code(const struct sbrec_dhcpv6_options *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_dhcpv6_options_col_code);
}

/* Causes the original contents of column "name" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "name" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "name" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "name" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_dhcpv6_options_insert()).
 *
 *   - If "name" has already been modified (with
 *     sbrec_dhcpv6_options_set_name()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_dhcpv6_options_set_name() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_dhcpv6_options_verify_name(const struct sbrec_dhcpv6_options *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_dhcpv6_options_col_name);
}

/* Causes the original contents of column "type" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "type" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "type" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "type" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_dhcpv6_options_insert()).
 *
 *   - If "type" has already been modified (with
 *     sbrec_dhcpv6_options_set_type()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_dhcpv6_options_set_type() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_dhcpv6_options_verify_type(const struct sbrec_dhcpv6_options *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_dhcpv6_options_col_type);
}

/* Returns the "code" column's value from the "DHCPv6_Options" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes code's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "code" member in sbrec_dhcpv6_options. */
const struct ovsdb_datum *
sbrec_dhcpv6_options_get_code(const struct sbrec_dhcpv6_options *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &sbrec_dhcpv6_options_col_code);
}

/* Returns the "name" column's value from the "DHCPv6_Options" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes name's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "name" member in sbrec_dhcpv6_options. */
const struct ovsdb_datum *
sbrec_dhcpv6_options_get_name(const struct sbrec_dhcpv6_options *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_dhcpv6_options_col_name);
}

/* Returns the "type" column's value from the "DHCPv6_Options" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes type's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "type" member in sbrec_dhcpv6_options. */
const struct ovsdb_datum *
sbrec_dhcpv6_options_get_type(const struct sbrec_dhcpv6_options *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_dhcpv6_options_col_type);
}

/* Sets the "code" column from the "DHCPv6_Options" table in 'row' to
 * 'code'.
 *
 * Argument constraints: in range 0 to 254
 *
 * The caller retains ownership of the arguments. */
void
sbrec_dhcpv6_options_set_code(const struct sbrec_dhcpv6_options *row, int64_t code)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = code;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_dhcpv6_options_col_code, &datum);
}

/* Sets the "name" column from the "DHCPv6_Options" table in 'row' to
 * 'name'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_dhcpv6_options_set_name(const struct sbrec_dhcpv6_options *row, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_dhcpv6_options_col_name, &datum);
}

/* Sets the "type" column from the "DHCPv6_Options" table in 'row' to
 * 'type'.
 *
 * Argument constraints: one of "mac", "str", or "ipv6"
 *
 * The caller retains ownership of the arguments. */
void
sbrec_dhcpv6_options_set_type(const struct sbrec_dhcpv6_options *row, const char *type)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, type);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_dhcpv6_options_col_type, &datum);
}

/* Sets the "code" column from the "DHCPv6_Options" table in 'row' to
 * 'code'.
 *
 * Argument constraints: in range 0 to 254
 *
 * The caller retains ownership of the arguments. */
void
sbrec_dhcpv6_options_add_clause_code(struct ovsdb_idl_condition *cond, enum ovsdb_function function, int64_t code)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = code;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_dhcpv6_options_col_code,
                          &datum);
}

/* Sets the "name" column from the "DHCPv6_Options" table in 'row' to
 * 'name'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_dhcpv6_options_add_clause_name(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_dhcpv6_options_col_name,
                          &datum);
}

/* Sets the "type" column from the "DHCPv6_Options" table in 'row' to
 * 'type'.
 *
 * Argument constraints: one of "mac", "str", or "ipv6"
 *
 * The caller retains ownership of the arguments. */
void
sbrec_dhcpv6_options_add_clause_type(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *type)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, type);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_dhcpv6_options_col_type,
                          &datum);
}

void
sbrec_dhcpv6_options_set_condition(struct ovsdb_idl *idl, struct ovsdb_idl_condition *condition)
{
    ovsdb_idl_set_condition(idl, &sbrec_table_dhcpv6_options, condition);
}
static union ovsdb_atom DHCPv6_Options_col_type_key_enum_keys[3] = {
    { .string = "ipv6" },
    { .string = "mac" },
    { .string = "str" },
};
static struct ovsdb_datum DHCPv6_Options_col_type_key_enum = {
    .n = 3,
    .keys = DHCPv6_Options_col_type_key_enum_keys,
};

struct ovsdb_idl_column sbrec_dhcpv6_options_columns[SBREC_DHCPV6_OPTIONS_N_COLUMNS] = {
    [SBREC_DHCPV6_OPTIONS_COL_CODE] = {
         .name = "code",
         .type = {
            .key = {
               .type = OVSDB_TYPE_INTEGER,
               .u.integer = { .min = INT64_C(0), .max = INT64_C(254) },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_dhcpv6_options_parse_code,
         .unparse = sbrec_dhcpv6_options_unparse_code,
    },

    [SBREC_DHCPV6_OPTIONS_COL_NAME] = {
         .name = "name",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_dhcpv6_options_parse_name,
         .unparse = sbrec_dhcpv6_options_unparse_name,
    },

    [SBREC_DHCPV6_OPTIONS_COL_TYPE] = {
         .name = "type",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .enum_ = &DHCPv6_Options_col_type_key_enum,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_dhcpv6_options_parse_type,
         .unparse = sbrec_dhcpv6_options_unparse_type,
    },

};

/* Datapath_Binding table. */

static void
sbrec_datapath_binding_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_datapath_binding *row = sbrec_datapath_binding_cast(row_);
    smap_init(&row->external_ids);
    for (size_t i = 0; i < datum->n; i++) {
        smap_add(&row->external_ids,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
sbrec_datapath_binding_parse_tunnel_key(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_datapath_binding *row = sbrec_datapath_binding_cast(row_);

    if (datum->n >= 1) {
        row->tunnel_key = datum->keys[0].integer;
    } else {
        row->tunnel_key = 0;
    }
}

static void
sbrec_datapath_binding_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct sbrec_datapath_binding *row = sbrec_datapath_binding_cast(row_);
    smap_destroy(&row->external_ids);
}

static void
sbrec_datapath_binding_unparse_tunnel_key(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_datapath_binding_init__(struct ovsdb_idl_row *row)
{
    sbrec_datapath_binding_init(sbrec_datapath_binding_cast(row));
}

/* Clears the contents of 'row' in table "Datapath_Binding". */
void
sbrec_datapath_binding_init(struct sbrec_datapath_binding *row)
{
    memset(row, 0, sizeof *row); 
    smap_init(&row->external_ids);
}

/* Searches table "Datapath_Binding" in 'idl' for a row with UUID 'uuid'.  Returns
 * a pointer to the row if there is one, otherwise a null pointer.  */
const struct sbrec_datapath_binding *
sbrec_datapath_binding_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return sbrec_datapath_binding_cast(ovsdb_idl_get_row_for_uuid(idl, &sbrec_table_datapath_binding, uuid));
}

/* Returns a row in table "Datapath_Binding" in 'idl', or a null pointer if that
 * table is empty.
 *
 * Database tables are internally maintained as hash tables, so adding or
 * removing rows while traversing the same table can cause some rows to be
 * visited twice or not at apply. */
const struct sbrec_datapath_binding *
sbrec_datapath_binding_first(const struct ovsdb_idl *idl)
{
    return sbrec_datapath_binding_cast(ovsdb_idl_first_row(idl, &sbrec_table_datapath_binding));
}

/* Returns a row following 'row' within its table, or a null pointer if 'row'
 * is the last row in its table. */
const struct sbrec_datapath_binding *
sbrec_datapath_binding_next(const struct sbrec_datapath_binding *row)
{
    return sbrec_datapath_binding_cast(ovsdb_idl_next_row(&row->header_));
}

unsigned int sbrec_datapath_binding_get_seqno(const struct ovsdb_idl *idl)
{
    return ovsdb_idl_table_get_seqno(idl, &sbrec_table_datapath_binding);
}

unsigned int sbrec_datapath_binding_row_get_seqno(const struct sbrec_datapath_binding *row, enum ovsdb_idl_change change)
{
    return ovsdb_idl_row_get_seqno(&row->header_, change);
}

const struct sbrec_datapath_binding *
sbrec_datapath_binding_track_get_first(const struct ovsdb_idl *idl)
{
    return sbrec_datapath_binding_cast(ovsdb_idl_track_get_first(idl, &sbrec_table_datapath_binding));
}

const struct sbrec_datapath_binding
*sbrec_datapath_binding_track_get_next(const struct sbrec_datapath_binding *row)
{
    return sbrec_datapath_binding_cast(ovsdb_idl_track_get_next(&row->header_));
}


/* Deletes 'row' from table "Datapath_Binding".  'row' may be freed, so it must not be
 * accessed afterward.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_datapath_binding_delete(const struct sbrec_datapath_binding *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

/* Inserts and returns a new row in the table "Datapath_Binding" in the database
 * with open transaction 'txn'.
 *
 * The new row is assigned a randomly generated provisional UUID.
 * ovsdb-server will assign a different UUID when 'txn' is committed,
 * but the IDL will replace any uses of the provisional UUID in the
 * data to be to be committed by the UUID assigned by ovsdb-server. */
struct sbrec_datapath_binding *
sbrec_datapath_binding_insert(struct ovsdb_idl_txn *txn)
{
    return sbrec_datapath_binding_cast(ovsdb_idl_txn_insert(txn, &sbrec_table_datapath_binding, NULL));
}

bool
sbrec_datapath_binding_is_updated(const struct sbrec_datapath_binding *row, enum sbrec_datapath_binding_column_id column)
{
    return ovsdb_idl_track_is_updated(&row->header_, &sbrec_datapath_binding_columns[column]);
}

/* Causes the original contents of column "external_ids" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "external_ids" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "external_ids" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "external_ids" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_datapath_binding_insert()).
 *
 *   - If "external_ids" has already been modified (with
 *     sbrec_datapath_binding_set_external_ids()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_datapath_binding_set_external_ids() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_datapath_binding_verify_external_ids(const struct sbrec_datapath_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_datapath_binding_col_external_ids);
}

/* Causes the original contents of column "tunnel_key" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "tunnel_key" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "tunnel_key" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "tunnel_key" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_datapath_binding_insert()).
 *
 *   - If "tunnel_key" has already been modified (with
 *     sbrec_datapath_binding_set_tunnel_key()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_datapath_binding_set_tunnel_key() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_datapath_binding_verify_tunnel_key(const struct sbrec_datapath_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_datapath_binding_col_tunnel_key);
}

/* Returns the "external_ids" column's value from the "Datapath_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "external_ids" member in sbrec_datapath_binding. */
const struct ovsdb_datum *
sbrec_datapath_binding_get_external_ids(const struct sbrec_datapath_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_datapath_binding_col_external_ids);
}

/* Returns the "tunnel_key" column's value from the "Datapath_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes tunnel_key's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "tunnel_key" member in sbrec_datapath_binding. */
const struct ovsdb_datum *
sbrec_datapath_binding_get_tunnel_key(const struct sbrec_datapath_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &sbrec_datapath_binding_col_tunnel_key);
}

/* Sets the "external_ids" column's value from the "Datapath_Binding" table in 'row'
 * to 'external_ids'.
 *
 * The caller retains ownership of 'external_ids' and everything in it. */
void
sbrec_datapath_binding_set_external_ids(const struct sbrec_datapath_binding *row, const struct smap *external_ids)
{
    struct ovsdb_datum datum;

    if (external_ids) {
        ovsdb_datum_from_smap(&datum, external_ids);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &sbrec_datapath_binding_col_external_ids,
                        &datum);
}


/* Sets the "tunnel_key" column from the "Datapath_Binding" table in 'row' to
 * 'tunnel_key'.
 *
 * Argument constraints: in range 1 to 16,777,215
 *
 * The caller retains ownership of the arguments. */
void
sbrec_datapath_binding_set_tunnel_key(const struct sbrec_datapath_binding *row, int64_t tunnel_key)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = tunnel_key;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_datapath_binding_col_tunnel_key, &datum);
}

/* Sets an element of the "external_ids" map column from the "Datapath_Binding" table in 'row'
 * to 'new_value' given the key value 'new_key'.
 *
 */
void
sbrec_datapath_binding_update_external_ids_setkey(const struct sbrec_datapath_binding *row, const char *new_key, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = xmalloc(datum->n * sizeof *datum->values);

    datum->keys[0].string = xstrdup(new_key);
    datum->values[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_map(&row->header_,
                                    &sbrec_datapath_binding_col_external_ids,
                                    datum);
}

/* Deletes an element of the "external_ids" map column from the "Datapath_Binding" table in 'row'
 * given the key value 'delete_key'.
 *
 */
void
sbrec_datapath_binding_update_external_ids_delkey(const struct sbrec_datapath_binding *row, const char *delete_key)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_key);

    ovsdb_idl_txn_delete_partial_map(&row->header_,
                                    &sbrec_datapath_binding_col_external_ids,
                                    datum);
}

/* Sets the "external_ids" column's value from the "Datapath_Binding" table in 'row'
 * to 'external_ids'.
 *
 * The caller retains ownership of 'external_ids' and everything in it. */
void
sbrec_datapath_binding_add_clause_external_ids(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct smap *external_ids)
{
    struct ovsdb_datum datum;

    if (external_ids) {
        ovsdb_datum_from_smap(&datum, external_ids);
    } else {
        ovsdb_datum_init_empty(&datum);
    }

    ovsdb_idl_condition_add_clause(cond,
                                   function,
                                   &sbrec_datapath_binding_col_external_ids,
                                   &datum);

    ovsdb_datum_destroy(&datum, &sbrec_datapath_binding_col_external_ids.type);
}


/* Sets the "tunnel_key" column from the "Datapath_Binding" table in 'row' to
 * 'tunnel_key'.
 *
 * Argument constraints: in range 1 to 16,777,215
 *
 * The caller retains ownership of the arguments. */
void
sbrec_datapath_binding_add_clause_tunnel_key(struct ovsdb_idl_condition *cond, enum ovsdb_function function, int64_t tunnel_key)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = tunnel_key;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_datapath_binding_col_tunnel_key,
                          &datum);
}

void
sbrec_datapath_binding_set_condition(struct ovsdb_idl *idl, struct ovsdb_idl_condition *condition)
{
    ovsdb_idl_set_condition(idl, &sbrec_table_datapath_binding, condition);
}

struct ovsdb_idl_column sbrec_datapath_binding_columns[SBREC_DATAPATH_BINDING_N_COLUMNS] = {
    [SBREC_DATAPATH_BINDING_COL_EXTERNAL_IDS] = {
         .name = "external_ids",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = {
                .type = OVSDB_TYPE_STRING,
                .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .n_min = 0,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_datapath_binding_parse_external_ids,
         .unparse = sbrec_datapath_binding_unparse_external_ids,
    },

    [SBREC_DATAPATH_BINDING_COL_TUNNEL_KEY] = {
         .name = "tunnel_key",
         .type = {
            .key = {
               .type = OVSDB_TYPE_INTEGER,
               .u.integer = { .min = INT64_C(1), .max = INT64_C(16777215) },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_datapath_binding_parse_tunnel_key,
         .unparse = sbrec_datapath_binding_unparse_tunnel_key,
    },

};

/* Encap table. */

static void
sbrec_encap_parse_ip(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_encap *row = sbrec_encap_cast(row_);

    if (datum->n >= 1) {
        row->ip = datum->keys[0].string;
    } else {
        row->ip = "";
    }
}

static void
sbrec_encap_parse_options(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_encap *row = sbrec_encap_cast(row_);
    smap_init(&row->options);
    for (size_t i = 0; i < datum->n; i++) {
        smap_add(&row->options,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
sbrec_encap_parse_type(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_encap *row = sbrec_encap_cast(row_);

    if (datum->n >= 1) {
        row->type = datum->keys[0].string;
    } else {
        row->type = "";
    }
}

static void
sbrec_encap_unparse_ip(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_encap_unparse_options(struct ovsdb_idl_row *row_)
{
    struct sbrec_encap *row = sbrec_encap_cast(row_);
    smap_destroy(&row->options);
}

static void
sbrec_encap_unparse_type(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_encap_init__(struct ovsdb_idl_row *row)
{
    sbrec_encap_init(sbrec_encap_cast(row));
}

/* Clears the contents of 'row' in table "Encap". */
void
sbrec_encap_init(struct sbrec_encap *row)
{
    memset(row, 0, sizeof *row); 
    row->ip = "";
    smap_init(&row->options);
    row->type = "";
}

/* Searches table "Encap" in 'idl' for a row with UUID 'uuid'.  Returns
 * a pointer to the row if there is one, otherwise a null pointer.  */
const struct sbrec_encap *
sbrec_encap_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return sbrec_encap_cast(ovsdb_idl_get_row_for_uuid(idl, &sbrec_table_encap, uuid));
}

/* Returns a row in table "Encap" in 'idl', or a null pointer if that
 * table is empty.
 *
 * Database tables are internally maintained as hash tables, so adding or
 * removing rows while traversing the same table can cause some rows to be
 * visited twice or not at apply. */
const struct sbrec_encap *
sbrec_encap_first(const struct ovsdb_idl *idl)
{
    return sbrec_encap_cast(ovsdb_idl_first_row(idl, &sbrec_table_encap));
}

/* Returns a row following 'row' within its table, or a null pointer if 'row'
 * is the last row in its table. */
const struct sbrec_encap *
sbrec_encap_next(const struct sbrec_encap *row)
{
    return sbrec_encap_cast(ovsdb_idl_next_row(&row->header_));
}

unsigned int sbrec_encap_get_seqno(const struct ovsdb_idl *idl)
{
    return ovsdb_idl_table_get_seqno(idl, &sbrec_table_encap);
}

unsigned int sbrec_encap_row_get_seqno(const struct sbrec_encap *row, enum ovsdb_idl_change change)
{
    return ovsdb_idl_row_get_seqno(&row->header_, change);
}

const struct sbrec_encap *
sbrec_encap_track_get_first(const struct ovsdb_idl *idl)
{
    return sbrec_encap_cast(ovsdb_idl_track_get_first(idl, &sbrec_table_encap));
}

const struct sbrec_encap
*sbrec_encap_track_get_next(const struct sbrec_encap *row)
{
    return sbrec_encap_cast(ovsdb_idl_track_get_next(&row->header_));
}


/* Deletes 'row' from table "Encap".  'row' may be freed, so it must not be
 * accessed afterward.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_encap_delete(const struct sbrec_encap *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

/* Inserts and returns a new row in the table "Encap" in the database
 * with open transaction 'txn'.
 *
 * The new row is assigned a randomly generated provisional UUID.
 * ovsdb-server will assign a different UUID when 'txn' is committed,
 * but the IDL will replace any uses of the provisional UUID in the
 * data to be to be committed by the UUID assigned by ovsdb-server. */
struct sbrec_encap *
sbrec_encap_insert(struct ovsdb_idl_txn *txn)
{
    return sbrec_encap_cast(ovsdb_idl_txn_insert(txn, &sbrec_table_encap, NULL));
}

bool
sbrec_encap_is_updated(const struct sbrec_encap *row, enum sbrec_encap_column_id column)
{
    return ovsdb_idl_track_is_updated(&row->header_, &sbrec_encap_columns[column]);
}

/* Causes the original contents of column "ip" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "ip" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "ip" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "ip" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_encap_insert()).
 *
 *   - If "ip" has already been modified (with
 *     sbrec_encap_set_ip()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_encap_set_ip() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_encap_verify_ip(const struct sbrec_encap *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_encap_col_ip);
}

/* Causes the original contents of column "options" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "options" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "options" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "options" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_encap_insert()).
 *
 *   - If "options" has already been modified (with
 *     sbrec_encap_set_options()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_encap_set_options() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_encap_verify_options(const struct sbrec_encap *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_encap_col_options);
}

/* Causes the original contents of column "type" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "type" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "type" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "type" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_encap_insert()).
 *
 *   - If "type" has already been modified (with
 *     sbrec_encap_set_type()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_encap_set_type() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_encap_verify_type(const struct sbrec_encap *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_encap_col_type);
}

/* Returns the "ip" column's value from the "Encap" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes ip's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "ip" member in sbrec_encap. */
const struct ovsdb_datum *
sbrec_encap_get_ip(const struct sbrec_encap *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_encap_col_ip);
}

/* Returns the "options" column's value from the "Encap" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes options's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "options" member in sbrec_encap. */
const struct ovsdb_datum *
sbrec_encap_get_options(const struct sbrec_encap *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_encap_col_options);
}

/* Returns the "type" column's value from the "Encap" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes type's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "type" member in sbrec_encap. */
const struct ovsdb_datum *
sbrec_encap_get_type(const struct sbrec_encap *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_encap_col_type);
}

/* Sets the "ip" column from the "Encap" table in 'row' to
 * 'ip'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_encap_set_ip(const struct sbrec_encap *row, const char *ip)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, ip);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_encap_col_ip, &datum);
}

/* Sets the "options" column's value from the "Encap" table in 'row'
 * to 'options'.
 *
 * The caller retains ownership of 'options' and everything in it. */
void
sbrec_encap_set_options(const struct sbrec_encap *row, const struct smap *options)
{
    struct ovsdb_datum datum;

    if (options) {
        ovsdb_datum_from_smap(&datum, options);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &sbrec_encap_col_options,
                        &datum);
}


/* Sets the "type" column from the "Encap" table in 'row' to
 * 'type'.
 *
 * Argument constraints: one of "stt", "geneve", or "vxlan"
 *
 * The caller retains ownership of the arguments. */
void
sbrec_encap_set_type(const struct sbrec_encap *row, const char *type)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, type);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_encap_col_type, &datum);
}

/* Sets an element of the "options" map column from the "Encap" table in 'row'
 * to 'new_value' given the key value 'new_key'.
 *
 */
void
sbrec_encap_update_options_setkey(const struct sbrec_encap *row, const char *new_key, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = xmalloc(datum->n * sizeof *datum->values);

    datum->keys[0].string = xstrdup(new_key);
    datum->values[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_map(&row->header_,
                                    &sbrec_encap_col_options,
                                    datum);
}

/* Deletes an element of the "options" map column from the "Encap" table in 'row'
 * given the key value 'delete_key'.
 *
 */
void
sbrec_encap_update_options_delkey(const struct sbrec_encap *row, const char *delete_key)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_key);

    ovsdb_idl_txn_delete_partial_map(&row->header_,
                                    &sbrec_encap_col_options,
                                    datum);
}

/* Sets the "ip" column from the "Encap" table in 'row' to
 * 'ip'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_encap_add_clause_ip(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *ip)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, ip);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_encap_col_ip,
                          &datum);
}

/* Sets the "options" column's value from the "Encap" table in 'row'
 * to 'options'.
 *
 * The caller retains ownership of 'options' and everything in it. */
void
sbrec_encap_add_clause_options(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct smap *options)
{
    struct ovsdb_datum datum;

    if (options) {
        ovsdb_datum_from_smap(&datum, options);
    } else {
        ovsdb_datum_init_empty(&datum);
    }

    ovsdb_idl_condition_add_clause(cond,
                                   function,
                                   &sbrec_encap_col_options,
                                   &datum);

    ovsdb_datum_destroy(&datum, &sbrec_encap_col_options.type);
}


/* Sets the "type" column from the "Encap" table in 'row' to
 * 'type'.
 *
 * Argument constraints: one of "stt", "geneve", or "vxlan"
 *
 * The caller retains ownership of the arguments. */
void
sbrec_encap_add_clause_type(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *type)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, type);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_encap_col_type,
                          &datum);
}

void
sbrec_encap_set_condition(struct ovsdb_idl *idl, struct ovsdb_idl_condition *condition)
{
    ovsdb_idl_set_condition(idl, &sbrec_table_encap, condition);
}
static union ovsdb_atom Encap_col_type_key_enum_keys[3] = {
    { .string = "geneve" },
    { .string = "stt" },
    { .string = "vxlan" },
};
static struct ovsdb_datum Encap_col_type_key_enum = {
    .n = 3,
    .keys = Encap_col_type_key_enum_keys,
};

struct ovsdb_idl_column sbrec_encap_columns[SBREC_ENCAP_N_COLUMNS] = {
    [SBREC_ENCAP_COL_IP] = {
         .name = "ip",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_encap_parse_ip,
         .unparse = sbrec_encap_unparse_ip,
    },

    [SBREC_ENCAP_COL_OPTIONS] = {
         .name = "options",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = {
                .type = OVSDB_TYPE_STRING,
                .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .n_min = 0,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_encap_parse_options,
         .unparse = sbrec_encap_unparse_options,
    },

    [SBREC_ENCAP_COL_TYPE] = {
         .name = "type",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .enum_ = &Encap_col_type_key_enum,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_encap_parse_type,
         .unparse = sbrec_encap_unparse_type,
    },

};

/* Logical_Flow table. */

static void
sbrec_logical_flow_parse_actions(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_logical_flow *row = sbrec_logical_flow_cast(row_);

    if (datum->n >= 1) {
        row->actions = datum->keys[0].string;
    } else {
        row->actions = "";
    }
}

static void
sbrec_logical_flow_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_logical_flow *row = sbrec_logical_flow_cast(row_);
    smap_init(&row->external_ids);
    for (size_t i = 0; i < datum->n; i++) {
        smap_add(&row->external_ids,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
sbrec_logical_flow_parse_logical_datapath(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_logical_flow *row = sbrec_logical_flow_cast(row_);

    if (datum->n >= 1) {
        row->logical_datapath = sbrec_datapath_binding_cast(ovsdb_idl_get_row_arc(row_, &sbrec_table_datapath_binding, &datum->keys[0].uuid));
    } else {
        row->logical_datapath = NULL;
    }
}

static void
sbrec_logical_flow_parse_match(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_logical_flow *row = sbrec_logical_flow_cast(row_);

    if (datum->n >= 1) {
        row->match = datum->keys[0].string;
    } else {
        row->match = "";
    }
}

static void
sbrec_logical_flow_parse_pipeline(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_logical_flow *row = sbrec_logical_flow_cast(row_);

    if (datum->n >= 1) {
        row->pipeline = datum->keys[0].string;
    } else {
        row->pipeline = "";
    }
}

static void
sbrec_logical_flow_parse_priority(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_logical_flow *row = sbrec_logical_flow_cast(row_);

    if (datum->n >= 1) {
        row->priority = datum->keys[0].integer;
    } else {
        row->priority = 0;
    }
}

static void
sbrec_logical_flow_parse_table_id(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_logical_flow *row = sbrec_logical_flow_cast(row_);

    if (datum->n >= 1) {
        row->table_id = datum->keys[0].integer;
    } else {
        row->table_id = 0;
    }
}

static void
sbrec_logical_flow_unparse_actions(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_logical_flow_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct sbrec_logical_flow *row = sbrec_logical_flow_cast(row_);
    smap_destroy(&row->external_ids);
}

static void
sbrec_logical_flow_unparse_logical_datapath(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_logical_flow_unparse_match(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_logical_flow_unparse_pipeline(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_logical_flow_unparse_priority(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_logical_flow_unparse_table_id(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_logical_flow_init__(struct ovsdb_idl_row *row)
{
    sbrec_logical_flow_init(sbrec_logical_flow_cast(row));
}

/* Clears the contents of 'row' in table "Logical_Flow". */
void
sbrec_logical_flow_init(struct sbrec_logical_flow *row)
{
    memset(row, 0, sizeof *row); 
    row->actions = "";
    smap_init(&row->external_ids);
    row->match = "";
    row->pipeline = "";
}

/* Searches table "Logical_Flow" in 'idl' for a row with UUID 'uuid'.  Returns
 * a pointer to the row if there is one, otherwise a null pointer.  */
const struct sbrec_logical_flow *
sbrec_logical_flow_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return sbrec_logical_flow_cast(ovsdb_idl_get_row_for_uuid(idl, &sbrec_table_logical_flow, uuid));
}

/* Returns a row in table "Logical_Flow" in 'idl', or a null pointer if that
 * table is empty.
 *
 * Database tables are internally maintained as hash tables, so adding or
 * removing rows while traversing the same table can cause some rows to be
 * visited twice or not at apply. */
const struct sbrec_logical_flow *
sbrec_logical_flow_first(const struct ovsdb_idl *idl)
{
    return sbrec_logical_flow_cast(ovsdb_idl_first_row(idl, &sbrec_table_logical_flow));
}

/* Returns a row following 'row' within its table, or a null pointer if 'row'
 * is the last row in its table. */
const struct sbrec_logical_flow *
sbrec_logical_flow_next(const struct sbrec_logical_flow *row)
{
    return sbrec_logical_flow_cast(ovsdb_idl_next_row(&row->header_));
}

unsigned int sbrec_logical_flow_get_seqno(const struct ovsdb_idl *idl)
{
    return ovsdb_idl_table_get_seqno(idl, &sbrec_table_logical_flow);
}

unsigned int sbrec_logical_flow_row_get_seqno(const struct sbrec_logical_flow *row, enum ovsdb_idl_change change)
{
    return ovsdb_idl_row_get_seqno(&row->header_, change);
}

const struct sbrec_logical_flow *
sbrec_logical_flow_track_get_first(const struct ovsdb_idl *idl)
{
    return sbrec_logical_flow_cast(ovsdb_idl_track_get_first(idl, &sbrec_table_logical_flow));
}

const struct sbrec_logical_flow
*sbrec_logical_flow_track_get_next(const struct sbrec_logical_flow *row)
{
    return sbrec_logical_flow_cast(ovsdb_idl_track_get_next(&row->header_));
}


/* Deletes 'row' from table "Logical_Flow".  'row' may be freed, so it must not be
 * accessed afterward.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_logical_flow_delete(const struct sbrec_logical_flow *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

/* Inserts and returns a new row in the table "Logical_Flow" in the database
 * with open transaction 'txn'.
 *
 * The new row is assigned a randomly generated provisional UUID.
 * ovsdb-server will assign a different UUID when 'txn' is committed,
 * but the IDL will replace any uses of the provisional UUID in the
 * data to be to be committed by the UUID assigned by ovsdb-server. */
struct sbrec_logical_flow *
sbrec_logical_flow_insert(struct ovsdb_idl_txn *txn)
{
    return sbrec_logical_flow_cast(ovsdb_idl_txn_insert(txn, &sbrec_table_logical_flow, NULL));
}

bool
sbrec_logical_flow_is_updated(const struct sbrec_logical_flow *row, enum sbrec_logical_flow_column_id column)
{
    return ovsdb_idl_track_is_updated(&row->header_, &sbrec_logical_flow_columns[column]);
}

/* Causes the original contents of column "actions" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "actions" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "actions" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "actions" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_logical_flow_insert()).
 *
 *   - If "actions" has already been modified (with
 *     sbrec_logical_flow_set_actions()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_logical_flow_set_actions() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_logical_flow_verify_actions(const struct sbrec_logical_flow *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_logical_flow_col_actions);
}

/* Causes the original contents of column "external_ids" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "external_ids" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "external_ids" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "external_ids" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_logical_flow_insert()).
 *
 *   - If "external_ids" has already been modified (with
 *     sbrec_logical_flow_set_external_ids()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_logical_flow_set_external_ids() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_logical_flow_verify_external_ids(const struct sbrec_logical_flow *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_logical_flow_col_external_ids);
}

/* Causes the original contents of column "logical_datapath" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "logical_datapath" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "logical_datapath" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "logical_datapath" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_logical_flow_insert()).
 *
 *   - If "logical_datapath" has already been modified (with
 *     sbrec_logical_flow_set_logical_datapath()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_logical_flow_set_logical_datapath() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_logical_flow_verify_logical_datapath(const struct sbrec_logical_flow *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_logical_flow_col_logical_datapath);
}

/* Causes the original contents of column "match" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "match" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "match" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "match" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_logical_flow_insert()).
 *
 *   - If "match" has already been modified (with
 *     sbrec_logical_flow_set_match()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_logical_flow_set_match() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_logical_flow_verify_match(const struct sbrec_logical_flow *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_logical_flow_col_match);
}

/* Causes the original contents of column "pipeline" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "pipeline" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "pipeline" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "pipeline" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_logical_flow_insert()).
 *
 *   - If "pipeline" has already been modified (with
 *     sbrec_logical_flow_set_pipeline()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_logical_flow_set_pipeline() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_logical_flow_verify_pipeline(const struct sbrec_logical_flow *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_logical_flow_col_pipeline);
}

/* Causes the original contents of column "priority" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "priority" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "priority" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "priority" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_logical_flow_insert()).
 *
 *   - If "priority" has already been modified (with
 *     sbrec_logical_flow_set_priority()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_logical_flow_set_priority() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_logical_flow_verify_priority(const struct sbrec_logical_flow *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_logical_flow_col_priority);
}

/* Causes the original contents of column "table_id" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "table_id" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "table_id" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "table_id" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_logical_flow_insert()).
 *
 *   - If "table_id" has already been modified (with
 *     sbrec_logical_flow_set_table_id()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_logical_flow_set_table_id() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_logical_flow_verify_table_id(const struct sbrec_logical_flow *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_logical_flow_col_table_id);
}

/* Returns the "actions" column's value from the "Logical_Flow" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes actions's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "actions" member in sbrec_logical_flow. */
const struct ovsdb_datum *
sbrec_logical_flow_get_actions(const struct sbrec_logical_flow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_logical_flow_col_actions);
}

/* Returns the "external_ids" column's value from the "Logical_Flow" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "external_ids" member in sbrec_logical_flow. */
const struct ovsdb_datum *
sbrec_logical_flow_get_external_ids(const struct sbrec_logical_flow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_logical_flow_col_external_ids);
}

/* Returns the "logical_datapath" column's value from the "Logical_Flow" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes logical_datapath's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "logical_datapath" member in sbrec_logical_flow. */
const struct ovsdb_datum *
sbrec_logical_flow_get_logical_datapath(const struct sbrec_logical_flow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &sbrec_logical_flow_col_logical_datapath);
}

/* Returns the "match" column's value from the "Logical_Flow" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes match's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "match" member in sbrec_logical_flow. */
const struct ovsdb_datum *
sbrec_logical_flow_get_match(const struct sbrec_logical_flow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_logical_flow_col_match);
}

/* Returns the "pipeline" column's value from the "Logical_Flow" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes pipeline's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "pipeline" member in sbrec_logical_flow. */
const struct ovsdb_datum *
sbrec_logical_flow_get_pipeline(const struct sbrec_logical_flow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_logical_flow_col_pipeline);
}

/* Returns the "priority" column's value from the "Logical_Flow" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes priority's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "priority" member in sbrec_logical_flow. */
const struct ovsdb_datum *
sbrec_logical_flow_get_priority(const struct sbrec_logical_flow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &sbrec_logical_flow_col_priority);
}

/* Returns the "table_id" column's value from the "Logical_Flow" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes table_id's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "table_id" member in sbrec_logical_flow. */
const struct ovsdb_datum *
sbrec_logical_flow_get_table_id(const struct sbrec_logical_flow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &sbrec_logical_flow_col_table_id);
}

/* Sets the "actions" column from the "Logical_Flow" table in 'row' to
 * 'actions'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_logical_flow_set_actions(const struct sbrec_logical_flow *row, const char *actions)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, actions);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_logical_flow_col_actions, &datum);
}

/* Sets the "external_ids" column's value from the "Logical_Flow" table in 'row'
 * to 'external_ids'.
 *
 * The caller retains ownership of 'external_ids' and everything in it. */
void
sbrec_logical_flow_set_external_ids(const struct sbrec_logical_flow *row, const struct smap *external_ids)
{
    struct ovsdb_datum datum;

    if (external_ids) {
        ovsdb_datum_from_smap(&datum, external_ids);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &sbrec_logical_flow_col_external_ids,
                        &datum);
}


/* Sets the "logical_datapath" column from the "Logical_Flow" table in 'row' to
 * 'logical_datapath'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_logical_flow_set_logical_datapath(const struct sbrec_logical_flow *row, const struct sbrec_datapath_binding *logical_datapath)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.uuid = logical_datapath->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_logical_flow_col_logical_datapath, &datum);
}

/* Sets the "match" column from the "Logical_Flow" table in 'row' to
 * 'match'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_logical_flow_set_match(const struct sbrec_logical_flow *row, const char *match)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, match);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_logical_flow_col_match, &datum);
}

/* Sets the "pipeline" column from the "Logical_Flow" table in 'row' to
 * 'pipeline'.
 *
 * Argument constraints: either "ingress" or "egress"
 *
 * The caller retains ownership of the arguments. */
void
sbrec_logical_flow_set_pipeline(const struct sbrec_logical_flow *row, const char *pipeline)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, pipeline);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_logical_flow_col_pipeline, &datum);
}

/* Sets the "priority" column from the "Logical_Flow" table in 'row' to
 * 'priority'.
 *
 * Argument constraints: in range 0 to 65,535
 *
 * The caller retains ownership of the arguments. */
void
sbrec_logical_flow_set_priority(const struct sbrec_logical_flow *row, int64_t priority)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = priority;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_logical_flow_col_priority, &datum);
}

/* Sets the "table_id" column from the "Logical_Flow" table in 'row' to
 * 'table_id'.
 *
 * Argument constraints: in range 0 to 15
 *
 * The caller retains ownership of the arguments. */
void
sbrec_logical_flow_set_table_id(const struct sbrec_logical_flow *row, int64_t table_id)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = table_id;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_logical_flow_col_table_id, &datum);
}

/* Sets an element of the "external_ids" map column from the "Logical_Flow" table in 'row'
 * to 'new_value' given the key value 'new_key'.
 *
 */
void
sbrec_logical_flow_update_external_ids_setkey(const struct sbrec_logical_flow *row, const char *new_key, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = xmalloc(datum->n * sizeof *datum->values);

    datum->keys[0].string = xstrdup(new_key);
    datum->values[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_map(&row->header_,
                                    &sbrec_logical_flow_col_external_ids,
                                    datum);
}

/* Deletes an element of the "external_ids" map column from the "Logical_Flow" table in 'row'
 * given the key value 'delete_key'.
 *
 */
void
sbrec_logical_flow_update_external_ids_delkey(const struct sbrec_logical_flow *row, const char *delete_key)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_key);

    ovsdb_idl_txn_delete_partial_map(&row->header_,
                                    &sbrec_logical_flow_col_external_ids,
                                    datum);
}

/* Sets the "actions" column from the "Logical_Flow" table in 'row' to
 * 'actions'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_logical_flow_add_clause_actions(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *actions)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, actions);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_logical_flow_col_actions,
                          &datum);
}

/* Sets the "external_ids" column's value from the "Logical_Flow" table in 'row'
 * to 'external_ids'.
 *
 * The caller retains ownership of 'external_ids' and everything in it. */
void
sbrec_logical_flow_add_clause_external_ids(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct smap *external_ids)
{
    struct ovsdb_datum datum;

    if (external_ids) {
        ovsdb_datum_from_smap(&datum, external_ids);
    } else {
        ovsdb_datum_init_empty(&datum);
    }

    ovsdb_idl_condition_add_clause(cond,
                                   function,
                                   &sbrec_logical_flow_col_external_ids,
                                   &datum);

    ovsdb_datum_destroy(&datum, &sbrec_logical_flow_col_external_ids.type);
}


/* Sets the "logical_datapath" column from the "Logical_Flow" table in 'row' to
 * 'logical_datapath'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_logical_flow_add_clause_logical_datapath(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct uuid *logical_datapath)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.uuid = *logical_datapath;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_logical_flow_col_logical_datapath,
                          &datum);
}

/* Sets the "match" column from the "Logical_Flow" table in 'row' to
 * 'match'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_logical_flow_add_clause_match(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *match)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, match);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_logical_flow_col_match,
                          &datum);
}

/* Sets the "pipeline" column from the "Logical_Flow" table in 'row' to
 * 'pipeline'.
 *
 * Argument constraints: either "ingress" or "egress"
 *
 * The caller retains ownership of the arguments. */
void
sbrec_logical_flow_add_clause_pipeline(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *pipeline)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, pipeline);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_logical_flow_col_pipeline,
                          &datum);
}

/* Sets the "priority" column from the "Logical_Flow" table in 'row' to
 * 'priority'.
 *
 * Argument constraints: in range 0 to 65,535
 *
 * The caller retains ownership of the arguments. */
void
sbrec_logical_flow_add_clause_priority(struct ovsdb_idl_condition *cond, enum ovsdb_function function, int64_t priority)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = priority;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_logical_flow_col_priority,
                          &datum);
}

/* Sets the "table_id" column from the "Logical_Flow" table in 'row' to
 * 'table_id'.
 *
 * Argument constraints: in range 0 to 15
 *
 * The caller retains ownership of the arguments. */
void
sbrec_logical_flow_add_clause_table_id(struct ovsdb_idl_condition *cond, enum ovsdb_function function, int64_t table_id)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = table_id;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_logical_flow_col_table_id,
                          &datum);
}

void
sbrec_logical_flow_set_condition(struct ovsdb_idl *idl, struct ovsdb_idl_condition *condition)
{
    ovsdb_idl_set_condition(idl, &sbrec_table_logical_flow, condition);
}
static union ovsdb_atom Logical_Flow_col_pipeline_key_enum_keys[2] = {
    { .string = "egress" },
    { .string = "ingress" },
};
static struct ovsdb_datum Logical_Flow_col_pipeline_key_enum = {
    .n = 2,
    .keys = Logical_Flow_col_pipeline_key_enum_keys,
};

struct ovsdb_idl_column sbrec_logical_flow_columns[SBREC_LOGICAL_FLOW_N_COLUMNS] = {
    [SBREC_LOGICAL_FLOW_COL_ACTIONS] = {
         .name = "actions",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_logical_flow_parse_actions,
         .unparse = sbrec_logical_flow_unparse_actions,
    },

    [SBREC_LOGICAL_FLOW_COL_EXTERNAL_IDS] = {
         .name = "external_ids",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = {
                .type = OVSDB_TYPE_STRING,
                .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .n_min = 0,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_logical_flow_parse_external_ids,
         .unparse = sbrec_logical_flow_unparse_external_ids,
    },

    [SBREC_LOGICAL_FLOW_COL_LOGICAL_DATAPATH] = {
         .name = "logical_datapath",
         .type = {
            .key = {
               .type = OVSDB_TYPE_UUID,
               .u.uuid = { .refTableName = "Datapath_Binding", .refType = OVSDB_REF_STRONG },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_logical_flow_parse_logical_datapath,
         .unparse = sbrec_logical_flow_unparse_logical_datapath,
    },

    [SBREC_LOGICAL_FLOW_COL_MATCH] = {
         .name = "match",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_logical_flow_parse_match,
         .unparse = sbrec_logical_flow_unparse_match,
    },

    [SBREC_LOGICAL_FLOW_COL_PIPELINE] = {
         .name = "pipeline",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .enum_ = &Logical_Flow_col_pipeline_key_enum,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_logical_flow_parse_pipeline,
         .unparse = sbrec_logical_flow_unparse_pipeline,
    },

    [SBREC_LOGICAL_FLOW_COL_PRIORITY] = {
         .name = "priority",
         .type = {
            .key = {
               .type = OVSDB_TYPE_INTEGER,
               .u.integer = { .min = INT64_C(0), .max = INT64_C(65535) },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_logical_flow_parse_priority,
         .unparse = sbrec_logical_flow_unparse_priority,
    },

    [SBREC_LOGICAL_FLOW_COL_TABLE_ID] = {
         .name = "table_id",
         .type = {
            .key = {
               .type = OVSDB_TYPE_INTEGER,
               .u.integer = { .min = INT64_C(0), .max = INT64_C(15) },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_logical_flow_parse_table_id,
         .unparse = sbrec_logical_flow_unparse_table_id,
    },

};

/* MAC_Binding table. */

static void
sbrec_mac_binding_parse_datapath(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_mac_binding *row = sbrec_mac_binding_cast(row_);

    if (datum->n >= 1) {
        row->datapath = sbrec_datapath_binding_cast(ovsdb_idl_get_row_arc(row_, &sbrec_table_datapath_binding, &datum->keys[0].uuid));
    } else {
        row->datapath = NULL;
    }
}

static void
sbrec_mac_binding_parse_ip(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_mac_binding *row = sbrec_mac_binding_cast(row_);

    if (datum->n >= 1) {
        row->ip = datum->keys[0].string;
    } else {
        row->ip = "";
    }
}

static void
sbrec_mac_binding_parse_logical_port(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_mac_binding *row = sbrec_mac_binding_cast(row_);

    if (datum->n >= 1) {
        row->logical_port = datum->keys[0].string;
    } else {
        row->logical_port = "";
    }
}

static void
sbrec_mac_binding_parse_mac(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_mac_binding *row = sbrec_mac_binding_cast(row_);

    if (datum->n >= 1) {
        row->mac = datum->keys[0].string;
    } else {
        row->mac = "";
    }
}

static void
sbrec_mac_binding_unparse_datapath(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_mac_binding_unparse_ip(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_mac_binding_unparse_logical_port(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_mac_binding_unparse_mac(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_mac_binding_init__(struct ovsdb_idl_row *row)
{
    sbrec_mac_binding_init(sbrec_mac_binding_cast(row));
}

/* Clears the contents of 'row' in table "MAC_Binding". */
void
sbrec_mac_binding_init(struct sbrec_mac_binding *row)
{
    memset(row, 0, sizeof *row); 
    row->ip = "";
    row->logical_port = "";
    row->mac = "";
}

/* Searches table "MAC_Binding" in 'idl' for a row with UUID 'uuid'.  Returns
 * a pointer to the row if there is one, otherwise a null pointer.  */
const struct sbrec_mac_binding *
sbrec_mac_binding_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return sbrec_mac_binding_cast(ovsdb_idl_get_row_for_uuid(idl, &sbrec_table_mac_binding, uuid));
}

/* Returns a row in table "MAC_Binding" in 'idl', or a null pointer if that
 * table is empty.
 *
 * Database tables are internally maintained as hash tables, so adding or
 * removing rows while traversing the same table can cause some rows to be
 * visited twice or not at apply. */
const struct sbrec_mac_binding *
sbrec_mac_binding_first(const struct ovsdb_idl *idl)
{
    return sbrec_mac_binding_cast(ovsdb_idl_first_row(idl, &sbrec_table_mac_binding));
}

/* Returns a row following 'row' within its table, or a null pointer if 'row'
 * is the last row in its table. */
const struct sbrec_mac_binding *
sbrec_mac_binding_next(const struct sbrec_mac_binding *row)
{
    return sbrec_mac_binding_cast(ovsdb_idl_next_row(&row->header_));
}

unsigned int sbrec_mac_binding_get_seqno(const struct ovsdb_idl *idl)
{
    return ovsdb_idl_table_get_seqno(idl, &sbrec_table_mac_binding);
}

unsigned int sbrec_mac_binding_row_get_seqno(const struct sbrec_mac_binding *row, enum ovsdb_idl_change change)
{
    return ovsdb_idl_row_get_seqno(&row->header_, change);
}

const struct sbrec_mac_binding *
sbrec_mac_binding_track_get_first(const struct ovsdb_idl *idl)
{
    return sbrec_mac_binding_cast(ovsdb_idl_track_get_first(idl, &sbrec_table_mac_binding));
}

const struct sbrec_mac_binding
*sbrec_mac_binding_track_get_next(const struct sbrec_mac_binding *row)
{
    return sbrec_mac_binding_cast(ovsdb_idl_track_get_next(&row->header_));
}


/* Deletes 'row' from table "MAC_Binding".  'row' may be freed, so it must not be
 * accessed afterward.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_mac_binding_delete(const struct sbrec_mac_binding *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

/* Inserts and returns a new row in the table "MAC_Binding" in the database
 * with open transaction 'txn'.
 *
 * The new row is assigned a randomly generated provisional UUID.
 * ovsdb-server will assign a different UUID when 'txn' is committed,
 * but the IDL will replace any uses of the provisional UUID in the
 * data to be to be committed by the UUID assigned by ovsdb-server. */
struct sbrec_mac_binding *
sbrec_mac_binding_insert(struct ovsdb_idl_txn *txn)
{
    return sbrec_mac_binding_cast(ovsdb_idl_txn_insert(txn, &sbrec_table_mac_binding, NULL));
}

bool
sbrec_mac_binding_is_updated(const struct sbrec_mac_binding *row, enum sbrec_mac_binding_column_id column)
{
    return ovsdb_idl_track_is_updated(&row->header_, &sbrec_mac_binding_columns[column]);
}

/* Causes the original contents of column "datapath" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "datapath" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "datapath" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "datapath" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_mac_binding_insert()).
 *
 *   - If "datapath" has already been modified (with
 *     sbrec_mac_binding_set_datapath()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_mac_binding_set_datapath() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_mac_binding_verify_datapath(const struct sbrec_mac_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_mac_binding_col_datapath);
}

/* Causes the original contents of column "ip" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "ip" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "ip" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "ip" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_mac_binding_insert()).
 *
 *   - If "ip" has already been modified (with
 *     sbrec_mac_binding_set_ip()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_mac_binding_set_ip() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_mac_binding_verify_ip(const struct sbrec_mac_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_mac_binding_col_ip);
}

/* Causes the original contents of column "logical_port" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "logical_port" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "logical_port" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "logical_port" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_mac_binding_insert()).
 *
 *   - If "logical_port" has already been modified (with
 *     sbrec_mac_binding_set_logical_port()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_mac_binding_set_logical_port() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_mac_binding_verify_logical_port(const struct sbrec_mac_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_mac_binding_col_logical_port);
}

/* Causes the original contents of column "mac" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "mac" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "mac" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "mac" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_mac_binding_insert()).
 *
 *   - If "mac" has already been modified (with
 *     sbrec_mac_binding_set_mac()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_mac_binding_set_mac() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_mac_binding_verify_mac(const struct sbrec_mac_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_mac_binding_col_mac);
}

/* Returns the "datapath" column's value from the "MAC_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes datapath's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "datapath" member in sbrec_mac_binding. */
const struct ovsdb_datum *
sbrec_mac_binding_get_datapath(const struct sbrec_mac_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &sbrec_mac_binding_col_datapath);
}

/* Returns the "ip" column's value from the "MAC_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes ip's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "ip" member in sbrec_mac_binding. */
const struct ovsdb_datum *
sbrec_mac_binding_get_ip(const struct sbrec_mac_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_mac_binding_col_ip);
}

/* Returns the "logical_port" column's value from the "MAC_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes logical_port's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "logical_port" member in sbrec_mac_binding. */
const struct ovsdb_datum *
sbrec_mac_binding_get_logical_port(const struct sbrec_mac_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_mac_binding_col_logical_port);
}

/* Returns the "mac" column's value from the "MAC_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes mac's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "mac" member in sbrec_mac_binding. */
const struct ovsdb_datum *
sbrec_mac_binding_get_mac(const struct sbrec_mac_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_mac_binding_col_mac);
}

/* Sets the "datapath" column from the "MAC_Binding" table in 'row' to
 * 'datapath'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_mac_binding_set_datapath(const struct sbrec_mac_binding *row, const struct sbrec_datapath_binding *datapath)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.uuid = datapath->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_mac_binding_col_datapath, &datum);
}

/* Sets the "ip" column from the "MAC_Binding" table in 'row' to
 * 'ip'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_mac_binding_set_ip(const struct sbrec_mac_binding *row, const char *ip)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, ip);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_mac_binding_col_ip, &datum);
}

/* Sets the "logical_port" column from the "MAC_Binding" table in 'row' to
 * 'logical_port'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_mac_binding_set_logical_port(const struct sbrec_mac_binding *row, const char *logical_port)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, logical_port);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_mac_binding_col_logical_port, &datum);
}

/* Sets the "mac" column from the "MAC_Binding" table in 'row' to
 * 'mac'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_mac_binding_set_mac(const struct sbrec_mac_binding *row, const char *mac)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, mac);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_mac_binding_col_mac, &datum);
}

/* Sets the "datapath" column from the "MAC_Binding" table in 'row' to
 * 'datapath'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_mac_binding_add_clause_datapath(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct uuid *datapath)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.uuid = *datapath;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_mac_binding_col_datapath,
                          &datum);
}

/* Sets the "ip" column from the "MAC_Binding" table in 'row' to
 * 'ip'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_mac_binding_add_clause_ip(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *ip)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, ip);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_mac_binding_col_ip,
                          &datum);
}

/* Sets the "logical_port" column from the "MAC_Binding" table in 'row' to
 * 'logical_port'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_mac_binding_add_clause_logical_port(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *logical_port)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, logical_port);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_mac_binding_col_logical_port,
                          &datum);
}

/* Sets the "mac" column from the "MAC_Binding" table in 'row' to
 * 'mac'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_mac_binding_add_clause_mac(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *mac)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, mac);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_mac_binding_col_mac,
                          &datum);
}

void
sbrec_mac_binding_set_condition(struct ovsdb_idl *idl, struct ovsdb_idl_condition *condition)
{
    ovsdb_idl_set_condition(idl, &sbrec_table_mac_binding, condition);
}

struct ovsdb_idl_column sbrec_mac_binding_columns[SBREC_MAC_BINDING_N_COLUMNS] = {
    [SBREC_MAC_BINDING_COL_DATAPATH] = {
         .name = "datapath",
         .type = {
            .key = {
               .type = OVSDB_TYPE_UUID,
               .u.uuid = { .refTableName = "Datapath_Binding", .refType = OVSDB_REF_STRONG },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_mac_binding_parse_datapath,
         .unparse = sbrec_mac_binding_unparse_datapath,
    },

    [SBREC_MAC_BINDING_COL_IP] = {
         .name = "ip",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_mac_binding_parse_ip,
         .unparse = sbrec_mac_binding_unparse_ip,
    },

    [SBREC_MAC_BINDING_COL_LOGICAL_PORT] = {
         .name = "logical_port",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_mac_binding_parse_logical_port,
         .unparse = sbrec_mac_binding_unparse_logical_port,
    },

    [SBREC_MAC_BINDING_COL_MAC] = {
         .name = "mac",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_mac_binding_parse_mac,
         .unparse = sbrec_mac_binding_unparse_mac,
    },

};

/* Multicast_Group table. */

static void
sbrec_multicast_group_parse_datapath(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_multicast_group *row = sbrec_multicast_group_cast(row_);

    if (datum->n >= 1) {
        row->datapath = sbrec_datapath_binding_cast(ovsdb_idl_get_row_arc(row_, &sbrec_table_datapath_binding, &datum->keys[0].uuid));
    } else {
        row->datapath = NULL;
    }
}

static void
sbrec_multicast_group_parse_name(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_multicast_group *row = sbrec_multicast_group_cast(row_);

    if (datum->n >= 1) {
        row->name = datum->keys[0].string;
    } else {
        row->name = "";
    }
}

static void
sbrec_multicast_group_parse_ports(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_multicast_group *row = sbrec_multicast_group_cast(row_);
    row->ports = NULL;
    row->n_ports = 0;
    for (size_t i = 0; i < datum->n; i++) {
        struct sbrec_port_binding *keyRow = sbrec_port_binding_cast(ovsdb_idl_get_row_arc(row_, &sbrec_table_port_binding, &datum->keys[i].uuid));
        if (!keyRow) {
            continue;
        }
        if (!row->n_ports) {
            row->ports = xmalloc(datum->n * sizeof *row->ports);
        }
        row->ports[row->n_ports] = keyRow;
        row->n_ports++;
    }
}

static void
sbrec_multicast_group_parse_tunnel_key(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_multicast_group *row = sbrec_multicast_group_cast(row_);

    if (datum->n >= 1) {
        row->tunnel_key = datum->keys[0].integer;
    } else {
        row->tunnel_key = 0;
    }
}

static void
sbrec_multicast_group_unparse_datapath(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_multicast_group_unparse_name(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_multicast_group_unparse_ports(struct ovsdb_idl_row *row_)
{
    struct sbrec_multicast_group *row = sbrec_multicast_group_cast(row_);
    free(row->ports);
}

static void
sbrec_multicast_group_unparse_tunnel_key(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_multicast_group_init__(struct ovsdb_idl_row *row)
{
    sbrec_multicast_group_init(sbrec_multicast_group_cast(row));
}

/* Clears the contents of 'row' in table "Multicast_Group". */
void
sbrec_multicast_group_init(struct sbrec_multicast_group *row)
{
    memset(row, 0, sizeof *row); 
    row->name = "";
}

/* Searches table "Multicast_Group" in 'idl' for a row with UUID 'uuid'.  Returns
 * a pointer to the row if there is one, otherwise a null pointer.  */
const struct sbrec_multicast_group *
sbrec_multicast_group_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return sbrec_multicast_group_cast(ovsdb_idl_get_row_for_uuid(idl, &sbrec_table_multicast_group, uuid));
}

/* Returns a row in table "Multicast_Group" in 'idl', or a null pointer if that
 * table is empty.
 *
 * Database tables are internally maintained as hash tables, so adding or
 * removing rows while traversing the same table can cause some rows to be
 * visited twice or not at apply. */
const struct sbrec_multicast_group *
sbrec_multicast_group_first(const struct ovsdb_idl *idl)
{
    return sbrec_multicast_group_cast(ovsdb_idl_first_row(idl, &sbrec_table_multicast_group));
}

/* Returns a row following 'row' within its table, or a null pointer if 'row'
 * is the last row in its table. */
const struct sbrec_multicast_group *
sbrec_multicast_group_next(const struct sbrec_multicast_group *row)
{
    return sbrec_multicast_group_cast(ovsdb_idl_next_row(&row->header_));
}

unsigned int sbrec_multicast_group_get_seqno(const struct ovsdb_idl *idl)
{
    return ovsdb_idl_table_get_seqno(idl, &sbrec_table_multicast_group);
}

unsigned int sbrec_multicast_group_row_get_seqno(const struct sbrec_multicast_group *row, enum ovsdb_idl_change change)
{
    return ovsdb_idl_row_get_seqno(&row->header_, change);
}

const struct sbrec_multicast_group *
sbrec_multicast_group_track_get_first(const struct ovsdb_idl *idl)
{
    return sbrec_multicast_group_cast(ovsdb_idl_track_get_first(idl, &sbrec_table_multicast_group));
}

const struct sbrec_multicast_group
*sbrec_multicast_group_track_get_next(const struct sbrec_multicast_group *row)
{
    return sbrec_multicast_group_cast(ovsdb_idl_track_get_next(&row->header_));
}


/* Deletes 'row' from table "Multicast_Group".  'row' may be freed, so it must not be
 * accessed afterward.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_multicast_group_delete(const struct sbrec_multicast_group *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

/* Inserts and returns a new row in the table "Multicast_Group" in the database
 * with open transaction 'txn'.
 *
 * The new row is assigned a randomly generated provisional UUID.
 * ovsdb-server will assign a different UUID when 'txn' is committed,
 * but the IDL will replace any uses of the provisional UUID in the
 * data to be to be committed by the UUID assigned by ovsdb-server. */
struct sbrec_multicast_group *
sbrec_multicast_group_insert(struct ovsdb_idl_txn *txn)
{
    return sbrec_multicast_group_cast(ovsdb_idl_txn_insert(txn, &sbrec_table_multicast_group, NULL));
}

bool
sbrec_multicast_group_is_updated(const struct sbrec_multicast_group *row, enum sbrec_multicast_group_column_id column)
{
    return ovsdb_idl_track_is_updated(&row->header_, &sbrec_multicast_group_columns[column]);
}

/* Causes the original contents of column "datapath" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "datapath" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "datapath" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "datapath" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_multicast_group_insert()).
 *
 *   - If "datapath" has already been modified (with
 *     sbrec_multicast_group_set_datapath()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_multicast_group_set_datapath() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_multicast_group_verify_datapath(const struct sbrec_multicast_group *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_multicast_group_col_datapath);
}

/* Causes the original contents of column "name" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "name" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "name" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "name" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_multicast_group_insert()).
 *
 *   - If "name" has already been modified (with
 *     sbrec_multicast_group_set_name()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_multicast_group_set_name() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_multicast_group_verify_name(const struct sbrec_multicast_group *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_multicast_group_col_name);
}

/* Causes the original contents of column "ports" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "ports" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "ports" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "ports" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_multicast_group_insert()).
 *
 *   - If "ports" has already been modified (with
 *     sbrec_multicast_group_set_ports()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_multicast_group_set_ports() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_multicast_group_verify_ports(const struct sbrec_multicast_group *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_multicast_group_col_ports);
}

/* Causes the original contents of column "tunnel_key" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "tunnel_key" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "tunnel_key" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "tunnel_key" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_multicast_group_insert()).
 *
 *   - If "tunnel_key" has already been modified (with
 *     sbrec_multicast_group_set_tunnel_key()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_multicast_group_set_tunnel_key() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_multicast_group_verify_tunnel_key(const struct sbrec_multicast_group *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_multicast_group_col_tunnel_key);
}

/* Returns the "datapath" column's value from the "Multicast_Group" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes datapath's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "datapath" member in sbrec_multicast_group. */
const struct ovsdb_datum *
sbrec_multicast_group_get_datapath(const struct sbrec_multicast_group *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &sbrec_multicast_group_col_datapath);
}

/* Returns the "name" column's value from the "Multicast_Group" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes name's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "name" member in sbrec_multicast_group. */
const struct ovsdb_datum *
sbrec_multicast_group_get_name(const struct sbrec_multicast_group *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_multicast_group_col_name);
}

/* Returns the "ports" column's value from the "Multicast_Group" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes ports's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "ports" member in sbrec_multicast_group. */
const struct ovsdb_datum *
sbrec_multicast_group_get_ports(const struct sbrec_multicast_group *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &sbrec_multicast_group_col_ports);
}

/* Returns the "tunnel_key" column's value from the "Multicast_Group" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes tunnel_key's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "tunnel_key" member in sbrec_multicast_group. */
const struct ovsdb_datum *
sbrec_multicast_group_get_tunnel_key(const struct sbrec_multicast_group *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &sbrec_multicast_group_col_tunnel_key);
}

/* Sets the "datapath" column from the "Multicast_Group" table in 'row' to
 * 'datapath'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_multicast_group_set_datapath(const struct sbrec_multicast_group *row, const struct sbrec_datapath_binding *datapath)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.uuid = datapath->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_multicast_group_col_datapath, &datum);
}

/* Sets the "name" column from the "Multicast_Group" table in 'row' to
 * 'name'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_multicast_group_set_name(const struct sbrec_multicast_group *row, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_multicast_group_col_name, &datum);
}

/* Sets the "ports" column from the "Multicast_Group" table in 'row' to
 * the 'ports' set with 'n_ports' entries.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_multicast_group_set_ports(const struct sbrec_multicast_group *row, struct sbrec_port_binding **ports, size_t n_ports)
{
    struct ovsdb_datum datum;

    datum.n = n_ports;
    datum.keys = n_ports ? xmalloc(n_ports * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (size_t i = 0; i < n_ports; i++) {
        datum.keys[i].uuid = ports[i]->header_.uuid;
    }
    ovsdb_idl_txn_write(&row->header_, &sbrec_multicast_group_col_ports, &datum);
}

/* Sets the "tunnel_key" column from the "Multicast_Group" table in 'row' to
 * 'tunnel_key'.
 *
 * Argument constraints: in range 32,768 to 65,535
 *
 * The caller retains ownership of the arguments. */
void
sbrec_multicast_group_set_tunnel_key(const struct sbrec_multicast_group *row, int64_t tunnel_key)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = tunnel_key;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_multicast_group_col_tunnel_key, &datum);
}

/* Adds the value 'new_value' to the "ports" set column from the "Multicast_Group" table
 * in 'row'.
 *
 */
void
sbrec_multicast_group_update_ports_addvalue(const struct sbrec_multicast_group *row, const struct sbrec_port_binding *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].uuid = new_value->header_.uuid;

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &sbrec_multicast_group_col_ports,
                                    datum);
}

/* Deletes the value 'delete_value' from the "ports" set column from the
 * "Multicast_Group" table in 'row'.
 *
 */
void
sbrec_multicast_group_update_ports_delvalue(const struct sbrec_multicast_group *row, const struct sbrec_port_binding *delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].uuid = delete_value->header_.uuid;

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &sbrec_multicast_group_col_ports,
                                    datum);
}

/* Sets the "datapath" column from the "Multicast_Group" table in 'row' to
 * 'datapath'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_multicast_group_add_clause_datapath(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct uuid *datapath)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.uuid = *datapath;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_multicast_group_col_datapath,
                          &datum);
}

/* Sets the "name" column from the "Multicast_Group" table in 'row' to
 * 'name'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_multicast_group_add_clause_name(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_multicast_group_col_name,
                          &datum);
}

/* Sets the "ports" column from the "Multicast_Group" table in 'row' to
 * the 'ports' set with 'n_ports' entries.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_multicast_group_add_clause_ports(struct ovsdb_idl_condition *cond, enum ovsdb_function function, struct uuid **ports, size_t n_ports)
{
    struct ovsdb_datum datum;
    datum.n = n_ports;
    datum.keys = n_ports ? xmalloc(n_ports * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (size_t i = 0; i < n_ports; i++) {
        datum.keys[i].uuid = *ports[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_multicast_group_col_ports,
                          &datum);
    free(datum.keys);
}

/* Sets the "tunnel_key" column from the "Multicast_Group" table in 'row' to
 * 'tunnel_key'.
 *
 * Argument constraints: in range 32,768 to 65,535
 *
 * The caller retains ownership of the arguments. */
void
sbrec_multicast_group_add_clause_tunnel_key(struct ovsdb_idl_condition *cond, enum ovsdb_function function, int64_t tunnel_key)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = tunnel_key;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_multicast_group_col_tunnel_key,
                          &datum);
}

void
sbrec_multicast_group_set_condition(struct ovsdb_idl *idl, struct ovsdb_idl_condition *condition)
{
    ovsdb_idl_set_condition(idl, &sbrec_table_multicast_group, condition);
}

struct ovsdb_idl_column sbrec_multicast_group_columns[SBREC_MULTICAST_GROUP_N_COLUMNS] = {
    [SBREC_MULTICAST_GROUP_COL_DATAPATH] = {
         .name = "datapath",
         .type = {
            .key = {
               .type = OVSDB_TYPE_UUID,
               .u.uuid = { .refTableName = "Datapath_Binding", .refType = OVSDB_REF_STRONG },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_multicast_group_parse_datapath,
         .unparse = sbrec_multicast_group_unparse_datapath,
    },

    [SBREC_MULTICAST_GROUP_COL_NAME] = {
         .name = "name",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_multicast_group_parse_name,
         .unparse = sbrec_multicast_group_unparse_name,
    },

    [SBREC_MULTICAST_GROUP_COL_PORTS] = {
         .name = "ports",
         .type = {
            .key = {
               .type = OVSDB_TYPE_UUID,
               .u.uuid = { .refTableName = "Port_Binding", .refType = OVSDB_REF_WEAK },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_multicast_group_parse_ports,
         .unparse = sbrec_multicast_group_unparse_ports,
    },

    [SBREC_MULTICAST_GROUP_COL_TUNNEL_KEY] = {
         .name = "tunnel_key",
         .type = {
            .key = {
               .type = OVSDB_TYPE_INTEGER,
               .u.integer = { .min = INT64_C(32768), .max = INT64_C(65535) },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_multicast_group_parse_tunnel_key,
         .unparse = sbrec_multicast_group_unparse_tunnel_key,
    },

};

/* Port_Binding table. */

static void
sbrec_port_binding_parse_chassis(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_port_binding *row = sbrec_port_binding_cast(row_);

    if (datum->n >= 1) {
        row->chassis = sbrec_chassis_cast(ovsdb_idl_get_row_arc(row_, &sbrec_table_chassis, &datum->keys[0].uuid));
    } else {
        row->chassis = NULL;
    }
}

static void
sbrec_port_binding_parse_datapath(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_port_binding *row = sbrec_port_binding_cast(row_);

    if (datum->n >= 1) {
        row->datapath = sbrec_datapath_binding_cast(ovsdb_idl_get_row_arc(row_, &sbrec_table_datapath_binding, &datum->keys[0].uuid));
    } else {
        row->datapath = NULL;
    }
}

static void
sbrec_port_binding_parse_logical_port(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_port_binding *row = sbrec_port_binding_cast(row_);

    if (datum->n >= 1) {
        row->logical_port = datum->keys[0].string;
    } else {
        row->logical_port = "";
    }
}

static void
sbrec_port_binding_parse_mac(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_port_binding *row = sbrec_port_binding_cast(row_);
    row->mac = NULL;
    row->n_mac = 0;
    for (size_t i = 0; i < datum->n; i++) {
        if (!row->n_mac) {
            row->mac = xmalloc(datum->n * sizeof *row->mac);
        }
        row->mac[row->n_mac] = datum->keys[i].string;
        row->n_mac++;
    }
}

static void
sbrec_port_binding_parse_options(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_port_binding *row = sbrec_port_binding_cast(row_);
    smap_init(&row->options);
    for (size_t i = 0; i < datum->n; i++) {
        smap_add(&row->options,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
sbrec_port_binding_parse_parent_port(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_port_binding *row = sbrec_port_binding_cast(row_);

    if (datum->n >= 1) {
        row->parent_port = datum->keys[0].string;
    } else {
        row->parent_port = NULL;
    }
}

static void
sbrec_port_binding_parse_tag(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_port_binding *row = sbrec_port_binding_cast(row_);
    size_t n = MIN(1, datum->n);
    row->tag = NULL;
    row->n_tag = 0;
    for (size_t i = 0; i < n; i++) {
        if (!row->n_tag) {
            row->tag = xmalloc(n * sizeof *row->tag);
        }
        row->tag[row->n_tag] = datum->keys[i].integer;
        row->n_tag++;
    }
}

static void
sbrec_port_binding_parse_tunnel_key(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_port_binding *row = sbrec_port_binding_cast(row_);

    if (datum->n >= 1) {
        row->tunnel_key = datum->keys[0].integer;
    } else {
        row->tunnel_key = 0;
    }
}

static void
sbrec_port_binding_parse_type(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_port_binding *row = sbrec_port_binding_cast(row_);

    if (datum->n >= 1) {
        row->type = datum->keys[0].string;
    } else {
        row->type = "";
    }
}

static void
sbrec_port_binding_unparse_chassis(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_port_binding_unparse_datapath(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_port_binding_unparse_logical_port(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_port_binding_unparse_mac(struct ovsdb_idl_row *row_)
{
    struct sbrec_port_binding *row = sbrec_port_binding_cast(row_);
    free(row->mac);
}

static void
sbrec_port_binding_unparse_options(struct ovsdb_idl_row *row_)
{
    struct sbrec_port_binding *row = sbrec_port_binding_cast(row_);
    smap_destroy(&row->options);
}

static void
sbrec_port_binding_unparse_parent_port(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_port_binding_unparse_tag(struct ovsdb_idl_row *row_)
{
    struct sbrec_port_binding *row = sbrec_port_binding_cast(row_);
    free(row->tag);
}

static void
sbrec_port_binding_unparse_tunnel_key(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_port_binding_unparse_type(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_port_binding_init__(struct ovsdb_idl_row *row)
{
    sbrec_port_binding_init(sbrec_port_binding_cast(row));
}

/* Clears the contents of 'row' in table "Port_Binding". */
void
sbrec_port_binding_init(struct sbrec_port_binding *row)
{
    memset(row, 0, sizeof *row); 
    row->logical_port = "";
    smap_init(&row->options);
    row->type = "";
}

/* Searches table "Port_Binding" in 'idl' for a row with UUID 'uuid'.  Returns
 * a pointer to the row if there is one, otherwise a null pointer.  */
const struct sbrec_port_binding *
sbrec_port_binding_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return sbrec_port_binding_cast(ovsdb_idl_get_row_for_uuid(idl, &sbrec_table_port_binding, uuid));
}

/* Returns a row in table "Port_Binding" in 'idl', or a null pointer if that
 * table is empty.
 *
 * Database tables are internally maintained as hash tables, so adding or
 * removing rows while traversing the same table can cause some rows to be
 * visited twice or not at apply. */
const struct sbrec_port_binding *
sbrec_port_binding_first(const struct ovsdb_idl *idl)
{
    return sbrec_port_binding_cast(ovsdb_idl_first_row(idl, &sbrec_table_port_binding));
}

/* Returns a row following 'row' within its table, or a null pointer if 'row'
 * is the last row in its table. */
const struct sbrec_port_binding *
sbrec_port_binding_next(const struct sbrec_port_binding *row)
{
    return sbrec_port_binding_cast(ovsdb_idl_next_row(&row->header_));
}

unsigned int sbrec_port_binding_get_seqno(const struct ovsdb_idl *idl)
{
    return ovsdb_idl_table_get_seqno(idl, &sbrec_table_port_binding);
}

unsigned int sbrec_port_binding_row_get_seqno(const struct sbrec_port_binding *row, enum ovsdb_idl_change change)
{
    return ovsdb_idl_row_get_seqno(&row->header_, change);
}

const struct sbrec_port_binding *
sbrec_port_binding_track_get_first(const struct ovsdb_idl *idl)
{
    return sbrec_port_binding_cast(ovsdb_idl_track_get_first(idl, &sbrec_table_port_binding));
}

const struct sbrec_port_binding
*sbrec_port_binding_track_get_next(const struct sbrec_port_binding *row)
{
    return sbrec_port_binding_cast(ovsdb_idl_track_get_next(&row->header_));
}


/* Deletes 'row' from table "Port_Binding".  'row' may be freed, so it must not be
 * accessed afterward.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_port_binding_delete(const struct sbrec_port_binding *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

/* Inserts and returns a new row in the table "Port_Binding" in the database
 * with open transaction 'txn'.
 *
 * The new row is assigned a randomly generated provisional UUID.
 * ovsdb-server will assign a different UUID when 'txn' is committed,
 * but the IDL will replace any uses of the provisional UUID in the
 * data to be to be committed by the UUID assigned by ovsdb-server. */
struct sbrec_port_binding *
sbrec_port_binding_insert(struct ovsdb_idl_txn *txn)
{
    return sbrec_port_binding_cast(ovsdb_idl_txn_insert(txn, &sbrec_table_port_binding, NULL));
}

bool
sbrec_port_binding_is_updated(const struct sbrec_port_binding *row, enum sbrec_port_binding_column_id column)
{
    return ovsdb_idl_track_is_updated(&row->header_, &sbrec_port_binding_columns[column]);
}

/* Causes the original contents of column "chassis" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "chassis" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "chassis" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "chassis" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_port_binding_insert()).
 *
 *   - If "chassis" has already been modified (with
 *     sbrec_port_binding_set_chassis()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_port_binding_set_chassis() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_port_binding_verify_chassis(const struct sbrec_port_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_port_binding_col_chassis);
}

/* Causes the original contents of column "datapath" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "datapath" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "datapath" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "datapath" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_port_binding_insert()).
 *
 *   - If "datapath" has already been modified (with
 *     sbrec_port_binding_set_datapath()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_port_binding_set_datapath() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_port_binding_verify_datapath(const struct sbrec_port_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_port_binding_col_datapath);
}

/* Causes the original contents of column "logical_port" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "logical_port" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "logical_port" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "logical_port" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_port_binding_insert()).
 *
 *   - If "logical_port" has already been modified (with
 *     sbrec_port_binding_set_logical_port()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_port_binding_set_logical_port() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_port_binding_verify_logical_port(const struct sbrec_port_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_port_binding_col_logical_port);
}

/* Causes the original contents of column "mac" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "mac" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "mac" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "mac" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_port_binding_insert()).
 *
 *   - If "mac" has already been modified (with
 *     sbrec_port_binding_set_mac()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_port_binding_set_mac() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_port_binding_verify_mac(const struct sbrec_port_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_port_binding_col_mac);
}

/* Causes the original contents of column "options" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "options" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "options" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "options" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_port_binding_insert()).
 *
 *   - If "options" has already been modified (with
 *     sbrec_port_binding_set_options()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_port_binding_set_options() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_port_binding_verify_options(const struct sbrec_port_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_port_binding_col_options);
}

/* Causes the original contents of column "parent_port" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "parent_port" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "parent_port" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "parent_port" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_port_binding_insert()).
 *
 *   - If "parent_port" has already been modified (with
 *     sbrec_port_binding_set_parent_port()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_port_binding_set_parent_port() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_port_binding_verify_parent_port(const struct sbrec_port_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_port_binding_col_parent_port);
}

/* Causes the original contents of column "tag" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "tag" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "tag" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "tag" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_port_binding_insert()).
 *
 *   - If "tag" has already been modified (with
 *     sbrec_port_binding_set_tag()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_port_binding_set_tag() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_port_binding_verify_tag(const struct sbrec_port_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_port_binding_col_tag);
}

/* Causes the original contents of column "tunnel_key" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "tunnel_key" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "tunnel_key" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "tunnel_key" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_port_binding_insert()).
 *
 *   - If "tunnel_key" has already been modified (with
 *     sbrec_port_binding_set_tunnel_key()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_port_binding_set_tunnel_key() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_port_binding_verify_tunnel_key(const struct sbrec_port_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_port_binding_col_tunnel_key);
}

/* Causes the original contents of column "type" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "type" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "type" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "type" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_port_binding_insert()).
 *
 *   - If "type" has already been modified (with
 *     sbrec_port_binding_set_type()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_port_binding_set_type() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_port_binding_verify_type(const struct sbrec_port_binding *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_port_binding_col_type);
}

/* Returns the "chassis" column's value from the "Port_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes chassis's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "chassis" member in sbrec_port_binding. */
const struct ovsdb_datum *
sbrec_port_binding_get_chassis(const struct sbrec_port_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &sbrec_port_binding_col_chassis);
}

/* Returns the "datapath" column's value from the "Port_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes datapath's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "datapath" member in sbrec_port_binding. */
const struct ovsdb_datum *
sbrec_port_binding_get_datapath(const struct sbrec_port_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &sbrec_port_binding_col_datapath);
}

/* Returns the "logical_port" column's value from the "Port_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes logical_port's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "logical_port" member in sbrec_port_binding. */
const struct ovsdb_datum *
sbrec_port_binding_get_logical_port(const struct sbrec_port_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_port_binding_col_logical_port);
}

/* Returns the "mac" column's value from the "Port_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes mac's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "mac" member in sbrec_port_binding. */
const struct ovsdb_datum *
sbrec_port_binding_get_mac(const struct sbrec_port_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_port_binding_col_mac);
}

/* Returns the "options" column's value from the "Port_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes options's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "options" member in sbrec_port_binding. */
const struct ovsdb_datum *
sbrec_port_binding_get_options(const struct sbrec_port_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_port_binding_col_options);
}

/* Returns the "parent_port" column's value from the "Port_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes parent_port's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "parent_port" member in sbrec_port_binding. */
const struct ovsdb_datum *
sbrec_port_binding_get_parent_port(const struct sbrec_port_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_port_binding_col_parent_port);
}

/* Returns the "tag" column's value from the "Port_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes tag's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "tag" member in sbrec_port_binding. */
const struct ovsdb_datum *
sbrec_port_binding_get_tag(const struct sbrec_port_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &sbrec_port_binding_col_tag);
}

/* Returns the "tunnel_key" column's value from the "Port_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes tunnel_key's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "tunnel_key" member in sbrec_port_binding. */
const struct ovsdb_datum *
sbrec_port_binding_get_tunnel_key(const struct sbrec_port_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &sbrec_port_binding_col_tunnel_key);
}

/* Returns the "type" column's value from the "Port_Binding" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes type's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "type" member in sbrec_port_binding. */
const struct ovsdb_datum *
sbrec_port_binding_get_type(const struct sbrec_port_binding *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_port_binding_col_type);
}

/* Sets the "chassis" column from the "Port_Binding" table in 'row' to
 * the 'chassis' set.
 *
 * If "chassis" is null, the column will be the empty set,
 * otherwise it will contain the specified value.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_set_chassis(const struct sbrec_port_binding *row, const struct sbrec_chassis *chassis)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (chassis) {
        datum.n = 1;
        datum.keys = &key;
        key.uuid = chassis->header_.uuid;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_port_binding_col_chassis, &datum);
}

/* Sets the "datapath" column from the "Port_Binding" table in 'row' to
 * 'datapath'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_set_datapath(const struct sbrec_port_binding *row, const struct sbrec_datapath_binding *datapath)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.uuid = datapath->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_port_binding_col_datapath, &datum);
}

/* Sets the "logical_port" column from the "Port_Binding" table in 'row' to
 * 'logical_port'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_set_logical_port(const struct sbrec_port_binding *row, const char *logical_port)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, logical_port);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_port_binding_col_logical_port, &datum);
}

/* Sets the "mac" column from the "Port_Binding" table in 'row' to
 * the 'mac' set with 'n_mac' entries.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_set_mac(const struct sbrec_port_binding *row, const char **mac, size_t n_mac)
{
    struct ovsdb_datum datum;

    datum.n = n_mac;
    datum.keys = n_mac ? xmalloc(n_mac * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (size_t i = 0; i < n_mac; i++) {
        datum.keys[i].string = xstrdup(mac[i]);
    }
    ovsdb_idl_txn_write(&row->header_, &sbrec_port_binding_col_mac, &datum);
}

/* Sets the "options" column's value from the "Port_Binding" table in 'row'
 * to 'options'.
 *
 * The caller retains ownership of 'options' and everything in it. */
void
sbrec_port_binding_set_options(const struct sbrec_port_binding *row, const struct smap *options)
{
    struct ovsdb_datum datum;

    if (options) {
        ovsdb_datum_from_smap(&datum, options);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &sbrec_port_binding_col_options,
                        &datum);
}


/* Sets the "parent_port" column from the "Port_Binding" table in 'row' to
 * the 'parent_port' set.
 *
 * If "parent_port" is null, the column will be the empty set,
 * otherwise it will contain the specified value.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_set_parent_port(const struct sbrec_port_binding *row, const char *parent_port)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (parent_port) {
        datum.n = 1;
        datum.keys = &key;
        key.string = CONST_CAST(char *, parent_port);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_port_binding_col_parent_port, &datum);
}

/* Sets the "tag" column from the "Port_Binding" table in 'row' to
 * the 'tag' set with 'n_tag' entries.
 *
 * 'n_tag' may be 0 or 1; if it is 0, then 'tag'
 * may be NULL.
 *
 * Argument constraints: in range 1 to 4,095
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_set_tag(const struct sbrec_port_binding *row, const int64_t *tag, size_t n_tag)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (n_tag) {
        datum.n = 1;
        datum.keys = &key;
        key.integer = *tag;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_port_binding_col_tag, &datum);
}

/* Sets the "tunnel_key" column from the "Port_Binding" table in 'row' to
 * 'tunnel_key'.
 *
 * Argument constraints: in range 1 to 32,767
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_set_tunnel_key(const struct sbrec_port_binding *row, int64_t tunnel_key)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = tunnel_key;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_port_binding_col_tunnel_key, &datum);
}

/* Sets the "type" column from the "Port_Binding" table in 'row' to
 * 'type'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_set_type(const struct sbrec_port_binding *row, const char *type)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, type);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_port_binding_col_type, &datum);
}

/* Adds the value 'new_value' to the "chassis" set column from the "Port_Binding" table
 * in 'row'.
 *
 */
void
sbrec_port_binding_update_chassis_addvalue(const struct sbrec_port_binding *row, const struct sbrec_chassis *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].uuid = new_value->header_.uuid;

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &sbrec_port_binding_col_chassis,
                                    datum);
}

/* Deletes the value 'delete_value' from the "chassis" set column from the
 * "Port_Binding" table in 'row'.
 *
 */
void
sbrec_port_binding_update_chassis_delvalue(const struct sbrec_port_binding *row, const struct sbrec_chassis *delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].uuid = delete_value->header_.uuid;

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &sbrec_port_binding_col_chassis,
                                    datum);
}

/* Adds the value 'new_value' to the "mac" set column from the "Port_Binding" table
 * in 'row'.
 *
 */
void
sbrec_port_binding_update_mac_addvalue(const struct sbrec_port_binding *row, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &sbrec_port_binding_col_mac,
                                    datum);
}

/* Deletes the value 'delete_value' from the "mac" set column from the
 * "Port_Binding" table in 'row'.
 *
 */
void
sbrec_port_binding_update_mac_delvalue(const struct sbrec_port_binding *row, const char *delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_value);

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &sbrec_port_binding_col_mac,
                                    datum);
}

/* Sets an element of the "options" map column from the "Port_Binding" table in 'row'
 * to 'new_value' given the key value 'new_key'.
 *
 */
void
sbrec_port_binding_update_options_setkey(const struct sbrec_port_binding *row, const char *new_key, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = xmalloc(datum->n * sizeof *datum->values);

    datum->keys[0].string = xstrdup(new_key);
    datum->values[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_map(&row->header_,
                                    &sbrec_port_binding_col_options,
                                    datum);
}

/* Deletes an element of the "options" map column from the "Port_Binding" table in 'row'
 * given the key value 'delete_key'.
 *
 */
void
sbrec_port_binding_update_options_delkey(const struct sbrec_port_binding *row, const char *delete_key)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_key);

    ovsdb_idl_txn_delete_partial_map(&row->header_,
                                    &sbrec_port_binding_col_options,
                                    datum);
}

/* Adds the value 'new_value' to the "parent_port" set column from the "Port_Binding" table
 * in 'row'.
 *
 */
void
sbrec_port_binding_update_parent_port_addvalue(const struct sbrec_port_binding *row, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &sbrec_port_binding_col_parent_port,
                                    datum);
}

/* Deletes the value 'delete_value' from the "parent_port" set column from the
 * "Port_Binding" table in 'row'.
 *
 */
void
sbrec_port_binding_update_parent_port_delvalue(const struct sbrec_port_binding *row, const char *delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_value);

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &sbrec_port_binding_col_parent_port,
                                    datum);
}

/* Adds the value 'new_value' to the "tag" set column from the "Port_Binding" table
 * in 'row'.
 *
 */
void
sbrec_port_binding_update_tag_addvalue(const struct sbrec_port_binding *row, int64_t new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].integer = new_value;

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &sbrec_port_binding_col_tag,
                                    datum);
}

/* Deletes the value 'delete_value' from the "tag" set column from the
 * "Port_Binding" table in 'row'.
 *
 */
void
sbrec_port_binding_update_tag_delvalue(const struct sbrec_port_binding *row, int64_t delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].integer = delete_value;

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &sbrec_port_binding_col_tag,
                                    datum);
}

/* Sets the "chassis" column from the "Port_Binding" table in 'row' to
 * the 'chassis' set.
 *
 * If "chassis" is null, the column will be the empty set,
 * otherwise it will contain the specified value.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_add_clause_chassis(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct uuid *chassis)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (chassis) {
        datum.n = 1;
        datum.keys = &key;
        key.uuid = *chassis;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_port_binding_col_chassis,
                          &datum);
}

/* Sets the "datapath" column from the "Port_Binding" table in 'row' to
 * 'datapath'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_add_clause_datapath(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct uuid *datapath)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.uuid = *datapath;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_port_binding_col_datapath,
                          &datum);
}

/* Sets the "logical_port" column from the "Port_Binding" table in 'row' to
 * 'logical_port'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_add_clause_logical_port(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *logical_port)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, logical_port);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_port_binding_col_logical_port,
                          &datum);
}

/* Sets the "mac" column from the "Port_Binding" table in 'row' to
 * the 'mac' set with 'n_mac' entries.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_add_clause_mac(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char **mac, size_t n_mac)
{
    struct ovsdb_datum datum;
    datum.n = n_mac;
    datum.keys = n_mac ? xmalloc(n_mac * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (size_t i = 0; i < n_mac; i++) {
        datum.keys[i].string = CONST_CAST(char *, mac[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_VOID);
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_port_binding_col_mac,
                          &datum);
    free(datum.keys);
}

/* Sets the "options" column's value from the "Port_Binding" table in 'row'
 * to 'options'.
 *
 * The caller retains ownership of 'options' and everything in it. */
void
sbrec_port_binding_add_clause_options(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct smap *options)
{
    struct ovsdb_datum datum;

    if (options) {
        ovsdb_datum_from_smap(&datum, options);
    } else {
        ovsdb_datum_init_empty(&datum);
    }

    ovsdb_idl_condition_add_clause(cond,
                                   function,
                                   &sbrec_port_binding_col_options,
                                   &datum);

    ovsdb_datum_destroy(&datum, &sbrec_port_binding_col_options.type);
}


/* Sets the "parent_port" column from the "Port_Binding" table in 'row' to
 * the 'parent_port' set.
 *
 * If "parent_port" is null, the column will be the empty set,
 * otherwise it will contain the specified value.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_add_clause_parent_port(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *parent_port)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (parent_port) {
        datum.n = 1;
        datum.keys = &key;
        key.string = CONST_CAST(char *, parent_port);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_port_binding_col_parent_port,
                          &datum);
}

/* Sets the "tag" column from the "Port_Binding" table in 'row' to
 * the 'tag' set with 'n_tag' entries.
 *
 * 'n_tag' may be 0 or 1; if it is 0, then 'tag'
 * may be NULL.
 *
 * Argument constraints: in range 1 to 4,095
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_add_clause_tag(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const int64_t *tag, size_t n_tag)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (n_tag) {
        datum.n = 1;
        datum.keys = &key;
        key.integer = *tag;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_port_binding_col_tag,
                          &datum);
}

/* Sets the "tunnel_key" column from the "Port_Binding" table in 'row' to
 * 'tunnel_key'.
 *
 * Argument constraints: in range 1 to 32,767
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_add_clause_tunnel_key(struct ovsdb_idl_condition *cond, enum ovsdb_function function, int64_t tunnel_key)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = tunnel_key;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_port_binding_col_tunnel_key,
                          &datum);
}

/* Sets the "type" column from the "Port_Binding" table in 'row' to
 * 'type'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_port_binding_add_clause_type(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *type)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, type);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_port_binding_col_type,
                          &datum);
}

void
sbrec_port_binding_set_condition(struct ovsdb_idl *idl, struct ovsdb_idl_condition *condition)
{
    ovsdb_idl_set_condition(idl, &sbrec_table_port_binding, condition);
}

struct ovsdb_idl_column sbrec_port_binding_columns[SBREC_PORT_BINDING_N_COLUMNS] = {
    [SBREC_PORT_BINDING_COL_CHASSIS] = {
         .name = "chassis",
         .type = {
            .key = {
               .type = OVSDB_TYPE_UUID,
               .u.uuid = { .refTableName = "Chassis", .refType = OVSDB_REF_WEAK },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 0,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_port_binding_parse_chassis,
         .unparse = sbrec_port_binding_unparse_chassis,
    },

    [SBREC_PORT_BINDING_COL_DATAPATH] = {
         .name = "datapath",
         .type = {
            .key = {
               .type = OVSDB_TYPE_UUID,
               .u.uuid = { .refTableName = "Datapath_Binding", .refType = OVSDB_REF_STRONG },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_port_binding_parse_datapath,
         .unparse = sbrec_port_binding_unparse_datapath,
    },

    [SBREC_PORT_BINDING_COL_LOGICAL_PORT] = {
         .name = "logical_port",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_port_binding_parse_logical_port,
         .unparse = sbrec_port_binding_unparse_logical_port,
    },

    [SBREC_PORT_BINDING_COL_MAC] = {
         .name = "mac",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 0,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_port_binding_parse_mac,
         .unparse = sbrec_port_binding_unparse_mac,
    },

    [SBREC_PORT_BINDING_COL_OPTIONS] = {
         .name = "options",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = {
                .type = OVSDB_TYPE_STRING,
                .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .n_min = 0,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_port_binding_parse_options,
         .unparse = sbrec_port_binding_unparse_options,
    },

    [SBREC_PORT_BINDING_COL_PARENT_PORT] = {
         .name = "parent_port",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 0,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_port_binding_parse_parent_port,
         .unparse = sbrec_port_binding_unparse_parent_port,
    },

    [SBREC_PORT_BINDING_COL_TAG] = {
         .name = "tag",
         .type = {
            .key = {
               .type = OVSDB_TYPE_INTEGER,
               .u.integer = { .min = INT64_C(1), .max = INT64_C(4095) },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 0,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_port_binding_parse_tag,
         .unparse = sbrec_port_binding_unparse_tag,
    },

    [SBREC_PORT_BINDING_COL_TUNNEL_KEY] = {
         .name = "tunnel_key",
         .type = {
            .key = {
               .type = OVSDB_TYPE_INTEGER,
               .u.integer = { .min = INT64_C(1), .max = INT64_C(32767) },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_port_binding_parse_tunnel_key,
         .unparse = sbrec_port_binding_unparse_tunnel_key,
    },

    [SBREC_PORT_BINDING_COL_TYPE] = {
         .name = "type",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_port_binding_parse_type,
         .unparse = sbrec_port_binding_unparse_type,
    },

};

/* SB_Global table. */

static void
sbrec_sb_global_parse_connections(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_sb_global *row = sbrec_sb_global_cast(row_);
    row->connections = NULL;
    row->n_connections = 0;
    for (size_t i = 0; i < datum->n; i++) {
        struct sbrec_connection *keyRow = sbrec_connection_cast(ovsdb_idl_get_row_arc(row_, &sbrec_table_connection, &datum->keys[i].uuid));
        if (!keyRow) {
            continue;
        }
        if (!row->n_connections) {
            row->connections = xmalloc(datum->n * sizeof *row->connections);
        }
        row->connections[row->n_connections] = keyRow;
        row->n_connections++;
    }
}

static void
sbrec_sb_global_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_sb_global *row = sbrec_sb_global_cast(row_);
    smap_init(&row->external_ids);
    for (size_t i = 0; i < datum->n; i++) {
        smap_add(&row->external_ids,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
sbrec_sb_global_parse_nb_cfg(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_sb_global *row = sbrec_sb_global_cast(row_);

    if (datum->n >= 1) {
        row->nb_cfg = datum->keys[0].integer;
    } else {
        row->nb_cfg = 0;
    }
}

static void
sbrec_sb_global_parse_ssl(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_sb_global *row = sbrec_sb_global_cast(row_);

    if (datum->n >= 1) {
        row->ssl = sbrec_ssl_cast(ovsdb_idl_get_row_arc(row_, &sbrec_table_ssl, &datum->keys[0].uuid));
    } else {
        row->ssl = NULL;
    }
}

static void
sbrec_sb_global_unparse_connections(struct ovsdb_idl_row *row_)
{
    struct sbrec_sb_global *row = sbrec_sb_global_cast(row_);
    free(row->connections);
}

static void
sbrec_sb_global_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct sbrec_sb_global *row = sbrec_sb_global_cast(row_);
    smap_destroy(&row->external_ids);
}

static void
sbrec_sb_global_unparse_nb_cfg(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_sb_global_unparse_ssl(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_sb_global_init__(struct ovsdb_idl_row *row)
{
    sbrec_sb_global_init(sbrec_sb_global_cast(row));
}

/* Clears the contents of 'row' in table "SB_Global". */
void
sbrec_sb_global_init(struct sbrec_sb_global *row)
{
    memset(row, 0, sizeof *row); 
    smap_init(&row->external_ids);
}

/* Searches table "SB_Global" in 'idl' for a row with UUID 'uuid'.  Returns
 * a pointer to the row if there is one, otherwise a null pointer.  */
const struct sbrec_sb_global *
sbrec_sb_global_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return sbrec_sb_global_cast(ovsdb_idl_get_row_for_uuid(idl, &sbrec_table_sb_global, uuid));
}

/* Returns a row in table "SB_Global" in 'idl', or a null pointer if that
 * table is empty.
 *
 * Database tables are internally maintained as hash tables, so adding or
 * removing rows while traversing the same table can cause some rows to be
 * visited twice or not at apply. */
const struct sbrec_sb_global *
sbrec_sb_global_first(const struct ovsdb_idl *idl)
{
    return sbrec_sb_global_cast(ovsdb_idl_first_row(idl, &sbrec_table_sb_global));
}

/* Returns a row following 'row' within its table, or a null pointer if 'row'
 * is the last row in its table. */
const struct sbrec_sb_global *
sbrec_sb_global_next(const struct sbrec_sb_global *row)
{
    return sbrec_sb_global_cast(ovsdb_idl_next_row(&row->header_));
}

unsigned int sbrec_sb_global_get_seqno(const struct ovsdb_idl *idl)
{
    return ovsdb_idl_table_get_seqno(idl, &sbrec_table_sb_global);
}

unsigned int sbrec_sb_global_row_get_seqno(const struct sbrec_sb_global *row, enum ovsdb_idl_change change)
{
    return ovsdb_idl_row_get_seqno(&row->header_, change);
}

const struct sbrec_sb_global *
sbrec_sb_global_track_get_first(const struct ovsdb_idl *idl)
{
    return sbrec_sb_global_cast(ovsdb_idl_track_get_first(idl, &sbrec_table_sb_global));
}

const struct sbrec_sb_global
*sbrec_sb_global_track_get_next(const struct sbrec_sb_global *row)
{
    return sbrec_sb_global_cast(ovsdb_idl_track_get_next(&row->header_));
}


/* Deletes 'row' from table "SB_Global".  'row' may be freed, so it must not be
 * accessed afterward.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_sb_global_delete(const struct sbrec_sb_global *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

/* Inserts and returns a new row in the table "SB_Global" in the database
 * with open transaction 'txn'.
 *
 * The new row is assigned a randomly generated provisional UUID.
 * ovsdb-server will assign a different UUID when 'txn' is committed,
 * but the IDL will replace any uses of the provisional UUID in the
 * data to be to be committed by the UUID assigned by ovsdb-server. */
struct sbrec_sb_global *
sbrec_sb_global_insert(struct ovsdb_idl_txn *txn)
{
    return sbrec_sb_global_cast(ovsdb_idl_txn_insert(txn, &sbrec_table_sb_global, NULL));
}

bool
sbrec_sb_global_is_updated(const struct sbrec_sb_global *row, enum sbrec_sb_global_column_id column)
{
    return ovsdb_idl_track_is_updated(&row->header_, &sbrec_sb_global_columns[column]);
}

/* Causes the original contents of column "connections" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "connections" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "connections" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "connections" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_sb_global_insert()).
 *
 *   - If "connections" has already been modified (with
 *     sbrec_sb_global_set_connections()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_sb_global_set_connections() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_sb_global_verify_connections(const struct sbrec_sb_global *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_sb_global_col_connections);
}

/* Causes the original contents of column "external_ids" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "external_ids" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "external_ids" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "external_ids" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_sb_global_insert()).
 *
 *   - If "external_ids" has already been modified (with
 *     sbrec_sb_global_set_external_ids()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_sb_global_set_external_ids() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_sb_global_verify_external_ids(const struct sbrec_sb_global *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_sb_global_col_external_ids);
}

/* Causes the original contents of column "nb_cfg" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "nb_cfg" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "nb_cfg" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "nb_cfg" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_sb_global_insert()).
 *
 *   - If "nb_cfg" has already been modified (with
 *     sbrec_sb_global_set_nb_cfg()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_sb_global_set_nb_cfg() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_sb_global_verify_nb_cfg(const struct sbrec_sb_global *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_sb_global_col_nb_cfg);
}

/* Causes the original contents of column "ssl" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "ssl" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "ssl" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "ssl" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_sb_global_insert()).
 *
 *   - If "ssl" has already been modified (with
 *     sbrec_sb_global_set_ssl()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_sb_global_set_ssl() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_sb_global_verify_ssl(const struct sbrec_sb_global *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_sb_global_col_ssl);
}

/* Returns the "connections" column's value from the "SB_Global" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes connections's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "connections" member in sbrec_sb_global. */
const struct ovsdb_datum *
sbrec_sb_global_get_connections(const struct sbrec_sb_global *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &sbrec_sb_global_col_connections);
}

/* Returns the "external_ids" column's value from the "SB_Global" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "external_ids" member in sbrec_sb_global. */
const struct ovsdb_datum *
sbrec_sb_global_get_external_ids(const struct sbrec_sb_global *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_sb_global_col_external_ids);
}

/* Returns the "nb_cfg" column's value from the "SB_Global" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes nb_cfg's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "nb_cfg" member in sbrec_sb_global. */
const struct ovsdb_datum *
sbrec_sb_global_get_nb_cfg(const struct sbrec_sb_global *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &sbrec_sb_global_col_nb_cfg);
}

/* Returns the "ssl" column's value from the "SB_Global" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes ssl's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "ssl" member in sbrec_sb_global. */
const struct ovsdb_datum *
sbrec_sb_global_get_ssl(const struct sbrec_sb_global *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &sbrec_sb_global_col_ssl);
}

/* Sets the "connections" column from the "SB_Global" table in 'row' to
 * the 'connections' set with 'n_connections' entries.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_sb_global_set_connections(const struct sbrec_sb_global *row, struct sbrec_connection **connections, size_t n_connections)
{
    struct ovsdb_datum datum;

    datum.n = n_connections;
    datum.keys = n_connections ? xmalloc(n_connections * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (size_t i = 0; i < n_connections; i++) {
        datum.keys[i].uuid = connections[i]->header_.uuid;
    }
    ovsdb_idl_txn_write(&row->header_, &sbrec_sb_global_col_connections, &datum);
}

/* Sets the "external_ids" column's value from the "SB_Global" table in 'row'
 * to 'external_ids'.
 *
 * The caller retains ownership of 'external_ids' and everything in it. */
void
sbrec_sb_global_set_external_ids(const struct sbrec_sb_global *row, const struct smap *external_ids)
{
    struct ovsdb_datum datum;

    if (external_ids) {
        ovsdb_datum_from_smap(&datum, external_ids);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &sbrec_sb_global_col_external_ids,
                        &datum);
}


/* Sets the "nb_cfg" column from the "SB_Global" table in 'row' to
 * 'nb_cfg'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_sb_global_set_nb_cfg(const struct sbrec_sb_global *row, int64_t nb_cfg)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = nb_cfg;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_sb_global_col_nb_cfg, &datum);
}

/* Sets the "ssl" column from the "SB_Global" table in 'row' to
 * the 'ssl' set.
 *
 * If "ssl" is null, the column will be the empty set,
 * otherwise it will contain the specified value.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_sb_global_set_ssl(const struct sbrec_sb_global *row, const struct sbrec_ssl *ssl)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (ssl) {
        datum.n = 1;
        datum.keys = &key;
        key.uuid = ssl->header_.uuid;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_sb_global_col_ssl, &datum);
}

/* Adds the value 'new_value' to the "connections" set column from the "SB_Global" table
 * in 'row'.
 *
 */
void
sbrec_sb_global_update_connections_addvalue(const struct sbrec_sb_global *row, const struct sbrec_connection *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].uuid = new_value->header_.uuid;

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &sbrec_sb_global_col_connections,
                                    datum);
}

/* Deletes the value 'delete_value' from the "connections" set column from the
 * "SB_Global" table in 'row'.
 *
 */
void
sbrec_sb_global_update_connections_delvalue(const struct sbrec_sb_global *row, const struct sbrec_connection *delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].uuid = delete_value->header_.uuid;

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &sbrec_sb_global_col_connections,
                                    datum);
}

/* Sets an element of the "external_ids" map column from the "SB_Global" table in 'row'
 * to 'new_value' given the key value 'new_key'.
 *
 */
void
sbrec_sb_global_update_external_ids_setkey(const struct sbrec_sb_global *row, const char *new_key, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = xmalloc(datum->n * sizeof *datum->values);

    datum->keys[0].string = xstrdup(new_key);
    datum->values[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_map(&row->header_,
                                    &sbrec_sb_global_col_external_ids,
                                    datum);
}

/* Deletes an element of the "external_ids" map column from the "SB_Global" table in 'row'
 * given the key value 'delete_key'.
 *
 */
void
sbrec_sb_global_update_external_ids_delkey(const struct sbrec_sb_global *row, const char *delete_key)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_key);

    ovsdb_idl_txn_delete_partial_map(&row->header_,
                                    &sbrec_sb_global_col_external_ids,
                                    datum);
}

/* Adds the value 'new_value' to the "ssl" set column from the "SB_Global" table
 * in 'row'.
 *
 */
void
sbrec_sb_global_update_ssl_addvalue(const struct sbrec_sb_global *row, const struct sbrec_ssl *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].uuid = new_value->header_.uuid;

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &sbrec_sb_global_col_ssl,
                                    datum);
}

/* Deletes the value 'delete_value' from the "ssl" set column from the
 * "SB_Global" table in 'row'.
 *
 */
void
sbrec_sb_global_update_ssl_delvalue(const struct sbrec_sb_global *row, const struct sbrec_ssl *delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].uuid = delete_value->header_.uuid;

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &sbrec_sb_global_col_ssl,
                                    datum);
}

/* Sets the "connections" column from the "SB_Global" table in 'row' to
 * the 'connections' set with 'n_connections' entries.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_sb_global_add_clause_connections(struct ovsdb_idl_condition *cond, enum ovsdb_function function, struct uuid **connections, size_t n_connections)
{
    struct ovsdb_datum datum;
    datum.n = n_connections;
    datum.keys = n_connections ? xmalloc(n_connections * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (size_t i = 0; i < n_connections; i++) {
        datum.keys[i].uuid = *connections[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_sb_global_col_connections,
                          &datum);
    free(datum.keys);
}

/* Sets the "external_ids" column's value from the "SB_Global" table in 'row'
 * to 'external_ids'.
 *
 * The caller retains ownership of 'external_ids' and everything in it. */
void
sbrec_sb_global_add_clause_external_ids(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct smap *external_ids)
{
    struct ovsdb_datum datum;

    if (external_ids) {
        ovsdb_datum_from_smap(&datum, external_ids);
    } else {
        ovsdb_datum_init_empty(&datum);
    }

    ovsdb_idl_condition_add_clause(cond,
                                   function,
                                   &sbrec_sb_global_col_external_ids,
                                   &datum);

    ovsdb_datum_destroy(&datum, &sbrec_sb_global_col_external_ids.type);
}


/* Sets the "nb_cfg" column from the "SB_Global" table in 'row' to
 * 'nb_cfg'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_sb_global_add_clause_nb_cfg(struct ovsdb_idl_condition *cond, enum ovsdb_function function, int64_t nb_cfg)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.integer = nb_cfg;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_sb_global_col_nb_cfg,
                          &datum);
}

/* Sets the "ssl" column from the "SB_Global" table in 'row' to
 * the 'ssl' set.
 *
 * If "ssl" is null, the column will be the empty set,
 * otherwise it will contain the specified value.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_sb_global_add_clause_ssl(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct uuid *ssl)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (ssl) {
        datum.n = 1;
        datum.keys = &key;
        key.uuid = *ssl;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_sb_global_col_ssl,
                          &datum);
}

void
sbrec_sb_global_set_condition(struct ovsdb_idl *idl, struct ovsdb_idl_condition *condition)
{
    ovsdb_idl_set_condition(idl, &sbrec_table_sb_global, condition);
}

struct ovsdb_idl_column sbrec_sb_global_columns[SBREC_SB_GLOBAL_N_COLUMNS] = {
    [SBREC_SB_GLOBAL_COL_CONNECTIONS] = {
         .name = "connections",
         .type = {
            .key = {
               .type = OVSDB_TYPE_UUID,
               .u.uuid = { .refTableName = "Connection", .refType = OVSDB_REF_STRONG },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 0,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_sb_global_parse_connections,
         .unparse = sbrec_sb_global_unparse_connections,
    },

    [SBREC_SB_GLOBAL_COL_EXTERNAL_IDS] = {
         .name = "external_ids",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = {
                .type = OVSDB_TYPE_STRING,
                .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .n_min = 0,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_sb_global_parse_external_ids,
         .unparse = sbrec_sb_global_unparse_external_ids,
    },

    [SBREC_SB_GLOBAL_COL_NB_CFG] = {
         .name = "nb_cfg",
         .type = {
            .key = {
               .type = OVSDB_TYPE_INTEGER,
               .u.integer = { .min = INT64_MIN, .max = INT64_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_sb_global_parse_nb_cfg,
         .unparse = sbrec_sb_global_unparse_nb_cfg,
    },

    [SBREC_SB_GLOBAL_COL_SSL] = {
         .name = "ssl",
         .type = {
            .key = {
               .type = OVSDB_TYPE_UUID,
               .u.uuid = { .refTableName = "SSL", .refType = OVSDB_REF_STRONG },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 0,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_sb_global_parse_ssl,
         .unparse = sbrec_sb_global_unparse_ssl,
    },

};

/* SSL table. */

static void
sbrec_ssl_parse_bootstrap_ca_cert(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_ssl *row = sbrec_ssl_cast(row_);

    if (datum->n >= 1) {
        row->bootstrap_ca_cert = datum->keys[0].boolean;
    } else {
        row->bootstrap_ca_cert = false;
    }
}

static void
sbrec_ssl_parse_ca_cert(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_ssl *row = sbrec_ssl_cast(row_);

    if (datum->n >= 1) {
        row->ca_cert = datum->keys[0].string;
    } else {
        row->ca_cert = "";
    }
}

static void
sbrec_ssl_parse_certificate(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_ssl *row = sbrec_ssl_cast(row_);

    if (datum->n >= 1) {
        row->certificate = datum->keys[0].string;
    } else {
        row->certificate = "";
    }
}

static void
sbrec_ssl_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_ssl *row = sbrec_ssl_cast(row_);
    smap_init(&row->external_ids);
    for (size_t i = 0; i < datum->n; i++) {
        smap_add(&row->external_ids,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
sbrec_ssl_parse_private_key(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct sbrec_ssl *row = sbrec_ssl_cast(row_);

    if (datum->n >= 1) {
        row->private_key = datum->keys[0].string;
    } else {
        row->private_key = "";
    }
}

static void
sbrec_ssl_unparse_bootstrap_ca_cert(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_ssl_unparse_ca_cert(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_ssl_unparse_certificate(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_ssl_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct sbrec_ssl *row = sbrec_ssl_cast(row_);
    smap_destroy(&row->external_ids);
}

static void
sbrec_ssl_unparse_private_key(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
sbrec_ssl_init__(struct ovsdb_idl_row *row)
{
    sbrec_ssl_init(sbrec_ssl_cast(row));
}

/* Clears the contents of 'row' in table "SSL". */
void
sbrec_ssl_init(struct sbrec_ssl *row)
{
    memset(row, 0, sizeof *row); 
    row->ca_cert = "";
    row->certificate = "";
    smap_init(&row->external_ids);
    row->private_key = "";
}

/* Searches table "SSL" in 'idl' for a row with UUID 'uuid'.  Returns
 * a pointer to the row if there is one, otherwise a null pointer.  */
const struct sbrec_ssl *
sbrec_ssl_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return sbrec_ssl_cast(ovsdb_idl_get_row_for_uuid(idl, &sbrec_table_ssl, uuid));
}

/* Returns a row in table "SSL" in 'idl', or a null pointer if that
 * table is empty.
 *
 * Database tables are internally maintained as hash tables, so adding or
 * removing rows while traversing the same table can cause some rows to be
 * visited twice or not at apply. */
const struct sbrec_ssl *
sbrec_ssl_first(const struct ovsdb_idl *idl)
{
    return sbrec_ssl_cast(ovsdb_idl_first_row(idl, &sbrec_table_ssl));
}

/* Returns a row following 'row' within its table, or a null pointer if 'row'
 * is the last row in its table. */
const struct sbrec_ssl *
sbrec_ssl_next(const struct sbrec_ssl *row)
{
    return sbrec_ssl_cast(ovsdb_idl_next_row(&row->header_));
}

unsigned int sbrec_ssl_get_seqno(const struct ovsdb_idl *idl)
{
    return ovsdb_idl_table_get_seqno(idl, &sbrec_table_ssl);
}

unsigned int sbrec_ssl_row_get_seqno(const struct sbrec_ssl *row, enum ovsdb_idl_change change)
{
    return ovsdb_idl_row_get_seqno(&row->header_, change);
}

const struct sbrec_ssl *
sbrec_ssl_track_get_first(const struct ovsdb_idl *idl)
{
    return sbrec_ssl_cast(ovsdb_idl_track_get_first(idl, &sbrec_table_ssl));
}

const struct sbrec_ssl
*sbrec_ssl_track_get_next(const struct sbrec_ssl *row)
{
    return sbrec_ssl_cast(ovsdb_idl_track_get_next(&row->header_));
}


/* Deletes 'row' from table "SSL".  'row' may be freed, so it must not be
 * accessed afterward.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_ssl_delete(const struct sbrec_ssl *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

/* Inserts and returns a new row in the table "SSL" in the database
 * with open transaction 'txn'.
 *
 * The new row is assigned a randomly generated provisional UUID.
 * ovsdb-server will assign a different UUID when 'txn' is committed,
 * but the IDL will replace any uses of the provisional UUID in the
 * data to be to be committed by the UUID assigned by ovsdb-server. */
struct sbrec_ssl *
sbrec_ssl_insert(struct ovsdb_idl_txn *txn)
{
    return sbrec_ssl_cast(ovsdb_idl_txn_insert(txn, &sbrec_table_ssl, NULL));
}

bool
sbrec_ssl_is_updated(const struct sbrec_ssl *row, enum sbrec_ssl_column_id column)
{
    return ovsdb_idl_track_is_updated(&row->header_, &sbrec_ssl_columns[column]);
}

/* Causes the original contents of column "bootstrap_ca_cert" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "bootstrap_ca_cert" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "bootstrap_ca_cert" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "bootstrap_ca_cert" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_ssl_insert()).
 *
 *   - If "bootstrap_ca_cert" has already been modified (with
 *     sbrec_ssl_set_bootstrap_ca_cert()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_ssl_set_bootstrap_ca_cert() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_ssl_verify_bootstrap_ca_cert(const struct sbrec_ssl *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_ssl_col_bootstrap_ca_cert);
}

/* Causes the original contents of column "ca_cert" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "ca_cert" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "ca_cert" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "ca_cert" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_ssl_insert()).
 *
 *   - If "ca_cert" has already been modified (with
 *     sbrec_ssl_set_ca_cert()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_ssl_set_ca_cert() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_ssl_verify_ca_cert(const struct sbrec_ssl *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_ssl_col_ca_cert);
}

/* Causes the original contents of column "certificate" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "certificate" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "certificate" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "certificate" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_ssl_insert()).
 *
 *   - If "certificate" has already been modified (with
 *     sbrec_ssl_set_certificate()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_ssl_set_certificate() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_ssl_verify_certificate(const struct sbrec_ssl *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_ssl_col_certificate);
}

/* Causes the original contents of column "external_ids" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "external_ids" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "external_ids" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "external_ids" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_ssl_insert()).
 *
 *   - If "external_ids" has already been modified (with
 *     sbrec_ssl_set_external_ids()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_ssl_set_external_ids() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_ssl_verify_external_ids(const struct sbrec_ssl *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_ssl_col_external_ids);
}

/* Causes the original contents of column "private_key" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "private_key" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "private_key" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "private_key" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     sbrec_ssl_insert()).
 *
 *   - If "private_key" has already been modified (with
 *     sbrec_ssl_set_private_key()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * sbrec_ssl_set_private_key() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
sbrec_ssl_verify_private_key(const struct sbrec_ssl *row)
{
    ovsdb_idl_txn_verify(&row->header_, &sbrec_ssl_col_private_key);
}

/* Returns the "bootstrap_ca_cert" column's value from the "SSL" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes bootstrap_ca_cert's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "bootstrap_ca_cert" member in sbrec_ssl. */
const struct ovsdb_datum *
sbrec_ssl_get_bootstrap_ca_cert(const struct sbrec_ssl *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &sbrec_ssl_col_bootstrap_ca_cert);
}

/* Returns the "ca_cert" column's value from the "SSL" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes ca_cert's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "ca_cert" member in sbrec_ssl. */
const struct ovsdb_datum *
sbrec_ssl_get_ca_cert(const struct sbrec_ssl *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_ssl_col_ca_cert);
}

/* Returns the "certificate" column's value from the "SSL" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes certificate's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "certificate" member in sbrec_ssl. */
const struct ovsdb_datum *
sbrec_ssl_get_certificate(const struct sbrec_ssl *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_ssl_col_certificate);
}

/* Returns the "external_ids" column's value from the "SSL" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "external_ids" member in sbrec_ssl. */
const struct ovsdb_datum *
sbrec_ssl_get_external_ids(const struct sbrec_ssl *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_ssl_col_external_ids);
}

/* Returns the "private_key" column's value from the "SSL" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes private_key's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "private_key" member in sbrec_ssl. */
const struct ovsdb_datum *
sbrec_ssl_get_private_key(const struct sbrec_ssl *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &sbrec_ssl_col_private_key);
}

/* Sets the "bootstrap_ca_cert" column from the "SSL" table in 'row' to
 * 'bootstrap_ca_cert'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_ssl_set_bootstrap_ca_cert(const struct sbrec_ssl *row, bool bootstrap_ca_cert)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.boolean = bootstrap_ca_cert;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_ssl_col_bootstrap_ca_cert, &datum);
}

/* Sets the "ca_cert" column from the "SSL" table in 'row' to
 * 'ca_cert'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_ssl_set_ca_cert(const struct sbrec_ssl *row, const char *ca_cert)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, ca_cert);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_ssl_col_ca_cert, &datum);
}

/* Sets the "certificate" column from the "SSL" table in 'row' to
 * 'certificate'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_ssl_set_certificate(const struct sbrec_ssl *row, const char *certificate)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, certificate);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_ssl_col_certificate, &datum);
}

/* Sets the "external_ids" column's value from the "SSL" table in 'row'
 * to 'external_ids'.
 *
 * The caller retains ownership of 'external_ids' and everything in it. */
void
sbrec_ssl_set_external_ids(const struct sbrec_ssl *row, const struct smap *external_ids)
{
    struct ovsdb_datum datum;

    if (external_ids) {
        ovsdb_datum_from_smap(&datum, external_ids);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &sbrec_ssl_col_external_ids,
                        &datum);
}


/* Sets the "private_key" column from the "SSL" table in 'row' to
 * 'private_key'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_ssl_set_private_key(const struct sbrec_ssl *row, const char *private_key)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, private_key);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &sbrec_ssl_col_private_key, &datum);
}

/* Sets an element of the "external_ids" map column from the "SSL" table in 'row'
 * to 'new_value' given the key value 'new_key'.
 *
 */
void
sbrec_ssl_update_external_ids_setkey(const struct sbrec_ssl *row, const char *new_key, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = xmalloc(datum->n * sizeof *datum->values);

    datum->keys[0].string = xstrdup(new_key);
    datum->values[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_map(&row->header_,
                                    &sbrec_ssl_col_external_ids,
                                    datum);
}

/* Deletes an element of the "external_ids" map column from the "SSL" table in 'row'
 * given the key value 'delete_key'.
 *
 */
void
sbrec_ssl_update_external_ids_delkey(const struct sbrec_ssl *row, const char *delete_key)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->keys);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_key);

    ovsdb_idl_txn_delete_partial_map(&row->header_,
                                    &sbrec_ssl_col_external_ids,
                                    datum);
}

/* Sets the "bootstrap_ca_cert" column from the "SSL" table in 'row' to
 * 'bootstrap_ca_cert'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_ssl_add_clause_bootstrap_ca_cert(struct ovsdb_idl_condition *cond, enum ovsdb_function function, bool bootstrap_ca_cert)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.boolean = bootstrap_ca_cert;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_ssl_col_bootstrap_ca_cert,
                          &datum);
}

/* Sets the "ca_cert" column from the "SSL" table in 'row' to
 * 'ca_cert'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_ssl_add_clause_ca_cert(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *ca_cert)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, ca_cert);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_ssl_col_ca_cert,
                          &datum);
}

/* Sets the "certificate" column from the "SSL" table in 'row' to
 * 'certificate'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_ssl_add_clause_certificate(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *certificate)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, certificate);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_ssl_col_certificate,
                          &datum);
}

/* Sets the "external_ids" column's value from the "SSL" table in 'row'
 * to 'external_ids'.
 *
 * The caller retains ownership of 'external_ids' and everything in it. */
void
sbrec_ssl_add_clause_external_ids(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct smap *external_ids)
{
    struct ovsdb_datum datum;

    if (external_ids) {
        ovsdb_datum_from_smap(&datum, external_ids);
    } else {
        ovsdb_datum_init_empty(&datum);
    }

    ovsdb_idl_condition_add_clause(cond,
                                   function,
                                   &sbrec_ssl_col_external_ids,
                                   &datum);

    ovsdb_datum_destroy(&datum, &sbrec_ssl_col_external_ids.type);
}


/* Sets the "private_key" column from the "SSL" table in 'row' to
 * 'private_key'.
 *
 * The caller retains ownership of the arguments. */
void
sbrec_ssl_add_clause_private_key(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *private_key)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, private_key);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &sbrec_ssl_col_private_key,
                          &datum);
}

void
sbrec_ssl_set_condition(struct ovsdb_idl *idl, struct ovsdb_idl_condition *condition)
{
    ovsdb_idl_set_condition(idl, &sbrec_table_ssl, condition);
}

struct ovsdb_idl_column sbrec_ssl_columns[SBREC_SSL_N_COLUMNS] = {
    [SBREC_SSL_COL_BOOTSTRAP_CA_CERT] = {
         .name = "bootstrap_ca_cert",
         .type = {
            .key = {
               .type = OVSDB_TYPE_BOOLEAN,
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_ssl_parse_bootstrap_ca_cert,
         .unparse = sbrec_ssl_unparse_bootstrap_ca_cert,
    },

    [SBREC_SSL_COL_CA_CERT] = {
         .name = "ca_cert",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_ssl_parse_ca_cert,
         .unparse = sbrec_ssl_unparse_ca_cert,
    },

    [SBREC_SSL_COL_CERTIFICATE] = {
         .name = "certificate",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_ssl_parse_certificate,
         .unparse = sbrec_ssl_unparse_certificate,
    },

    [SBREC_SSL_COL_EXTERNAL_IDS] = {
         .name = "external_ids",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = {
                .type = OVSDB_TYPE_STRING,
                .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .n_min = 0,
            .n_max = UINT_MAX,
         },
         .mutable = true,
         .parse = sbrec_ssl_parse_external_ids,
         .unparse = sbrec_ssl_unparse_external_ids,
    },

    [SBREC_SSL_COL_PRIVATE_KEY] = {
         .name = "private_key",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .u.string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .mutable = true,
         .parse = sbrec_ssl_parse_private_key,
         .unparse = sbrec_ssl_unparse_private_key,
    },

};

struct ovsdb_idl_table_class sbrec_table_classes[SBREC_N_TABLES] = {
    {"Address_Set", true,
     sbrec_address_set_columns, ARRAY_SIZE(sbrec_address_set_columns),
     sizeof(struct sbrec_address_set), sbrec_address_set_init__},
    {"Chassis", true,
     sbrec_chassis_columns, ARRAY_SIZE(sbrec_chassis_columns),
     sizeof(struct sbrec_chassis), sbrec_chassis_init__},
    {"Connection", false,
     sbrec_connection_columns, ARRAY_SIZE(sbrec_connection_columns),
     sizeof(struct sbrec_connection), sbrec_connection_init__},
    {"DHCP_Options", true,
     sbrec_dhcp_options_columns, ARRAY_SIZE(sbrec_dhcp_options_columns),
     sizeof(struct sbrec_dhcp_options), sbrec_dhcp_options_init__},
    {"DHCPv6_Options", true,
     sbrec_dhcpv6_options_columns, ARRAY_SIZE(sbrec_dhcpv6_options_columns),
     sizeof(struct sbrec_dhcpv6_options), sbrec_dhcpv6_options_init__},
    {"Datapath_Binding", true,
     sbrec_datapath_binding_columns, ARRAY_SIZE(sbrec_datapath_binding_columns),
     sizeof(struct sbrec_datapath_binding), sbrec_datapath_binding_init__},
    {"Encap", false,
     sbrec_encap_columns, ARRAY_SIZE(sbrec_encap_columns),
     sizeof(struct sbrec_encap), sbrec_encap_init__},
    {"Logical_Flow", true,
     sbrec_logical_flow_columns, ARRAY_SIZE(sbrec_logical_flow_columns),
     sizeof(struct sbrec_logical_flow), sbrec_logical_flow_init__},
    {"MAC_Binding", true,
     sbrec_mac_binding_columns, ARRAY_SIZE(sbrec_mac_binding_columns),
     sizeof(struct sbrec_mac_binding), sbrec_mac_binding_init__},
    {"Multicast_Group", true,
     sbrec_multicast_group_columns, ARRAY_SIZE(sbrec_multicast_group_columns),
     sizeof(struct sbrec_multicast_group), sbrec_multicast_group_init__},
    {"Port_Binding", true,
     sbrec_port_binding_columns, ARRAY_SIZE(sbrec_port_binding_columns),
     sizeof(struct sbrec_port_binding), sbrec_port_binding_init__},
    {"SB_Global", true,
     sbrec_sb_global_columns, ARRAY_SIZE(sbrec_sb_global_columns),
     sizeof(struct sbrec_sb_global), sbrec_sb_global_init__},
    {"SSL", false,
     sbrec_ssl_columns, ARRAY_SIZE(sbrec_ssl_columns),
     sizeof(struct sbrec_ssl), sbrec_ssl_init__},
};

struct ovsdb_idl_class sbrec_idl_class = {
    "OVN_Southbound", sbrec_table_classes, ARRAY_SIZE(sbrec_table_classes)
};

/* Return the schema version.  The caller must not free the returned value. */
const char *
sbrec_get_db_version(void)
{
    return "1.9.0";
}

