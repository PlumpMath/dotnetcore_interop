/**
 @file    ste.h
 @author  (C) Copyright 1991-2014 by Symmetry Software
 @date    2005-2014
 @brief   Interface for using STE
*/

#ifndef _STE_H_
#define _STE_H_

#include <stddef.h>
#ifdef _MSC_VER
typedef __int8            int8_t;
typedef __int16           int16_t;
typedef __int32           int32_t;
typedef __int64           int64_t;
typedef unsigned __int8   uint8_t;
typedef unsigned __int16  uint16_t;
typedef unsigned __int32  uint32_t;
typedef unsigned __int64  uint64_t;
#else
#include <stdint.h>
#endif

#if defined STE_API
#undef STE_API
#undef STE_IMPORTEXPORT
#endif

#if defined(BUILDING_STE)
#	if defined _WIN32
#		define STE_IMPORTEXPORT __declspec( dllexport )
#	else
#		define STE_IMPORTEXPORT
#	endif
#else
#	if defined _WIN32
#		define STE_IMPORTEXPORT __declspec( dllimport )
#	else
#		define STE_IMPORTEXPORT
#	endif
#endif

#define STE_API(rtype) extern STE_IMPORTEXPORT rtype

#if (defined(__i386__) && !defined(__x86_64__)) || (defined(_M_IX86) && !defined(_WIN64))
#  if defined __GNUC__
#     define STE_CDECL __attribute__((cdecl))
#     define STE_STDCALL __attribute__((stdcall))
#     define STE_FASTCALL __attribute__((fastcall))
#  elif ( defined _MSC_VER )
#     define STE_CDECL    __cdecl
#     define STE_STDCALL  __stdcall
#     define STE_FASTCALL __fastcall
#  endif
#else
#  define STE_CDECL
#  define STE_STDCALL
#  define STE_FASTCALL
#endif

#define false   0
#define true    1
#define bool    int

typedef struct ste_handle ste_handle;
typedef struct ste_pool_handle ste_pool_handle;

#define	ste_GNIS_zipcode			1  /**< The zipcode filter code for  #ste_set_gnis_filter, #ste_get_gnis_match_count and #ste_get_gnis_match_list */
#define	ste_GNIS_city				2  /**< The city filter code for  #ste_set_gnis_filter, #ste_get_gnis_match_count and #ste_get_gnis_match_list */
#define	ste_GNIS_county				3  /**< The county filter code for  #ste_set_gnis_filter, #ste_get_gnis_match_count and #ste_get_gnis_match_list */
#define	ste_GNIS_state				4  /**< The state filter code for  #ste_set_gnis_filter, #ste_get_gnis_match_count and #ste_get_gnis_match_list */
#define	ste_GNIS_municipality		5  /**< The municipality filter code for #ste_set_gnis_filter, #ste_get_gnis_match_count and #ste_get_gnis_match_list */
#define	ste_GNIS_schoolDistrict		6  /**< The school district filter code for  #ste_set_gnis_filter, #ste_get_gnis_match_count and #ste_get_gnis_match_list */
#define	ste_GNIS_steLocationCode	7  /**< The STE Location Code filter code for  #ste_get_gnis_match_count and #ste_get_gnis_match_list */
#define	ste_GNIS_statezips			8  /**< The STE Location Code filter code for  #ste_get_gnis_match_count and #ste_get_gnis_match_list */

#define ste_WAGE_Regular					1 /**< Regular wages code - used for the \a wageType parameter in the #ste_set_wages function. */
#define ste_WAGE_Supplemental				2 /**< Supplemental wages code - used for the \a wageType parameter in the #ste_set_wages function */
#define ste_WAGE_PreviousPeriod				3 /**< Previous period regular wages code - used for the \a wageType parameter in the #ste_set_wages function */
#define ste_WAGE_PreviousPeriodSupplemental	4 /**< Previous period supplemental wages code - used for the \a wageType parameter in the #ste_set_wages function */
#define ste_WAGE_Combined					5 /**< Combined wages code (regular plus supplemental) */
#define ste_WAGE_CAN_LumpSum				6 /**< Lump-sum wages code (Canada only) - used for the \a wageType parameter in the #ste_set_wages function. */
#define ste_WAGE_CAN_Bonus					7 /**< Supplemental wages code (Canada only) - used for the \a wageType parameter in the #ste_set_wages function. */
#define ste_WAGE_FUTA_GrossWages			8 /**< FUTA wages - used for the \a wageType parameter in the #ste_set_wages function.  */
#define ste_WAGE_SUTA_GrossWages			9 /**< SUTA wages - used for the \a wageType parameter in the #ste_set_wages function.  */
#define ste_WAGE_SUTA_Previous_State		10 /**< SUTA wages for a previous employment state - used for the \a wageType parameter in the #ste_set_wages function. */
#define ste_WAGE_SUTA_Predecessor			11 /**< SUTA wages for a predecessor employer - used for the \a wageType parameter in the #ste_set_wages function. */
#define ste_WAGE_EI							12 /**< Employment Insurance wages (Canada only) - used for the \a wageType parameter in the #ste_set_wages function. */
#define ste_WAGE_EI_bonus					13 /**< Employment Insurance bonus wages (Canada only) - used for the \a wageType parameter in the #ste_set_wages function.*/
#define ste_WAGE_CPP						14 /**< CPP wages  (Canada only) - used for the \a wageType parameter in the #ste_set_wages function. */
#define ste_WAGE_CPP_bonus					15 /**< CPP bonus wages  (Canada only) - used for the \a wageType parameter in the #ste_set_wages function. */
#define ste_WAGE_QPP						16 /**< QPP wages (Canada only) - used for the \a wageType parameter in the #ste_set_wages function. */
#define ste_WAGE_QPP_bonus					17 /**< QPP bonus wages (Canada only) - used for the \a wageType parameter in the #ste_set_wages function. */
#define ste_WAGE_Pension_Income				18 /**< Pension income (Canada only) - used for the \a wageType parameter in the #ste_set_wages function. */
#define ste_WAGE_Quebec_Single_Payment		19 /**< Quebec Single Payment (Canada only) - used for the \a wageType parameter in the #ste_set_wages function. */
#define ste_WAGE_QPIP						20 /**< QPIP wages (Canada only) - used for the \a wageType parameter in the #ste_set_wages function. */
#define ste_WAGE_TIPS						21 /**< Tips - used for the \a wageType parameter in the #ste_set_wages function. */
#define ste_WAGE_RUIA_Compensation			22 /**< Railroad Unemployment Insurance Act (RUIA) Compensation - used for the \a wageType parameter in the #ste_set_wages function. */

#define ste_CALC_Method_Annualized			1 /**< Annualized calculation method code for the parameters in the #ste_set_calcmethod function */
#define ste_CALC_Method_Cumulative			2 /**< Cummulative calculation method code for the parameters in the #ste_set_calcmethod function */
#define ste_CALC_Method_Flat				3 /**< Flat rate calculation method code for the parameters in the #ste_set_calcmethod function */
#define ste_CALC_Method_CurrentAggregation	4 /**< Current aggregation calculation method code for the parameters in the #ste_set_calcmethod function */
#define ste_CALC_Method_PreviousAggregation	5 /**< Previous aggregation calculation method code for the parameters in the #ste_set_calcmethod function */
#define ste_CALC_Method_Daily				6 /**< Daily calculation method code for the parameters in the #ste_set_calcmethod function */
#define ste_CALC_Method_None				7 /**< Turn off calculations - method code for the parameters in the #ste_set_calcmethod function */
#define ste_CALC_Method_EMST_FULL			1 /**< Withhold full EMST amount on the paycheck - method code for the parameters in the #ste_set_emst or #ste_set_pa_emst functions. */
#define ste_CALC_Method_EMST_SPREAD			2 /**< Withhold 1/4 of EMST tax or 10% of wages if wages less than $130 - method code for the parameters in the #ste_set_emst or #ste_set_pa_emst functions. */


#define ste_FED_Single						1 /**< Employee is filing single - used for the \a filingStatus parameter in the #ste_set_federal function */
#define ste_FED_Married						2 /**< Employee is filing married - used for the \a filingStatus parameter in the #ste_set_federal function */
#define ste_FED_Married_Use_Single_Rate		3 /**< Employee is filing married but withholding at the higer single rate - used for the \a filingStatus parameter in the #ste_set_federal function */
#define ste_FED_NonresidentAlien			4 /**< Employee is filing nonresident alien - used for the \a filingStatus parameter in the #ste_set_federal function */

#define ste_EIC_None						0 /**< No EIC */
#define ste_EIC_Single						1 /**< Employee is filing single - used for the \a filingStatus parameter in the #ste_set_eic function */
#define ste_EIC_Married_One_Certificate		2 /**< Employee is filing married but only one spouse has filed a W-5 certificate - used for the \a filingStatus parameter in the #ste_set_eic function */
#define ste_EIC_Married_Two_Certificates	3 /**< Employee is filing married and both spouses have filed a W-5 certificate - used for the \a filingStatus parameter in the #ste_set_eic function */

