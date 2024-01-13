y = {
    route: {
        dashboard: "Live Video",
        network_settings: "Network Settings",
        ip_settings: "IP Settings",
        gb28181_settings: "GB28181 Settings",
        rtmp_settings: "RTMP Settings",
        media_settings: "Video Settings", //<=Media Settings
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
        occlusion_detection: "Mask Detection", // Mask detection => Tamper detection
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
        any: "Any", // any => Any
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
        qr_code: "QR Code", // Qr code => QR Code
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
        name: "Name", // <=name
        work_mode: "Work mode", //<=work mode
        wlan: "WLAN",
        ap: "AP hotspot",
        status: "Connection Status", // <= connection status
        ssid: "SSID",
        password: "Password", // <=password
        connected: "Connected", // <=connected
        not_connected: "Ununited" // <=ununited
    },
    net_4g: {
        status: "Connection Status", // connection status
        enabled: "Open" // open
    },
    gb28181_settings: {
        enabled: "Enable 28181",
        local_sip_port: "Local SIP Port(1025-65525)", // <=Local SIP Port(1025-65525
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
        wide_dynamic: "WDR", //<=Wide Dynamic
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
        x: "X Coordinate Percentage(%)", // <=Area Coordinate Percentage(%)
        y: "Y Coordinate Percentage(%)", // <= Area Coordinate Percentage(%)
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
        quality_tip: "(1-9 The higher the number, the better the quality)",
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
        collect_volume: "Capture Volume", // <=Collect Volume
        play_volume: "Play Volume",
        input_method: "Input Device" //<=Input Method
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
        input_user: "User Information", //<=Input User Information
        confirm_password: "Confirm password", // <=Enter the password again
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
        amplify: "Zoom", //<=Amplify
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
        save_setting: "Recording Setting", //<=Save Setting
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
        no_format: "TF card not formated", // <=TF card not format
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
        server_id: "Server ID", // <=服务器编号
        server_url: "Server Address", // <= Server address
        server_path: "Server Storage Directory", //<=Server storage directory
        path: "Path",
        rtmp_enabled: "Enable RTMP", // <=开启RTMP功能
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
        about_devices: "About Device", //<=About Devices
        devices_name: "Devices Name",
        devices_time: "Device Time",
        software_version: "Device Version",
        firmware_version: "Firmware Version",
        system_maintenance: "System Maintenance",
        use_ntp: "Enabled NTP",
        use_computer: "Manual Settings",
        use_multicast: "Open Multicast", //<=open multicast
        video_streaming: "Video Streaming", //<=video streaming
        IP_multicast: "Multicast IP", // <=multicast IP
        multicast_port: "Multicast Port", //<=multicast port
        Play_address: "UDP Multicast Play Address",
        equipment: "ID Equipment", //<=ID equipment
        server: "Server URL" // <=server URL
    },
    osd: {
        basic_settings: "Basic Settings",
        system_settings: "System Settings",
        custom_settings: "Custom Settings",
        font_size: "Font Size", //<=Front Size
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
}, 
w = { // Italian??
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
}, 
P = { // Korean
    route: {
        dashboard: "실시간 영상",
        network_settings: "네트워크 설정", //<=네트웤설정
        ip_settings: "IP 설정",
        gb28181_settings: "GB28181 설정",
        media_settings: "영상 설정",
        video_capture: "영상 캡쳐 설정",
        datetime_title: "시간 및 타이틀",
        video_codec: "코덱 설정",
        audio_capture: "오디오 캡쳐 설정",
        audio_codec: "오디오 설정",
        fill_light: "보조등 설정",
        privacy_mask: "사생활 보호", //<=마스크설정
        warning_settings: "알람 설정",
        human_recognition: "인체 감지", //<=휴먼식별
        electric_vehicle_recognition: "전동차 식별", // <=전동차식별
        fall_detection: "넘어짐 감지", //<=넘어짐 검사
        flame_recognition: "화염연기 감지", //<=화염연기 식별
        smoke_detection: "흡연 감지", //<=흡연검사
        motion_detection: "모션 디텍션",
        occlusion_detection: "임의 조작 감지", //은폐탐지
        notifies: "이벤트 목록", //알림장
        system_settings: "시스템 설정",
        user_management: "사용자 관리",
        system_time: "시스템 타임", //<=시시템타임
        maintenance: "시스템 유지관리",
        documentation: "파일",
        guide: "가이드",
        permission: "권한 테스트",
        pagePermission: "페이지 권한",
        rolePermission: "사용자 권한", //<=유저권한
        directivePermission: "관리자 권환", //<=Instruction권한
        page401: "401",
        page404: "404",
        errorLog: "오류 로그",
        theme: "스킨 체인지",
        clipboardDemo: "세계화",
        i18n: "엔터네셔설",
        externalLink: "외부 링크",
        profile: "사용자 센터",
        language: "언어",
        storage: "저장 설정",
        ptzcontrol: "PTZ 제어", //<=PTZ 제어
        audio_settings: "오디오 설정",
        network_protocol: "네트워크 프로토콜", //<=네트웍프로토콜
        platform_settings: "플래폼 설정",
        intelligence_algorithms: "지능형 알고리즘", //<=지능형 알고리즘
        ai_settings: "AI 기능",
        video_coding: "비디오 인코딩", //<=비디오레크딩
        image_parameters: "이미지 파라미터",
        capture_settings: "캡쳐 설정",
        osd_settings: "OSD 설정",
        devices_maintenance: "디바이스 유지관리"
    },
    dashboard: {
        name: "이름", //<=명칭
        id: "디바이스 표기",
        version: "버전",
        monitor: "모니터링",
        intercom: "인터콤",
        snapshot: "스냅샵",
        videotape: "녹화"
    },
    navbar: {
        dashboard: "실시간 영상",
        logOut: "로그아웃", //<=Log Out
        profile: "사용자 정보", //<=사용자중심
        theme: "스킨 바꾸기",
        size: "크기"
    },
    login: {
        title: "시스템 로그인",
        logIn: "로그인",
        username: "계정",
        password: "비밀번호",
        language: "언어", // added
        remeberPwd: "비밀번호 기억하기", // added
        any: "익명", //any
        thirdparty: "파트너 로그인",
        thirdpartyTips: "로컬에서는 시뮬레이션할수없습니다. 자신의업무와 결합하여 시뮬레이션 하십시오! ! !",
        confirm_logout: "로그아웃 확인", //<=Confirm logout
        re_login_msg: "이미 로그아웃 하였습니다. 취소하거나 다시 로그인 할 수 있습니다.", //<=You have been logged out, you can cancel to stay on this page, or log in again
        restart_msg: "<div>디바이스 재시작을 해야 수정사항이 적용됩니다. 정상작동을 위해 <span id='timed' style='color: #06B7AE'></span> 초 이내에 시스템 종료되고 다시 로그인합니다.</div>" //<=<div>Your modification requires an IPC restart to take effect. The system will exit in <span id='timed' style='color: #06B7AE'></span> seconds and log in again to function properly.</div>
    },
    permission: {
        addRole: "사용자 추가",
        editPermission: "편집 권한",
        roles: "권한",
        switchRoles: "권한 교체",
        tips: "",
        delete: "삭제",
        confirm: "확인",
        cancel: "취소"
    },
    errorLog: {
        tips: "",
        description: "설명", //<=
        documentation: "파일 소개"
    },
    theme: {
        change: "스킨 바꾸기",
        documentation: "스킨 파일",
        tips: ""
    },
    tagsView: {
        refresh: "새로고침", //<=취소
        close: "닫기",
        closeOthers: "다른 항목 닫기", //<=기타닫기
        closeAll: "모두 닫기"
    },
    settings: {
        title: "시템구성 설정",
        theme: "테마 색상",//<=테마컬러
        tagsView: "태그뷰 열기", //Open Tags-View
        fixedHeader: "Header 고정",
        sidebarLogo: "사이드바 LOGO"
    },
    button: {
        save: "저장",
        view: "보기",
        edit: "편집",
        all: "전부",
        all_list: "전부 선택",
        empty: "비우기",
        delete: "삭제",
        refresh: "취소",
        search: "찾기", //<=서치
        restart: "리부팅",
        setting: "설정",
        updatesoft: "업그레드",
        default: "기본값", //<=디폴트
        restore_factory: "초기화 설정",
        reset: "초기화",
        cancel: "취소", //<=Cancel
        re_login: "다시 로그인", //<=Re-Login
        yes: "예", //<=Yes
        qr_code: "QR 코드 생성", //<=2차원 코드를 생성하다
        no: "아니오" //<= No
    },
    ip_settings: {
        mac_address: "MAC 주소", //<=MAC 주소
        dhcp: "DHCP",
        self_adaption: "IP 자체 적응", //<=IP 적응
        ipv4_addr: "IPv4 주소", //<=IPv4 주소
        ipv4_mask: "IPv4 서브넷마스크", //<=IPv4 서브넷 마스크
        ipv4_gateway: "IPv4 게이트웨이",//<=IPv4 게이트 웨이
        ipv6_addr: "IPv6 주소", //<=IPv6 주소
        ipv6_gateway: "IPv6 게이트웨이", //<=IPv6 게이트 웨이
        dns1: "DNS1",
        dns2: "DNS2",
        ip_settings: "IP 설정",
        auto_ip: "자동 IP",
        static_ip: "정적 IP",
        static_ddns: "정적 DDNS",
        auto_ddns: "자동 DDNS"
    },
    wifi: {
        name: "이름", //<=명칭
        work_mode: "동작 모드", //<=작업 모드
        wlan: "WLAN",
        ap: "AP", // <=AP핫스팟
        status: "연결 상태", //<=연결 상태
        ssid: "SSID",
        password: "암호",
        connected: "연결 됨", //<=연결되었음
        not_connected: "연결 안 됨", //<=연결되지
        signal_strength:"신호 강도", // add
        very_strong:"매우 강함", // add
        strong:"강함", // add
        middle:"중간", // add
        weak:"약함" // add
    },
    net_4g: {
        status: "연결 상태",
        enabled: "사용" //<=작동을
    },
    gb28181_settings: {
        enabled: "사용", //<=로컬SIP포트
        local_sip_port: "로컬 SI P포트(1025-65525)", //<=로컬SIP포트(1025-65525
        sip_server_id: "SIP 서버 ID",
        sip_server_domain: "SIP 서버 도메인", //<=SIP서버 ADD
        sip_server_ip: "SIP 서버 IP", //<=SIP서버 ADD
        sip_server_port: "SIP 서버 포트(1-65535)", //<=SIP서버 포트(1-65535)
        sip_username: "SIP 사용자 이름",
        sip_user_auth_id: "SIP 사용자 인증 ID", //<=비밀번호 확인
        password: "비밀번호", //<=비밀번호 확인
        password_confirm: "비밀번호 확인", //<=비밀번호 확인
        term_of_validity: "레지스트 유효기간(초)",
        heartbeat_cycle: "하드비트 주기(5-3600)", //<=심장박동 주기(5-3600)
        max_heartbeat_timeout: "최대 하트비트 제한시간(3-255)", //<=최대 하트비트 제한 시간입니다(3-255)
        stream_index: "스트림 인덱스", //<=오디오채넬ID
        video_channel_code_id: "비디오 채넬 ID", //<=오디오채넬ID
        audio_channel_code_id: "오디오 채넬 ID",
        alarm_id: "알람 ID"
    },
    rtmp_settings: {
        enabled: "RTMP 사용", //<=rtmp 사용
        stream_type: "스트림 형식", //<=코드 스트림 형식
        remote_host: "서버 주소", //<=서버 주소
        remote_port: "포트 번호(1-65535)", //<=포트 번호(1-65535)
        app_name: "앱 이름", //<=응용이름
        stream_id: "스트림 ID", //<=흐르ID
        illustrate: "설명",
        illustrate_context_1: "파라미터 설명, 예를 들어 rtmp url은 다음과 같다면，인자는 문자열'/'로 나눈다.",//<=이상 파라 메 터의 함의는 무엇 인가？예를 들어 rtmp url은 다음과 같다，인자는 문자열/로 나눌 수 있다。
        illustrate_context_2: " rtmp://abc.defgh.com/live/4287d428c?wsSecret=5ba27f7727a398a8",
        illustrate_context_3: "1) 서버 주소:   abc.defgh.com",
        illustrate_context_4: "2) 포트 번호:   \t 기본값은 1935 이며 abc.defgh.com 뒤에 ':숫자'는 포트번호를 나타낸다.",
        illustrate_context_5: "3) 앱이름:  \t live",
        illustrate_context_6: "4) 스트림ID:       4287d428c?wsSecret=5ba27f7727a398a"
    },
    video_capture: {
        brightness: "밝기",
        contrast: "대비", //<=이와는 대조적으로
        saturation: "채도", //<=포화
        backlight: "백라이트", //<=백 라이트
        sharpness: "선명도",
        video_standard: "비디오 표준", //<=비디오 표준
        horizontal_flip: "수평 뒤집기", //<=수평 뒤집
        vertical_flip: "수직 뒤집기", //<=수직 뒤집
        prevent_overexposure: "과다 노출 방지", //<=과다 노출을 방지
        scene_mode: "현장 모드", //<=현장 모드
        AE_sensitivity: "AE 민감도", //<=AE 민감도
        AE_tolerance: "AE 오프셋", //<=AE 공차
        exposure_mode: "노출 모드", //<=노출 모드
        white_balance: "화이트 밸런스", //<=화이트 밸런스
        wide_dynamic: "WDR", //<=넓은 동적
        wide_dynamic_enhancement: "WDR 수준", //<=넓은 동적 향상
        noise_reduction_3d: "3D DNR", //<=3D 노이즈 감소
        noise_reduction_3d_enhancement: "3D DNR 수준", //<=3D 노이즈 감소 향상
        capture_setting: "기본 설정", //<=캡쳐설정
        advance_setting: "고급 설정", //<=3D 노이즈 감소 향상
        auto: "자동",
        indoor: "실내",
        outdoor: "실외",
        disable: "사용 안 함", //<=잠금
        manual: "수동"
    },
    datetime_title: {
        datetime: "날짜 & 시간",
        x: "X 좌표(%)", //<=지역 좌표 백분율(%)
        y: "Y 좌표(%)", //<=지역 좌표 백분율(%)
        time_format: "시간 형식",
        week: "주 표시", //<=쇼 주
        date_format: "날짜 형식",
        style: "주 스타일", 
        title: "제목",
        channel: "채널",
        enabled: "활성화",
        name: "채널 이름",
        hour24: "24 시간",
        hour12: "12 시간",
        english: "영어",
        chinese: "중국어" //<=중국
    },
    video_codec: {
        main_stream: "메인 스트림", //<=메인 스 트림
        encode_format: "인코딩 형식", //<=인 코딩 형식
        resolve: "해상도",
        bitrate: "비트레이트 타입", //<=비트 전송 률
        framerate: "최대 프레임 수", //<=프레임 속도
        bps: "비트 레이트", //<=비트 전송 률
        keyframe_interval: "키 프레임 간격", //<=키 프레임 간격
        sub_stream: "서브 스트림", //<=하위 스 트림
        h264: "H.264",
        h265: "H.265",
        quality: "품질",
        quality_tip: "(1-9 숫자가 높을수록 품질이 좋아집니다)",
        first_main_stream: "첫번째 메인 스트림", //<=첫 번 째 메인 스 트림
        first_sub_stream: "첫번째 서브 스트림", //<=첫 번 째 하위 스 트림
        second_main_stream: "두번째 메인 스트림", //<=Second Main Stream
        second_sub_stream: "두번째 서브 스트림", //<=Second Sub Stream
        stream_id: "스트림 ID", //<=스 트림 ID
        profile: "프로파일 " //<=프로 파일 
    },
    audio_capture: {
        sample_rate: "샘플링 주파수", //<=샘플 속도
        sample_bit: "샘플링 비트", //<=표본 좀
        collect_volume: "입력 볼륨", //<=수집 볼륨
        play_volume: "재생 볼륨", // <=연극 볼륨
        input_method: "입력 장치" //<=입력 방법
    },
    audio_codec: {
        encode_enabled: "활성화",
        encode_format: "형식",
        decode_enabled: "디코딩" //<=해독
    },
    fill_light: {
        ir_cut: "IR 컷 트리거",
        light_mode: "조명 모드",
        image_mode: "이미지 모드",
        photosensitive_type: "감광 타입", //<=감광 성 유형
        start_sensitivity: "보조등 민감도", //<=감광 성 유형
        automatic_sensitivity: "광원 자동 조정 감도", //<=광원의 자동 조정 감도
        light_type: "조명 타입", //<=빛 유형
        dimming_mode: "조명 밝기 조절", //<=간접조명 모드
        luminance: "휘도", //<=앞으로
        forward: "정방향", //<=역방향의
        reverse: "역방향",//<=역
        lampred: "적외선 모드", //<=적외선 지적인 간접조명 모드
        lampwhite: "백색 광원 디밍 모드", //<=화이트 라이트/따뜻한 라이트 지능형 디밍 모드
        lampdouble: "듀얼 광원 (적외선, 흰색/온열) 디밍 모드", //<=듀얼 광원 (적외선, 흰색/온열) 지능형 디밍 모드
        smart_lampred: "적외선 지능형 디밍 모드", //<=Infrared Intelligent Dimming Mode
        smart_lampwhite: "화이트 라이트 지능형 디밍 모드", //<=White Light/Warm Light Intelligent Dimming Mode
        smart_lampdouble: "듀얼 광원 (적외선, 흰색/온열) 지능형 디밍 모드", //<=Dual Light Source (Infrared, White/Warm) Intelligent Dimming Mode
        auto: "자동",
        day: "낮", //<=하루
        night: "밤",
        timing: "타이밍",
        hard: "딱딱한 빛", //<=열심히
        soft: "부드러운 빛", //<=부 드러 운
        morning: "아침",
        middle: "중간", 
        evening: "저녁",
        fast: "빠르게", //<=고급
        slow: "천천히",
        red_light: " 적색 빛", //<=적신호
        warm_light: "따뜻한 빛", //<=따뜻 한 빛
        manual: "수동",
        night_start_time: "밤 시작 시간",
        night_end_time: "밤 끝 시간"//<=저녁이 끝나는 시간
    },
    privacy_mask: {
        privacy_zone: "프라이버시 영역",
        enabled: "적용",
        x: "X 좌표",
        y: "Y 좌표",
        width: "넓이",
        height: "높이",
        color: "색상" //<=컬러
    },
    user_management: {
        name: "사용자 이름", //<=사용자명
        password: "비밀번호",
        group: "사용자 그룹",
        enabled: "사용",//<=적용
        operations: "편집",
        edit: "수정",
        remove: "삭제",
        add: "추가",
        admin: "관리자",
        operator: "사용자",
        viewer: "뷰어",
        cancel: "취소",
        confirm: "확인",
        input_user: "사용자 입력", //뷰어
        confirm_password: "비밀번호 확인", //<=취소
        built_in_user: "내장된 사용자는 지울 수 없습니다.", //<=Built-in user cannot be deleted
        invalid_user: "사용자 이름은 세글자 이상입니다.", //<=User name cannot be less than three characters
        invalid_password: "비밀번호는 6자 이상이며 비밀번호가 일치하는지 확인하십시오.",//<=The password can be less than 6 digits or confirm password are different.
        user: "사용자" //<=확인
    },
    system_time: {
        mode: "워크 모드",
        ntp_server: "NTP 서버",
        port: "NTP 포트",
        sync_time: "NTP 동기화 주기",
        timezone: "타임존",
        time: "시간",
        same_host: "PC와 일치",
        ntp: "NTP",
        manual: "수동" //<=사용자
    },
    maintenance: {
        enabled: "사용", //<=적용
        day: "점검 일자",
        restart_time: "작동 시간",
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
        restarting: "다시 시작", //<=Restarting
        restore: "공장 초기화로 인해 모든 데이터와 IP는 초기화됩니다." //<=Restoring factory settings will lose all modified information and reset the IP address.
    },
    human_recognition: {
        enabled: "사용", //<=활성화
        sensitivity: "민감도",
        alarm_mode: "알람 모드",
        flash_light: "조명", //플래쉬 빛
        play_tone: "경고음 재생", //연극 어조
        area: "영역", //<=지역
        defence: "시작", //국방 시간
        withdrawal: "끝", //철수 시간
        days: "일",
        repeat: "반복",
        voice: "음성", //<=목소리
        m_f: "월-금", //<=M-F
        m_s: "월-일", //<=M-S
        sat_sun: "토일", //토요일과 일요일
        sun: "일요일",
        everyday: "매일",
        default: "기본",
        max_deployment_area: "최대 4개 영역을 지원합니다.", //The system only supports up to 4 deployment areas
        tips: "마우스 왼쪽을 드래그해서 감지할 영역(최대 4개)을 설정합니다." //Press the left button and drag to draw the area to be monitored, up to 4 areas
    },
    occlusion_detection: {
        enabled: "사용", //<=활성화
        area: "영역", //<=지역
        sensitivity: "민감도",
        alarm_mode: "알람 모드",
        flash_light: "조명", //<=플래쉬 빛
        play_tone: "경고음 재생", //<=연극 어조
        tips: "마우스 왼쪽을 드래그해서 감지할 영역(최대 4개)을 설정합니다." //<=왼쪽 버튼을 누르고 드래그하여 모니터링할 영역, 최대 4 영역까지 그립니다
    },
    motion_detection: {
        enabled: "사용", //<=활성화
        sensitivity: "민감도",
        alarm_mode: "알람 모드",
        flash_light: "조명", //<=플래쉬 빛
        Video_stream: "비디오 스트림",
        recording_recording: "이벤트 이전 녹화", //<=녹화 시간을 미리 남기다
        Recording_duration: "녹화 시간",
        signal_transfer: "IO 출력", //<=io 알람 출력
        Number_snaps: "스냅샷 수",
        play_tone: "경고음 재생" //<=보이스 알람
    },
    notify: {
        type: "타입",
        datetime: "시간",
        anthropomorphic: "인체 탐지",
        motion: "이동 탐지",
        occlusion: "임의 조작 탐지", //은폐 탐지
        none: "해당 없슴" //<=가 유효하지 않습니다
    },
    ptzcontrol: {
        name: "PTZ",
        amplify: "줌", //<=확대
        focus: "포커스",
        aperture: "조리개",
        ptz_speed: "PTZ 속도", //PTZ 스피드
        doubling_speed: "2배속", //줌 스피드
        focus_mode: "포커스 모드",
        focus_sensitivity: "포커스 민감도", //<=프커스 미감도
        focus_area: "포커스 영역", //<=포커스 구역
        preset_position: "프리셋 포지션", //포지션
        code_stream: "스트림",
        base_set: "기본 설정",
        more_set: "더보기"
    },
    storage: {
        storage: "저장",
        media_format: "파일 형식", //녹화방식
        image_save_path: "이미지 캡쳐 위치", //<=이미지캡쳐위치
        video_save_path: "영상 파일 저장 위치", //<=영상파일저장위치
        storage_device: "TF 카드 저장 장치", //<=TF카드저장
        save_setting: "녹화 설정", //<=저장설정
        storage_Plan: "녹화 스케쥴", //<=저장계획
        storage_management: "PC 저장 설정", //<=PC저장설정
        video_files: "영상 파일", //TF카드저장
        record_audio: "음성 저장", //보이스저장
        tf_card: "TF 카드 관리",
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
        full_stop: "녹화 완료 후 중지", //<=녹음 완료 후 중지
        choose_time: "시간 선택",
        manual_recording: "수동 녹화",
        timer_recording: "고정 시간 녹화",
        recording_type: "녹화 방식",
        media_forma: "파일 형식", //<=파일방식
        file_type: "파일 형식", //<=파일유형
        video_audio: "영상+음성",
        onliy_video: "영상",
        ftp: "FTP", //<=파일명
        email: "이메일", //<=파일명
        file_name: "파일명",
        action: "액션", //액션
        max_record_time: "최대 녹화 시간" //<=최대녹화시간
    },
    lg: {
        msg: "언어를 바꾸었습니다." //<=스위치 언어 성공
    },
    tf_card: {
        ok: "tf 카드 정상",
        no_card: "tf 카드가 인식되지 않았습니다",
        no_format: "tf 카드가 포맷되지 않았습니다",
        abnormal: "tf 카드 이상 (파티션 없음, 읽기 전용 등)",
        file_type: "파일 시스템", //<=파일 형식을 포맷합니다
        is_delete: "TF 카드는 포맷된 건가요?",
        formatting: "tf 카드를 포맷하는 중입니다!",
        cancel: "취소",
        confirm: "확인"
    },
    network_settings: {
        name: "네트워크 설정", //<=네트웍설정
        wired_network: "유선 네트워크 설정", //<=유선네트웍설정
        wifi_settings: "WIFI 설정",
        s4g_settings: "4G 설정",
        ip_address_filtering: "IP 필터링" //<=WIFI설정
    },
    network_protocol: {
        enabled: "사용", //<=적용
        name: "네트워크 프로토콜", //네트웍 프로토콜
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
        http_port: "Http 포트",
        listening_port: "리스닝 포트", //<=감시포트
        upgrade_port: "업그레드 포트",
        multicast_ttl: "멀티캐스트 TTL", //<=캐스트 TTL
        identity_authentication: "신분 인증",
        rtmp: "RTMP",
        user: "사용자 이름",
        password: "암호",
        server_id: "서버 ID", //<=服务器编号
        server_url: "서버 주소",
        server_path: "서버 디렉토리",
        path: "경로",
        rtmp_enabled: "RTMP 사용",
        rstp_enabled: "신분 인증",
        rtp_enabled: "RTP 사용", //<=Ativar RTP
        stream: "비디오 스트림", //<=비디오 스 트림
        port: "포트 번호",
        video_id: "비디오 ID",
        audio_id: "오디오 ID",
        talk_id: "인터콤 ID", //<=인 터 콤 ID
        mtu: "Mtu",
        udp: "UDP",
        udp_enabled: "UDP 멀티캐스트 사용", //<=UDP 멀티캐스트를 활성화합니다
        udp_ip: "멀티캐스트 IP", //<=멀티 캐 스 트 IP
        udp_port: "멀티캐스트 포트", //<=포트 번호
        udp_url: "UDP 멀티캐스트 재생 주소",
        ftp_normal: "기본값" //<=기본인자
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
        mouse_click: "클릭 방식으로 시간을 선택",
        times_output: "최대 5개까지 선택" //<=시간선택이최대5개
    },
    platform_settings: {
        gb28181: "GB28181",
        onvif: "ONVIF"
    },
    devices_maintenance: {
        about_devices: "디바이스 정보", //<= 장치에 대해
        devices_name: "디바이스명",
        devices_time: "작동시간",
        software_version: "디바이스 버전", //<=Device Version
        firmware_version: "펌웨어 버전", //<=Firmware Version
        system_maintenance: "시스템 유지보수",
        use_ntp: "NTP 적용",
        use_computer: "PC 동기화",
        use_multicast: "멀티캐스트 열기",
        video_streaming: "비디오 스트림 선택",
        IP_multicast: "멀티캐스트 IP",
        multicast_port: "멀티캐스트 포트",
        Play_address: "UDP멀티캐스트 재생 주소",
        equipment: "ID 설정", //<=ID 설치
        server: "서버 URL"
    },
    osd: {
        basic_settings: "기본 설정",
        system_settings: "시스템 설정",
        custom_settings: "사용자 설정", //<=카스톰마이징
        font_size: "글자 크기", //<=Front Size
        pellucidity: "투명도",
        use_title: "타이틀 사용", //<=타이틀적용
        color: "색상", //<=컬러
        use: "사용", //<=적용
        add_info: "메시지 추가",
        custom_centent: "사용자 내용", //<=Custom Content
        add_infos: {
            rr: "해상도",
            rpfr: "해상도+프레임",
            rpfrcr: "해상도+프레임+비트"
        }
    },
    area: {
        red: "적색", //<=붉은
        green: "녹색",
        yellow: "황색",//<=노란색
        blue: "청색" //<=파란색
    }
}, 
S = {
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
}