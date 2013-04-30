try_proto(int domain) {
	int s;
	isc_result_t result = ISC_R_SUCCESS;
	char strbuf[ISC_STRERRORSIZE];

	s = socket(domain, SOCK_STREAM, 0);
	if (s == -1) {
			isc__strerror(errno, strbuf, sizeof(strbuf));
			UNEXPECTED_ERROR(__FILE__, __LINE__,
					 "socket() %s: %s",
					 isc_msgcat_get(isc_msgcat,
							ISC_MSGSET_GENERAL,
							ISC_MSG_FAILED,
							"failed"),
					 strbuf);
			return (ISC_R_UNEXPECTED);
	}

	(void)close(s);
	return (result);
}


int 
main(
    int argc,
    char *argv[]
    )
{
    
    return 0;
}