#define ste_State_EIC_None					0

#define ste_STATE_NoRounding				0 /**< Do not round the state calculation. Used for the \a roundingOption parameter of #ste_set_state.  */
#define ste_STATE_YesRounding				1 /**< Round the state calculation. Used for the \a roundingOption parameter of #ste_set_state.  */
#define ste_STATE_DefaultRounding			2 /**< Use build in rounding rules for state calculation. Used for the \a roundingOption parameter of #ste_set_state.  */

#define ste_BENEFIT_125						1 /**< Section 125 benefit type. Used with #ste_set_benefits, #ste_get_benefits, and #ste_set_custom_benefit. */
#define ste_BENEFIT_401K					2 /**< 401k benefit type. Used with #ste_set_benefits, #ste_get_benefits, and #ste_set_custom_benefit. */
#define ste_BENEFIT_403B					3 /**< 403b benefit type. Used with #ste_set_benefits, #ste_get_benefits, and #ste_set_custom_benefit. */
#define ste_BENEFIT_457						4 /**< 457 benefit type. Used with #ste_set_benefits, #ste_get_benefits, and #ste_set_custom_benefit. */
#define ste_BENEFIT_Custom					5 /**< Custom benefit type. Used with #ste_set_benefits, #ste_get_benefits, and #ste_set_custom_benefit. */
#define ste_BENEFIT_Roth401K				6 /**< Roth 401k benefit type. Used with #ste_set_benefits, #ste_get_benefits, and #ste_set_custom_benefit. */
#define ste_BENEFIT_Roth403B				7 /**< Roth 403b benefit type. Used with #ste_set_benefits, #ste_get_benefits, and #ste_set_custom_benefit. */
#define ste_BENEFIT_FSA						8 /**< FSA benefit type. Used with #ste_set_benefits, #ste_get_benefits, and #ste_set_custom_benefit. */
#define ste_BENEFIT_HSA						9 /**< HSA benefit type. Used with #ste_set_benefits, #ste_get_benefits, and #ste_set_custom_benefit. */
#define ste_BENEFIT_SimpleIRA				10 /**< Simple IRA benefit type. Used with #ste_set_benefits, #ste_get_benefits, and #ste_set_custom_benefit. */
#define ste_BENEFIT_Roth457					11 /**< Roth 457 benefit type. Used with #ste_set_benefits, #ste_get_benefits, and #ste_set_custom_benefit. */
#define ste_BENEFIT_FSADependentCare		12 /**< FSA Dependent Care benefit type. Used with #ste_set_benefits, #ste_get_benefits, and #ste_set_custom_benefit. */

#define ste_CNTY_KY_OLF						1 /**< Kentucky Occupational License Fee. Used with #ste_set_ky_county and #ste_get_ky_county. */
#define ste_CNTY_KY_MENTAL_HEALTH			2 /**< Kentucky Mental Health tax. Used with #ste_set_ky_county and #ste_get_ky_county. */
#define ste_CNTY_KY_SENIOR_CITIZEN			3 /**< Kentucky Senior Citizen tax. Used with #ste_set_ky_county and #ste_get_ky_county. */
#define ste_CNTY_KY_TRANSIT					4 /**< Kentucky Transit Fee. Used with #ste_set_ky_county and #ste_get_ky_county. */
#define ste_CNTY_KY_OLTS					5 /**< Kentucky Occupational License Tax for Schools. Used with #ste_set_ky_county and #ste_get_ky_county. */

#define ste_OPTION_Auto_Adjust					1 /**< Auto adjust taxes which have a wage base. Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_Prorate						2 /**< Prorate taxes which are flat fee. Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_Ohio_City_Credit				3 /**< Apply Ohio city credit for taxes paid in nonresident location. Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_Custom_Wage_Type				4 /**< Custom Wage Type setting. Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_State_Calc_Override			5 /**< Override state calculation setting. Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_Logging_Level				6 /**< Set the STE logging level. Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_Logfile_Directory			7 /**< Set the STE log file directory location. Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_Logfile_Name					8 /**< Set the STE log file name. Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_Logfile_Info					9 /**< Set the STE log file directory location. Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_PA_Local_Courtesy				10 /**< Set the PA Local Courtesy flag. Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_SUTA_Total_Benefits			11 /**< All state benefits subtracted from SUTA. Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_Benefit_Annual_Wage_Limit	12 /**< Turns on or off the annual wage limit for benefits. Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_Imputed_Income_Type			13 /**< Turns on or off imputed income settings. Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_Oregon_WC_Override			14 /**< Allows the employer to pay the employee portion Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_Act32_Tax_Distribution		15 /**<Distributes taxes to the work locations */
#define ste_OPTION_Local_Courtesy_PA_EIT		16 /**< Set the Local Courtesy flag for PA EIT */
#define ste_OPTION_Local_Courtesy_OH_City		17 /**< Set the Local Courtesy flag for OH City */
#define ste_OPTION_Local_Courtesy_OH_School		18 /**< Set the Local Courtesy flag for OH School District */
#define ste_OPTION_Local_Courtesy_KY_OLTS		19 /**< Set the Local Courtesy flag for KY OLTS */
#define ste_OPTION_New_Mexico_WC_Override		20 /**< Allows the employer to pay the employee portion Used with #ste_set_option and #ste_set_option_flag. */
#define ste_OPTION_Non_Active_Taxes				21 /**< Non Active Tax flag.  Setting to true will cause ste_get_tax_list to include non active taxes.  Used with #ste_set_option and #ste_set_option_flag. */

/*
 * Imputed Income Types
 */
enum ste_imputed {
	ste_IMPUTED_INCOME_GTL = 1,					/**< Group Term Life Insurance Type */
	ste_IMPUTED_INCOME_CUSTOM = 2               /**< Custom imputed income. Used with #ste_set_imputed_income, #ste_get_imputed_income, and #ste_set_custom_imputed_income. */

};

/*
 * Web Service Types
 */
enum ste_ws {
	ste_WEBSERVICE_STE_WS = 1,				/**< Service for calculating taxes over the internet. Used with #ste_ws_set_web_service. */
	ste_WEBSERVICE_STE_LOC_CODE,			/**< Service for retrieving location codes from a street address - version 1. Used with #ste_ws_set_web_service. */
	ste_WEBSERVICE_GOOGLE_GEOCODE,			/**< Service for retrieving latitude/longitude from a street address using Google. Used with #ste_ws_set_web_service. */
	ste_WEBSERVICE_YAHOO_GEOCODE,			/**< Service for retrieving latitude/longitude from a street address using Yahoo. Used with #ste_ws_set_web_service. */
	ste_WEBSERVICE_BING_GEOCODE			/**< Service for retrieving latitude/longitude from a street address using Bing. Used with #ste_ws_set_web_service. */

};

#define FED_LOCATION_CODE "00-000-0000"		/**< Federal pseudo location code */

