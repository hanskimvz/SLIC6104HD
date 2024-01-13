(window["webpackJsonp"] = window["webpackJsonp"] || []).push([["chunk-1bfa552a"], {
    1032: function(t, e, s) {
        "use strict";
        s("89c7")
    },
    4381: function(t, e, s) {
        "use strict";
        s("d3b7"),
        s("caad"),
        s("2532");
        var a = s("4360");
        function r(t, e) {
            var s = e.value
              , r = a["a"].getters && a["a"].getters.roles;
            if (!(s && s instanceof Array))
                throw new Error("need roles! Like v-permission=\"['admin','editor']\"");
            if (s.length > 0) {
                var n = s
                  , o = r.some((function(t) {
                    return n.includes(t)
                }
                ));
                o || t.parentNode && t.parentNode.removeChild(t)
            }
        }
        var n = {
            inserted: function(t, e) {
                r(t, e)
            },
            update: function(t, e) {
                r(t, e)
            }
        }
          , o = function(t) {
            t.directive("permission", n)
        };
        window.Vue && (window["permission"] = n,
        Vue.use(o)),
        n.install = o;
        e["a"] = n
    },
    8593: function(t, e, s) {
        "use strict";
        s.d(e, "a", (function() {
            return r
        }
        )),
        s.d(e, "d", (function() {
            return n
        }
        )),
        s.d(e, "b", (function() {
            return o
        }
        )),
        s.d(e, "c", (function() {
            return l
        }
        ));
        var a = s("b775");
        function r(t) {
            return Object(a["a"])({
                url: "/v1/system/settings",
                method: "get",
                params: {
                    query: t
                }
            })
        }
        function n(t) {
            return Object(a["a"])({
                url: "/v1/system/update",
                method: "post",
                data: t
            })
        }
        function o() {
            return Object(a["a"])({
                url: "/v1/system/restart",
                method: "post"
            })
        }
        function l() {
            return Object(a["a"])({
                url: "/v1/system/restore",
                method: "post"
            })
        }
    },
    "89c7": function(t, e, s) {},
    "9f7f3": function(t, e, s) {
        "use strict";
        s("f8f9")
    },
    ab10: function(t, e, s) {
        "use strict";
        s.d(e, "b", (function() {
            return r
        }
        )),
        s.d(e, "e", (function() {
            return n
        }
        )),
        s.d(e, "a", (function() {
            return o
        }
        )),
        s.d(e, "d", (function() {
            return l
        }
        )),
        s.d(e, "c", (function() {
            return i
        }
        ));
        var a = s("b775");
        function r(t) {
            return Object(a["a"])({
                url: "/v1/network/settings",
                method: "get",
                params: {
                    query: t
                }
            })
        }
        function n(t) {
            return Object(a["a"])({
                url: "/v1/network/update",
                method: "post",
                data: t
            })
        }
        function o(t) {
            return Object(a["a"])({
                url: "/v1/network/ssids",
                method: "get",
                params: {
                    query: t
                }
            })
        }
        function l(t) {
            return Object(a["a"])({
                url: "/v1/network/sendUARTTestData",
                method: "post",
                data: t
            })
        }
        function i() {
            return Object(a["a"])({
                url: "/v1/network/recieveUARTTestData",
                method: "get"
            })
        }
    },
    ba1a: function(t, e, s) {
        "use strict";
        s.r(e);
        var a = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-row", {
                staticClass: "media-content"
            }, [s("el-tabs", {
                attrs: {
                    type: "border-card"
                },
                on: {
                    "tab-click": t.handleClick
                },
                model: {
                    value: t.activeName,
                    callback: function(e) {
                        t.activeName = e
                    },
                    expression: "activeName"
                }
            }, [s("el-tab-pane", {
                key: "tenth",
                attrs: {
                    name: "tenth"
                }
            }, [s("span", {
                attrs: {
                    slot: "label"
                },
                slot: "label"
            }, [s("i", {
                staticClass: "el-icon-document-checked"
            }), t._v(" " + t._s(t.$t("network_protocol.ntf")))]), t.pages.tenth.istab ? s("ntf") : t._e()], 1), s("el-tab-pane", {
                key: "eleventh",
                attrs: {
                    name: "eleventh"
                }
            }, [s("span", {
                attrs: {
                    slot: "label"
                },
                slot: "label"
            }, [s("i", {
                staticClass: "el-icon-document-checked"
            }), t._v(" UDP")]), t.pages.eleventh.istab ? s("UDP") : t._e()], 1), s("el-tab-pane", {
                key: "twelveth",
                attrs: {
                    name: "twelveth"
                }
            }, [s("span", {
                attrs: {
                    slot: "label"
                },
                slot: "label"
            }, [s("i", {
                staticClass: "el-icon-document-checked"
            }), t._v(" FTP")]), t.pages.twelveth.istab ? s("FTP") : t._e()], 1), s("el-tab-pane", {
                key: "thirteenth",
                attrs: {
                    name: "thirteenth"
                }
            }, [s("span", {
                attrs: {
                    slot: "label"
                },
                slot: "label"
            }, [s("i", {
                staticClass: "el-icon-document-checked"
            }), t._v(" RTMP")]), t.pages.thirteenth.istab ? s("RTMP") : t._e()], 1), s("el-tab-pane", {
                key: "fourteenth",
                attrs: {
                    name: "fourteenth"
                }
            }, [s("span", {
                attrs: {
                    slot: "label"
                },
                slot: "label"
            }, [s("i", {
                staticClass: "el-icon-document-checked"
            }), t._v(" MQTT")])]), s("el-tab-pane", {
                key: "fifteenth",
                attrs: {
                    name: "fifteenth"
                }
            }, [s("span", {
                attrs: {
                    slot: "label"
                },
                slot: "label"
            }, [s("i", {
                staticClass: "el-icon-document-checked"
            }), t._v(" P2P")]), t.pages.fifteenth.istab ? s("P2P") : t._e()], 1), s("el-tab-pane", {
                key: "sixteenth",
                attrs: {
                    name: "sixteenth"
                }
            }, [s("span", {
                attrs: {
                    slot: "label"
                },
                slot: "label"
            }, [s("i", {
                staticClass: "el-icon-document-checked"
            }), t._v(" webRTC")]), t.pages.sixteenth.istab ? s("Webrtc") : t._e()], 1), s("el-tab-pane", {
                key: "seventeenth",
                attrs: {
                    name: "seventeenth"
                }
            }, [s("span", {
                attrs: {
                    slot: "label"
                },
                slot: "label"
            }, [s("i", {
                staticClass: "el-icon-document-checked"
            }), t._v(" 串口配置")]), t.pages.seventeenth.istab ? s("UARTTransmission") : t._e()], 1)], 1)], 1)], 1)
        }
          , r = []
          , n = (s("b0c0"),
        function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-row", {
                attrs: {
                    gutter: 24
                }
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 5
                    },
                    lg: {
                        span: 12,
                        offset: 5
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 16,
                        offset: 4
                    }
                }
            }, [s("el-form", {
                ref: "httpport",
                attrs: {
                    model: t.httpport,
                    "label-width": "160px"
                }
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("network_protocol.http_port")
                }
            }, [s("el-input", {
                attrs: {
                    type: "number"
                },
                model: {
                    value: t.httpport.HttpPort,
                    callback: function(e) {
                        t.$set(t.httpport, "HttpPort", e)
                    },
                    expression: "httpport.HttpPort"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("network_protocol.listening_port")
                }
            }, [s("el-input", {
                attrs: {
                    type: "number"
                },
                model: {
                    value: t.httpport.port,
                    callback: function(e) {
                        t.$set(t.httpport, "port", e)
                    },
                    expression: "httpport.port"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("network_protocol.upgrade_port")
                }
            }, [s("el-input", {
                attrs: {
                    type: "number"
                },
                model: {
                    value: t.httpport.upport,
                    callback: function(e) {
                        t.$set(t.httpport, "upport", e)
                    },
                    expression: "httpport.upport"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("network_protocol.multicast_ttl")
                }
            }, [s("el-input", {
                attrs: {
                    type: "number"
                },
                model: {
                    value: t.httpport.ttl,
                    callback: function(e) {
                        t.$set(t.httpport, "ttl", e)
                    },
                    expression: "httpport.ttl"
                }
            })], 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSubmit
                }
            }, [t._v(t._s(t.$t("button.save")))]), s("el-button", {
                on: {
                    click: t.onRefresh
                }
            }, [t._v(t._s(t.$t("button.refresh")))])], 1)], 1)], 1)], 1)], 1)
        }
        )
          , o = []
          , l = s("b775");
        function i(t) {
            return Object(l["a"])({
                url: "/v1/protocol/settings",
                method: "get",
                params: {
                    query: t
                }
            })
        }
        function u(t) {
            return Object(l["a"])({
                url: "/v1/protocol/update",
                method: "post",
                data: t
            })
        }
        var m = {
            data: function() {
                return {
                    httpport: {
                        HttpPort: "80",
                        port: "60000",
                        upport: "61000",
                        ttl: "1"
                    }
                }
            },
            created: function() {
                this.fetchData()
            },
            methods: {
                fetchData: function() {
                    var t = this;
                    i("httpport").then((function(e) {
                        t.httpport = e.data.settings,
                        window.console.log(t.httpport)
                    }
                    ))
                },
                updateData: function() {
                    u({
                        type: "httpport",
                        settings: this.httpport
                    }).then((function(t) {
                        window.console.log("updated!")
                    }
                    ))
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData(),
                    window.console.log("reload!")
                }
            }
        }
          , c = m
          , p = s("2877")
          , f = Object(p["a"])(c, n, o, !1, null, null, null)
          , d = f.exports
          , b = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-row", {
                attrs: {
                    gutter: 24
                }
            }, [s("el-form", {
                ref: "ftp",
                staticClass: "custom_form2 auto_wh mt20",
                attrs: {
                    model: t.ftp,
                    "label-width": "auto"
                }
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 5
                    },
                    lg: {
                        span: 12,
                        offset: 5
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 18,
                        offset: 3
                    }
                }
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("network_protocol.enabled")
                }
            }, [s("el-switch", {
                model: {
                    value: t.ftp.enabled,
                    callback: function(e) {
                        t.$set(t.ftp, "enabled", e)
                    },
                    expression: "ftp.enabled"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("network_protocol.server_url")
                }
            }, [s("el-input", {
                staticClass: "w300",
                model: {
                    value: t.ftp.remote_host,
                    callback: function(e) {
                        t.$set(t.ftp, "remote_host", e)
                    },
                    expression: "ftp.remote_host"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("network_protocol.port")
                }
            }, [s("el-input", {
                staticClass: "w200",
                attrs: {
                    placeholder: "1-65535"
                },
                model: {
                    value: t.ftp.remote_port,
                    callback: function(e) {
                        t.$set(t.ftp, "remote_port", e)
                    },
                    expression: "ftp.remote_port"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("network_protocol.user")
                }
            }, [s("el-input", {
                staticClass: "w200",
                model: {
                    value: t.ftp.user_name,
                    callback: function(e) {
                        t.$set(t.ftp, "user_name", e)
                    },
                    expression: "ftp.user_name"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("network_protocol.password")
                }
            }, [s("el-input", {
                staticClass: "w200",
                attrs: {
                    "show-password": ""
                },
                model: {
                    value: t.ftp.user_password,
                    callback: function(e) {
                        t.$set(t.ftp, "user_password", e)
                    },
                    expression: "ftp.user_password"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("network_protocol.server_path")
                }
            }, [s("el-input", {
                staticClass: "w300",
                attrs: {
                    placeholder: ""
                },
                model: {
                    value: t.ftp.remote_path,
                    callback: function(e) {
                        t.$set(t.ftp, "remote_path", e)
                    },
                    expression: "ftp.remote_path"
                }
            }, [s("el-button", {
                attrs: {
                    slot: "append",
                    icon: "el-icon-folder"
                },
                slot: "append"
            })], 1)], 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSubmit
                }
            }, [t._v(t._s(t.$t("button.save")))]), s("el-button", {
                on: {
                    click: t.onRefresh
                }
            }, [t._v(t._s(t.$t("button.refresh")))]), s("el-button", {
                attrs: {
                    type: "warning"
                },
                on: {
                    click: t.onDefault
                }
            }, [t._v(t._s(t.$t("button.default")))])], 1)], 1)], 1)], 1)], 1)
        }
          , _ = []
          , h = s("ab10")
          , v = {
            data: function() {
                return {
                    ftp: {
                        enabled: !0,
                        remote_host: "",
                        remote_path: "/",
                        remote_port: "",
                        user_name: "",
                        user_password: ""
                    }
                }
            },
            created: function() {
                this.fetchData()
            },
            methods: {
                ftpTest: function() {},
                fetchData: function() {
                    var t = this;
                    Object(h["b"])("ftp").then((function(e) {
                        t.ftp = e.data.settings,
                        window.console.log(t.ftp)
                    }
                    ))
                },
                updateData: function() {
                    Object(h["e"])({
                        type: "ftp",
                        settings: this.ftp
                    }).then((function(t) {
                        window.console.log("updated!")
                    }
                    ))
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData(),
                    window.console.log("reload!")
                },
                onDefault: function() {
                    var t = this;
                    Object(h["b"])("ftp_default").then((function(e) {
                        t.ftp = e.data.settings
                    }
                    ))
                }
            }
        }
          , w = v
          , g = Object(p["a"])(w, b, _, !1, null, null, null)
          , $ = g.exports
          , y = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-row", {
                attrs: {
                    gutter: 24
                }
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 6
                    },
                    lg: {
                        span: 12,
                        offset: 6
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 16,
                        offset: 4
                    }
                }
            }, [s("el-form", {
                ref: "form",
                attrs: {
                    model: t.form,
                    "label-width": "120px"
                }
            }, [s("el-form-item", {
                attrs: {
                    label: "启用DDNS"
                }
            }, [s("el-switch", {
                model: {
                    value: t.form.DDNS,
                    callback: function(e) {
                        t.$set(t.form, "DDNS", e)
                    },
                    expression: "form.DDNS"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "服务器类型"
                }
            }, [s("el-select", {
                attrs: {
                    placeholder: "请选择"
                },
                model: {
                    value: t.form.optionsValue,
                    callback: function(e) {
                        t.$set(t.form, "optionsValue", e)
                    },
                    expression: "form.optionsValue"
                }
            }, t._l(t.form.options, (function(t) {
                return s("el-option", {
                    key: t.value,
                    attrs: {
                        label: t.label,
                        value: t.value
                    }
                })
            }
            )), 1)], 1), s("el-form-item", {
                attrs: {
                    label: "服务器端口"
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "1-65535"
                },
                model: {
                    value: t.form.port,
                    callback: function(e) {
                        t.$set(t.form, "port", e)
                    },
                    expression: "form.port"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "域名"
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "请输入域名"
                },
                model: {
                    value: t.form.url,
                    callback: function(e) {
                        t.$set(t.form, "url", e)
                    },
                    expression: "form.url"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "用户名"
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "请输入用户名"
                },
                model: {
                    value: t.form.user,
                    callback: function(e) {
                        t.$set(t.form, "user", e)
                    },
                    expression: "form.user"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "密码"
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "请输入密码",
                    "show-password": ""
                },
                model: {
                    value: t.form.password,
                    callback: function(e) {
                        t.$set(t.form, "password", e)
                    },
                    expression: "form.password"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "保活周期"
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "请输入保活周期（min）"
                },
                model: {
                    value: t.form.status,
                    callback: function(e) {
                        t.$set(t.form, "status", e)
                    },
                    expression: "form.status"
                }
            })], 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSubmit
                }
            }, [t._v("设置")]), s("el-button", {
                on: {
                    click: t.onCancel
                }
            }, [t._v("刷新")])], 1)], 1)], 1)], 1)], 1)
        }
          , k = []
          , x = {
            data: function() {
                return {
                    form: {
                        name: "",
                        region: "",
                        date1: "",
                        date2: "",
                        delivery: !1,
                        type: [],
                        resource: "",
                        status: "",
                        desc: "",
                        options: [{
                            value: "0",
                            label: "dyndns"
                        }, {
                            value: "1",
                            label: "dyndns1"
                        }, {
                            value: "2",
                            label: "dyndns2"
                        }]
                    }
                }
            },
            methods: {
                onSubmit: function() {
                    this.$message("submit!")
                },
                onCancel: function() {
                    this.$message({
                        message: "cancel!",
                        type: "warning"
                    })
                }
            }
        }
          , T = x
          , D = Object(p["a"])(T, y, k, !1, null, null, null)
          , C = D.exports
          , O = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-card", {
                staticClass: "box-card customer_boxhead"
            }, [s("div", {
                staticClass: "clearfix",
                attrs: {
                    slot: "header"
                },
                slot: "header"
            }, [s("span", [t._v("心跳设置")])]), s("el-row", {
                attrs: {
                    gutter: 24
                }
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 6
                    },
                    lg: {
                        span: 12,
                        offset: 6
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 16,
                        offset: 4
                    }
                }
            }, [s("el-form", {
                ref: "form",
                attrs: {
                    model: t.form,
                    "label-width": "120px"
                }
            }, [s("el-form-item", {
                attrs: {
                    label: "启用"
                }
            }, [s("el-switch", {
                model: {
                    value: t.form.stutus,
                    callback: function(e) {
                        t.$set(t.form, "stutus", e)
                    },
                    expression: "form.stutus"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "域名"
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "请输入域名"
                },
                model: {
                    value: t.form.url,
                    callback: function(e) {
                        t.$set(t.form, "url", e)
                    },
                    expression: "form.url"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "服务器端口"
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "请输入服务器端口"
                },
                model: {
                    value: t.form.port,
                    callback: function(e) {
                        t.$set(t.form, "port", e)
                    },
                    expression: "form.port"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "刷新周期"
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "请输入刷新周期（ms）"
                },
                model: {
                    value: t.form.uptime,
                    callback: function(e) {
                        t.$set(t.form, "uptime", e)
                    },
                    expression: "form.uptime"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "标识"
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "请输入ID标识"
                },
                model: {
                    value: t.form.id,
                    callback: function(e) {
                        t.$set(t.form, "id", e)
                    },
                    expression: "form.id"
                }
            })], 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: function(e) {
                        return t.submitForm("form")
                    }
                }
            }, [t._v("设置")]), s("el-button", {
                on: {
                    click: function(e) {
                        return t.resetForm("form")
                    }
                }
            }, [t._v("重置")])], 1)], 1)], 1)], 1)], 1)], 1)
        }
          , j = []
          , S = {
            data: function() {
                return {
                    form: {
                        url: "",
                        path: "/",
                        port: "",
                        user: "",
                        password: "",
                        stutus: !0
                    }
                }
            },
            methods: {
                submitForm: function(t) {
                    this.$refs[t].validate((function(t) {
                        if (!t)
                            return console.log("error submit!!"),
                            !1;
                        alert("submit!")
                    }
                    ))
                },
                resetForm: function(t) {
                    this.$refs[t].resetFields()
                }
            }
        }
          , U = S
          , P = Object(p["a"])(U, O, j, !1, null, null, null)
          , M = (P.exports,
        function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-row", {
                attrs: {
                    gutter: 24
                }
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 7
                    },
                    lg: {
                        span: 12,
                        offset: 6
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 16,
                        offset: 4
                    }
                }
            }, [s("el-form", {
                ref: "form",
                attrs: {
                    model: t.form,
                    "label-width": "120px"
                }
            }, [s("el-form-item", {
                attrs: {
                    label: "PPOE设置"
                }
            }, [s("el-switch", {
                model: {
                    value: t.form.ppoe,
                    callback: function(e) {
                        t.$set(t.form, "ppoe", e)
                    },
                    expression: "form.ppoe"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "IPv4地址"
                }
            }, [s("el-input", {
                model: {
                    value: t.form.IPv4,
                    callback: function(e) {
                        t.$set(t.form, "IPv4", e)
                    },
                    expression: "form.IPv4"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "用户名"
                }
            }, [s("el-input", {
                model: {
                    value: t.form.user,
                    callback: function(e) {
                        t.$set(t.form, "user", e)
                    },
                    expression: "form.user"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "密码"
                }
            }, [s("el-input", {
                model: {
                    value: t.form.password,
                    callback: function(e) {
                        t.$set(t.form, "password", e)
                    },
                    expression: "form.password"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "PPoE状态"
                }
            }, [s("el-input", {
                attrs: {
                    disabled: !0
                },
                model: {
                    value: t.form.status,
                    callback: function(e) {
                        t.$set(t.form, "status", e)
                    },
                    expression: "form.status"
                }
            })], 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSubmit
                }
            }, [t._v("设置")]), s("el-button", {
                on: {
                    click: t.onCancel
                }
            }, [t._v("刷新")])], 1)], 1)], 1)], 1)], 1)
        }
        )
          , R = []
          , I = {
            data: function() {
                return {
                    form: {
                        name: "",
                        region: "",
                        date1: "",
                        date2: "",
                        delivery: !1,
                        type: [],
                        resource: "",
                        status: "开启",
                        desc: ""
                    }
                }
            },
            methods: {
                onSubmit: function() {
                    this.$message("submit!")
                },
                onCancel: function() {
                    this.$message({
                        message: "cancel!",
                        type: "warning"
                    })
                }
            }
        }
          , G = I
          , N = Object(p["a"])(G, M, R, !1, null, null, null)
          , E = N.exports
          , q = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-row", {
                attrs: {
                    gutter: 24
                }
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 6
                    },
                    lg: {
                        span: 12,
                        offset: 6
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 16,
                        offset: 4
                    }
                }
            }, [s("el-form", {
                ref: "smtp",
                attrs: {
                    model: t.smtp,
                    "label-width": "120px",
                    rules: t.rules
                }
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("smtp.url"),
                    prop: "SMTP"
                }
            }, [s("el-input", {
                model: {
                    value: t.smtp.url,
                    callback: function(e) {
                        t.$set(t.smtp, "url", e)
                    },
                    expression: "smtp.url"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("smtp.port"),
                    prop: "port"
                }
            }, [s("el-input", {
                model: {
                    value: t.smtp.port,
                    callback: function(e) {
                        t.$set(t.smtp, "port", e)
                    },
                    expression: "smtp.port"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("smtp.senduser"),
                    prop: "senduser"
                }
            }, [s("el-input", {
                model: {
                    value: t.smtp.senduser,
                    callback: function(e) {
                        t.$set(t.smtp, "senduser", e)
                    },
                    expression: "smtp.senduser"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("smtp.user")
                }
            }, [s("el-input", {
                model: {
                    value: t.smtp.user,
                    callback: function(e) {
                        t.$set(t.smtp, "user", e)
                    },
                    expression: "smtp.user"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("smtp.password")
                }
            }, [s("el-input", {
                attrs: {
                    "show-password": ""
                },
                model: {
                    value: t.smtp.password,
                    callback: function(e) {
                        t.$set(t.smtp, "password", e)
                    },
                    expression: "smtp.password"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("smtp.getuser"),
                    prop: "getuser"
                }
            }, [s("el-input", {
                model: {
                    value: t.smtp.getuser,
                    callback: function(e) {
                        t.$set(t.smtp, "getuser", e)
                    },
                    expression: "smtp.getuser"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("smtp.ssl")
                }
            }, [s("el-switch", {
                model: {
                    value: t.smtp.ssl,
                    callback: function(e) {
                        t.$set(t.smtp, "ssl", e)
                    },
                    expression: "smtp.ssl"
                }
            })], 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSubmit
                }
            }, [t._v(t._s(t.$t("button.save")))]), s("el-button", {
                on: {
                    click: t.onRefresh
                }
            }, [t._v(t._s(t.$t("button.refresh")))])], 1)], 1)], 1)], 1)], 1)
        }
          , F = []
          , V = {
            data: function() {
                return {
                    smtp: {
                        url: "",
                        port: "",
                        senduser: "",
                        user: "",
                        password: "",
                        getuser: "",
                        ssl: !0
                    },
                    rules: {
                        smtp: [{
                            required: !0,
                            message: this.$t("smtp.getuser_msg"),
                            trigger: "blur"
                        }],
                        senduser: [{
                            required: !0,
                            message: this.$t("smtp.senduser_msg"),
                            trigger: "blur"
                        }],
                        getuser: [{
                            required: !0,
                            message: this.$t("smtp.getuser_msg"),
                            trigger: "blur"
                        }]
                    }
                }
            },
            created: function() {
                this.fetchData()
            },
            methods: {
                ftpTest: function() {},
                fetchData: function() {
                    var t = this;
                    i("smtp").then((function(e) {
                        t.smtp = e.data.settings,
                        window.console.log(t.smtp)
                    }
                    ))
                },
                updateData: function() {
                    u({
                        type: "smtp",
                        settings: this.smtp
                    }).then((function(t) {
                        window.console.log("updated!")
                    }
                    ))
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData(),
                    window.console.log("reload!")
                }
            }
        }
          , H = V
          , z = Object(p["a"])(H, q, F, !1, null, null, null)
          , A = z.exports
          , J = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-row", {
                attrs: {
                    gutter: 24
                }
            }, [s("el-form", {
                ref: "system_time",
                staticClass: "custom_form2 auto_wh mt20",
                attrs: {
                    model: t.system_time
                }
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 5
                    },
                    lg: {
                        span: 12,
                        offset: 5
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 18,
                        offset: 3
                    }
                }
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("system_time.mode")
                }
            }, [s("el-radio-group", {
                model: {
                    value: t.system_time.auto_mode,
                    callback: function(e) {
                        t.$set(t.system_time, "auto_mode", e)
                    },
                    expression: "system_time.auto_mode"
                }
            }, [s("el-radio", {
                attrs: {
                    label: !0
                }
            }, [t._v(t._s(t.$t("devices_maintenance.use_ntp")))]), s("el-radio", {
                attrs: {
                    label: !1
                }
            }, [t._v(t._s(t.$t("devices_maintenance.use_computer")))])], 1)], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("system_time.timezone")
                }
            }, [s("el-select", {
                model: {
                    value: t.system_time.timezone,
                    callback: function(e) {
                        t.$set(t.system_time, "timezone", e)
                    },
                    expression: "system_time.timezone"
                }
            }, t._l(t.options, (function(e) {
                return s("el-option", {
                    key: e.value,
                    attrs: {
                        label: t.$t(e.label),
                        value: e.value
                    }
                })
            }
            )), 1)], 1), s("div", {
                directives: [{
                    name: "show",
                    rawName: "v-show",
                    value: t.system_time.auto_mode,
                    expression: "system_time.auto_mode"
                }]
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("system_time.ntp_server")
                }
            }, [s("el-input", {
                staticClass: "w200",
                model: {
                    value: t.system_time.ntp_server.name,
                    callback: function(e) {
                        t.$set(t.system_time.ntp_server, "name", e)
                    },
                    expression: "system_time.ntp_server.name"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("system_time.port")
                }
            }, [s("el-input-number", {
                staticClass: "w200",
                model: {
                    value: t.system_time.ntp_server.port,
                    callback: function(e) {
                        t.$set(t.system_time.ntp_server, "port", e)
                    },
                    expression: "system_time.ntp_server.port"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("system_time.sync_time")
                }
            }, [s("el-input-number", {
                staticClass: "w200",
                model: {
                    value: t.system_time.ntp_server.sync_time,
                    callback: function(e) {
                        t.$set(t.system_time.ntp_server, "sync_time", e)
                    },
                    expression: "system_time.ntp_server.sync_time"
                }
            })], 1)], 1), s("div", {
                directives: [{
                    name: "show",
                    rawName: "v-show",
                    value: !t.system_time.auto_mode,
                    expression: "!system_time.auto_mode"
                }]
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("system_time.time")
                }
            }, [s("el-date-picker", {
                staticClass: "w200",
                attrs: {
                    type: "datetime",
                    disabled: t.same_host
                },
                model: {
                    value: t.date_time,
                    callback: function(e) {
                        t.date_time = e
                    },
                    expression: "date_time"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("system_time.same_host")
                }
            }, [s("el-switch", {
                on: {
                    change: t.onSameHostChanged
                },
                model: {
                    value: t.same_host,
                    callback: function(e) {
                        t.same_host = e
                    },
                    expression: "same_host"
                }
            })], 1)], 1)], 1), s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 5
                    },
                    lg: {
                        span: 12,
                        offset: 5
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 18,
                        offset: 3
                    }
                }
            }, [s("el-form-item", {
                directives: [{
                    name: "permission",
                    rawName: "v-permission",
                    value: ["admin", "operator"],
                    expression: "['admin', 'operator']"
                }],
                staticClass: "mt20",
                attrs: {
                    "label-width": "120px"
                }
            }, [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSubmit
                }
            }, [t._v(t._s(t.$t("button.save")))]), s("el-button", {
                on: {
                    click: t.onRefresh
                }
            }, [t._v(t._s(t.$t("button.refresh")))]), s("el-button", {
                attrs: {
                    type: "warning"
                },
                on: {
                    click: t.onDefault
                }
            }, [t._v(t._s(t.$t("button.default")))])], 1)], 1)], 1)], 1)], 1)
        }
          , Q = []
          , W = s("4381")
          , L = s("8593")
          , B = {
            directives: {
                permission: W["a"]
            },
            data: function() {
                return {
                    system_time: {
                        auto_mode: null,
                        timezone: null,
                        ntp_server: {
                            name: null,
                            port: null,
                            sync_time: null
                        },
                        manual_mode: {
                            time: null
                        }
                    },
                    same_host: !1,
                    date_time: null,
                    options: [{
                        label: "GMT -12",
                        value: -1200
                    }, {
                        label: "GMT -11",
                        value: -1100
                    }, {
                        label: "GMT -10",
                        value: -1e3
                    }, {
                        label: "GMT -9",
                        value: -900
                    }, {
                        label: "GMT -8",
                        value: -800
                    }, {
                        label: "GMT -7",
                        value: -700
                    }, {
                        label: "GMT -6",
                        value: -600
                    }, {
                        label: "GMT -5",
                        value: -500
                    }, {
                        label: "GMT -4",
                        value: -400
                    }, {
                        label: "GMT -3",
                        value: -300
                    }, {
                        label: "GMT -2",
                        value: -200
                    }, {
                        label: "GMT -1",
                        value: -100
                    }, {
                        label: "GMT 0",
                        value: 0
                    }, {
                        label: "GMT +1",
                        value: 100
                    }, {
                        label: "GMT +2",
                        value: 200
                    }, {
                        label: "GMT +3",
                        value: 300
                    }, {
                        label: "GMT +4",
                        value: 400
                    }, {
                        label: "GMT +5",
                        value: 500
                    }, {
                        label: "GMT +6",
                        value: 600
                    }, {
                        label: "GMT +7",
                        value: 700
                    }, {
                        label: "GMT +8",
                        value: 800
                    }, {
                        label: "GMT +9",
                        value: 900
                    }, {
                        label: "GMT +10",
                        value: 1e3
                    }, {
                        label: "GMT +11",
                        value: 1100
                    }, {
                        label: "GMT +12",
                        value: 1200
                    }, {
                        label: "GMT +13",
                        value: 1300
                    }]
                }
            },
            created: function() {
                this.fetchData()
            },
            methods: {
                fetchData: function() {
                    var t = this;
                    Object(L["a"])("system_time").then((function(e) {
                        t.system_time = e.data.settings,
                        window.console.log(t.system_time),
                        t.updateUi()
                    }
                    ))
                },
                updateData: function() {
                    this.same_host && (this.date_time = new Date),
                    this.system_time.manual_mode.time = Math.floor(this.date_time.getTime() / 1e3),
                    Object(L["d"])({
                        type: "system_time",
                        settings: this.system_time
                    }).then((function(t) {
                        window.console.log("updated!")
                    }
                    ))
                },
                updateUi: function() {
                    this.date_time = this.utcSeconds2Datetime()
                },
                onSameHostChanged: function() {
                    this.same_host ? this.date_time = new Date : this.date_time = this.utcSeconds2Datetime()
                },
                utcSeconds2Datetime: function() {
                    var t = new Date(0);
                    return this.system_time.manual_mode.time && t.setUTCSeconds(this.system_time.manual_mode.time),
                    t
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData(),
                    window.console.log("reload!")
                },
                onDefault: function() {
                    var t = this;
                    Object(L["a"])("system_time_default").then((function(e) {
                        t.system_time = e.data.settings,
                        window.console.log(t.system_time),
                        t.updateUi()
                    }
                    ))
                }
            }
        }
          , K = B
          , X = Object(p["a"])(K, J, Q, !1, null, null, null)
          , Y = X.exports
          , Z = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-row", {
                attrs: {
                    gutter: 24
                }
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 7
                    },
                    lg: {
                        span: 12,
                        offset: 6
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 16,
                        offset: 4
                    }
                }
            }, [s("el-form", {
                ref: "form",
                attrs: {
                    model: t.form,
                    "label-width": "120px"
                }
            }, [s("el-form-item", {
                attrs: {
                    label: "启用UPnp"
                }
            }, [s("el-switch", {
                model: {
                    value: t.form.UPnp,
                    callback: function(e) {
                        t.$set(t.form, "UPnp", e)
                    },
                    expression: "form.UPnp"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "数据映射端口"
                }
            }, [s("el-input", {
                model: {
                    value: t.form.IPv4,
                    callback: function(e) {
                        t.$set(t.form, "IPv4", e)
                    },
                    expression: "form.IPv4"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "HTTP映射端口"
                }
            }, [s("el-input", {
                model: {
                    value: t.form.user,
                    callback: function(e) {
                        t.$set(t.form, "user", e)
                    },
                    expression: "form.user"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "刷新周期（h）"
                }
            }, [s("el-input", {
                model: {
                    value: t.form.status,
                    callback: function(e) {
                        t.$set(t.form, "status", e)
                    },
                    expression: "form.status"
                }
            })], 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSubmit
                }
            }, [t._v("设置")]), s("el-button", {
                on: {
                    click: t.onCancel
                }
            }, [t._v("刷新")])], 1)], 1)], 1)], 1)], 1)
        }
          , tt = []
          , et = {
            data: function() {
                return {
                    form: {
                        name: "",
                        region: "",
                        date1: "",
                        date2: "",
                        delivery: !1,
                        type: [],
                        resource: "",
                        status: "",
                        desc: ""
                    }
                }
            },
            methods: {
                onSubmit: function() {
                    this.$message("submit!")
                },
                onCancel: function() {
                    this.$message({
                        message: "cancel!",
                        type: "warning"
                    })
                }
            }
        }
          , st = et
          , at = Object(p["a"])(st, Z, tt, !1, null, null, null)
          , rt = at.exports
          , nt = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-row", {
                attrs: {
                    gutter: 24
                }
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 5
                    },
                    lg: {
                        span: 12,
                        offset: 5
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 16,
                        offset: 4
                    }
                }
            }, [s("el-form", {
                ref: "rstp",
                attrs: {
                    model: t.rstp,
                    "label-width": "160px"
                }
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("rstp.is_dna")
                }
            }, [s("el-switch", {
                model: {
                    value: t.rstp.enabled,
                    callback: function(e) {
                        t.$set(t.rstp, "enabled", e)
                    },
                    expression: "rstp.enabled"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("rstp.port")
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "1-65535"
                },
                model: {
                    value: t.rstp.port,
                    callback: function(e) {
                        t.$set(t.rstp, "port", e)
                    },
                    expression: "rstp.port"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("rstp.video_id")
                }
            }, [s("el-input", {
                model: {
                    value: t.rstp.videoId,
                    callback: function(e) {
                        t.$set(t.rstp, "videoId", e)
                    },
                    expression: "rstp.videoId"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("rstp.voice_id")
                }
            }, [s("el-input", {
                model: {
                    value: t.rstp.voiceId,
                    callback: function(e) {
                        t.$set(t.rstp, "voiceId", e)
                    },
                    expression: "rstp.voiceId"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("rstp.talk_id")
                }
            }, [s("el-input", {
                model: {
                    value: t.rstp.talkID,
                    callback: function(e) {
                        t.$set(t.rstp, "talkID", e)
                    },
                    expression: "rstp.talkID"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("rstp.mtu")
                }
            }, [s("el-input", {
                model: {
                    value: t.rstp.Mtu,
                    callback: function(e) {
                        t.$set(t.rstp, "Mtu", e)
                    },
                    expression: "rstp.Mtu"
                }
            })], 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSubmit
                }
            }, [t._v(t._s(t.$t("button.save")))]), s("el-button", {
                on: {
                    click: t.onRefresh
                }
            }, [t._v(t._s(t.$t("button.refresh")))])], 1)], 1)], 1)], 1)], 1)
        }
          , ot = []
          , lt = {
            data: function() {
                return {
                    rstp: {
                        enabled: !0,
                        port: "",
                        videoId: "",
                        voiceId: "",
                        talkID: "",
                        Mtu: ""
                    }
                }
            },
            created: function() {
                this.fetchData()
            },
            methods: {
                fetchData: function() {
                    var t = this;
                    i("rstp").then((function(e) {
                        t.rstp = e.data.settings,
                        window.console.log(t.rstp)
                    }
                    ))
                },
                updateData: function() {
                    u({
                        type: "rstp",
                        settings: this.rstp
                    }).then((function(t) {
                        window.console.log("updated!")
                    }
                    ))
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData(),
                    window.console.log("reload!")
                }
            }
        }
          , it = lt
          , ut = Object(p["a"])(it, nt, ot, !1, null, null, null)
          , mt = ut.exports
          , ct = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-row", {
                attrs: {
                    gutter: 24
                }
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 5
                    },
                    lg: {
                        span: 12,
                        offset: 5
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 16,
                        offset: 4
                    }
                }
            }, [s("el-form", {
                ref: "rtp",
                attrs: {
                    model: t.rtp,
                    "label-width": "160px"
                }
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("rtp.enabled")
                }
            }, [s("el-switch", {
                model: {
                    value: t.rtp.enabled,
                    callback: function(e) {
                        t.$set(t.rtp, "enabled", e)
                    },
                    expression: "rtp.enabled"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("rtp.send_stream")
                }
            }, [s("el-select", {
                model: {
                    value: t.rtp.send_stream,
                    callback: function(e) {
                        t.$set(t.rtp, "send_stream", e)
                    },
                    expression: "rtp.send_stream"
                }
            }, t._l(t.options, (function(t) {
                return s("el-option", {
                    key: t.value,
                    attrs: {
                        label: t.label,
                        value: t.value
                    }
                })
            }
            )), 1)], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("rtp.port")
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "1-65535"
                },
                model: {
                    value: t.rtp.port,
                    callback: function(e) {
                        t.$set(t.rtp, "port", e)
                    },
                    expression: "rtp.port"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("rtp.mtu")
                }
            }, [s("el-input", {
                attrs: {
                    disabled: !0
                },
                model: {
                    value: t.rtp.Mtu,
                    callback: function(e) {
                        t.$set(t.rtp, "Mtu", e)
                    },
                    expression: "rtp.Mtu"
                }
            })], 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSubmit
                }
            }, [t._v(t._s(t.$t("button.save")))]), s("el-button", {
                on: {
                    click: t.onRefresh
                }
            }, [t._v(t._s(t.$t("button.refresh")))])], 1)], 1)], 1)], 1)], 1)
        }
          , pt = []
          , ft = {
            data: function() {
                return {
                    rtp: {
                        port: "1024",
                        enabled: !0,
                        send_stream: "1",
                        Mtu: ""
                    },
                    options: [{
                        value: "0",
                        label: "stream1"
                    }, {
                        value: "1",
                        label: "stream2"
                    }, {
                        value: "2",
                        label: "stream3"
                    }]
                }
            },
            created: function() {
                this.fetchData()
            },
            methods: {
                fetchData: function() {
                    var t = this;
                    i("rtp").then((function(e) {
                        t.rtp = e.data.settings,
                        window.console.log(t.rtp)
                    }
                    ))
                },
                updateData: function() {
                    u({
                        type: "rtp",
                        settings: this.rtp
                    }).then((function(t) {
                        window.console.log("updated!")
                    }
                    ))
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData(),
                    window.console.log("reload!")
                }
            }
        }
          , dt = ft
          , bt = Object(p["a"])(dt, ct, pt, !1, null, null, null)
          , _t = bt.exports
          , ht = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-row", {
                attrs: {
                    gutter: 24
                }
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 6
                    },
                    lg: {
                        span: 12,
                        offset: 6
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 16,
                        offset: 4
                    }
                }
            }, [s("el-form", {
                ref: "form",
                attrs: {
                    model: t.form,
                    "label-width": "120px"
                }
            }, [s("el-form-item", {
                attrs: {
                    label: "启用8021"
                }
            }, [s("el-switch", {
                model: {
                    value: t.form.s8021,
                    callback: function(e) {
                        t.$set(t.form, "s8021", e)
                    },
                    expression: "form.s8021"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "EAP协议类型"
                }
            }, [s("el-select", {
                attrs: {
                    placeholder: "请选择"
                }
            }, [s("el-option", {
                attrs: {
                    value: "EAP"
                }
            })], 1)], 1), s("el-form-item", {
                attrs: {
                    label: "版本号"
                }
            }, [s("el-select", {
                attrs: {
                    placeholder: "请选择"
                }
            }, [s("el-option", {
                attrs: {
                    value: "1"
                }
            })], 1)], 1), s("el-form-item", {
                attrs: {
                    label: "用户名"
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "请输入用户名"
                },
                model: {
                    value: t.form.user,
                    callback: function(e) {
                        t.$set(t.form, "user", e)
                    },
                    expression: "form.user"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "密码"
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "请输入密码",
                    "show-password": ""
                },
                model: {
                    value: t.form.password,
                    callback: function(e) {
                        t.$set(t.form, "password", e)
                    },
                    expression: "form.password"
                }
            })], 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: function(e) {
                        return t.submitForm("form")
                    }
                }
            }, [t._v("设置")]), s("el-button", {
                on: {
                    click: function(e) {
                        return t.resetForm("form")
                    }
                }
            }, [t._v("重置")])], 1)], 1)], 1)], 1)], 1)
        }
          , vt = []
          , wt = {
            data: function() {
                return {
                    form: {
                        url: "",
                        path: "/",
                        port: "",
                        user: "",
                        password: "",
                        s8021: !0
                    }
                }
            },
            methods: {
                submitForm: function(t) {
                    this.$refs[t].validate((function(t) {
                        if (!t)
                            return console.log("error submit!!"),
                            !1;
                        alert("submit!")
                    }
                    ))
                },
                resetForm: function(t) {
                    this.$refs[t].resetFields()
                }
            }
        }
          , gt = wt
          , $t = Object(p["a"])(gt, ht, vt, !1, null, null, null)
          , yt = $t.exports
          , kt = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-row", {
                attrs: {
                    gutter: 24
                }
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 5
                    },
                    lg: {
                        span: 12,
                        offset: 5
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 16,
                        offset: 4
                    }
                }
            }, [s("el-form", {
                ref: "form",
                attrs: {
                    model: t.form,
                    "label-width": "180px"
                }
            }, [s("el-form-item", {
                attrs: {
                    label: "Reallytime monitor"
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "reallytime monitor"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: "Command"
                }
            }, [s("el-input", {
                attrs: {
                    placeholder: "reallytime monitor"
                },
                model: {
                    value: t.form.user,
                    callback: function(e) {
                        t.$set(t.form, "user", e)
                    },
                    expression: "form.user"
                }
            })], 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: function(e) {
                        return t.submitForm("form")
                    }
                }
            }, [t._v("设置")]), s("el-button", {
                on: {
                    click: function(e) {
                        return t.resetForm("form")
                    }
                }
            }, [t._v("重置")])], 1)], 1)], 1)], 1)], 1)
        }
          , xt = []
          , Tt = {
            data: function() {
                return {
                    form: {
                        url: "",
                        path: "/",
                        port: "",
                        user: "",
                        password: "",
                        s8021: !0
                    }
                }
            },
            methods: {
                submitForm: function(t) {
                    this.$refs[t].validate((function(t) {
                        if (!t)
                            return console.log("error submit!!"),
                            !1;
                        alert("submit!")
                    }
                    ))
                },
                resetForm: function(t) {
                    this.$refs[t].resetFields()
                }
            }
        }
          , Dt = Tt
          , Ct = Object(p["a"])(Dt, kt, xt, !1, null, null, null)
          , Ot = Ct.exports
          , jt = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 5
                    },
                    lg: {
                        span: 12,
                        offset: 6
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 16,
                        offset: 4
                    }
                }
            }, [s("el-form", {
                ref: "form",
                attrs: {
                    "label-width": "140px"
                }
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("devices_maintenance.use_multicast")
                }
            }, [s("el-switch", {
                model: {
                    value: t.udp.enabled,
                    callback: function(e) {
                        t.$set(t.udp, "enabled", e)
                    },
                    expression: "udp.enabled"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("devices_maintenance.video_streaming")
                }
            }, [s("el-select", {
                staticClass: "customer_row_title_sl",
                attrs: {
                    placeholder: "please select",
                    size: "small"
                },
                model: {
                    value: t.udp.stream_id,
                    callback: function(e) {
                        t.$set(t.udp, "stream_id", e)
                    },
                    expression: "udp.stream_id"
                }
            }, t._l(t.view_options, (function(e) {
                return s("el-option", {
                    key: e.value,
                    attrs: {
                        label: t.$t(e.label),
                        value: e.value
                    }
                })
            }
            )), 1)], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("devices_maintenance.IP_multicast")
                }
            }, [s("el-input", {
                model: {
                    value: t.udp.remote_host,
                    callback: function(e) {
                        t.$set(t.udp, "remote_host", e)
                    },
                    expression: "udp.remote_host"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("devices_maintenance.multicast_port")
                }
            }, [s("el-input-number", {
                attrs: {
                    "controls-position": "right"
                },
                model: {
                    value: t.udp.remote_port,
                    callback: function(e) {
                        t.$set(t.udp, "remote_port", e)
                    },
                    expression: "udp.remote_port"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("devices_maintenance.Play_address")
                }
            }, [s("el-input", {
                model: {
                    value: t.udp.remote_url,
                    callback: function(e) {
                        t.$set(t.udp, "remote_url", e)
                    },
                    expression: "udp.remote_url"
                }
            })], 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSubmit
                }
            }, [t._v(t._s(t.$t("button.save")))]), s("el-button", {
                on: {
                    click: t.onRefresh
                }
            }, [t._v(t._s(t.$t("button.refresh")))])], 1)], 1)], 1)], 1)
        }
          , St = []
          , Ut = {
            data: function() {
                return {
                    udp: {
                        enabled: !1,
                        stream_id: 0,
                        remote_host: "238.0.0.1",
                        remote_port: 1234,
                        remote_url: "udp://@238.0.0.1:1234"
                    },
                    view_options: [{
                        label: "video_codec.main_stream",
                        value: 0
                    }, {
                        label: "video_codec.sub_stream",
                        value: 1
                    }]
                }
            },
            created: function() {
                this.fetchData()
            },
            methods: {
                fetchData: function() {
                    var t = this;
                    Object(h["b"])("udp").then((function(e) {
                        t.udp = e.data.settings
                    }
                    ))
                },
                updateData: function() {
                    var t = this;
                    Object(h["e"])({
                        type: "udp",
                        settings: this.udp
                    }).then((function(e) {
                        t.onRefresh()
                    }
                    ))
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData()
                }
            }
        }
          , Pt = Ut
          , Mt = Object(p["a"])(Pt, jt, St, !1, null, null, null)
          , Rt = Mt.exports
          , It = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 5
                    },
                    lg: {
                        span: 12,
                        offset: 6
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 16,
                        offset: 4
                    }
                }
            }, [s("el-form", {
                ref: "form",
                attrs: {
                    "label-width": "120px"
                }
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("devices_maintenance.equipment")
                }
            }, [s("el-input", {
                model: {
                    value: t.p2p.deviceId,
                    callback: function(e) {
                        t.$set(t.p2p, "deviceId", e)
                    },
                    expression: "p2p.deviceId"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("user_management.password")
                }
            }, [s("el-input", {
                attrs: {
                    type: t.passwordType
                },
                model: {
                    value: t.p2p.password,
                    callback: function(e) {
                        t.$set(t.p2p, "password", e)
                    },
                    expression: "p2p.password"
                }
            }, [s("a", {
                staticStyle: {
                    "margin-right": "5px"
                },
                attrs: {
                    slot: "suffix",
                    href: "javascript:;"
                },
                on: {
                    click: function(e) {
                        return t.onSwitchType(t.passwordType)
                    }
                },
                slot: "suffix"
            }, [s("svg-icon", {
                attrs: {
                    "icon-class": "password" === t.passwordType ? "eye" : "eye-open"
                }
            })], 1)])], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("devices_maintenance.server")
                }
            }, [s("el-input", {
                model: {
                    value: t.p2p.url,
                    callback: function(e) {
                        t.$set(t.p2p, "url", e)
                    },
                    expression: "p2p.url"
                }
            })], 1), s("el-form-item", [s("el-popover", {
                staticStyle: {
                    "margin-right": "10px"
                },
                attrs: {
                    placement: "top",
                    title: "",
                    width: "325",
                    trigger: "click"
                }
            }, [s("qrcode-vue", {
                attrs: {
                    value: t.qrcodeValue,
                    size: 300,
                    level: "H"
                }
            }), s("el-button", {
                attrs: {
                    slot: "reference",
                    type: "danger"
                },
                slot: "reference"
            }, [t._v(" " + t._s(t.$t("button.qr_code")) + " ")])], 1), s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSubmit
                }
            }, [t._v(t._s(t.$t("button.save")))]), s("el-button", {
                on: {
                    click: t.onRefresh
                }
            }, [t._v(t._s(t.$t("button.refresh")))])], 1)], 1)], 1)], 1)
        }
          , Gt = []
          , Nt = (s("e9c4"),
        s("d7b0"))
          , Et = {
            components: {
                QrcodeVue: Nt["a"]
            },
            data: function() {
                return {
                    p2p: {
                        deviceId: "",
                        password: "",
                        url: ""
                    },
                    passwordType: "password"
                }
            },
            computed: {
                qrcodeValue: function() {
                    return JSON.stringify(this.p2p)
                }
            },
            created: function() {
                this.fetchData()
            },
            methods: {
                onSwitchType: function(t) {
                    this.passwordType = "password" === t ? "text" : "password"
                },
                fetchData: function() {
                    var t = this;
                    Object(h["b"])("p2p").then((function(e) {
                        t.p2p = e.data.settings
                    }
                    ))
                },
                updateData: function() {
                    var t = this;
                    Object(h["e"])({
                        type: "p2p",
                        settings: this.p2p
                    }).then((function(e) {
                        t.onRefresh()
                    }
                    ))
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData()
                }
            }
        }
          , qt = Et
          , Ft = Object(p["a"])(qt, It, Gt, !1, null, null, null)
          , Vt = Ft.exports
          , Ht = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 5
                    },
                    lg: {
                        span: 12,
                        offset: 6
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 16,
                        offset: 4
                    }
                }
            }, [s("el-form", {
                ref: "form",
                attrs: {
                    "label-width": "120px"
                }
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("devices_maintenance.equipment")
                }
            }, [s("el-input", {
                model: {
                    value: t.webrtc.deviceId,
                    callback: function(e) {
                        t.$set(t.webrtc, "deviceId", e)
                    },
                    expression: "webrtc.deviceId"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("user_management.password")
                }
            }, [s("el-input", {
                attrs: {
                    type: t.passwordType
                },
                model: {
                    value: t.webrtc.password,
                    callback: function(e) {
                        t.$set(t.webrtc, "password", e)
                    },
                    expression: "webrtc.password"
                }
            }, [s("a", {
                staticStyle: {
                    "margin-right": "5px"
                },
                attrs: {
                    slot: "suffix",
                    href: "javascript:;"
                },
                on: {
                    click: function(e) {
                        return t.onSwitchType(t.passwordType)
                    }
                },
                slot: "suffix"
            }, [s("svg-icon", {
                attrs: {
                    "icon-class": "password" === t.passwordType ? "eye" : "eye-open"
                }
            })], 1)])], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("devices_maintenance.server")
                }
            }, [s("el-input", {
                model: {
                    value: t.webrtc.url,
                    callback: function(e) {
                        t.$set(t.webrtc, "url", e)
                    },
                    expression: "webrtc.url"
                }
            })], 1), s("el-form-item", [s("el-popover", {
                staticStyle: {
                    "margin-right": "10px"
                },
                attrs: {
                    placement: "top",
                    title: "",
                    width: "325",
                    trigger: "click"
                }
            }, [s("qrcode-vue", {
                attrs: {
                    value: t.qrcodeValue,
                    size: 300,
                    level: "H"
                }
            }), s("el-button", {
                attrs: {
                    slot: "reference",
                    type: "danger"
                },
                slot: "reference"
            }, [t._v(" " + t._s(t.$t("button.qr_code")) + " ")])], 1), s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSubmit
                }
            }, [t._v(t._s(t.$t("button.save")))]), s("el-button", {
                on: {
                    click: t.onRefresh
                }
            }, [t._v(t._s(t.$t("button.refresh")))])], 1)], 1)], 1)], 1)
        }
          , zt = []
          , At = {
            components: {
                QrcodeVue: Nt["a"]
            },
            data: function() {
                return {
                    webrtc: {
                        deviceId: "",
                        password: "",
                        url: ""
                    },
                    passwordType: "password"
                }
            },
            computed: {
                qrcodeValue: function() {
                    return JSON.stringify(this.webrtc)
                }
            },
            created: function() {
                this.fetchData()
            },
            methods: {
                onSwitchType: function(t) {
                    this.passwordType = "password" === t ? "text" : "password"
                },
                fetchData: function() {
                    var t = this;
                    Object(h["b"])("webrtc").then((function(e) {
                        t.webrtc = e.data.settings
                    }
                    ))
                },
                updateData: function() {
                    var t = this;
                    Object(h["e"])({
                        type: "webrtc",
                        settings: this.webrtc
                    }).then((function(e) {
                        t.onRefresh()
                    }
                    ))
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData()
                }
            }
        }
          , Jt = At
          , Qt = Object(p["a"])(Jt, Ht, zt, !1, null, null, null)
          , Wt = Qt.exports
          , Lt = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-col", {
                attrs: {
                    xl: {
                        span: 10,
                        offset: 5
                    },
                    lg: {
                        span: 12,
                        offset: 6
                    },
                    md: {
                        span: 16,
                        offset: 4
                    },
                    sm: {
                        span: 16,
                        offset: 4
                    }
                }
            }, [s("el-form", {
                ref: "form",
                attrs: {
                    "label-width": "120px"
                }
            }, [s("el-tabs", {
                model: {
                    value: t.activeName,
                    callback: function(e) {
                        t.activeName = e
                    },
                    expression: "activeName"
                }
            }, t._l(t.serial_port_enum, (function(e, a) {
                return s("el-tab-pane", {
                    attrs: {
                        label: "串口编号" + e,
                        name: e
                    }
                }, [t.uartTransmission[a] ? [s("el-form-item", {
                    attrs: {
                        label: "开启"
                    }
                }, [s("el-switch", {
                    model: {
                        value: t.uartTransmission[a].enabled,
                        callback: function(e) {
                            t.$set(t.uartTransmission[a], "enabled", e)
                        },
                        expression: "uartTransmission[index].enabled"
                    }
                })], 1), s("el-form-item", {
                    attrs: {
                        label: "波特率"
                    }
                }, [s("el-select", {
                    model: {
                        value: t.uartTransmission[a].baud_rate,
                        callback: function(e) {
                            t.$set(t.uartTransmission[a], "baud_rate", e)
                        },
                        expression: "uartTransmission[index].baud_rate"
                    }
                }, t._l(t.uartTransmission[a].baud_rate_enum, (function(t) {
                    return s("el-option", {
                        key: t,
                        attrs: {
                            label: t,
                            value: t
                        }
                    })
                }
                )), 1)], 1), s("el-form-item", {
                    attrs: {
                        label: "数据位"
                    }
                }, [s("el-select", {
                    model: {
                        value: t.uartTransmission[a].data_bits,
                        callback: function(e) {
                            t.$set(t.uartTransmission[a], "data_bits", e)
                        },
                        expression: "uartTransmission[index].data_bits"
                    }
                }, t._l(t.uartTransmission[a].data_bits_enum, (function(t) {
                    return s("el-option", {
                        key: t,
                        attrs: {
                            label: t,
                            value: t
                        }
                    })
                }
                )), 1)], 1), s("el-form-item", {
                    attrs: {
                        label: "数据校验"
                    }
                }, [s("el-select", {
                    model: {
                        value: t.uartTransmission[a].data_parity,
                        callback: function(e) {
                            t.$set(t.uartTransmission[a], "data_parity", e)
                        },
                        expression: "uartTransmission[index].data_parity"
                    }
                }, t._l(t.uartTransmission[a].data_parity_enum, (function(t) {
                    return s("el-option", {
                        key: t,
                        attrs: {
                            label: t,
                            value: t
                        }
                    })
                }
                )), 1)], 1), s("el-form-item", {
                    attrs: {
                        label: "停止位"
                    }
                }, [s("el-select", {
                    model: {
                        value: t.uartTransmission[a].stop_bits,
                        callback: function(e) {
                            t.$set(t.uartTransmission[a], "stop_bits", e)
                        },
                        expression: "uartTransmission[index].stop_bits"
                    }
                }, t._l(t.uartTransmission[a].stop_bits_enum, (function(t) {
                    return s("el-option", {
                        key: t,
                        attrs: {
                            label: t,
                            value: t
                        }
                    })
                }
                )), 1)], 1), s("el-form-item", {
                    attrs: {
                        label: "功能绑定"
                    }
                }, [s("el-select", {
                    model: {
                        value: t.uartTransmission[a].protocol_type,
                        callback: function(e) {
                            t.$set(t.uartTransmission[a], "protocol_type", e)
                        },
                        expression: "uartTransmission[index].protocol_type"
                    }
                }, t._l(t.uartTransmission[a].protocol_type_enum, (function(t) {
                    return s("el-option", {
                        key: t,
                        attrs: {
                            label: t,
                            value: t
                        }
                    })
                }
                )), 1)], 1), "UartToUdp" === t.uartTransmission[a].protocol_type ? [s("el-form-item", {
                    attrs: {
                        label: "UDP服务器IP"
                    }
                }, [s("el-input", {
                    model: {
                        value: t.uartTransmission[a].UartToUdp.udp_remote_host,
                        callback: function(e) {
                            t.$set(t.uartTransmission[a].UartToUdp, "udp_remote_host", e)
                        },
                        expression: "uartTransmission[index].UartToUdp.udp_remote_host"
                    }
                })], 1), s("el-form-item", {
                    attrs: {
                        label: "服务器端口"
                    }
                }, [s("el-input", {
                    model: {
                        value: t.uartTransmission[a].UartToUdp.udp_remote_port,
                        callback: function(e) {
                            t.$set(t.uartTransmission[a].UartToUdp, "udp_remote_port", e)
                        },
                        expression: "uartTransmission[index].UartToUdp.udp_remote_port"
                    }
                })], 1), s("el-form-item", {
                    attrs: {
                        label: "本地端口"
                    }
                }, [s("el-input", {
                    model: {
                        value: t.uartTransmission[a].UartToUdp.udp_local_port,
                        callback: function(e) {
                            t.$set(t.uartTransmission[a].UartToUdp, "udp_local_port", e)
                        },
                        expression: "uartTransmission[index].UartToUdp.udp_local_port"
                    }
                })], 1)] : "UartToTcp" === t.uartTransmission[a].protocol_type ? [s("el-form-item", {
                    attrs: {
                        label: "TCP服务器IP"
                    }
                }, [s("el-input", {
                    model: {
                        value: t.uartTransmission[a].UartToTcp.tcp_remote_host,
                        callback: function(e) {
                            t.$set(t.uartTransmission[a].UartToTcp, "tcp_remote_host", e)
                        },
                        expression: "uartTransmission[index].UartToTcp.tcp_remote_host"
                    }
                })], 1), s("el-form-item", {
                    attrs: {
                        label: "服务器端口"
                    }
                }, [s("el-input", {
                    model: {
                        value: t.uartTransmission[a].UartToTcp.tcp_remote_port,
                        callback: function(e) {
                            t.$set(t.uartTransmission[a].UartToTcp, "tcp_remote_port", e)
                        },
                        expression: "uartTransmission[index].UartToTcp.tcp_remote_port"
                    }
                })], 1), s("el-form-item", {
                    attrs: {
                        label: "心跳包间隔时间"
                    }
                }, [s("el-input", {
                    model: {
                        value: t.uartTransmission[a].UartToTcp.tcp_remote_heartbeat,
                        callback: function(e) {
                            t.$set(t.uartTransmission[a].UartToTcp, "tcp_remote_heartbeat", e)
                        },
                        expression: "uartTransmission[index].UartToTcp.tcp_remote_heartbeat"
                    }
                })], 1)] : t._e()] : t._e()], 2)
            }
            )), 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSubmit
                }
            }, [t._v(t._s(t.$t("button.save")))]), s("el-button", {
                on: {
                    click: t.onRefresh
                }
            }, [t._v(t._s(t.$t("button.refresh")))])], 1)], 1), s("div", [t._v(" 串口收发测试"), s("br")]), s("el-fieldset", [s("el-form", [s("el-form-item", {
                attrs: {
                    label: ""
                }
            }, [s("el-input", {
                attrs: {
                    type: "textarea"
                },
                model: {
                    value: t.serial_send_data,
                    callback: function(e) {
                        t.serial_send_data = e
                    },
                    expression: "serial_send_data"
                }
            })], 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSend
                }
            }, [t._v("发送")])], 1), s("el-form-item", {
                attrs: {
                    label: ""
                }
            }, [s("el-input", {
                attrs: {
                    type: "textarea"
                },
                model: {
                    value: t.serial_recv_data,
                    callback: function(e) {
                        t.serial_recv_data = e
                    },
                    expression: "serial_recv_data"
                }
            })], 1), s("el-form-item", [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onRecieve
                }
            }, [t._v("接收")])], 1)], 1)], 1)], 1)], 1)
        }
          , Bt = []
          , Kt = s("5530")
          , Xt = {
            components: {},
            data: function() {
                return {
                    serial_port_enum: ["1", "2", "3", "4"],
                    activeName: "1",
                    uartTransmission: [],
                    serial_send_data: "",
                    serial_recv_data: ""
                }
            },
            created: function() {
                this.fetchData()
            },
            methods: {
                fetchData: function() {
                    var t = this;
                    Object(h["b"])("uartTransmission").then((function(e) {
                        t.uartTransmission = e.data.settings;
                        for (var s = t.uartTransmission.length, a = s; a < 4; a++)
                            t.uartTransmission.push(Object(Kt["a"])(Object(Kt["a"])({}, t.uartTransmission[0]), {}, {
                                enabled: !1
                            }));
                        console.log("this.uartTransmission", t.uartTransmission)
                    }
                    ))
                },
                updateData: function() {
                    var t = this;
                    Object(h["e"])({
                        type: "uartTransmission",
                        settings: this.uartTransmission
                    }).then((function(e) {
                        t.onRefresh()
                    }
                    ))
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData()
                },
                onSend: function() {
                    Object(h["d"])({
                        serial_send_data: this.serial_send_data
                    })
                },
                onRecieve: function() {
                    var t = this;
                    Object(h["c"])().then((function(e) {
                        t.serial_recv_data = e.data.serial_recv_data
                    }
                    ))
                }
            }
        }
          , Yt = Xt
          , Zt = Object(p["a"])(Yt, Lt, Bt, !1, null, null, null)
          , te = Zt.exports
          , ee = function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("div", {
                staticClass: "app-container"
            }, [s("el-form", {
                ref: "rtmp_settings",
                attrs: {
                    model: t.rtmp_settings,
                    "label-width": "160px"
                }
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("rtmp_settings.enabled")
                }
            }, [s("el-switch", {
                model: {
                    value: t.rtmp_settings.enabled,
                    callback: function(e) {
                        t.$set(t.rtmp_settings, "enabled", e)
                    },
                    expression: "rtmp_settings.enabled"
                }
            })], 1), s("div", {
                directives: [{
                    name: "show",
                    rawName: "v-show",
                    value: t.rtmp_settings.enabled,
                    expression: "rtmp_settings.enabled"
                }]
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("rtmp_settings.stream_type")
                }
            }, [s("el-select", {
                model: {
                    value: t.rtmp_settings.stream_type,
                    callback: function(e) {
                        t.$set(t.rtmp_settings, "stream_type", e)
                    },
                    expression: "rtmp_settings.stream_type"
                }
            }, t._l(t.view_options, (function(e) {
                return s("el-option", {
                    key: e.value,
                    attrs: {
                        label: t.$t(e.label),
                        value: e.value
                    }
                })
            }
            )), 1)], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("rtmp_settings.remote_host")
                }
            }, [s("el-input", {
                model: {
                    value: t.rtmp_settings.remote_host,
                    callback: function(e) {
                        t.$set(t.rtmp_settings, "remote_host", e)
                    },
                    expression: "rtmp_settings.remote_host"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("rtmp_settings.remote_port")
                }
            }, [s("el-input-number", {
                model: {
                    value: t.rtmp_settings.remote_port,
                    callback: function(e) {
                        t.$set(t.rtmp_settings, "remote_port", e)
                    },
                    expression: "rtmp_settings.remote_port"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("rtmp_settings.app_name")
                }
            }, [s("el-input", {
                model: {
                    value: t.rtmp_settings.app_name,
                    callback: function(e) {
                        t.$set(t.rtmp_settings, "app_name", e)
                    },
                    expression: "rtmp_settings.app_name"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("rtmp_settings.stream_id")
                }
            }, [s("el-input", {
                model: {
                    value: t.rtmp_settings.stream_id,
                    callback: function(e) {
                        t.$set(t.rtmp_settings, "stream_id", e)
                    },
                    expression: "rtmp_settings.stream_id"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("rtmp_settings.illustrate")
                }
            }, [s("div", [t._v(t._s(t.$t("rtmp_settings.illustrate_context_1")))]), s("div", [t._v(t._s(t.$t("rtmp_settings.illustrate_context_2")))]), s("div", [t._v(t._s(t.$t("rtmp_settings.illustrate_context_3")))]), s("div", [t._v(t._s(t.$t("rtmp_settings.illustrate_context_4")))]), s("div", [t._v(t._s(t.$t("rtmp_settings.illustrate_context_5")))]), s("div", [t._v(t._s(t.$t("rtmp_settings.illustrate_context_6")))])])], 1), s("el-form-item", {
                directives: [{
                    name: "permission",
                    rawName: "v-permission",
                    value: ["admin", "operator"],
                    expression: "['admin', 'operator']"
                }],
                staticClass: "mt20",
                attrs: {
                    "label-width": "120px"
                }
            }, [s("el-button", {
                attrs: {
                    type: "primary"
                },
                on: {
                    click: t.onSubmit
                }
            }, [t._v(t._s(t.$t("button.save")))]), s("el-button", {
                on: {
                    click: t.onRefresh
                }
            }, [t._v(t._s(t.$t("button.refresh")))]), s("el-button", {
                attrs: {
                    type: "warning"
                },
                on: {
                    click: t.onDefault
                }
            }, [t._v(t._s(t.$t("button.default")))])], 1)], 1)], 1)
        }
          , se = []
          , ae = (s("b64b"),
        s("61f7"))
          , re = {
            directives: {
                permission: W["a"]
            },
            data: function() {
                return {
                    rtmp_settings: {
                        enabled: null,
                        stream_type: null,
                        remote_host: null,
                        remote_port: null,
                        app_name: null,
                        stream_id: null
                    },
                    prev_data: null,
                    view_options: [{
                        label: "video_codec.main_stream",
                        value: 0
                    }, {
                        label: "video_codec.sub_stream",
                        value: 1
                    }]
                }
            },
            created: function() {
                this.fetchData()
            },
            methods: {
                fetchData: function() {
                    var t = this;
                    Object(h["b"])("rtmp").then((function(e) {
                        t.rtmp_settings = e.data.settings,
                        window.console.log(t.rtmp_settings),
                        t.prev_data = JSON.parse(JSON.stringify(t.rtmp_settings))
                    }
                    ))
                },
                updateData: function() {
                    Object(h["e"])({
                        type: "rtmp",
                        settings: this.rtmp_settings
                    }).then(),
                    this.isNeedRestart() && Object(ae["a"])(10)
                },
                isNeedRestart: function() {
                    return !1
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData(),
                    window.console.log("reload!")
                },
                onDefault: function() {
                    var t = this;
                    Object(h["b"])("rtmp_default").then((function(e) {
                        t.rtmp_settings = e.data.settings,
                        window.console.log(t.rtmp_settings)
                    }
                    ))
                }
            }
        }
          , ne = re
          , oe = (s("1032"),
        Object(p["a"])(ne, ee, se, !1, null, "1bd1c7ea", null))
          , le = oe.exports
          , ie = {
            components: {
                http: d,
                rstp: mt,
                rtp: _t,
                FTP: $,
                smtp: A,
                qos: Ot,
                p8201: yt,
                upnp: rt,
                ppoe: E,
                ntf: Y,
                ddns: C,
                UDP: Rt,
                P2P: Vt,
                Webrtc: Wt,
                UARTTransmission: te,
                RTMP: le
            },
            data: function() {
                return {
                    activeName: "tenth",
                    pages: {
                        first: {
                            istab: !0,
                            key: "first"
                        },
                        second: {
                            istab: !1,
                            key: "second"
                        },
                        third: {
                            istab: !1,
                            key: "third"
                        },
                        fourth: {
                            istab: !1,
                            key: "fourth"
                        },
                        fifth: {
                            istab: !1,
                            key: "fifth"
                        },
                        sixth: {
                            istab: !1,
                            key: "sixth"
                        },
                        eighth: {
                            istab: !1,
                            key: "eighth"
                        },
                        seventh: {
                            istab: !1,
                            key: "seventh"
                        },
                        ninth: {
                            istab: !1,
                            key: "ninth"
                        },
                        tenth: {
                            istab: !0,
                            key: "tenth"
                        },
                        eleventh: {
                            istab: !1,
                            key: "eleventh"
                        },
                        twelveth: {
                            istab: !1,
                            key: "twelveth"
                        },
                        thirteenth: {
                            istab: !1,
                            key: "thirteenth"
                        },
                        fourteenth: {
                            istab: !1,
                            key: "fourteenth"
                        },
                        fifteenth: {
                            istab: !1,
                            key: "fifteenth"
                        },
                        sixteenth: {
                            istab: !1,
                            key: "sixteenth"
                        },
                        seventeenth: {
                            istab: !1,
                            key: "seventeenth"
                        }
                    }
                }
            },
            created: function() {},
            mounted: function() {},
            methods: {
                handleClick: function(t) {
                    for (var e in this.pages)
                        t.name !== e ? this.pages[e]["istab"] = !1 : this.pages[e]["istab"] = !0
                }
            }
        }
          , ue = ie
          , me = (s("9f7f3"),
        Object(p["a"])(ue, a, r, !1, null, "bdebe0d0", null));
        e["default"] = me.exports
    },
    f8f9: function(t, e, s) {}
}]);
