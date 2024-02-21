export default {
  route: {
    dashboard: 'Live ',
    network_settings: 'Impostazioni di Rete',
    ip_settings: 'Rete',
    gb28181_settings: 'Parametri GB28181',
    media_settings: 'Parametri Media',
    video_capture: 'Cattura Video',
    datetime_title: 'Orario & Titolo',
    video_codec: 'Codifica Video',
    audio_capture: 'Cattura Video',
    audio_codec: 'Codifica Audio',
    fill_light: 'Riempi luce',
    privacy_mask: 'Maschera Privacy',
    warning_settings: 'Impostazioni Allarmi',
    human_recognition: 'Riconoscimento umano',
    motion_detection: 'Rilevamento movimento',
    occlusion_detection: 'Mask Detection',
    system_settings: 'Impostazioni di sistema',
    user_management: 'Gestione Utenti',
    system_time: 'Data e Ora',
    maintenance: 'Manutenzione',
    documentation: 'Documentazione',
    guide: 'Aiuto',
    permission: 'Autenticazione',
    pagePermission: 'Page Autenticazione',
    rolePermission: 'Role Autenticazione',
    directivePermission: 'Directive Autenticazione',
    page401: '401',
    page404: '404',
    errorLog: 'Registro Errori',
    theme: 'Tema',
    clipboardDemo: 'Globalizzazione',
    i18n: 'I18n',
    externalLink: 'Profilo',
    profile: 'Profilo',
    language: 'Lingua',
    storage: 'Impostazioni Archiviazione',
    ptzcontrol: 'Controllo PTZ',
    audio_settings: 'Impostazioni Audio',
    network_protocol: 'Protocollo di Rete',
    platform_settings: 'Impostazioni Piattaforma',
	intelligence_algorithms: 'Intelligence Algorithms',
    ai_settings: 'Impostazioni AI',
    video_coding: 'Codifica Video',
    image_parameters: 'Parametri Immagine',
    capture_settings: 'Parametri di Cattura',
    osd_settings: 'Impostazioni OSD',
    devices_maintenance: 'Dispositivo in Manutenzione'
  },
  dashboard: {
    name: 'Nome',
    id: 'ID',
    version: 'Versione',
    monitor: 'Monitor',
    intercom: 'Intercom',
    snapshot: 'Istantanea',
    videotape: 'Video'
  },
  navbar: {
    dashboard: 'Video dal Vivo',
    github: 'Github',
    logOut: 'Log Out',
    profile: 'Profilo',
    theme: 'Tema',
    size: 'Dimensione'
  },
  login: {
    title: 'Modulo di accesso',
    logIn: 'accedi',
    username: 'nome',
    password: 'Password',
    any: 'any',
    thirdparty: 'Accesso di terzi',
    thirdpartyTips: 'La simulazione non può essere eseguita in locale! ! !',
    confirm_logout: 'Confirm logout',
    re_login_msg: 'You have been logged out, you can cancel to stay on this page, or log in again',
    restart_msg: '<div>Your modification requires an IPC restart to take effect. The system will exit in <span id=\'timed\' style=\'color: #06B7AE\'></span> seconds and log in again to function properly.</div>'
  },
  permission: {
    addRole: 'Nuovo Ruolo',
    editPermission: 'Modifica',
    roles: 'I tuoi ruoli',
    switchRoles: 'Cambia Ruoli',
    tips: '',
    delete: 'Delete',
    confirm: 'Confirm',
    cancel: 'Cancel'
  },
  errorLog: {
    tips: '',
    description: '',
    documentation: 'Document Introduction'
  },
  theme: {
    change: 'Cambia Tema',
    documentation: 'Informazioni sul Tema',
    tips: ''
  },
  tagsView: {
    refresh: 'Aggiorna',
    close: 'Chiudi',
    closeOthers: 'Chiudi Rimanenti',
    closeAll: 'Chiudi Tutto'
  },
  settings: {
    title: 'Impostazioni stile pagina',
    theme: 'Colore del Tema',
    tagsView: 'Open Tags-View',
    fixedHeader: 'Fixed Header',
    sidebarLogo: 'Sidebar Logo'
  },
  button: {
    save: 'Salva',
    view: 'Mostra',
    edit: 'Modifica',
    all: 'All',
    all_list: 'All List',
    empty: 'Svuota',
    delete: 'Cancella',
    refresh: 'Aggiorna',
    search: 'Cerca',
    restart: 'Riavvia',
    setting: 'Impostazioni',
    updatesoft: 'Aggiornamento Software',
    default: 'Default',
    restore_factory: 'Ripristina Dati di Fabbrica',
    reset: 'Reset',
    cancel: 'Cancel',
    re_login: 'Re-Login',
    yes: 'Yes',
    no: 'No'
  },
  ip_settings: {
    mac_address: 'Indirizzo MAC',
    dhcp: 'DHCP',
    self_adaption: 'Adattamento IP',
    ipv4_addr: 'Indirizzo IPv4',
    ipv4_mask: 'Maschera di sottorete IPv4',
    ipv4_gateway: 'Gateway IPv4',
    ipv6_addr: 'Indirizzo IPv6',
    ipv6_gateway: 'Gateway IPv6',
    dns1: 'DNS1',
    dns2: 'DNS2',
    ip_settings: 'Impostazioni IP',
    auto_ip: 'IP Automatico',
    static_ip: 'IP Statico',
    static_ddns: 'DDNS Statico',
    auto_ddns: 'DDNS Automatico'
  },
  wifi: {
    name: 'name',
    work_mode: 'work mode',
    wlan: 'WLAN',
    ap: 'AP hotspot',
    status: 'connection status',
    ssid: 'SSID',
    password: 'password',
    connected: 'connected',
    not_connected: 'ununited',
  },
  net_4g: {
    status: 'connection status',
    enabled: 'open'
  },
  gb28181_settings: {
    enabled: 'Abilita 28181',
    local_sip_port: 'Porta locale SIP(1025-65525',
    sip_server_id: 'ID Server SIP',
    sip_server_domain: 'Dominio Server SIP',
    sip_server_ip: 'IP Server SIP',
    sip_server_port: 'Porta Server SIP(1-65535)',
    sip_username: 'Nome utente SIP',
    sip_user_auth_id: 'ID Auth utente SIP',
    password: 'Password',
    password_confirm: 'Conferma Password',
    term_of_validity: 'Termine di Valitdità(second)',
    heartbeat_cycle: 'Ciclo del battito cardiaco(5-3600)',
    max_heartbeat_timeout: 'Tempo massimo di battito cardiaco(3-255)',
    stream_index: '28181 indice della corrente',
    video_channel_code_id: 'ID codice canale Video',
    audio_channel_code_id: 'ID codice canale Audio',
    alarm_id: 'ID allarme'
  },
  video_capture: {
    brightness: 'Luminosità',
    contrast: 'Contrasto',
    saturation: 'Saturazione',
    backlight: 'Controluce',
    sharpness: 'Sharpness',
    video_standard: 'Standard Video',
    horizontal_flip: 'Specchia Immagine Orizzontale',
    vertical_flip: 'Specchia Immagine Verticale',
    prevent_overexposure: 'Previeni Sovraesposizione',
    scene_mode: 'Modalità Scena',
    AE_sensitivity: 'Sensibilità AE',
    AE_tolerance: 'Tolleranza AE',
    exposure_mode: 'Mode Esposizione',
    white_balance: 'White Balance',
    wide_dynamic: 'Wide Dynamic',
    wide_dynamic_enhancement: 'Miglioramento Wide Dynamic',
    noise_reduction_3d: 'Riduzione Rumore 3D',
    noise_reduction_3d_enhancement: 'Miglioramento Riduzione Rumore 3D',
    // 字符
    capture_setting: 'Impostazioni di Cattura',
    advance_setting: 'Impostazioni Avanzate',
    auto: 'Automatico',
    indoor: 'Interno',
    outdoor: 'Esterni',
    disable: 'Disabilita',
    manual: 'Manuale'
  },
  datetime_title: {
    datetime: 'Date & Time',
    x: 'Percentuale Coordinate d\'Area (%)',
    y: 'Percentuale Coordinate d\'Area(%)',
    time_format: 'Formato Ora',
    week: 'Stile Settimana',
    date_format: 'Stile Settimana',
    style: 'Stile Settimana',
    title: 'Titolo',
    channel: 'Abilitato',
    enabled: 'Nome Canale',
    name: 'Nome Canale',
    hour24: '24 Ore',
    hour12: '24 Ore',
    english: 'Inglese',
    chinese: 'Risoluzione'
  },
  video_codec: {
    main_stream: 'Stream Principale',
    encode_format: 'Formato Codifica Video',
    resolve: 'Risoluzione',
    bitrate: 'Bitrate',
    framerate: 'Frame Rate',
    bps: 'Bitrate',
    keyframe_interval: 'Risoluzione',
    sub_stream: 'Sub Stream',
    // 字符
    h264: 'H.264',
    h265: 'H.265',
    quality: 'Qualità',
    quality_tip: '（1-9, Maggiore corrisponde ad una qualità migliore）',
    //  new add---------
    first_main_stream: 'Primo Main Stream',
    first_sub_stream: 'Primo Sub Stream',
    second_main_stream: 'Secondo Main Stream',
    second_sub_stream: 'Secondo Sub Stream',
    stream_id: 'Stream ID',
    profile: 'Sample Rate '
  },
  audio_capture: {
    sample_rate: 'Sample Rate',
    sample_bit: 'Risoluzione Bit',
    collect_volume: 'Volume Registrazione',
    play_volume: 'Volume Riproduzione',
    input_method: 'Tipo di Input'
  },
  audio_codec: {
    encode_enabled: 'Abilitato',
    encode_format: 'Formato',
    decode_enabled: 'Decodifica'
  },
  fill_light: {
    ir_cut: 'Attivazione taglio IR',
    light_mode: 'Modalità luce',
    image_mode: 'Modalità immagine',
    photosensitive_type: 'Tipo fotosensibile',
    start_sensitivity: 'Sensibilità iniziale della sorgente luminosa',
    automatic_sensitivity: 'Sensibilità di regolazione automatica della sorgente luminosa',
    light_type: 'Tipo luce',
    dimming_mode: 'Regolazione modalità',
    luminance: 'Luminanza(100%)',
    // 字符
    forward: 'Inoltra',
    reverse: 'Inverso',
    lampred: 'Infrared Normal Mode',
    lampwhite: 'White Light/Warm Light Normal Dimming Mode',
    lampdouble: 'Dual Light Source (Infrared, White/Warm) Normal Dimming Mode',
    smart_lampred: 'Modalità di regolazione intelligente all’infrarosso',
    smart_lampwhite: 'White Light/Warm Light Intelligent Dimming Mode',
    smart_lampdouble: 'Modalità di regolazione intelligente luce bianca/luce calda',
    auto: 'Auto',
    day: 'Giorno',
    night: 'Notte',
    timing: 'Timing',
    hard: 'Hard',
    soft: 'Soft',
    morning: 'Mezzogiorno',
    middle: 'Mezzogiorno',
    evening: 'Sera',
    fast: 'Veloce',
    slow: 'Luce Rossa',
    red_light: 'Luce Rossa',
    warm_light: 'Manuale',
    manual: 'Manuale',
    night_start_time: 'Night Start Time',
    night_end_time: 'Night End Time'
  },
  privacy_mask: {
    privacy_zone: 'Privacy Zone',
    enabled: 'Abilitato',
    x: 'X Coordinata',
    y: 'Y Coordinata',
    width: 'Larghezza',
    height: 'Altezza',
    color: 'Colore'
  },
  user_management: {
    name: 'Nome',
    password: 'Password',
    group: 'Gruppo',
    enabled: 'Abilitato',
    operations: 'Operazione',
    edit: 'Modifica',
    remove: 'Cancella',
    add: 'Aggiungi',
    admin: 'Administrator',
    operator: 'Operator',
    viewer: 'Viewer',
    cancel: 'Annulla',
    confirm: 'Conferma',
    input_user: 'Aggiungi informazioni Utente',
    confirm_password: 'Reinserire la password',
    built_in_user: 'Built-in user cannot be deleted',
    invalid_user: 'User name cannot be less than three characters',
    invalid_password: 'The password can be less than 6 digits or confirm password are different.',
    user: 'Utente'
  },
  system_time: {
    mode: 'Modalità operativa',
    ntp_server: 'Server NTP',
    port: 'NTP porto',
    sync_time: 'Sincronizzazione NTP',
    timezone: 'Fuso orario',
    time: 'ora',
    same_host: 'Conforme al dispositivo',
    ntp: 'NTP',
    manual: 'Manuale'
  },
  maintenance: {
    enabled: 'Abilitato',
    day: 'Maintenance Day',
    restart_time: 'Orario di Riavvio',
    sunday: 'Venerdi',
    monday: 'Venerdi',
    tuesday: 'Venerdi',
    wednesday: 'Venerdi',
    thursday: 'Venerdi',
    friday: 'Venerdi',
    saturday: 'Sabato',
    everyday: 'Tutti i Giorni',
    am: 'a.m.',
    pm: 'p.m.',
    y: 'Anno',
    m: 'Anno',
    d: 'Giorno',
    restarting: 'Restarting',
    restore: 'Restoring factory settings will lose all modified information and reset the IP address.'
  },
  human_recognition: {
    enabled: 'Abilitato',
    sensitivity: 'Sensibilità',
    alarm_mode: 'Modalità di Allarme',
    flash_light: 'Flash Light',
    play_tone: 'Avviso Sonoro',
    area: 'Area',
    defence: 'Defence Time',
    withdrawal: 'Withdrawal Time',
    days: 'Giorni',
    repeat: 'Ripetizione',
    voice: 'Voice',
    m_f: 'M-F',
    m_s: 'M-S',
    sat_sun: 'Sabato e Domenica',
    sun: 'Domenica',
    everyday: 'Tutti i Giorni',
    default: 'Default',
    max_deployment_area: 'The system only supports up to 4 deployment areas',
    tips: 'Press the left button and drag to draw the area to be monitored, up to 4 areas'
  },
  occlusion_detection: {
    enabled: 'Abilita',
    area: 'Area',
    sensitivity: 'Sensibilità',
    alarm_mode: 'Modalità Allarme',
    flash_light: 'Flash Light',
    play_tone: 'Avviso Sonoro',
    tips: 'Clicca e Trascina con il tasto Sinistro per disegnare l\'area da osservare'
  },
  motion_detection: {
    enabled: 'Abilita',
    sensitivity: 'Sensibilità',
    alarm_mode: 'Modalità Allarme',
    flash_light: 'Flash Light',
    play_tone: 'Avviso Sonoro'
  },
  ptzcontrol: {
    name: 'PTZ',
    amplify: 'Amplifica',
    focus: 'Fuoco',
    aperture: 'Apertura',
    ptz_speed: 'Velocità PTZ',
    doubling_speed: 'Velocità Zoom',
    focus_mode: 'Modalità Fuoco',
    focus_sensitivity: 'Sensibilità Fuoco',
    focus_area: 'Area Fuoco',
    preset_position: 'Preset Position',
    code_stream: 'Code Stream',
    base_set: 'Impostazioni Base',
    more_set: 'Impostazioni Avanzate',
    invoke_preset: 'Invoke Preset',
    add_preset: 'Add Preset',
    remove_preset: 'Remove Preset'
  },
  storage: {
    storage: 'Archivio',
    media_format: 'Formato Media',
    image_save_path: 'Percorso Archiviazioni Immagini',
    video_save_path: 'Percorso Archiviazioni Video',
    storage_device: 'Disposiivo di Archiviazione TF Card',
    save_setting: 'Salva Impostazioni',
    storage_Plan: 'Piano di Archiviazioni',
    storage_management: 'Gestione Archiviazione',
    video_files: 'File Video',
    record_audio: 'Registra Audio',
    tf_card: 'Archiviazione TF Card',
    volume: 'Volume',
    status: 'Stato',
    format: 'Formatta',
    unformat: 'Elimina Formattazione',
    usb_disk: 'Disco USB',
    total: 'Totale',
    used: 'Usato',
    recording_status: 'Stato Registrazioni',
    working_mode: 'Modalità Lavoro',
    video_stream: 'Video Stream',
    video_file_size: 'Dimensione File Video',
    video_strategy: 'Strategia Archiviazione Video',
    auto_override: 'Sovrascrivi il Video',
    full_stop: 'Ferma la Registrazione quando l\'archivio è pieno',
    choose_time: 'Scelta Orario',
    manual_recording: 'Registrazione Manuale',
    timer_recording: 'Registrazione Temporizzata',
    recording_type: 'Tipo di Registrazione',
    media_forma: 'Formato di Registrazione',
    file_type: 'Tipo di File',
    video_audio: 'Video & Audio',
    onliy_video: 'Solo Video',
    ftp: 'Upload su server FTP',
    email: 'Invia via Email',
    file_name: 'Nome File',
    action: 'Azione',
    max_record_time: 'Durata Massima Registrazioni'
  },
  lg: {
    msg: 'Cambio lingua effettuato correttamente'
  },
  tf_card: {
    ok: 'TF card Ok',
    no_card: 'No TF card',
    no_format: 'TF card not format',
    abnormal: 'TF card abnormal',
    file_type: 'Format type',
    is_delete: 'La scheda TF è formattata?',
    formatting: 'Formatting TF Card!',
	cancel: "Annulla",
    confirm: "Conferma"
  },
  network_settings: {
    name: 'Impostazioni di Rete',
    wired_network: 'Impostazioni Rete Cablata',
    wifi_settings: 'impostazioni WIFI',
    s4g_settings: 'Impostazioni 4G',
    ip_address_filtering: 'Impostazioni Filtro indirizzi IP'

  },
  network_protocol: {
    enabled: 'Abilitato',
    name: 'Protocolli di Rete',
    http: 'HTTP',
    rtsp: 'RTSP',
    rtp: 'RTP',
    ftp: 'FTP',
    smtp: 'SMTP',
    qos: 'Qos',
    x8021: '802.1x',
    upnp: 'uPnP',
    pppoe: 'PPPoE',
    ntf: 'NTP',
    ddns: 'DDNS',
    http_port: 'Porta Http',
    listening_port: 'Porta d\'Ascolto',
    upgrade_port: 'Porta di Aggiornamento',
    multicast_ttl: 'TTL Multicast',
    identity_authentication: 'Autenticazione identità',
    rtmp:'RTMP',
    user:'Nome utente',
    password:'Password',
    server_id:'服务器编号',
    server_url:'Indirizzo Server',
    server_path:'Directory memoria Server',
    path:'tracciato',
    rtmp_enabled:'Abilita RTMP',
    rstp_enabled:'Autenticazione identità',
    rtp_enabled:'Abilita RTP',
    stream:'Flusso Video',
    port:'Numero porta',
    video_id:'ID Video',
    audio_id:'ID Audio',
    talk_id:'ID Intercom',
    mtu:'Mtu',
    udp:"UDP",
    udp_enabled:'Abilita Multicast UDP',
    udp_ip:'IP Multicast',
    udp_port:'Numero porta',
    udp_url:'Indirizzo di riproduzione Multicast UDP',
    ftp_normal:'Parametro predefinito'

  },
  time: {
    name: 'Orario',
    day_time: 'Giorno/Orario',
    start_time: 'Orario Inizio',
    end_time: 'Orario Fine',
    to: 'Fino a',
    monday: 'Lunedi',
    tuesday: 'Martedi',
    wednesday: 'Mercoledi',
    thursday: 'Giovedi',
    friday: 'Venerdi',
    saturday: 'Sabato',
    weekday: 'Giorni feriali',
    mouse_click: 'Usa il mouse per scegliere l\'intervallo di tempo',
    times_output: 'L\'intervallo di tempo non supera i 5'
  },
  platform_settings: {
    gb28181: 'GB28181',
    onvif: 'ONVIF'
  },
  devices_maintenance: {
    about_devices: 'Informazioni sul Dispositivo',
    devices_name: 'Nome Dispositivo',
    devices_time: 'Orario del Dispositivo',
    software_version: 'Versione Software',
    firmware_version: 'Versione Firmware',
    system_maintenance: 'Manutenzione del Dispositivo',
    use_ntp: 'Abilita NTP',
    use_computer: 'Sincronizza con il Computer',
	use_multicast:'Abilita Multicast UDP',
	video_streaming:'Flusso Video',
	IP_multicast:'组播IP',
	multicast_port:'组播端口',
	Play_address:'UDP组播播放地址',
	equipment:'ID 设置',
	server:'服务器URL'

  },
  osd: {
    basic_settings: 'Impostazioni Base',
    system_settings: 'Impostazione Sistema',
    custom_settings: 'Impostazioni Personalizzate',
    font_size: 'Dimensione Carattere',
    pellucidity: 'Transparenza',
    use_title: 'Abilita Titolo',
    color: 'Colore',
    use: 'Abilita ',
    add_info: 'Infromazioni Sovraimpressione',
    custom_centent: 'Informazioni Personalizzate',
    add_infos: {
      rr: 'Risoluzione',
      rpfr: 'Risoluzione & Frame Rate',
      rpfrcr: 'Risoluzione & Frame Rate & Code Rate'
    }
  },
  area: {
    red: 'Rosso',
    green: 'Verde',
    yellow: 'Giallo',
    blue: 'Blu'
  }
}
