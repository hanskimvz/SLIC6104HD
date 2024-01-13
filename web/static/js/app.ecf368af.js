(window["webpackJsonp"] = window["webpackJsonp"] || []).push([["app"], {
    0: function(e, t, a) {
        e.exports = a("56d7")
    },
    "0781": function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("24ab")
          , o = a.n(i)
          , n = a("83d6")
          , r = a.n(n)
          , s = r.a.showSettings
          , d = r.a.fixedHeader
          , c = r.a.sidebarLogo
          , l = {
            showSettings: s,
            theme: o.a.theme,
            fixedHeader: d,
            sidebarLogo: c
        }
          , m = {
            CHANGE_SETTING: function(e, t) {
                var a = t.key
                  , i = t.value;
                e.hasOwnProperty(a) && (e[a] = i)
            }
        }
          , u = {
            changeSetting: function(e, t) {
                var a = e.commit;
                a("CHANGE_SETTING", t)
            }
        };
        t["default"] = {
            namespaced: !0,
            state: l,
            mutations: m,
            actions: u
        }
    },
    "0ae2d": function(e, t, a) {
        "use strict";
        a("cbd7")
    },
    "0cfd": function(e, t, a) {
        "use strict";
        a("d52e")
    },
    "0f9a": function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("c7eb")
          , o = a("1da1")
          , n = (a("b0c0"),
        a("d3b7"),
        a("498a"),
        a("b775"));
        function r(e) {
            return Object(n["a"])({
                url: "/v1/user/login",
                method: "post",
                data: e
            })
        }
        function s(e) {
            return Object(n["a"])({
                url: "/v1/user/info",
                method: "get",
                params: {
                    token: e
                }
            })
        }
        function d() {
            return Object(n["a"])({
                url: "/v1/user/logout",
                method: "post"
            })
        }
        var c = a("5f87")
          , l = a("a18c")
          , m = {
            token: Object(c["a"])(),
            name: "",
            avatar: "",
            introduction: "",
            roles: []
        }
          , u = {
            SET_TOKEN: function(e, t) {
                e.token = t
            },
            SET_INTRODUCTION: function(e, t) {
                e.introduction = t
            },
            SET_NAME: function(e, t) {
                e.name = t
            },
            SET_AVATAR: function(e, t) {
                e.avatar = t
            },
            SET_ROLES: function(e, t) {
                e.roles = t
            }
        }
          , _ = {
            login: function(e, t) {
                var a = e.commit
                  , i = t.username
                  , o = t.password;
                return new Promise((function(e, t) {
                    r({
                        username: i.trim(),
                        password: o
                    }).then((function(t) {
                        var i = t.data;
                        a("SET_TOKEN", i.token),
                        Object(c["c"])(i.token),
                        e()
                    }
                    )).catch((function(e) {
                        t(e)
                    }
                    ))
                }
                ))
            },
            getInfo: function(e) {
                var t = e.commit
                  , a = e.state;
                return new Promise((function(e, i) {
                    s(a.token).then((function(a) {
                        var o = a.data;
                        o || i("Verification failed, please Login again.");
                        var n = o.roles
                          , r = o.name
                          , s = o.avatar
                          , d = o.introduction;
                        (!n || n.length <= 0) && i("getInfo: roles must be a non-null array!"),
                        t("SET_ROLES", n),
                        t("SET_NAME", r),
                        t("SET_AVATAR", s),
                        t("SET_INTRODUCTION", d),
                        e(o)
                    }
                    )).catch((function(e) {
                        i(e)
                    }
                    ))
                }
                ))
            },
            logout: function(e) {
                var t = e.commit
                  , a = e.state
                  , i = e.dispatch;
                return new Promise((function(e, o) {
                    d(a.token).then((function() {
                        t("SET_TOKEN", ""),
                        t("SET_ROLES", []),
                        Object(c["b"])(),
                        Object(l["d"])(),
                        i("tagsView/delAllViews", null, {
                            root: !0
                        }),
                        e()
                    }
                    )).catch((function(e) {
                        o(e)
                    }
                    ))
                }
                ))
            },
            resetToken: function(e) {
                var t = e.commit;
                return new Promise((function(e) {
                    t("SET_TOKEN", ""),
                    t("SET_ROLES", []),
                    Object(c["b"])(),
                    e()
                }
                ))
            },
            changeRoles: function(e, t) {
                return Object(o["a"])(Object(i["a"])().mark((function a() {
                    var o, n, r, s, d, m;
                    return Object(i["a"])().wrap((function(a) {
                        while (1)
                            switch (a.prev = a.next) {
                            case 0:
                                return o = e.commit,
                                n = e.dispatch,
                                r = t + "-token",
                                o("SET_TOKEN", r),
                                Object(c["c"])(r),
                                a.next = 6,
                                n("getInfo");
                            case 6:
                                return s = a.sent,
                                d = s.roles,
                                Object(l["d"])(),
                                a.next = 11,
                                n("permission/generateRoutes", d, {
                                    root: !0
                                });
                            case 11:
                                m = a.sent,
                                l["c"].addRoutes(m),
                                n("tagsView/delAllViews", null, {
                                    root: !0
                                });
                            case 14:
                            case "end":
                                return a.stop()
                            }
                    }
                    ), a)
                }
                )))()
            }
        };
        t["default"] = {
            namespaced: !0,
            state: m,
            mutations: u,
            actions: _
        }
    },
    "17df": function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("e017")
          , o = a.n(i)
          , n = a("21a1")
          , r = a.n(n)
          , s = new o.a({
            id: "icon-international",
            use: "icon-international-usage",
            viewBox: "0 0 128 128",
            content: '<symbol xmlns="http://www.w3.org/2000/svg" viewBox="0 0 128 128" id="icon-international"><path d="M83.287 103.01c-1.57-3.84-6.778-10.414-15.447-19.548-2.327-2.444-2.182-4.306-1.338-9.862v-.64c.553-3.81 1.513-6.05 14.313-8.087 6.516-1.018 8.203 1.57 10.589 5.178l.785 1.193a12.625 12.625 0 0 0 6.43 5.207c1.134.524 2.53 1.164 4.421 2.24 4.596 2.53 4.596 5.41 4.596 11.753v.727a26.91 26.91 0 0 1-5.178 17.454 59.055 59.055 0 0 1-19.025 11.026c3.49-6.546.814-14.313 0-16.553l-.146-.087zM64 5.12a58.502 58.502 0 0 1 25.484 5.818 54.313 54.313 0 0 0-12.859 10.327c-.93 1.28-1.716 2.473-2.472 3.579-2.444 3.694-3.637 5.352-5.818 5.614a25.105 25.105 0 0 1-4.219 0c-4.276-.29-10.094-.64-11.956 4.422-1.193 3.23-1.396 11.956 2.444 16.495.66 1.077.778 2.4.32 3.578a7.01 7.01 0 0 1-2.066 3.229 18.938 18.938 0 0 1-2.909-2.91 18.91 18.91 0 0 0-8.32-6.603c-1.25-.349-2.647-.64-3.985-.93-3.782-.786-8.03-1.688-9.019-3.812a14.895 14.895 0 0 1-.727-5.818 21.935 21.935 0 0 0-1.396-9.25 8.873 8.873 0 0 0-5.557-4.946A58.705 58.705 0 0 1 64 5.12zM0 64c0 35.346 28.654 64 64 64 35.346 0 64-28.654 64-64 0-35.346-28.654-64-64-64C28.654 0 0 28.654 0 64z" /></symbol>'
        });
        r.a.add(s);
        t["default"] = s
    },
    "18f0": function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("e017")
          , o = a.n(i)
          , n = a("21a1")
          , r = a.n(n)
          , s = new o.a({
            id: "icon-link",
            use: "icon-link-usage",
            viewBox: "0 0 128 128",
            content: '<symbol xmlns="http://www.w3.org/2000/svg" viewBox="0 0 128 128" id="icon-link"><path d="M115.625 127.937H.063V12.375h57.781v12.374H12.438v90.813h90.813V70.156h12.374z" /><path d="M116.426 2.821l8.753 8.753-56.734 56.734-8.753-8.745z" /><path d="M127.893 37.982h-12.375V12.375H88.706V0h39.187z" /></symbol>'
        });
        r.a.add(s);
        t["default"] = s
    },
    1981: function(e, t, a) {},
    2224: function(e, t, a) {
        "use strict";
        a("5031")
    },
    "24ab": function(e, t, a) {
        e.exports = {
            theme: "#4796ff"
        }
    },
    2580: function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("e017")
          , o = a.n(i)
          , n = a("21a1")
          , r = a.n(n)
          , s = new o.a({
            id: "icon-language",
            use: "icon-language-usage",
            viewBox: "0 0 128 128",
            content: '<symbol xmlns="http://www.w3.org/2000/svg" viewBox="0 0 128 128" id="icon-language"><path d="M84.742 36.8c2.398 7.2 5.595 12.8 11.19 18.4 4.795-4.8 7.992-11.2 10.39-18.4h-21.58zm-52.748 40h20.78l-10.39-28-10.39 28z" /><path d="M111.916 0H16.009C7.218 0 .025 7.2.025 16v96c0 8.8 7.193 16 15.984 16h95.907c8.791 0 15.984-7.2 15.984-16V16c0-8.8-6.394-16-15.984-16zM72.754 103.2c-1.598 1.6-3.197 1.6-4.795 1.6-.8 0-2.398 0-3.197-.8-.8-.8-1.599 0-1.599-.8s-.799-1.6-1.598-3.2c-.8-1.6-.8-2.4-1.599-4l-3.196-8.8H28.797L25.6 96c-1.598 3.2-2.398 5.6-3.197 7.2-.8 1.6-2.398 1.6-4.795 1.6-1.599 0-3.197-.8-4.796-1.6-1.598-1.6-2.397-2.4-2.397-4 0-.8 0-1.6.799-3.2.8-1.6.8-2.4 1.598-4l17.583-44.8c.8-1.6.8-3.2 1.599-4.8.799-1.6 1.598-3.2 2.397-4 .8-.8 1.599-2.4 3.197-3.2 1.599-.8 3.197-.8 4.796-.8 1.598 0 3.196 0 4.795.8 1.598.8 2.398 1.6 3.197 3.2.799.8 1.598 2.4 2.397 4 .8 1.6 1.599 3.2 2.398 5.6l17.583 44c1.598 3.2 2.398 5.6 2.398 7.2-.8.8-1.599 2.4-2.398 4zM116.711 72c-8.791-3.2-15.185-7.2-20.78-12-5.594 5.6-12.787 9.6-21.579 12l-2.397-4c8.791-2.4 15.984-5.6 21.579-11.2C87.939 51.2 83.144 44 81.545 36h-7.992v-3.2h21.58c-1.6-2.4-3.198-5.6-4.796-8l2.397-.8c1.599 2.4 3.997 5.6 5.595 8.8h19.98v4h-7.992c-2.397 8-6.393 15.2-11.189 20 5.595 4.8 11.988 8.8 20.78 11.2l-3.197 4z" /></symbol>'
        });
        r.a.add(s);
        t["default"] = s
    },
    "279e": function(e, t, a) {},
    "2a3d": function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("e017")
          , o = a.n(i)
          , n = a("21a1")
          , r = a.n(n)
          , s = new o.a({
            id: "icon-password",
            use: "icon-password-usage",
            viewBox: "0 0 128 128",
            content: '<symbol xmlns="http://www.w3.org/2000/svg" viewBox="0 0 128 128" id="icon-password"><path d="M108.8 44.322H89.6v-5.36c0-9.04-3.308-24.163-25.6-24.163-23.145 0-25.6 16.881-25.6 24.162v5.361H19.2v-5.36C19.2 15.281 36.798 0 64 0c27.202 0 44.8 15.281 44.8 38.961v5.361zm-32 39.356c0-5.44-5.763-9.832-12.8-9.832-7.037 0-12.8 4.392-12.8 9.832 0 3.682 2.567 6.808 6.407 8.477v11.205c0 2.718 2.875 4.962 6.4 4.962 3.524 0 6.4-2.244 6.4-4.962V92.155c3.833-1.669 6.393-4.795 6.393-8.477zM128 64v49.201c0 8.158-8.645 14.799-19.2 14.799H19.2C8.651 128 0 121.359 0 113.201V64c0-8.153 8.645-14.799 19.2-14.799h89.6c10.555 0 19.2 6.646 19.2 14.799z" /></symbol>'
        });
        r.a.add(s);
        t["default"] = s
    },
    "2b29": function(e, t, a) {
        "use strict";
        a("f6c3")
    },
    "30c3": function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("e017")
          , o = a.n(i)
          , n = a("21a1")
          , r = a.n(n)
          , s = new o.a({
            id: "icon-example",
            use: "icon-example-usage",
            viewBox: "0 0 128 128",
            content: '<symbol xmlns="http://www.w3.org/2000/svg" viewBox="0 0 128 128" id="icon-example"><path d="M96.258 57.462h31.421C124.794 27.323 100.426 2.956 70.287.07v31.422a32.856 32.856 0 0 1 25.971 25.97zm-38.796-25.97V.07C27.323 2.956 2.956 27.323.07 57.462h31.422a32.856 32.856 0 0 1 25.97-25.97zm12.825 64.766v31.421c30.46-2.885 54.507-27.253 57.713-57.712H96.579c-2.886 13.466-13.146 23.726-26.292 26.291zM31.492 70.287H.07c2.886 30.46 27.253 54.507 57.713 57.713V96.579c-13.466-2.886-23.726-13.146-26.291-26.292z" /></symbol>'
        });
        r.a.add(s);
        t["default"] = s
    },
    "31c2": function(e, t, a) {
        "use strict";
        a.r(t),
        a.d(t, "filterAsyncRoutes", (function() {
            return r
        }
        ));
        var i = a("5530")
          , o = (a("d3b7"),
        a("caad"),
        a("2532"),
        a("159b"),
        a("99af"),
        a("a18c"));
        function n(e, t) {
            return !t.meta || !t.meta.roles || e.some((function(e) {
                return t.meta.roles.includes(e)
            }
            ))
        }
        function r(e, t) {
            var a = [];
            return e.forEach((function(e) {
                var o = Object(i["a"])({}, e);
                n(t, o) && (o.children && (o.children = r(o.children, t)),
                a.push(o))
            }
            )),
            a
        }
        var s = {
            routes: [],
            addRoutes: []
        }
          , d = {
            SET_ROUTES: function(e, t) {
                e.addRoutes = t,
                e.routes = o["b"].concat(t)
            }
        }
          , c = {
            generateRoutes: function(e, t) {
                var a = e.commit;
                return new Promise((function(e) {
                    var i;
                    i = t.includes("admin") ? o["a"] || [] : r(o["a"], t),
                    a("SET_ROUTES", i),
                    e(i)
                }
                ))
            }
        };
        t["default"] = {
            namespaced: !0,
            state: s,
            mutations: d,
            actions: c
        }
    },
    4360: function(e, t, a) {
        "use strict";
        a("13d5"),
        a("d3b7"),
        a("ddb0"),
        a("ac1f"),
        a("5319");
        var i = a("2b0e")
          , o = a("2f62")
          , n = (a("b0c0"),
        {
            sidebar: function(e) {
                return e.app.sidebar
            },
            language: function(e) {
                return e.app.language
            },
            device: function(e) {
                return e.app.device
            },
            token: function(e) {
                return e.user.token
            },
            avatar: function(e) {
                return e.user.avatar
            },
            name: function(e) {
                return e.user.name
            },
            introduction: function(e) {
                return e.user.introduction
            },
            roles: function(e) {
                return e.user.roles
            },
            permission_routes: function(e) {
                return e.permission.routes
            },
            errorLogs: function(e) {
                return e.errorLog.logs
            }
        })
          , r = n;
        i["default"].use(o["a"]);
        var s = a("c653")
          , d = s.keys().reduce((function(e, t) {
            var a = t.replace(/^\.\/(.*)\.\w+$/, "$1")
              , i = s(t);
            return e[a] = i.default,
            e
        }
        ), {})
          , c = new o["a"].Store({
            modules: d,
            getters: r
        });
        t["a"] = c
    },
    "47f1": function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("e017")
          , o = a.n(i)
          , n = a("21a1")
          , r = a.n(n)
          , s = new o.a({
            id: "icon-table",
            use: "icon-table-usage",
            viewBox: "0 0 128 128",
            content: '<symbol xmlns="http://www.w3.org/2000/svg" viewBox="0 0 128 128" id="icon-table"><path d="M.006.064h127.988v31.104H.006V.064zm0 38.016h38.396v41.472H.006V38.08zm0 48.384h38.396v41.472H.006V86.464zM44.802 38.08h38.396v41.472H44.802V38.08zm0 48.384h38.396v41.472H44.802V86.464zM89.598 38.08h38.396v41.472H89.598zm0 48.384h38.396v41.472H89.598z" /><path d="M.006.064h127.988v31.104H.006V.064zm0 38.016h38.396v41.472H.006V38.08zm0 48.384h38.396v41.472H.006V86.464zM44.802 38.08h38.396v41.472H44.802V38.08zm0 48.384h38.396v41.472H44.802V86.464zM89.598 38.08h38.396v41.472H89.598zm0 48.384h38.396v41.472H89.598z" /></symbol>'
        });
        r.a.add(s);
        t["default"] = s
    },
    "4c54": function(e, t, a) {
        e.exports = a.p + "static/img/logo-icon.5a584440.png"
    },
    "4d49": function(e, t, a) {
        "use strict";
        a.r(t);
        a("a434");
        var i = {
            logs: []
        }
          , o = {
            ADD_ERROR_LOG: function(e, t) {
                e.logs.push(t)
            },
            CLEAR_ERROR_LOG: function(e) {
                e.logs.splice(0)
            }
        }
          , n = {
            addErrorLog: function(e, t) {
                var a = e.commit;
                a("ADD_ERROR_LOG", t)
            },
            clearErrorLog: function(e) {
                var t = e.commit;
                t("CLEAR_ERROR_LOG")
            }
        };
        t["default"] = {
            namespaced: !0,
            state: i,
            mutations: o,
            actions: n
        }
    },
    "4df5": function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("e017")
          , o = a.n(i)
          , n = a("21a1")
          , r = a.n(n)
          , s = new o.a({
            id: "icon-eye",
            use: "icon-eye-usage",
            viewBox: "0 0 128 64",
            content: '<symbol xmlns="http://www.w3.org/2000/svg" viewBox="0 0 128 64" id="icon-eye"><path d="M127.072 7.994c1.37-2.208.914-5.152-.914-6.87-2.056-1.717-4.797-1.226-6.396.982-.229.245-25.586 32.382-55.74 32.382-29.24 0-55.74-32.382-55.968-32.627-1.6-1.963-4.57-2.208-6.397-.49C-.17 3.086-.399 6.275 1.2 8.238c.457.736 5.94 7.36 14.62 14.72L4.17 35.96c-1.828 1.963-1.6 5.152.228 6.87.457.98 1.6 1.471 2.742 1.471s2.284-.49 3.198-1.472l12.564-13.983c5.94 4.416 13.021 8.587 20.788 11.53l-4.797 17.418c-.685 2.699.686 5.397 3.198 6.133h1.37c2.057 0 3.884-1.472 4.341-3.68L52.6 42.83c3.655.736 7.538 1.227 11.422 1.227 3.883 0 7.767-.49 11.422-1.227l4.797 17.173c.457 2.208 2.513 3.68 4.34 3.68.457 0 .914 0 1.143-.246 2.513-.736 3.883-3.434 3.198-6.133l-4.797-17.172c7.767-2.944 14.848-7.114 20.788-11.53l12.336 13.738c.913.981 2.056 1.472 3.198 1.472s2.284-.49 3.198-1.472c1.828-1.963 1.828-4.906.228-6.87l-11.65-13.001c9.366-7.36 14.849-14.474 14.849-14.474z" /></symbol>'
        });
        r.a.add(s);
        t["default"] = s
    },
    5031: function(e, t, a) {},
    "51ff": function(e, t, a) {
        var i = {
            "./dashboard.svg": "f782",
            "./example.svg": "30c3",
            "./eye-open.svg": "d7ec",
            "./eye.svg": "4df5",
            "./form.svg": "eb1b",
            "./international.svg": "17df",
            "./language.svg": "2580",
            "./link.svg": "18f0",
            "./nested.svg": "dcf8",
            "./password.svg": "2a3d",
            "./table.svg": "47f1",
            "./tree.svg": "93cd",
            "./user.svg": "b3b5"
        };
        function o(e) {
            var t = n(e);
            return a(t)
        }
        function n(e) {
            if (!a.o(i, e)) {
                var t = new Error("Cannot find module '" + e + "'");
                throw t.code = "MODULE_NOT_FOUND",
                t
            }
            return i[e]
        }
        o.keys = function() {
            return Object.keys(i)
        }
        ,
        o.resolve = n,
        e.exports = o,
        o.id = "51ff"
    },
    "56d7": function(e, t, a) {
        "use strict";
        a.r(t);
        a("e260"),
        a("e6cf"),
        a("cca6"),
        a("a79d");
        var i = a("2b0e")
          , o = (a("f5df1"),
        a("5c96"))
          , n = a.n(o)
          , r = (a("0fae"),
        a("24ab"),
        a("b20f"),
        function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("div", {
                attrs: {
                    id: "app"
                }
            }, [a("router-view")], 1)
        }
        )
          , s = []
          , d = {
            name: "App"
        }
          , c = d
          , l = a("2877")
          , m = Object(l["a"])(c, r, s, !1, null, null, null)
          , u = m.exports
          , _ = a("4360")
          , p = a("a18c")
          , g = a("9923")
          , h = (a("d81d"),
        a("d3b7"),
        a("ddb0"),
        function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return e.isExternal ? a("div", e._g({
                staticClass: "svg-external-icon svg-icon",
                style: e.styleExternalIcon
            }, e.$listeners)) : a("svg", e._g({
                class: e.svgClass,
                attrs: {
                    "aria-hidden": "true"
                }
            }, e.$listeners), [a("use", {
                attrs: {
                    "xlink:href": e.iconName
                }
            })])
        }
        )
          , f = []
          , v = a("61f7")
          , b = {
            name: "SvgIcon",
            props: {
                iconClass: {
                    type: String,
                    required: !0
                },
                className: {
                    type: String,
                    default: ""
                }
            },
            computed: {
                isExternal: function() {
                    return Object(v["b"])(this.iconClass)
                },
                iconName: function() {
                    return "#icon-".concat(this.iconClass)
                },
                svgClass: function() {
                    return this.className ? "svg-icon " + this.className : "svg-icon"
                },
                styleExternalIcon: function() {
                    return {
                        mask: "url(".concat(this.iconClass, ") no-repeat 50% 50%"),
                        "-webkit-mask": "url(".concat(this.iconClass, ") no-repeat 50% 50%")
                    }
                }
            }
        }
          , y = b
          , w = (a("2b29"),
        Object(l["a"])(y, h, f, !1, null, "f9f7fefc", null))
          , P = w.exports;
        i["default"].component("svg-icon", P);
        var S = a("51ff")
          , T = function(e) {
            return e.keys().map(e)
        };
        T(S);
        var I = a("c7eb")
          , D = a("5530")
          , z = a("1da1")
          , C = a("323e")
          , k = a.n(C)
          , A = (a("a5d8"),
        a("5f87"))
          , M = (a("99af"),
        a("83d6"))
          , x = a.n(M)
          , R = x.a.title || "Vue Admin Template";
        function E(e) {
            var t = g["a"].te("route.".concat(e));
            if (t) {
                var a = g["a"].t("route.".concat(e));
                return "".concat(a, " - ").concat(R)
            }
            return "".concat(R)
        }
        k.a.configure({
            showSpinner: !1
        });
        var O = ["/login"];
        p["c"].beforeEach(function() {
            var e = Object(z["a"])(Object(I["a"])().mark((function e(t, a, i) {
                var n, r, s, d, c;
                return Object(I["a"])().wrap((function(e) {
                    while (1)
                        switch (e.prev = e.next) {
                        case 0:
                            if (k.a.start(),
                            document.title = E(t.meta.title),
                            n = Object(A["a"])(),
                            !n) {
                                e.next = 35;
                                break
                            }
                            if ("/login" !== t.path) {
                                e.next = 9;
                                break
                            }
                            i({
                                path: "/"
                            }),
                            k.a.done(),
                            e.next = 33;
                            break;
                        case 9:
                            if (r = _["a"].getters.roles && _["a"].getters.roles.length > 0,
                            !r) {
                                e.next = 14;
                                break
                            }
                            i(),
                            e.next = 33;
                            break;
                        case 14:
                            return e.prev = 14,
                            e.next = 17,
                            _["a"].dispatch("user/getInfo");
                        case 17:
                            return s = e.sent,
                            d = s.roles,
                            e.next = 21,
                            _["a"].dispatch("permission/generateRoutes", d);
                        case 21:
                            c = e.sent,
                            p["c"].addRoutes(c),
                            i(Object(D["a"])(Object(D["a"])({}, t), {}, {
                                replace: !0
                            })),
                            e.next = 33;
                            break;
                        case 26:
                            return e.prev = 26,
                            e.t0 = e["catch"](14),
                            e.next = 30,
                            _["a"].dispatch("user/resetToken");
                        case 30:
                            o["Message"].error(e.t0 || "Has Error"),
                            i("/login?redirect=".concat(t.path)),
                            k.a.done();
                        case 33:
                            e.next = 36;
                            break;
                        case 35:
                            -1 !== O.indexOf(t.path) ? i() : (i("/login?redirect=".concat(t.path)),
                            k.a.done());
                        case 36:
                        case "end":
                            return e.stop()
                        }
                }
                ), e, null, [[14, 26]])
            }
            )));
            return function(t, a, i) {
                return e.apply(this, arguments)
            }
        }()),
        p["c"].afterEach((function() {
            k.a.done()
        }
        )),
        i["default"].use(n.a, {
            i18n: function(e, t) {
                return g["a"].t(e, t)
            }
        }),
        i["default"].config.productionTip = !1,
        new i["default"]({
            el: "#app",
            router: p["c"],
            store: _["a"],
            i18n: g["a"],
            render: function(e) {
                return e(u)
            }
        })
    },
    "5f87": function(e, t, a) {
        "use strict";
        a.d(t, "a", (function() {
            return r
        }
        )),
        a.d(t, "c", (function() {
            return s
        }
        )),
        a.d(t, "b", (function() {
            return d
        }
        ));
        var i = a("a78e")
          , o = a.n(i)
          , n = "vue_admin_template_token";
        function r() {
            return o.a.get(n)
        }
        function s(e) {
            return o.a.set(n, e)
        }
        function d() {
            return o.a.remove(n)
        }
    },
    "61c4": function(e, t, a) {
        "use strict";
        a("dcea")
    },
    "61f7": function(e, t, a) {
        "use strict";
        a.d(t, "b", (function() {
            return s
        }
        )),
        a.d(t, "c", (function() {
            return d
        }
        )),
        a.d(t, "a", (function() {
            return l
        }
        ));
        a("ac1f"),
        a("00b4"),
        a("5319");
        var i = a("5c96")
          , o = a("4360")
          , n = a("9923");
        a("2b44");
        function r(e) {
            var t = n["a"].te("".concat(e));
            if (t) {
                var a = n["a"].t("".concat(e));
                return "".concat(a)
            }
            return "".concat(e)
        }
        function s(e) {
            return /^(https?:|mailto:|tel:)/.test(e)
        }
        function d(e) {
            return -1 === e.indexOf(" ") && e.length >= 3
        }
        function c(e) {
            o["a"].dispatch("user/resetToken").then((function() {
                void 0 !== e ? location.replace("http://".concat(e)) : location.reload()
            }
            ))
        }
        function l(e, t) {
            var a = e
              , o = setInterval((function(e) {
                a--,
                document.getElementById("timed").innerHTML = a,
                a < 1 && (clearInterval(o),
                i["MessageBox"].close(),
                c(t))
            }
            ), 1e3);
            i["MessageBox"].alert(r("login.restart_msg"), r("login.confirm_logout"), {
                confirmButtonText: r("button.re_login"),
                dangerouslyUseHTMLString: !0,
                closeOnClickModal: !1,
                callback: function(a) {
                    clearInterval(o),
                    c(t),
                    document.getElementById("timed").innerHTML = e
                }
            })
        }
    },
    "83d6": function(e, t) {
        e.exports = {
            title: "IP Camera Web Service",
            fixedHeader: !1,
            showSettings: !0,
            sidebarLogo: !0
        }
    },
    8969: function(e, t, a) {
        "use strict";
        a("1981")
    },
    "8dd0": function(e, t, a) {
        "use strict";
        a("c459")
    },
    "93cd": function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("e017")
          , o = a.n(i)
          , n = a("21a1")
          , r = a.n(n)
          , s = new o.a({
            id: "icon-tree",
            use: "icon-tree-usage",
            viewBox: "0 0 128 128",
            content: '<symbol xmlns="http://www.w3.org/2000/svg" viewBox="0 0 128 128" id="icon-tree"><path d="M126.713 90.023c.858.985 1.287 2.134 1.287 3.447v29.553c0 1.423-.429 2.6-1.287 3.53-.858.93-1.907 1.395-3.146 1.395H97.824c-1.145 0-2.146-.465-3.004-1.395-.858-.93-1.287-2.107-1.287-3.53V93.47c0-.875.19-1.696.572-2.462.382-.766.906-1.368 1.573-1.806a3.84 3.84 0 0 1 2.146-.657h9.725V69.007a3.84 3.84 0 0 0-.43-1.806 3.569 3.569 0 0 0-1.143-1.313 2.714 2.714 0 0 0-1.573-.492h-36.47v23.149h9.725c1.144 0 2.145.492 3.004 1.478.858.985 1.287 2.134 1.287 3.447v29.553c0 .876-.191 1.696-.573 2.463-.38.766-.905 1.368-1.573 1.806a3.84 3.84 0 0 1-2.145.656H51.915a3.84 3.84 0 0 1-2.145-.656c-.668-.438-1.216-1.04-1.645-1.806a4.96 4.96 0 0 1-.644-2.463V93.47c0-1.313.43-2.462 1.288-3.447.858-.986 1.907-1.478 3.146-1.478h9.582v-23.15h-37.9c-.953 0-1.74.356-2.359 1.068-.62.711-.93 1.56-.93 2.544v19.538h9.726c1.239 0 2.264.492 3.074 1.478.81.985 1.216 2.134 1.216 3.447v29.553c0 1.423-.405 2.6-1.216 3.53-.81.93-1.835 1.395-3.074 1.395H4.29c-.476 0-.93-.082-1.358-.246a4.1 4.1 0 0 1-1.144-.657 4.658 4.658 0 0 1-.93-1.067 5.186 5.186 0 0 1-.643-1.395 5.566 5.566 0 0 1-.215-1.56V93.47c0-.437.048-.875.143-1.313a3.95 3.95 0 0 1 .429-1.15c.19-.328.429-.656.715-.984.286-.329.572-.602.858-.821.286-.22.62-.383 1.001-.493.382-.11.763-.164 1.144-.164h9.726V61.619c0-.985.31-1.833.93-2.544.619-.712 1.358-1.068 2.216-1.068h44.335V39.62h-9.582c-1.24 0-2.288-.492-3.146-1.477a5.09 5.09 0 0 1-1.287-3.448V5.14c0-1.423.429-2.627 1.287-3.612.858-.985 1.907-1.477 3.146-1.477h25.743c.763 0 1.478.246 2.145.739a5.17 5.17 0 0 1 1.573 1.888c.382.766.573 1.587.573 2.462v29.553c0 1.313-.43 2.463-1.287 3.448-.859.985-1.86 1.477-3.004 1.477h-9.725v18.389h42.762c.954 0 1.74.355 2.36 1.067.62.711.93 1.56.93 2.545v26.925h9.582c1.239 0 2.288.492 3.146 1.478z" /></symbol>'
        });
        r.a.add(s);
        t["default"] = s
    },
    9923: function(e, t, a) {
        "use strict";
        a.d(t, "b", (function() {
            return z
        }
        ));
        var i = a("5530")
          , o = (a("b64b"),
        a("2b0e"))
          , n = a("a925")
          , r = a("a78e")
          , s = a.n(r)
          , d = a("b2d6")
          , c = a.n(d)
          , l = a("956c")
          , m = a.n(l)
          , u = a("fcff")
          , _ = a.n(u)
          , p = a("da67")
          , g = a.n(p)
          , h = a("dccd")
          , f = a.n(h)
          , v = a("f0d9")
          , b = a.n(v)
          , y = {
            route: {
                dashboard: "Live Video",
                network_settings: "Network Settings",
                ip_settings: "IP Settings",
                gb28181_settings: "GB28181 Settings",
                rtmp_settings: "RTMP Settings",
                media_settings: "Media Settings",
                video_capture: "Video Capture",
                datetime_title: "Time & Title",
                video_codec: "Video Codec",
                audio_capture: "Audio Capture",
                audio_codec: "Audio Codec",
                fill_light: "Fill Light",
                privacy_mask: "Privacy Mask",
                warning_settings: "Alarm Settings",
                human_recognition: "Human Recognition",
                electric_vehicle_recognition: "Electric Vehicle Recognition",
                fall_detection: "Fall Detection",
                flame_recognition: "Flame Recognition",
                smoke_detection: "Smoke Detection",
                motion_detection: "Motion Detection",
                occlusion_detection: "Mask Detection",
                notifies: "Alarm Notify",
                system_settings: "System Setting",
                user_management: "User Management",
                system_time: "System Time",
                maintenance: "System Maintenance",
                documentation: "Documentation",
                guide: "Guide",
                permission: "Authentication",
                pagePermission: "Page Authentication",
                rolePermission: "Role Authentication",
                directivePermission: "Directive Authentication",
                page401: "401",
                page404: "404",
                errorLog: "Error Log",
                theme: "Theme",
                i18n: "I18n",
                externalLink: "Profile",
                profile: "Profile",
                language: "Language",
                storage: "Storage Settings",
                ptzcontrol: "PTZ Control",
                audio_settings: "Audio Settings",
                network_protocol: "Network Protocol",
                platform_settings: "Platform Settings",
                intelligence_algorithms: "Intelligence Algorithms",
                ai_settings: "AI Settings",
                video_coding: "Video Coding",
                image_parameters: "Image Parameters",
                capture_settings: "Capture Settings",
                osd_settings: "OSD Settings",
                devices_maintenance: "Devices Maintenance"
            },
            dashboard: {
                name: "Name",
                id: "ID",
                version: "Version",
                monitor: "Monitor",
                intercom: "Intercom",
                snapshot: "Snapshot",
                videotape: "Video"
            },
            navbar: {
                dashboard: "Live Video",
                github: "Github",
                logOut: "Log Out",
                profile: "Profile",
                theme: "Theme",
                size: "Size"
            },
            login: {
                title: "Login Form",
                logIn: "Login",
                username: "Username",
                password: "Password",
                language: "Language",
                remeberPwd: "Remember Password",
                any: "any",
                thirdparty: "Third Party Login",
                thirdpartyTips: "Can not be simulated on local, please combine with your own business for simulation! ! !",
                confirm_logout: "Confirm logout",
                re_login_msg: "You have been logged out, you can cancel to stay on this page, or log in again",
                restart_msg: "<div>Your modification requires an IPC restart to take effect. The system will exit in <span id='timed' style='color: #06B7AE'></span> seconds and log in again to function properly.</div>"
            },
            permission: {
                addRole: "New Role",
                editPermission: "Edit",
                roles: "Your Roles",
                switchRoles: "Switch Roles",
                tips: "",
                delete: "Delete",
                confirm: "Confirm",
                cancel: "Cancel"
            },
            errorLog: {
                tips: "",
                description: "",
                documentation: "Document Introduction"
            },
            theme: {
                change: "Change Theme",
                documentation: "Theme Documentation",
                tips: ""
            },
            tagsView: {
                refresh: "Refresh",
                close: "Close",
                closeOthers: "Close Others",
                closeAll: "Close All"
            },
            settings: {
                title: "Page Style Setting",
                theme: "Theme Color",
                tagsView: "Open Tags-View",
                fixedHeader: "Fixed Header",
                sidebarLogo: "Sidebar Logo"
            },
            button: {
                save: "Save",
                view: "View",
                edit: "Edit",
                all: "All",
                all_list: "All List",
                empty: "Empty",
                delete: "Delete",
                refresh: "Refresh",
                search: "Search",
                restart: "Restart",
                setting: "Setting",
                updatesoft: "Updatesoft",
                default: "Default",
                restore_factory: "Restore Factory",
                reset: "Reset",
                cancel: "Cancel",
                re_login: "Re-Login",
                yes: "Yes",
                qr_code: "Qr code",
                no: "No"
            },
            ip_settings: {
                mac_address: "MAC Address",
                dhcp: "DHCP",
                self_adaption: "IP Self-Adaption",
                ipv4_addr: "IPv4 Address",
                ipv4_mask: "IPv4 Subnet Mask",
                ipv4_gateway: "IPv4 Gateway",
                ipv6_addr: "IPv6 Address",
                ipv6_gateway: "IPv6 Gateway",
                dns1: "DNS1",
                dns2: "DNS2",
                ip_settings: "IP Settings",
                auto_ip: "Auto IP",
                static_ip: "Static IP",
                static_ddns: "Static DDNS",
                auto_ddns: "Auto DDNS"
            },
            wifi: {
                name: "name",
                work_mode: "work mode",
                wlan: "WLAN",
                ap: "AP hotspot",
                status: "connection status",
                ssid: "SSID",
                password: "password",
                connected: "connected",
                not_connected: "ununited"
            },
            net_4g: {
                status: "connection status",
                enabled: "open"
            },
            gb28181_settings: {
                enabled: "Enable 28181",
                local_sip_port: "Local SIP Port(1025-65525",
                sip_server_id: "SIP Server ID",
                sip_server_domain: "SIP Server Domain",
                sip_server_ip: "SIP Server IP",
                sip_server_port: "SIP Server Port(1-65535)",
                sip_username: "SIP User Name",
                sip_user_auth_id: "SIP User Auth ID",
                password: "Password",
                password_confirm: "Password Confirm",
                term_of_validity: "Term of Validity(second)",
                heartbeat_cycle: "Heartbeat Cycle(5-3600)",
                max_heartbeat_timeout: "Max Heartbeat Timeout(3-255)",
                stream_index: "28181 Stream Index",
                video_channel_code_id: "Video Channel Code ID",
                audio_channel_code_id: "Audio Channel Code ID",
                alarm_id: "Alarm ID"
            },
            rtmp_settings: {
                enabled: "Enable RTMP",
                stream_type: "Stream Type",
                remote_host: "Remote Host",
                remote_port: "Remote Port(1-65535)",
                app_name: "App Name",
                stream_id: "Stream ID",
                illustrate: "Illustrate",
                illustrate_context_1: "What do the above parameters mean? For example, the RTMP push URL is as follows, and the corresponding parameter can be obtained by splitting characters /.",
                illustrate_context_2: " rtmp://abc.defgh.com/live/4287d428c?wsSecret=5ba27f7727a398a8",
                illustrate_context_3: "1) Server address:   abc.defgh.com",
                illustrate_context_4: '2) Port number:   \t By default, the value is 1935. If abc.defgh.com is followed by":number", the number indicates the port number',
                illustrate_context_5: "3) Application name:  \t live",
                illustrate_context_6: "4) Stream ID:       4287d428c?wsSecret=5ba27f7727a398a"
            },
            video_capture: {
                brightness: "Brightness",
                contrast: "Contrast",
                saturation: "Saturation",
                backlight: "Backlight",
                sharpness: "Sharpness",
                video_standard: "Video Standard",
                horizontal_flip: "Horizontal Flip",
                vertical_flip: "Vertical Flip",
                prevent_overexposure: "Prevent Overexposure",
                scene_mode: "Scene Mode",
                AE_sensitivity: "AE Sensitivity",
                AE_tolerance: "AE Tolerance",
                exposure_mode: "Exposure Mode",
                white_balance: "White Balance",
                wide_dynamic: "Wide Dynamic",
                wide_dynamic_enhancement: "Wide Dynamic Enhancement",
                noise_reduction_3d: "3D Noise Reduction",
                noise_reduction_3d_enhancement: "3D Noise Reduction Enhancement",
                capture_setting: "Capture Setting",
                advance_setting: "Advance Setting",
                auto: "Auto",
                indoor: "Indoor",
                outdoor: "Outdoor",
                disable: "Disable",
                manual: "Manual"
            },
            datetime_title: {
                datetime: "Date & Time",
                x: "Area Coordinate Percentage(%)",
                y: "Area Coordinate Percentage(%)",
                time_format: "Time Format",
                week: "Show Week",
                date_format: "Date Format",
                style: "Week Style",
                title: "Title",
                channel: "Channel",
                enabled: "Enabled",
                name: "Channel Name",
                hour24: "24 Hours",
                hour12: "12 Hours",
                english: "English",
                chinese: "Chinese"
            },
            video_codec: {
                main_stream: "Main Stream",
                encode_format: "Encode Format",
                resolve: "Resolution",
                bitrate: "Bitrate",
                framerate: "Frame Rate",
                bps: "Bitrate",
                keyframe_interval: "Keyframe Interval",
                sub_stream: "Sub Stream",
                h264: "H.264",
                h265: "H.265",
                quality: "Quality",
                quality_tip: "（1-9 The higher the number, the better the quality）",
                first_main_stream: "First Main Stream",
                first_sub_stream: "First Sub Stream",
                second_main_stream: "Second Main Stream",
                second_sub_stream: "Second Sub Stream",
                stream_id: "Stream ID",
                profile: "Profile "
            },
            audio_capture: {
                sample_rate: "Sample Rate",
                sample_bit: "Sample Bit",
                collect_volume: "Collect Volume",
                play_volume: "Play Volume",
                input_method: "Input Method"
            },
            audio_codec: {
                encode_enabled: "Enabled",
                encode_format: "Format",
                decode_enabled: "Decode"
            },
            fill_light: {
                ir_cut: "IR Cut Trigger",
                light_mode: "Light Mode",
                image_mode: "Image Mode",
                photosensitive_type: "Photosensitive Type",
                start_sensitivity: "Lamp Source Starting Sensitivity",
                automatic_sensitivity: "Automatic Adjustment Sensitivity of Light Source",
                light_type: "Light Type",
                dimming_mode: "Dimming Mode",
                luminance: "Luminance(100%)",
                forward: "Forward",
                reverse: "Reverse",
                lampred: "Infrared Normal Mode",
                lampwhite: "White Light/Warm Light Normal Dimming Mode",
                lampdouble: "Dual Light Source (Infrared, White/Warm) Normal Dimming Mode",
                smart_lampred: "Infrared Intelligent Dimming Mode",
                smart_lampwhite: "White Light/Warm Light Intelligent Dimming Mode",
                smart_lampdouble: "Dual Light Source (Infrared, White/Warm) Intelligent Dimming Mode",
                auto: "Auto",
                day: "Day",
                night: "Night",
                timing: "Timing",
                hard: "Hard",
                soft: "Soft",
                morning: "Morning",
                middle: "Middle",
                evening: "Evening",
                fast: "Fast",
                slow: "Slow",
                red_light: "Red Light",
                warm_light: "Warm Light",
                manual: "Manual",
                night_start_time: "Night Start Time",
                night_end_time: "Night End Time"
            },
            privacy_mask: {
                privacy_zone: "Privacy Zone",
                enabled: "Enabled",
                x: "X Coordinate",
                y: "Y Coordinate",
                width: "Width",
                height: "Height",
                color: "Color"
            },
            user_management: {
                name: "Name",
                password: "Password",
                group: "Group",
                enabled: "Enabled",
                operations: "Operations",
                edit: "Edit",
                remove: "Remove",
                add: "Add",
                admin: "Administrator",
                operator: "Operator",
                viewer: "Viewer",
                cancel: "Cancel",
                confirm: "Confirm",
                input_user: "Input User Information",
                confirm_password: "Enter the password again",
                built_in_user: "Built-in user cannot be deleted",
                invalid_user: "User name cannot be less than three characters",
                invalid_password: "The password can be less than 6 digits or confirm password are different.",
                user: "User"
            },
            system_time: {
                mode: "Operation Mode",
                ntp_server: "NTP Server",
                port: "NTP Port",
                sync_time: "NTP Synctime (minutes)",
                timezone: "Time Zone",
                time: "Time",
                same_host: "Consistent with the device",
                ntp: "NTP",
                manual: "Manual"
            },
            maintenance: {
                enabled: "Enabled",
                day: "Maintenance Day",
                restart_time: "Restart Time",
                sunday: "Sunday",
                monday: "Monday",
                tuesday: "Tuesday",
                wednesday: "Wednesday",
                thursday: "Thursday",
                friday: "Friday",
                saturday: "Saturday",
                everyday: "Everyday",
                am: "a.m.",
                pm: "p.m.",
                y: "Year",
                m: "Month",
                d: "Date",
                restarting: "Restarting",
                restore: "Restoring factory settings will lose all modified information and reset the IP address."
            },
            human_recognition: {
                enabled: "Enabled",
                sensitivity: "Sensitivity",
                alarm_mode: "Alarm Mode",
                flash_light: "Flash Light",
                play_tone: "Play Tone",
                area: "Area",
                defence: "Defence Time",
                withdrawal: "Withdrawal Time",
                days: "Days",
                repeat: "Repeat",
                voice: "Voice",
                m_f: "M-F",
                m_s: "M-S",
                sat_sun: "Saturday and Sunday",
                sun: "Sunday",
                everyday: "Everyday",
                default: "Default",
                max_deployment_area: "The system only supports up to 4 deployment areas",
                tips: "Press the left button and drag to draw the area to be monitored, up to 4 areas"
            },
            occlusion_detection: {
                enabled: "Enabled",
                area: "Area",
                sensitivity: "Sensitivity",
                alarm_mode: "Alarm Mode",
                flash_light: "Flash Light",
                play_tone: "Play Tone",
                tips: "Press the left button and drag to draw the area to be monitored"
            },
            motion_detection: {
                enabled: "Enabled",
                sensitivity: "Sensitivity",
                alarm_mode: "Alarm Mode",
                flash_light: "Flash Light",
                play_tone: "Play Tone",
                Video_stream: "Video stream",
                recording_recording: "Reserved recording duration",
                Recording_duration: "Recording duration",
                signal_transfer: "IO alarm output",
                Number_snaps: "Number of snaps"
            },
            notify: {
                type: "Type",
                datetime: "Time",
                anthropomorphic: "Anthropomorphic detection",
                motion: "Motion detection",
                occlusion: "Video occlusion",
                none: "None"
            },
            ptzcontrol: {
                name: "PTZ",
                amplify: "Amplify",
                focus: "Focus",
                aperture: "Aperture",
                ptz_speed: "PTZ Speed",
                doubling_speed: "Zoom Speed",
                focus_mode: "Focus Mode",
                focus_sensitivity: "Focus Sensitivity",
                focus_area: "Focus Area",
                preset_position: "Preset Position",
                code_stream: "Code Stream",
                base_set: "Base Setting",
                more_set: "More Setting",
                invoke_preset: "Invoke Preset",
                add_preset: "Add Preset",
                remove_preset: "Remove Preset"
            },
            storage: {
                storage: "Storage",
                media_format: "Media Format",
                image_save_path: "Image Save Path",
                video_save_path: "Video Save Path",
                storage_device: "TF Card Storage Device",
                save_setting: "Save Setting",
                storage_Plan: "Storage Plan",
                storage_management: "Storage Management",
                video_files: "Video Files",
                record_audio: "Record Audio",
                tf_card: "TF Card Storage",
                volume: "Volume",
                status: "Status",
                format: "Format",
                unformat: "Unformat",
                usb_disk: "USB Disk",
                total: "Total",
                used: "Used",
                recording_status: "Recording Status",
                working_mode: "Working Mode",
                video_stream: "Video Stream",
                video_file_size: "Video File Size",
                video_strategy: "Video Strategy",
                auto_override: "Auto Override",
                full_stop: "Stop after full",
                choose_time: "Choose Time",
                manual_recording: "Manual Recording",
                timer_recording: "Timer Recording",
                recording_type: "Recording Type",
                media_forma: "Media Format",
                file_type: "File Type",
                video_audio: "Video & Audio",
                onliy_video: "Only Video",
                ftp: "Upload FTP Servers",
                email: "Send Email",
                file_name: "File Name",
                action: "Action",
                max_record_time: "Single file length (minutes)"
            },
            lg: {
                msg: "Switch Language Success"
            },
            tf_card: {
                ok: "TF card Ok",
                no_card: "No TF card",
                no_format: "TF card not format",
                abnormal: "TF card abnormal",
                file_type: "Format type",
                is_delete: "Is the TF card formatted?",
                formatting: "Formatting TF Card!",
                cancel: "Cancel",
                confirm: "Confirm"
            },
            network_settings: {
                name: "Network Settings",
                wired_network: "Wired Network Settings",
                wifi_settings: "WIFI Settings",
                s4g_settings: "4G Settings",
                ip_address_filtering: "IP Address Filtering"
            },
            network_protocol: {
                enabled: "Enabled",
                name: "Network Protocol",
                http: "HTTP",
                rtsp: "RTSP",
                rtp: "RTP",
                ftp: "FTP",
                smtp: "SMTP",
                qos: "Qos",
                x8021: "802.1x",
                upnp: "uPnP",
                pppoe: "PPPoE",
                ntf: "NTP",
                ddns: "DDNS",
                http_port: "Http Port",
                listening_port: "Listening Port",
                upgrade_port: "Upgrade Port",
                multicast_ttl: "Multicast TTL",
                identity_authentication: "Identity Authentication",
                udp: "UDP",
                rtmp: "RTMP",
                user: "User Name",
                password: "Password",
                server_id: "服务器编号",
                server_url: "Server address",
                server_path: "Server storage directory",
                path: "Path",
                rtmp_enabled: "开启RTMP功能",
                rstp_enabled: "Identity Authentication",
                rtp_enabled: "Enable RTP",
                stream: "Video Stream",
                port: "Port Number",
                video_id: "Video ID",
                audio_id: "Audio ID",
                talk_id: "Intercom ID",
                mtu: "Mtu",
                udp_enabled: "Enable UDP Multicast",
                udp_ip: "Multicast IP",
                udp_port: "Port Number",
                udp_url: "UDP Multicast Play Address",
                ftp_normal: "Default Parameter"
            },
            time: {
                name: "Time",
                day_time: "Day/Time",
                start_time: "Start Time",
                end_time: "End Time",
                to: "To",
                monday: "Monday",
                tuesday: "Tuesday",
                wednesday: "Wednesday",
                thursday: "Thursday",
                friday: "Friday",
                saturday: "Saturday",
                weekday: "Weekday",
                mouse_click: "Click the time quantum via mouse",
                times_output: "Time quantum can't pass five"
            },
            platform_settings: {
                gb28181: "GB28181",
                onvif: "ONVIF"
            },
            devices_maintenance: {
                about_devices: "About Devices",
                devices_name: "Devices Name",
                devices_time: "Device Time",
                software_version: "Device Version",
                firmware_version: "Firmware Version",
                system_maintenance: "System Maintenance",
                use_ntp: "Enabled NTP",
                use_computer: "Manual Settings",
                use_multicast: "open multicast",
                video_streaming: "video streaming",
                IP_multicast: "multicast IP",
                multicast_port: "multicast port",
                Play_address: "UDP Multicast Play Address",
                equipment: "ID equipment",
                server: "server URL"
            },
            osd: {
                basic_settings: "Basic Settings",
                system_settings: "System Settings",
                custom_settings: "Custom Settings",
                font_size: "Front Size",
                pellucidity: "Pellucidity",
                use_title: "Enabled Title",
                color: "Color",
                use: "Enabled ",
                add_info: "Overlay Information",
                custom_centent: "Custom Content",
                add_infos: {
                    rr: "Resolution",
                    rpfr: "Resolution & Frame Rate",
                    rpfrcr: "Resolution & Frame Rate & Code Rate"
                }
            },
            area: {
                red: "Red",
                green: "Green",
                yellow: "Yellow",
                blue: "Blue"
            }
            }
          , w = {
            route: {
                dashboard: "Live ",
                network_settings: "Impostazioni di Rete",
                ip_settings: "Rete",
                gb28181_settings: "Parametri GB28181",
                media_settings: "Parametri Media",
                video_capture: "Cattura Video",
                datetime_title: "Orario & Titolo",
                video_codec: "Codifica Video",
                audio_capture: "Cattura Video",
                audio_codec: "Codifica Audio",
                fill_light: "Riempi luce",
                privacy_mask: "Maschera Privacy",
                warning_settings: "Impostazioni Allarmi",
                human_recognition: "Riconoscimento umano",
                motion_detection: "Rilevamento movimento",
                occlusion_detection: "Mask Detection",
                system_settings: "Impostazioni di sistema",
                user_management: "Gestione Utenti",
                system_time: "Data e Ora",
                maintenance: "Manutenzione",
                documentation: "Documentazione",
                guide: "Aiuto",
                permission: "Autenticazione",
                pagePermission: "Page Autenticazione",
                rolePermission: "Role Autenticazione",
                directivePermission: "Directive Autenticazione",
                page401: "401",
                page404: "404",
                errorLog: "Registro Errori",
                theme: "Tema",
                clipboardDemo: "Globalizzazione",
                i18n: "I18n",
                externalLink: "Profilo",
                profile: "Profilo",
                language: "Lingua",
                storage: "Impostazioni Archiviazione",
                ptzcontrol: "Controllo PTZ",
                audio_settings: "Impostazioni Audio",
                network_protocol: "Protocollo di Rete",
                platform_settings: "Impostazioni Piattaforma",
                intelligence_algorithms: "Intelligence Algorithms",
                ai_settings: "Impostazioni AI",
                video_coding: "Codifica Video",
                image_parameters: "Parametri Immagine",
                capture_settings: "Parametri di Cattura",
                osd_settings: "Impostazioni OSD",
                devices_maintenance: "Dispositivo in Manutenzione"
            },
            dashboard: {
                name: "Nome",
                id: "ID",
                version: "Versione",
                monitor: "Monitor",
                intercom: "Intercom",
                snapshot: "Istantanea",
                videotape: "Video"
            },
            navbar: {
                dashboard: "Video dal Vivo",
                github: "Github",
                logOut: "Log Out",
                profile: "Profilo",
                theme: "Tema",
                size: "Dimensione"
            },
            login: {
                title: "Modulo di accesso",
                logIn: "accedi",
                username: "nome",
                password: "Password",
                any: "any",
                thirdparty: "Accesso di terzi",
                thirdpartyTips: "La simulazione non può essere eseguita in locale! ! !",
                confirm_logout: "Confirm logout",
                re_login_msg: "You have been logged out, you can cancel to stay on this page, or log in again",
                restart_msg: "<div>Your modification requires an IPC restart to take effect. The system will exit in <span id='timed' style='color: #06B7AE'></span> seconds and log in again to function properly.</div>"
            },
            permission: {
                addRole: "Nuovo Ruolo",
                editPermission: "Modifica",
                roles: "I tuoi ruoli",
                switchRoles: "Cambia Ruoli",
                tips: "",
                delete: "Delete",
                confirm: "Confirm",
                cancel: "Cancel"
            },
            errorLog: {
                tips: "",
                description: "",
                documentation: "Document Introduction"
            },
            theme: {
                change: "Cambia Tema",
                documentation: "Informazioni sul Tema",
                tips: ""
            },
            tagsView: {
                refresh: "Aggiorna",
                close: "Chiudi",
                closeOthers: "Chiudi Rimanenti",
                closeAll: "Chiudi Tutto"
            },
            settings: {
                title: "Impostazioni stile pagina",
                theme: "Colore del Tema",
                tagsView: "Open Tags-View",
                fixedHeader: "Fixed Header",
                sidebarLogo: "Sidebar Logo"
            },
            button: {
                save: "Salva",
                view: "Mostra",
                edit: "Modifica",
                all: "All",
                all_list: "All List",
                empty: "Svuota",
                delete: "Cancella",
                refresh: "Aggiorna",
                search: "Cerca",
                restart: "Riavvia",
                setting: "Impostazioni",
                updatesoft: "Aggiornamento Software",
                default: "Default",
                restore_factory: "Ripristina Dati di Fabbrica",
                reset: "Reset",
                cancel: "Cancel",
                re_login: "Re-Login",
                yes: "Yes",
                no: "No"
            },
            ip_settings: {
                mac_address: "Indirizzo MAC",
                dhcp: "DHCP",
                self_adaption: "Adattamento IP",
                ipv4_addr: "Indirizzo IPv4",
                ipv4_mask: "Maschera di sottorete IPv4",
                ipv4_gateway: "Gateway IPv4",
                ipv6_addr: "Indirizzo IPv6",
                ipv6_gateway: "Gateway IPv6",
                dns1: "DNS1",
                dns2: "DNS2",
                ip_settings: "Impostazioni IP",
                auto_ip: "IP Automatico",
                static_ip: "IP Statico",
                static_ddns: "DDNS Statico",
                auto_ddns: "DDNS Automatico"
            },
            wifi: {
                name: "name",
                work_mode: "work mode",
                wlan: "WLAN",
                ap: "AP hotspot",
                status: "connection status",
                ssid: "SSID",
                password: "password",
                connected: "connected",
                not_connected: "ununited"
            },
            net_4g: {
                status: "connection status",
                enabled: "open"
            },
            gb28181_settings: {
                enabled: "Abilita 28181",
                local_sip_port: "Porta locale SIP(1025-65525",
                sip_server_id: "ID Server SIP",
                sip_server_domain: "Dominio Server SIP",
                sip_server_ip: "IP Server SIP",
                sip_server_port: "Porta Server SIP(1-65535)",
                sip_username: "Nome utente SIP",
                sip_user_auth_id: "ID Auth utente SIP",
                password: "Password",
                password_confirm: "Conferma Password",
                term_of_validity: "Termine di Valitdità(second)",
                heartbeat_cycle: "Ciclo del battito cardiaco(5-3600)",
                max_heartbeat_timeout: "Tempo massimo di battito cardiaco(3-255)",
                stream_index: "28181 indice della corrente",
                video_channel_code_id: "ID codice canale Video",
                audio_channel_code_id: "ID codice canale Audio",
                alarm_id: "ID allarme"
            },
            video_capture: {
                brightness: "Luminosità",
                contrast: "Contrasto",
                saturation: "Saturazione",
                backlight: "Controluce",
                sharpness: "Sharpness",
                video_standard: "Standard Video",
                horizontal_flip: "Specchia Immagine Orizzontale",
                vertical_flip: "Specchia Immagine Verticale",
                prevent_overexposure: "Previeni Sovraesposizione",
                scene_mode: "Modalità Scena",
                AE_sensitivity: "Sensibilità AE",
                AE_tolerance: "Tolleranza AE",
                exposure_mode: "Mode Esposizione",
                white_balance: "White Balance",
                wide_dynamic: "Wide Dynamic",
                wide_dynamic_enhancement: "Miglioramento Wide Dynamic",
                noise_reduction_3d: "Riduzione Rumore 3D",
                noise_reduction_3d_enhancement: "Miglioramento Riduzione Rumore 3D",
                capture_setting: "Impostazioni di Cattura",
                advance_setting: "Impostazioni Avanzate",
                auto: "Automatico",
                indoor: "Interno",
                outdoor: "Esterni",
                disable: "Disabilita",
                manual: "Manuale"
            },
            datetime_title: {
                datetime: "Date & Time",
                x: "Percentuale Coordinate d'Area (%)",
                y: "Percentuale Coordinate d'Area(%)",
                time_format: "Formato Ora",
                week: "Stile Settimana",
                date_format: "Stile Settimana",
                style: "Stile Settimana",
                title: "Titolo",
                channel: "Abilitato",
                enabled: "Nome Canale",
                name: "Nome Canale",
                hour24: "24 Ore",
                hour12: "24 Ore",
                english: "Inglese",
                chinese: "Risoluzione"
            },
            video_codec: {
                main_stream: "Stream Principale",
                encode_format: "Formato Codifica Video",
                resolve: "Risoluzione",
                bitrate: "Bitrate",
                framerate: "Frame Rate",
                bps: "Bitrate",
                keyframe_interval: "Risoluzione",
                sub_stream: "Sub Stream",
                h264: "H.264",
                h265: "H.265",
                quality: "Qualità",
                quality_tip: "（1-9, Maggiore corrisponde ad una qualità migliore）",
                first_main_stream: "Primo Main Stream",
                first_sub_stream: "Primo Sub Stream",
                second_main_stream: "Secondo Main Stream",
                second_sub_stream: "Secondo Sub Stream",
                stream_id: "Stream ID",
                profile: "Sample Rate "
            },
            audio_capture: {
                sample_rate: "Sample Rate",
                sample_bit: "Risoluzione Bit",
                collect_volume: "Volume Registrazione",
                play_volume: "Volume Riproduzione",
                input_method: "Tipo di Input"
            },
            audio_codec: {
                encode_enabled: "Abilitato",
                encode_format: "Formato",
                decode_enabled: "Decodifica"
            },
            fill_light: {
                ir_cut: "Attivazione taglio IR",
                light_mode: "Modalità luce",
                image_mode: "Modalità immagine",
                photosensitive_type: "Tipo fotosensibile",
                start_sensitivity: "Sensibilità iniziale della sorgente luminosa",
                automatic_sensitivity: "Sensibilità di regolazione automatica della sorgente luminosa",
                light_type: "Tipo luce",
                dimming_mode: "Regolazione modalità",
                luminance: "Luminanza(100%)",
                forward: "Inoltra",
                reverse: "Inverso",
                lampred: "Infrared Normal Mode",
                lampwhite: "White Light/Warm Light Normal Dimming Mode",
                lampdouble: "Dual Light Source (Infrared, White/Warm) Normal Dimming Mode",
                smart_lampred: "Modalità di regolazione intelligente all’infrarosso",
                smart_lampwhite: "White Light/Warm Light Intelligent Dimming Mode",
                smart_lampdouble: "Modalità di regolazione intelligente luce bianca/luce calda",
                auto: "Auto",
                day: "Giorno",
                night: "Notte",
                timing: "Timing",
                hard: "Hard",
                soft: "Soft",
                morning: "Mezzogiorno",
                middle: "Mezzogiorno",
                evening: "Sera",
                fast: "Veloce",
                slow: "Luce Rossa",
                red_light: "Luce Rossa",
                warm_light: "Manuale",
                manual: "Manuale",
                night_start_time: "Night Start Time",
                night_end_time: "Night End Time"
            },
            privacy_mask: {
                privacy_zone: "Privacy Zone",
                enabled: "Abilitato",
                x: "X Coordinata",
                y: "Y Coordinata",
                width: "Larghezza",
                height: "Altezza",
                color: "Colore"
            },
            user_management: {
                name: "Nome",
                password: "Password",
                group: "Gruppo",
                enabled: "Abilitato",
                operations: "Operazione",
                edit: "Modifica",
                remove: "Cancella",
                add: "Aggiungi",
                admin: "Administrator",
                operator: "Operator",
                viewer: "Viewer",
                cancel: "Annulla",
                confirm: "Conferma",
                input_user: "Aggiungi informazioni Utente",
                confirm_password: "Reinserire la password",
                built_in_user: "Built-in user cannot be deleted",
                invalid_user: "User name cannot be less than three characters",
                invalid_password: "The password can be less than 6 digits or confirm password are different.",
                user: "Utente"
            },
            system_time: {
                mode: "Modalità operativa",
                ntp_server: "Server NTP",
                port: "NTP porto",
                sync_time: "Sincronizzazione NTP",
                timezone: "Fuso orario",
                time: "ora",
                same_host: "Conforme al dispositivo",
                ntp: "NTP",
                manual: "Manuale"
            },
            maintenance: {
                enabled: "Abilitato",
                day: "Maintenance Day",
                restart_time: "Orario di Riavvio",
                sunday: "Venerdi",
                monday: "Venerdi",
                tuesday: "Venerdi",
                wednesday: "Venerdi",
                thursday: "Venerdi",
                friday: "Venerdi",
                saturday: "Sabato",
                everyday: "Tutti i Giorni",
                am: "a.m.",
                pm: "p.m.",
                y: "Anno",
                m: "Anno",
                d: "Giorno",
                restarting: "Restarting",
                restore: "Restoring factory settings will lose all modified information and reset the IP address."
            },
            human_recognition: {
                enabled: "Abilitato",
                sensitivity: "Sensibilità",
                alarm_mode: "Modalità di Allarme",
                flash_light: "Flash Light",
                play_tone: "Avviso Sonoro",
                area: "Area",
                defence: "Defence Time",
                withdrawal: "Withdrawal Time",
                days: "Giorni",
                repeat: "Ripetizione",
                voice: "Voice",
                m_f: "M-F",
                m_s: "M-S",
                sat_sun: "Sabato e Domenica",
                sun: "Domenica",
                everyday: "Tutti i Giorni",
                default: "Default",
                max_deployment_area: "The system only supports up to 4 deployment areas",
                tips: "Press the left button and drag to draw the area to be monitored, up to 4 areas"
            },
            occlusion_detection: {
                enabled: "Abilita",
                area: "Area",
                sensitivity: "Sensibilità",
                alarm_mode: "Modalità Allarme",
                flash_light: "Flash Light",
                play_tone: "Avviso Sonoro",
                tips: "Clicca e Trascina con il tasto Sinistro per disegnare l'area da osservare"
            },
            motion_detection: {
                enabled: "Abilita",
                sensitivity: "Sensibilità",
                alarm_mode: "Modalità Allarme",
                flash_light: "Flash Light",
                play_tone: "Avviso Sonoro"
            },
            ptzcontrol: {
                name: "PTZ",
                amplify: "Amplifica",
                focus: "Fuoco",
                aperture: "Apertura",
                ptz_speed: "Velocità PTZ",
                doubling_speed: "Velocità Zoom",
                focus_mode: "Modalità Fuoco",
                focus_sensitivity: "Sensibilità Fuoco",
                focus_area: "Area Fuoco",
                preset_position: "Preset Position",
                code_stream: "Code Stream",
                base_set: "Impostazioni Base",
                more_set: "Impostazioni Avanzate",
                invoke_preset: "Invoke Preset",
                add_preset: "Add Preset",
                remove_preset: "Remove Preset"
            },
            storage: {
                storage: "Archivio",
                media_format: "Formato Media",
                image_save_path: "Percorso Archiviazioni Immagini",
                video_save_path: "Percorso Archiviazioni Video",
                storage_device: "Disposiivo di Archiviazione TF Card",
                save_setting: "Salva Impostazioni",
                storage_Plan: "Piano di Archiviazioni",
                storage_management: "Gestione Archiviazione",
                video_files: "File Video",
                record_audio: "Registra Audio",
                tf_card: "Archiviazione TF Card",
                volume: "Volume",
                status: "Stato",
                format: "Formatta",
                unformat: "Elimina Formattazione",
                usb_disk: "Disco USB",
                total: "Totale",
                used: "Usato",
                recording_status: "Stato Registrazioni",
                working_mode: "Modalità Lavoro",
                video_stream: "Video Stream",
                video_file_size: "Dimensione File Video",
                video_strategy: "Strategia Archiviazione Video",
                auto_override: "Sovrascrivi il Video",
                full_stop: "Ferma la Registrazione quando l'archivio è pieno",
                choose_time: "Scelta Orario",
                manual_recording: "Registrazione Manuale",
                timer_recording: "Registrazione Temporizzata",
                recording_type: "Tipo di Registrazione",
                media_forma: "Formato di Registrazione",
                file_type: "Tipo di File",
                video_audio: "Video & Audio",
                onliy_video: "Solo Video",
                ftp: "Upload su server FTP",
                email: "Invia via Email",
                file_name: "Nome File",
                action: "Azione",
                max_record_time: "Durata Massima Registrazioni"
            },
            lg: {
                msg: "Cambio lingua effettuato correttamente"
            },
            tf_card: {
                ok: "TF card Ok",
                no_card: "No TF card",
                no_format: "TF card not format",
                abnormal: "TF card abnormal",
                file_type: "Format type",
                is_delete: "La scheda TF è formattata?",
                formatting: "Formatting TF Card!",
                cancel: "Annulla",
                confirm: "Conferma"
            },
            network_settings: {
                name: "Impostazioni di Rete",
                wired_network: "Impostazioni Rete Cablata",
                wifi_settings: "impostazioni WIFI",
                s4g_settings: "Impostazioni 4G",
                ip_address_filtering: "Impostazioni Filtro indirizzi IP"
            },
            network_protocol: {
                enabled: "Abilitato",
                name: "Protocolli di Rete",
                http: "HTTP",
                rtsp: "RTSP",
                rtp: "RTP",
                ftp: "FTP",
                smtp: "SMTP",
                qos: "Qos",
                x8021: "802.1x",
                upnp: "uPnP",
                pppoe: "PPPoE",
                ntf: "NTP",
                ddns: "DDNS",
                http_port: "Porta Http",
                listening_port: "Porta d'Ascolto",
                upgrade_port: "Porta di Aggiornamento",
                multicast_ttl: "TTL Multicast",
                identity_authentication: "Autenticazione identità",
                rtmp: "RTMP",
                user: "Nome utente",
                password: "Password",
                server_id: "服务器编号",
                server_url: "Indirizzo Server",
                server_path: "Directory memoria Server",
                path: "tracciato",
                rtmp_enabled: "Abilita RTMP",
                rstp_enabled: "Autenticazione identità",
                rtp_enabled: "Abilita RTP",
                stream: "Flusso Video",
                port: "Numero porta",
                video_id: "ID Video",
                audio_id: "ID Audio",
                talk_id: "ID Intercom",
                mtu: "Mtu",
                udp: "UDP",
                udp_enabled: "Abilita Multicast UDP",
                udp_ip: "IP Multicast",
                udp_port: "Numero porta",
                udp_url: "Indirizzo di riproduzione Multicast UDP",
                ftp_normal: "Parametro predefinito"
            },
            time: {
                name: "Orario",
                day_time: "Giorno/Orario",
                start_time: "Orario Inizio",
                end_time: "Orario Fine",
                to: "Fino a",
                monday: "Lunedi",
                tuesday: "Martedi",
                wednesday: "Mercoledi",
                thursday: "Giovedi",
                friday: "Venerdi",
                saturday: "Sabato",
                weekday: "Giorni feriali",
                mouse_click: "Usa il mouse per scegliere l'intervallo di tempo",
                times_output: "L'intervallo di tempo non supera i 5"
            },
            platform_settings: {
                gb28181: "GB28181",
                onvif: "ONVIF"
            },
            devices_maintenance: {
                about_devices: "Informazioni sul Dispositivo",
                devices_name: "Nome Dispositivo",
                devices_time: "Orario del Dispositivo",
                software_version: "Versione Software",
                firmware_version: "Versione Firmware",
                system_maintenance: "Manutenzione del Dispositivo",
                use_ntp: "Abilita NTP",
                use_computer: "Sincronizza con il Computer",
                use_multicast: "Abilita Multicast UDP",
                video_streaming: "Flusso Video",
                IP_multicast: "组播IP",
                multicast_port: "组播端口",
                Play_address: "UDP组播播放地址",
                equipment: "ID 设置",
                server: "服务器URL"
            },
            osd: {
                basic_settings: "Impostazioni Base",
                system_settings: "Impostazione Sistema",
                custom_settings: "Impostazioni Personalizzate",
                font_size: "Dimensione Carattere",
                pellucidity: "Transparenza",
                use_title: "Abilita Titolo",
                color: "Colore",
                use: "Abilita ",
                add_info: "Infromazioni Sovraimpressione",
                custom_centent: "Informazioni Personalizzate",
                add_infos: {
                    rr: "Risoluzione",
                    rpfr: "Risoluzione & Frame Rate",
                    rpfrcr: "Risoluzione & Frame Rate & Code Rate"
                }
            },
            area: {
                red: "Rosso",
                green: "Verde",
                yellow: "Giallo",
                blue: "Blu"
            }
            }
          , P = {
            route: {
                dashboard: "실시간영상",
                network_settings: "네트웍설정",
                ip_settings: "IP설정",
                gb28181_settings: "GB28181설정",
                media_settings: "영상설정",
                video_capture: "영상캡쳐설정",
                datetime_title: "시간및타이틀",
                video_codec: "코덱설정",
                audio_capture: "오디오캡쳐설정",
                audio_codec: "오디오설정",
                fill_light: "보조등설정",
                privacy_mask: "마스크설정",
                warning_settings: "알람설정",
                human_recognition: "휴먼식별",
                electric_vehicle_recognition: "전동차 식별",
                fall_detection: "넘어짐 검사",
                flame_recognition: "화염연기 식별",
                smoke_detection: "흡연 검사",
                motion_detection: "모션디텍션",
                occlusion_detection: "은폐 탐지",
                notifies: "알림장",
                system_settings: "시스템설정",
                user_management: "사용자관리",
                system_time: "시시템타임",
                maintenance: "시스템유지관리",
                documentation: "파일",
                guide: "가이드",
                permission: "권한테스트",
                pagePermission: "페이지권한",
                rolePermission: "유저권한",
                directivePermission: "Instruction권한",
                page401: "401",
                page404: "404",
                errorLog: "오류로그",
                theme: "스킨체인지",
                clipboardDemo: "세계화",
                i18n: "엔터네셔설",
                externalLink: "외부링크",
                profile: "사용자센터",
                language: "언어",
                storage: "저장설정",
                ptzcontrol: "PTZ 제어",
                audio_settings: "오디오설정",
                network_protocol: "네트웍프로토콜",
                platform_settings: "플래폼설정",
                intelligence_algorithms: "지능형 알고리즘",
                ai_settings: "AI기능",
                video_coding: "비디오레크딩",
                image_parameters: "이미지파라미터",
                capture_settings: "캡쳐설정",
                osd_settings: "OSD설정",
                devices_maintenance: "디바이스유지관리"
            },
            dashboard: {
                name: "명칭",
                id: "디바이스표기",
                version: "버전",
                monitor: "모니터링",
                intercom: "인터콤",
                snapshot: "스냅샵",
                videotape: "녹화"
            },
            navbar: {
                dashboard: "실시간영상",
                logOut: "Log Out",
                profile: "사용자중심",
                theme: "스킨체인지",
                size: "싸이즈"
            },
            login: {
                title: "시스템로그인",
                logIn: "로그인",
                username: "계정",
                password: "비밀번호",
                any: "any",
                thirdparty: "3자등록",
                thirdpartyTips: "로컬에서는 시뮬레이션할수없습니다. 자신의업무와 결합하여 시뮬레이션 하십시오! ! !",
                confirm_logout: "Confirm logout",
                re_login_msg: "You have been logged out, you can cancel to stay on this page, or log in again",
                restart_msg: "<div>Your modification requires an IPC restart to take effect. The system will exit in <span id='timed' style='color: #06B7AE'></span> seconds and log in again to function properly.</div>"
            },
            permission: {
                addRole: "사용자추가",
                editPermission: "편집권한",
                roles: "나의권한",
                switchRoles: "권한교체",
                tips: "",
                delete: "삭제",
                confirm: "확인",
                cancel: "취소"
            },
            errorLog: {
                tips: "",
                description: "",
                documentation: "파일소개"
            },
            theme: {
                change: "스킨체인지",
                documentation: "스킨파일",
                tips: ""
            },
            tagsView: {
                refresh: "취소",
                close: "닫기",
                closeOthers: "기타닫기",
                closeAll: "모두닫기"
            },
            settings: {
                title: "시템구성설정",
                theme: "테마컬러",
                tagsView: "Open Tags-View",
                fixedHeader: "Header고정",
                sidebarLogo: "사이드바logo"
            },
            button: {
                save: "저장",
                view: "보기",
                edit: "편집",
                all: "전부",
                all_list: "전부선택",
                empty: "비우기",
                delete: "삭제",
                refresh: "취소",
                search: "서치",
                restart: "리부팅",
                setting: "설정",
                updatesoft: "업그레드",
                default: "디폴트",
                restore_factory: "초기화설정",
                reset: "초기화",
                cancel: "Cancel",
                re_login: "Re-Login",
                yes: "Yes",
                qr_code: "2차원 코드를 생성하다",
                no: "No"
            },
            ip_settings: {
                mac_address: "MAC 주소",
                dhcp: "DHCP",
                self_adaption: "IP 적응",
                ipv4_addr: "IPv4 주소",
                ipv4_mask: "IPv4 서브넷 마스크",
                ipv4_gateway: "IPv4 게이트 웨이",
                ipv6_addr: "IPv6 주소",
                ipv6_gateway: "IPv6 게이트 웨이",
                dns1: "DNS1",
                dns2: "DNS2",
                ip_settings: "IP 설정",
                auto_ip: "자동 IP",
                static_ip: "정적 IP",
                static_ddns: "정적 DDNS",
                auto_ddns: "자동 DDNS"
            },
            wifi: {
                name: "명칭",
                work_mode: "작업 모드",
                wlan: "WLAN",
                ap: "AP핫스팟",
                status: "연결 상태",
                ssid: "SSID",
                password: "암호",
                connected: "연결되었음",
                not_connected: "연결되지"
            },
            net_4g: {
                status: "연결 상태",
                enabled: "작동을"
            },
            gb28181_settings: {
                enabled: "로컬SIP포트",
                local_sip_port: "로컬SIP포트(1025-65525",
                sip_server_id: "SIP서버 ID",
                sip_server_domain: "SIP서버 ADD",
                sip_server_ip: "SIP서버 ADD",
                sip_server_port: "SIP서버 포트(1-65535)",
                sip_username: "SIP사용자명",
                sip_user_auth_id: "비밀번호 확인",
                password: "비밀번호 확인",
                password_confirm: "비밀번호 확인",
                term_of_validity: "레지스트유효기간(초)",
                heartbeat_cycle: "심장박동 주기(5-3600)",
                max_heartbeat_timeout: "최대 하트비트 제한 시간입니다(3-255)",
                stream_index: "오디오채넬ID",
                video_channel_code_id: "오디오채넬ID",
                audio_channel_code_id: "오디오채넬ID",
                alarm_id: "알람ID"
            },
            rtmp_settings: {
                enabled: "rtmp 사용",
                stream_type: "코드 스트림 형식",
                remote_host: "서버 주소",
                remote_port: "포트 번호(1-65535)",
                app_name: "응용이름",
                stream_id: "흐르ID",
                illustrate: "설명",
                illustrate_context_1: "이상 파라 메 터의 함의는 무엇 인가？예를 들어 rtmp url은 다음과 같다，인자는 문자열/로 나눌 수 있다。",
                illustrate_context_2: " rtmp://abc.defgh.com/live/4287d428c?wsSecret=5ba27f7727a398a8",
                illustrate_context_3: "1) 서버 주소:   abc.defgh.com",
                illustrate_context_4: '2) 포트 번호:   \t 기본값은 1935 이며 abc.defgh.com 뒤에 포트 번호를 나타내는":숫자"가 이어지면',
                illustrate_context_5: "3) 응용이름:  \t live",
                illustrate_context_6: "4) 흐르ID:       4287d428c?wsSecret=5ba27f7727a398a"
            },
            video_capture: {
                brightness: "밝기",
                contrast: "이와는 대조적으로",
                saturation: "포화",
                backlight: "백 라이트",
                sharpness: "선명도",
                video_standard: "비디오 표준",
                horizontal_flip: "수평 뒤집",
                vertical_flip: "수직 뒤집",
                prevent_overexposure: "과다 노출을 방지",
                scene_mode: "현장 모드",
                AE_sensitivity: "AE 민감도",
                AE_tolerance: "AE 공차",
                exposure_mode: "노출 모드",
                white_balance: "화이트 밸런스",
                wide_dynamic: "넓은 동적",
                wide_dynamic_enhancement: "넓은 동적 향상",
                noise_reduction_3d: "3D 노이즈 감소",
                noise_reduction_3d_enhancement: "3D 노이즈 감소 향상",
                capture_setting: "캡쳐설정",
                advance_setting: "어드벤스드설정",
                auto: "자동",
                indoor: "실내",
                outdoor: "실외",
                disable: "잠금",
                manual: "수동"
            },
            datetime_title: {
                datetime: "날짜 & 시간",
                x: "지역 좌표 백분율(%)",
                y: "지역 좌표 백분율(%)",
                time_format: "시간 형식",
                week: "쇼 주",
                date_format: "날짜 형식",
                style: "주 스타일",
                title: "제목",
                channel: "채널",
                enabled: "활성화",
                name: "채널 이름",
                hour24: "24 시간",
                hour12: "12 시간",
                english: "영어",
                chinese: "중국"
            },
            video_codec: {
                main_stream: "메인 스 트림",
                encode_format: "인 코딩 형식",
                resolve: "해상도",
                bitrate: "비트 전송 률",
                framerate: "프레임 속도",
                bps: "비트 전송 률",
                keyframe_interval: "키 프레임 간격",
                sub_stream: "하위 스 트림",
                h264: "H.264",
                h265: "H.265",
                quality: "품질",
                quality_tip: "（1-9 숫자가 높을수록 품질이 좋아집니다）",
                first_main_stream: "첫 번 째 메인 스 트림",
                first_sub_stream: "첫 번 째 하위 스 트림",
                second_main_stream: "Second Main Stream",
                second_sub_stream: "Second Sub Stream",
                stream_id: "스 트림 ID",
                profile: "프로 파일 "
            },
            audio_capture: {
                sample_rate: "샘플 속도",
                sample_bit: "표본 좀",
                collect_volume: "수집 볼륨",
                play_volume: "연극 볼륨",
                input_method: "입력 방법"
            },
            audio_codec: {
                encode_enabled: "활성화",
                encode_format: "형식",
                decode_enabled: "해독"
            },
            fill_light: {
                ir_cut: "IR 컷 트리거",
                light_mode: "조명 모드",
                image_mode: "이미지 모드",
                photosensitive_type: "감광 성 유형",
                start_sensitivity: "램프 원본 민감도 시작",
                automatic_sensitivity: "광원의 자동 조정 감도",
                light_type: "빛 유형",
                dimming_mode: "간접조명 모드",
                luminance: "앞으로",
                forward: "역방향의",
                reverse: "역",
                lampred: "적외선 지적인 간접조명 모드",
                lampwhite: "화이트 라이트/따뜻한 라이트 지능형 디밍 모드",
                lampdouble: "듀얼 광원 (적외선, 흰색/온열) 지능형 디밍 모드",
                smart_lampred: "Infrared Intelligent Dimming Mode",
                smart_lampwhite: "White Light/Warm Light Intelligent Dimming Mode",
                smart_lampdouble: "Dual Light Source (Infrared, White/Warm) Intelligent Dimming Mode",
                auto: "자동",
                day: "하루",
                night: "밤",
                timing: "타이밍",
                hard: "열심히",
                soft: "부 드러 운",
                morning: "아침",
                middle: "중간",
                evening: "저녁",
                fast: "고급",
                slow: "천천히",
                red_light: " 적신호",
                warm_light: "따뜻 한 빛",
                manual: "수동",
                night_start_time: "밤 시작 시간",
                night_end_time: "저녁이 끝나는 시간"
            },
            privacy_mask: {
                privacy_zone: "프라이버시영역",
                enabled: "적용",
                x: "X좌표",
                y: "Y좌표",
                width: "넓이",
                height: "높이",
                color: "컬러"
            },
            user_management: {
                name: "사용자명",
                password: "비밀번호",
                group: "사용자 그룹",
                enabled: "적용",
                operations: "편집",
                edit: "수정",
                remove: "삭제",
                add: "추가",
                admin: "관리자",
                operator: "사용자",
                viewer: "뷰어",
                cancel: "취소",
                confirm: "확인",
                input_user: "뷰어",
                confirm_password: "취소",
                built_in_user: "Built-in user cannot be deleted",
                invalid_user: "User name cannot be less than three characters",
                invalid_password: "The password can be less than 6 digits or confirm password are different.",
                user: "확인"
            },
            system_time: {
                mode: "워크 모드",
                ntp_server: "NTP서버",
                port: "NTP포트",
                sync_time: "NTP동기화주기",
                timezone: "타임존",
                time: "시간",
                same_host: "PC와일치",
                ntp: "NTP",
                manual: "사용자"
            },
            maintenance: {
                enabled: "작동",
                day: "점검일자",
                restart_time: "작동시간",
                sunday: "일요일",
                monday: "월요일",
                tuesday: "화요일",
                wednesday: "수요일",
                thursday: "목요일",
                friday: "금요일",
                saturday: "토요일",
                everyday: "매일",
                am: "오전.",
                pm: "오후",
                y: "년",
                m: "월",
                d: "일",
                restarting: "Restarting",
                restore: "Restoring factory settings will lose all modified information and reset the IP address."
            },
            human_recognition: {
                enabled: "활성화",
                sensitivity: "민감도",
                alarm_mode: "알람 모드",
                flash_light: "플래쉬 빛",
                play_tone: "연극 어조",
                area: "지역",
                defence: "국방 시간",
                withdrawal: "철수 시간",
                days: "일",
                repeat: "반복",
                voice: "목소리",
                m_f: "M-F",
                m_s: "M-S",
                sat_sun: "토요일과 일요일",
                sun: "일요일",
                everyday: "매일",
                default: "기본",
                max_deployment_area: "The system only supports up to 4 deployment areas",
                tips: "Press the left button and drag to draw the area to be monitored, up to 4 areas"
            },
            occlusion_detection: {
                enabled: "활성화",
                area: "지역",
                sensitivity: "민감도",
                alarm_mode: "알람 모드",
                flash_light: "플래쉬 빛",
                play_tone: "연극 어조",
                tips: "왼쪽 버튼을 누르고 드래그하여 모니터링할 영역, 최대 4 영역까지 그립니다"
            },
            motion_detection: {
                enabled: "활성화",
                sensitivity: "민감도",
                alarm_mode: "알람 모드",
                flash_light: "플래쉬 빛",
                Video_stream: "비디오 스트림",
                recording_recording: "녹화 시간을 미리 남기다",
                Recording_duration: "녹화 시간",
                signal_transfer: "io 알람 출력",
                Number_snaps: "스냅샷 수",
                play_tone: "보이스 알람"
            },
            notify: {
                type: "타입",
                datetime: "시간",
                anthropomorphic: "인체 탐지",
                motion: "이동 탐지",
                occlusion: "은폐 탐지",
                none: "가 유효하지 않습니다"
            },
            ptzcontrol: {
                name: "PTZ",
                amplify: "확대",
                focus: "포커스",
                aperture: "조리개",
                ptz_speed: "PTZ 스피드",
                doubling_speed: "줌 스피드",
                focus_mode: "포커스 모드",
                focus_sensitivity: "프커스 미감도",
                focus_area: "포커스 구역",
                preset_position: "포지션",
                code_stream: "스트림",
                base_set: "기본설정",
                more_set: "더보기"
            },
            storage: {
                storage: "저장",
                media_format: "녹화방식",
                image_save_path: "이미지캡쳐위치",
                video_save_path: "영상파일저장위치",
                storage_device: "TF카드저장",
                save_setting: "저장설정",
                storage_Plan: "저장계획",
                storage_management: "PC저장설정",
                video_files: "TF카드저장",
                record_audio: "보이스저장",
                tf_card: "TF카드관리",
                volume: "싸이즈",
                status: "상태",
                format: "포맷",
                unformat: "미 포맷",
                usb_disk: "USB관리",
                total: "총",
                used: "사용",
                recording_status: "녹화시작",
                working_mode: "동작모드",
                video_stream: "영상스트림",
                video_file_size: "녹화파일싸이즈",
                video_strategy: "녹화방식",
                auto_override: "자동 덮어쓰기",
                full_stop: "녹음 완료 후 중지",
                choose_time: "시간 선택",
                manual_recording: "수동녹화",
                timer_recording: "고정시간녹화",
                recording_type: "녹화방식",
                media_forma: "파일방식",
                file_type: "파일유형",
                video_audio: "영상+음성",
                onliy_video: "영상",
                ftp: "파일명",
                email: "파일명",
                file_name: "파일명",
                action: "액션",
                max_record_time: "최대녹화시간"
            },
            lg: {
                msg: "스위치 언어 성공"
            },
            tf_card: {
                ok: "tf 카드 정상",
                no_card: "tf 카드가 인식되지 않았습니다",
                no_format: "tf 카드가 포맷되지 않았습니다",
                abnormal: "tf 카드 이상 (파티션 없음, 읽기 전용 등)",
                file_type: "파일 형식을 포맷합니다",
                is_delete: "TF 카드는 포맷된 건가요?",
                formatting: "tf 카드를 포맷하는 중입니다!",
                cancel: "취소",
                confirm: "확인"
            },
            network_settings: {
                name: "네트웍설정",
                wired_network: "유선네트웍설정",
                wifi_settings: "WIFI설정",
                s4g_settings: "4G설정",
                ip_address_filtering: "WIFI설정"
            },
            network_protocol: {
                enabled: "적용",
                name: "네트웍 프로토콜",
                http: "HTTP",
                rtsp: "RTSP",
                rtp: "RTP",
                ftp: "FTP",
                smtp: "SMTP",
                qos: "Qos",
                x8021: "802.1x",
                upnp: "uPnP",
                pppoe: "PPPoE",
                ntf: "NTP",
                ddns: "DDNS",
                http_port: "Http포트",
                listening_port: "감시포트",
                upgrade_port: "업그레드포트",
                multicast_ttl: "캐스트TTL",
                identity_authentication: "신분인증",
                rtmp: "RTMP",
                user: "사용자 이름",
                password: "암호",
                server_id: "服务器编号",
                server_url: "서버 주소",
                server_path: "서버 디렉토리",
                path: "경로",
                rtmp_enabled: "RTMP 사용",
                rstp_enabled: "신분 인증",
                rtp_enabled: "Ativar RTP",
                stream: "비디오 스 트림",
                port: "포트 번호",
                video_id: "비디오 ID",
                audio_id: "오디오 ID",
                talk_id: "인 터 콤 ID",
                mtu: "Mtu",
                udp: "UDP",
                udp_enabled: "UDP 멀티캐스트를 활성화합니다",
                udp_ip: "멀티 캐 스 트 IP",
                udp_port: "포트 번호",
                udp_url: "UDP 멀티캐스트 재생 주소",
                ftp_normal: "기본 인자"
            },
            time: {
                name: "시간",
                day_time: "일자/시간",
                start_time: "시작시간",
                end_time: "종료시간",
                to: "까지",
                monday: "월요일",
                tuesday: "화요일",
                wednesday: "수요일",
                thursday: "목요일",
                friday: "금요일",
                saturday: "토요일",
                weekday: "일요일",
                mouse_click: "클릭방식으로시간을선택",
                times_output: "시간선택이최대5개"
            },
            platform_settings: {
                gb28181: "GB28181",
                onvif: "ONVIF"
            },
            devices_maintenance: {
                about_devices: " 장치에 대해",
                devices_name: "디바이스명",
                devices_time: "작동시간",
                software_version: "Device Version",
                firmware_version: "Firmware Version",
                system_maintenance: "시스템유지보수",
                use_ntp: "NTP적용",
                use_computer: "PC동기화",
                use_multicast: "멀티캐스트 열기",
                video_streaming: "비디오 스트림 선택",
                IP_multicast: "멀티캐스트 IP",
                multicast_port: "멀티캐스트 포트",
                Play_address: "UDP멀티캐스트 재생 주소",
                equipment: "ID 설치",
                server: "서버URL"
            },
            osd: {
                basic_settings: "기본설정",
                system_settings: "시스템설정",
                custom_settings: "카스톰마이징",
                font_size: "Front Size",
                pellucidity: "투명도",
                use_title: "타이틀적용",
                color: "컬러",
                use: "적용 ",
                add_info: "메시지추가",
                custom_centent: "Custom Content",
                add_infos: {
                    rr: "해상도",
                    rpfr: "해상도+프레임",
                    rpfrcr: "해상도+프레임+비트"
                }
            },
            area: {
                red: "붉은",
                green: "녹색",
                yellow: "노란색",
                blue: "파란색"
            }
            }
          , S = {
            route: {
                dashboard: "Ao vivo",
                network_settings: "Configurações de rede",
                ip_settings: "Configurações de IP",
                gb28181_settings: "Configurações de GB28181",
                media_settings: "Configurações de mídia",
                video_capture: "Captura de vídeo",
                datetime_title: "Horário e Título",
                video_codec: "Codec de vídeo",
                audio_capture: "Captura de áudio",
                audio_codec: "Codec de áudio",
                fill_light: "Luz de preenchimento",
                privacy_mask: "Máscara de privacidade",
                warning_settings: "Configurações de alarme",
                human_recognition: "Reconhecimento humano",
                motion_detection: "Reconhecimento de movimento",
                occlusion_detection: "Detecção de máscara",
                system_settings: "Configurações do sistema",
                user_management: "Gerenciamento de usuários",
                system_time: "Horário do sistema",
                maintenance: "Manutenção do sistema",
                documentation: "Documentação",
                guide: "Guia",
                permission: "Autenticação",
                pagePermission: "Página de autenticação",
                rolePermission: "Função de autenticação",
                directivePermission: "Autenticação direta",
                page401: "401",
                page404: "404",
                errorLog: "Log de erros",
                theme: "Tema",
                clipboardDemo: "Área de transferência",
                i18n: "I18n",
                externalLink: "Perfil Externo",
                profile: "Perfil",
                language: "Idioma",
                storage: "Configurações de armazenamento",
                ptzcontrol: "Controle PTZ",
                audio_settings: "Configurações de áudio",
                network_protocol: "Protocolo de rede",
                platform_settings: "Configurações da plataforma",
                ai_settings: "Configurações AI",
                video_coding: "Codificação de vídeo",
                image_parameters: "Parâmetros de imagem",
                capture_settings: "Configurações de captura",
                osd_settings: "Configurações OSD",
                devices_maintenance: "Manutenção de dispositivos"
            },
            dashboard: {
                name: "Nome",
                id: "ID",
                version: "Versão",
                monitor: "Monitor",
                intercom: "Interfone",
                snapshot: "Snapshot",
                videotape: "Snapshot"
            },
            navbar: {
                dashboard: "Ao vivo",
                github: "Github",
                logOut: "Deslogar",
                profile: "Perfil",
                theme: "Tema",
                size: "Tamanho"
            },
            login: {
                title: "Forma de login",
                logIn: "Login",
                username: "Usuário",
                password: "Senha",
                any: "any",
                thirdparty: "A simulação não pode ser realizada localmente",
                thirdpartyTips: "Realize uma simulação com base no seu próprio negócio!!!",
                confirm_logout: "Confirm logout",
                re_login_msg: "You have been logged out, you can cancel to stay on this page, or log in again",
                restart_msg: "<div>Your modification requires an IPC restart to take effect. The system will exit in <span id='timed' style='color: #06B7AE'></span> seconds and log in again to function properly.</div>"
            },
            permission: {
                addRole: "Nova regra",
                editPermission: "Editar",
                roles: "Suas regras",
                switchRoles: "Alterar regra",
                tips: "",
                delete: "Deletar",
                confirm: "Confirmar",
                cancel: "Cancelar"
            },
            errorLog: {
                tips: "",
                description: "",
                documentation: "Doc. de introdução"
            },
            theme: {
                change: "Alterar tema",
                documentation: "Doc. de tema",
                tips: ""
            },
            tagsView: {
                refresh: "Atualizar",
                close: "Fechar",
                closeOthers: "Fechar outros",
                closeAll: "Fechar todos"
            },
            settings: {
                title: "Configuração de estilo de página",
                theme: "Tema de cores",
                tagsView: "Abrir Tags-View",
                fixedHeader: "Cabeçalho fixo",
                sidebarLogo: "Logo da barra lateral"
            },
            button: {
                save: "Salvar",
                view: "Visualizar",
                edit: "Editar",
                all: "Todos",
                all_list: "Listar todos",
                empty: "Vazio",
                delete: "Deletar",
                refresh: "Atualizar",
                search: "procurar",
                restart: "Reiniciar",
                setting: "Configurações",
                updatesoft: "Atualizar software",
                default: "Padrão",
                restore_factory: "Restaurar de fábrica",
                reset: "Reset",
                cancel: "Cancel",
                re_login: "Re-Login",
                yes: "Yes",
                no: "No"
            },
            ip_settings: {
                mac_address: "Endereço MAC",
                dhcp: "DHCP",
                self_adaption: "IP Estático",
                ipv4_addr: "Endereço IPv4",
                ipv4_mask: "Máscará IPv4",
                ipv4_gateway: "Gateway IPv4",
                ipv6_addr: "Endereço IPv6",
                ipv6_gateway: "Gateway IPv6",
                dns1: "DNS1",
                dns2: "DNS2",
                ip_settings: "Configurações de IP",
                auto_ip: "IP Autompatico",
                static_ip: "IP Estático",
                static_ddns: "DDNS Estático",
                auto_ddns: "DDNS Automático"
            },
            gb28181_settings: {
                enabled: "Habilitar 28181",
                local_sip_port: "Porta SIP local(1025-65525",
                sip_server_id: "ID Servidor SIP",
                sip_server_domain: "Domínio Servidor SIP",
                sip_server_ip: "IP Servidor SIP",
                sip_server_port: "Porta Servidor SIP(1-65535)",
                sip_username: "Usuário SIP",
                sip_user_auth_id: "Usuário de autenticação SIP",
                password: "Senha",
                password_confirm: "Confirmar senha",
                term_of_validity: "Prazo de validade(segundos)",
                heartbeat_cycle: "Heartbeat Cycle(5-3600)",
                max_heartbeat_timeout: "Max Heartbeat Timeout(3-255)",
                stream_index: "28181 Stream Index",
                video_channel_code_id: "VID do código do canal de vídeo",
                audio_channel_code_id: "ID do código do canal de áudio",
                alarm_id: "Alarm ID"
            },
            video_capture: {
                brightness: "Brilho",
                contrast: "Contraste",
                saturation: "Saturação",
                backlight: "Luz de fundo",
                sharpness: "Nitidez",
                video_standard: "Padrão de vídeo",
                horizontal_flip: "Inverter horizontalmente",
                vertical_flip: "Inverter verticalmente",
                prevent_overexposure: "Prevent Overexposure",
                scene_mode: "Modo de imagem",
                AE_sensitivity: "Sensibilidade AE",
                AE_tolerance: "Tolerância AE",
                exposure_mode: "Modo de exposição",
                white_balance: "Balanço de Branco",
                wide_dynamic: "Balanço de Branco",
                wide_dynamic_enhancement: "Amplo aprimoramento dinâmico",
                noise_reduction_3d: "Redução de ruído 3D",
                noise_reduction_3d_enhancement: "Aprimoramento de redução de ruído 3D",
                capture_setting: "Amplo aprimoramento dinâmico",
                advance_setting: "Configurações avançadas",
                auto: "Automático",
                indoor: "Interno",
                outdoor: "Externo",
                disable: "Desabilitar",
                manual: "Manual"
            },
            datetime_title: {
                datetime: "Data e hora",
                x: "Porcentagem de coordenada da área(%)",
                y: "Porcentagem de coordenada da área(%)",
                time_format: "Formato do horário",
                week: "Visualizar dia da semana",
                date_format: "Formato da data",
                style: "Estilo da semana",
                title: "Título",
                channel: "Canal",
                enabled: "Habilitar",
                name: "Nome do canal",
                hour24: "24 Horas",
                hour12: "12 horas",
                english: "Inglês",
                chinese: "Chinês"
            },
            video_codec: {
                main_stream: "Stream principal",
                encode_format: "Formato de codificação",
                resolve: "Resolução",
                bitrate: "Bitrate",
                framerate: "Taxa de quadros",
                bps: "Bitrate",
                keyframe_interval: "Intervalo de quadros",
                sub_stream: "Sub Stream",
                h264: "H.264",
                h265: "H.265",
                quality: "Qualidade",
                quality_tip: "（1-9 Quanto maior o número, melhor a qualidade）",
                first_main_stream: "primeira stream principal",
                first_sub_stream: "Primeira sub stream",
                second_main_stream: "Segunda stream principal",
                second_sub_stream: "Segunda sub secundária",
                stream_id: "ID da stream",
                profile: "Perfil "
            },
            audio_capture: {
                sample_rate: "Taxa de amostragem",
                sample_bit: "Taxa de bit",
                collect_volume: "Volume capturado",
                play_volume: "Volume reproduzido",
                input_method: "Método de entrada"
            },
            audio_codec: {
                encode_enabled: "Habilitar",
                encode_format: "Codificar",
                decode_enabled: "Decodificar"
            },
            fill_light: {
                ir_cut: "IR Cut Trigger",
                light_mode: "Modo de luz",
                image_mode: "Modo de imagem",
                photosensitive_type: "Photosensitive Type",
                start_sensitivity: "Sensibilidade inicial da fonte da luz",
                automatic_sensitivity: "Sensibilidade de ajuste automático da fonte de luz",
                light_type: "Tipo de luz",
                dimming_mode: "Modo de escurecimento",
                luminance: "Luminosidade(100%)",
                forward: "Forward",
                reverse: "Invertido",
                lampred: "Modo de escurecimento inteligente infravermelho",
                lampwhite: "Modo de escurecimento inteligente (uma fonte de luz)",
                lampdouble: "Modo de escurecimento inteligente (duas fontes de luz)",
                smart_lampred: "Infrared Intelligent Dimming Mode",
                smart_lampwhite: "White Light/Warm Light Intelligent Dimming Mode",
                smart_lampdouble: "Dual Light Source (Infrared, White/Warm) Intelligent Dimming Mode",
                auto: "Automático",
                day: "Dia",
                night: "Noite",
                timing: "Temporização",
                hard: "Hard",
                soft: "Soft",
                morning: "Manhã",
                middle: "Tarde",
                evening: "Noite",
                fast: "Rápido",
                slow: "Devagar",
                red_light: "Luz vermelha",
                warm_light: "Luz branca",
                manual: "Manual",
                night_start_time: "Night Start Time",
                night_end_time: "Night End Time"
            },
            privacy_mask: {
                privacy_zone: "Zona de privacidade",
                enabled: "Habilitar",
                x: "Coordenada X",
                y: "Coordenada Y",
                width: "Largura",
                height: "Altura",
                color: "Cor"
            },
            user_management: {
                name: "Name",
                password: "Password",
                group: "Group",
                enabled: "Enabled",
                operations: "Operations",
                edit: "Edit",
                remove: "Remove",
                add: "Add",
                admin: "Administrator",
                operator: "Operator",
                viewer: "Viewer",
                cancel: "Cancel",
                confirm: "Confirm",
                input_user: "Input User Information",
                confirm_password: "Enter the password again",
                built_in_user: "Built-in user cannot be deleted",
                invalid_user: "User name cannot be less than three characters",
                invalid_password: "The password can be less than 6 digits or confirm password are different.",
                user: "User"
            },
            system_time: {
                mode: "Modo de Operação",
                ntp_server: "Servidor NTP",
                port: "Porta NTP",
                sync_time: "Tempo de sincronização NTP",
                timezone: "Fuso horário",
                time: "Hora",
                same_host: "Consistente com o dispositivo",
                ntp: "NTP",
                manual: "Manual"
            },
            maintenance: {
                enabled: "Habilitar",
                day: "Dia da Manutenção",
                restart_time: "Tempo de reinicialização",
                sunday: "Domingo",
                monday: "Segunda-feira",
                tuesday: "Terça-feira",
                wednesday: "Quarta-feira",
                thursday: "Quinta-feira",
                friday: "Sexta-feira",
                saturday: "Sábado",
                everyday: "Cotidiano",
                am: "a.m.",
                pm: "p.m.",
                y: "Ano",
                m: "Mês",
                d: "Data",
                restarting: "Restarting",
                restore: "Restoring factory settings will lose all modified information and reset the IP address."
            },
            human_recognition: {
                enabled: "Habilitar",
                sensitivity: "Sensibilidade",
                alarm_mode: "Modo de alarme",
                flash_light: "Luz de flash",
                play_tone: "Reproduzir tom",
                area: "Área",
                defence: "Tempo de defesa",
                withdrawal: "Tempo de retirada",
                days: "Dias",
                repeat: "Repetições",
                voice: "Voz",
                m_f: "M-F",
                m_s: "M-S",
                sat_sun: "Sábado e domingo",
                sun: "Domingo",
                everyday: "Todos os dias",
                default: "Padrão",
                max_deployment_area: "The system only supports up to 4 deployment areas",
                tips: "Press the left button and drag to draw the area to be monitored, up to 4 areas"
            },
            occlusion_detection: {
                enabled: "Habilitar",
                area: "Área",
                sensitivity: "Sensibilidade",
                alarm_mode: "Modo de alarme",
                flash_light: "Luz de flash",
                play_tone: "Reproduzir tom",
                tips: "Pressione o botão esquerdo e arraste para desenhar a área monitorada"
            },
            motion_detection: {
                enabled: "Habilitar",
                sensitivity: "Sensibilidade",
                alarm_mode: "Modo de alarme",
                flash_light: "Luz de flash",
                play_tone: "Reproduzir tom"
            },
            ptzcontrol: {
                name: "PTZ",
                amplify: "Ampliar",
                focus: "Focalizar",
                aperture: "Abertura",
                ptz_speed: "Velocidade PTZ",
                doubling_speed: "Velocidade do zoom",
                focus_mode: "Modo de foco",
                focus_sensitivity: "Sensibilidade do foco",
                focus_area: "Área focalizada",
                preset_position: "Posição predefinida",
                code_stream: "Fluxo de código",
                base_set: "Configurações base",
                more_set: "Mais configurações"
            },
            storage: {
                storage: "Armazenamento",
                media_format: "Formato de mídia",
                image_save_path: "Path para salvar a imagem",
                video_save_path: "Path para salvar o vídeo",
                storage_device: "Dispositivo de armazenamento de cartão TF",
                save_setting: "Salvar configurações",
                storage_Plan: "Armazenamento de plano",
                storage_management: "Gerenciamento de armazenamento",
                video_files: "Arquivos de vídeo",
                record_audio: "Gravar áudio",
                tf_card: "Armazenamento de cartão TF",
                volume: "Estado",
                status: "Estado",
                format: "Formatar",
                unformat: "Desformatar",
                usb_disk: "Disco USB",
                total: "Total",
                used: "Utilizado",
                recording_status: "Estado de gravação",
                working_mode: "Modo de operação",
                video_stream: "Video Stream",
                video_file_size: "Tamanho do arquivo de vídeo",
                video_strategy: "Estratégia de vídeo",
                auto_override: "Substituição automática",
                full_stop: "Parar após alcançar limite",
                choose_time: "Escolha de tempo",
                manual_recording: "Gravação Manual",
                timer_recording: "Gravação de temporizador",
                recording_type: "Tipo de gravação",
                media_forma: "Formato de mídia",
                file_type: "Tipo de arquivo",
                video_audio: "Vídeo & Áudio",
                onliy_video: "Apenas vídeo",
                ftp: "Carregar servidores FTP",
                email: "Enviar e-mail",
                file_name: "Nome do arquivo",
                action: "Ação",
                max_record_time: "Tempo máximo de gravação"
            },
            lg: {
                msg: "Idioma alterado com sucesso"
            },
            tf_card: {
                ok: "TF card Ok",
                no_card: "No TF card",
                no_format: "TF card not format",
                abnormal: "TF card abnormal",
                file_type: "Format type",
                is_delete: "O cartão TF está formatado?",
                formatting: "Formatting TF Card!",
                cancel: "Cancelar",
                confirm: "Confirmar"
            },
            network_settings: {
                name: "Configurações de rede",
                wired_network: "Configurações de rede com fio",
                wifi_settings: "Configurações de rede WIFI",
                s4g_settings: "Configurações de 4G",
                ip_address_filtering: "Filtro de endereços IP"
            },
            network_protocol: {
                enabled: "Habilitar",
                name: "Protocolo de rede",
                http: "HTTP",
                rtsp: "RTSP",
                rtp: "RTP",
                ftp: "FTP",
                smtp: "SMTP",
                qos: "Qos",
                x8021: "802.1x",
                upnp: "uPnP",
                pppoe: "PPPoE",
                ntf: "NTP",
                ddns: "DDNS",
                http_port: "Porta HTTP",
                listening_port: "Porta de escuta",
                upgrade_port: "Porta de upgrade",
                multicast_ttl: "Multicast TTL",
                identity_authentication: "Identidade de autenticação",
                rtmp: "RTMP",
                user: "Nome de usuário",
                password: "Senha",
                server_id: "服务器编号",
                server_url: "Endereço do servidor",
                server_path: "Diretório de armazenamento do servidor",
                path: "Caminho",
                rtmp_enabled: "Habilitar RTMP",
                rstp_enabled: "Autenticação de identidade",
                rtp_enabled: "Ativar RTP",
                stream: "Fluxo de vídeo",
                port: "Número da porta",
                video_id: "ID do vídeo",
                audio_id: "ID de áudio",
                talk_id: "ID do intercomunicador",
                mtu: "Mtu",
                udp: "UDP",
                udp_enabled: "Habilitar Multicast UDP",
                udp_ip: "Multicast IP",
                udp_port: "Número da porta",
                udp_url: "Endereço de reprodução de multicast UDP",
                ftp_normal: "Parâmetro padrão"
            },
            time: {
                name: "Horário",
                day_time: "Dia/Hora",
                start_time: "Horário de início",
                end_time: "Horário final",
                to: "To",
                monday: "Segunda-feira",
                tuesday: "Terça-feira",
                wednesday: "Quarta-feira",
                thursday: "Quinta-feira",
                friday: "Sexta-feira",
                saturday: "Sábado",
                weekday: "Dias da semana",
                mouse_click: "Clique na quantidade de tempo",
                times_output: "Quantidade de tempo não pode passar de cinco"
            },
            platform_settings: {
                gb28181: "GB28181",
                onvif: "ONVIF"
            },
            devices_maintenance: {
                about_devices: "Sobre o dispositivos",
                devices_name: "Nome do dispositivo",
                devices_time: "Horário",
                software_version: "Versão de software",
                firmware_version: "Versão de firmware",
                system_maintenance: "Manutenção do sistema",
                use_ntp: "Habilitar NTP",
                use_computer: "Sincronizar com computador"
            },
            osd: {
                basic_settings: "Configuração básica",
                system_settings: "Configuração do sistema",
                custom_settings: "Configuração customizada",
                font_size: "Tamanho da fonte",
                pellucidity: "Transparência",
                use_title: "Habilitar título",
                color: "Cor",
                use: "Habilitar ",
                add_info: "Sobreposição",
                custom_centent: "Conteúdo custom",
                add_infos: {
                    rr: "Resolução",
                    rpfr: "Resolução e Taxa de frame",
                    rpfrcr: "Resolução e Taxa de frame e Taxa de code"
                }
            },
            area: {
                red: "Vermelho",
                green: "Verde",
                yellow: "Amarelo",
                blue: "Azul"
            }
            }
          , T = {
            route: {
                dashboard: "Живое видео",
                network_settings: "Сетевые настройки",
                ip_settings: "Настройка IP",
                gb28181_settings: "GB28181 Settings",
                media_settings: "Настройки медиа",
                video_capture: "Запись",
                datetime_title: "Время и текст",
                video_codec: "Видео кодек",
                audio_capture: "Видео кодек",
                audio_codec: "Аудио кодек",
                fill_light: "Свет для заправки",
                privacy_mask: "Маска для защиты данных",
                warning_settings: "Настройки тревоги ",
                human_recognition: "Обнаружение человека   ",
                motion_detection: "Детектор движения",
                occlusion_detection: "Обнаружение масок",
                system_settings: "Системные настройки",
                user_management: "Пользовательские настройки",
                system_time: "Системное время",
                maintenance: "Обслуживание системы",
                documentation: "Документация",
                guide: "Год",
                permission: "Аутентификация",
                pagePermission: "Страница аутентификации",
                rolePermission: "Роль",
                directivePermission: "Удостоверение подлинности в соответствии с директивой",
                page401: "401",
                page404: "404",
                errorLog: "Журнал ошибок",
                theme: "По теме:",
                clipboardDemo: "Глобализация и развитие",
                i18n: "I18n",
                externalLink: "Профиль",
                profile: "Профиль",
                language: "Язык",
                storage: "Настройки хранилища",
                ptzcontrol: "PTZ контроль",
                audio_settings: "Настройки аудио",
                network_protocol: "Сетевой протокол",
                platform_settings: "Настройки платформы",
                ai_settings: "Параметры ии",
                video_coding: "Кодирование",
                image_parameters: "Параметры изображения",
                capture_settings: "Настройки записи",
                osd_settings: "Настройки OSD",
                devices_maintenance: "Обслуживание устройств"
            },
            dashboard: {
                name: "Имя",
                id: "ID",
                version: "Версия",
                monitor: "Монитор",
                intercom: "Интерком",
                snapshot: "Снимок",
                videotape: "Видео"
            },
            navbar: {
                dashboard: "Живое видео",
                github: "Github",
                logOut: "Выйти",
                profile: "Профиль",
                theme: "Тема",
                size: "Размер"
            },
            login: {
                title: "Форма входа в систему",
                logIn: "Вход в систему",
                username: "Пользователь",
                password: "Пароль",
                any: "any",
                thirdparty: "Логин третьей стороны",
                thirdpartyTips: "Не могут быть смоделированы на местном, пожалуйста, объединить с вашим собственным бизнесом для моделирования! ! !"
            },
            permission: {
                addRole: "Новая роль",
                editPermission: "Редактировать",
                roles: "Ваши роли",
                switchRoles: "Смена ролей",
                tips: "",
                delete: "Удалить",
                confirm: "Подтвердить",
                cancel: "Отмена"
            },
            errorLog: {
                tips: "",
                description: "",
                documentation: "Введение к документу"
            },
            theme: {
                change: "Тема < < изменение > >",
                documentation: "Документация по теме",
                tips: ""
            },
            tagsView: {
                refresh: "Обновить",
                close: "Закрыть",
                closeOthers: "Закрыть другие",
                closeAll: "Закрыть все"
            },
            settings: {
                title: "Настройка стиля страницы",
                theme: "Цвет темы",
                tagsView: "Открытые тэги-view",
                fixedHeader: "Фиксированный заголовок",
                sidebarLogo: "Логотип боковой панели"
            },
            button: {
                save: "Сохранить",
                view: "Вид",
                edit: "Редактировать",
                all: "Все",
                all_list: "Весь лист",
                empty: "Очистить",
                delete: "Удалить",
                refresh: "Обновить",
                search: "Поиск",
                restart: "Перезапуск",
                setting: "Параметры",
                updatesoft: "Обновить софт",
                default: "По умолчанию",
                restore_factory: "Заодское значение",
                reset: "Перезагрузить"
            },
            ip_settings: {
                mac_address: "MAC Address",
                dhcp: "DHCP",
                self_adaption: "IP Self-Adaption",
                ipv4_addr: "IPv4 адрес",
                ipv4_mask: "IPv4 маска подсети",
                ipv4_gateway: "IPv4 шлюз",
                ipv6_addr: "IPv6 адрес",
                ipv6_gateway: "IPv6 шлюз",
                dns1: "DNS1",
                dns2: "DNS2",
                ip_settings: "Настройка IP",
                auto_ip: "Автоматический IP",
                static_ip: "Статический IP",
                static_ddns: "Статический DDNS",
                auto_ddns: "Автоматический DDNS"
            },
            gb28181_settings: {
                enabled: "Использовать 28181",
                local_sip_port: "Локальный SIP порт(1025-65525",
                sip_server_id: "SIP сервер ID",
                sip_server_domain: "Домен SIP сервера",
                sip_server_ip: "IP адрес SIP сервера",
                sip_server_port: "Порт SIP сервера(1-65535)",
                sip_username: "Имя SIP пользователя",
                sip_user_auth_id: "IP SIP пользователя",
                password: "Пароль",
                password_confirm: "Подтвердите пароль",
                term_of_validity: "Срок действия (секунд)",
                heartbeat_cycle: "Частота обновления(5-3600)",
                max_heartbeat_timeout: "Максимальное время обновления(3-255)",
                stream_index: "28181 индекс потока",
                video_channel_code_id: "ID кода видеоканала",
                audio_channel_code_id: "ID кода аудиоканала",
                alarm_id: "ID тревоги"
            },
            video_capture: {
                brightness: "Яркость",
                contrast: "Констраст",
                saturation: "Насыщенность",
                backlight: "Подсветка",
                sharpness: "Стандарт видеоs",
                video_standard: "Стандарт видео",
                horizontal_flip: "Отразить по горизонтали",
                vertical_flip: "Отразить по вертикали",
                prevent_overexposure: "Местоположение",
                scene_mode: "Местоположение",
                AE_sensitivity: "AE допуск",
                AE_tolerance: "AE допуск",
                exposure_mode: "Режим экспозиции",
                white_balance: "Баланс белого",
                wide_dynamic: "WD",
                wide_dynamic_enhancement: "WD коррекция",
                noise_reduction_3d: "3D шумоподавление",
                noise_reduction_3d_enhancement: "Интенсивность 3D-шумоподавления",
                capture_setting: "Предварительная настройка",
                advance_setting: "Предварительная настройка",
                auto: "Авто",
                indoor: "В помещении",
                outdoor: "Отключить",
                disable: "Отключить",
                manual: "Настроить"
            },
            datetime_title: {
                datetime: "Дата и время",
                x: "Доля в процентах (%)",
                y: "Доля в процентах (%)",
                time_format: "Формат времени",
                week: "Шоу-неделя",
                date_format: "Формат для даты",
                style: "Стиль недели",
                title: "Название сайта",
                channel: "По каналу связи",
                enabled: "Включена ли функция",
                name: "Название канала",
                hour24: "24 часа",
                hour12: "12 часов",
                english: "Английский язык",
                chinese: "китайск"
            },
            video_codec: {
                main_stream: "Основной поток",
                encode_format: "Кодек",
                resolve: "Разрешение",
                bitrate: "Тип битрейта",
                framerate: "частота кадров",
                bps: "Битрейт",
                keyframe_interval: "Интервал опорного кадра",
                sub_stream: "Суб поток",
                h264: "H.264",
                h265: "H.265",
                quality: "качеств",
                quality_tip: "（1-9 Чем выше числовое значение, тем лучше качество）",
                first_main_stream: "Первый основной поток",
                first_sub_stream: "Первый суб поток",
                second_main_stream: "Второй основной поток",
                second_sub_stream: "Второй суб поток",
                stream_id: "Stream ID",
                profile: "Профиль "
            },
            audio_capture: {
                sample_rate: "Частота дискретизации",
                sample_bit: "Глубина бит",
                collect_volume: "Чувствительность",
                play_volume: "Громкость воспроизведения",
                input_method: "Вход"
            },
            audio_codec: {
                encode_enabled: "Использовать",
                encode_format: "Кодек",
                decode_enabled: "Декодировать"
            },
            fill_light: {
                ir_cut: "активация",
                light_mode: "Световой режим",
                image_mode: "Режим изображения",
                photosensitive_type: "Светочувствительный тип",
                start_sensitivity: "Источник света активирует чувствительность",
                automatic_sensitivity: "Источник лампы автоматически регулирует чувствительность",
                light_type: "Тип света",
                dimming_mode: "Режим настройки света",
                luminance: "Яркость света(100%)",
                forward: "Направля к",
                reverse: "обратн",
                infrared: "Инфракрасный интеллект, настроенный на свет",
                white_warm_light: "Умные настройки белого света/теплового света",
                dual_light_source: "Двойной источник света (инфракрасный, белый свет/тепловой свет) — интеллектуальная фотомодуляция",
                auto: "автоматическ",
                day: "днем",
                night: "ноч",
                timing: "Замедлен действ",
                hard: "Жесткая светочувствительность",
                soft: "Мягкая светочувствительность",
                morning: "утр",
                middle: "В полден",
                evening: "ноч",
                fast: "быстр",
                slow: "медлен",
                red_light: "красн",
                warm_light: "Тепл свет",
                manual: "вручн"
            },
            privacy_mask: {
                privacy_zone: "Частная зона",
                enabled: "открыт",
                x: "X координат",
                y: "Y координат",
                width: "ширин",
                height: "высот",
                color: "цвет"
            },
            user_management: {
                name: "Имя пользователя.",
                password: "код",
                group: "Группа пользователей.",
                enabled: "открыт",
                operations: "операцион",
                edit: "модификац",
                remove: "удал",
                add: "добавля",
                admin: "Администратор.",
                operator: "оператор",
                viewer: "Наблюдатель",
                cancel: "отмен",
                confirm: "подтверд",
                input_user: "Ввод информации пользователя",
                confirm_password: "Введите еще раз",
                user: "пользовател"
            },
            system_time: {
                mode: "Способ работы",
                ntp_server: "NTP сервер",
                port: "NTP порт",
                sync_time: "Частота синхронизации",
                timezone: "Часовой пояс",
                time: "Время",
                same_host: "Согласуется с компьютером",
                ntp: "NTP",
                manual: "Заданное значенеи"
            },
            maintenance: {
                enabled: "Разрешить",
                day: "День технического обслуживания",
                restart_time: "Время перезапуска",
                sunday: "Воскресенье",
                monday: "Понедельник",
                tuesday: "Вторник",
                wednesday: "Среда",
                thursday: "Четверг",
                friday: "Пятница",
                saturday: "Суббота",
                everyday: "Каждый день",
                am: "a.m.",
                pm: "p.m.",
                y: "Год",
                m: "Месяц",
                d: "День"
            },
            human_recognition: {
                enabled: "открыт",
                sensitivity: "чувствительность",
                alarm_mode: "Сигнализация.",
                flash_light: "Сигнальные огни мигают",
                play_tone: "Включай",
                area: "региональн",
                defence: "Время на оборону.",
                withdrawal: "Время вывода.",
                days: "День на часах",
                repeat: "повторение",
                voice: "Сигнализация.",
                m_f: "С понедельника по пятницу",
                m_s: "С понедельника по субботу.",
                sat_sun: "Суббота и воскресенье",
                sun: "В воскресен",
                everyday: "Кажд ден",
                default: "По умолчан"
            },
            occlusion_detection: {
                enabled: "открыт",
                area: "региональн",
                sensitivity: "чувствительность",
                alarm_mode: "Сигнализация.",
                flash_light: "Сигнальные огни мигают",
                play_tone: "Включай",
                tips: "Нажмите на левую кнопку, передвиньте область, за которой нужно следить, и поддержите до четырех"
            },
            motion_detection: {
                enabled: "открыт",
                sensitivity: "чувствительность",
                alarm_mode: "Сигнализация.",
                flash_light: "Flash Light",
                play_tone: "Сигнальные огни мигают"
            },
            ptzcontrol: {
                name: "PTZ",
                amplify: "Увеличь",
                focus: "сфокусирова",
                aperture: "диафрагм",
                ptz_speed: "Скорость облаков",
                doubling_speed: "Скорость изменения",
                focus_mode: "Режим фокусировки",
                focus_sensitivity: "Чувствительность к фокусировке",
                focus_area: "Область фокусировки",
                preset_position: "Занять позиции.",
                code_stream: "Ярд поток",
                base_set: "Основная установка",
                more_set: "Больше настроек"
            },
            storage: {
                storage: "Хранилище",
                media_format: "Формат файла",
                image_save_path: "Сохранять изображение в",
                video_save_path: "Сохранять видео в",
                storage_device: "TF карта",
                save_setting: "Сохранить настройки",
                storage_Plan: "Расписание",
                storage_management: "Управление хранилищем",
                video_files: "Видео файл",
                record_audio: "Запись аудио",
                tf_card: "TF карта",
                volume: "Занято",
                status: "статус",
                format: "Форматировать",
                unformat: "Не форматирована",
                usb_disk: "USB диск",
                total: "Полный",
                used: "Используется",
                recording_status: "Статус записи",
                working_mode: "Рабочий режим",
                video_stream: "Видеопоток",
                video_file_size: "Размер файла",
                video_strategy: "При заполнении хранилища",
                auto_override: "Перезапись",
                full_stop: "Остановить при заполнении",
                choose_time: "Выбор времени",
                manual_recording: "Ручная регистрация данных",
                timer_recording: "Запись с таймером",
                recording_type: "Вид видео",
                media_forma: "Формат медиа",
                file_type: "Тип файла",
                video_audio: "Видео и аудио",
                onliy_video: "Только видео",
                ftp: "Загрузка FTP сервера",
                email: "Отправляю e-mail",
                file_name: "Имя файла",
                action: "операцион",
                max_record_time: "Максимальная длительность записи"
            },
            lg: {
                msg: "Перевести язык успеха"
            },
            tf_card: {
                ok: "TF card Ok",
                no_card: "No TF card",
                no_format: "TF card not format",
                abnormal: "TF card abnormal",
                file_type: "Format type",
                is_delete: "Форматирована ли TF карта?",
                formatting: "Formatting TF Card!",
                cancel: "Все в силе",
                confirm: "увер"
            },
            network_settings: {
                name: "Настройка сети",
                wired_network: "Настройка wi-fi",
                wifi_settings: "Настройка wi-fi",
                s4g_settings: "Установка на 4G",
                ip_address_filtering: "Фильтрация IP-адреса"
            },
            network_protocol: {
                enabled: "открыт",
                name: "Сетевой протокол",
                http: "HTTP",
                rtsp: "RTSP",
                rtp: "RTP",
                ftp: "FTP",
                smtp: "SMTP",
                qos: "Qos",
                x8021: "802.1x",
                upnp: "uPnP",
                pppoe: "PPPoE",
                ntf: "NTP",
                ddns: "DDNS",
                http_port: "Порт Http",
                listening_port: "Порт подслушивания",
                upgrade_port: "Обновленный порт",
                multicast_ttl: "Мультикаст TTL",
                identity_authentication: "Удостоверение личности",
                rtmp: "RTMP",
                user: "Имя пользователя",
                password: "Пароль для входа",
                server_id: "服务器编号",
                server_url: "Адрес сервера",
                server_path: "Каталог серверов",
                path: "Путь к успеху",
                rtmp_enabled: "Включение RTMP",
                rstp_enabled: "Удостоверение личности",
                rtp_enabled: "Включение RTP",
                stream: "Поток видео",
                port: "Номер порта",
                video_id: "Видео-ID",
                audio_id: "Аудиоid",
                talk_id: "Идентификатор интеркома",
                mtu: "Mtu",
                udp: "UDP",
                udp_enabled: "Включите UDP Multicast",
                udp_ip: "Multicast IP-адрес",
                udp_port: "Номер порта",
                udp_url: "Адрес воспроизводится группой UDP",
                ftp_normal: "Параметр по умолчанию"
            },
            time: {
                name: "Время",
                day_time: "День/Время",
                start_time: "Время начала",
                end_time: "Время конца",
                to: "To",
                monday: "понедельник",
                tuesday: "Вторник.",
                wednesday: "среда",
                thursday: "среда",
                friday: "пятница",
                saturday: "Суббота",
                weekday: "воскресенье",
                mouse_click: "Пожалуйста, выберите время с помощью мыши",
                times_output: "Время не может быть больше пяти"
            },
            platform_settings: {
                gb28181: "GB28181",
                onvif: "ONVIF"
            },
            devices_maintenance: {
                about_devices: "Об устройстве",
                devices_name: "Имя устройства",
                devices_time: "Время",
                software_version: "Версия устройства",
                firmware_version: "Версия прошивка",
                system_maintenance: "Обслуживание системы",
                use_ntp: "Использовать NTP",
                use_computer: "Синхронизация с ПК"
            },
            osd: {
                basic_settings: "Базовые настройки",
                system_settings: "Системные настройки",
                custom_settings: "Пользовательские настройки",
                font_size: "Размер передней части",
                pellucidity: "Прозрачность.",
                use_title: "Включить заголовок",
                color: "Цвет",
                use: "открыт ",
                add_info: "Наложенная информация",
                custom_centent: "Пользовательский контент",
                add_infos: {
                    rr: "Разрешающая способность",
                    rpfr: "Разрешающая способность & Частот кадр",
                    rpfrcr: "Разрешающая способность & Частот кадр & Уровен ярд"
                }
            },
            area: {
                red: "Зеленый",
                green: "Зеленый",
                yellow: " качество",
                blue: " качество"
            }
            }
          , I = {
            route: {
                dashboard: "实时视频",
                network_settings: "网络设置",
                ip_settings: "IP设置",
                gb28181_settings: "GB28181设置",
                rtmp_settings: "RTMP设置",
                media_settings: "视频设置",
                video_capture: "视频采集设置",
                datetime_title: "时间和标题",
                video_codec: "视频编码设置",
                audio_capture: "音频采集设置",
                audio_codec: "音频编码设置",
                fill_light: "补光灯设置",
                privacy_mask: "隐私遮挡设置",
                warning_settings: "报警设置",
                human_recognition: "人形识别",
                electric_vehicle_recognition: "电动车识别",
                fall_detection: "跌倒检测",
                flame_recognition: "火焰烟雾识别",
                smoke_detection: "抽烟检测",
                motion_detection: "移动侦测",
                occlusion_detection: "遮挡侦测",
                notifies: "告警通知",
                system_settings: "系统设置",
                user_management: "用户管理",
                system_time: "系统时间",
                maintenance: "系统维护",
                documentation: "文档",
                guide: "引导页",
                permission: "权限测试页",
                rolePermission: "角色权限",
                pagePermission: "页面权限",
                directivePermission: "指令权限",
                page401: "401",
                page404: "404",
                errorLog: "错误日志",
                theme: "换肤",
                i18n: "国际化",
                externalLink: "外链",
                profile: "个人中心",
                language: "语言",
                storage: "存储设置",
                ptzcontrol: "云台",
                audio_settings: "音频设置",
                network_protocol: "网络协议",
                platform_settings: "平台设置",
                intelligence_algorithms: "智能算法",
                ai_settings: "AI 功能",
                video_coding: "视频编码",
                image_parameters: "图像参数",
                capture_settings: "抓拍设置",
                osd_settings: "OSD设置",
                devices_maintenance: "设备维护"
            },
            dashboard: {
                name: "名称",
                id: "设备标识",
                version: "版本",
                monitor: "监听",
                intercom: "对讲",
                snapshot: "抓图",
                videotape: "录像"
            },
            navbar: {
                dashboard: "实时视频",
                github: "项目地址",
                logOut: "退出登录",
                profile: "个人中心",
                theme: "换肤",
                size: "布局大小"
            },
            login: {
                title: "系统登录",
                logIn: "登录",
                username: "账号",
                password: "密码",
                language: "语言",
                remeberPwd: "记住密码",
                any: "随便填",
                thirdparty: "第三方登录",
                thirdpartyTips: "本地不能模拟，请结合自己业务进行模拟！！！",
                confirm_logout: "确认注销",
                re_login_msg: "您已经注销，您可以取消以留在此页面，也可以重新登录",
                restart_msg: "<div>您的修改需要IPC重启方能生效，系统将在 <span id='timed' style='color: #06B7AE'></span> 秒后退出，重新登录方可正常使用</div>"
            },
            permission: {
                addRole: "新增角色",
                editPermission: "编辑权限",
                roles: "你的权限",
                switchRoles: "切换权限",
                tips: "",
                delete: "删除",
                confirm: "确定",
                cancel: "取消"
            },
            errorLog: {
                tips: "请点击右上角bug小图标",
                description: "现在的管理后台基本都是spa的形式了，它增强了用户体验，但同时也会增加页面出问题的可能性，可能一个小小的疏忽就导致整个页面的死锁。好在 Vue 官网提供了一个方法来捕获处理异常，你可以在其中进行错误处理或者异常上报。",
                documentation: "文档介绍"
            },
            theme: {
                change: "换肤",
                documentation: "换肤文档",
                tips: "Tips: 它区别于 navbar 上的 theme-pick, 是两种不同的换肤方法，各自有不同的应用场景，具体请参考文档。"
            },
            tagsView: {
                refresh: "取消",
                close: "关闭",
                closeOthers: "关闭其它",
                closeAll: "关闭所有"
            },
            settings: {
                title: "系统布局配置",
                theme: "主题色",
                tagsView: "开启 Tags-View",
                fixedHeader: "固定 Header",
                sidebarLogo: "侧边栏 Logo"
            },
            button: {
                save: "保存",
                view: "查看",
                edit: "编辑",
                all: "全选",
                all_list: "选中所有",
                empty: "清空",
                delete: "删除",
                refresh: "刷新",
                search: "查询",
                restart: "重启",
                setting: "设置",
                updatesoft: "软件升级",
                default: "恢复默认",
                restore_factory: "恢复出厂设置",
                reset: "重置",
                cancel: "取消",
                re_login: "重新登录",
                yes: "是",
                qr_code: "生成二维码",
                no: "否"
            },
            ip_settings: {
                mac_address: "MAC地址",
                dhcp: "DHCP",
                self_adaption: "IP 自适应",
                ipv4_addr: "IPv4 地址",
                ipv4_mask: "IPv4 子网掩码",
                ipv4_gateway: "IPv4 网关",
                ipv6_addr: "IPv6 地址",
                ipv6_gateway: "IPv6 网关",
                dns1: "DNS1",
                dns2: "DNS2",
                ip_settings: "IP获取设置",
                auto_ip: "自动获取IP",
                static_ip: "静态IP",
                static_ddns: "静态DDNS",
                auto_ddns: "自动获取DDNS"
            },
            wifi: {
                name: "名称",
                work_mode: "工作模式",
                wlan: "WLAN",
                ap: "AP热点",
                status: "连接状态",
                ssid: "SSID",
                password: "密码",
                connected: "已连接",
                not_connected: "未连接"
            },
            net_4g: {
                status: "连接状态",
                enabled: "开启"
            },
            gb28181_settings: {
                enabled: "启用28181协议",
                local_sip_port: "本地SIP端口(1025-65525",
                sip_server_id: "SIP服务器ID",
                sip_server_domain: "SIP服务器域",
                sip_server_ip: "SIP服务器地址",
                sip_server_port: "SIP服务器端口(1-65535)",
                sip_username: "SIP用户名",
                sip_user_auth_id: "SIP用户认证ID",
                password: "密码",
                password_confirm: "确认密码",
                term_of_validity: "注册有效期（秒）",
                heartbeat_cycle: "心跳周期(5-3600)",
                max_heartbeat_timeout: "最大心跳超时次数(3-255)",
                stream_index: "28181码流索引",
                video_channel_code_id: "视频通道编码ID",
                audio_channel_code_id: "音频输出通道ID",
                alarm_id: "报警ID"
            },
            rtmp_settings: {
                enabled: "启用RTMP",
                stream_type: "码流类型",
                remote_host: "服务器地址",
                remote_port: "端口号(1-65535)",
                app_name: "应用名称",
                stream_id: "流ID",
                illustrate: "说明",
                illustrate_context_1: "以上参数的含义是什么？例如RTMP推流URL如下，以字符/拆分可以得到对应的参数。",
                illustrate_context_2: " rtmp://abc.defgh.com/live/4287d428c?wsSecret=5ba27f7727a398a8",
                illustrate_context_3: "1) 服务器地址:   abc.defgh.com",
                illustrate_context_4: '2) 端口号:   \t 缺省时默认是1935，如果abc.defgh.com后面接着":数字"，该数字表示端口号',
                illustrate_context_5: "3) 应用名称:  \t live",
                illustrate_context_6: "4) 流ID:       4287d428c?wsSecret=5ba27f7727a398a"
            },
            video_capture: {
                brightness: "亮度",
                contrast: "对比度",
                saturation: "饱和度",
                backlight: "背光",
                sharpness: "锐度",
                video_standard: "视频制式",
                horizontal_flip: "水平翻转",
                vertical_flip: "垂直翻转",
                prevent_overexposure: "防止过曝",
                scene_mode: "场景模式",
                AE_sensitivity: "AE灵敏度",
                AE_tolerance: "AE容忍度",
                exposure_mode: "曝光模式",
                white_balance: "白平衡",
                wide_dynamic: "宽动态",
                wide_dynamic_enhancement: "宽动态增强",
                noise_reduction_3d: "3D降噪",
                noise_reduction_3d_enhancement: "3D降噪增强",
                capture_setting: "采集设置",
                advance_setting: "高级设置",
                auto: "自动",
                indoor: "室内",
                outdoor: "室外",
                disable: "禁用",
                manual: "手动"
            },
            datetime_title: {
                datetime: "启用日期",
                x: "区域横坐标百分比(%)",
                y: "区域纵坐标百分比(%)",
                time_format: "时间显示格式",
                week: "显示星期",
                date_format: "日期格式",
                style: "星期显示风格",
                title: "标题",
                channel: "通道号",
                enabled: "启用",
                name: "通道名(不超过32个字符)",
                hour24: "24小时",
                hour12: "12小时",
                english: "英文",
                chinese: "中文"
            },
            video_codec: {
                main_stream: "主码流",
                encode_format: "编码格式",
                resolve: "分辨率",
                bitrate: "码率控制",
                framerate: "帧率",
                bps: "码率",
                keyframe_interval: "关键帧间隔",
                sub_stream: "子码流",
                h264: "H.264",
                h265: "H.265",
                quality: "质量",
                quality_tip: "（1-9 数值越高，质量越好）",
                first_main_stream: "第一路主码流",
                first_sub_stream: "第一路子码流",
                second_main_stream: "第二路主码流",
                second_sub_stream: "第二路子码流",
                stream_id: "码流 ID",
                profile: "profile设置"
            },
            audio_capture: {
                sample_rate: "采样率",
                sample_bit: "位宽",
                collect_volume: "输入音量",
                play_volume: "输出音量",
                input_method: "输入方式"
            },
            audio_codec: {
                encode_enabled: "启用音频输入",
                encode_format: "编码方式",
                decode_enabled: "启用音频输出"
            },
            fill_light: {
                ir_cut: "IR CUT触发",
                light_mode: "灯光模式",
                image_mode: "图像模式",
                photosensitive_type: "光敏类型",
                start_sensitivity: "灯源启动灵敏度",
                automatic_sensitivity: "灯源自动调节灵敏度",
                light_type: "灯光类型",
                dimming_mode: "调光模式",
                luminance: "光照亮度(100%)",
                forward: "正向",
                reverse: "反向",
                lampred: "红外普通模式",
                lampwhite: "白光(暖光) 普通模式",
                lampdouble: "双光源(红外、白光/暖光) 普通模式",
                smart_lampred: "红外智能调光模式",
                smart_lampwhite: "白光/暖光智能调光模式",
                smart_lampdouble: "双光源（红外、白光/暖光）智能调光模式",
                auto: "自动",
                day: "白天",
                night: "夜晚",
                timing: "定时",
                hard: "硬光敏",
                soft: "软光敏",
                morning: "早",
                middle: "中",
                evening: "晚",
                fast: "高",
                slow: "低",
                red_light: "红光",
                warm_light: "暖光",
                manual: "手动",
                night_start_time: "夜晚开始时间",
                night_end_time: "夜晚结束时间"
            },
            privacy_mask: {
                privacy_zone: "隐私区域",
                enabled: "启用",
                x: "X 坐标",
                y: "Y 坐标",
                width: "宽度",
                height: "高度",
                color: "颜色"
            },
            user_management: {
                name: "用户名",
                password: "密码",
                group: "用户组",
                enabled: "启用",
                operations: "操作",
                edit: "修改",
                remove: "删除",
                add: "添加",
                admin: "管理员",
                operator: "操作员",
                viewer: "观察员",
                cancel: "取消",
                confirm: "确认",
                input_user: "输入用户信息",
                confirm_password: "再次输入密码",
                built_in_user: "内置用户无法删除",
                invalid_user: "用户名不能小于三个字符",
                invalid_password: "密码小于6个字符并且两次输入不一致",
                user: "用户"
            },
            system_time: {
                mode: "工作方式",
                ntp_server: "NTP 服务器",
                port: "NTP 端口",
                sync_time: "NTP 同步周期(分钟)",
                timezone: "时区",
                time: "时间",
                same_host: "与电脑一致",
                ntp: "NTP",
                manual: "手动"
            },
            maintenance: {
                enabled: "启用",
                day: "维护日",
                restart_time: "重启时间",
                sunday: "星期日",
                monday: "星期一",
                tuesday: "星期二",
                wednesday: "星期三",
                thursday: "星期四",
                friday: "星期五",
                saturday: "星期六",
                everyday: "每天",
                am: "上午",
                pm: "下午",
                y: "年",
                m: "月",
                d: "日",
                restarting: "正在重启中，稍后请重新登录",
                restore: "恢复出厂设置将丢失所有已修改的信息，并且会重置IP地址。"
            },
            human_recognition: {
                enabled: "启用",
                sensitivity: "灵敏度",
                alarm_mode: "报警方式",
                flash_light: "警示灯闪烁",
                play_tone: "播放提示音",
                area: "区域",
                defence: "布防时间",
                withdrawal: "撤防时间",
                days: "布防天数",
                repeat: "重复次数",
                voice: "报警声音",
                m_f: "周一到周五",
                m_s: "周一到周六",
                sat_sun: "周六与周日",
                sun: "周日",
                everyday: "每天",
                default: "默认",
                max_deployment_area: "系统最多只支持四个布防区域",
                tips: "按下左键，拖动绘制要监控的区域，最多支持4个区域"
            },
            occlusion_detection: {
                enabled: "启用",
                area: "区域",
                sensitivity: "灵敏度",
                alarm_mode: "报警方式",
                flash_light: "警示灯闪烁",
                play_tone: "播放提示音",
                tips: "按下左键，拖动绘制要监控的区域"
            },
            motion_detection: {
                enabled: "启用",
                sensitivity: "灵敏度",
                alarm_mode: "报警方式",
                flash_light: "警示灯闪烁",
                play_tone: "播放提示音",
                Video_stream: "录像码流",
                recording_recording: "预留录像时长",
                Recording_duration: "录像时长",
                signal_transfer: "IO报警输出",
                Number_snaps: "抓拍张数"
            },
            notify: {
                type: "类型",
                datetime: "时间",
                anthropomorphic: "人形侦测",
                motion: "移动侦测",
                occlusion: "遮挡侦测",
                none: "无效"
            },
            ptzcontrol: {
                name: "云台",
                amplify: "放大",
                focus: "聚焦",
                aperture: "光圈",
                ptz_speed: "云台速度",
                doubling_speed: "变倍速度",
                focus_mode: "聚焦模式",
                focus_sensitivity: "聚焦灵敏度",
                focus_area: "对焦区域",
                preset_position: "预设位置",
                code_stream: "码流",
                base_set: "基本设置",
                more_set: "更多设置",
                invoke_preset: "调用预设",
                add_preset: "添加预设",
                remove_preset: "删除预设"
            },
            storage: {
                storage: "存储",
                media_format: "录像格式",
                image_save_path: "抓图存储路径",
                video_save_path: "录像存储路径",
                storage_device: "TF卡存储设备",
                save_setting: "存储设置",
                storage_Plan: "存储计划",
                storage_management: "电脑存储设置",
                video_files: "录像文件",
                record_audio: "录制音频",
                tf_card: "TF卡管理",
                volume: "容量",
                status: "状态",
                format: "格式化",
                unformat: "未格式化",
                usb_disk: "U盘管理",
                total: "总共",
                used: "已用",
                recording_status: "启用录像",
                working_mode: "工作模式",
                video_stream: "录像码流",
                video_file_size: "录像文件大小",
                video_strategy: "录像策略",
                auto_override: "自动覆盖",
                full_stop: "录满停止",
                choose_time: "选择时间",
                manual_recording: "手动录像",
                timer_recording: "定时录像",
                recording_type: "录像类型",
                media_forma: "媒体格式",
                file_type: "文件类型",
                video_audio: "视频+音频",
                onliy_video: "仅视频",
                ftp: "上传FTP服务器",
                email: "发送Email",
                file_name: "文件名",
                action: "操作",
                max_record_time: "单个文件长度（分钟）"
            },
            lg: {
                msg: "切换语言成功"
            },
            tf_card: {
                ok: "TF卡正常",
                no_card: "未识别到TF卡",
                no_format: "TF卡未格式化",
                abnormal: "TF卡异常（未分区或者只读等)",
                file_type: "格式化文件类型",
                is_delete: "TF卡是否进行格式化?",
                formatting: "正在格式化TF卡!",
                cancel: "取消",
                confirm: "确定"
            },
            network_settings: {
                name: "网络设置",
                wired_network: "有线网络设置",
                wifi_settings: "WIFI设置",
                s4g_settings: "4G设置",
                ip_address_filtering: "IP地址过滤"
            },
            network_protocol: {
                enabled: "启用",
                name: "网络协议",
                http: "HTTP",
                rtsp: "RTSP",
                rtp: "RTP",
                ftp: "FTP",
                smtp: "SMTP",
                qos: "Qos",
                x8021: "802.1x",
                upnp: "uPnP",
                pppoe: "PPPoE",
                ntf: "NTP",
                ddns: "DDNS",
                http_port: "Http端口",
                listening_port: "监听端口",
                upgrade_port: "升级端口",
                multicast_ttl: "多播TTL",
                identity_authentication: "进行身份认证",
                udp: "UDP",
                rtmp: "RTMP",
                user: "用户名",
                password: "密码",
                server_id: "服务器编号",
                server_url: "服务器地址",
                server_path: "服务器存储目录",
                path: "路径",
                rtmp_enabled: "开启RTMP功能",
                rstp_enabled: "进行身份认证",
                rtp_enabled: "开启RTP",
                stream: "视频流",
                port: "端口",
                video_id: "视频ID",
                audio_id: "音频ID",
                talk_id: "对讲ID",
                mtu: "Mtu",
                udp_enabled: "开启UDP组播",
                udp_ip: "组播IP",
                udp_port: "开启UDP组播",
                udp_url: "UDP组播播放地址",
                ftp_normal: "默认参数"
            },
            time: {
                name: "时间",
                day_time: "日期/时间",
                start_time: "开始时间",
                end_time: "结束时间",
                to: "至",
                monday: "星期一",
                tuesday: "星期二",
                wednesday: "星期三",
                thursday: "星期四",
                friday: "星期五",
                saturday: "星期六",
                weekday: "星期日",
                mouse_click: "请用鼠标点选时间段",
                times_output: "时间段不能超过五个"
            },
            platform_settings: {
                mobile_monitoring: "手机监看",
                gb28181: "GB28181",
                onvif: "ONVIF"
            },
            devices_maintenance: {
                about_devices: "关于设备",
                devices_name: "设备名称",
                devices_time: "运行时间",
                software_version: "软件版本",
                firmware_version: "固件版本",
                system_maintenance: "系统维护",
                use_ntp: "启用NTP",
                use_computer: "手动设置",
                use_multicast: "开启组播",
                video_streaming: "选择视频流",
                IP_multicast: "组播IP",
                multicast_port: "组播端口",
                Play_address: "UDP组播播放地址",
                equipment: "ID 设置",
                server: "服务器URL"
            },
            osd: {
                basic_settings: "基本设置",
                system_settings: "系统设置",
                custom_settings: "自定义",
                font_size: "字体大小",
                pellucidity: "透明度",
                use_title: "启用标题",
                color: "颜色",
                use: "启用",
                add_info: "叠加信息",
                custom_centent: "自定义内容",
                add_infos: {
                    rr: "分辨率",
                    rpfr: "分辨率+帧率",
                    rpfrcr: "分辨率+帧率+码率"
                }
            },
            area: {
                red: "红色",
                green: "绿色",
                yellow: "黄色",
                blue: "蓝色"
            }
            };
        o["default"].use(n["a"]);
        var D = {
            en: Object(i["a"])(Object(i["a"])({}, y), c.a),
            it: Object(i["a"])(Object(i["a"])({}, w), m.a),
            ko: Object(i["a"])(Object(i["a"])({}, P), _.a),
            pt: Object(i["a"])(Object(i["a"])({}, S), g.a),
            ru: Object(i["a"])(Object(i["a"])({}, T), f.a),
            zh: Object(i["a"])(Object(i["a"])({}, I), b.a)
        };
        function z() {
            var e = s.a.get("language");
            if (e)
                return e;
            for (var t = (navigator.language || navigator.browserLanguage).toLowerCase(), a = Object.keys(D), i = 0, o = a; i < o.length; i++) {
                var n = o[i];
                if (t.indexOf(n) > -1)
                    return n
            }
            return "en"
        }
        var C = new n["a"]({
            locale: z(),
            messages: D
        });
        t["a"] = C
    },
    "9b34": function(e, t, a) {
        "use strict";
        a("b33c")
    },
    "9f15": function(e, t, a) {
        "use strict";
        a("d12c")
    },
    a18c: function(e, t, a) {
        "use strict";
        a.d(t, "b", (function() {
            return qe
        }
        )),
        a.d(t, "a", (function() {
            return We
        }
        )),
        a.d(t, "d", (function() {
            return Qe
        }
        ));
        a("d3b7"),
        a("3ca3"),
        a("ddb0");
        var i = a("2b0e")
          , o = a("8c4f")
          , n = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("div", {
                staticClass: "app-wrapper",
                class: e.classObj
            }, ["mobile" === e.device && e.sidebar.opened ? a("div", {
                staticClass: "drawer-bg",
                on: {
                    click: e.handleClickOutside
                }
            }) : e._e(), a("sidebar", {
                staticClass: "sidebar-container"
            }), a("div", {
                staticClass: "main-container"
            }, [a("div", {
                class: {
                    "fixed-header": e.fixedHeader
                }
            }, [a("navbar")], 1), a("app-main")], 1)], 1)
        }
          , r = []
          , s = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("section", {
                staticClass: "app-main"
            }, [a("transition", {
                attrs: {
                    name: "fade-transform",
                    mode: "out-in"
                }
            }, [a("router-view", {
                key: e.key
            })], 1)], 1)
        }
          , d = []
          , c = {
            name: "AppMain",
            computed: {
                key: function() {
                    return this.$route.path
                }
            }
        }
          , l = c
          , m = (a("2224"),
        a("0ae2d"),
        a("2877"))
          , u = Object(m["a"])(l, s, d, !1, null, "64cf4d83", null)
          , _ = u.exports
          , p = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("div", {
                staticClass: "navbar"
            }, [a("hamburger", {
                staticClass: "hamburger-container",
                attrs: {
                    "is-active": e.sidebar.opened
                },
                on: {
                    toggleClick: e.toggleSideBar
                }
            }), a("breadcrumb", {
                staticClass: "breadcrumb-container"
            }), a("div", {
                staticClass: "right-menu"
            }, [[a("lang-select", {
                staticClass: "right-menu-item hover-effect"
            })], a("el-dropdown", {
                staticClass: "avatar-container right-menu-item hover-effect",
                attrs: {
                    trigger: "click"
                }
            }, [a("i", {
                staticClass: "el-icon-user-solid",
                staticStyle: {
                    "font-size": "14px"
                }
            }, [e._v(" " + e._s(e.userName()))]), a("el-dropdown-menu", {
                staticClass: "user-dropdown",
                attrs: {
                    slot: "dropdown"
                },
                slot: "dropdown"
            }, [a("router-link", {
                attrs: {
                    to: "/"
                }
            }, [a("el-dropdown-item", [e._v(" " + e._s(e.$t("navbar.dashboard")) + " ")])], 1), a("a", {
                attrs: {
                    target: "_blank"
                },
                on: {
                    click: function(t) {
                        e.centerDialogVisible = !0
                    }
                }
            }, [a("el-dropdown-item", [e._v(" " + e._s(e.$t("navbar.theme")) + " ")])], 1), a("el-dropdown-item", {
                attrs: {
                    divided: ""
                },
                nativeOn: {
                    click: function(t) {
                        return e.logout(t)
                    }
                }
            }, [a("span", {
                staticStyle: {
                    display: "block"
                }
            }, [e._v(e._s(e.$t("navbar.logOut")))])])], 1)], 1)], 2), a("el-dialog", {
                attrs: {
                    title: e.$t("navbar.theme"),
                    visible: e.centerDialogVisible,
                    width: "40%",
                    center: ""
                },
                on: {
                    "update:visible": function(t) {
                        e.centerDialogVisible = t
                    }
                }
            }, [a("theme-picker", {
                on: {
                    click: e.themeChange
                }
            })], 1)], 1)
        }
          , g = []
          , h = a("c7eb")
          , f = a("1da1")
          , v = a("5530")
          , b = (a("b0c0"),
        a("2f62"))
          , y = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("el-breadcrumb", {
                staticClass: "app-breadcrumb",
                attrs: {
                    separator: "/"
                }
            }, [a("transition-group", {
                attrs: {
                    name: "breadcrumb"
                }
            }, e._l(e.levelList, (function(t, i) {
                return a("el-breadcrumb-item", {
                    key: t.path
                }, ["noRedirect" === t.redirect || i === e.levelList.length - 1 ? a("span", {
                    staticClass: "no-redirect"
                }, [e._v(" " + e._s(e.generateTitle(t.meta.title)) + " ")]) : a("a", {
                    on: {
                        click: function(a) {
                            return a.preventDefault(),
                            e.handleLink(t)
                        }
                    }
                }, [e._v(e._s(e.generateTitle(t.meta.title)))])])
            }
            )), 1)], 1)
        }
          , w = [];
        a("2ca0"),
        a("4de4"),
        a("99af"),
        a("498a");
        function P(e) {
            var t = this.$te("route." + e);
            return t ? this.$t("route." + e) : e
        }
        var S, T, I = a("bd11"), D = a.n(I), z = {
            data: function() {
                return {
                    levelList: null
                }
            },
            watch: {
                $route: function(e) {
                    e.path.startsWith("/redirect/") || this.getBreadcrumb()
                }
            },
            created: function() {
                this.getBreadcrumb()
            },
            methods: {
                generateTitle: P,
                getBreadcrumb: function() {
                    var e = this.$route.matched.filter((function(e) {
                        return e.meta && e.meta.title
                    }
                    ))
                      , t = e[0];
                    this.isDashboard(t) || (e = [{
                        path: "/dashboard",
                        meta: {
                            title: "dashboard"
                        }
                    }].concat(e)),
                    this.levelList = e.filter((function(e) {
                        return e.meta && e.meta.title && !1 !== e.meta.breadcrumb
                    }
                    ))
                },
                isDashboard: function(e) {
                    var t = e && e.name;
                    return !!t && t.trim().toLocaleLowerCase() === "Dashboard".toLocaleLowerCase()
                },
                pathCompile: function(e) {
                    var t = this.$route.params
                      , a = D.a.compile(e);
                    return a(t)
                },
                handleLink: function(e) {
                    var t = e.redirect
                      , a = e.path;
                    t ? this.$router.push(t) : this.$router.push(this.pathCompile(a))
                }
            }
        }, C = z, k = (a("0cfd"),
        Object(m["a"])(C, y, w, !1, null, "b57c6daa", null)), A = k.exports, M = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("div", {
                staticStyle: {
                    padding: "0 15px"
                },
                on: {
                    click: e.toggleClick
                }
            }, [a("svg", {
                staticClass: "hamburger",
                class: {
                    "is-active": e.isActive
                },
                attrs: {
                    viewBox: "0 0 1024 1024",
                    xmlns: "http://www.w3.org/2000/svg",
                    width: "64",
                    height: "64"
                }
            }, [a("path", {
                attrs: {
                    d: "M408 442h480c4.4 0 8-3.6 8-8v-56c0-4.4-3.6-8-8-8H408c-4.4 0-8 3.6-8 8v56c0 4.4 3.6 8 8 8zm-8 204c0 4.4 3.6 8 8 8h480c4.4 0 8-3.6 8-8v-56c0-4.4-3.6-8-8-8H408c-4.4 0-8 3.6-8 8v56zm504-486H120c-4.4 0-8 3.6-8 8v56c0 4.4 3.6 8 8 8h784c4.4 0 8-3.6 8-8v-56c0-4.4-3.6-8-8-8zm0 632H120c-4.4 0-8 3.6-8 8v56c0 4.4 3.6 8 8 8h784c4.4 0 8-3.6 8-8v-56c0-4.4-3.6-8-8-8zM142.4 642.1L298.7 519a8.84 8.84 0 0 0 0-13.9L142.4 381.9c-5.8-4.6-14.4-.5-14.4 6.9v246.3a8.9 8.9 0 0 0 14.4 7z"
                }
            })])])
        }, x = [], R = {
            name: "Hamburger",
            props: {
                isActive: {
                    type: Boolean,
                    default: !1
                }
            },
            methods: {
                toggleClick: function() {
                    this.$emit("toggleClick")
                }
            }
        }, E = R, O = (a("8dd0"),
        Object(m["a"])(E, M, x, !1, null, "49e15297", null)), L = O.exports, N = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("el-dropdown", {
                attrs: {
                    trigger: "click"
                },
                on: {
                    command: e.handleSetLanguage
                }
            }, [a("el-button", {
                attrs: {
                    size: "medium",
                    type: "text"
                }
            }, [e._v(" " + e._s(e.$t("route.language"))), a("i", {
                staticClass: "el-icon-arrow-down el-icon--right"
            })]), a("el-dropdown-menu", {
                attrs: {
                    slot: "dropdown"
                },
                slot: "dropdown"
            }, [a("el-dropdown-item", {
                attrs: {
                    disabled: "zh" === e.language,
                    command: "zh"
                }
            }, [e._v(" 中文 ")]), a("el-dropdown-item", {
                attrs: {
                    disabled: "en" === e.language,
                    command: "en"
                }
            }, [e._v(" English ")]), a("el-dropdown-item", {
                attrs: {
                    disabled: "it" === e.language,
                    command: "it"
                }
            }, [e._v(" Italiano ")]), a("el-dropdown-item", {
                attrs: {
                    disabled: "ko" === e.language,
                    command: "ko"
                }
            }, [e._v(" 한국어 ")]), a("el-dropdown-item", {
                attrs: {
                    disabled: "pt" === e.language,
                    command: "pt"
                }
            }, [e._v(" Português ")]), a("el-dropdown-item", {
                attrs: {
                    disabled: "ru" === e.language,
                    command: "ru"
                }
            }, [e._v(" Русский язык ")])], 1)], 1)
        }, F = [], V = {
            computed: {
                language: function() {
                    return this.$store.getters.language
                }
            },
            methods: {
                handleSetLanguage: function(e) {
                    this.$i18n.locale = e,
                    this.$store.dispatch("app/setLanguage", e),
                    this.$message({
                        message: this.$t("lg.msg"),
                        type: "success"
                    })
                }
            }
        }, H = V, B = Object(m["a"])(H, N, F, !1, null, null, null), j = B.exports, U = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("div", {
                staticClass: "ctheme",
                staticStyle: {
                    clear: "both",
                    float: "none",
                    "text-align": "center"
                },
                attrs: {
                    center: ""
                }
            }, [a("ul", e._l(e.colors, (function(t, i) {
                return a("li", {
                    key: i,
                    staticClass: "ctheme",
                    style: {
                        background: t
                    },
                    attrs: {
                        value: t
                    },
                    on: {
                        click: function(a) {
                            return e.changetheme(t)
                        }
                    }
                })
            }
            )), 0), a("div", [a("el-button", {
                on: {
                    click: function(t) {
                        return e.changetheme("#4796ff")
                    }
                }
            }, [e._v(e._s(e.$t("button.default")))])], 1)])
        }, G = [], $ = (a("ac1f"),
        a("5319"),
        a("fb6a"),
        a("00b4"),
        a("4d63"),
        a("2c3e"),
        a("25f0"),
        a("159b"),
        a("a15b"),
        a("a9e3"),
        a("b680"),
        a("f6f8").version), q = "#4796ff", W = {
            data: function() {
                return {
                    chalk: "",
                    theme: "",
                    colors: ["#4796ff", "#339966", "#FF9800", "#1890ff", "#304156", "#3F51B5", "#009688", "#6959CD", "#9C27B0"]
                }
            },
            computed: {
                defaultTheme: function() {
                    return this.$store.state.settings.theme
                }
            },
            watch: {
                defaultTheme: {
                    handler: function(e, t) {
                        this.theme = e
                    },
                    immediate: !0
                },
                theme: function(e) {
                    var t = this;
                    return Object(f["a"])(Object(h["a"])().mark((function a() {
                        var i, o, n, r, s, d, c, l;
                        return Object(h["a"])().wrap((function(a) {
                            while (1)
                                switch (a.prev = a.next) {
                                case 0:
                                    if (i = t.chalk ? t.theme : q,
                                    "string" === typeof e) {
                                        a.next = 3;
                                        break
                                    }
                                    return a.abrupt("return");
                                case 3:
                                    if (o = t.getThemeCluster(e.replace("#", "")),
                                    n = t.getThemeCluster(i.replace("#", "")),
                                    console.log(o, n),
                                    r = t.$message({
                                        message: "  Compiling the theme",
                                        customClass: "theme-message",
                                        type: "success",
                                        duration: 0,
                                        iconClass: "el-icon-loading"
                                    }),
                                    s = function(e, a) {
                                        return function() {
                                            var i = t.getThemeCluster(q.replace("#", ""))
                                              , n = t.updateStyle(t[e], i, o)
                                              , r = document.getElementById(a);
                                            r || (r = document.createElement("style"),
                                            r.setAttribute("id", a),
                                            document.head.appendChild(r)),
                                            r.innerText = n
                                        }
                                    }
                                    ,
                                    t.chalk) {
                                        a.next = 12;
                                        break
                                    }
                                    return d = "https://unpkg.com/element-ui@".concat($, "/lib/theme-chalk/index.css"),
                                    a.next = 12,
                                    t.getCSSString(d, "chalk");
                                case 12:
                                    c = s("chalk", "chalk-style"),
                                    c(),
                                    l = [].slice.call(document.querySelectorAll("style")).filter((function(e) {
                                        var t = e.innerText;
                                        return new RegExp(i,"i").test(t) && !/Chalk Variables/.test(t)
                                    }
                                    )),
                                    l.forEach((function(e) {
                                        var a = e.innerText;
                                        "string" === typeof a && (e.innerText = t.updateStyle(a, n, o))
                                    }
                                    )),
                                    t.updateCustomStyle(t.theme),
                                    t.$emit("change", e),
                                    r.close();
                                case 19:
                                case "end":
                                    return a.stop()
                                }
                        }
                        ), a)
                    }
                    )))()
                }
            },
            methods: {
                changetheme: function(e) {
                    this.$store.state.settings.theme = e
                },
                updateStyle: function(e, t, a) {
                    var i = e;
                    return t.forEach((function(e, t) {
                        i = i.replace(new RegExp(e,"ig"), a[t])
                    }
                    )),
                    i
                },
                updateCustomStyle: function(e) {
                    var t = this.lightDarkenColor(e, -30)
                      , a = this.lightDarkenColor(e, 10)
                      , i = this.lightDarkenColor(e, -10)
                      , o = this.lightDarkenColor(e, 60);
                    window.document.getElementsByTagName("body")[0].style.setProperty("--customer-base-color", e),
                    window.document.getElementsByTagName("body")[0].style.setProperty("--customer-base-color2", t),
                    window.document.getElementsByTagName("body")[0].style.setProperty("--customer-base-color3", a),
                    window.document.getElementsByTagName("body")[0].style.setProperty("--customer-base-color4", i),
                    window.document.getElementsByTagName("body")[0].style.setProperty("--customer-base-color5", o)
                },
                getRgbNum: function(e) {
                    if (4 === e.length) {
                        for (var t = "#", a = 1; a < 4; a += 1)
                            t += e.slice(a, a + 1).concat(e.slice(a, a + 1));
                        e = t
                    }
                    for (var i = [], o = 1; o < 7; o += 2)
                        i.push(parseInt("0x" + e.slice(o, o + 2)));
                    return i
                },
                colorRgba: function(e, t) {
                    var a = /^#([0-9a-fA-f]{3}|[0-9a-fA-f]{6})$/
                      , i = e.toLowerCase();
                    if (t = t || 1,
                    i && a.test(i)) {
                        var o = this.getRgbNum(i);
                        return "rgba(" + o.join(",") + "," + t + ")"
                    }
                    return i
                },
                lightDarkenColor: function(e, t) {
                    for (var a = this.getRgbNum(e), i = [], o = 0; o < a.length; o++) {
                        var n = a[o] + t;
                        n < 0 && (n = 0),
                        n > 255 && (n = 255),
                        i.push(n)
                    }
                    return "rgba(" + i.join(",") + ",1)"
                },
                getCSSString: function(e, t) {
                    var a = this;
                    return new Promise((function(i) {
                        var o = new XMLHttpRequest;
                        o.onreadystatechange = function() {
                            4 === o.readyState && 200 === o.status && (a[t] = o.responseText.replace(/@font-face{[^}]+}/, ""),
                            i())
                        }
                        ,
                        o.open("GET", e),
                        o.send()
                    }
                    ))
                },
                getThemeCluster: function(e) {
                    for (var t = function(e, t) {
                        var a = parseInt(e.slice(0, 2), 16)
                          , i = parseInt(e.slice(2, 4), 16)
                          , o = parseInt(e.slice(4, 6), 16);
                        return 0 === t ? [a, i, o].join(",") : (a += Math.round(t * (255 - a)),
                        i += Math.round(t * (255 - i)),
                        o += Math.round(t * (255 - o)),
                        a = a.toString(16),
                        i = i.toString(16),
                        o = o.toString(16),
                        "#".concat(a).concat(i).concat(o))
                    }, a = function(e, t) {
                        var a = parseInt(e.slice(0, 2), 16)
                          , i = parseInt(e.slice(2, 4), 16)
                          , o = parseInt(e.slice(4, 6), 16);
                        return a = Math.round((1 - t) * a),
                        i = Math.round((1 - t) * i),
                        o = Math.round((1 - t) * o),
                        a = a.toString(16),
                        i = i.toString(16),
                        o = o.toString(16),
                        "#".concat(a).concat(i).concat(o)
                    }, i = [e], o = 0; o <= 9; o++)
                        i.push(t(e, Number((o / 10).toFixed(2))));
                    return i.push(a(e, .1)),
                    i
                }
            }
        }, Y = W, Z = (a("9b34"),
        Object(m["a"])(Y, U, G, !1, null, null, null)), Q = Z.exports, X = {
            components: {
                Breadcrumb: A,
                Hamburger: L,
                LangSelect: j,
                ThemePicker: Q
            },
            data: function() {
                return {
                    centerDialogVisible: !1
                }
            },
            computed: Object(v["a"])({}, Object(b["b"])(["sidebar", "avatar"])),
            methods: {
                toggleSideBar: function() {
                    this.$store.dispatch("app/toggleSideBar")
                },
                logout: function() {
                    var e = this;
                    return Object(f["a"])(Object(h["a"])().mark((function t() {
                        return Object(h["a"])().wrap((function(t) {
                            while (1)
                                switch (t.prev = t.next) {
                                case 0:
                                    return t.next = 2,
                                    e.$store.dispatch("user/logout");
                                case 2:
                                    e.$router.push("/login?redirect=".concat(e.$route.fullPath));
                                case 3:
                                case "end":
                                    return t.stop()
                                }
                        }
                        ), t)
                    }
                    )))()
                },
                godashboard: function() {
                    this.$router.push("/")
                },
                userName: function() {
                    return this.$store.getters.name
                },
                themeChange: function(e) {
                    this.$store.dispatch("settings/changeSetting", {
                        key: "theme",
                        value: e
                    })
                }
            }
        }, K = X, J = (a("9f15"),
        Object(m["a"])(K, p, g, !1, null, "2ba78d24", null)), ee = J.exports, te = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("div", {
                class: {
                    "has-logo": e.showLogo
                }
            }, [e.showLogo ? a("logo", {
                attrs: {
                    collapse: e.isCollapse
                }
            }) : e._e(), a("el-scrollbar", {
                attrs: {
                    "wrap-class": "scrollbar-wrapper"
                }
            }, [a("el-menu", {
                attrs: {
                    "default-active": e.activeMenu,
                    collapse: e.isCollapse,
                    "background-color": e.variables.menuBg,
                    "text-color": e.variables.menuText,
                    "unique-opened": !1,
                    "active-text-color": e.variables.menuActiveText,
                    "collapse-transition": !1,
                    mode: "vertical"
                }
            }, e._l(e.routes, (function(e) {
                return a("sidebar-item", {
                    key: e.path,
                    attrs: {
                        item: e,
                        "base-path": e.path
                    }
                })
            }
            )), 1)], 1)], 1)
        }, ae = [], ie = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a("div", {
                staticClass: "sidebar-logo-container",
                class: {
                    collapse: e.collapse
                }
            }, [a("transition", {
                attrs: {
                    name: "sidebarLogoFade"
                }
            }, [e.collapse ? a("router-link", {
                key: "collapse",
                staticClass: "sidebar-logo-link",
                attrs: {
                    to: "/"
                }
            }, [e.logo ? a("img", {
                staticClass: "sidebar-logo",
                attrs: {
                    src: e.logo
                }
            }) : a("h1", {
                staticClass: "sidebar-title"
            }, [e._v(e._s(e.title) + " ")])]) : a("router-link", {
                key: "expand",
                staticClass: "sidebar-logo-link",
                attrs: {
                    to: "/"
                }
            }, [e.logo ? a("img", {
                staticClass: "sidebar-logo",
                attrs: {
                    src: e.logo
                }
            }) : e._e(), a("h1", {
                staticClass: "sidebar-title",
                domProps: {
                    innerHTML: e._s(e.title)
                }
            })])], 1)], 1)
        }, oe = [], ne = a("4c54"), re = a.n(ne), se = {
            name: "SidebarLogo",
            props: {
                collapse: {
                    type: Boolean,
                    required: !0
                }
            },
            data: function() {
                return {
                    title: "创安威视<br/>icamvision",
                    logo: re.a
                }
            }
        }, de = se, ce = (a("8969"),
        Object(m["a"])(de, ie, oe, !1, null, "27be41ed", null)), le = ce.exports, me = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return e.item.hidden ? e._e() : a("div", [!e.hasOneShowingChild(e.item.children, e.item) || e.onlyOneChild.children && !e.onlyOneChild.noShowingChildren || e.item.alwaysShow ? a("el-submenu", {
                ref: "subMenu",
                attrs: {
                    index: e.resolvePath(e.item.path),
                    "popper-append-to-body": ""
                }
            }, [a("template", {
                slot: "title"
            }, [e.item.meta ? a("item", {
                attrs: {
                    icon: e.item.meta && e.item.meta.icon,
                    title: e.generateTitle(e.item.meta.title)
                }
            }) : e._e()], 1), e._l(e.item.children, (function(t) {
                return a("sidebar-item", {
                    key: t.path,
                    staticClass: "nest-menu",
                    attrs: {
                        "is-nest": !0,
                        item: t,
                        "base-path": e.resolvePath(t.path)
                    }
                })
            }
            ))], 2) : [e.onlyOneChild.meta ? a("app-link", {
                attrs: {
                    to: e.resolvePath(e.onlyOneChild.path)
                }
            }, [a("el-menu-item", {
                class: {
                    "submenu-title-noDropdown": !e.isNest
                },
                attrs: {
                    index: e.resolvePath(e.onlyOneChild.path)
                }
            }, [a("item", {
                attrs: {
                    icon: e.onlyOneChild.meta.icon || e.item.meta && e.item.meta.icon,
                    title: e.generateTitle(e.onlyOneChild.meta.title)
                }
            })], 1)], 1) : e._e()]], 2)
        }, ue = [], _e = a("df7c"), pe = a.n(_e), ge = a("61f7"), he = (a("caad"),
        a("2532"),
        {
            name: "MenuItem",
            functional: !0,
            props: {
                icon: {
                    type: String,
                    default: ""
                },
                title: {
                    type: String,
                    default: ""
                }
            },
            render: function(e, t) {
                var a = t.props
                  , i = a.icon
                  , o = a.title
                  , n = [];
                return i && (i.includes("el-icon") ? n.push(e("i", {
                    class: [i, "sub-el-icon"]
                })) : n.push(e("svg-icon", {
                    attrs: {
                        "icon-class": i
                    }
                }))),
                o && n.push(e("span", {
                    slot: "title"
                }, [o])),
                n
            }
        }), fe = he, ve = (a("f87e"),
        Object(m["a"])(fe, S, T, !1, null, "18eeea00", null)), be = ve.exports, ye = function() {
            var e = this
              , t = e.$createElement
              , a = e._self._c || t;
            return a(e.type, e._b({
                tag: "component"
            }, "component", e.linkProps(e.to), !1), [e._t("default")], 2)
        }, we = [], Pe = {
            props: {
                to: {
                    type: String,
                    required: !0
                }
            },
            computed: {
                isExternal: function() {
                    return Object(ge["b"])(this.to)
                },
                type: function() {
                    return this.isExternal ? "a" : "router-link"
                }
            },
            methods: {
                linkProps: function(e) {
                    return this.isExternal ? {
                        href: e,
                        target: "_blank",
                        rel: "noopener"
                    } : {
                        to: e
                    }
                }
            }
        }, Se = Pe, Te = Object(m["a"])(Se, ye, we, !1, null, null, null), Ie = Te.exports, De = {
            computed: {
                device: function() {
                    return this.$store.state.app.device
                }
            },
            mounted: function() {
                this.fixBugIniOS()
            },
            methods: {
                fixBugIniOS: function() {
                    var e = this
                      , t = this.$refs.subMenu;
                    if (t) {
                        var a = t.handleMouseleave;
                        t.handleMouseleave = function(t) {
                            "mobile" !== e.device && a(t)
                        }
                    }
                }
            }
        }, ze = {
            name: "SidebarItem",
            components: {
                Item: be,
                AppLink: Ie
            },
            mixins: [De],
            props: {
                item: {
                    type: Object,
                    required: !0
                },
                isNest: {
                    type: Boolean,
                    default: !1
                },
                basePath: {
                    type: String,
                    default: ""
                }
            },
            data: function() {
                return this.onlyOneChild = null,
                {}
            },
            methods: {
                hasOneShowingChild: function() {
                    var e = this
                      , t = arguments.length > 0 && void 0 !== arguments[0] ? arguments[0] : []
                      , a = arguments.length > 1 ? arguments[1] : void 0
                      , i = t.filter((function(t) {
                        return !t.hidden && (e.onlyOneChild = t,
                        !0)
                    }
                    ));
                    return 1 === i.length || 0 === i.length && (this.onlyOneChild = Object(v["a"])(Object(v["a"])({}, a), {}, {
                        path: "",
                        noShowingChildren: !0
                    }),
                    !0)
                },
                resolvePath: function(e) {
                    return Object(ge["b"])(e) ? e : Object(ge["b"])(this.basePath) ? this.basePath : pe.a.resolve(this.basePath, e)
                },
                generateTitle: P
            }
        }, Ce = ze, ke = Object(m["a"])(Ce, me, ue, !1, null, null, null), Ae = ke.exports, Me = a("cf1e"), xe = a.n(Me), Re = {
            components: {
                SidebarItem: Ae,
                Logo: le
            },
            computed: Object(v["a"])(Object(v["a"])({}, Object(b["b"])(["sidebar"])), {}, {
                routes: function() {
                    return this.$router.options.routes
                },
                activeMenu: function() {
                    var e = this.$route
                      , t = e.meta
                      , a = e.path;
                    return t.activeMenu ? t.activeMenu : a
                },
                showLogo: function() {
                    return this.$store.state.settings.sidebarLogo
                },
                variables: function() {
                    return xe.a
                },
                isCollapse: function() {
                    return !this.sidebar.opened
                }
            })
        }, Ee = Re, Oe = Object(m["a"])(Ee, te, ae, !1, null, null, null), Le = Oe.exports, Ne = a("4360"), Fe = document, Ve = Fe.body, He = 992, Be = {
            watch: {
                $route: function(e) {
                    "mobile" === this.device && this.sidebar.opened && Ne["a"].dispatch("app/closeSideBar", {
                        withoutAnimation: !1
                    })
                }
            },
            beforeMount: function() {
                window.addEventListener("resize", this.$_resizeHandler)
            },
            beforeDestroy: function() {
                window.removeEventListener("resize", this.$_resizeHandler)
            },
            mounted: function() {
                var e = this.$_isMobile();
                e && (Ne["a"].dispatch("app/toggleDevice", "mobile"),
                Ne["a"].dispatch("app/closeSideBar", {
                    withoutAnimation: !0
                }))
            },
            methods: {
                $_isMobile: function() {
                    var e = Ve.getBoundingClientRect();
                    return e.width - 1 < He
                },
                $_resizeHandler: function() {
                    if (!document.hidden) {
                        var e = this.$_isMobile();
                        Ne["a"].dispatch("app/toggleDevice", e ? "mobile" : "desktop"),
                        e && Ne["a"].dispatch("app/closeSideBar", {
                            withoutAnimation: !0
                        })
                    }
                }
            }
        }, je = {
            name: "Layout",
            components: {
                Navbar: ee,
                Sidebar: Le,
                AppMain: _
            },
            mixins: [Be],
            computed: {
                sidebar: function() {
                    return this.$store.state.app.sidebar
                },
                device: function() {
                    return this.$store.state.app.device
                },
                showSettings: function() {
                    return this.$store.state.settings.showSettings
                },
                fixedHeader: function() {
                    return this.$store.state.settings.fixedHeader
                },
                classObj: function() {
                    return {
                        hideSidebar: !this.sidebar.opened,
                        openSidebar: this.sidebar.opened,
                        withoutAnimation: this.sidebar.withoutAnimation,
                        mobile: "mobile" === this.device
                    }
                }
            },
            created: function() {},
            methods: {
                handleClickOutside: function() {
                    this.$store.dispatch("app/closeSideBar", {
                        withoutAnimation: !1
                    })
                }
            }
        }, Ue = je, Ge = (a("61c4"),
        Object(m["a"])(Ue, n, r, !1, null, "e553f17e", null)), $e = Ge.exports;
        i["default"].use(o["a"]);
        var qe = [{
            path: "/login",
            component: function() {
                return a.e("chunk-2d0f1194").then(a.bind(null, "9ed6"))
            },
            hidden: !0
        }, {
            path: "/404",
            component: function() {
                return a.e("chunk-159c7f2c").then(a.bind(null, "8cdb"))
            },
            hidden: !0
        }, {
            path: "/",
            component: $e,
            redirect: "/dashboard",
            hidden: !0,
            children: [{
                path: "dashboard",
                component: function() {
                    return Promise.all([a.e("chunk-03e6a162"), a.e("chunk-7fd58bf5")]).then(a.bind(null, "9406"))
                },
                name: "Dashboard",
                meta: {
                    title: "dashboard",
                    icon: "dashboard"
                }
            }]
        }, {
            path: "/media-settings",
            component: $e,
            redirect: "/media-settings/",
            children: [{
                path: "media_settings",
                component: function() {
                    return a.e("chunk-5a2d7c13").then(a.bind(null, "abac"))
                },
                name: "media_settings",
                meta: {
                    title: "media_settings",
                    icon: "el-icon-video-camera-solid"
                }
            }]
        }, {
            path: "/network-settings",
            component: $e,
            redirect: "/network-settings/",
            children: [{
                path: "network_settings",
                component: function() {
                    return a.e("chunk-c65e1b8c").then(a.bind(null, "6b83"))
                },
                name: "network_settings",
                meta: {
                    title: "network_settings",
                    icon: "el-icon-eleme"
                }
            }]
        }, {
            path: "/network-protocol",
            component: $e,
            redirect: "/network-protocol/",
            children: [{
                path: "network_protocol",
                component: function() {
                    return Promise.all([a.e("chunk-71a95a4d"), a.e("chunk-1bfa552a")]).then(a.bind(null, "ba1a"))
                },
                name: "network_protocol",
                meta: {
                    title: "network_protocol",
                    icon: "el-icon-connection"
                }
            }]
        }, {
            path: "/audio-settings",
            component: $e,
            redirect: "/audio-ettings/",
            children: [{
                path: "audio_settings",
                component: function() {
                    return a.e("chunk-0e5d24a1").then(a.bind(null, "fec4"))
                },
                name: "audio_settings",
                meta: {
                    title: "audio_settings",
                    icon: "el-icon-mic"
                }
            }]
        }, {
            path: "/warning-settings",
            component: $e,
            redirect: "/warning-settings/",
            children: [{
                path: "warning_settings",
                component: function() {
                    return Promise.all([a.e("chunk-ab1962b6"), a.e("chunk-5f959fd6")]).then(a.bind(null, "700d"))
                },
                name: "warning_settings",
                meta: {
                    title: "warning_settings",
                    icon: "el-icon-bell"
                }
            }]
        }, {
            path: "/storage",
            component: $e,
            children: [{
                path: "/storage",
                name: "storage",
                component: function() {
                    return a.e("chunk-1ef2d540").then(a.bind(null, "bd113"))
                },
                meta: {
                    title: "storage",
                    icon: "el-icon-s-cooperation"
                }
            }]
        }, {
            path: "/platform-settings",
            component: $e,
            children: [{
                path: "/platform-settings",
                name: "platform_settings",
                component: function() {
                    return a.e("chunk-bdea0ffe").then(a.bind(null, "76ef"))
                },
                meta: {
                    title: "platform_settings",
                    icon: "el-icon-s-platform"
                }
            }]
        }, {
            path: "/intelligence_algorithms",
            component: $e,
            children: [{
                path: "/platform-intelligence_algorithms",
                name: "intelligence_algorithms",
                component: function() {
                    return Promise.all([a.e("chunk-ab1962b6"), a.e("chunk-dc15f838")]).then(a.bind(null, "8880"))
                },
                meta: {
                    title: "intelligence_algorithms",
                    icon: "el-icon-s-opportunity"
                }
            }]
        }, {
            path: "/user-management",
            component: $e,
            meta: {
                roles: ["admin"]
            },
            children: [{
                path: "/user-management",
                name: "user_management",
                component: function() {
                    return a.e("chunk-f51db6cc").then(a.bind(null, "6235"))
                },
                meta: {
                    title: "user_management",
                    icon: "el-icon-user",
                    roles: ["admin"]
                }
            }]
        }, {
            path: "/system-settings",
            component: $e,
            redirect: "/system-settings/",
            children: [{
                path: "/system-settings",
                component: function() {
                    return a.e("chunk-69dbd776").then(a.bind(null, "6d70"))
                },
                name: "devices_maintenance",
                meta: {
                    title: "devices_maintenance",
                    icon: "el-icon-menu"
                }
            }]
        }, {
            path: "*",
            redirect: "/404",
            hidden: !0
        }]
          , We = []
          , Ye = function() {
            return new o["a"]({
                scrollBehavior: function() {
                    return {
                        y: 0
                    }
                },
                routes: qe
            })
        }
          , Ze = Ye();
        function Qe() {
            var e = Ye();
            Ze.matcher = e.matcher
        }
        t["c"] = Ze
    },
    b20f: function(e, t, a) {
        e.exports = {
            menuText: "#bfcbd9",
            menuActiveText: "#409eff",
            subMenuActiveText: "#f4f4f5",
            menuBg: "#304156",
            menuHover: "#263445",
            subMenuBg: "#1f2d3d",
            subMenuHover: "#001528",
            sideBarWidth: "210px"
        }
    },
    b33c: function(e, t, a) {},
    b3b5: function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("e017")
          , o = a.n(i)
          , n = a("21a1")
          , r = a.n(n)
          , s = new o.a({
            id: "icon-user",
            use: "icon-user-usage",
            viewBox: "0 0 130 130",
            content: '<symbol xmlns="http://www.w3.org/2000/svg" viewBox="0 0 130 130" id="icon-user"><path d="M63.444 64.996c20.633 0 37.359-14.308 37.359-31.953 0-17.649-16.726-31.952-37.359-31.952-20.631 0-37.36 14.303-37.358 31.952 0 17.645 16.727 31.953 37.359 31.953zM80.57 75.65H49.434c-26.652 0-48.26 18.477-48.26 41.27v2.664c0 9.316 21.608 9.325 48.26 9.325H80.57c26.649 0 48.256-.344 48.256-9.325v-2.663c0-22.794-21.605-41.271-48.256-41.271z" stroke="#979797" /></symbol>'
        });
        r.a.add(s);
        t["default"] = s
    },
    b775: function(e, t, a) {
        "use strict";
        a("d3b7");
        var i = a("bc3a")
          , o = a.n(i)
          , n = a("5c96")
          , r = a("4360")
          , s = a("5f87")
          , d = a("9923");
        function c(e) {
            var t = d["a"].te("".concat(e));
            if (t) {
                var a = d["a"].t("".concat(e));
                return "".concat(a)
            }
            return "".concat(e)
        }
        var l = o.a.create({
            baseURL: "/api",
            timeout: 5e3
        });
        l.interceptors.request.use((function(e) {
            return r["a"].getters.token && (e.headers["X-Token"] = Object(s["a"])()),
            e
        }
        ), (function(e) {
            return console.log(e),
            Promise.reject(e)
        }
        )),
        l.interceptors.response.use((function(e) {
            var t = e.data;
            return 2e4 !== t.code ? (50008 !== t.code && 50012 !== t.code && 50014 !== t.code || n["MessageBox"].confirm(c("login.re_login_msg"), c("login.confirm_logout"), {
                confirmButtonText: c("button.re_login"),
                cancelButtonText: c("button.cancel"),
                type: "warning"
            }).then((function() {
                r["a"].dispatch("user/resetToken").then((function() {
                    location.reload()
                }
                ))
            }
            )),
            Promise.reject(new Error(t.message || "Error"))) : t
        }
        ), (function(e) {
            return console.log("err" + e),
            Promise.reject(e)
        }
        )),
        t["a"] = l
    },
    c459: function(e, t, a) {},
    c653: function(e, t, a) {
        var i = {
            "./app.js": "d9cd",
            "./errorLog.js": "4d49",
            "./permission.js": "31c2",
            "./settings.js": "0781",
            "./user.js": "0f9a"
        };
        function o(e) {
            var t = n(e);
            return a(t)
        }
        function n(e) {
            if (!a.o(i, e)) {
                var t = new Error("Cannot find module '" + e + "'");
                throw t.code = "MODULE_NOT_FOUND",
                t
            }
            return i[e]
        }
        o.keys = function() {
            return Object.keys(i)
        }
        ,
        o.resolve = n,
        e.exports = o,
        o.id = "c653"
    },
    cbd7: function(e, t, a) {},
    cf1e: function(e, t, a) {
        e.exports = {
            menuText: "#bfcbd9",
            menuActiveText: "#409eff",
            subMenuActiveText: "#f4f4f5",
            menuBg: "#304156",
            menuHover: "#263445",
            subMenuBg: "#1f2d3d",
            subMenuHover: "#001528",
            sideBarWidth: "210px"
        }
    },
    d12c: function(e, t, a) {},
    d52e: function(e, t, a) {},
    d7ec: function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("e017")
          , o = a.n(i)
          , n = a("21a1")
          , r = a.n(n)
          , s = new o.a({
            id: "icon-eye-open",
            use: "icon-eye-open-usage",
            viewBox: "0 0 1024 1024",
            content: '<symbol class="icon" viewBox="0 0 1024 1024" xmlns="http://www.w3.org/2000/svg" id="icon-eye-open"><defs><style></style></defs><path d="M512 128q69.675 0 135.51 21.163t115.498 54.997 93.483 74.837 73.685 82.006 51.67 74.837 32.17 54.827L1024 512q-2.347 4.992-6.315 13.483T998.87 560.17t-31.658 51.669-44.331 59.99-56.832 64.34-69.504 60.16-82.347 51.5-94.848 34.687T512 896q-69.675 0-135.51-21.163t-115.498-54.826-93.483-74.326-73.685-81.493-51.67-74.496-32.17-54.997L0 513.707q2.347-4.992 6.315-13.483t18.816-34.816 31.658-51.84 44.331-60.33 56.832-64.683 69.504-60.331 82.347-51.84 94.848-34.816T512 128.085zm0 85.333q-46.677 0-91.648 12.331t-81.152 31.83-70.656 47.146-59.648 54.485-48.853 57.686-37.675 52.821-26.325 43.99q12.33 21.674 26.325 43.52t37.675 52.351 48.853 57.003 59.648 53.845T339.2 767.02t81.152 31.488T512 810.667t91.648-12.331 81.152-31.659 70.656-46.848 59.648-54.186 48.853-57.344 37.675-52.651T927.957 512q-12.33-21.675-26.325-43.648t-37.675-52.65-48.853-57.345-59.648-54.186-70.656-46.848-81.152-31.659T512 213.334zm0 128q70.656 0 120.661 50.006T682.667 512 632.66 632.661 512 682.667 391.339 632.66 341.333 512t50.006-120.661T512 341.333zm0 85.334q-35.328 0-60.33 25.002T426.666 512t25.002 60.33T512 597.334t60.33-25.002T597.334 512t-25.002-60.33T512 426.666z" /></symbol>'
        });
        r.a.add(s);
        t["default"] = s
    },
    d9cd: function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("a78e")
          , o = a.n(i)
          , n = a("9923")
          , r = {
            sidebar: {
                opened: !o.a.get("sidebarStatus") || !!+o.a.get("sidebarStatus"),
                withoutAnimation: !1
            },
            device: "desktop",
            language: Object(n["b"])()
        }
          , s = {
            TOGGLE_SIDEBAR: function(e) {
                e.sidebar.opened = !e.sidebar.opened,
                e.sidebar.withoutAnimation = !1,
                e.sidebar.opened ? o.a.set("sidebarStatus", 1) : o.a.set("sidebarStatus", 0)
            },
            CLOSE_SIDEBAR: function(e, t) {
                o.a.set("sidebarStatus", 0),
                e.sidebar.opened = !1,
                e.sidebar.withoutAnimation = t
            },
            TOGGLE_DEVICE: function(e, t) {
                e.device = t
            },
            SET_LANGUAGE: function(e, t) {
                e.language = t,
                o.a.set("language", t)
            }
        }
          , d = {
            toggleSideBar: function(e) {
                var t = e.commit;
                t("TOGGLE_SIDEBAR")
            },
            closeSideBar: function(e, t) {
                var a = e.commit
                  , i = t.withoutAnimation;
                a("CLOSE_SIDEBAR", i)
            },
            toggleDevice: function(e, t) {
                var a = e.commit;
                a("TOGGLE_DEVICE", t)
            },
            setLanguage: function(e, t) {
                var a = e.commit;
                a("SET_LANGUAGE", t)
            }
        };
        t["default"] = {
            namespaced: !0,
            state: r,
            mutations: s,
            actions: d
        }
    },
    dcea: function(e, t, a) {},
    dcf8: function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("e017")
          , o = a.n(i)
          , n = a("21a1")
          , r = a.n(n)
          , s = new o.a({
            id: "icon-nested",
            use: "icon-nested-usage",
            viewBox: "0 0 128 128",
            content: '<symbol xmlns="http://www.w3.org/2000/svg" viewBox="0 0 128 128" id="icon-nested"><path d="M.002 9.2c0 5.044 3.58 9.133 7.998 9.133 4.417 0 7.997-4.089 7.997-9.133 0-5.043-3.58-9.132-7.997-9.132S.002 4.157.002 9.2zM31.997.066h95.981V18.33H31.997V.066zm0 45.669c0 5.044 3.58 9.132 7.998 9.132 4.417 0 7.997-4.088 7.997-9.132 0-3.263-1.524-6.278-3.998-7.91-2.475-1.63-5.524-1.63-7.998 0-2.475 1.632-4 4.647-4 7.91zM63.992 36.6h63.986v18.265H63.992V36.6zm-31.995 82.2c0 5.043 3.58 9.132 7.998 9.132 4.417 0 7.997-4.089 7.997-9.132 0-5.044-3.58-9.133-7.997-9.133s-7.998 4.089-7.998 9.133zm31.995-9.131h63.986v18.265H63.992V109.67zm0-27.404c0 5.044 3.58 9.133 7.998 9.133 4.417 0 7.997-4.089 7.997-9.133 0-3.263-1.524-6.277-3.998-7.909-2.475-1.631-5.524-1.631-7.998 0-2.475 1.632-4 4.646-4 7.91zm31.995-9.13h31.991V91.4H95.987V73.135z" /></symbol>'
        });
        r.a.add(s);
        t["default"] = s
    },
    eb1b: function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("e017")
          , o = a.n(i)
          , n = a("21a1")
          , r = a.n(n)
          , s = new o.a({
            id: "icon-form",
            use: "icon-form-usage",
            viewBox: "0 0 128 128",
            content: '<symbol xmlns="http://www.w3.org/2000/svg" viewBox="0 0 128 128" id="icon-form"><path d="M84.068 23.784c-1.02 0-1.877-.32-2.572-.96a8.588 8.588 0 0 1-1.738-2.237 11.524 11.524 0 0 1-1.042-2.621c-.232-.895-.348-1.641-.348-2.238V0h.278c.834 0 1.622.085 2.363.256.742.17 1.645.575 2.711 1.214 1.066.64 2.363 1.535 3.892 2.686 1.53 1.15 3.453 2.664 5.77 4.54 2.502 2.045 4.494 3.771 5.977 5.178 1.483 1.406 2.618 2.6 3.406 3.58.787.98 1.274 1.812 1.46 2.494.185.682.277 1.278.277 1.79v2.046H84.068zM127.3 84.01c.278.682.464 1.535.556 2.558.093 1.023-.37 2.003-1.39 2.94-.463.427-.88.832-1.25 1.215-.372.384-.696.704-.974.96a6.69 6.69 0 0 1-.973.767l-11.816-10.741a44.331 44.331 0 0 0 1.877-1.535 31.028 31.028 0 0 1 1.737-1.406c1.112-.938 2.317-1.343 3.615-1.215 1.297.128 2.363.405 3.197.83.927.427 1.923 1.173 2.989 2.239 1.065 1.065 1.876 2.195 2.432 3.388zM78.23 95.902c2.038 0 3.752-.511 5.143-1.534l-26.969 25.83H18.037c-1.761 0-3.684-.47-5.77-1.407a24.549 24.549 0 0 1-5.838-3.709 21.373 21.373 0 0 1-4.518-5.306c-1.204-2.003-1.807-4.07-1.807-6.202V16.495c0-1.79.44-3.665 1.32-5.626A18.41 18.41 0 0 1 5.04 5.562a21.798 21.798 0 0 1 5.213-3.964C12.198.533 14.237 0 16.37 0h53.24v15.984c0 1.62.278 3.367.834 5.242a16.704 16.704 0 0 0 2.572 5.179c1.159 1.577 2.665 2.898 4.518 3.964 1.853 1.066 4.078 1.598 6.673 1.598h20.295v42.325L85.458 92.45c1.02-1.364 1.529-2.856 1.529-4.476 0-2.216-.857-4.113-2.572-5.69-1.714-1.577-3.776-2.366-6.186-2.366H26.1c-2.409 0-4.448.789-6.116 2.366-1.668 1.577-2.502 3.474-2.502 5.69 0 2.217.834 4.092 2.502 5.626 1.668 1.535 3.707 2.302 6.117 2.302h52.13zM26.1 47.951c-2.41 0-4.449.789-6.117 2.366-1.668 1.577-2.502 3.473-2.502 5.69 0 2.216.834 4.092 2.502 5.626 1.668 1.534 3.707 2.302 6.117 2.302h52.13c2.409 0 4.47-.768 6.185-2.302 1.715-1.534 2.572-3.41 2.572-5.626 0-2.217-.857-4.113-2.572-5.69-1.714-1.577-3.776-2.366-6.186-2.366H26.1zm52.407 64.063l1.807-1.663 3.476-3.196a479.75 479.75 0 0 0 4.587-4.284 500.757 500.757 0 0 1 5.004-4.667c3.985-3.666 8.48-7.758 13.485-12.276l11.677 10.741-13.485 12.404-5.004 4.603-4.587 4.22a179.46 179.46 0 0 0-3.267 3.068c-.88.853-1.367 1.322-1.46 1.407-.463.341-.973.703-1.529 1.087-.556.383-1.112.703-1.668.959-.556.256-1.413.575-2.572.959a83.5 83.5 0 0 1-3.545 1.087 72.2 72.2 0 0 1-3.475.895c-1.112.256-1.946.426-2.502.511-1.112.17-1.854.043-2.224-.383-.371-.426-.464-1.151-.278-2.174.092-.511.278-1.279.556-2.302.278-1.023.602-2.067.973-3.132l1.042-3.005c.325-.938.58-1.577.765-1.918a10.157 10.157 0 0 1 2.224-2.941z" /></symbol>'
        });
        r.a.add(s);
        t["default"] = s
    },
    f6c3: function(e, t, a) {},
    f782: function(e, t, a) {
        "use strict";
        a.r(t);
        var i = a("e017")
          , o = a.n(i)
          , n = a("21a1")
          , r = a.n(n)
          , s = new o.a({
            id: "icon-dashboard",
            use: "icon-dashboard-usage",
            viewBox: "0 0 128 100",
            content: '<symbol xmlns="http://www.w3.org/2000/svg" viewBox="0 0 128 100" id="icon-dashboard"><path d="M27.429 63.638c0-2.508-.893-4.65-2.679-6.424-1.786-1.775-3.94-2.662-6.464-2.662-2.524 0-4.679.887-6.465 2.662-1.785 1.774-2.678 3.916-2.678 6.424 0 2.508.893 4.65 2.678 6.424 1.786 1.775 3.94 2.662 6.465 2.662 2.524 0 4.678-.887 6.464-2.662 1.786-1.775 2.679-3.916 2.679-6.424zm13.714-31.801c0-2.508-.893-4.65-2.679-6.424-1.785-1.775-3.94-2.662-6.464-2.662-2.524 0-4.679.887-6.464 2.662-1.786 1.774-2.679 3.916-2.679 6.424 0 2.508.893 4.65 2.679 6.424 1.785 1.774 3.94 2.662 6.464 2.662 2.524 0 4.679-.888 6.464-2.662 1.786-1.775 2.679-3.916 2.679-6.424zM71.714 65.98l7.215-27.116c.285-1.23.107-2.378-.536-3.443-.643-1.064-1.56-1.762-2.75-2.094-1.19-.33-2.333-.177-3.429.462-1.095.639-1.81 1.573-2.143 2.804l-7.214 27.116c-2.857.237-5.405 1.266-7.643 3.088-2.238 1.822-3.738 4.152-4.5 6.992-.952 3.644-.476 7.098 1.429 10.364 1.905 3.265 4.69 5.37 8.357 6.317 3.667.947 7.143.474 10.429-1.42 3.285-1.892 5.404-4.66 6.357-8.305.762-2.84.619-5.607-.429-8.305-1.047-2.697-2.762-4.85-5.143-6.46zm47.143-2.342c0-2.508-.893-4.65-2.678-6.424-1.786-1.775-3.94-2.662-6.465-2.662-2.524 0-4.678.887-6.464 2.662-1.786 1.774-2.679 3.916-2.679 6.424 0 2.508.893 4.65 2.679 6.424 1.786 1.775 3.94 2.662 6.464 2.662 2.524 0 4.679-.887 6.465-2.662 1.785-1.775 2.678-3.916 2.678-6.424zm-45.714-45.43c0-2.509-.893-4.65-2.679-6.425C68.68 10.01 66.524 9.122 64 9.122c-2.524 0-4.679.887-6.464 2.661-1.786 1.775-2.679 3.916-2.679 6.425 0 2.508.893 4.65 2.679 6.424 1.785 1.774 3.94 2.662 6.464 2.662 2.524 0 4.679-.888 6.464-2.662 1.786-1.775 2.679-3.916 2.679-6.424zm32 13.629c0-2.508-.893-4.65-2.679-6.424-1.785-1.775-3.94-2.662-6.464-2.662-2.524 0-4.679.887-6.464 2.662-1.786 1.774-2.679 3.916-2.679 6.424 0 2.508.893 4.65 2.679 6.424 1.785 1.774 3.94 2.662 6.464 2.662 2.524 0 4.679-.888 6.464-2.662 1.786-1.775 2.679-3.916 2.679-6.424zM128 63.638c0 12.351-3.357 23.78-10.071 34.286-.905 1.372-2.19 2.058-3.858 2.058H13.93c-1.667 0-2.953-.686-3.858-2.058C3.357 87.465 0 76.037 0 63.638c0-8.613 1.69-16.847 5.071-24.703C8.452 31.08 13 24.312 18.714 18.634c5.715-5.68 12.524-10.199 20.429-13.559C47.048 1.715 55.333.035 64 .035c8.667 0 16.952 1.68 24.857 5.04 7.905 3.36 14.714 7.88 20.429 13.559 5.714 5.678 10.262 12.446 13.643 20.301 3.38 7.856 5.071 16.09 5.071 24.703z" /></symbol>'
        });
        r.a.add(s);
        t["default"] = s
    },
    f87e: function(e, t, a) {
        "use strict";
        a("279e")
    }
}, [[0, "runtime", "chunk-elementUI", "chunk-libs"]]]);
