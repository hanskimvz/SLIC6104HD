(window["webpackJsonp"] = window["webpackJsonp"] || []).push([["chunk-c65e1b8c"], {
    2684: function(t, e, s) {},
    2767: function(t, e, s) {
        "use strict";
        s("2684")
    },
    4381: function(t, e, s) {
        "use strict";
        s("d3b7"),
        s("caad"),
        s("2532");
        var i = s("4360");
        function n(t, e) {
            var s = e.value
              , n = i["a"].getters && i["a"].getters.roles;
            if (!(s && s instanceof Array))
                throw new Error("need roles! Like v-permission=\"['admin','editor']\"");
            if (s.length > 0) {
                var a = s
                  , r = n.some((function(t) {
                    return a.includes(t)
                }
                ));
                r || t.parentNode && t.parentNode.removeChild(t)
            }
        }
        var a = {
            inserted: function(t, e) {
                n(t, e)
            },
            update: function(t, e) {
                n(t, e)
            }
        }
          , r = function(t) {
            t.directive("permission", a)
        };
        window.Vue && (window["permission"] = a,
        Vue.use(r)),
        a.install = r;
        e["a"] = a
    },
    "5f28": function(t, e, s) {
        "use strict";
        s("c89d")
    },
    "6b83": function(t, e, s) {
        "use strict";
        s.r(e);
        var i = function() {
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
                key: "first",
                attrs: {
                    name: "first"
                }
            }, [s("span", {
                attrs: {
                    slot: "label"
                },
                slot: "label"
            }, [s("i", {
                staticClass: "el-icon-sort"
            }), t._v(" " + t._s(t.$t("network_settings.wired_network")))]), t.pages.first.istab ? s("ipSettings") : t._e()], 1), s("el-tab-pane", {
                key: "second",
                attrs: {
                    name: "second"
                }
            }, [s("span", {
                attrs: {
                    slot: "label"
                },
                slot: "label"
            }, [s("i", {
                staticClass: "el-icon-sort"
            }), t._v(t._s(t.$t("network_settings.wifi_settings")))]), t.pages.second.istab ? s("wifi") : t._e()], 1), s("el-tab-pane", {
                key: "third",
                attrs: {
                    name: "third"
                }
            }, [s("span", {
                attrs: {
                    slot: "label"
                },
                slot: "label"
            }, [s("i", {
                staticClass: "el-icon-sort"
            }), t._v(t._s(t.$t("network_settings.s4g_settings")))]), t.pages.third.istab ? s("net4g") : t._e()], 1)], 1)], 1)], 1)
        }
          , n = []
          , a = (s("b0c0"),
        function() {
            var t = this
              , e = t.$createElement
              , s = t._self._c || e;
            return s("el-form", {
                ref: "ip_settings",
                staticClass: "custom_form2 auto_wh mt20",
                attrs: {
                    model: t.ip_settings,
                    "label-width": "auto"
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
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("ip_settings.mac_address")
                }
            }, [s("el-input", {
                staticClass: "w200",
                attrs: {
                    readonly: !0
                },
                model: {
                    value: t.ip_settings.mac_address,
                    callback: function(e) {
                        t.$set(t.ip_settings, "mac_address", e)
                    },
                    expression: "ip_settings.mac_address"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("ip_settings.dhcp")
                }
            }, [s("el-switch", {
                model: {
                    value: t.ip_settings.dhcp,
                    callback: function(e) {
                        t.$set(t.ip_settings, "dhcp", e)
                    },
                    expression: "ip_settings.dhcp"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("ip_settings.self_adaption")
                }
            }, [s("el-switch", {
                model: {
                    value: t.ip_settings.self_adaption,
                    callback: function(e) {
                        t.$set(t.ip_settings, "self_adaption", e)
                    },
                    expression: "ip_settings.self_adaption"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("ip_settings.ipv4_addr")
                }
            }, [s("el-input", {
                staticClass: "w200",
                attrs: {
                    disabled: t.ip_settings.dhcp
                },
                model: {
                    value: t.ip_settings.ipv4_addr,
                    callback: function(e) {
                        t.$set(t.ip_settings, "ipv4_addr", e)
                    },
                    expression: "ip_settings.ipv4_addr"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("ip_settings.ipv4_mask")
                }
            }, [s("el-input", {
                staticClass: "w200",
                attrs: {
                    disabled: t.ip_settings.dhcp
                },
                model: {
                    value: t.ip_settings.ipv4_mask,
                    callback: function(e) {
                        t.$set(t.ip_settings, "ipv4_mask", e)
                    },
                    expression: "ip_settings.ipv4_mask"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("ip_settings.ipv4_gateway")
                }
            }, [s("el-input", {
                staticClass: "w200",
                attrs: {
                    disabled: t.ip_settings.dhcp
                },
                model: {
                    value: t.ip_settings.ipv4_gateway,
                    callback: function(e) {
                        t.$set(t.ip_settings, "ipv4_gateway", e)
                    },
                    expression: "ip_settings.ipv4_gateway"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("ip_settings.dns1")
                }
            }, [s("el-input", {
                staticClass: "w200",
                attrs: {
                    disabled: t.ip_settings.dhcp
                },
                model: {
                    value: t.ip_settings.dns1,
                    callback: function(e) {
                        t.$set(t.ip_settings, "dns1", e)
                    },
                    expression: "ip_settings.dns1"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("ip_settings.dns2")
                }
            }, [s("el-input", {
                staticClass: "w200",
                attrs: {
                    disabled: t.ip_settings.dhcp
                },
                model: {
                    value: t.ip_settings.dns2,
                    callback: function(e) {
                        t.$set(t.ip_settings, "dns2", e)
                    },
                    expression: "ip_settings.dns2"
                }
            })], 1), s("el-form-item", {
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
        )
          , r = []
          , o = (s("b64b"),
        s("e9c4"),
        s("4381"))
          , l = s("ab10")
          , c = s("61f7")
          , d = {
            directives: {
                permission: o["a"]
            },
            data: function() {
                return {
                    ip_settings: {
                        mac_address: "",
                        dhcp: !1,
                        self_adaption: !1,
                        ipv4_addr: "",
                        ipv4_mask: "",
                        ipv4_gateway: "",
                        ipv6_addr: "",
                        ipv6_gateway: "",
                        dns1: "",
                        dns2: ""
                    },
                    prev_data: null
                }
            },
            created: function() {
                this.fetchData()
            },
            methods: {
                fetchData: function() {
                    var t = this;
                    Object(l["b"])("ip").then((function(e) {
                        t.ip_settings = e.data.settings,
                        window.console.log(t.ip_settings),
                        t.prev_data = JSON.parse(JSON.stringify(t.ip_settings))
                    }
                    ))
                },
                updateData: function() {
                    Object(l["e"])({
                        type: "ip",
                        settings: this.ip_settings
                    }).then(),
                    this.isNeedRestart() && Object(c["a"])(10, this.ip_settings.ipv4_addr)
                },
                isNeedRestart: function() {
                    return this.ip_settings.dhcp !== this.prev_data.dhcp || this.ip_settings.self_adaption !== this.prev_data.self_adaption || this.ip_settings.ipv4_addr !== this.prev_data.ipv4_addr || this.ip_settings.ipv4_mask !== this.prev_data.ipv4_mask || this.ip_settings.ipv4_gateway !== this.prev_data.ipv4_gateway || this.ip_settings.dns1 !== this.prev_data.dns1 || this.ip_settings.dns2 !== this.prev_data.dns2
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
                    Object(l["b"])("ip_default").then((function(e) {
                        t.ip_settings = e.data.settings,
                        window.console.log(t.ip_settings)
                    }
                    ))
                }
            }
        }
          , f = d
          , p = (s("ab39"),
        s("2877"))
          , u = Object(p["a"])(f, a, r, !1, null, "2d84dd9a", null)
          , _ = u.exports
          , h = function() {
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
                attrs: {
                    "label-width": "120px"
                }
            }, [s("el-form-item", {
                attrs: {
                    label: t.$t("net_4g.enabled")
                }
            }, [s("el-switch", {
                model: {
                    value: t.net_4g.enabled,
                    callback: function(e) {
                        t.$set(t.net_4g, "enabled", e)
                    },
                    expression: "net_4g.enabled"
                }
            })], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("net_4g.status")
                }
            }, [t._v(" " + t._s("disconnected" === t.net_4g.net4G_status ? t.$t("wifi.not_connected") : t.$t("wifi.connected")) + " ")]), s("el-form-item", [s("el-button", {
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
          , m = []
          , b = {
            data: function() {
                return {
                    net_4g: {
                        enabled: !0,
                        net4G_status: ""
                    },
                    prev_data: null
                }
            },
            created: function() {
                this.fetchData()
            },
            methods: {
                fetchData: function() {
                    var t = this;
                    Object(l["b"])("net4g").then((function(e) {
                        t.net_4g = e.data.settings,
                        window.console.log(t.net_4g),
                        t.prev_data = JSON.parse(JSON.stringify(t.net_4g))
                    }
                    ))
                },
                updateData: function() {
                    var t = this;
                    delete this.net_4g.net4G_status,
                    Object(l["e"])({
                        type: "net4g",
                        settings: this.net_4g
                    }).then((function(e) {
                        t.onRefresh(),
                        t.isNeedRestart() && Object(c["a"])(15)
                    }
                    ))
                },
                isNeedRestart: function() {
                    return this.net_4g.enabled !== this.prev_data.enabled
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
          , g = b
          , w = Object(p["a"])(g, h, m, !1, null, null, null)
          , v = w.exports
          , k = function() {
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
                    label: t.$t("wifi.work_mode")
                }
            }, [s("el-radio-group", {
                model: {
                    value: t.wifi.wifi_mode,
                    callback: function(e) {
                        t.$set(t.wifi, "wifi_mode", e)
                    },
                    expression: "wifi.wifi_mode"
                }
            }, [s("el-radio", {
                attrs: {
                    label: "sta"
                }
            }, [t._v(t._s(t.$t("wifi.wlan")))]), s("el-radio", {
                attrs: {
                    label: "ap"
                }
            }, [t._v(t._s(t.$t("wifi.ap")))])], 1)], 1), "sta" === t.wifi.wifi_mode ? [s("el-form-item", {
                attrs: {
                    label: t.$t("wifi.ssid")
                }
            }, [s("el-autocomplete", {
                ref: "autoCom",
                staticStyle: {
                    width: "100%"
                },
                attrs: {
                    clearable: "",
                    "popper-class": "my-autocomplete",
                    "fetch-suggestions": t.querySearch,
                    placeholder: "请输入内容"
                },
                on: {
                    select: t.handleSelect
                },
                scopedSlots: t._u([{
                    key: "default",
                    fn: function(e) {
                        var i = e.item;
                        return [s("div", {
                            staticClass: "item"
                        }, [s("div", {
                            staticClass: "name"
                        }, [t._v(" " + t._s(i.value) + " ")]), s("div", {
                            staticClass: "strength"
                        }, [t._v(" " + t._s(1 === i.strength ? "信号强" : "信号弱") + " ")])])]
                    }
                }], null, !1, 3641403612),
                model: {
                    value: t.wifi.wifi_ssid,
                    callback: function(e) {
                        t.$set(t.wifi, "wifi_ssid", e)
                    },
                    expression: "wifi.wifi_ssid"
                }
            }, [s("el-button", {
                attrs: {
                    slot: "append",
                    icon: "el-icon-search"
                },
                on: {
                    click: t.handleIconClick
                },
                slot: "append"
            })], 1)], 1), s("el-form-item", {
                attrs: {
                    label: t.$t("wifi.password")
                }
            }, [s("el-input", {
                attrs: {
                    type: t.passwordType
                },
                model: {
                    value: t.wifi.wifi_password,
                    callback: function(e) {
                        t.$set(t.wifi, "wifi_password", e)
                    },
                    expression: "wifi.wifi_password"
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
            })], 1)])], 1)] : t._e(), s("el-form-item", {
                attrs: {
                    label: t.$t("wifi.status")
                }
            }, [t._v(" " + t._s("disconnected" === t.wifi.wifi_status ? t.$t("wifi.not_connected") : t.$t("wifi.connected")) + " ")]), s("el-form-item", {
                attrs: {
                    label: "信号强度"
                }
            }, [t._v(" " + t._s(t.getWifiStrengthText(t.wifi.wifi_strength)) + " ")]), s("el-form-item", [s("el-button", {
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
            }, [t._v(t._s(t.$t("button.default")))])], 1)], 2)], 1)], 1)
        }
          , y = []
          , $ = s("c7eb")
          , x = s("1da1")
          , S = {
            data: function() {
                return {
                    wifi: {
                        wifi_password: "",
                        wifi_ssid: "",
                        wifi_mode: "sta"
                    },
                    passwordType: "password",
                    ssids: []
                }
            },
            created: function() {
                this.fetchData(),
                this.loadSSIDs()
            },
            methods: {
                getWifiStrengthText: function(t) {
                    switch (t) {
                    case 1:
                        return "很强";
                    case 2:
                        return "强";
                    case 3:
                        return "中";
                    case 4:
                        return "弱"
                    }
                },
                querySearch: function(t, e) {
                    var s = this.ssids;
                    return e(s)
                },
                loadSSIDs: function() {
                    var t = this;
                    return Object(x["a"])(Object($["a"])().mark((function e() {
                        return Object($["a"])().wrap((function(e) {
                            while (1)
                                switch (e.prev = e.next) {
                                case 0:
                                    return e.next = 2,
                                    Object(l["a"])("wifi").then((function(e) {
                                        t.ssids = e.data
                                    }
                                    ));
                                case 2:
                                case "end":
                                    return e.stop()
                                }
                        }
                        ), e)
                    }
                    )))()
                },
                handleSelect: function(t) {
                    this.wifi.wifi_ssid = t.value
                },
                handleIconClick: function() {
                    var t = this;
                    return Object(x["a"])(Object($["a"])().mark((function e() {
                        return Object($["a"])().wrap((function(e) {
                            while (1)
                                switch (e.prev = e.next) {
                                case 0:
                                    return e.next = 2,
                                    t.loadSSIDs();
                                case 2:
                                    t.$refs.autoCom.focus();
                                case 3:
                                case "end":
                                    return e.stop()
                                }
                        }
                        ), e)
                    }
                    )))()
                },
                onSwitchType: function(t) {
                    this.passwordType = "password" === t ? "text" : "password"
                },
                fetchData: function() {
                    var t = this;
                    Object(l["b"])("wifi").then((function(e) {
                        t.wifi = e.data.settings
                    }
                    ))
                },
                updateData: function() {
                    var t = this;
                    delete this.wifi.wifi_status,
                    Object(l["e"])({
                        type: "wifi",
                        settings: this.wifi
                    }).then((function(e) {
                        t.onRefresh()
                    }
                    ))
                },
                onDefault: function() {
                    this.wifi.wifi_mode = "ap"
                },
                onSubmit: function() {
                    this.updateData()
                },
                onRefresh: function() {
                    this.fetchData()
                }
            }
        }
          , O = S
          , D = (s("5f28"),
        Object(p["a"])(O, k, y, !1, null, null, null))
          , C = D.exports
          , j = {
            components: {
                ipSettings: _,
                net4g: v,
                wifi: C
            },
            data: function() {
                return {
                    activeName: "first",
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
                            istab: !1,
                            key: "tenth"
                        },
                        eleventh: {
                            istab: !1,
                            key: "eleventh"
                        }
                    }
                }
            },
            created: function() {},
            mounted: function() {},
            methods: {
                handleClick: function(t) {
                    for (var e in this.pages)
                        this.pages[e]["istab"] = t.name === e
                }
            }
        }
          , N = j
          , R = (s("2767"),
        Object(p["a"])(N, i, n, !1, null, "2c411c6e", null));
        e["default"] = R.exports
    },
    ab10: function(t, e, s) {
        "use strict";
        s.d(e, "b", (function() {
            return n
        }
        )),
        s.d(e, "e", (function() {
            return a
        }
        )),
        s.d(e, "a", (function() {
            return r
        }
        )),
        s.d(e, "d", (function() {
            return o
        }
        )),
        s.d(e, "c", (function() {
            return l
        }
        ));
        var i = s("b775");
        function n(t) {
            return Object(i["a"])({
                url: "/v1/network/settings",
                method: "get",
                params: {
                    query: t
                }
            })
        }
        function a(t) {
            return Object(i["a"])({
                url: "/v1/network/update",
                method: "post",
                data: t
            })
        }
        function r(t) {
            return Object(i["a"])({
                url: "/v1/network/ssids",
                method: "get",
                params: {
                    query: t
                }
            })
        }
        function o(t) {
            return Object(i["a"])({
                url: "/v1/network/sendUARTTestData",
                method: "post",
                data: t
            })
        }
        function l() {
            return Object(i["a"])({
                url: "/v1/network/recieveUARTTestData",
                method: "get"
            })
        }
    },
    ab39: function(t, e, s) {
        "use strict";
        s("d10e")
    },
    c89d: function(t, e, s) {},
    d10e: function(t, e, s) {},
    e9c4: function(t, e, s) {
        var i = s("23e7")
          , n = s("d066")
          , a = s("d039")
          , r = n("JSON", "stringify")
          , o = /[\uD800-\uDFFF]/g
          , l = /^[\uD800-\uDBFF]$/
          , c = /^[\uDC00-\uDFFF]$/
          , d = function(t, e, s) {
            var i = s.charAt(e - 1)
              , n = s.charAt(e + 1);
            return l.test(t) && !c.test(n) || c.test(t) && !l.test(i) ? "\\u" + t.charCodeAt(0).toString(16) : t
        }
          , f = a((function() {
            return '"\\udf06\\ud834"' !== r("\udf06\ud834") || '"\\udead"' !== r("\udead")
        }
        ));
        r && i({
            target: "JSON",
            stat: !0,
            forced: f
        }, {
            stringify: function(t, e, s) {
                var i = r.apply(null, arguments);
                return "string" == typeof i ? i.replace(o, d) : i
            }
        })
    }
}]);
