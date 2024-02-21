import Vue from 'vue'
import VueI18n from 'vue-i18n'
import Cookies from 'js-cookie'
import elementEnLocale from 'element-ui/lib/locale/lang/en' // element-ui lang
import elementItLocale from 'element-ui/lib/locale/lang/it'// element-ui lang
import elementKoLocale from 'element-ui/lib/locale/lang/ko'// element-ui lang
import elementPtLocale from 'element-ui/lib/locale/lang/pt'// element-ui lang
import elementRuLocale from 'element-ui/lib/locale/lang/ru-RU'// element-ui lang
import elementZhLocale from 'element-ui/lib/locale/lang/zh-CN'// element-ui lang
// import elementEsLocale from 'element-ui/lib/locale/lang/es'// element-ui lang
// import elementJaLocale from 'element-ui/lib/locale/lang/ja'// element-ui lang
import enLocale from './en'
import itLocale from './it'
import koLocale from './ko'
import ptLocale from './pt'
import ruLocale from './ru'
import zhLocale from './zh'
// import esLocale from './es'
// import jaLocale from './ja'

Vue.use(VueI18n)

const messages = {
  en: {
    ...enLocale,
    ...elementEnLocale
  },
  it: {
    ...itLocale,
    ...elementItLocale
  },
  ko: {
    ...koLocale,
    ...elementKoLocale
  },
  pt: {
    ...ptLocale,
    ...elementPtLocale
  },
  ru: {
    ...ruLocale,
    ...elementRuLocale
  },
  zh: {
    ...zhLocale,
    ...elementZhLocale
  }
  // es: {
  //   ...esLocale,
  //   ...elementEsLocale
  // },
  // ja: {
  //   ...jaLocale,
  //   ...elementJaLocale
  // }
}
export function getLanguage() {
  const chooseLanguage = Cookies.get('language')
  if (chooseLanguage) return chooseLanguage

  // if has not choose language
  const language = (navigator.language || navigator.browserLanguage).toLowerCase()
  const locales = Object.keys(messages)
  for (const locale of locales) {
    if (language.indexOf(locale) > -1) {
      return locale
    }
  }
  return 'en'
}
const i18n = new VueI18n({
  // set locale
  // options: en | zh | es
  locale: getLanguage(),
  // set locale messages
  messages
})

export default i18n