enum suta_surcharge {
	ste_SUTA_SURCHARGE_ALABAMA_EMPLOYMENT_SECURITY_ASSESSMENT = 1,
	ste_SUTA_SURCHARGE_ARIZONA_JOB_TRAINING_TAX = 3,
	ste_SUTA_SURCHARGE_CALIFORNIA_EMPLOYMENT_TRAINING_TAX = 4,
	ste_SUTA_SURCHARGE_COLORADO_SOLVENCY_SURCHARGE = 5,
	ste_SUTA_SURCHARGE_CONNECTICUT_FUND_SOLVENCY_TAX = 6,
	ste_SUTA_SURCHARGE_DELAWARE_SUPPLEMENTAL_ASSESSMENT = 7,
	ste_SUTA_SURCHARGE_DELAWARE_TRAINING_TAX = 8,
	ste_SUTA_SURCHARGE_DC_ADMINISTRATIVE_FUNDING_TAX = 9,
	ste_SUTA_SURCHARGE_DC_SOLVENCY_TAX = 10,
	ste_SUTA_SURCHARGE_GEORGIA_ADMINISTRATIVE_ASSESSMENT_TAX = 11,
	ste_SUTA_SURCHARGE_HAWAII_EMPLOYMENT_AND_TRAINING_TAX = 12,
	ste_SUTA_SURCHARGE_IDAHO_ADMINISTRATIVE_RESERVE = 13,
	ste_SUTA_SURCHARGE_INDIANA_SKILLS_TRAINING_ASSESSMENT = 15,
	ste_SUTA_SURCHARGE_KANSAS_SURCHARGE = 16,
	ste_SUTA_SURCHARGE_MASSACHUSETTS_STATE_HEALTH_INS_TAX = 17,
	ste_SUTA_SURCHARGE_MASSACHUSETTS_WORKFORCE_TRAINING_FUND = 18,
	ste_SUTA_SURCHARGE_MINNESOTA_WORKFORCE_ENHANCEMENT_FEE = 19,
	ste_SUTA_SURCHARGE_MISSISSIPPI_WORKFORCE_TRAINING_ENHANCEMENT = 20,
	ste_SUTA_SURCHARGE_MISSOURI_SURCHARGE = 21,
	ste_SUTA_SURCHARGE_MONTANA_ADMINISTRATIVE_FUND_TAX = 22,
	ste_SUTA_SURCHARGE_NEVADA_CAREER_ENHANCEMENT_PROGRAM = 23,
	ste_SUTA_SURCHARGE_NEW_HAMPSHIRE_ADMINISTRATIVE_CONTRIBUTION = 24,
	ste_SUTA_SURCHARGE_NEW_YORK_REEMPLOYMENT_FUND = 25,
	ste_SUTA_SURCHARGE_NEWYORK_SUBSIDIARY_TAX = 26,
	ste_SUTA_SURCHARGE_PENNSYLVANIA_ADDITIONAL_CONTRIBUTIONS_TAX = 28,
	ste_SUTA_SURCHARGE_PUERTO_RICO_SPECIAL_ASSESSMENT_TAX = 29,
	ste_SUTA_SURCHARGE_RHODE_ISLAND_JOB_DEVELOPMENT_FUND = 30,
	ste_SUTA_SURCHARGE_SOUTH_CAROLINA_SUI_ADMIN_CONTINGENCY_ASSESSMENT_TAX = 32,
	ste_SUTA_SURCHARGE_SOUTH_DAKOTA_SUTA_SURCHARGE_INVESTMENT_FEE_TAX = 33,
	ste_SUTA_SURCHARGE_TENNESEE_JOB_SKILLS_FEE = 34,
	ste_SUTA_SURCHARGE_TEXAS_REPLENISHMENT_TAX = 35,
	ste_SUTA_SURCHARGE_WASHINGTON_RATE_CLASS_1_THRU_19_EMPLOYMENT_ADMIN_FUND = 37,
	ste_SUTA_SURCHARGE_WASHINGTON_RATE_CLASS_20_EMPLOYMENT_ADMIN_FUND = 38,
	ste_SUTA_SURCHARGE_WESTVIRGINIA_SURTAX = 39,
	ste_SUTA_SURCHARGE_MAINE_CSSF = 41,
	ste_SUTA_SURCHARGE_MINNESOTA_ADDITIONAL_ASSESSMENT = 42,
	ste_SUTA_SURCHARGE_MINNESOTA_FEDERAL_LOAN_INTEREST_ASSESSMENT = 43,
	ste_SUTA_SURCHARGE_SOUTH_DAKOTA_TRUST_FUND_FEE = 44,
	ste_SUTA_SURCHARGE_MISSOURI_AUTOMATION_SURCHARGE = 45,
	ste_SUTA_SURCHARGE_IOWA_RESERVE_FUND = 46,
	ste_SUTA_SURCHARGE_IOWA_ADMINISTRATIVE_SURCHARGE = 47,
	ste_SUTA_SURCHARGE_NJ_WORKFORCE_SWF = 48,
	ste_SUTA_SURCHARGE_IDAHO_WORKFORCE_DEVELOPMENT = 49,
	ste_SUTA_SURCHARGE_NJ_HEALTH_CARE_SUBSIDY_FUND = 50,
	ste_SUTA_SURCHARGE_ARIZONA_SPECIAL_ASSESSMENT_TAX = 51,
	ste_SUTA_SURCHARGE_WASHINGTON_RATE_CLASS_1_40_EMPLOYMENT_ADMIN_FUND = 52,
	ste_SUTA_SURCHARGE_COLORADO_BOND_SURCHARGE = 53,
	ste_SUTA_SURCHARGE_KENTUCKY_EMPLOYMENT_TRAINING_SURCHARGE = 54,
	ste_SUTA_SURCHARGE_NEVADA_BOND_SURCHARGE = 55,
	ste_SUTA_SURCHARGE_MICHIGAN_OBLIGATION_ASSESSMENT = 56
};

/* Employer SDI taxes */

#define 	ste_EMPLOYER_SDI_NEW_JERSEY			1	/**< New Jersey SDI - Used as the \a sdiTaxID parameter in #ste_set_sdi_employer and #ste_get_sdi_employer. */
#define 	ste_EMPLOYER_SDI_PUERTO_RICO		2	/**< Puerto Rico SDI - Used as the \a sdiTaxID parameter in #ste_set_sdi_employer and #ste_get_sdi_employer. */

#define    	ste_TRANSIT_CANBY_TAX				1	/**< Canby transit tax - Used as the \a transitTaxID parameter in #ste_set_transit_tax and #ste_get_transit_tax. */
#define    	ste_TRANSIT_LANE_TAX				2	/**< Lane transit tax - Used as the \a transitTaxID parameter in #ste_set_transit_tax and #ste_get_transit_tax. */
#define    	ste_TRANSIT_TRIMET_EXCISE_TAX		3	/**< Trimet transit tax - Used as the \a transitTaxID parameter in #ste_set_transit_tax and #ste_get_transit_tax. */
#define    	ste_TRANSIT_SANDY_TAX				4	/**< Sandy transit tax - Used as the \a transitTaxID parameter in_set_transit_tax and #ste_get_transit_tax. */
#define    	ste_TRANSIT_WILSONVILLE_TAX			5	/**< Wilsonville transit tax - Used as the \a transitTaxID parameter in #ste_set_transit_tax and #ste_get_transit_tax. */
#define    	ste_TRANSIT_SOUTH_CLACKAMAS_TAX		6	/**< South Clackamas transit tax - Used as the \a transitTaxID parameter in #ste_set_transit_tax and #ste_get_transit_tax. */

#define    	ste_EMPLOYER_NJ_NY_WATERFRONT_TAX					1	/**< New Jersey/New York Waterfront tax - Employer tax used with #ste_set_percent_payroll and #ste_get_percent_payroll. */
#define    	ste_EMPLOYER_NEVADA_MBT_FINANCIAL_INSTITUTION_TAX	2	/**< Nevada MBT Financial Institution tax - Employer tax used with #ste_set_percent_payroll and #ste_get_percent_payroll. */
#define    	ste_EMPLOYER_NEVADA_MBT_GENERAL_BUSINESS_TAX		3	/**< Nevada MBT General Business tax - Employer tax used with #ste_set_percent_payroll and #ste_get_percent_payroll. */
#define    	ste_EMPLOYER_ST_LOUIS_PAYROLL_EXPENSE_TAX			4	/**< St. Louis Payroll Expense tax - Employer tax used with #ste_set_percent_payroll and #ste_get_percent_payroll. */
#define    	ste_EMPLOYER_SAN_FRANCISCO_PAYROLL_EXPENSE_TAX		5	/**< San Francisco Payroll Expense tax - Employer tax used with #ste_set_percent_payroll and #ste_get_percent_payroll. */
#define    	ste_EMPLOYER_PITTSBURGH_PAYROLL_TAX					6	/**< City of Pittsburgh Payroll tax - Employer tax used with #ste_set_percent_payroll and #ste_get_percent_payroll. */
#define    	ste_EMPLOYER_NEWARK_PAYROLL_TAX						7	/**< City of Newark Payroll tax - Employer tax used with #ste_set_percent_payroll and #ste_get_percent_payroll. */
#define    	ste_EMPLOYER_NEW_YORK_MCTMT							8	/**< City of New York Payroll tax - Employer tax used with #ste_set_percent_payroll and #ste_get_percent_payroll. */

