p = main
c = 3

all:
	g++ $p.cpp -o $p
	@for i in `seq $c`; do \
	echo "==== $$i.in ===="; \
	./$p < $$i.in; \
	done