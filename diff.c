static void diff_filespec_load_driver(struct diff_filespec *one);
static size_t fill_textconv(struct userdiff_driver *driver,
			    struct diff_filespec *df, char **outbuf);

	FILE *file;
static void emit_line_0(FILE *file, const char *set, const char *reset,
static void emit_line(FILE *file, const char *set, const char *reset,
	emit_line_0(file, set, reset, line[0], line+1, len-1);
		emit_line_0(ecbdata->file, set, reset, '+', line, len);
		emit_line_0(ecbdata->file, ws, reset, '+', line, len);
		emit_line_0(ecbdata->file, set, reset, '+', "", 0);
			      ecbdata->file, set, reset, ws);
		emit_line(ecbdata->file, plain, reset, line, len);
	emit_line(ecbdata->file, frag, reset, line, ep - line);
	if (ep != cp)
		emit_line(ecbdata->file, plain, reset, cp, ep - cp);
	if (ep < line + len)
		emit_line(ecbdata->file, func, reset, ep, line + len - ep);
			emit_line_0(ecb->file, old, reset, '-',
		emit_line_0(ecb->file, plain, reset, '\\',
	ecbdata.file = o->file;
		"%s--- %s%s%s\n%s+++ %s%s%s\n%s@@ -",
		metainfo, a_name.buf, name_a_tab, reset,
		metainfo, b_name.buf, name_b_tab, reset, fraginfo);
	FILE *file;
					  size_t count, const char *buf)
	if (diff_words->current_plus != plus_begin)
		fn_out_diff_words_write_helper(diff_words->file,
				diff_words->current_plus);
	if (minus_begin != minus_end)
		fn_out_diff_words_write_helper(diff_words->file,
				minus_end - minus_begin, minus_begin);
	if (plus_begin != plus_end)
		fn_out_diff_words_write_helper(diff_words->file,
				plus_end - plus_begin, plus_begin);
	xdemitcb_t ecb;
		fn_out_diff_words_write_helper(diff_words->file,
			diff_words->minus.text.size, diff_words->minus.text.ptr);
	xpp.flags = XDF_NEED_MINIMAL;
		      &xpp, &xecfg, &ecb);
			diff_words->plus.text.size)
		fn_out_diff_words_write_helper(diff_words->file,
			- diff_words->current_plus, diff_words->current_plus);
		fprintf(ecbdata->file, "%s", ecbdata->header->buf);
		fprintf(ecbdata->file, "%s--- %s%s%s\n",
			meta, ecbdata->label_path[0], reset, name_a_tab);
		fprintf(ecbdata->file, "%s+++ %s%s%s\n",
			meta, ecbdata->label_path[1], reset, name_b_tab);
			putc('\n', ecbdata->file);
		emit_line(ecbdata->file, reset, reset, line, len);
			fputs("~\n", ecbdata->file);
			emit_line(ecbdata->file, plain, reset, line, len);
			fputs("~\n", ecbdata->file);
			emit_line(ecbdata->file, plain, reset, line+1, len-1);
		emit_line(ecbdata->file, color, reset, line, len);
static long gather_dirstat(FILE *file, struct dirstat_dir *dir, unsigned long changed, const char *base, int baselen)
			this = gather_dirstat(file, dir, changed, f->name, newbaselen);
				fprintf(file, "%4d.%01d%% %.*s\n", percent, permille % 10, baselen, base);
	gather_dirstat(options->file, &dir, changed, "", 0);
				"%s:%d: leftover conflict marker\n",
				data->filename, data->lineno);
		fprintf(data->o->file, "%s:%d: %s.\n",
			data->filename, data->lineno, err);
		emit_line(data->o->file, set, reset, line, 1);
static void emit_binary_diff_body(FILE *file, mmfile_t *one, mmfile_t *two)
		fprintf(file, "delta %lu\n", orig_size);
		fprintf(file, "literal %lu\n", two->size);
	fprintf(file, "\n");
static void emit_binary_diff(FILE *file, mmfile_t *one, mmfile_t *two)
	fprintf(file, "GIT binary patch\n");
	emit_binary_diff_body(file, one, two);
	emit_binary_diff_body(file, two, one);