enum JEDD {
	ste_JEDD_Bainbridge_Solon = 1,
	ste_JEDD_Bath_Akron_Fairlawn = 2,
	ste_JEDD_Beachwood_East = 3,
	ste_JEDD_Beachwood_West = 4,
	ste_JEDD_Brimfield_Kent = 5,
	ste_JEDD_Brimfield_Tallmadge = 6,
	ste_JEDD_Clayton = 7,
	ste_JEDD_Cleveland_Highland_Hills = 8,
	ste_JEDD_Cleveland_Warrensville_Heights = 9,
	ste_JEDD_Copley_Akron = 10,
	ste_JEDD_Coventry_Akron = 11,
	ste_JEDD_Dayton_Butler_Township = 12,
	ste_JEDD_Dayton_Miami_Township = 13,
	ste_JEDD_Elyria_Township_City_Of_Elyria = 14,
	ste_JEDD_Emerald_Park = 15,
	ste_JEDD_ETNA_JEDZ1_Etna_Corporate_Park = 16,
	ste_JEDD_ETNA_JEDZ2_South_Of_JEDZ1 = 17,
	ste_JEDD_Gateway = 18,
	ste_JEDD_Hamilton_Fairfield_Township = 19,
	ste_JEDD_Harrison_City_Harrison_Township = 20,
	ste_JEDD_IX_Center = 21,
	ste_JEDD_Kent_Franklin = 22,
	ste_JEDD_Lorain_Amherst_Township = 23,
	ste_JEDD_Macedonia_Northfield_Center_Township = 24,
	ste_JEDD_Middletown_Liberty_Township = 25,
	ste_JEDD_Milford_Union_Township = 26,
	ste_JEDD_Monclova_Maumee_Toledo = 27,
	ste_JEDD_Mount_Healthy_Springfield_Township_Hamilton_County = 28,
	ste_JEDD_North_Baltimore_Henry = 29,
	ste_JEDD_North_Pickaway_Cnty_Harrison_Twp_Vlgs_Of_Ashville_South_Bloomfield = 30,
	ste_JEDD_Olmstead = 31,
	ste_JEDD_Orange_Chagrin_Highlands = 32,
	ste_JEDD_Painesville_Concord = 33,
	ste_JEDD_Perry = 34,
	ste_JEDD_Perrysburg_Toledo = 35,
	ste_JEDD_Reminderville_Twinsburg_Township = 36,
	ste_JEDD_Reynoldsburg_Enterprise_Zone = 37,
	ste_JEDD_Rossford_Toledo = 38,
	ste_JEDD_Shaker_Square = 39,
	ste_JEDD_Springfield_Akron = 40,
	ste_JEDD_Springfield_Beckley_Municipal_Airpark = 41,
	ste_JEDD_West_Chester_1 = 42,
	ste_JEDD_Zanesville = 43,
	ste_JEDD_Youngstown_Gerard = 44,
	ste_JEDD_Medina_Montville = 45,
	ste_JEDD_Defiance = 46,
	ste_JEDD_Butler_Vandalia = 47,
	ste_JEDD_Coshocton = 48,
	/* deprecated - please use ste_JEDD_Pataskala */
	ste_JEDD_ETNA_Newark = 49,
	ste_JEDD_Hamilton_Indian_Springs_1 = 50,
	ste_JEDD_Hamilton_Indian_Springs_2 = 51,
	ste_JEDD_Prairie_Obetz = 52,
	ste_JEDD_Prairie_Township = 54,
	ste_JEDD_Blendon_Westerville_JEDZ = 55,
	ste_JEDD_Sycamore_Kenwood_Southwest = 56,
	ste_JEDD_Sycamore_Kenwood_Central = 57,
	ste_JEDD_Sycamore_Kenwood_East = 58,
	ste_JEDD_Butler_Stone_Springs = 59,
	ste_JEDD_Boston_Township_Peninsula = 60,
	ste_JEDD_Eaton = 61,
	ste_JEDD_Pataskala = 62,
	ste_JEDD_Columbia_Township = 63,
	ste_JEDD_Austin_Center = 64,
	ste_JEDD_Dayton_Mall_Miami_Township = 65,
	ste_JEDD_Sycamore_Kenwood_Northwest = 66,
	ste_JEDD_Clinton_Grandview_Heights = 67,
	ste_JEDD_Springfield_Township_JEDZ = 68,
	ste_JEDD_Rush_Township_Uhrichsville_JEDD = 69,
	ste_JEDD_Milford_II = 70,
	ste_JEDD_Milford_III = 71,
	ste_JEDD_Milford_IV = 72,
	ste_JEDD_Green_Township_Cheviot_Western_Ridge = 73,
	ste_JEDD_Green_Township_Cheviot_District_II = 74,
	ste_JEDD_Green_Township_Cheviot_Mercy_West_District_III = 75,
	ste_JEDD_Holland_Springfield_Township = 76,
	ste_JEDD_Scioto_Township = 77,
	ste_JEDD_Navarre = 78,
	ste_JEDD_Toledo_Troy = 79,
	ste_JEDD_Xenia = 80,
	ste_JEDD_Geneva_I = 81,
	ste_JEDD_Geneva_II = 82,
	ste_JEDD_Geneva_III = 83,
	ste_JEDD_Medina_Lafayette = 84,
	ste_JEDD_Toledo_Airport = 85,
	ste_JEDD_Richfield = 86,
	ste_JEDD_Lebanon = 87,
	ste_JEDD_Hubbard = 88,
	ste_JEDD_Maumee = 89,
	ste_JEDD_Zanesville_Springfield = 90,
	ste_JEDD_Zanesville_Newton = 91,
	ste_JEDD_Walton_Sagamore = 92,
	ste_JEDD_Berkshire = 93,
	ste_JEDD_Ashtabula= 94,
	ste_JEDD_Saybrook_Depot_Road = 95,
	ste_JEDD_Saybrook_Route_20 = 96,
	ste_JEDD_Monclova_Whitehouse = 97
};

enum DAF {
	ste_DAF_Warren_ITA= 1
};

