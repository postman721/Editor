ARCHIVE ?= plusplus-editor-3.6.2.tar.gz
DIRECTORY ?= plusplus-editor-3.6.2

.PHONY: verify extract check valgrind clean

verify:
	@set -eu; \
	archive='$(ARCHIVE)'; \
	if [ ! -f "$$archive" ]; then \
		printf '%s\n' "Archive not found: $$archive" >&2; \
		exit 1; \
	fi; \
	sha256sum -c SHA256SUMS; \
	tar -tzf "$$archive" >/dev/null; \
	printf '%s\n' "Archive verified: $$archive"

extract: verify
	@set -eu; \
	archive='$(ARCHIVE)'; \
	directory='$(DIRECTORY)'; \
	if [ -e "$$directory" ]; then \
		printf '%s\n' "Already exists: $$directory" >&2; \
		exit 1; \
	fi; \
	tar -xzf "$$archive"; \
	printf '%s\n' "Extracted: $$archive"; \
	printf '%s\n' "Next: cd $$directory"

check:
	@set -eu; \
	if [ ! -d '$(DIRECTORY)' ]; then \
		$(MAKE) extract; \
	fi; \
	$(MAKE) -C '$(DIRECTORY)' check

valgrind:
	@set -eu; \
	if [ ! -d '$(DIRECTORY)' ]; then \
		$(MAKE) extract; \
	fi; \
	$(MAKE) -C '$(DIRECTORY)' valgrind

clean:
	rm -rf '$(DIRECTORY)'
