#ifndef SRC_ADDRESS_H_
#define SRC_ADDRESS_H_

#include <stdbool.h>
#include <netinet/in.h>
#include <libcmscodec/IPAddress.h>
#include <libcmscodec/IPAddressRange.h>

struct ipv4_prefix {
	struct in_addr addr;
	uint8_t len;
};

struct ipv6_prefix {
	struct in6_addr addr;
	uint8_t len;
};

struct ipv4_range {
	struct in_addr min;
	struct in_addr max;
};

struct ipv6_range {
	struct in6_addr min;
	struct in6_addr max;
};

uint32_t u32_suffix_mask(unsigned int);
uint32_t be32_suffix_mask(unsigned int);
void ipv6_suffix_mask(unsigned int, struct in6_addr *);

bool prefix4_equals(struct ipv4_prefix const *, struct ipv4_prefix const *);
bool prefix6_equals(struct ipv6_prefix const *, struct ipv6_prefix const *);

int prefix4_decode(IPAddress_t const *, struct ipv4_prefix *);
int prefix6_decode(IPAddress_t const *, struct ipv6_prefix *);
int range4_decode(IPAddressRange_t const *, struct ipv4_range *);
int range6_decode(IPAddressRange_t const *, struct ipv6_range *);

#endif /* SRC_ADDRESS_H_ */
