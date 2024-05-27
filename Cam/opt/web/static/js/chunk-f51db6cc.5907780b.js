(window["webpackJsonp"]=window["webpackJsonp"]||[]).push([["chunk-f51db6cc"],{6235:function(e,t,n){"use strict";n.r(t);var s=function(){var e=this,t=e.$createElement,n=e._self._c||t;return n("div",{staticClass:"app-container"},[n("el-row",{staticClass:"media-content"},[n("el-tabs",{attrs:{type:"border-card"},on:{"tab-click":e.handleClick},model:{value:e.activeName,callback:function(t){e.activeName=t},expression:"activeName"}},[n("el-tab-pane",{key:"first",attrs:{name:"first"}},[n("span",{attrs:{slot:"label"},slot:"label"},[n("i",{staticClass:"el-icon-user"}),e._v(" "+e._s(e.$t("user_management.user")))]),e.pages.first.istab?n("user"):e._e()],1)],1)],1)],1)},a=[],r=(n("b0c0"),function(){var e=this,t=e.$createElement,n=e._self._c||t;return n("div",{staticClass:"mt20"},[n("div",{staticClass:"box-card customer_boxhead"},[n("el-table",{directives:[{name:"loading",rawName:"v-loading",value:e.listLoading,expression:"listLoading"}],attrs:{data:e.user_management.users,"element-loading-text":"Loading",border:"",fit:"","highlight-current-row":""}},[n("el-table-column",{attrs:{align:"center",label:"ID",width:"95"},scopedSlots:e._u([{key:"default",fn:function(t){return[e._v(" "+e._s(t.$index)+" ")]}}])}),n("el-table-column",{attrs:{label:e.$t("user_management.name")},scopedSlots:e._u([{key:"default",fn:function(t){return[e._v(" "+e._s(t.row.name)+" ")]}}])}),n("el-table-column",{attrs:{label:e.$t("user_management.group")},scopedSlots:e._u([{key:"default",fn:function(t){return[n("span",[e._v(e._s(e.$t(e.groupNames(t.row.classify))))])]}}])}),n("el-table-column",{attrs:{"class-name":"status-col",label:e.$t("user_management.enabled"),align:"center"},scopedSlots:e._u([{key:"default",fn:function(t){return[n("el-tag",{attrs:{type:e._f("statusFilter")(t.row.enabled)}},[e._v(e._s(e.$t(e.enabledStatus(t.row.enabled))))])]}}])}),e.checkPermission(["admin"])?n("el-table-column",{attrs:{fixed:"right",label:e.$t("user_management.operations")},scopedSlots:e._u([{key:"default",fn:function(t){return[n("el-button",{attrs:{link:"",type:"primary",size:"small"},on:{click:function(n){return n.preventDefault(),e.editRow(t.$index)}}},[e._v(" "+e._s(e.$t("user_management.edit"))+" ")]),n("el-button",{attrs:{link:"",type:"warning",size:"small"},on:{click:function(n){return n.preventDefault(),e.removeRow(t.$index)}}},[e._v(" "+e._s(e.$t("user_management.remove"))+" ")])]}}],null,!1,4055921810)}):e._e()],1),e.checkPermission(["admin"])?n("el-button",{staticClass:"mt-4",staticStyle:{width:"100%"},on:{click:e.onAddUser}},[e._v(" "+e._s(e.$t("user_management.add"))+" ")]):e._e()],1),n("el-dialog",{attrs:{visible:e.dialogAddVisible,title:e.$t("user_management.input_user")},on:{"update:visible":function(t){e.dialogAddVisible=t}},scopedSlots:e._u([{key:"footer",fn:function(){return[n("span",{staticClass:"dialog-footer"},[n("el-button",{on:{click:e.onCancel}},[e._v(" "+e._s(e.$t("user_management.cancel"))+" ")]),n("el-button",{attrs:{type:"primary"},on:{click:e.onConfirm}},[e._v(" "+e._s(e.$t("user_management.confirm"))+" ")])],1)]},proxy:!0}])},[n("el-form",{attrs:{model:e.current_user}},[n("el-form-item",{attrs:{label:e.$t("user_management.name"),"label-width":e.formLabelWidth}},[n("el-input",{attrs:{autocomplete:"off",readonly:"modify_user"===e.operator_type},model:{value:e.current_user.name,callback:function(t){e.$set(e.current_user,"name",t)},expression:"current_user.name"}})],1),n("el-form-item",{attrs:{label:e.$t("user_management.password"),"label-width":e.formLabelWidth}},[n("el-input",{attrs:{type:"password","show-password":""},model:{value:e.current_user.password,callback:function(t){e.$set(e.current_user,"password",t)},expression:"current_user.password"}})],1),n("el-form-item",{attrs:{label:e.$t("user_management.confirm_password"),"label-width":e.formLabelWidth}},[n("el-input",{attrs:{type:"password","show-password":""},model:{value:e.confirm_password,callback:function(t){e.confirm_password=t},expression:"confirm_password"}})],1),n("el-form-item",{attrs:{label:e.$t("user_management.group"),"label-width":e.formLabelWidth}},[n("el-select",{attrs:{placeholder:"Please select a zone"},model:{value:e.current_user.classify,callback:function(t){e.$set(e.current_user,"classify",t)},expression:"current_user.classify"}},e._l(e.group_options,(function(t){return n("el-option",{key:t.value,attrs:{label:e.$t(t.label),value:t.value}})})),1)],1),n("el-form-item",{attrs:{label:e.$t("user_management.enabled"),"label-width":e.formLabelWidth}},[n("el-switch",{model:{value:e.current_user.enabled,callback:function(t){e.$set(e.current_user,"enabled",t)},expression:"current_user.enabled"}})],1)],1)],1)],1)}),i=[],o=(n("a434"),n("e350")),u=n("8593"),l=n("61f7"),c={filters:{statusFilter:function(e){var t={true:"success",false:"danger"};return t[e]}},data:function(){return{current_user:{name:"",password:"",classify:0,enabled:!0},operator_type:null,confirm_password:"",group_options:[{label:"user_management.admin",value:2},{label:"user_management.operator",value:1},{label:"user_management.viewer",value:0}],dialogAddVisible:!1,formLabelWidth:"140px",user_management:{users:null},listLoading:!0}},created:function(){this.fetchData()},methods:{checkPermission:o["a"],fetchData:function(){var e=this;this.listLoading=!0,Object(u["a"])("user_management").then((function(t){e.user_management=t.data.settings,window.console.log(e.user_management),e.listLoading=!1}))},updateData:function(){Object(u["d"])({type:"user_management",settings:this.user_management}).then((function(e){window.console.log("updated!")}))},groupNames:function(e){for(var t=0;t<this.group_options.length;t++)if(this.group_options[t].value===e)return this.group_options[t].label;return""},enabledStatus:function(e){return e?"button.yes":"button.no"},removeRow:function(e){var t=this;this.current_user=this.user_management.users[e],"admin"!==this.current_user.name?Object(u["d"])({type:"remove_user",settings:this.current_user}).then((function(n){t.user_management.users.splice(e,1)})):this.$message({message:this.$t("user_management.built_in_user"),type:"warning"})},editRow:function(e){this.current_user=this.user_management.users[e],this.operator_type="modify_user",this.dialogAddVisible=!0},onAddUser:function(){this.current_user={name:"",password:"",classify:0,enabled:!0},this.operator_type="add_user",this.dialogAddVisible=!0},onCancel:function(){this.dialogAddVisible=!1},onConfirm:function(){var e=this;Object(l["c"])(this.current_user.name)?this.current_user.password.length<6||this.current_user.password!==this.confirm_password?this.$message({message:this.$t("user_management.invalid_password"),type:"warning"}):Object(u["d"])({type:this.operator_type,settings:this.current_user}).then((function(t){e.dialogAddVisible=!1,"add_user"===e.operator_type?e.user_management.users.push(e.current_user):"modify_user"===e.operator_type&&e.onRefresh()})):this.$message({message:this.$t("user_management.invalid_user"),type:"warning"})},onSubmit:function(){this.updateData()},onRefresh:function(){this.fetchData(),window.console.log("reload!")}}},d=c,m=n("2877"),f=Object(m["a"])(d,r,i,!1,null,null,null),_=f.exports,p={components:{user:_},data:function(){return{activeName:"first",pages:{first:{istab:!0,key:"first"},second:{istab:!1,key:"second"}}}},created:function(){},mounted:function(){},methods:{handleClick:function(e){for(var t in this.pages)e.name!==t?this.pages[t]["istab"]=!1:this.pages[t]["istab"]=!0}}},b=p,g=(n("7c93"),Object(m["a"])(b,s,a,!1,null,"5d3bbdbd",null));t["default"]=g.exports},"7c93":function(e,t,n){"use strict";n("a4d8")},8593:function(e,t,n){"use strict";n.d(t,"a",(function(){return a})),n.d(t,"d",(function(){return r})),n.d(t,"b",(function(){return i})),n.d(t,"c",(function(){return o}));var s=n("b775");function a(e){return Object(s["a"])({url:"/v1/system/settings",method:"get",params:{query:e}})}function r(e){return Object(s["a"])({url:"/v1/system/update",method:"post",data:e})}function i(){return Object(s["a"])({url:"/v1/system/restart",method:"post"})}function o(){return Object(s["a"])({url:"/v1/system/restore",method:"post"})}},a4d8:function(e,t,n){},e350:function(e,t,n){"use strict";n.d(t,"a",(function(){return a}));n("caad"),n("d3b7"),n("2532");var s=n("4360");function a(e){if(e&&e instanceof Array&&e.length>0){var t=s["a"].getters&&s["a"].getters.roles,n=e,a=t.some((function(e){return n.includes(e)}));return a}return console.error("need roles! Like v-permission=\"['admin','editor']\""),!1}}}]);