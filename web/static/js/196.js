(window["webpackJsonp"] = window["webpackJsonp"] || []).push([["chunk-ab1962b6"], {
    "0b50": function(e, t, a) {},
    "0c55": function(e, t, a) {},
    "0e7b": function(e, t, a) {
        "use strict";
        a("0b50")
    },
    "121a": function(e, t, a) {
        "use strict";
        a("0c55")
    },
    "183a": function(e, t, a) {
        "use strict";
        var n = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("div", {
                staticClass: "box-card customer_boxhead"
            }, [a("div", {
                staticClass: "media-img customer_vbox",
                staticStyle: {
                    height: "600px",
                    overflow: "hidden"
                }
            }, [a("iframe", {
                attrs: {
                    id: "wx-player",
                    width: "100%",
                    height: "100%",
                    src: e.html_path,
                    frameborder: "no"
                }
            }), e.motion_detection.enabled ? a("div", {
                ref: "cavbox",
                attrs: {
                    id: "osd_canvastext"
                }
            }, [a("CanvasList", {
                attrs: {
                    boxlist: e.rect_lists,
                    cavtypes: e.cavcurrent_types[e.current_type].area,
                    cavtype_id: e.current_type
                },
                on: {
                    "update:boxlist": function(t) {
                        e.rect_lists = t
                    },
                    "update:cavtypes": function(t) {
                        return e.$set(e.cavcurrent_types[e.current_type], "area", t)
                    },
                    changelist: e.setmylist
                }
            })], 1) : e._e()]), a("div", [a("br"), a("el-switch", {
                attrs: {
                    "inactive-text": e.$t("motion_detection.enabled")
                },
                model: {
                    value: e.motion_detection.enabled,
                    callback: function(t) {
                        e.$set(e.motion_detection, "enabled", t)
                    },
                    expression: "motion_detection.enabled"
                }
            })], 1), a("div", {
                directives: [{
                    name: "show",
                    rawName: "v-show",
                    value: e.motion_detection.enabled,
                    expression: "motion_detection.enabled"
                }],
                staticClass: "mt20"
            }, [a("el-divider"), a("el-form", {
                ref: "motion_detection",
                staticClass: "custom_form2 ",
                attrs: {
                    model: e.motion_detection
                }
            }, [a("el-row", {
                staticClass: "mt20",
                attrs: {
                    gutter: 40
                }
            }, [a("el-col", {
                attrs: {
                    sm: 4
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.area")
                }
            }, [a("el-select", {
                model: {
                    value: e.current_type,
                    callback: function(t) {
                        e.current_type = t
                    },
                    expression: "current_type"
                }
            }, e._l(e.cavcurrent_types, (function(e) {
                return a("el-option", {
                    key: e.value,
                    attrs: {
                        label: e.label,
                        value: e.value
                    }
                })
            }
            )), 1)], 1)], 1), a("el-col", {
                staticClass: "auto_wh",
                attrs: {
                    sm: 5
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.sensitivity")
                }
            }, [a("el-slider", {
                style: {
                    minWidth: "auto"
                },
                model: {
                    value: e.motion_detection.sensitivity,
                    callback: function(t) {
                        e.$set(e.motion_detection, "sensitivity", t)
                    },
                    expression: "motion_detection.sensitivity"
                }
            })], 1)], 1), a("el-col", {
                attrs: {
                    sm: 3
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.flash_light")
                }
            }, [a("el-switch", {
                model: {
                    value: e.motion_detection.alarm_mode.flash_light,
                    callback: function(t) {
                        e.$set(e.motion_detection.alarm_mode, "flash_light", t)
                    },
                    expression: "motion_detection.alarm_mode.flash_light"
                }
            })], 1), a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.signal_transfer")
                }
            }, [a("el-switch", {
                model: {
                    value: e.motion_detection.alarm_mode.alarm_output,
                    callback: function(t) {
                        e.$set(e.motion_detection.alarm_mode, "alarm_output", t)
                    },
                    expression: "motion_detection.alarm_mode.alarm_output"
                }
            })], 1)], 1), a("el-col", {
                attrs: {
                    sm: 3
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.play_tone")
                }
            }, [a("el-switch", {
                model: {
                    value: e.motion_detection.alarm_mode.play_tone,
                    callback: function(t) {
                        e.$set(e.motion_detection.alarm_mode, "play_tone", t)
                    },
                    expression: "motion_detection.alarm_mode.play_tone"
                }
            })], 1), a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.Number_snaps")
                }
            }, [a("el-select", {
                staticClass: "customer_row_title_sl",
                attrs: {
                    placeholder: "please select",
                    size: "small"
                },
                model: {
                    value: e.motion_detection.alarm_mode.capture_numbers,
                    callback: function(t) {
                        e.$set(e.motion_detection.alarm_mode, "capture_numbers", t)
                    },
                    expression: "motion_detection.alarm_mode.capture_numbers"
                }
            }, e._l(e.capture_numbers_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1)], 1), a("el-col", {
                attrs: {
                    sm: 3
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.Video_stream")
                }
            }, [a("el-select", {
                staticClass: "customer_row_title_sl",
                attrs: {
                    placeholder: "please select",
                    size: "small"
                },
                model: {
                    value: e.motion_detection.alarm_mode.record_stream,
                    callback: function(t) {
                        e.$set(e.motion_detection.alarm_mode, "record_stream", t)
                    },
                    expression: "motion_detection.alarm_mode.record_stream"
                }
            }, e._l(e.view_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1)], 1), a("el-col", {
                attrs: {
                    sm: 3
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.recording_recording")
                }
            }, [a("el-select", {
                staticClass: "customer_row_title_sl",
                attrs: {
                    placeholder: "please select",
                    size: "small"
                },
                model: {
                    value: e.motion_detection.alarm_mode.pre_record_time,
                    callback: function(t) {
                        e.$set(e.motion_detection.alarm_mode, "pre_record_time", t)
                    },
                    expression: "motion_detection.alarm_mode.pre_record_time"
                }
            }, e._l(e.pre_record_time_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1)], 1), a("el-col", {
                attrs: {
                    sm: 3
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.Recording_duration")
                }
            }, [a("el-select", {
                staticClass: "customer_row_title_sl",
                attrs: {
                    placeholder: "please select",
                    size: "small"
                },
                model: {
                    value: e.motion_detection.alarm_mode.record_time,
                    callback: function(t) {
                        e.$set(e.motion_detection.alarm_mode, "record_time", t)
                    },
                    expression: "motion_detection.alarm_mode.record_time"
                }
            }, e._l(e.record_time_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1)], 1)], 1)], 1), a("el-table", {
                attrs: {
                    data: e.motion_detection.deployment_area,
                    align: "center",
                    border: ""
                }
            }, [a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.defence"),
                    prop: "defence"
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [e._v(" " + e._s(e.secondsToTime(t.row.defence)) + " ")]
                    }
                }])
            }), a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.withdrawal"),
                    prop: "withdrawal"
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [e._v(" " + e._s(e.secondsToTime(t.row.withdrawal)) + " ")]
                    }
                }])
            }), a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.days"),
                    prop: "days"
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [e._v(" " + e._s(e.$t(e.weekday_map.get(t.row.days))) + " ")]
                    }
                }])
            }), a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.repeat"),
                    prop: "repeat"
                }
            }), a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.voice"),
                    prop: "voice"
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [e._v(" " + e._s(e.$t(e.voiceName(t.row.voice))) + " ")]
                    }
                }])
            }), a("el-table-column", {
                attrs: {
                    fixed: "right",
                    label: e.$t("user_management.operations")
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [a("el-button", {
                            attrs: {
                                link: "",
                                type: "danger",
                                size: "small"
                            },
                            on: {
                                click: function(a) {
                                    return a.preventDefault(),
                                    e.removeRow(t.$index)
                                }
                            }
                        }, [e._v(" " + e._s(e.$t("user_management.remove")) + " ")])]
                    }
                }])
            })], 1), a("el-button", {
                staticClass: "mt-4 cs_btn",
                staticStyle: {
                    width: "100%"
                },
                on: {
                    click: e.onAddDefence
                }
            }, [e._v(" " + e._s(e.$t("user_management.add")) + " ")])], 1), a("el-divider"), a("div", {
                directives: [{
                    name: "permission",
                    rawName: "v-permission",
                    value: ["admin", "operator"],
                    expression: "['admin', 'operator']"
                }],
                staticClass: "mt20",
                attrs: {
                    align: "center"
                }
            }, [a("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: e.onSubmit
                }
            }, [e._v(e._s(e.$t("button.save")))]), a("el-button", {
                on: {
                    click: e.onRefresh
                }
            }, [e._v(e._s(e.$t("button.refresh")))]), a("el-button", {
                attrs: {
                    type: "warning"
                },
                on: {
                    click: e.onDefault
                }
            }, [e._v(e._s(e.$t("button.default")))])], 1), a("el-dialog", {
                attrs: {
                    visible: e.dialogAddVisible,
                    title: e.$t("user_management.add")
                },
                on: {
                    "update:visible": function(t) {
                        e.dialogAddVisible = t
                    }
                },
                scopedSlots: e._u([{
                    key: "footer",
                    fn: function() {
                        return [a("span", {
                            staticClass: "dialog-footer"
                        }, [a("el-button", {
                            on: {
                                click: e.onCancel
                            }
                        }, [e._v(" " + e._s(e.$t("user_management.cancel")) + " ")]), a("el-button", {
                            attrs: {
                                type: "primary"
                            },
                            on: {
                                click: e.onConfirm
                            }
                        }, [e._v(" " + e._s(e.$t("user_management.confirm")) + " ")])], 1)]
                    },
                    proxy: !0
                }])
            }, [a("el-form", {
                ref: "current_deployment_area",
                staticClass: "auto_wh",
                attrs: {
                    model: e.current_deployment_area,
                    "label-position": "left"
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.days")
                }
            }, [a("el-select", {
                model: {
                    value: e.current_deployment_area.days,
                    callback: function(t) {
                        e.$set(e.current_deployment_area, "days", t)
                    },
                    expression: "current_deployment_area.days"
                }
            }, e._l(e.weekday_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1), a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.repeat")
                }
            }, [a("el-select", {
                model: {
                    value: e.current_deployment_area.repeat,
                    callback: function(t) {
                        e.$set(e.current_deployment_area, "repeat", t)
                    },
                    expression: "current_deployment_area.repeat"
                }
            }, e._l(e.repeat_options, (function(e) {
                return a("el-option", {
                    key: e,
                    attrs: {
                        value: e
                    }
                })
            }
            )), 1)], 1), a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.defence")
                }
            }, [a("el-time-picker", {
                attrs: {
                    size: "small",
                    "picker-options": {
                        selectableRange: "00:00:00 - 23:59:59"
                    }
                },
                model: {
                    value: e.current_deployment_area.defence,
                    callback: function(t) {
                        e.$set(e.current_deployment_area, "defence", t)
                    },
                    expression: "current_deployment_area.defence"
                }
            })], 1), a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.withdrawal")
                }
            }, [a("el-time-picker", {
                attrs: {
                    size: "small",
                    "picker-options": {
                        selectableRange: "00:00:01 - 23:59:59"
                    }
                },
                model: {
                    value: e.current_deployment_area.withdrawal,
                    callback: function(t) {
                        e.$set(e.current_deployment_area, "withdrawal", t)
                    },
                    expression: "current_deployment_area.withdrawal"
                }
            })], 1)], 1)], 1)], 1)
        }
          , o = []
          , r = (a("99af"),
        a("a434"),
        a("4ec9"),
        a("d3b7"),
        a("3ca3"),
        a("38cf"),
        a("ddb0"),
        a("4381"))
          , i = a("ed5f")
          , l = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("canvas", {
                ref: "rectCanvas",
                attrs: {
                    id: "canvasrect"
                }
            })
        }
          , s = []
          , c = (a("cb29"),
        a("d81d"),
        a("159b"),
        {
            props: ["boxlist", "cavtypes", "cavtype_id"],
            data: function() {
                return {
                    list: [],
                    cavbox: this.boxlist,
                    area: this.cavtypes,
                    boxw: 0,
                    boxh: 0
                }
            },
            watch: {
                cavtype_id: {
                    handler: function(e, t) {
                        var a = this
                          , n = this;
                        n.area = [this.cavtypes[0], this.cavtypes[1]],
                        n.cavbox = [],
                        0 === this.cavbox.length && (n.cavbox = new Array(this.area[1]).fill("").map((function(e) {
                            return new Array(a.area[0]).fill(1)
                        }
                        ))),
                        n.list = [],
                        n.initCanvas(),
                        n.cavsend()
                    },
                    deep: !0
                }
            },
            created: function() {},
            mounted: function() {
                var e = this;
                setTimeout((function() {
                    e.initCanvas()
                }
                ), 300)
            },
            methods: {
                initCanvas: function() {
                    var e = this
                      , t = this;
                    this.$nextTick((function() {
                        var a = e.$refs.rectCanvas;
                        a.width = a.clientWidth,
                        a.height = a.clientHeight;
                        var n = a.getContext("2d");
                        a.style.cursor = "crosshair";
                        var o = t.area ? t.area : [3, 4];
                        t.list;
                        0 === e.cavbox.length && (e.cavbox = new Array(e.area[1]).fill("").map((function(t) {
                            return new Array(e.area[0]).fill(1)
                        }
                        ))),
                        n.clearRect(0, 0, a.width, a.height);
                        var r = a.width / o[0]
                          , i = a.height / o[1];
                        e.boxw = r - 4,
                        e.boxh = i - 4;
                        a.height;
                        e.list = [];
                        for (var l = 0; l < o[0]; l++)
                            for (var s = 0; s < o[1]; s++) {
                                var c = [l * r, s * i, e.boxw, e.boxh, [s, l]];
                                e.list.push(c)
                            }
                        t.reDraw(a, n, null),
                        t.draw(a)
                    }
                    ))
                },
                start: function() {
                    var e = this
                      , t = this;
                    this.$nextTick((function() {
                        var a = e.$refs.rectCanvas;
                        a.width = a.clientWidth,
                        a.height = a.clientHeight;
                        var n = a.getContext("2d");
                        a.style.cursor = "crosshair";
                        var o = t.area;
                        t.list;
                        0 === e.cavbox.length && (e.cavbox = new Array(e.area[1]).fill("").map((function(t) {
                            return new Array(e.area[0]).fill(1)
                        }
                        ))),
                        n.clearRect(0, 0, a.width, a.height);
                        var r = a.width / o[0]
                          , i = a.height / o[1];
                        e.boxw = r - 4,
                        e.boxh = i - 4;
                        a.height;
                        e.list = [];
                        for (var l = 0; l < o[0]; l++)
                            for (var s = 0; s < o[1]; s++) {
                                var c = [l * r, s * i, e.boxw, e.boxh, [s, l]];
                                e.list.push(c)
                            }
                        console.log("------------------"),
                        console.log(e.cavbox),
                        console.log("------------------"),
                        t.reDraw(a, n, null),
                        t.draw(a)
                    }
                    ))
                },
                draw: function(e, t) {
                    var a = e.getContext("2d");
                    a.strokeStyle = "blue",
                    a.lineWidth = 2;
                    var n = this.list
                      , o = 0
                      , r = 0
                      , i = this;
                    e.onmousemove = function(l) {
                        var s;
                        o = l.offsetX,
                        r = l.offsetY,
                        n.forEach((function(t, n, l) {
                            o > t[0] && o < t[0] + t[2] && r > t[1] && r < t[1] + t[3] && (s = n,
                            i.judgeDraw(e, a, s))
                        }
                        )),
                        e.onmouseout = function(a) {
                            void 0 !== t && i.draw(e, n, t)
                        }
                    }
                },
                judgeDraw: function(e, t, a) {
                    this.list;
                    e.style.cursor = "default";
                    var n = 0
                      , o = 0
                      , r = 0
                      , i = 0
                      , l = this;
                    e.onmousedown = function(s) {
                        n = s.offsetX,
                        o = s.offsetY,
                        e.onmouseup = function(a) {
                            r = a.offsetX,
                            i = a.offsetY;
                            for (var s = Math.floor(n / (e.width / l.area[0])), c = Math.floor(r / (e.width / l.area[0])), u = Math.floor(o / (e.height / l.area[1])), d = Math.floor(i / (e.height / l.area[1])), m = s; m <= c; m++)
                                for (var _ = u; _ <= d; _++)
                                    1 === l.cavbox[_][m] ? l.cavbox[_][m] = 0 : l.cavbox[_][m] = 1;
                            l.cavsend(),
                            l.reDraw(e, t, null),
                            l.draw(e, null)
                        }
                        ,
                        l.delDraw(e, t, this.list, a)
                    }
                },
                delDraw: function(e, t, a, n) {
                    var o = this;
                    e.onkeydown = null === n ? function(e) {
                        return !1
                    }
                    : function(r) {
                        var i = r.keyCode || r.which;
                        8 == i && null !== n && (a.length >= 1 ? (a.splice(n, 1),
                        o.reDraw(e, t, a)) : t.clearRect(0, 0, e.width, e.height),
                        o.delDraw(e, t, a, null),
                        o.reDraw(e, t, a),
                        o.draw(e, a))
                    }
                },
                reDraw: function(e, t, a) {
                    t.clearRect(0, 0, e.width, e.height);
                    var n = this
                      , o = this.list;
                    console.log(n.cavbox),
                    o.forEach((function(e, o, r) {
                        void 0 === a || o != a ? 1 === n.cavbox[e[4][0]][e[4][1]] ? (t.beginPath(),
                        t.strokeStyle = "red",
                        t.rect(e[0], e[1], e[2], e[3]),
                        t.stroke()) : (t.beginPath(),
                        t.strokeStyle = "RGBA(102,102,102,0)",
                        t.rect(e[0], e[1], e[2], e[3]),
                        t.stroke()) : 1 === n.cavbox[e[4][0]][e[4][1]] ? (n.cavbox[e[4][0]][e[4][1]] = 0,
                        t.beginPath(),
                        t.strokeStyle = "yellow",
                        t.rect(e[0], e[1], e[2], e[3]),
                        t.stroke()) : (t.beginPath(),
                        t.strokeStyle = "green",
                        t.rect(e[0], e[1], e[2], e[3]),
                        t.stroke(),
                        n.cavbox[e[4][0]][e[4][1]] = 1)
                    }
                    ))
                },
                cavsend: function() {
                    this.$emit("changelist", this.cavbox)
                }
            }
        })
          , u = c
          , d = (a("a77e"),
        a("2877"))
          , m = Object(d["a"])(u, l, s, !1, null, "7bffa8e8", null)
          , _ = m.exports
          , f = {
            props: ["view_options", "record_time_options", "pre_record_time_options", "capture_numbers_options"],
            components: {
                CanvasList: _
            },
            directives: {
                permission: r["a"]
            },
            data: function() {
                return {
                    activeNames: ["1"],
                    html_path: "/static/player/index.html",
                    rect_lists: [],
                    current_type: 0,
                    cavcurrent_types: [],
                    dialogAddVisible: !1,
                    current_deployment_area: {
                        area: {
                            id: 0
                        },
                        defence: null,
                        withdrawal: null,
                        days: 1,
                        repeat: 1
                    },
                    repeat_options: [1, 2, 3],
                    weekday_map: new Map([[i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI, "human_recognition.m_f"], [i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI | i["a"].SAT, "human_recognition.m_s"], [i["a"].SAT | i["a"].SUN, "human_recognition.sat_sun"], [i["a"].SUN, "human_recognition.sun"], [i["a"].SUN | i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI | i["a"].SAT, "human_recognition.everyday"]]),
                    weekday_options: [{
                        label: "human_recognition.m_f",
                        value: i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI
                    }, {
                        label: "human_recognition.m_s",
                        value: i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI | i["a"].SAT
                    }, {
                        label: "human_recognition.sat_sun",
                        value: i["a"].SAT | i["a"].SUN
                    }, {
                        label: "human_recognition.sun",
                        value: i["a"].SUN
                    }, {
                        label: "human_recognition.everyday",
                        value: i["a"].SUN | i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI | i["a"].SAT
                    }],
                    motion_detection: {
                        enabled: null,
                        sensitivity: null,
                        alarm_mode: {
                            flash_light: null,
                            play_tone: null,
                            alarm_output: !1,
                            capture_numbers: 0,
                            record_stream: 0,
                            pre_record_time: 0,
                            record_time: 0
                        },
                        ratio_enum: [303, 403, 404, 504, 909, 1609, 2218],
                        rect_lists: [],
                        deployment_area: []
                    }
                }
            },
            watch: {
                motion_detection: {
                    handler: function(e, t) {
                        console.log("change")
                    },
                    deep: !0
                }
            },
            created: function() {
                this.fetchData()
            },
            mounted: function() {
                this.loadPlayer()
            },
            methods: {
                setmylist: function(e) {
                    this.$set(this.motion_detection, "rect_lists", e)
                },
                loadPlayer: function() {
                    var e = document.getElementById("wx-player");
                    e.onload = function() {
                        var t = e.contentWindow;
                        sessionStorage.getItem("sub_stream_video_codec");
                        t.postMessage({
                            id: 16,
                            stream: 1
                        }, "*")
                    }
                },
                onDelete: function() {
                    this.$set(this.motion_detection, "path", []),
                    this.$set(this.motion_detection, "deployment_area", [])
                },
                fetchData: function() {
                    var e = this;
                    Object(i["b"])("motion_detection").then((function(t) {
                        e.motion_detection = t.data.settings,
                        e.updateUi()
                    }
                    ))
                },
                updateData: function() {
                    Object(i["d"])({
                        type: "motion_detection",
                        settings: this.motion_detection
                    }).then((function(e) {
                        window.console.log("updated!")
                    }
                    ))
                },
                updateUi: function() {
                    var e, t;
                    this.motion_detection.rect_lists.length > 0 && (this.rect_lists = this.motion_detection.rect_lists,
                    e = this.rect_lists.length,
                    t = this.rect_lists[0].length),
                    this.current_type = 0,
                    this.cavcurrent_types = [];
                    for (var a = 0; a < this.motion_detection.ratio_enum.length; a++) {
                        var n = this.motion_detection.ratio_enum[a]
                          , o = Math.floor(n / 100)
                          , r = Math.floor(n % 100)
                          , i = {
                            label: "".concat(o, " × ").concat(r),
                            area: [o, r],
                            value: a
                        };
                        this.cavcurrent_types.push(i),
                        e === r && t === o && (this.current_type = a)
                    }
                },
                secondsToTime: function(e) {
                    return Object(i["c"])(e)
                },
                timeToSeconds: function(e) {
                    return 3600 * e.getHours() + 60 * e.getMinutes() + e.getSeconds()
                },
                voiceName: function(e) {
                    return "human_recognition.default"
                },
                removeRow: function(e) {
                    this.motion_detection.deployment_area.splice(e, 1)
                },
                onAddDefence: function() {
                    this.motion_detection.deployment_area.length >= 4 ? this.$message({
                        message: this.$t("human_recognition.max_deployment_area"),
                        type: "warning"
                    }) : this.dialogAddVisible = !0
                },
                onCancel: function() {
                    this.dialogAddVisible = !1
                },
                onConfirm: function() {
                    this.dialogAddVisible = !1;
                    var e = {
                        defence: 0,
                        withdrawal: 0,
                        days: 1,
                        repeat: 1,
                        voice: 0
                    };
                    e.days = this.current_deployment_area.days,
                    e.repeat = this.current_deployment_area.repeat,
                    e.defence = this.timeToSeconds(this.current_deployment_area.defence),
                    e.withdrawal = this.timeToSeconds(this.current_deployment_area.withdrawal),
                    this.motion_detection.deployment_area.push(e)
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData(),
                    window.console.log("reload!")
                },
                onDefault: function() {
                    var e = this;
                    Object(i["b"])("motion_detection_default").then((function(t) {
                        e.motion_detection = t.data.settings,
                        e.updateUi()
                    }
                    ))
                }
            }
        }
          , h = f
          , p = (a("121a"),
        Object(d["a"])(h, n, o, !1, null, "0793b68c", null));
        t["a"] = p.exports
    },
    "38cf": function(e, t, a) {
        var n = a("23e7")
          , o = a("1148");
        n({
            target: "String",
            proto: !0
        }, {
            repeat: o
        })
    },
    "3eba": function(e, t, a) {},
    4381: function(e, t, a) {
        "use strict";
        a("caad"),
        a("d3b7"),
        a("2532");
        var n = a("4360");
        function o(e, t) {
            var a = t.value
              , o = n["a"].getters && n["a"].getters.roles;
            if (!(a && a instanceof Array))
                throw new Error("need roles! Like v-permission=\"['admin','editor']\"");
            if (a.length > 0) {
                var r = a
                  , i = o.some((function(e) {
                    return r.includes(e)
                }
                ));
                i || e.parentNode && e.parentNode.removeChild(e)
            }
        }
        var r = {
            inserted: function(e, t) {
                o(e, t)
            },
            update: function(e, t) {
                o(e, t)
            }
        }
          , i = function(e) {
            e.directive("permission", r)
        };
        window.Vue && (window["permission"] = r,
        Vue.use(i)),
        r.install = i;
        t["a"] = r
    },
    "4ec9": function(e, t, a) {
        "use strict";
        var n = a("6d61")
          , o = a("6566");
        e.exports = n("Map", (function(e) {
            return function() {
                return e(this, arguments.length ? arguments[0] : void 0)
            }
        }
        ), o)
    },
    6566: function(e, t, a) {
        "use strict";
        var n = a("9bf2").f
          , o = a("7c73")
          , r = a("e2cc")
          , i = a("0366")
          , l = a("19aa")
          , s = a("2266")
          , c = a("7dd0")
          , u = a("2626")
          , d = a("83ab")
          , m = a("f183").fastKey
          , _ = a("69f3")
          , f = _.set
          , h = _.getterFor;
        e.exports = {
            getConstructor: function(e, t, a, c) {
                var u = e((function(e, n) {
                    l(e, u, t),
                    f(e, {
                        type: t,
                        index: o(null),
                        first: void 0,
                        last: void 0,
                        size: 0
                    }),
                    d || (e.size = 0),
                    void 0 != n && s(n, e[c], e, a)
                }
                ))
                  , _ = h(t)
                  , p = function(e, t, a) {
                    var n, o, r = _(e), i = v(e, t);
                    return i ? i.value = a : (r.last = i = {
                        index: o = m(t, !0),
                        key: t,
                        value: a,
                        previous: n = r.last,
                        next: void 0,
                        removed: !1
                    },
                    r.first || (r.first = i),
                    n && (n.next = i),
                    d ? r.size++ : e.size++,
                    "F" !== o && (r.index[o] = i)),
                    e
                }
                  , v = function(e, t) {
                    var a, n = _(e), o = m(t);
                    if ("F" !== o)
                        return n.index[o];
                    for (a = n.first; a; a = a.next)
                        if (a.key == t)
                            return a
                };
                return r(u.prototype, {
                    clear: function() {
                        var e = this
                          , t = _(e)
                          , a = t.index
                          , n = t.first;
                        while (n)
                            n.removed = !0,
                            n.previous && (n.previous = n.previous.next = void 0),
                            delete a[n.index],
                            n = n.next;
                        t.first = t.last = void 0,
                        d ? t.size = 0 : e.size = 0
                    },
                    delete: function(e) {
                        var t = this
                          , a = _(t)
                          , n = v(t, e);
                        if (n) {
                            var o = n.next
                              , r = n.previous;
                            delete a.index[n.index],
                            n.removed = !0,
                            r && (r.next = o),
                            o && (o.previous = r),
                            a.first == n && (a.first = o),
                            a.last == n && (a.last = r),
                            d ? a.size-- : t.size--
                        }
                        return !!n
                    },
                    forEach: function(e) {
                        var t, a = _(this), n = i(e, arguments.length > 1 ? arguments[1] : void 0, 3);
                        while (t = t ? t.next : a.first) {
                            n(t.value, t.key, this);
                            while (t && t.removed)
                                t = t.previous
                        }
                    },
                    has: function(e) {
                        return !!v(this, e)
                    }
                }),
                r(u.prototype, a ? {
                    get: function(e) {
                        var t = v(this, e);
                        return t && t.value
                    },
                    set: function(e, t) {
                        return p(this, 0 === e ? 0 : e, t)
                    }
                } : {
                    add: function(e) {
                        return p(this, e = 0 === e ? 0 : e, e)
                    }
                }),
                d && n(u.prototype, "size", {
                    get: function() {
                        return _(this).size
                    }
                }),
                u
            },
            setStrong: function(e, t, a) {
                var n = t + " Iterator"
                  , o = h(t)
                  , r = h(n);
                c(e, t, (function(e, t) {
                    f(this, {
                        type: n,
                        target: e,
                        state: o(e),
                        kind: t,
                        last: void 0
                    })
                }
                ), (function() {
                    var e = r(this)
                      , t = e.kind
                      , a = e.last;
                    while (a && a.removed)
                        a = a.previous;
                    return e.target && (e.last = a = a ? a.next : e.state.first) ? "keys" == t ? {
                        value: a.key,
                        done: !1
                    } : "values" == t ? {
                        value: a.value,
                        done: !1
                    } : {
                        value: [a.key, a.value],
                        done: !1
                    } : (e.target = void 0,
                    {
                        value: void 0,
                        done: !0
                    })
                }
                ), a ? "entries" : "values", !a, !0),
                u(t)
            }
        }
    },
    "6d61": function(e, t, a) {
        "use strict";
        var n = a("23e7")
          , o = a("da84")
          , r = a("94ca")
          , i = a("6eeb")
          , l = a("f183")
          , s = a("2266")
          , c = a("19aa")
          , u = a("861d")
          , d = a("d039")
          , m = a("1c7e")
          , _ = a("d44e")
          , f = a("7156");
        e.exports = function(e, t, a) {
            var h = -1 !== e.indexOf("Map")
              , p = -1 !== e.indexOf("Weak")
              , v = h ? "set" : "add"
              , b = o[e]
              , g = b && b.prototype
              , y = b
              , w = {}
              , x = function(e) {
                var t = g[e];
                i(g, e, "add" == e ? function(e) {
                    return t.call(this, 0 === e ? 0 : e),
                    this
                }
                : "delete" == e ? function(e) {
                    return !(p && !u(e)) && t.call(this, 0 === e ? 0 : e)
                }
                : "get" == e ? function(e) {
                    return p && !u(e) ? void 0 : t.call(this, 0 === e ? 0 : e)
                }
                : "has" == e ? function(e) {
                    return !(p && !u(e)) && t.call(this, 0 === e ? 0 : e)
                }
                : function(e, a) {
                    return t.call(this, 0 === e ? 0 : e, a),
                    this
                }
                )
            };
            if (r(e, "function" != typeof b || !(p || g.forEach && !d((function() {
                (new b).entries().next()
            }
            )))))
                y = a.getConstructor(t, e, h, v),
                l.REQUIRED = !0;
            else if (r(e, !0)) {
                var k = new y
                  , $ = k[v](p ? {} : -0, 1) != k
                  , D = d((function() {
                    k.has(1)
                }
                ))
                  , S = m((function(e) {
                    new b(e)
                }
                ))
                  , T = !p && d((function() {
                    var e = new b
                      , t = 5;
                    while (t--)
                        e[v](t, t);
                    return !e.has(-0)
                }
                ));
                S || (y = t((function(t, a) {
                    c(t, y, e);
                    var n = f(new b, t, y);
                    return void 0 != a && s(a, n[v], n, h),
                    n
                }
                )),
                y.prototype = g,
                g.constructor = y),
                (D || T) && (x("delete"),
                x("has"),
                h && x("get")),
                (T || $) && x(v),
                p && g.clear && delete g.clear
            }
            return w[e] = y,
            n({
                global: !0,
                forced: y != b
            }, w),
            _(y, e),
            p || a.setStrong(y, e, h),
            y
        }
    },
    "80ff": function(e, t, a) {
        "use strict";
        a("9929")
    },
    "81d5": function(e, t, a) {
        "use strict";
        var n = a("7b0b")
          , o = a("23cb")
          , r = a("50c4");
        e.exports = function(e) {
            var t = n(this)
              , a = r(t.length)
              , i = arguments.length
              , l = o(i > 1 ? arguments[1] : void 0, a)
              , s = i > 2 ? arguments[2] : void 0
              , c = void 0 === s ? a : o(s, a);
            while (c > l)
                t[l++] = e;
            return t
        }
    },
    "8f09": function(e, t, a) {
        "use strict";
        a("a51f")
    },
    9929: function(e, t, a) {},
    a51f: function(e, t, a) {},
    a70b: function(e, t, a) {
        "use strict";
        var n = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("div", {
                staticClass: "box-card customer_boxhead"
            }, [a("div", {
                staticClass: "media-img customer_vbox",
                staticStyle: {
                    height: "600px",
                    overflow: "hidden"
                }
            }, [a("iframe", {
                attrs: {
                    id: "wx-player",
                    width: "100%",
                    height: "100%",
                    src: e.html_path,
                    frameborder: "no"
                }
            }), e.occlusion_detection.enabled ? a("div", {
                ref: "cavbox",
                attrs: {
                    id: "osd_canvastext"
                }
            }) : e._e()]), a("div", {
                staticClass: "mt20"
            }, [a("el-switch", {
                attrs: {
                    "inactive-text": e.$t("occlusion_detection.enabled")
                },
                model: {
                    value: e.occlusion_detection.enabled,
                    callback: function(t) {
                        e.$set(e.occlusion_detection, "enabled", t)
                    },
                    expression: "occlusion_detection.enabled"
                }
            })], 1), e.occlusion_detection.enabled ? a("div", [a("el-form", {
                ref: "occlusion_detection",
                staticClass: "custom_form2 ",
                attrs: {
                    model: e.occlusion_detection,
                    "label-width": "auto",
                    "label-position": "top"
                }
            }, [a("el-row", {
                staticClass: "mt20",
                attrs: {
                    gutter: 40
                }
            }, [a("el-col", {
                attrs: {
                    sm: 5
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("occlusion_detection.sensitivity")
                }
            }, [a("el-slider", {
                model: {
                    value: e.occlusion_detection.sensitivity,
                    callback: function(t) {
                        e.$set(e.occlusion_detection, "sensitivity", t)
                    },
                    expression: "occlusion_detection.sensitivity"
                }
            })], 1)], 1), a("el-col", {
                attrs: {
                    sm: 2
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("occlusion_detection.flash_light")
                }
            }, [a("el-switch", {
                model: {
                    value: e.occlusion_detection.alarm_mode.flash_light,
                    callback: function(t) {
                        e.$set(e.occlusion_detection.alarm_mode, "flash_light", t)
                    },
                    expression: "occlusion_detection.alarm_mode.flash_light"
                }
            })], 1)], 1), a("el-col", {
                attrs: {
                    sm: 2
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("occlusion_detection.play_tone")
                }
            }, [a("el-switch", {
                model: {
                    value: e.occlusion_detection.alarm_mode.play_tone,
                    callback: function(t) {
                        e.$set(e.occlusion_detection.alarm_mode, "play_tone", t)
                    },
                    expression: "occlusion_detection.alarm_mode.play_tone"
                }
            })], 1)], 1), a("el-col", {
                attrs: {
                    sm: 2
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.signal_transfer")
                }
            }, [a("el-switch", {
                model: {
                    value: e.occlusion_detection.alarm_mode.alarm_output,
                    callback: function(t) {
                        e.$set(e.occlusion_detection.alarm_mode, "alarm_output", t)
                    },
                    expression: "occlusion_detection.alarm_mode.alarm_output"
                }
            })], 1)], 1), a("el-col", {
                attrs: {
                    sm: 3
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.Video_stream")
                }
            }, [a("el-select", {
                staticClass: "customer_row_title_sl",
                attrs: {
                    placeholder: "please select",
                    size: "small"
                },
                model: {
                    value: e.occlusion_detection.alarm_mode.record_stream,
                    callback: function(t) {
                        e.$set(e.occlusion_detection.alarm_mode, "record_stream", t)
                    },
                    expression: "occlusion_detection.alarm_mode.record_stream"
                }
            }, e._l(e.view_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1)], 1), a("el-col", {
                attrs: {
                    sm: 3
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.recording_recording")
                }
            }, [a("el-select", {
                staticClass: "customer_row_title_sl",
                attrs: {
                    placeholder: "please select",
                    size: "small"
                },
                model: {
                    value: e.occlusion_detection.alarm_mode.pre_record_time,
                    callback: function(t) {
                        e.$set(e.occlusion_detection.alarm_mode, "pre_record_time", t)
                    },
                    expression: "occlusion_detection.alarm_mode.pre_record_time"
                }
            }, e._l(e.pre_record_time_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1)], 1), a("el-col", {
                attrs: {
                    sm: 3
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.Recording_duration")
                }
            }, [a("el-select", {
                staticClass: "customer_row_title_sl",
                attrs: {
                    placeholder: "please select",
                    size: "small"
                },
                model: {
                    value: e.occlusion_detection.alarm_mode.record_time,
                    callback: function(t) {
                        e.$set(e.occlusion_detection.alarm_mode, "record_time", t)
                    },
                    expression: "occlusion_detection.alarm_mode.record_time"
                }
            }, e._l(e.record_time_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1)], 1), a("el-col", {
                attrs: {
                    sm: 3
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.Number_snaps")
                }
            }, [a("el-select", {
                staticClass: "customer_row_title_sl",
                attrs: {
                    placeholder: "please select",
                    size: "small"
                },
                model: {
                    value: e.occlusion_detection.alarm_mode.capture_numbers,
                    callback: function(t) {
                        e.$set(e.occlusion_detection.alarm_mode, "capture_numbers", t)
                    },
                    expression: "occlusion_detection.alarm_mode.capture_numbers"
                }
            }, e._l(e.capture_numbers_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1)], 1)], 1)], 1), a("el-divider"), a("el-table", {
                attrs: {
                    data: e.occlusion_detection.deployment_area,
                    align: "center",
                    border: ""
                }
            }, [a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.defence"),
                    prop: "defence"
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [e._v(" " + e._s(e.secondsToTime(t.row.defence)) + " ")]
                    }
                }], null, !1, 2850792123)
            }), a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.withdrawal"),
                    prop: "withdrawal"
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [e._v(" " + e._s(e.secondsToTime(t.row.withdrawal)) + " ")]
                    }
                }], null, !1, 4101690238)
            }), a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.days"),
                    prop: "days"
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [e._v(" " + e._s(e.$t(e.weekday_map.get(t.row.days))) + " ")]
                    }
                }], null, !1, 2062307993)
            }), a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.repeat"),
                    prop: "repeat"
                }
            }), a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.voice"),
                    prop: "voice"
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [e._v(" " + e._s(e.$t(e.voiceName(t.row.voice))) + " ")]
                    }
                }], null, !1, 135097930)
            }), a("el-table-column", {
                attrs: {
                    fixed: "right",
                    label: e.$t("user_management.operations")
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [a("el-button", {
                            attrs: {
                                link: "",
                                type: "danger",
                                size: "small"
                            },
                            on: {
                                click: function(a) {
                                    return a.preventDefault(),
                                    e.removeRow(t.$index)
                                }
                            }
                        }, [e._v(" " + e._s(e.$t("user_management.remove")) + " ")])]
                    }
                }], null, !1, 3153080129)
            })], 1), a("el-button", {
                staticClass: "mt-4",
                staticStyle: {
                    width: "100%"
                },
                on: {
                    click: e.onAddDefence
                }
            }, [e._v(" " + e._s(e.$t("user_management.add")) + " ")])], 1) : e._e(), a("el-divider"), a("div", {
                directives: [{
                    name: "permission",
                    rawName: "v-permission",
                    value: ["admin", "operator"],
                    expression: "['admin', 'operator']"
                }],
                attrs: {
                    align: "center"
                }
            }, [a("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: e.onSubmit
                }
            }, [e._v(e._s(e.$t("button.save")))]), a("el-button", {
                attrs: {
                    type: "danger"
                },
                on: {
                    click: e.onDelete
                }
            }, [e._v(e._s(e.$t("button.empty")))]), a("el-button", {
                on: {
                    click: e.onRefresh
                }
            }, [e._v(e._s(e.$t("button.refresh")))]), a("el-button", {
                attrs: {
                    type: "warning"
                },
                on: {
                    click: e.onDefault
                }
            }, [e._v(e._s(e.$t("button.default")))])], 1), a("el-dialog", {
                attrs: {
                    visible: e.dialogAddVisible,
                    title: e.$t("user_management.add")
                },
                on: {
                    "update:visible": function(t) {
                        e.dialogAddVisible = t
                    }
                },
                scopedSlots: e._u([{
                    key: "footer",
                    fn: function() {
                        return [a("span", {
                            staticClass: "dialog-footer"
                        }, [a("el-button", {
                            on: {
                                click: e.onCancel
                            }
                        }, [e._v(" " + e._s(e.$t("user_management.cancel")) + " ")]), a("el-button", {
                            attrs: {
                                type: "primary"
                            },
                            on: {
                                click: e.onConfirm
                            }
                        }, [e._v(" " + e._s(e.$t("user_management.confirm")) + " ")])], 1)]
                    },
                    proxy: !0
                }])
            }, [a("el-form", {
                ref: "current_deployment_area",
                attrs: {
                    model: e.current_deployment_area,
                    "label-width": "120px",
                    "label-position": "left"
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.days")
                }
            }, [a("el-select", {
                model: {
                    value: e.current_deployment_area.days,
                    callback: function(t) {
                        e.$set(e.current_deployment_area, "days", t)
                    },
                    expression: "current_deployment_area.days"
                }
            }, e._l(e.weekday_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1), a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.repeat")
                }
            }, [a("el-select", {
                model: {
                    value: e.current_deployment_area.repeat,
                    callback: function(t) {
                        e.$set(e.current_deployment_area, "repeat", t)
                    },
                    expression: "current_deployment_area.repeat"
                }
            }, e._l(e.repeat_options, (function(e) {
                return a("el-option", {
                    key: e,
                    attrs: {
                        value: e
                    }
                })
            }
            )), 1)], 1), a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.defence")
                }
            }, [a("el-time-picker", {
                attrs: {
                    size: "small",
                    "picker-options": {
                        selectableRange: "00:00:00 - 23:59:59"
                    }
                },
                model: {
                    value: e.current_deployment_area.defence,
                    callback: function(t) {
                        e.$set(e.current_deployment_area, "defence", t)
                    },
                    expression: "current_deployment_area.defence"
                }
            })], 1), a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.withdrawal")
                }
            }, [a("el-time-picker", {
                attrs: {
                    size: "small",
                    "picker-options": {
                        selectableRange: "00:00:01 - 23:59:59"
                    }
                },
                model: {
                    value: e.current_deployment_area.withdrawal,
                    callback: function(t) {
                        e.$set(e.current_deployment_area, "withdrawal", t)
                    },
                    expression: "current_deployment_area.withdrawal"
                }
            })], 1)], 1)], 1)], 1)
        }
          , o = []
          , r = (a("a434"),
        a("4ec9"),
        a("d3b7"),
        a("3ca3"),
        a("38cf"),
        a("ddb0"),
        a("4381"))
          , i = a("ed5f")
          , l = a("e8e8")
          , s = {
            props: ["view_options", "record_time_options", "pre_record_time_options", "capture_numbers_options"],
            components: {
                CanvasRect: l["a"]
            },
            directives: {
                permission: r["a"]
            },
            data: function() {
                return {
                    html_path: "/static/player/index.html",
                    occlusion_detection: {
                        enabled: !1,
                        sensitivity: null,
                        alarm_mode: {
                            flash_light: null,
                            play_tone: null,
                            alarm_output: !1,
                            capture_numbers: 0,
                            record_stream: 0,
                            pre_record_time: 0,
                            record_time: 0
                        },
                        deployment_area: [],
                        path: []
                    },
                    dialogAddVisible: !1,
                    current_deployment_area: {
                        area: {
                            id: 0
                        },
                        defence: null,
                        withdrawal: null,
                        days: 1,
                        repeat: 1
                    },
                    areaopionts: [{
                        label: "area.red",
                        value: 0,
                        color: "red"
                    }],
                    repeat_options: [1, 2, 3],
                    weekday_map: new Map([[i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI, "human_recognition.m_f"], [i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI | i["a"].SAT, "human_recognition.m_s"], [i["a"].SAT | i["a"].SUN, "human_recognition.sat_sun"], [i["a"].SUN, "human_recognition.sun"], [i["a"].SUN | i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI | i["a"].SAT, "human_recognition.everyday"]]),
                    weekday_options: [{
                        label: "human_recognition.m_f",
                        value: i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI
                    }, {
                        label: "human_recognition.m_s",
                        value: i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI | i["a"].SAT
                    }, {
                        label: "human_recognition.sat_sun",
                        value: i["a"].SAT | i["a"].SUN
                    }, {
                        label: "human_recognition.sun",
                        value: i["a"].SUN
                    }, {
                        label: "human_recognition.everyday",
                        value: i["a"].SUN | i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI | i["a"].SAT
                    }]
                }
            },
            created: function() {
                this.fetchData()
            },
            mounted: function() {
                this.loadPlayer()
            },
            methods: {
                update_layers: function(e) {
                    this.occlusion_detection.path = e[0]
                },
                loadPlayer: function() {
                    var e = document.getElementById("wx-player");
                    e.onload = function() {
                        var t = e.contentWindow;
                        sessionStorage.getItem("sub_stream_video_codec");
                        t.postMessage({
                            id: 16,
                            stream: 1
                        }, "*")
                    }
                },
                onDelete: function() {
                    this.$set(this.occlusion_detection, "deployment_area", [])
                },
                fetchData: function() {
                    var e = this;
                    Object(i["b"])("occlusion_detection").then((function(t) {
                        e.occlusion_detection = t.data.settings,
                        window.console.log(e.occlusion_detection)
                    }
                    ))
                },
                updateData: function() {
                    Object(i["d"])({
                        type: "occlusion_detection",
                        settings: this.occlusion_detection
                    }).then((function(e) {
                        window.console.log("updated!")
                    }
                    ))
                },
                secondsToTime: function(e) {
                    return Object(i["c"])(e)
                },
                timeToSeconds: function(e) {
                    return 3600 * e.getHours() + 60 * e.getMinutes() + e.getSeconds()
                },
                voiceName: function(e) {
                    return "human_recognition.default"
                },
                removeRow: function(e) {
                    this.occlusion_detection.deployment_area.splice(e, 1)
                },
                onAddDefence: function() {
                    this.occlusion_detection.deployment_area.length >= 4 ? this.$message({
                        message: this.$t("human_recognition.max_deployment_area"),
                        type: "warning"
                    }) : this.dialogAddVisible = !0
                },
                onCancel: function() {
                    this.dialogAddVisible = !1
                },
                onConfirm: function() {
                    this.dialogAddVisible = !1;
                    var e = {
                        defence: 0,
                        withdrawal: 0,
                        days: 1,
                        repeat: 1,
                        voice: 0
                    };
                    e.days = this.current_deployment_area.days,
                    e.repeat = this.current_deployment_area.repeat,
                    e.defence = this.timeToSeconds(this.current_deployment_area.defence),
                    e.withdrawal = this.timeToSeconds(this.current_deployment_area.withdrawal),
                    this.occlusion_detection.deployment_area.push(e)
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData(),
                    window.console.log("reload!")
                },
                onDefault: function() {
                    var e = this;
                    Object(i["b"])("occlusion_detection_default").then((function(t) {
                        e.occlusion_detection = t.data.settings,
                        window.console.log(e.occlusion_detection)
                    }
                    ))
                }
            }
        }
          , c = s
          , u = (a("8f09"),
        a("2877"))
          , d = Object(u["a"])(c, n, o, !1, null, "22001938", null);
        t["a"] = d.exports
    },
    a77e: function(e, t, a) {
        "use strict";
        a("3eba")
    },
    bb2f: function(e, t, a) {
        var n = a("d039");
        e.exports = !n((function() {
            return Object.isExtensible(Object.preventExtensions({}))
        }
        ))
    },
    c630: function(e, t, a) {
        "use strict";
        var n = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("div", {
                staticClass: "box-card customer_boxhead"
            }, [a("div", {
                staticClass: "media-img customer_vbox",
                staticStyle: {
                    height: "600px",
                    overflow: "hidden"
                }
            }, [a("iframe", {
                attrs: {
                    id: "wx-player",
                    width: "100%",
                    height: "100%",
                    src: e.html_path,
                    frameborder: "no"
                }
            }), e.human_recognition.enabled ? a("div", {
                ref: "cavbox",
                attrs: {
                    id: "osd_canvastext"
                }
            }, [e.human_recognition.enabled ? a("CanvasRect", {
                attrs: {
                    layers: e.human_recognition.path,
                    colors: e.areaopionts
                },
                on: {
                    "update:layers": function(t) {
                        return e.$set(e.human_recognition, "path", t)
                    },
                    get_layers: function(t) {
                        return e.update_layers(arguments)
                    }
                }
            }) : e._e()], 1) : e._e()]), a("div", [a("br"), a("el-switch", {
                attrs: {
                    "inactive-text": e.$t("human_recognition.enabled")
                },
                model: {
                    value: e.human_recognition.enabled,
                    callback: function(t) {
                        e.$set(e.human_recognition, "enabled", t)
                    },
                    expression: "human_recognition.enabled"
                }
            })], 1), e.human_recognition.enabled ? a("div", [a("div", {
                staticClass: "mt20"
            }, [a("el-alert", {
                attrs: {
                    title: e.$t("human_recognition.tips"),
                    type: "info"
                }
            })], 1), a("el-form", {
                ref: "human_recognition",
                staticClass: "custom_form2 ",
                attrs: {
                    model: e.human_recognition,
                    "label-width": "auto",
                    "label-position": "top"
                }
            }, [a("el-row", {
                staticClass: "mt20",
                attrs: {
                    gutter: 40
                }
            }, [a("el-col", {
                attrs: {
                    sm: 5
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.sensitivity")
                }
            }, [a("el-slider", {
                model: {
                    value: e.human_recognition.sensitivity,
                    callback: function(t) {
                        e.$set(e.human_recognition, "sensitivity", t)
                    },
                    expression: "human_recognition.sensitivity"
                }
            })], 1)], 1), a("el-col", {
                attrs: {
                    sm: 2
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.flash_light")
                }
            }, [a("el-switch", {
                model: {
                    value: e.human_recognition.alarm_mode.flash_light,
                    callback: function(t) {
                        e.$set(e.human_recognition.alarm_mode, "flash_light", t)
                    },
                    expression: "human_recognition.alarm_mode.flash_light"
                }
            })], 1)], 1), a("el-col", {
                attrs: {
                    sm: 2
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.play_tone")
                }
            }, [a("el-switch", {
                model: {
                    value: e.human_recognition.alarm_mode.play_tone,
                    callback: function(t) {
                        e.$set(e.human_recognition.alarm_mode, "play_tone", t)
                    },
                    expression: "human_recognition.alarm_mode.play_tone"
                }
            })], 1)], 1), a("el-col", {
                attrs: {
                    sm: 2
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.signal_transfer")
                }
            }, [a("el-switch", {
                model: {
                    value: e.human_recognition.alarm_mode.alarm_output,
                    callback: function(t) {
                        e.$set(e.human_recognition.alarm_mode, "alarm_output", t)
                    },
                    expression: "human_recognition.alarm_mode.alarm_output"
                }
            })], 1)], 1), a("el-col", {
                attrs: {
                    sm: 3
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.Video_stream")
                }
            }, [a("el-select", {
                staticClass: "customer_row_title_sl",
                attrs: {
                    placeholder: "please select",
                    size: "small"
                },
                model: {
                    value: e.human_recognition.alarm_mode.record_stream,
                    callback: function(t) {
                        e.$set(e.human_recognition.alarm_mode, "record_stream", t)
                    },
                    expression: "human_recognition.alarm_mode.record_stream"
                }
            }, e._l(e.view_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1)], 1), a("el-col", {
                attrs: {
                    sm: 3
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.recording_recording")
                }
            }, [a("el-select", {
                staticClass: "customer_row_title_sl",
                attrs: {
                    placeholder: "please select",
                    size: "small"
                },
                model: {
                    value: e.human_recognition.alarm_mode.pre_record_time,
                    callback: function(t) {
                        e.$set(e.human_recognition.alarm_mode, "pre_record_time", t)
                    },
                    expression: "human_recognition.alarm_mode.pre_record_time"
                }
            }, e._l(e.pre_record_time_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1)], 1), a("el-col", {
                attrs: {
                    sm: 3
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.Recording_duration")
                }
            }, [a("el-select", {
                staticClass: "customer_row_title_sl",
                attrs: {
                    placeholder: "please select",
                    size: "small"
                },
                model: {
                    value: e.human_recognition.alarm_mode.record_time,
                    callback: function(t) {
                        e.$set(e.human_recognition.alarm_mode, "record_time", t)
                    },
                    expression: "human_recognition.alarm_mode.record_time"
                }
            }, e._l(e.record_time_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1)], 1), a("el-col", {
                attrs: {
                    sm: 3
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("motion_detection.Number_snaps")
                }
            }, [a("el-select", {
                staticClass: "customer_row_title_sl",
                attrs: {
                    placeholder: "please select",
                    size: "small"
                },
                model: {
                    value: e.human_recognition.alarm_mode.capture_numbers,
                    callback: function(t) {
                        e.$set(e.human_recognition.alarm_mode, "capture_numbers", t)
                    },
                    expression: "human_recognition.alarm_mode.capture_numbers"
                }
            }, e._l(e.capture_numbers_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1)], 1)], 1)], 1), a("el-divider"), a("el-table", {
                attrs: {
                    data: e.human_recognition.deployment_area,
                    align: "center",
                    border: ""
                }
            }, [a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.area"),
                    prop: "area"
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [e._v(" " + e._s(e.$t(e.areaName(t.row.area))) + " ")]
                    }
                }], null, !1, 998055050)
            }), a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.defence"),
                    prop: "defence"
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [e._v(" " + e._s(e.secondsToTime(t.row.defence)) + " ")]
                    }
                }], null, !1, 2850792123)
            }), a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.withdrawal"),
                    prop: "withdrawal"
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [e._v(" " + e._s(e.secondsToTime(t.row.withdrawal)) + " ")]
                    }
                }], null, !1, 4101690238)
            }), a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.days"),
                    prop: "days"
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [e._v(" " + e._s(e.$t(e.weekday_map.get(t.row.days))) + " ")]
                    }
                }], null, !1, 2062307993)
            }), a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.repeat"),
                    prop: "repeat"
                }
            }), a("el-table-column", {
                attrs: {
                    label: e.$t("human_recognition.voice"),
                    prop: "voice"
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [e._v(" " + e._s(e.$t(e.voiceName(t.row.voice))) + " ")]
                    }
                }], null, !1, 135097930)
            }), a("el-table-column", {
                attrs: {
                    fixed: "right",
                    label: e.$t("user_management.operations")
                },
                scopedSlots: e._u([{
                    key: "default",
                    fn: function(t) {
                        return [a("el-button", {
                            attrs: {
                                link: "",
                                type: "danger",
                                size: "small"
                            },
                            on: {
                                click: function(a) {
                                    return a.preventDefault(),
                                    e.removeRow(t.$index)
                                }
                            }
                        }, [e._v(" " + e._s(e.$t("user_management.remove")) + " ")])]
                    }
                }], null, !1, 3153080129)
            })], 1), a("el-button", {
                staticClass: "mt-4",
                staticStyle: {
                    width: "100%"
                },
                on: {
                    click: e.onAddDefence
                }
            }, [e._v(" " + e._s(e.$t("user_management.add")) + " ")])], 1) : e._e(), a("el-divider"), a("div", {
                directives: [{
                    name: "permission",
                    rawName: "v-permission",
                    value: ["admin", "operator"],
                    expression: "['admin', 'operator']"
                }],
                staticClass: "mt20",
                attrs: {
                    align: "center"
                }
            }, [a("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: e.onSubmit
                }
            }, [e._v(e._s(e.$t("button.save")))]), a("el-button", {
                attrs: {
                    type: "danger"
                },
                on: {
                    click: e.onDelete
                }
            }, [e._v(e._s(e.$t("button.empty")))]), a("el-button", {
                on: {
                    click: e.onRefresh
                }
            }, [e._v(e._s(e.$t("button.refresh")))]), a("el-button", {
                attrs: {
                    type: "warning"
                },
                on: {
                    click: e.onDefault
                }
            }, [e._v(e._s(e.$t("button.default")))])], 1), a("el-dialog", {
                attrs: {
                    visible: e.dialogAddVisible,
                    title: e.$t("user_management.add")
                },
                on: {
                    "update:visible": function(t) {
                        e.dialogAddVisible = t
                    }
                },
                scopedSlots: e._u([{
                    key: "footer",
                    fn: function() {
                        return [a("span", {
                            staticClass: "dialog-footer"
                        }, [a("el-button", {
                            on: {
                                click: e.onCancel
                            }
                        }, [e._v(" " + e._s(e.$t("user_management.cancel")) + " ")]), a("el-button", {
                            attrs: {
                                type: "primary"
                            },
                            on: {
                                click: e.onConfirm
                            }
                        }, [e._v(" " + e._s(e.$t("user_management.confirm")) + " ")])], 1)]
                    },
                    proxy: !0
                }])
            }, [a("el-form", {
                ref: "current_deployment_area",
                attrs: {
                    model: e.current_deployment_area,
                    "label-width": "120px",
                    "label-position": "left"
                }
            }, [a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.area")
                }
            }, [a("el-select", {
                attrs: {
                    size: "small"
                },
                model: {
                    value: e.current_deployment_area.area.id,
                    callback: function(t) {
                        e.$set(e.current_deployment_area.area, "id", t)
                    },
                    expression: "current_deployment_area.area.id"
                }
            }, e._l(e.areaopionts, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: t.value + " - " + e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1), a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.days")
                }
            }, [a("el-select", {
                model: {
                    value: e.current_deployment_area.days,
                    callback: function(t) {
                        e.$set(e.current_deployment_area, "days", t)
                    },
                    expression: "current_deployment_area.days"
                }
            }, e._l(e.weekday_options, (function(t) {
                return a("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1), a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.repeat")
                }
            }, [a("el-select", {
                model: {
                    value: e.current_deployment_area.repeat,
                    callback: function(t) {
                        e.$set(e.current_deployment_area, "repeat", t)
                    },
                    expression: "current_deployment_area.repeat"
                }
            }, e._l(e.repeat_options, (function(e) {
                return a("el-option", {
                    key: e,
                    attrs: {
                        value: e
                    }
                })
            }
            )), 1)], 1), a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.defence")
                }
            }, [a("el-time-picker", {
                attrs: {
                    size: "small",
                    "picker-options": {
                        selectableRange: "00:00:00 - 23:59:59"
                    }
                },
                model: {
                    value: e.current_deployment_area.defence,
                    callback: function(t) {
                        e.$set(e.current_deployment_area, "defence", t)
                    },
                    expression: "current_deployment_area.defence"
                }
            })], 1), a("el-form-item", {
                attrs: {
                    label: e.$t("human_recognition.withdrawal")
                }
            }, [a("el-time-picker", {
                attrs: {
                    size: "small",
                    "picker-options": {
                        selectableRange: "00:00:01 - 23:59:59"
                    }
                },
                model: {
                    value: e.current_deployment_area.withdrawal,
                    callback: function(t) {
                        e.$set(e.current_deployment_area, "withdrawal", t)
                    },
                    expression: "current_deployment_area.withdrawal"
                }
            })], 1)], 1)], 1)], 1)
        }
          , o = []
          , r = (a("a434"),
        a("e9c4"),
        a("4ec9"),
        a("b64b"),
        a("d3b7"),
        a("3ca3"),
        a("38cf"),
        a("ddb0"),
        a("4381"))
          , i = a("ed5f")
          , l = a("e8e8")
          , s = a("61f7")
          , c = {
            props: ["view_options", "record_time_options", "pre_record_time_options", "capture_numbers_options"],
            components: {
                CanvasRect: l["a"]
            },
            directives: {
                permission: r["a"]
            },
            data: function() {
                return {
                    html_path: "/static/player/index.html",
                    human_recognition: {
                        enabled: !0,
                        sensitivity: 0,
                        alarm_mode: {
                            flash_light: !1,
                            play_tone: !1,
                            alarm_output: !1,
                            capture_numbers: 0,
                            record_stream: 0,
                            pre_record_time: 0,
                            record_time: 0
                        },
                        deployment_area: [],
                        path: []
                    },
                    prev_data: null,
                    dialogAddVisible: !1,
                    current_deployment_area: {
                        area: {
                            id: 0
                        },
                        defence: null,
                        withdrawal: null,
                        days: 1,
                        repeat: 1
                    },
                    areaopionts: [{
                        label: "area.red",
                        value: 0,
                        color: "red"
                    }, {
                        label: "area.green",
                        value: 1,
                        color: "green"
                    }, {
                        label: "area.yellow",
                        value: 2,
                        color: "yellow"
                    }, {
                        label: "area.blue",
                        value: 3,
                        color: "blue"
                    }],
                    repeat_options: [1, 2, 3],
                    weekday_map: new Map([[i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI, "human_recognition.m_f"], [i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI | i["a"].SAT, "human_recognition.m_s"], [i["a"].SAT | i["a"].SUN, "human_recognition.sat_sun"], [i["a"].SUN, "human_recognition.sun"], [i["a"].SUN | i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI | i["a"].SAT, "human_recognition.everyday"]]),
                    weekday_options: [{
                        label: "human_recognition.m_f",
                        value: i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI
                    }, {
                        label: "human_recognition.m_s",
                        value: i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI | i["a"].SAT
                    }, {
                        label: "human_recognition.sat_sun",
                        value: i["a"].SAT | i["a"].SUN
                    }, {
                        label: "human_recognition.sun",
                        value: i["a"].SUN
                    }, {
                        label: "human_recognition.everyday",
                        value: i["a"].SUN | i["a"].MON | i["a"].TUE | i["a"].WED | i["a"].THU | i["a"].FRI | i["a"].SAT
                    }]
                }
            },
            created: function() {
                this.fetchData()
            },
            mounted: function() {
                this.loadPlayer()
            },
            methods: {
                update_layers: function(e) {
                    this.human_recognition.path = e[0]
                },
                loadPlayer: function() {
                    var e = document.getElementById("wx-player");
                    e.onload = function() {
                        var t = e.contentWindow;
                        t.postMessage({
                            id: 16,
                            stream: 1
                        }, "*")
                    }
                },
                onDelete: function() {
                    this.$set(this.human_recognition, "path", []),
                    this.$set(this.human_recognition, "deployment_area", [])
                },
                fetchData: function() {
                    var e = this;
                    Object(i["b"])("human_recognition").then((function(t) {
                        e.human_recognition = t.data.settings,
                        window.console.log(e.human_recognition),
                        e.prev_data = JSON.parse(JSON.stringify(e.human_recognition))
                    }
                    ))
                },
                updateData: function() {
                    var e = this;
                    Object(i["d"])({
                        type: "human_recognition",
                        settings: this.human_recognition
                    }).then((function(t) {
                        window.console.log("updated!"),
                        e.isNeedRestart() && Object(s["a"])(15)
                    }
                    ))
                },
                isNeedRestart: function() {
                    return this.human_recognition.enabled !== this.prev_data.enabled
                },
                secondsToTime: function(e) {
                    return Object(i["c"])(e)
                },
                timeToSeconds: function(e) {
                    return 3600 * e.getHours() + 60 * e.getMinutes() + e.getSeconds()
                },
                voiceName: function(e) {
                    return "human_recognition.default"
                },
                areaName: function(e) {
                    for (var t = 0; t < this.areaopionts.length; t++) {
                        var a = this.areaopionts[t];
                        if (a.value == e)
                            return a.label
                    }
                    return ""
                },
                removeRow: function(e) {
                    this.human_recognition.deployment_area.splice(e, 1)
                },
                onAddDefence: function() {
                    this.human_recognition.deployment_area.length >= 4 ? this.$message({
                        message: this.$t("human_recognition.max_deployment_area"),
                        type: "warning"
                    }) : this.dialogAddVisible = !0
                },
                onCancel: function() {
                    this.dialogAddVisible = !1
                },
                onConfirm: function() {
                    this.dialogAddVisible = !1;
                    var e = {
                        area: 0,
                        defence: 0,
                        withdrawal: 0,
                        days: 1,
                        repeat: 1,
                        voice: 0
                    };
                    e.area = this.current_deployment_area.area.id,
                    e.days = this.current_deployment_area.days,
                    e.repeat = this.current_deployment_area.repeat,
                    e.defence = this.timeToSeconds(this.current_deployment_area.defence),
                    e.withdrawal = this.timeToSeconds(this.current_deployment_area.withdrawal),
                    this.human_recognition.deployment_area.push(e)
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData(),
                    window.console.log("reload!")
                },
                onDefault: function() {
                    var e = this;
                    Object(i["b"])("human_recognition_default").then((function(t) {
                        e.human_recognition = t.data.settings,
                        window.console.log(e.human_recognition)
                    }
                    ))
                }
            }
        }
          , u = c
          , d = (a("0e7b"),
        a("2877"))
          , m = Object(d["a"])(u, n, o, !1, null, "21b881d3", null);
        t["a"] = m.exports
    },
    cb29: function(e, t, a) {
        var n = a("23e7")
          , o = a("81d5")
          , r = a("44d2");
        n({
            target: "Array",
            proto: !0
        }, {
            fill: o
        }),
        r("fill")
    },
    e8e8: function(e, t, a) {
        "use strict";
        var n = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("canvas", {
                ref: "rectCanvas",
                attrs: {
                    id: "canvasrect"
                }
            })
        }
          , o = []
          , r = (a("cb29"),
        a("a434"),
        a("d3b7"),
        a("159b"),
        {
            props: ["layers", "current_id", "colors"],
            data: function() {
                return {
                    markList: this.layers,
                    mycolor: this.colors
                }
            },
            watch: {
                layers: {
                    handler: function(e, t) {
                        console.log("son change"),
                        this.markList = e,
                        0 === e.length && (this.markList = [],
                        this.initCanvas())
                    },
                    deep: !0
                }
            },
            created: function() {
                var e = this;
                e.initCanvas()
            },
            mounted: function() {
                var e = this;
                setTimeout((function() {
                    e.initCanvas()
                }
                ), 300)
            },
            methods: {
                initCanvas: function() {
                    var e = this;
                    this.$nextTick((function() {
                        var t = e
                          , a = t.markList
                          , n = t.$refs.rectCanvas;
                        n.width = n.clientWidth,
                        n.height = n.clientHeight;
                        var o = n.getContext("2d");
                        n.style.cursor = "crosshair",
                        o.clearRect(0, 0, n.width, n.height);
                        for (var r = [], i = 0; i < a.length; i++) {
                            var l = {};
                            l = {
                                x: e.toDecimal(a[i].x * n.width / 100),
                                y: e.toDecimal(a[i].y * n.height / 100),
                                w: e.toDecimal(a[i].width * n.width / 100),
                                h: e.toDecimal(a[i].height * n.height / 100),
                                enabled: a[i].enabled,
                                color: a[i].color,
                                label: i
                            },
                            r.push(l)
                        }
                        t.reDraw(n, o, r, null),
                        t.draw(n, r)
                    }
                    ))
                },
                draw: function(e, t, a) {
                    var n = e.getContext("2d");
                    n.lineWidth = 2;
                    var o = 0
                      , r = 0
                      , i = this;
                    e.onmousemove = function(l) {
                        var s;
                        if (o = l.offsetX,
                        r = l.offsetY,
                        0 === t.length && i.newDraw(e, n, t),
                        void 0 === a)
                            t.forEach((function(a, l, c) {
                                a.w > 0 && a.h > 0 && o > a.x && o < a.x + a.w && r > a.y && r < a.y + a.h && (s = l,
                                i.judgeDraw(e, n, t, s)),
                                a.w < 0 && a.h > 0 && o < a.x && o > a.x + a.w && r > a.y && r < a.y + a.h && (s = l,
                                i.judgeDraw(e, n, t, s)),
                                a.w > 0 && a.h < 0 && o > a.x && o < a.x + a.w && r < a.y && r > a.y + a.h && (s = l,
                                i.judgeDraw(e, n, t, s)),
                                a.w < 0 && a.h < 0 && o < a.x && o > a.x + a.w && r < a.y && r > a.y + a.h && (s = l,
                                i.judgeDraw(e, n, t, s)),
                                void 0 === s && (t.length < i.mycolor.length ? i.newDraw(e, n, t) : e.onmousedown = function(e) {
                                    return !1
                                }
                                )
                            }
                            ));
                        else
                            for (var c = 0; c < t.length; c++) {
                                var u = t[c];
                                if (o < u.x + 5 && o > u.x - 5 && r < u.y + 5 && r > u.y - 5) {
                                    if (c === a) {
                                        i.changeDraw(e, n, t, a, 1);
                                        break
                                    }
                                } else if (o < u.x + u.w + 5 && o > u.x + u.w - 5 && r < u.y + 5 && r > u.y - 5) {
                                    if (c === a) {
                                        i.changeDraw(e, n, t, a, 2);
                                        break
                                    }
                                } else if (o < u.x + 5 && o > u.x - 5 && r < u.y + u.h + 5 && r > u.y + u.h - 5) {
                                    if (c === a) {
                                        i.changeDraw(e, n, t, a, 3);
                                        break
                                    }
                                } else if (o < u.x + u.w + 5 && o > u.x + u.w - 5 && r < u.y + u.h + 5 && r > u.y + u.h - 5) {
                                    if (c === a) {
                                        i.changeDraw(e, n, t, a, 4);
                                        break
                                    }
                                } else {
                                    if (u.w > 0 && u.h > 0 && o > u.x && o < u.x + u.w && r > u.y && r < u.y + u.h) {
                                        s = c,
                                        i.judgeDraw(e, n, t, c);
                                        break
                                    }
                                    if (u.w < 0 && u.h > 0 && o < u.x && o > u.x + u.w && r > u.y && r < u.y + u.h) {
                                        s = c,
                                        i.judgeDraw(e, n, t, c);
                                        break
                                    }
                                    if (u.w > 0 && u.h < 0 && o > u.x && o < u.x + u.w && r < u.y && r > u.y + u.h) {
                                        s = c,
                                        i.judgeDraw(e, n, t, c);
                                        break
                                    }
                                    if (u.w < 0 && u.h < 0 && o < u.x && o > u.x + u.w && r < u.y && r > u.y + u.h) {
                                        s = c,
                                        i.judgeDraw(e, n, t, c);
                                        break
                                    }
                                    void 0 === s && (t.length < i.mycolor.length ? i.newDraw(e, n, t) : e.onmousedown = function(e) {
                                        return !1
                                    }
                                    )
                                }
                            }
                        e.onmouseout = function(n) {
                            void 0 !== a && i.draw(e, t, a)
                        }
                    }
                },
                changeDraw: function(e, t, a, n, o) {
                    e.style.cursor = "pointer";
                    var r = a[n]
                      , i = this;
                    e.onmousedown = function(l) {
                        var s = l.offsetX
                          , c = l.offsetY;
                        e.onmousemove = function(l) {
                            var u = {};
                            switch (o) {
                            case 1:
                                u = {
                                    x: l.offsetX,
                                    y: l.offsetY,
                                    w: r.w - (l.offsetX - s),
                                    h: r.h - (l.offsetY - c),
                                    enabled: r.enabled,
                                    label: r.label
                                };
                                break;
                            case 2:
                                u = {
                                    x: r.x,
                                    y: r.y + (l.offsetY - c),
                                    w: r.w + (l.offsetX - s),
                                    h: r.h - (l.offsetY - c),
                                    enabled: r.enabled,
                                    label: r.label
                                };
                                break;
                            case 3:
                                u = {
                                    x: r.x + (l.offsetX - s),
                                    y: r.y,
                                    w: r.w - (l.offsetX - s),
                                    h: r.h + (l.offsetY - c),
                                    enabled: r.enabled,
                                    label: r.label
                                };
                                break;
                            case 4:
                                u = {
                                    x: r.x,
                                    y: r.y,
                                    w: r.w + (l.offsetX - s),
                                    h: r.h + (l.offsetY - c),
                                    enabled: r.enabled,
                                    label: r.label
                                };
                                break
                            }
                            a.splice(n, 1, u),
                            i.reDraw(e, t, a, n)
                        }
                        ,
                        e.onmouseout = function(n) {
                            i.reDraw(e, t, a),
                            i.draw(e, a)
                        }
                        ,
                        i.delDraw(e, t, a, n)
                    }
                },
                newDraw: function(e, t, a) {
                    e.style.cursor = "crosshair";
                    var n = !1
                      , o = 0
                      , r = 0
                      , i = this
                      , l = this.current_id + 1
                      , s = a.length;
                    a.length < i.mycolor.length ? e.onmousedown = function(c) {
                        n = !0,
                        o = c.offsetX,
                        r = c.offsetY,
                        i.delDraw(e, t, a, null),
                        e.onmousemove = function(l) {
                            n && (i.reDraw(e, t, a),
                            t.beginPath(),
                            t.setLineDash([8, 4]),
                            t.rect(o, r, l.offsetX - o, l.offsetY - r),
                            t.stroke())
                        }
                        ,
                        e.onmouseup = function(l) {
                            var c;
                            n && Math.abs(l.offsetX - o) > 10 && Math.abs(l.offsetY - r) > 10 ? (c = l.offsetY - r < 0 && l.offsetX - o < 0 ? {
                                x: l.offsetX,
                                y: l.offsetY,
                                w: Math.abs(l.offsetX - o),
                                h: Math.abs(l.offsetY - r),
                                enabled: !0,
                                label: s
                            } : l.offsetY - r > 0 && l.offsetX - o < 0 ? {
                                x: l.offsetX,
                                y: r,
                                w: Math.abs(l.offsetX - o),
                                h: Math.abs(l.offsetY - r),
                                enabled: !0,
                                label: s
                            } : l.offsetY - r < 0 && l.offsetX - o > 0 ? {
                                x: o,
                                y: l.offsetY,
                                w: Math.abs(l.offsetX - o),
                                h: Math.abs(l.offsetY - r),
                                enabled: !0,
                                label: s
                            } : {
                                x: o,
                                y: r,
                                w: l.offsetX - o,
                                h: l.offsetY - r,
                                enabled: !0,
                                label: s
                            },
                            a.push(c),
                            i.reDraw(e, t, a),
                            n = !1,
                            i.draw(e, a)) : (i.reDraw(e, t, a),
                            n = !1,
                            i.draw(e, a));
                            i.changelist(e, a)
                        }
                        ,
                        e.onmouseout = function(s) {
                            if (n && Math.abs(s.offsetX - o) > 10 && Math.abs(s.offsetY - r) > 10) {
                                var c = {
                                    x: o,
                                    y: r,
                                    w: s.offsetX - o,
                                    h: s.offsetY - r,
                                    enabled: !0,
                                    label: l
                                };
                                a.splice(l, 1, c),
                                i.reDraw(e, t, a),
                                n = !1,
                                i.draw(e, a)
                            } else
                                i.reDraw(e, t, a),
                                n = !1,
                                i.draw(e, a);
                            i.changelist(e, a)
                        }
                    }
                    : e.onmousedown = function(l) {
                        n = !1,
                        o = l.offsetX,
                        r = l.offsetY,
                        i.reDraw(e, t, a),
                        i.delDraw(e, t, a, null),
                        e.onmousemove = function(t) {
                            n = !1,
                            i.draw(e, a)
                        }
                        ,
                        e.onmouseup = function(o) {
                            i.reDraw(e, t, a),
                            n = !1,
                            i.draw(e, a)
                        }
                        ,
                        e.onmouseout = function(o) {
                            i.reDraw(e, t, a),
                            n = !1,
                            i.draw(e, a)
                        }
                    }
                },
                judgeDraw: function(e, t, a, n) {
                    e.style.cursor = "default";
                    var o = 0
                      , r = 0
                      , i = this;
                    e.onmousedown = function(l) {
                        o = l.offsetX,
                        r = l.offsetY,
                        i.reDraw(e, t, a, n),
                        e.onmouseup = function() {
                            i.reDraw(e, t, a, n),
                            i.draw(e, a, n)
                        }
                        ,
                        i.moveDraw(e, t, a, n, o, r),
                        i.delDraw(e, t, a, n)
                    }
                },
                moveDraw: function(e, t, a, n, o, r) {
                    var i = this
                      , l = a[n];
                    e.onmousemove = function(s) {
                        var c = {
                            x: l.x + (s.offsetX - o),
                            y: l.y + (s.offsetY - r),
                            w: l.w,
                            h: l.h,
                            label: l.label
                        };
                        a.splice(n, 1, c),
                        i.delDraw(e, t, a, n),
                        i.reDraw(e, t, a, n)
                    }
                    ,
                    e.onmouseup = function() {
                        i.reDraw(e, t, a, n),
                        i.draw(e, a, n),
                        i.changelist(e, a)
                    }
                },
                delDraw: function(e, t, a, n) {
                    var o = this;
                    e.onkeydown = null === n ? function(e) {
                        return !1
                    }
                    : function(r) {
                        var i = r.keyCode || r.which;
                        8 === i && null !== n && (a.length >= 1 ? (a.splice(n, 1),
                        o.reDraw(e, t, a)) : t.clearRect(0, 0, e.width, e.height),
                        o.delDraw(e, t, a, null),
                        o.reDraw(e, t, a),
                        o.draw(e, a))
                    }
                },
                reDraw: function(e, t, a, n) {
                    t.setLineDash([8, 0]),
                    t.clearRect(0, 0, e.width, e.height);
                    var o = this.mycolor;
                    a.forEach((function(e, a, n) {
                        var r = o[a].color ? o[a].color : "green";
                        t.beginPath(),
                        t.strokeStyle = r,
                        t.rect(e.x, e.y, e.w, e.h),
                        t.stroke()
                    }
                    )),
                    a.forEach((function(e, a, r) {
                        if (a === n) {
                            var i = o[a].color ? o[a].color : "green";
                            t.beginPath(),
                            t.strokeStyle = i,
                            t.rect(e.x, e.y, e.w, e.h),
                            t.fillStyle = "RGBA(102,102,102,0)",
                            t.fillRect(e.x, e.y, e.w, e.h),
                            t.stroke(),
                            t.beginPath(),
                            t.strokeStyle = "red",
                            t.arc(e.x, e.y, 4, 0, 2 * Math.PI),
                            t.fillStyle = "red",
                            t.fill(),
                            t.stroke(),
                            t.beginPath(),
                            t.arc(e.x, e.y + e.h, 4, 0, 2 * Math.PI),
                            t.fillStyle = "red",
                            t.fill(),
                            t.stroke(),
                            t.beginPath(),
                            t.arc(e.x + e.w, e.y + e.h, 4, 0, 2 * Math.PI),
                            t.fillStyle = "red",
                            t.fill(),
                            t.stroke(),
                            t.beginPath(),
                            t.arc(e.x + e.w, e.y, 4, 0, 2 * Math.PI),
                            t.fillStyle = "red",
                            t.fill(),
                            t.stroke()
                        }
                    }
                    ))
                },
                changelist: function(e, t) {
                    var a = [];
                    if (t.length > 0) {
                        for (var n = 0; n < t.length; n++) {
                            var o = {};
                            o = {
                                x: this.toDecimal(t[n].x / e.width * 100),
                                y: this.toDecimal(t[n].y / e.height * 100),
                                width: this.toDecimal(t[n].w / e.width * 100),
                                height: this.toDecimal(t[n].h / e.height * 100)
                            },
                            a.push(o)
                        }
                        this.$emit("get_layers", a, {
                            w: e.width,
                            h: e.height
                        })
                    }
                },
                addtext: function(e, t, a) {
                    t.w > 0 && t.h > 0 && (e.font = "16pt Arial",
                    e.textAlign = "center",
                    e.fillStyle = "#4796ff",
                    e.textBaseline = "middle",
                    e.strokeStyle = "red",
                    e.fillText(t.label + 1, t.x + t.w / 2, t.y + t.h / 2),
                    e.stroke())
                },
                toDecimal: function(e) {
                    var t = parseFloat(e);
                    if (!isNaN(t))
                        return t = Math.round(100 * e) / 100,
                        t
                }
            }
        })
          , i = r
          , l = (a("80ff"),
        a("2877"))
          , s = Object(l["a"])(i, n, o, !1, null, "acb9322e", null);
        t["a"] = s.exports
    },
    e9c4: function(e, t, a) {
        var n = a("23e7")
          , o = a("d066")
          , r = a("d039")
          , i = o("JSON", "stringify")
          , l = /[\uD800-\uDFFF]/g
          , s = /^[\uD800-\uDBFF]$/
          , c = /^[\uDC00-\uDFFF]$/
          , u = function(e, t, a) {
            var n = a.charAt(t - 1)
              , o = a.charAt(t + 1);
            return s.test(e) && !c.test(o) || c.test(e) && !s.test(n) ? "\\u" + e.charCodeAt(0).toString(16) : e
        }
          , d = r((function() {
            return '"\\udf06\\ud834"' !== i("\udf06\ud834") || '"\\udead"' !== i("\udead")
        }
        ));
        i && n({
            target: "JSON",
            stat: !0,
            forced: d
        }, {
            stringify: function(e, t, a) {
                var n = i.apply(null, arguments);
                return "string" == typeof n ? n.replace(l, u) : n
            }
        })
    },
    ed5f: function(e, t, a) {
        "use strict";
        a.d(t, "b", (function() {
            return o
        }
        )),
        a.d(t, "d", (function() {
            return r
        }
        )),
        a.d(t, "a", (function() {
            return i
        }
        )),
        a.d(t, "c", (function() {
            return l
        }
        ));
        var n = a("b775");
        function o(e) {
            return Object(n["a"])({
                url: "/v1/warning/settings",
                method: "get",
                params: {
                    query: e
                }
            })
        }
        function r(e) {
            return Object(n["a"])({
                url: "/v1/warning/update",
                method: "post",
                data: e
            })
        }
        var i = {
            SUN: 1,
            MON: 2,
            TUE: 4,
            WED: 8,
            THU: 16,
            FRI: 32,
            SAT: 64,
            EVE: 128
        };
        function l(e) {
            var t = parseInt(e)
              , a = "00"
              , n = "00";
            return t >= 60 && (a = Math.floor(t / 60),
            t %= 60,
            a >= 60 && (n = Math.floor(a / 60),
            a %= 60)),
            s(n) + ":" + s(a) + ":" + s(t)
        }
        function s(e) {
            return e > 0 ? e < 10 && (e = "0" + e) : e = "00",
            e
        }
    },
    f183: function(e, t, a) {
        var n = a("d012")
          , o = a("861d")
          , r = a("5135")
          , i = a("9bf2").f
          , l = a("90e3")
          , s = a("bb2f")
          , c = l("meta")
          , u = 0
          , d = Object.isExtensible || function() {
            return !0
        }
          , m = function(e) {
            i(e, c, {
                value: {
                    objectID: "O" + ++u,
                    weakData: {}
                }
            })
        }
          , _ = function(e, t) {
            if (!o(e))
                return "symbol" == typeof e ? e : ("string" == typeof e ? "S" : "P") + e;
            if (!r(e, c)) {
                if (!d(e))
                    return "F";
                if (!t)
                    return "E";
                m(e)
            }
            return e[c].objectID
        }
          , f = function(e, t) {
            if (!r(e, c)) {
                if (!d(e))
                    return !0;
                if (!t)
                    return !1;
                m(e)
            }
            return e[c].weakData
        }
          , h = function(e) {
            return s && p.REQUIRED && d(e) && !r(e, c) && m(e),
            e
        }
          , p = e.exports = {
            REQUIRED: !1,
            fastKey: _,
            getWeakData: f,
            onFreeze: h
        };
        n[c] = !0
    }
}]);