#ifdef __cplusplus
extern "C" {
#endif
STE_API(ste_handle *) STE_STDCALL ste_init(const char *dirLocation);
STE_API(uint16_t) STE_STDCALL ste_quit(const ste_handle *ste);
STE_API(uint16_t) STE_STDCALL ste_handle_check(const ste_handle *ste);
STE_API(uint16_t) STE_STDCALL ste_version(const ste_handle *ste, char *version);
STE_API(uint16_t) STE_STDCALL ste_license_info(const ste_handle *ste, char *license);
STE_API(uint16_t) STE_STDCALL ste_ws_set_web_service(const ste_handle *ste, int32_t serviceNo, const char *serverURL, const char *proxyURL, const char *username, const char *password, const char *subAccount);

STE_API(ste_pool_handle *) STE_STDCALL ste_pool_init(const char *dirLocation, int32_t numInitialObjects, long recycleTime, long forceRecoverTime, int32_t maxObjects);
STE_API(uint16_t) STE_STDCALL ste_pool_quit(ste_pool_handle *ste);
STE_API(uint16_t) STE_STDCALL ste_pool_checkin(ste_pool_handle *stepool, ste_handle *ste);
STE_API(ste_handle *) STE_STDCALL ste_pool_checkout(ste_pool_handle *stepool);
STE_API(void) STE_STDCALL ste_pool_stats(ste_pool_handle *stepool, int32_t *checkedIn, int32_t *checkedOut);

STE_API(uint16_t) STE_STDCALL ste_get_errno(void);
STE_API(const char *) STE_STDCALL ste_get_strerror(uint16_t errnum);

STE_API(uint16_t) STE_STDCALL ste_open_gnis_db(const ste_handle *ste);
STE_API(uint16_t) STE_STDCALL ste_close_gnis_db(const ste_handle *ste);
STE_API(uint16_t) STE_STDCALL ste_get_gnis_match_count(const ste_handle *ste, int32_t opcode );
STE_API(uint16_t) STE_STDCALL ste_get_gnis_match_list(const ste_handle *ste, int32_t opcode, char *value, char *gnisPartCode );

STE_API(uint16_t) STE_STDCALL ste_set_gnis_filter(const ste_handle *ste, const char *zipCode, const char *stateName, const char *cityName, const char *countyName, const char *muniName, const char *schoolName );
STE_API(bool)	  STE_STDCALL ste_gnis_isvalid_locationcode(const ste_handle *ste, const char *ste_location_code, const char *muniCode, const char * schoolID );
STE_API(uint16_t) STE_STDCALL ste_ws_geocode(const ste_handle *ste, int32_t serviceNo, const char *addressIn, int32_t *httpStatus, int32_t *accuracy, char *latitude, char *longitude, char *addressOut, char *cityOut, char *stateOut, char *zipOut);
STE_API(uint16_t) STE_STDCALL ste_ws_get_location_code(const ste_handle *ste, const char *address, const char *latitudeIN, const char *longitudeIN, int32_t *httpStatus, char *latitudeOUT, char *longitudeOUT, char *addressNormalized, char *geocodeStatusCode, char *geocodeStatusCodeMessage, char *addressPrecision, char *addressPrecisionMessage, char *stateCode, char *countyCode, char *cityCode, char *municipalityCode, char *schoolCode, char *transitDistrictCode, char *faultcode, char *faultstring);
STE_API(uint16_t) STE_STDCALL ste_ws_get_location_code_v2(const ste_handle *ste, const char *streetAddress, const char *streetAddressSecondLine, const char *city, const char *state, const char *zip, const char *latitudeIN, const char *longitudeIN, int32_t *httpStatus, char *latitudeOUT, char *longitudeOUT, char *addressNormalized, char *stateCode, char *stateName, char *stateAbbreviation, char *countyCode, char *countyName, char *cityCode, char *cityName, char *zipCode, char *municipalityCode, char *municipalityName, char *schoolCode, char *schoolName, char *transitDistrictCode, char *transitDistrictName, char *PSDcode, char *PSDrate, bool *isGeocoded, char *faultcode, char *faultstring);
STE_API(uint16_t) STE_STDCALL ste_ws_get_lcs_result_codes(const ste_handle *ste, char *resultCode, char *resultMessage);

STE_API(uint16_t) STE_STDCALL ste_set_payroll_run_parameters(const ste_handle *ste, const char *payDate, uint16_t payPeriodsPerYear, uint16_t payPeriodNumber );
STE_API(uint16_t) STE_STDCALL ste_clear_calculations(const ste_handle *ste);
STE_API(uint16_t) STE_STDCALL ste_clear_settings(const ste_handle *ste);
STE_API(uint16_t) STE_STDCALL ste_set_wages(const ste_handle *ste, const char *locationCode, const uint16_t wageType, double hours, double ctd, double mtd, double qtd, double ytd );
STE_API(uint16_t) STE_STDCALL ste_get_wages(const ste_handle *ste, const char *locationCode, const uint16_t wageType, double *hours, double *ctd, double *mtd, double *qtd, double *ytd );
STE_API(uint16_t) STE_STDCALL ste_set_benefits(const ste_handle *ste, const char *locationCode, const char *benefitReferenceCode, const uint16_t benefitType, const uint16_t wageType, double ctd, double ytd, double limit, double percent, bool catchUp, double employerContribution, double employerContributionYTD );
STE_API(uint16_t) STE_STDCALL ste_set_benefits_extended(const ste_handle *ste, const char *locationCode, const char *benefitReferenceCode, const uint16_t benefitType, const uint16_t wageType, double ctd, double ytd, double limit, double percent, bool catchUp, double employerContribution, double employerContributionYTD, double employerContributionPercent, double catchUpOverride );
STE_API(uint16_t) STE_STDCALL ste_set_v2_benefits(const ste_handle *ste, const char *benefitReferenceCode, const uint16_t benefitType, bool allowSupplementalElection, bool prorateUsingStateWages, double ctd, double ytd, double limit, double percent, bool catchUp, double employerContribution, double employerContributionYTD );
STE_API(uint16_t) STE_STDCALL ste_set_v2_benefits_extended(const ste_handle *ste, const char *benefitReferenceCode, const uint16_t benefitType, bool allowSupplementalElection, bool prorateUsingStateWages, double ctd, double ytd, double limit, double percent, bool catchUp, double employerContribution, double employerContributionYTD, double employerContributionPercent, double catchUpOverride );
STE_API(uint16_t) STE_STDCALL ste_get_benefits(const ste_handle *ste, const char *locationCode, const char *benefitReferenceCode, uint16_t *benefitType, uint16_t *wageType, double *ctd, double *ytd, double *limit, double *benefitAmt, double *percent, bool *catchUp );
STE_API(uint16_t) STE_STDCALL ste_get_benefits_extended(const ste_handle *ste, const char *locationCode, const char *benefitReferenceCode, uint16_t *benefitType, uint16_t *wageType, double *ctd, double *ytd, double *limit, double *benefitAmt, double *percent, bool *catchUp, double *employerContribution, double *employerContributionYTD, double *benefitEmployerAmt );
STE_API(uint16_t) STE_STDCALL ste_get_benefit_info(const ste_handle *ste, const uint16_t benefitType, double *limitAmt, double *combinedLimit, double *catchUpAmt, double *annualWageLimit);
STE_API(uint16_t) STE_STDCALL ste_get_state_rounding_info(const ste_handle *ste, const char *locationCode, bool *mandatoryRounding, bool *suggestedRounding);
STE_API(uint16_t) STE_STDCALL ste_set_custom_benefit(const ste_handle *ste, const char *locationCode, const char *benefitReferenceCode, const uint16_t benefitType, bool pretaxFICA, bool pretaxMedicare, bool pretaxFederal, bool pretaxState, bool pretaxLocal, bool pretaxSDI, bool pretaxSUI);
STE_API(uint16_t) STE_STDCALL ste_set_custom_v2_benefit(const ste_handle *ste, const char *benefitReferenceCode, const uint16_t benefitType, bool pretaxFICA, bool pretaxMedicare, bool pretaxFederal, bool pretaxState, bool pretaxLocal, bool pretaxSDI, bool pretaxSUI);
STE_API(uint16_t) STE_STDCALL ste_set_custom_wage_type(const ste_handle *ste, const char *wageTypeReferenceCode, const char *uniqueTaxIDSearchString, uint16_t desiredWageType, uint16_t *wageType);
STE_API(uint16_t) STE_STDCALL ste_set_custom_benefit_type(const ste_handle *ste, const char *benefitReferenceCode, const char *uniqueTaxIDSearchString, uint16_t desiredBenefitType, uint16_t *benefitType);
STE_API(uint16_t) STE_STDCALL ste_get_custom_wage_type_list(const ste_handle *ste, const char *wageTypeReferenceCode, uint16_t wageType, char *uniqueTaxID );
STE_API(uint16_t) STE_STDCALL ste_get_custom_benefit_type_list(const ste_handle *ste, const char *benefitReferenceCode, uint16_t benefitType, char *uniqueTaxID );
STE_API(uint16_t) STE_STDCALL ste_set_imputed_income(const ste_handle *ste, const char *locationCode, const char *imputedIncomeReferenceCode, const uint16_t imputedIncomeType, const uint16_t wageType, double ctd, double ytd);
STE_API(uint16_t) STE_STDCALL ste_get_imputed_income(const ste_handle *ste, const char *locationCode, const char *imputedIncomeReferenceCode, uint16_t *imputedIncomeType, uint16_t *wageType, double *ctd, double *ytd );
STE_API(uint16_t) STE_STDCALL ste_set_custom_imputed_income(const ste_handle *ste, const char *locationCode, const char *imputedIncomeReferenceCode, const uint16_t imputedIncomeType, bool addFICA, bool addMedicare, bool addFederal, bool addState, bool addLocal, bool addSDI, bool addSUI);
STE_API(uint16_t) STE_STDCALL ste_set_custom_imputed_income_type(const ste_handle *ste, const char *imputedIncomeReferenceCode, const char *uniqueTaxIDSearchString, uint16_t desiredImputedIncomeType, uint16_t *imputedIncomeType);
STE_API(uint16_t) STE_STDCALL ste_get_custom_imputed_income_type_list(const ste_handle *ste, const char *imputedIncomeReferenceCode, uint16_t imputedIncomeType, char *uniqueTaxID );
STE_API(uint16_t) STE_STDCALL ste_set_calcmethod(const ste_handle *ste, const char *locationCode, uint16_t methodRegularWages, uint16_t methodSupplementalWages );
STE_API(uint16_t) STE_STDCALL ste_set_federal(const ste_handle *ste, bool exemptStatus, uint16_t filingStatus, uint16_t numAllowances, bool roundOption, double additionalWH, double ytd, double mostRecentWH );
STE_API(uint16_t) STE_STDCALL ste_set_pension(const ste_handle *ste, bool isPensionPayment );
STE_API(uint16_t) STE_STDCALL ste_set_massachusetts_pension(const ste_handle *ste, double ctd, double ytd );
STE_API(uint16_t) STE_STDCALL ste_set_fica(const ste_handle *ste, bool exemptStatusEE, bool exemptStatusER, double ytdEE, double ytdER, bool autoAdjust );
STE_API(uint16_t) STE_STDCALL ste_set_rrta(const ste_handle *ste, bool exemptStatusEE, bool exemptStatusER, double ytdTier1_EE, double ytdTier1_ER, double ytdTier2_EE, double ytdTier2_ER, bool autoAdjust );
STE_API(uint16_t) STE_STDCALL ste_set_medicare(const ste_handle *ste, bool exemptStatus, double ytd );
STE_API(uint16_t) STE_STDCALL ste_set_medicare_additional(const ste_handle *ste, double ytdWH );
STE_API(uint16_t) STE_STDCALL ste_set_eic(const ste_handle *ste, uint16_t filingStatus, double ytd, bool filingJointly );
STE_API(uint16_t) STE_STDCALL ste_set_state_eic(const ste_handle *ste, const char *locationCode, int32_t filingStatus, int32_t numberDependents );
STE_API(uint16_t) STE_STDCALL ste_set_state(const ste_handle *ste, const char *locationCode, bool residentStateFlag, bool exemptFlag, uint16_t roundingOption, double additionalWH, double ytd, double mostRecentWH, bool hasNonResCertificate );
STE_API(uint16_t) STE_STDCALL ste_set_state_misc(const ste_handle *ste, const char *locationCode, const char *parmName, const char *parmValue );
STE_API(uint16_t) STE_STDCALL ste_get_state_misc_list(const ste_handle *ste, const char *locationCode, char *stateAbbreviation, char *stateNo, char *parmName, char *description, char *regex, int32_t *regexType, char *regexDescription, char *certificateLineNo );
STE_API(uint16_t) STE_STDCALL ste_get_state_misc_list_ext(const ste_handle *ste, const char *locationCode, char *stateAbbreviation, char *stateNo, char *parmName, char *description, char *regex, int32_t *regexType, char *regexDescription, char *certificateLineNo, char *listValues, char *defaultValue, char *helpText );
STE_API(uint16_t) STE_STDCALL ste_get_supplemental_types(const ste_handle *ste, const char *locationCode, char *stateAbbreviation, char *stateNo, char *type, char *rate);
STE_API(uint16_t) STE_STDCALL ste_set_county(const ste_handle *ste, const char *locationCode, bool isExempt, bool isResident );
STE_API(uint16_t) STE_STDCALL ste_set_ky_county(const ste_handle *ste, const char *locationCode, uint16_t taxSelector, bool isExempt, bool isResident, double ytdWH );
STE_API(uint16_t) STE_STDCALL ste_set_city(const ste_handle *ste, const char *locationCode, bool isExempt, bool isResident, uint16_t exemptions, double periodWithheldAmt );
STE_API(uint16_t) STE_STDCALL ste_set_wv_occupational_tax(const ste_handle *ste, const char *locationCode, bool isExempt, bool isResident, uint16_t exemptions, double periodWithheldAmt );
STE_API(uint16_t) STE_STDCALL ste_set_jedd(const ste_handle *ste, const char *locationCode, int32_t jeddTaxID, bool isExempt, bool isResident, uint16_t exemptions, double periodWithheldAmt );
STE_API(uint16_t) STE_STDCALL ste_set_daf(const ste_handle *ste, const char *locationCode, int32_t dafTaxID, bool isExempt, bool isResident, uint16_t exemptions, double periodWithheldAmt );
STE_API(uint16_t) STE_STDCALL ste_set_schooldistrict(const ste_handle *ste, const char *locationCode, const char *municipalityCode, const char *schoolID, bool isExempt, bool isResident );
STE_API(uint16_t) STE_STDCALL ste_set_pa_eit(const ste_handle *ste, const char *locationCode, const char *municipalityCode, const char *schoolID, bool isExempt, bool isResident );
STE_API(uint16_t) STE_STDCALL ste_set_sdi(const ste_handle *ste, const char *locationCode, double withheldYTD, double periodWithheldAmt, double overrideRate, double overrideWageBase, bool isExempt );
STE_API(uint16_t) STE_STDCALL ste_set_washington_industrial_sdi(const ste_handle *ste, const char *locationCode, const char *sdiReference, double hours, double withheldYTD, double periodWithheldAmt, double overrideRate, double overrideWageBase, bool isExempt );
STE_API(uint16_t) STE_STDCALL ste_set_fli(const ste_handle *ste, const char *locationCode, double withheldYTD, double overrideRate, double overrideWageBase, bool isExempt );
STE_API(uint16_t) STE_STDCALL ste_set_health_care_subsidy_fund(const ste_handle *ste, const char *locationCode, double withheldYTD, double overrideRate, double overrideWageBase, bool isExempt );
STE_API(uint16_t) STE_STDCALL ste_set_sui(const ste_handle *ste, const char *locationCode, double withheldYTD, double overrideRate, double overrideWageBase, bool isExempt );
STE_API(uint16_t) STE_STDCALL ste_set_workerscomp(const ste_handle *ste, const char *locationCode, double withheldYTD, double periodWithheldAmt, double overrideRate, double overrideWageBase, bool isExempt );
STE_API(uint16_t) STE_STDCALL ste_set_emst(const ste_handle *ste, const char *locationCode, const char *municipalityCode, const char *schoolID, bool isExempt, bool isResident, uint16_t method, double withheldYTD, bool isLastCheck );
STE_API(uint16_t) STE_STDCALL ste_set_pa_emst(const ste_handle *ste, const char *locationCode, const char *municipalityCode, const char *schoolID, bool isExempt, bool isResident, uint16_t method, double municipalWithheldYTD, double schoolWithheldYTD, bool isLastCheck );
STE_API(uint16_t) STE_STDCALL ste_set_gross_up(const ste_handle *ste, double netPay, double regularWages, const uint16_t wageType, double hours, double mtdWages, double qtdWages, double ytdWages, double supplementalHours, double supplementalMtdWages, double supplementalQtdWages, double supplementalYtdWages );
STE_API(uint16_t) STE_STDCALL ste_calculate(const ste_handle *ste );
STE_API(double)   STE_STDCALL ste_get_federal(const ste_handle *ste, double *fitCTD, double *supplementalCTD);
STE_API(double)   STE_STDCALL ste_get_fica(const ste_handle *ste);
STE_API(uint16_t) STE_STDCALL ste_get_rrta(const ste_handle *ste, bool *exemptStatusEE, bool *exemptStatusER, double *ytdTier1_EE, double *ytdTier1_ER, double *ytdTier2_EE, double *ytdTier2_ER, bool *autoAdjust, double *tier1_EE, double *tier1_ER, double *tier2_EE, double *tier2_ER);
STE_API(double)   STE_STDCALL ste_get_medicare(const ste_handle *ste);
STE_API(double)   STE_STDCALL ste_get_medicare_additional(const ste_handle *ste);
STE_API(double)   STE_STDCALL ste_get_eic(const ste_handle *ste);
STE_API(double)   STE_STDCALL ste_get_state_eic(const ste_handle *ste, const char *locationCode);
STE_API(double)   STE_STDCALL ste_get_state(const ste_handle *ste, const char *locationCode, double *sitCTD, double *supplementalCTD);
STE_API(double)   STE_STDCALL ste_get_county(const ste_handle *ste, const char *locationCode, double *countyCTD, double *countySupplementalCTD);
STE_API(double)   STE_STDCALL ste_get_ky_county(const ste_handle *ste, const char *locationCode, uint16_t taxSelector, double *countyCTD, double *countySupplementalCTD);
STE_API(double)   STE_STDCALL ste_get_city(const ste_handle *ste, const char *locationCode, double *cityCTD, double *citySupplementalCTD);
STE_API(double)   STE_STDCALL ste_get_wv_occupational_tax(const ste_handle *ste, const char *locationCode, double *occupationalCTD, double *occupationalSupplementalCTD);
STE_API(double)   STE_STDCALL ste_get_jedd(const ste_handle *ste, const char *locationCode, int32_t jeddTaxID, double *cityCTD, double *citySupplementalCTD);
STE_API(double)   STE_STDCALL ste_get_daf(const ste_handle *ste, const char *locationCode, int32_t dafTaxID, double *cityCTD, double *citySupplementalCTD);
STE_API(double)   STE_STDCALL ste_get_schooldistrict(const ste_handle *ste, const char *locationCode, double *schoolCTD, double *schoolSupplementalCTD);
STE_API(double)   STE_STDCALL ste_get_pa_eit(const ste_handle *ste, const char *locationCode, double *taxRegWages_muni, double *taxRegWages_school, double *taxSupplemental_muni, double *taxSupplemental_school);
STE_API(double)   STE_STDCALL ste_get_sdi(const ste_handle *ste, const char *locationCode, double *sdiCTD, double *sdiSupplementalCTD);
STE_API(double)   STE_STDCALL ste_get_washington_industrial_sdi(const ste_handle *ste, const char *locationCode, const char *sdiReference, double *sdiCTD);
STE_API(double)   STE_STDCALL ste_get_fli(const ste_handle *ste, const char *locationCode, double *sdiCTD, double *sdiSupplementalCTD);
STE_API(double)   STE_STDCALL ste_get_health_care_subsidy_fund(const ste_handle *ste, const char *locationCode, double *healthcareCTD, double *healthcareSupplementalCTD);
STE_API(double)   STE_STDCALL ste_get_sui(const ste_handle *ste, const char *locationCode, double *suiCTD, double *suiSupplementalCTD);
STE_API(double)   STE_STDCALL ste_get_workerscomp(const ste_handle *ste, const char *locationCode, double *wcCTD, double *wcSupplementalCTD);
STE_API(double)   STE_STDCALL ste_get_mariana_wst(const ste_handle *ste, double *wstCTD);
STE_API(double)   STE_STDCALL ste_get_emst(const ste_handle *ste, const char *locationCode, double *emstCTD, double *emstSupplementalCTD);
STE_API(double)   STE_STDCALL ste_get_pa_emst(const ste_handle *ste, const char *locationCode, double *taxRegWages_muni, double *taxRegWages_school, double *taxSupplemental_muni, double *taxSupplemental_school);
STE_API(double)   STE_STDCALL ste_get_gross_up(const ste_handle *ste );

STE_API(uint16_t) STE_STDCALL ste_get_tax_count(const ste_handle *ste );
STE_API(uint16_t) STE_STDCALL ste_get_tax_list(const ste_handle *ste, char *uniqueTaxID, bool *isResident, char *description, double *rate, double *wageBase, double *taxLimitAmount, char *taxLimitPeriod, bool *isEmployerTax);
STE_API(uint16_t) STE_STDCALL ste_get_tax_list_ext(const ste_handle *ste, char *uniqueTaxID, bool *isResident, char *description, double *rate, double *wageBase, double *taxLimitAmount, char *taxLimitPeriod, char *taxInstallationDate, char *taxEffectiveDate, double *credit, double *creditLimit, bool *isEmployerTax);
STE_API(uint16_t) STE_STDCALL ste_set_tax_list(const ste_handle *ste, const char *locationCode, bool isResidentWorkLocation, const char *municipalityCode, const char *schoolID);
STE_API(uint16_t) STE_STDCALL ste_get_tax_id_list(const ste_handle *ste, const char *searchString, char *uniqueTaxID, bool *isResident, char *description, double *rate, double *wageBase, double *taxLimitAmount, char *taxLimitPeriod, bool *isEmployerTax);
STE_API(uint16_t) STE_STDCALL ste_get_tax_id_list_ext(const ste_handle *ste, const char *searchString, char *uniqueTaxID, bool *isResident, char *description, double *rate, double *wageBase, double *taxLimitAmount, char *taxLimitPeriod, char *taxInstallationDate, char *taxEffectiveDate, double *credit, double *creditLimit, bool *isEmployerTax);
STE_API(uint16_t) STE_STDCALL ste_get_benefit_status_list(const ste_handle *ste, const char *searchString, char *uniqueTaxID, bool *is401KPretax, bool *is403BPretax, bool *is457Pretax, bool *is125Pretax, bool *isFSAPretax, bool *isHSAPretax, bool *isSimpleIRAPretax, bool *is401KEmployerContribution, bool *is403BEmployerContribution, bool *is457EmployerContribution, bool *is125EmployerContribution, bool *isFSAEmployerContribution, bool *isHSAEmployerContribution, bool *isSimpleIRAEmployerContribution);
STE_API(uint16_t) STE_STDCALL ste_get_benefit_status_list_ext(const ste_handle *ste, const char *searchString, char *uniqueTaxID, bool *is401KPretax, bool *is403BPretax, bool *is457Pretax, bool *isRoth401KPretax, bool *isRoth403BPretax, bool *isRoth457Pretax, bool *is125Pretax, bool *isFSAPretax, bool *isFSADCPretax, bool *isHSAPretax, bool *isSimpleIRAPretax, bool *is401KEmployerContribution, bool *is403BEmployerContribution, bool *is457EmployerContribution, bool *isRoth401KEmployerContribution, bool *isRoth403BEmployerContribution, bool *isRoth457EmployerContribution, bool *is125EmployerContribution, bool *isFSAEmployerContribution, bool *isFSADCEmployerContribution, bool *isHSAEmployerContribution, bool *isSimpleIRAEmployerContribution);
STE_API(uint16_t) STE_STDCALL ste_set_nexus(const ste_handle *ste, const char *locationCode, bool hasNexus );
STE_API(uint16_t) STE_STDCALL ste_get_nexus(const ste_handle *ste, const char *locationCode, bool *hasNexus );

STE_API(uint16_t) STE_STDCALL ste_get_taxcalc_count(const ste_handle *ste );
STE_API(uint16_t) STE_STDCALL ste_get_taxcalc_list(const ste_handle *ste, char *locationCode, char *uniqueTaxID, char *description, uint16_t *paytype, double *taxAmt, double *grossWages, double *subjectWages, double *grossSubjectWages);
STE_API(uint16_t) STE_STDCALL ste_get_tax_info_table(const ste_handle *ste, const char *uTaxID, const char *columnName, char *result);

STE_API(void)	  STE_STDCALL  ste_set_errno( uint16_t err );

STE_API(uint16_t) STE_STDCALL ste_get_number(const ste_handle *ste, char *varName, double *value );
STE_API(uint16_t) STE_STDCALL ste_set_number(const ste_handle *ste, char *varName, double value );
STE_API(uint16_t) STE_STDCALL ste_get_boolean(const ste_handle *ste, char *varName, int32_t *value );
STE_API(uint16_t) STE_STDCALL ste_set_boolean(const ste_handle *ste, char *varName, int32_t value );
STE_API(uint16_t) STE_STDCALL ste_get_string(const ste_handle *ste, char *varName, char **s);
STE_API(uint16_t) STE_STDCALL ste_set_string(const ste_handle *ste, char *varName, const char *s, size_t length );
STE_API(uint16_t) STE_STDCALL ste_set_nil(const ste_handle *ste, char *varName );
STE_API(uint16_t) STE_STDCALL ste_exec(const ste_handle *ste, char *varName );
STE_API(void) 	  STE_STDCALL ste_exec_va (const ste_handle *ste, const char *func, const char *sig, ...);
STE_API(uint16_t) STE_STDCALL ste_set_option(const ste_handle *ste, int32_t optionNo, const char *optionValue );
STE_API(uint16_t) STE_STDCALL ste_set_option_flag(const ste_handle *ste, int32_t optionNo, bool flagValue );
STE_API(char *)	  STE_STDCALL ste_xml(const ste_handle *ste, const char *xmlStringIN, bool validateXML );
STE_API(void)	  STE_STDCALL ste_free_ptr(void *ptr);
STE_API(uint16_t) STE_STDCALL ste_set_log_entry(const ste_handle *ste, const char *logLevel, const char *message);

/* Employer tax functions */

STE_API(double)   STE_STDCALL ste_get_fica_employer(const ste_handle *ste);
STE_API(double)   STE_STDCALL ste_get_medicare_employer(const ste_handle *ste);
STE_API(uint16_t) STE_STDCALL ste_set_ui(const ste_handle *ste, const char *locationCode, double rate, bool isExempt );
STE_API(uint16_t) STE_STDCALL ste_set_ui_ext(const ste_handle *ste, const char *locationCode, double rate, double overrideWageBase, bool isExempt );
STE_API(uint16_t) STE_STDCALL ste_get_ui(const ste_handle *ste, const char *locationCode, double *rate, double *grossWages, double *subjectWages, double *wageBase, double *subjectWagesCTD, double *excessWagesCTD, double *subjectWagesQTD, double *excessWagesQTD, double *subjectWagesYTD, double *excessWagesYTD, double *taxAmt );
STE_API(uint16_t) STE_STDCALL ste_set_ui_surcharge(const ste_handle *ste, const char *locationCode, int32_t surchargeTaxID, double rate, bool isExempt );
STE_API(uint16_t) STE_STDCALL ste_get_ui_surcharge(const ste_handle *ste, const char *locationCode, int32_t surchargeTaxID, double *rate, double *grossWages, double *subjectWages, double *wageBase, double *subjectWagesCTD, double *excessWagesCTD, double *subjectWagesQTD, double *excessWagesQTD, double *subjectWagesYTD, double *excessWagesYTD, double *taxAmt );
STE_API(uint16_t) STE_STDCALL ste_set_ruia(const ste_handle *ste, double rate, bool isExempt );
STE_API(uint16_t) STE_STDCALL ste_get_ruia(const ste_handle *ste, double *rate, double *grossWages, double *subjectWages, double *wageBase, double *subjectWagesCTD, double *excessWagesCTD, double *taxAmt );
STE_API(uint16_t) STE_STDCALL ste_set_sdi_employer(const ste_handle *ste, const char *locationCode, int32_t sdiTaxID, double rate, double sdiTaxYTD, bool isExempt );
STE_API(uint16_t) STE_STDCALL ste_set_sdi_employer_ext(const ste_handle *ste, const char *locationCode, int32_t sdiTaxID, double rate, double overrideWageBase, double sdiTaxYTD, bool isExempt );
STE_API(double)   STE_STDCALL ste_get_sdi_employer(const ste_handle *ste, const char *locationCode, int32_t sdiTaxID, double *sdiTax );
STE_API(uint16_t) STE_STDCALL ste_set_transit_tax(const ste_handle *ste, const char *locationCode, int32_t transitTaxID, bool isExempt );
STE_API(double)   STE_STDCALL ste_get_transit_tax(const ste_handle *ste, const char *locationCode, int32_t transitTaxID, double *transitTax, double *transitTaxSupplemental);
STE_API(uint16_t) STE_STDCALL ste_set_wy_workers_comp(const ste_handle *ste, double rate, bool isCorporateOfficer, bool isExempt );
STE_API(double)   STE_STDCALL ste_get_wy_workers_comp(const ste_handle *ste, double *workersCompTax, double *workersCompTaxSupplemental );
STE_API(uint16_t) STE_STDCALL ste_set_wa_industrial(const ste_handle *ste, const char *locationCode, double rate, bool isExempt );
STE_API(uint16_t) STE_STDCALL ste_set_wa_industrial_ext(const ste_handle *ste, const char *locationCode, const char *sdiReference, double hours, double rate, bool isExempt );
STE_API(double)   STE_STDCALL ste_get_wa_industrial(const ste_handle *ste, const char *locationCode, double *industrialInsurance, double *industrialInsuranceSupplemental );
STE_API(double)   STE_STDCALL ste_get_wa_industrial_ext(const ste_handle *ste, const char *locationCode, const char *sdiReference, double *industrialInsurance );
STE_API(double)   STE_STDCALL ste_get_or_workers_comp(const ste_handle *ste, double *workersCompTax, double *workersCompTaxSupplemental );
STE_API(uint16_t) STE_STDCALL ste_set_ma_uhi(const ste_handle *ste, double wagesTaxedYTD, double overridePercentage, double overrideWageBase, double avgNumEmployees, bool isExempt );
STE_API(uint16_t) STE_STDCALL ste_get_ma_uhi(const ste_handle *ste, double *rate, double *grossWages, double *subjectWages, double *wageBase, double *subjectWagesCTD, double *excessWagesCTD, double *subjectWagesQTD, double *excessWagesQTD, double *subjectWagesYTD, double *excessWagesYTD, double *taxAmt );
STE_API(uint16_t) STE_STDCALL ste_set_ma_emac(const ste_handle *ste, double wagesTaxedYTD, double overridePercentage, double overrideWageBase, bool isExempt );
STE_API(uint16_t) STE_STDCALL ste_get_ma_emac(const ste_handle *ste, double *rate, double *grossWages, double *subjectWages, double *wageBase, double *subjectWagesCTD, double *excessWagesCTD, double *subjectWagesQTD, double *excessWagesQTD, double *subjectWagesYTD, double *excessWagesYTD, double *taxAmt );
STE_API(double)   STE_STDCALL ste_get_mctmt(const ste_handle *ste, double *mctmtTax, double *mctmtSupplemental );

STE_API(uint16_t) STE_STDCALL ste_set_head_tax(const ste_handle *ste, const char *locationCode, int32_t numberEmployees, bool isExempt );
STE_API(double)   STE_STDCALL ste_get_head_tax(const ste_handle *ste, const char *locationCode );
STE_API(uint16_t) STE_STDCALL ste_set_percent_payroll(const ste_handle *ste, const char *locationCode, int32_t taxID, double totalWages, bool isExempt );
STE_API(double)   STE_STDCALL ste_get_percent_payroll(const ste_handle *ste, const char *locationCode, int32_t taxID );
STE_API(uint16_t) STE_STDCALL ste_calculate_employer(const ste_handle *ste );

/* Canadian functions */

STE_API(uint16_t) STE_STDCALL ste_ca_calculate(const ste_handle *ste );
STE_API(double)   STE_STDCALL ste_ca_get_cpp(const ste_handle *ste);
STE_API(double)   STE_STDCALL ste_ca_get_qpp(const ste_handle *ste);
STE_API(double)   STE_STDCALL ste_ca_get_qpp_employer(const ste_handle *ste);
STE_API(double)   STE_STDCALL ste_ca_get_ei(const ste_handle *ste);
STE_API(double)   STE_STDCALL ste_ca_get_ei_employer(const ste_handle *ste);
STE_API(double)   STE_STDCALL ste_ca_get_federal_tax(const ste_handle *ste);
STE_API(double)   STE_STDCALL ste_ca_get_provincial_tax(const ste_handle *ste, const char *locationCode);
STE_API(double)   STE_STDCALL ste_ca_get_quebec_single_payment_tax(const ste_handle *ste);

STE_API(double)	  STE_STDCALL ste_ca_get_bonus_cpp(const ste_handle *ste);
STE_API(double)   STE_STDCALL ste_ca_get_bonus_qpp(const ste_handle *ste);
STE_API(double)   STE_STDCALL ste_ca_get_bonus_ei(const ste_handle *ste);


STE_API(double)   STE_STDCALL ste_ca_get_calculated_bonus_tax(const ste_handle *ste, const char *locationCode);
STE_API(double)   STE_STDCALL ste_ca_get_calculated_lumpsum_tax(const ste_handle *ste, const char *locationCode);

/* ste_ca_set_federal_values, ste_ca_set_provincial_values, ste_ca_set_exempts are deprecated */
STE_API(uint16_t) STE_STDCALL ste_ca_set_federal_values(const ste_handle *ste, double totalClaimAmountFederal, double approvedSharesFederal, double taxCreditFederal, double ytdWH);
STE_API(uint16_t) STE_STDCALL ste_ca_set_provincial_values(const ste_handle *ste, const char *provinceNumber, double totalClaimAmountProvincial, double approvedSharesProvincial, double taxCreditProvincial, double TD1TaxCredit, double prescribedZoneAmount, double ytdWH);
STE_API(uint16_t) STE_STDCALL ste_ca_set_exempts(const ste_handle *ste, bool eiExempt, bool cppExempt, bool taxExempt);

STE_API(uint16_t) STE_STDCALL ste_ca_set_federal(const ste_handle *ste, bool exemptStatus, double totalClaimAmountFederal, double approvedSharesFederal, double taxCreditFederal, double ytdWH);
STE_API(uint16_t) STE_STDCALL ste_ca_set_provincial(const ste_handle *ste, bool isExempt, const char *provinceNumber, double totalClaimAmountProvincial, double approvedSharesProvincial, double taxCreditProvincial, double TD1TaxCredit, double prescribedZoneAmount, double ytdWH);
STE_API(uint16_t) STE_STDCALL ste_ca_set_reductions(const ste_handle *ste, double approvedShares, double annualIncomeReductions, double payPeriodIncomeReductions, double cppReductions, double eiReductions);
STE_API(uint16_t) STE_STDCALL ste_ca_set_federal_reductions(const ste_handle *ste, double approvedShares, double annualIncomeReductions, double payPeriodIncomeReductions, double cppReductions, double eiReductions, double HD);
STE_API(uint16_t) STE_STDCALL ste_ca_set_provincial_reductions(const ste_handle *ste, const char *locationCode, double annualProvincialIncomeReductions, double payPeriodProvincialIncomeReductions );
STE_API(uint16_t) STE_STDCALL ste_ca_set_bonus_tax(const ste_handle *ste, double tax,  const char *locationCode );

STE_API(uint16_t) STE_STDCALL ste_ca_calc_total_claim_amount(const ste_handle *ste,  const char *locationCode );
STE_API(uint16_t) STE_STDCALL ste_ca_add_dependent_child(const ste_handle *ste, bool minorChild, int32_t postSecSchoolTerms, bool additionalAmount, bool singleParentFamily, double childsNetIncome);
STE_API(uint16_t) STE_STDCALL ste_ca_reset_dependent_children(const ste_handle *ste );

STE_API(uint16_t) STE_STDCALL ste_ca_set_quebec_health_exemption(const ste_handle *ste, bool quebecHealthExempt);
STE_API(uint16_t) STE_STDCALL ste_ca_set_quebec_spouse(const ste_handle *ste, double spouseNetIncome, double spouseRetirementIncome, double spouseTransferredAmount);
STE_API(uint16_t) STE_STDCALL ste_ca_set_quebec_other_incomes(const ste_handle *ste, double retirementIncome, double familyNetIncome);

STE_API(uint16_t) STE_STDCALL ste_ca_set_quebec_Age_Respect(const ste_handle *ste, int32_t ageRespect);
STE_API(uint16_t) STE_STDCALL ste_ca_set_quebec_Living_Alone(const ste_handle *ste, int32_t livingAlone);
STE_API(uint16_t) STE_STDCALL ste_ca_set_quebec_Impairment_Persons(const ste_handle *ste, int32_t impairmentPersons);


STE_API(uint16_t) STE_STDCALL ste_ca_add_other_dependent(const ste_handle *ste, bool dependentsInfirmity, double dependentsNetIncome );
STE_API(uint16_t) STE_STDCALL ste_ca_reset_other_dependents(const ste_handle *ste);
STE_API(uint16_t) STE_STDCALL ste_ca_calc_quebec_credit_amount(const ste_handle *ste );

STE_API(uint16_t) STE_STDCALL ste_ca_td1_set_annual_net_income(const ste_handle *ste, double annualNetIncome );
STE_API(uint16_t) STE_STDCALL ste_ca_td1_set_senior_supplementary(const ste_handle *ste, bool seniorSupplementary );
STE_API(uint16_t) STE_STDCALL ste_ca_td1_set_pension_income(const ste_handle *ste, double pensionIncome );
STE_API(uint16_t) STE_STDCALL ste_ca_td1_set_tuition(const ste_handle *ste, double fullTimeTuitionFees, int32_t fullTimeMonths, int32_t fullTimeInstitutions, double partTimeTuitionFees, int32_t partTimeMonths, int32_t partTimeInstitutions );
STE_API(uint16_t) STE_STDCALL ste_ca_td1_set_disability(const ste_handle *ste, bool disability );
STE_API(uint16_t) STE_STDCALL ste_ca_td1_set_spouse_amounts(const ste_handle *ste, double spouseNetIncome, double spouseTransferredAmount );
STE_API(uint16_t) STE_STDCALL ste_ca_td1_set_dependent_values(const ste_handle *ste,int32_t dependent, double dependentNetIncome, int32_t dependentChildren, int32_t disabledDependents, double dependentTransferredAmount );

STE_API(double)	  STE_STDCALL ste_ca_td1_get_provincial_tax_credit(const ste_handle *ste, const char *locationCode);
STE_API(double)	  STE_STDCALL ste_ca_td1_get_total_claim_amount(const ste_handle *ste);

STE_API(double)	  STE_STDCALL ste_ca_quebec_calc_get_federal(const ste_handle *ste, double *federalTax, double *ei);
STE_API(uint16_t) STE_STDCALL ste_ca_quebec_set_qpip(const ste_handle *ste, bool exemptStatus, double emp_ytd, double er_ytd);
STE_API(double)	  STE_STDCALL ste_ca_quebec_get_qpip(const ste_handle *ste, double *qpip, double *qpipEmp);

STE_API(uint16_t) STE_STDCALL ste_ca_set_cpp(const ste_handle *ste, bool exemptStatus, double ytd );
STE_API(uint16_t) STE_STDCALL ste_ca_set_qpp(const ste_handle *ste, bool exemptStatus, double ytd );
STE_API(uint16_t) STE_STDCALL ste_ca_set_ei(const ste_handle *ste, bool exemptStatus, double ytd );
#ifdef __cplusplus
}
#endif

#endif