static struct userdiff_driver *get_textconv(struct diff_filespec *one)
	strbuf_addf(&header, "%sdiff --git %s %s%s\n", set, a_one, b_two, reset);
		strbuf_addf(&header, "%snew file mode %06o%s\n", set, two->mode, reset);
		if (xfrm_msg && xfrm_msg[0])
			strbuf_addf(&header, "%s%s%s\n", set, xfrm_msg, reset);
		strbuf_addf(&header, "%sdeleted file mode %06o%s\n", set, one->mode, reset);
		if (xfrm_msg && xfrm_msg[0])
			strbuf_addf(&header, "%s%s%s\n", set, xfrm_msg, reset);
			strbuf_addf(&header, "%sold mode %06o%s\n", set, one->mode, reset);
			strbuf_addf(&header, "%snew mode %06o%s\n", set, two->mode, reset);
		if (xfrm_msg && xfrm_msg[0])
			strbuf_addf(&header, "%s%s%s\n", set, xfrm_msg, reset);
		    !memcmp(mf1.ptr, mf2.ptr, mf1.size))
			emit_binary_diff(o->file, &mf1, &mf2);
			fprintf(o->file, "Binary files %s and %s differ\n",
				lbl[0], lbl[1]);
		xdemitcb_t ecb;
		if (!DIFF_XDL_TST(o, WHITESPACE_FLAGS)) {
		ecbdata.file = o->file;
		xpp.flags = XDF_NEED_MINIMAL | o->xdl_opts;
			ecbdata.diff_words->file = o->file;
			      &xpp, &xecfg, &ecb);
		xdemitcb_t ecb;
		xpp.flags = XDF_NEED_MINIMAL | o->xdl_opts;
			      &xpp, &xecfg, &ecb);
		xdemitcb_t ecb;
		xpp.flags = XDF_NEED_MINIMAL;
			      &xpp, &xecfg, &ecb);
			  struct diff_filepair *p)
		strbuf_addf(msg, "similarity index %d%%", similarity_index(p));
		strbuf_addstr(msg, "\ncopy from ");
		strbuf_addstr(msg, "\ncopy to ");
		strbuf_addch(msg, '\n');
		strbuf_addf(msg, "similarity index %d%%", similarity_index(p));
		strbuf_addstr(msg, "\nrename from ");
		strbuf_addstr(msg, "\nrename to ");
		strbuf_addch(msg, '\n');
			strbuf_addf(msg, "dissimilarity index %d%%\n",
				    similarity_index(p));
		/* nothing */
		;
		strbuf_addf(msg, "index %.*s..%.*s",
			    abbrev, sha1_to_hex(one->sha1),
			    abbrev, sha1_to_hex(two->sha1));
		strbuf_addch(msg, '\n');
	if (msg->len)
		strbuf_setlen(msg, msg->len - 1);

	if (msg) {
		fill_metainfo(msg, name, other, one, two, o, p);
		xfrm_msg = msg->len ? msg->buf : NULL;
	}
			     one, two, xfrm_msg, o, complete_rewrite);
	if (!diff_mnemonic_prefix) {
	if (!strcmp(arg, "-p") || !strcmp(arg, "-u"))
		DIFF_OPT_SET(options, IGNORE_SUBMODULES);
static void show_mode_change(FILE *file, struct diff_filepair *p, int show_name)
		fprintf(file, " mode change %06o => %06o%c", p->one->mode, p->two->mode,
			show_name ? ' ' : '\n');
static void show_rename_copy(FILE *file, const char *renamecopy, struct diff_filepair *p)
	show_mode_change(file, p, 0);
static void diff_summary(FILE *file, struct diff_filepair *p)
		show_rename_copy(file, "copy", p);
		show_rename_copy(file, "rename", p);
			fputs(" rewrite ", file);
		show_mode_change(file, p, !p->score);
		xdemitcb_t ecb;
		xpp.flags = XDF_NEED_MINIMAL;
			      &xpp, &xecfg, &ecb);
	q->queue = NULL;
	q->nr = q->alloc = 0;
		for (i = 0; i < q->nr; i++)
			diff_summary(options->file, q->queue[i]);
	q->queue = NULL;
	q->nr = q->alloc = 0;
	outq.queue = NULL;
	outq.nr = outq.alloc = 0;
	outq.queue = NULL;
	outq.nr = outq.alloc = 0;
static size_t fill_textconv(struct userdiff_driver *driver,
			    struct diff_filespec *df,
			    char **outbuf)