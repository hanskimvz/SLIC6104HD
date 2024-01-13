(window["webpackJsonp"] = window["webpackJsonp"] || []).push([["chunk-7fd58bf5"], {
    "0e85": function(e, t, o) {
        "use strict";
        o.d(t, "a", (function() {
            return n
        }
        )),
        o.d(t, "b", (function() {
            return s
        }
        ));
        var a = o("b775");
        function n(e) {
            return Object(a["a"])({
                url: "/v1/media/settings",
                method: "get",
                params: {
                    query: e
                }
            })
        }
        function s(e) {
            return Object(a["a"])({
                url: "/v1/media/update",
                method: "post",
                data: e
            })
        }
    },
    "2f24": function(e, t, o) {},
    3039: function(e, t, o) {
        "use strict";
        o("2f24")
    },
    4381: function(e, t, o) {
        "use strict";
        o("d3b7"),
        o("caad"),
        o("2532");
        var a = o("4360");
        function n(e, t) {
            var o = t.value
              , n = a["a"].getters && a["a"].getters.roles;
            if (!(o && o instanceof Array))
                throw new Error("need roles! Like v-permission=\"['admin','editor']\"");
            if (o.length > 0) {
                var s = o
                  , r = n.some((function(e) {
                    return s.includes(e)
                }
                ));
                r || e.parentNode && e.parentNode.removeChild(e)
            }
        }
        var s = {
            inserted: function(e, t) {
                n(e, t)
            },
            update: function(e, t) {
                n(e, t)
            }
        }
          , r = function(e) {
            e.directive("permission", s)
        };
        window.Vue && (window["permission"] = s,
        Vue.use(r)),
        s.install = r;
        t["a"] = s
    },
    9406: function(e, t, o) {
        "use strict";
        o.r(t);
        var a = function() {
            var e = this
              , t = e.$createElement
              , o = e._self._c || t;
            return o("div", {
                staticClass: "dashboard-container"
            }, [o("el-row", {
                staticClass: "customer_row",
                attrs: {
                    gutter: 24
                }
            }, [o("div", {
                staticClass: "customer_row_title"
            }, [o("el-row", {
                attrs: {
                    gutter: 24
                }
            }, [o("el-switch", {
                staticStyle: {
                    border: "1px solid rgba(255,255,255,0.1)",
                    padding: "17px 20px",
                    "border-radius": "30px",
                    background: "rgba(255,255,255,0.1)"
                },
                attrs: {
                    "inactive-text": e.$t("dashboard.monitor")
                },
                on: {
                    change: e.onListening
                },
                model: {
                    value: e.listening,
                    callback: function(t) {
                        e.listening = t
                    },
                    expression: "listening"
                }
            }), o("el-button", {
                staticClass: "customer_row_title_btn customer_row_title_btn_set",
                attrs: {
                    type: "primary",
                    round: "",
                    icon: "el-icon-microphone",
                    size: "small",
                    disabled: !0
                }
            }, [e._v(" " + e._s(e.$t("dashboard.intercom")) + " ")]), o("el-button", {
                staticClass: "customer_row_title_btn customer_row_title_btn_set",
                attrs: {
                    type: "primary",
                    round: "",
                    icon: "el-icon-picture-outline",
                    size: "small"
                },
                on: {
                    click: e.onSnapshots
                }
            }, [e._v(" " + e._s(e.$t("dashboard.snapshot")) + " ")]), o("el-button", {
                staticClass: "customer_row_title_btn customer_row_title_btn_set",
                attrs: {
                    type: "primary",
                    round: "",
                    icon: "el-icon-video-camera",
                    size: "small",
                    disabled: !0
                }
            }, [e._v(" " + e._s(e.$t("dashboard.videotape")) + " ")]), o("el-select", {
                staticClass: "customer_row_title_sl",
                attrs: {
                    placeholder: "please select",
                    size: "small"
                },
                on: {
                    change: e.onStreamSelectChanged
                },
                model: {
                    value: e.current_view,
                    callback: function(t) {
                        e.current_view = t
                    },
                    expression: "current_view"
                }
            }, e._l(e.view_options, (function(t) {
                return o("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1)], 1), o("el-row", {
                staticClass: "media-content padding15"
            }, [o("el-col", {
                attrs: {
                    xl: 18,
                    lg: 17,
                    md: 15,
                    xs: 24,
                    sm: 24
                }
            }, [o("div", {
                staticClass: "media-img customer_vbox",
                staticStyle: {
                    height: "700px",
                    overflow: "hidden"
                }
            }, [o("iframe", {
                attrs: {
                    id: "wx-player",
                    width: "100%",
                    height: "100%",
                    src: e.html_path,
                    frameborder: "no"
                }
            })])]), o("el-col", {
                attrs: {
                    xl: 6,
                    lg: 7,
                    md: 9,
                    xs: 24,
                    sm: 24
                }
            }, [o("el-tabs", {
                attrs: {
                    type: "border-card"
                }
            }, [o("el-tab-pane", {
                staticClass: "customer_tab_item",
                attrs: {
                    label: e.$t("ptzcontrol.name")
                }
            }, [o("el-form", {
                ref: "video_codec",
                staticClass: "custom_form2 auto_wh",
                attrs: {
                    model: e.video_codec
                }
            }, [o("PTZControl")], 1)], 1), o("el-tab-pane", {
                attrs: {
                    label: e.$t("video_codec.main_stream")
                }
            }, [o("el-form", {
                ref: "video_codec",
                staticClass: "custom_form2 auto_wh",
                attrs: {
                    model: e.video_codec
                }
            }, [o("el-form-item", {
                attrs: {
                    label: e.$t("video_codec.encode_format")
                }
            }, [o("el-select", {
                attrs: {
                    size: "small"
                },
                model: {
                    value: e.video_codec.main_stream.encode_format,
                    callback: function(t) {
                        e.$set(e.video_codec.main_stream, "encode_format", t)
                    },
                    expression: "video_codec.main_stream.encode_format"
                }
            }, e._l(e.encode_formats, (function(t) {
                return o("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1), o("el-form-item", {
                attrs: {
                    label: e.$t("video_codec.resolve")
                }
            }, [o("el-select", {
                attrs: {
                    size: "small"
                },
                model: {
                    value: e.video_codec.main_stream.resolve,
                    callback: function(t) {
                        e.$set(e.video_codec.main_stream, "resolve", t)
                    },
                    expression: "video_codec.main_stream.resolve"
                }
            }, e._l(e.ms_resolve_options, (function(e) {
                return o("el-option", {
                    key: e.value,
                    attrs: {
                        label: e.label,
                        value: e.value
                    }
                })
            }
            )), 1)], 1), o("el-form-item", {
                attrs: {
                    label: e.$t("video_codec.bitrate")
                }
            }, [o("el-select", {
                attrs: {
                    size: "small"
                },
                model: {
                    value: e.video_codec.main_stream.bitrate,
                    callback: function(t) {
                        e.$set(e.video_codec.main_stream, "bitrate", t)
                    },
                    expression: "video_codec.main_stream.bitrate"
                }
            }, e._l(e.bit_rates, (function(e) {
                return o("el-option", {
                    key: e.value,
                    attrs: {
                        label: e.label,
                        value: e.value
                    }
                })
            }
            )), 1)], 1), o("el-form-item", {
                attrs: {
                    label: e.$t("video_codec.framerate")
                }
            }, [o("el-input-number", {
                attrs: {
                    size: "small",
                    min: 5,
                    max: 30
                },
                model: {
                    value: e.video_codec.main_stream.framerate,
                    callback: function(t) {
                        e.$set(e.video_codec.main_stream, "framerate", t)
                    },
                    expression: "video_codec.main_stream.framerate"
                }
            })], 1), o("el-form-item", {
                attrs: {
                    label: e.$t("video_codec.bps")
                }
            }, [o("el-input-number", {
                attrs: {
                    size: "small",
                    min: 256,
                    max: 8e3
                },
                model: {
                    value: e.video_codec.main_stream.bps,
                    callback: function(t) {
                        e.$set(e.video_codec.main_stream, "bps", t)
                    },
                    expression: "video_codec.main_stream.bps"
                }
            })], 1), o("el-form-item", {
                attrs: {
                    label: e.$t("video_codec.keyframe_interval")
                }
            }, [o("el-input-number", {
                attrs: {
                    size: "small",
                    min: 5,
                    max: 300
                },
                model: {
                    value: e.video_codec.main_stream.keyframe_interval,
                    callback: function(t) {
                        e.$set(e.video_codec.main_stream, "keyframe_interval", t)
                    },
                    expression: "video_codec.main_stream.keyframe_interval"
                }
            })], 1), o("el-divider"), o("el-form-item", {
                directives: [{
                    name: "permission",
                    rawName: "v-permission",
                    value: ["admin", "operator"],
                    expression: "['admin', 'operator']"
                }],
                staticClass: "mt20",
                attrs: {
                    "label-width": "20px"
                }
            }, [o("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: e.onSubmit
                }
            }, [e._v(e._s(e.$t("button.save")))]), o("el-button", {
                on: {
                    click: e.onRefresh
                }
            }, [e._v(e._s(e.$t("button.refresh")))]), o("el-button", {
                attrs: {
                    type: "warning"
                },
                on: {
                    click: e.onDefault
                }
            }, [e._v(e._s(e.$t("button.default")))])], 1)], 1)], 1), o("el-tab-pane", {
                attrs: {
                    label: e.$t("video_codec.sub_stream")
                }
            }, [o("el-form", {
                ref: "video_codec",
                staticClass: "custom_form2 auto_wh",
                attrs: {
                    model: e.video_codec
                }
            }, [o("el-form-item", {
                attrs: {
                    label: e.$t("video_codec.encode_format")
                }
            }, [o("el-select", {
                attrs: {
                    size: "small"
                },
                model: {
                    value: e.video_codec.sub_stream.encode_format,
                    callback: function(t) {
                        e.$set(e.video_codec.sub_stream, "encode_format", t)
                    },
                    expression: "video_codec.sub_stream.encode_format"
                }
            }, e._l(e.encode_formats, (function(t) {
                return o("el-option", {
                    key: t.value,
                    attrs: {
                        label: e.$t(t.label),
                        value: t.value
                    }
                })
            }
            )), 1)], 1), o("el-form-item", {
                attrs: {
                    label: e.$t("video_codec.resolve")
                }
            }, [o("el-select", {
                attrs: {
                    size: "small"
                },
                model: {
                    value: e.video_codec.sub_stream.resolve,
                    callback: function(t) {
                        e.$set(e.video_codec.sub_stream, "resolve", t)
                    },
                    expression: "video_codec.sub_stream.resolve"
                }
            }, e._l(e.ss_resolve_options, (function(e) {
                return o("el-option", {
                    key: e.value,
                    attrs: {
                        label: e.label,
                        value: e.value
                    }
                })
            }
            )), 1)], 1), o("el-form-item", {
                attrs: {
                    label: e.$t("video_codec.bitrate")
                }
            }, [o("el-select", {
                attrs: {
                    size: "small"
                },
                model: {
                    value: e.video_codec.sub_stream.bitrate,
                    callback: function(t) {
                        e.$set(e.video_codec.sub_stream, "bitrate", t)
                    },
                    expression: "video_codec.sub_stream.bitrate"
                }
            }, e._l(e.bit_rates, (function(e) {
                return o("el-option", {
                    key: e.value,
                    attrs: {
                        label: e.label,
                        value: e.value
                    }
                })
            }
            )), 1)], 1), o("el-form-item", {
                attrs: {
                    label: e.$t("video_codec.framerate")
                }
            }, [o("el-input-number", {
                attrs: {
                    size: "small",
                    min: 5,
                    max: 30
                },
                model: {
                    value: e.video_codec.sub_stream.framerate,
                    callback: function(t) {
                        e.$set(e.video_codec.sub_stream, "framerate", t)
                    },
                    expression: "video_codec.sub_stream.framerate"
                }
            })], 1), o("el-form-item", {
                attrs: {
                    label: e.$t("video_codec.bps")
                }
            }, [o("el-input-number", {
                attrs: {
                    size: "small",
                    min: 64,
                    max: 1e3
                },
                model: {
                    value: e.video_codec.sub_stream.bps,
                    callback: function(t) {
                        e.$set(e.video_codec.sub_stream, "bps", t)
                    },
                    expression: "video_codec.sub_stream.bps"
                }
            })], 1), o("el-form-item", {
                attrs: {
                    label: e.$t("video_codec.keyframe_interval")
                }
            }, [o("el-input-number", {
                attrs: {
                    size: "small",
                    min: 5,
                    max: 300
                },
                model: {
                    value: e.video_codec.sub_stream.keyframe_interval,
                    callback: function(t) {
                        e.$set(e.video_codec.sub_stream, "keyframe_interval", t)
                    },
                    expression: "video_codec.sub_stream.keyframe_interval"
                }
            })], 1), o("el-divider"), o("el-form-item", {
                directives: [{
                    name: "permission",
                    rawName: "v-permission",
                    value: ["admin", "operator"],
                    expression: "['admin', 'operator']"
                }],
                staticClass: "mt20",
                attrs: {
                    "label-width": "20px"
                }
            }, [o("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: e.onSubmit
                }
            }, [e._v(e._s(e.$t("button.save")))]), o("el-button", {
                on: {
                    click: e.onRefresh
                }
            }, [e._v(e._s(e.$t("button.refresh")))]), o("el-button", {
                attrs: {
                    type: "warning"
                },
                on: {
                    click: e.onDefault
                }
            }, [e._v(e._s(e.$t("button.default")))])], 1)], 1)], 1)], 1)], 1)], 1)], 1)], 1)
        }
          , n = []
          , s = (o("d3b7"),
        o("3ca3"),
        o("ddb0"),
        o("2b3d"),
        o("9861"),
        o("fb6a"),
        o("ace4"),
        o("5cc6"),
        o("9a8c"),
        o("a975"),
        o("735e"),
        o("c1ac"),
        o("d139"),
        o("3a7b"),
        o("d5d6"),
        o("82f8"),
        o("e91f"),
        o("60bd"),
        o("5f96"),
        o("3280"),
        o("3fcc"),
        o("ca91"),
        o("25a1"),
        o("cd26"),
        o("3c5d"),
        o("2954"),
        o("649e"),
        o("219c"),
        o("170b"),
        o("b39a"),
        o("72f7"),
        o("25f0"),
        o("b64b"),
        o("e9c4"),
        o("99af"),
        o("4381"))
          , r = o("0e85")
          , i = o("b775");
        function l(e) {
            return Object(i["a"])({
                url: "/v1/livestream/capture",
                method: "get",
                params: {
                    stream: e
                }
            })
        }
        var c = function() {
            var e = this
              , t = e.$createElement
              , o = e._self._c || t;
            return o("div", {
                staticClass: "grid-content bg-purple"
            }, [o("div", {
                staticClass: "c1"
            }, [o("div", {
                staticClass: "pie"
            }, [o("div", {
                staticClass: "slice-one slice",
                on: {
                    mousedown: e.onMoveRight,
                    mouseup: e.onStopPTZ
                }
            }, [o("a", [e._v(">")])]), o("div", {
                staticClass: "slice-two slice",
                on: {
                    mousedown: e.onMoveDown,
                    mouseup: e.onStopPTZ
                }
            }, [o("a", [e._v(">")])]), o("div", {
                staticClass: "slice-three slice",
                on: {
                    mousedown: e.onMoveLeft,
                    mouseup: e.onStopPTZ
                }
            }, [o("a", [e._v(">")])]), o("div", {
                staticClass: "slice-four slice",
                on: {
                    mousedown: e.onMoveUp,
                    mouseup: e.onStopPTZ
                }
            }, [o("a", [e._v(">")])]), o("div", {
                staticClass: "center-kz",
                on: {
                    click: e.onStopPTZ
                }
            }, [o("a", [e._v("PTZ")])]), o("div")])]), o("el-divider"), o("el-form-item", {
                attrs: {
                    label: e.$t("ptzcontrol.amplify")
                }
            }, [o("el-button", {
                staticClass: "fonti16",
                attrs: {
                    type: "primary",
                    icon: "el-icon-zoom-out",
                    size: "small"
                },
                nativeOn: {
                    mousedown: function(t) {
                        return e.onCameraOperate("zoom-wide")
                    },
                    mouseup: function(t) {
                        return e.onStopPTZ(t)
                    }
                }
            }), o("el-button", {
                staticClass: "fonti16",
                attrs: {
                    type: "primary",
                    icon: "el-icon-zoom-in",
                    size: "small"
                },
                nativeOn: {
                    mousedown: function(t) {
                        return e.onCameraOperate("zoom-tele")
                    },
                    mouseup: function(t) {
                        return e.onStopPTZ(t)
                    }
                }
            })], 1), o("el-form-item", {
                attrs: {
                    label: e.$t("ptzcontrol.focus")
                }
            }, [o("el-button", {
                staticClass: "fonti16",
                attrs: {
                    type: "primary",
                    icon: "el-icon-zoom-out",
                    size: "small"
                },
                nativeOn: {
                    mousedown: function(t) {
                        return e.onCameraOperate("focus-near")
                    },
                    mouseup: function(t) {
                        return e.onStopPTZ(t)
                    }
                }
            }), o("el-button", {
                staticClass: "fonti16",
                attrs: {
                    type: "primary",
                    icon: "el-icon-zoom-in",
                    size: "small"
                },
                nativeOn: {
                    mousedown: function(t) {
                        return e.onCameraOperate("focus-far")
                    },
                    mouseup: function(t) {
                        return e.onStopPTZ(t)
                    }
                }
            })], 1), o("el-form-item", {
                attrs: {
                    label: e.$t("ptzcontrol.aperture")
                }
            }, [o("el-button", {
                staticClass: "fonti16",
                attrs: {
                    type: "primary",
                    icon: "el-icon-zoom-out",
                    size: "small"
                },
                nativeOn: {
                    mousedown: function(t) {
                        return e.onCameraOperate("iris_close")
                    },
                    mouseup: function(t) {
                        return e.onStopPTZ(t)
                    }
                }
            }), o("el-button", {
                staticClass: "fonti16",
                attrs: {
                    type: "primary",
                    icon: "el-icon-zoom-in",
                    size: "small"
                },
                nativeOn: {
                    mousedown: function(t) {
                        return e.onCameraOperate("iris_open")
                    },
                    mouseup: function(t) {
                        return e.onStopPTZ(t)
                    }
                }
            })], 1), o("el-form-item", {
                attrs: {
                    label: e.$t("ptzcontrol.ptz_speed")
                }
            }, [o("el-slider", {
                attrs: {
                    max: 255
                },
                model: {
                    value: e.ptzcontrol.move_speed,
                    callback: function(t) {
                        e.$set(e.ptzcontrol, "move_speed", t)
                    },
                    expression: "ptzcontrol.move_speed"
                }
            })], 1), o("el-form-item", {
                attrs: {
                    label: e.$t("ptzcontrol.preset_position")
                }
            }, [o("el-select", {
                attrs: {
                    filterable: "",
                    "allow-create": "",
                    size: "small"
                },
                on: {
                    blur: function(t) {
                        return e.blurInput(t)
                    }
                },
                model: {
                    value: e.current_pos,
                    callback: function(t) {
                        e.current_pos = t
                    },
                    expression: "current_pos"
                }
            }, e._l(e.ptzcontrol.preset_position, (function(e) {
                return o("el-option", {
                    key: e,
                    attrs: {
                        label: e,
                        value: e
                    }
                })
            }
            )), 1)], 1), o("el-form-item", {
                attrs: {
                    label: "",
                    align: "center"
                }
            }, [o("el-tooltip", {
                attrs: {
                    content: e.$t("ptzcontrol.invoke_preset")
                }
            }, [o("el-button", {
                attrs: {
                    type: "primary",
                    icon: "el-icon-caret-right",
                    size: "mini"
                },
                on: {
                    click: function(t) {
                        return e.onPresetOperate("call", e.current_pos)
                    }
                }
            })], 1), o("el-tooltip", {
                attrs: {
                    content: e.$t("ptzcontrol.add_preset")
                }
            }, [o("el-button", {
                attrs: {
                    type: "primary",
                    icon: "el-icon-check",
                    size: "mini"
                },
                on: {
                    click: e.addPreset
                }
            })], 1), o("el-tooltip", {
                attrs: {
                    content: e.$t("ptzcontrol.remove_preset")
                }
            }, [o("el-button", {
                attrs: {
                    type: "primary",
                    icon: "el-icon-delete",
                    size: "mini"
                },
                on: {
                    click: e.removeCurrentPreset
                }
            })], 1)], 1)], 1)
        }
          , u = [];
        o("498a"),
        o("7db0"),
        o("a434");
        function d(e, t) {
            return Object(i["a"])({
                url: "/v1/ptz/move",
                method: "get",
                params: {
                    direction: e,
                    speed: t
                }
            })
        }
        function m() {
            return Object(i["a"])({
                url: "/v1/ptz/stop",
                method: "post"
            })
        }
        function _(e, t) {
            return Object(i["a"])({
                url: "/v1/ptz/camera",
                method: "get",
                params: {
                    operate: e,
                    preset: t
                }
            })
        }
        function p(e) {
            return Object(i["a"])({
                url: "/v1/ptz/settings",
                method: "get",
                params: {
                    query: e
                }
            })
        }
        function v(e) {
            return Object(i["a"])({
                url: "/v1/ptz/update",
                method: "post",
                data: e
            })
        }
        var f = {
            data: function() {
                return {
                    current_pos: null,
                    ptzcontrol: {
                        move_speed: null,
                        preset_position: []
                    }
                }
            },
            created: function() {
                this.fetchData()
            },
            methods: {
                fetchData: function() {
                    var e = this;
                    p("preset").then((function(t) {
                        e.ptzcontrol = t.data.settings,
                        window.console.log(e.ptzcontrol)
                    }
                    ))
                },
                updateData: function() {
                    v({
                        type: "preset",
                        settings: this.ptzcontrol
                    }).then((function(e) {
                        window.console.log("updated!")
                    }
                    ))
                },
                blurInput: function(e) {
                    var t = e.target.value.trim();
                    isNaN(t) || (this.current_pos = t)
                },
                onCameraOperate: function(e) {
                    _(e).then((function(t) {
                        window.console.log("%o", e)
                    }
                    ))
                },
                onPresetOperate: function(e, t) {
                    _(e, t).then((function(o) {
                        window.console.log("%o:%o", e, t)
                    }
                    ))
                },
                addPreset: function() {
                    if (this.ptzcontrol.preset_position.length >= 5)
                        this.$message({
                            message: "Ths system can only support 5 preset",
                            type: "warning"
                        });
                    else {
                        var e = {};
                        if (e = parseInt(this.current_pos),
                        isNaN(e))
                            return "Not a number!";
                        var t = this.ptzcontrol.preset_position.find((function(t) {
                            return t === e
                        }
                        ));
                        t || (window.console.log("添加预设%o", e),
                        this.ptzcontrol.preset_position.push(e),
                        this.onPresetOperate("set", e))
                    }
                },
                removeCurrentPreset: function() {
                    var e = this;
                    this.ptzcontrol.preset_position.find((function(t, o) {
                        t === e.current_pos && (window.console.log("删除预设%o于%o", t, o),
                        e.ptzcontrol.preset_position.splice(o, 1),
                        e.onPresetOperate("clear", t),
                        e.current_pos = null)
                    }
                    ))
                },
                onMoveRight: function() {
                    d("right", this.ptzcontrol.move_speed).then((function(e) {}
                    ))
                },
                onMoveLeft: function() {
                    d("left", this.ptzcontrol.move_speed).then((function(e) {}
                    ))
                },
                onMoveUp: function() {
                    d("up", this.ptzcontrol.move_speed).then((function(e) {}
                    ))
                },
                onMoveDown: function() {
                    d("down", this.ptzcontrol.move_speed).then((function(e) {}
                    ))
                },
                onStopPTZ: function() {
                    m().then((function(e) {
                        window.console.log("PTZ Stop")
                    }
                    ))
                }
            }
        }
          , b = f
          , h = o("2877")
          , w = Object(h["a"])(b, c, u, !1, null, null, null)
          , g = w.exports
          , y = o("61f7")
          , z = {
            name: "Dashboard2",
            directives: {
                permission: s["a"]
            },
            components: {
                PTZControl: g
            },
            data: function() {
                return {
                    frame_window: null,
                    html_path: "/static/player/index.html",
                    current_view: 0,
                    listening: !1,
                    video_codec: {
                        main_stream: {
                            encode_format: 0,
                            resolve: null,
                            resolve_enum: [],
                            bitrate: null,
                            framerate: 0,
                            bps: 0,
                            keyframe_interval: 0
                        },
                        sub_stream: {
                            encode_format: 0,
                            resolve: null,
                            resolve_enum: [],
                            bitrate: null,
                            framerate: 0,
                            bps: 0,
                            keyframe_interval: 0
                        }
                    },
                    prev_data: null,
                    view_options: [{
                        label: "video_codec.main_stream",
                        value: 0
                    }, {
                        label: "video_codec.sub_stream",
                        value: 1
                    }],
                    encode_formats: [{
                        label: "video_codec.h264",
                        value: 2
                    }, {
                        label: "video_codec.h265",
                        value: 3
                    }],
                    ms_resolve_options: [],
                    ss_resolve_options: [],
                    bit_rates: [{
                        label: "CBR",
                        value: 0
                    }, {
                        label: "VBR",
                        value: 1
                    }]
                }
            },
            created: function() {
                this.fetchData()
            },
            mounted: function() {
                var e = parseInt(sessionStorage.getItem("current_stream_id"));
                this.current_view = isNaN(e) ? 0 : e,
                window.console.log("当前码流 %o", this.current_view),
                this.loadPlayer()
            },
            methods: {
                loadPlayer: function() {
                    var e = this
                      , t = document.getElementById("wx-player");
                    t.onload = function() {
                        e.frame_window = t.contentWindow,
                        e.frame_window.postMessage({
                            id: 16,
                            stream: e.current_view
                        }, "*")
                    }
                },
                onListening: function() {
                    null != this.frame_window && this.frame_window.postMessage({
                        id: 17,
                        mute: !this.listening
                    }, "*")
                },
                onSnapshots: function() {
                    var e = this;
                    l(this.current_view).then((function(t) {
                        t.data ? (window.console.log(t.data),
                        e.downloadBase64Image(t.data, (new Date).toLocaleString() + ".jpg")) : null != e.frame_window && e.frame_window.postMessage({
                            id: 18
                        }, "*")
                    }
                    ))
                },
                downloadBase64Image: function(e, t) {
                    var o = this.b64toBlob(e)
                      , a = URL.createObjectURL(o)
                      , n = document.createElement("a");
                    n.href = a,
                    n.download = t,
                    n.click(),
                    document.body.removeChild(n)
                },
                b64toBlob: function(e) {
                    for (var t = atob(e), o = [], a = 0; a < t.length; a += 512) {
                        for (var n = t.slice(a, a + 512), s = new Array(n.length), r = 0; r < n.length; r++)
                            s[r] = n.charCodeAt(r);
                        var i = new Uint8Array(s);
                        o.push(i)
                    }
                    return new Blob(o,{
                        type: "image/jpeg"
                    })
                },
                onStreamSelectChanged: function() {
                    var e = this.current_view.toString();
                    window.console.log("选择码流 %o", e),
                    sessionStorage.setItem("current_stream_id", e),
                    null != this.frame_window && this.frame_window.postMessage({
                        id: 16,
                        stream: this.current_view
                    }, "*")
                },
                fetchData: function() {
                    var e = this;
                    Object(r["a"])("video_codec").then((function(t) {
                        e.video_codec = t.data.settings,
                        e.prev_data = JSON.parse(JSON.stringify(e.video_codec)),
                        window.console.log(e.video_codec),
                        e.updateUi()
                    }
                    ))
                },
                updateData: function() {
                    var e = this;
                    Object(r["b"])({
                        type: "video_codec",
                        settings: this.video_codec
                    }).then((function(t) {
                        window.console.log("已经设置编码 %o", e.video_codec),
                        window.console.log("以前编码 %o", e.prev_data),
                        e.isNeedRestart() && Object(y["a"])(15)
                    }
                    ))
                },
                isNeedRestart: function() {
                    return this.video_codec.main_stream.encode_format !== this.prev_data.main_stream.encode_format || this.video_codec.main_stream.resolve !== this.prev_data.main_stream.resolve || this.video_codec.sub_stream.encode_format !== this.prev_data.sub_stream.encode_format || this.video_codec.sub_stream.resolve !== this.prev_data.sub_stream.resolve
                },
                updateUi: function() {
                    this.ms_resolve_options = this.valuesToOptions(this.video_codec.main_stream.resolve_enum),
                    this.ss_resolve_options = this.valuesToOptions(this.video_codec.sub_stream.resolve_enum)
                },
                valuesToOptions: function(e) {
                    for (var t = [], o = 0; o < e.length; o++) {
                        var a = e[o]
                          , n = Math.floor(a / 1e4)
                          , s = Math.floor(a % 1e4)
                          , r = {
                            label: "".concat(n, " × ").concat(s),
                            value: a
                        };
                        t.push(r)
                    }
                    return t
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData()
                },
                onDefault: function() {
                    var e = this;
                    Object(r["a"])("video_codec_default").then((function(t) {
                        e.video_codec = t.data.settings,
                        window.console.log(e.video_codec),
                        e.updateUi()
                    }
                    ))
                }
            }
        }
          , k = z
          , $ = (o("3039"),
        Object(h["a"])(k, a, n, !1, null, "6d4f00e8", null));
        t["default"] = $.exports
    }
}]);
